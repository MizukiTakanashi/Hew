//============================================================
// PlayerEnemyGatoringCollision.cpp
// 作成日：2022/11/01
// 作成者：小西 蓮
//============================================================
#include "PlayerEnemyGatoringCollision.h"
#include "collision.h"
#include "ScreenOut.h"

//======================
// 更新処理
//======================
int PlayerEnemyGatoringCollision::Update(void)
{
	//プレイヤーの方
	//敵の方

	//弾
	//自身
	for (int i = 0; i < m_rPlayer->GetBulletNum(); i++) {
		for (int j = 0; j < m_rEnemyGatoringManagement->GetObjNum(); j++) {

			//もしも画面外にいたら壊せないようにする
			if (!ScreenOut::GetScreenOut(m_rEnemyGatoringManagement->GetObjPos(j),
				m_rEnemyGatoringManagement->GetObjSize())) {
				
				//当たったか判定
				if (Collision::ColBox(m_rPlayer->GetBulletPos(i), m_rEnemyGatoringManagement->GetObjPos(j),
						m_rPlayer->GetBulletSize(), m_rEnemyGatoringManagement->GetObjSize())) {
					//爆発をセット
					m_rExplosionManagement->SetExplosion(m_rEnemyGatoringManagement->GetObjPos(j));
					//敵アイテムのドロップ
					m_rItemManagement->SetItem(m_rEnemyGatoringManagement->GetObjPos(j), 0);

					//プレイヤーの弾を消す
					m_rPlayer->DeleteBullet(i);
					i--;
					//敵を消す
					m_rEnemyGatoringManagement->DeleteObj(j);
					j--;

					m_pNumber->AddNumber(1);
				}
			}
		}
	}

	//弾
	//弾
	for (int i = 0; i < m_rPlayer->GetBulletNum(); i++) {
		for (int j = 0; j < m_rEnemyGatoringManagement->GetBulletNum(); j++) {
			if (Collision::ColBox(m_rPlayer->GetBulletPos(i), m_rEnemyGatoringManagement->GetBulletPos(j),
				m_rPlayer->GetBulletSize(), m_rEnemyGatoringManagement->GetBulletSize())) {
				//爆発をセット
				m_rExplosionManagement->SetExplosion(m_rEnemyGatoringManagement->GetBulletPos(j));

				//プレイヤーの弾を消す
				m_rPlayer->DeleteBullet(i);
				i--;
				//敵の弾を消す
				m_rEnemyGatoringManagement->DeleteBullet(j);
				j--;
			}
		}
	}

	//プレイヤー自身が受けたダメージ数
	int attacked = 0;

	//自身
	//弾
	for (int j = 0; j < m_rEnemyGatoringManagement->GetBulletNum(); j++) {
		if (Collision::ColBox(m_rPlayer->GetPos(), m_rEnemyGatoringManagement->GetBulletPos(j),
			m_rPlayer->GetSize(), m_rEnemyGatoringManagement->GetBulletSize())) {
			//爆発をセット
			m_rExplosionManagement->SetExplosion(m_rEnemyGatoringManagement->GetBulletPos(j));

			//敵の弾を消す
			m_rEnemyGatoringManagement->DeleteBullet(j);
			j--;
			//ダメージ数を増やす
			attacked = 1 * EnemyGatoringManagement::BULLET_ATTACK;
		}
	}

	//自身
	//自身
	for (int j = 0; j < m_rEnemyGatoringManagement->GetObjNum(); j++) {
		if (Collision::ColBox(m_rPlayer->GetPos(), m_rEnemyGatoringManagement->GetObjPos(j),
			m_rPlayer->GetSize(), m_rEnemyGatoringManagement->GetObjSize())) {
			//一度離れてからじゃないともう一度当たった判定にはならない
			if (!m_PlayerEnemyGatoringCol) {
				//ぶつかったフラグをオン
				m_PlayerEnemyGatoringCol = true;

				//ダメージ数を増やす
				attacked = 1 * EnemyGatoringManagement::ATTACK;
			}
		}
		else {
			m_PlayerEnemyGatoringCol = false;
		}
	}

	return attacked;
}