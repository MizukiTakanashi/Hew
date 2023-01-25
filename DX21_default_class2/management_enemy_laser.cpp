//=======================================
// レーザーの敵の管理関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "management_enemy_laser.h"
#include "sound.h"

//==========================
// 定数の初期化
//==========================
const int EnemyLaserManagement::ENEMY_NUM[(int)STAGE::NUM] = { 3, 0, 4, 4, 0 };
const float EnemyLaserManagement::BULLET_SIZE_X = 20.0f;
const float EnemyLaserManagement::BULLET_SIZE_Y = 20.0f;
const float EnemyLaserManagement::EXIT_MOVE_SPEED_X = 2.5f;

//=========================
// 引数付きコンストラクタ
//=========================
EnemyLaserManagement::EnemyLaserManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage)
	:EnemyManagement(EnemyManagement::TYPE::LASER, ENEMY_NUM[stage], ATTACK, LASER_ATTACK), 
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectLaser(pDrawObject2)
{
	m_stage_num = stage;
	m_pEnemyLaser = new EnemyLaser[ENEMY_NUM[stage]];
	m_pLaser = new Laser[ENEMY_NUM[stage]];

	//===================
	// 音

	//ビーム音
	m_SE_06 = LoadSound((char*)"data\\SE\\2_06.wav");
	SetVolume(m_SE_06, 0.4f);

	//ビーム発射音
	m_SE_07 = LoadSound((char*)"data\\SE\\2_07.wav");

	//熱風音
	m_SE_14 = LoadSound((char*)"data\\SE\\1_14.wav");

	//ガス噴射音
	m_SE_19 = LoadSound((char*)"data\\SE\\2_19.wav");
}

//======================
// 更新処理
//======================
void EnemyLaserManagement::Update()
{
	m_FlameNum++; //フレーム数を増加

	//時間が来たら敵をセット
	if (m_FlameNum == m_SetEnemyTime[m_stage_num][m_EnemyNum])
	{
		//退出方向を決める
		bool right = true;
		if (m_EnemyNum == 0) {
			right = false;
		}

		EnemyLaser temp(m_pDrawObjectEnemy, m_SetEnemy[m_stage_num][m_EnemyNum], right);
		m_pEnemyLaser[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_pEnemyLaser[m_EnemyNum].SetLaserDirection(0);

		m_EnemyNum++;
	}

	if (m_EnemyNum == ENEMY_NUM[m_stage_num])
	{
		m_tutorial_clear = true;
	}

	//今いる敵の処理
	for (int i = 0; i < GetObjNum(); i++)
	{
		m_tutorial_clear = false;

		m_pEnemyLaser[i].Update();
		//レーザーのアップデート
		if (m_pEnemyLaser[i].GetLaserIndex() >= 0)
		{
			m_pLaser[m_pEnemyLaser[i].GetLaserIndex()].Update(m_pEnemyLaser[i].GetPos());
		}

		//退出時間来たら...
		if (m_pEnemyLaser[i].GetAppearanceTime() > EXIT_TIME) {
			//退出フラグオン
			m_pEnemyLaser[i].OnExitFlag();

			//右に退出
			if (m_pEnemyLaser[i].IsExitDirectionRight()) {
				m_pEnemyLaser[i].MovePos(D3DXVECTOR2(EXIT_MOVE_SPEED_X, 0.0f));
			}
			//左に退出
			else {
				m_pEnemyLaser[i].MovePos(D3DXVECTOR2(-EXIT_MOVE_SPEED_X, 0.0f));
			}
			continue;
		}

		//弾を作る
		if (m_pEnemyLaser[i].GetFlagBulletMake())
		{
			//レーザー番号をセット
			m_pEnemyLaser[i].SetLaserIndex(EnemyManagement::GetBulletNum());
			//レーザーを作る
			float laser_x = 0.0f;
			float laser_y = 0.0f;

			laser_x = BULLET_SIZE_X;

			Laser temp(m_pDrawObjectLaser, m_pEnemyLaser[i].GetPos() + D3DXVECTOR2(0.0f, 10.0f),
				D3DXVECTOR2(laser_x, laser_y));
			m_pLaser[EnemyManagement::GetBulletNum()] = temp;
			m_pLaser[EnemyManagement::GetBulletNum()].SetLaserDirectioon((Laser::DIRECTION)m_pEnemyLaser[i].GetLaserDirection());

			m_pEnemyLaser[i].SetLaserIndex(EnemyManagement::GetBulletNum());
			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyLaser[i].BulletMake();

			PlaySound(m_SE_07, 0);

			if (m_stage_num == (int)STAGE::MERCURY) {
				PlaySound(m_SE_14, 0);
			}
			else if (m_stage_num == (int)STAGE::SATURN) {
				PlaySound(m_SE_19, 0);
			}
			else {
				PlaySound(m_SE_06, 0);
			}
		}
	}

	//死んだ敵のレーザーのアップデート
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++)
	{
		if (m_pLaser[i].GetLaserTime() < 0)
		{
			m_pLaser[i].Update(m_pLaser->GetPos());
		}
		
		//画面外から出たら...
		if (m_pLaser[i].GetScreenOut())
		{
			//弾を消す
			DeleteBullet(i);
		}
	}
}

//==========================
// 描画処理
//==========================
void EnemyLaserManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyLaser[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++)
	{
		m_pLaser[i].Draw();
	}
}

//======================
// 敵のHPを減らす
//======================
bool EnemyLaserManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyLaser[index_num].ReduceHP(reduceHP);

	if (m_pEnemyLaser[index_num].GetHP() <= 0)
	{//HPが０以下なら敵を消す

		if (m_pEnemyLaser[index_num].GetLaserIndex() >= 0)
		{
			m_pLaser[m_pEnemyLaser[index_num].GetLaserIndex()].DeleteLaser();
		}
		
		return true;
	}
	return false;
}

//======================
// 敵を消す
//======================
void EnemyLaserManagement::DeleteObj(int index_num)
{
	//レーザーを消す
	if (m_pEnemyLaser[index_num].GetLaserIndex() >= 0)
	{
		m_pLaser[m_pEnemyLaser[index_num].GetLaserIndex()].DeleteLaser();
	}

	//敵を消す
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyLaser[i] = m_pEnemyLaser[i + 1];
	}

	//継承元の敵を消すを呼ぶ
	EnemyManagement::DeleteObj(index_num);

	if (m_EnemyNum == ENEMY_NUM[m_stage_num]) {
		m_tutorial_clear = true;
	}
}

//======================
// 弾を消す
//======================
void EnemyLaserManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++)
	{
		m_pLaser[i] = m_pLaser[i + 1];
	}
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++)
	{
		if (m_pEnemyLaser[i].GetLaserIndex() == index_num)
		{
			m_pEnemyLaser[i].SetLaserIndex(-1);
		}
		else if (m_pEnemyLaser[i].GetLaserIndex() > index_num)
		{
			m_pEnemyLaser[i].SetLaserIndex(m_pEnemyLaser[i].GetLaserIndex() - 1);
		}
	}
	EnemyManagement::IncreaseBulletNum(-1);
}