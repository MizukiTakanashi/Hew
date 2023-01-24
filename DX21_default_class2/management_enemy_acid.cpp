//=======================================
// 酸性雨の敵の管理関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "management_enemy_acid.h"

//==========================
// 定数の初期化
//==========================
const float EnemyAcidManagement::BULLET_SIZE_X = 100.0f;
const float EnemyAcidManagement::BULLET_SIZE_Y = 200.0f;
const float EnemyAcidManagement::BULLET_SPEED = 5.0f;
const float EnemyAcidManagement::EXIT_MOVE_SPEED_Y = 5.0f;

//=========================
// 引数付きコンストラクタ
//=========================
EnemyAcidManagement::EnemyAcidManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2)
	:EnemyManagement(EnemyManagement::TYPE::GATORING, ENEMY_NUM, ATTACK, BULLET_ATTACK),
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_pEnemyGatoring = new EnemyStop[ENEMY_NUM];
	m_pBullet = new Bullet[BULLET_NUM];
}

//======================
// 更新処理
//======================
void EnemyAcidManagement::Update()
{
	m_FlameNum++; //フレーム数を増加

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyStop temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemyGatoring[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	if (m_EnemyNum == ENEMY_NUM)
	{
		m_tutorial_clear = true;
	}

	//今いる敵の処理
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_tutorial_clear = false;
		m_pEnemyGatoring[i].Update();

		//退出時間来たら...
		if (m_pEnemyGatoring[i].GetAppearanceTime() > EXIT_TIME) {
			//上に消えて行く
			m_pEnemyGatoring[i].MovePos(D3DXVECTOR2(0.0f, -EXIT_MOVE_SPEED_Y));
			continue;
		}

		//弾を作る
		if (m_pEnemyGatoring[i].GetFlagBulletMake() && EnemyManagement::GetBulletNum() < BULLET_NUM)
		{
			Bullet temp(m_pDrawObjectBullet, m_pEnemyGatoring[i].GetPos() + D3DXVECTOR2(0.0f, 50.0f) ,
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y),D3DXVECTOR2(0, BULLET_SPEED), 0.0f);
						   // 弾の大きさ								弾を撃つ方向		
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyGatoring[i].BulletMake();
		}
	}

	//今いる弾の処理
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Update();
		//画面外から出たら...
		if (m_pBullet[i].GetScreenOut()) {
			//弾を消す
			DeleteBullet(i);
		}
	}
}

//==========================
// 描画処理
//==========================
void EnemyAcidManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyGatoring[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// 敵のHPを減らす
//======================
bool EnemyAcidManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyGatoring[index_num].ReduceHP(reduceHP);

	if (m_pEnemyGatoring[index_num].GetHP() <= 0)
	{//HPが０以下なら敵を消す


		return true;
	}
	return false;
}

//==========================
// 敵を消す
//==========================
void EnemyAcidManagement::DeleteObj(int index_num)
{
	//敵を消す
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyGatoring[i] = m_pEnemyGatoring[i + 1];
	}

	//継承元の敵を消すを呼ぶ
	EnemyManagement::DeleteObj(index_num);

	if (m_EnemyNum == ENEMY_NUM) {
		m_tutorial_clear = true;
	}
}

//======================
// 弾を消す
//======================
void EnemyAcidManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}