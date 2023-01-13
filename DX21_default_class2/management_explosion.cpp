//=======================================
// 爆発管理関係(cppファイル)
// 作成日：2022/09/18
// 作成者：高梨水希
//=======================================
#include "management_explosion.h"
#include "sound.h"
#include "collision.h"

//==========================
// 定数の初期化
//==========================
const D3DXVECTOR2 ExplosionManagement::CLOTH_INTERVAL = D3DXVECTOR2(5.0f, 5.0f);

//============================
// デフォルトコンストラクタ
//============================
ExplosionManagement::ExplosionManagement()
{
	m_pExplosion = new Explosion[ENEMY_NUM];
}

//=========================
// 引数付きコンストラクタ
//=========================
ExplosionManagement::ExplosionManagement(DrawObject & DrawObject) :m_DrawObject(DrawObject)
{
	m_pExplosion = new Explosion[ENEMY_NUM];
}

//======================
// 更新処理
//======================
void ExplosionManagement::Update(void)
{
	for (int i = 0; i < m_ExplosionNum; i++) {
		m_pExplosion[i].Update();

		//アニメーションが終わったら消す
		if (m_pExplosion[i].GetEndAnimation()) {
			for (int j = i; j < m_ExplosionNum - 1; j++) {
				m_pExplosion[j] = m_pExplosion[j + 1];
			}
			m_ExplosionNum--;
		}
	}
}

//==========================
// 爆発をセット
//==========================
void ExplosionManagement::SetExplosion(const D3DXVECTOR2& pos)
{
	for (int i = 0; i < m_ExplosionNum; i++) {
		//どこかの爆発と被ってたら...
		if (Collision::ColBox(m_pExplosion[i].GetPos(), pos,
			m_pExplosion[i].GetSize(), CLOTH_INTERVAL)) {
			return;
		}
	}
	Explosion Temp(m_DrawObject, pos);
	m_pExplosion[m_ExplosionNum] = Temp;
	m_ExplosionNum++;
}
