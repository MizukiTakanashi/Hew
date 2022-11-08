//=======================================
// 普通の敵の管理関係(cppファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#include "management_enemy_normal.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// 定数の初期化
//==========================
const float EnemyNormalManagement::BULLET_SIZE_X = 20.0f;
const float EnemyNormalManagement::BULLET_SIZE_Y = 20.0f;
const float EnemyNormalManagement::BULLET_SPEED = 5.0f;

//=========================
// 引数付きコンストラクタ
//=========================
EnemyNormalManagement::EnemyNormalManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, EnemySetPos& pEnemySetPos)
	:EnemyManagement(MAX_NUM, MAX_NUM, ATTACK, BULLET_ATTACK), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyNormal = new EnemyNormal[MAX_NUM];
	m_pBullet = new Bullet[MAX_NUM];
}

//======================
// 更新処理
//======================
void EnemyNormalManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	//時間が来たら敵を配置
	if (m_count++ > APPEARANCE_TIME && GetObjNum() != MAX_NUM) {
		//ランダムで出現位置を決める
		float x = rand() % (SCREEN_WIDTH - (int)EnemyNormal::SIZE_X / 2) + EnemyNormal::SIZE_X / 2;

		//フラグに応じて敵を作る
		if (m_pEnemySetPos.SetEnemy(D3DXVECTOR2(x, EnemyNormal::STOP_POS_Y), D3DXVECTOR2(EnemyNormal::SIZE_X + EnemyNormal::RANGE * 2, EnemyNormal::SIZE_Y))) {
			EnemyNormal temp(m_pDrawObjectEnemy, D3DXVECTOR2(x, -EnemyNormal::SIZE_Y / 2));
			m_pEnemyNormal[GetObjNum()] = temp;
		 	EnemyManagement::IncreaseObjNum(1);
		}

		m_count = 0;
	}

	//今いる敵の処理
	for (int i = 0; i < GetObjNum(); i++) {
		m_pEnemyNormal[i].Update();

		//弾を作る
		if (m_pEnemyNormal[i].GetFlagBulletMake() && EnemyManagement::GetBulletNum() != MAX_NUM) {
			//プレイヤーの後を追うようにして、弾を生成
			D3DXVECTOR2 movTemp = PlayerPos - m_pEnemyNormal[i].GetPos();
			D3DXVECTOR2 rotposTemp = m_pEnemyNormal[i].GetPos() - PlayerPos;
			D3DXVec2Normalize(&movTemp, &movTemp);
			movTemp *= BULLET_SPEED;

			//float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 90.0f;

			Bullet temp(m_pDrawObjectBullet, m_pEnemyNormal[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), movTemp, 0.0f);
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyNormal[i].BulletMake();
		}
	}

	//今いる弾の処理
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		//プレイヤーの後を追う(ホーミング弾)
		D3DXVECTOR2 movTemp = PlayerPos - m_pBullet[i].GetPos();
		D3DXVECTOR2 rotposTemp = m_pEnemyNormal[i].GetPos() - PlayerPos;
		D3DXVec2Normalize(&movTemp, &movTemp);
		movTemp *= BULLET_SPEED;

		//float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 90.0f;

		m_pBullet[i].SetRot(0.0f);
		m_pBullet[i].SetMove(movTemp);

		//弾の更新処理
		m_pBullet[i].Update();
		
		//画面外から出たら、時間経過したら...
		if (m_pBullet[i].GetScreenOut() || m_pBullet[i].GetTime() > BULLET_BREAK_TIME) {
			//弾を消す
			DeleteBullet(i);
		}
	}
}

//==========================
// 描画処理
//==========================
void EnemyNormalManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyNormal[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// 敵を消す
//======================
void EnemyNormalManagement::DeleteObj(int index_num)
{
	m_pEnemySetPos.DeleteEnemy(m_pEnemyNormal[index_num].GetPos());

	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyNormal[i] = m_pEnemyNormal[i + 1];
	}
	EnemyManagement::IncreaseObjNum(-1);
}

//======================
// 弾を消す
//======================
void EnemyNormalManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}