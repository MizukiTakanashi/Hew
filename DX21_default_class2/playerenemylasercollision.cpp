//============================================================
// プレイヤーとレーザーの敵の諸々の当たり判定関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//============================================================
#include "playerenemylasercollision.h"
#include "collision.h"
#include "ScreenOut.h"

//======================
// 更新処理
//======================
int PlayerEnemyLaserCollision::Update(void)
{
	//プレイヤーの方
	//敵の方

	//弾
	//自身
	for (int i = 0; i < m_rPlayer->GetBulletNum(); i++) {
		for (int j = 0; j < m_rEnemyNormalManagement->GetObjNum(); j++) {

			//もしも画面外にいたら壊せないようにする
			if (!ScreenOut::GetScreenOut(m_rEnemyNormalManagement->GetObjPos(j),
				m_rEnemyNormalManagement->GetObjSize())) {
				
				//当たったか判定
				if (Collision::ColBox(m_rPlayer->GetBulletPos(i), m_rEnemyNormalManagement->GetObjPos(j),
						m_rPlayer->GetBulletSize(), m_rEnemyNormalManagement->GetObjSize())) {
					//爆発をセット
					m_rExplosionManagement->SetExplosion(m_rEnemyNormalManagement->GetObjPos(j));
					//敵アイテムのドロップ
					m_rItemManagement->SetItem(m_rEnemyNormalManagement->GetObjPos(j), 0);

					//プレイヤーの弾を消す
					m_rPlayer->DeleteBullet(i);
					i--;
					//敵を消す
					m_rEnemyNormalManagement->DeleteEnemy(j);
					j--;

					m_pNumber->AddNumber(1);
				}
			}
		}
	}

	//弾
	//弾
	for (int i = 0; i < m_rPlayer->GetBulletNum(); i++) {
		for (int j = 0; j < m_rEnemyNormalManagement->GetBulletNum(); j++) {
			if (Collision::ColBox(m_rPlayer->GetBulletPos(i), m_rEnemyNormalManagement->GetBulletPos(j),
				m_rPlayer->GetBulletSize(), m_rEnemyNormalManagement->GetBulletSize())) {
				//爆発をセット
				m_rExplosionManagement->SetExplosion(m_rEnemyNormalManagement->GetBulletPos(j));

				//プレイヤーの弾を消す
				m_rPlayer->DeleteBullet(i);
				i--;
				//敵の弾を消す
				//m_rEnemyNormalManagement->DeleteBullet(j);
				j--;
			}
		}
	}

	//プレイヤー自身が受けたダメージ数
	int attacked = 0;

	//自身
	//弾
	for (int j = 0; j < m_rEnemyNormalManagement->GetBulletNum(); j++) {
		if (Collision::ColBox(m_rPlayer->GetPos(), m_rEnemyNormalManagement->GetBulletPos(j),
			m_rPlayer->GetSize(), m_rEnemyNormalManagement->GetBulletSize())) {

			//敵の弾を消す
			//m_rEnemyNormalManagement->DeleteBullet(j);
			//j--;
			//ダメージ数を増やす
			attacked = 1 * EnemyLaserManagement::LASER_ATTACK;
		}
	}

	//自身
	//自身
	for (int j = 0; j < m_rEnemyNormalManagement->GetObjNum(); j++) {
		if (Collision::ColBox(m_rPlayer->GetPos(), m_rEnemyNormalManagement->GetObjPos(j),
			m_rPlayer->GetSize(), m_rEnemyNormalManagement->GetObjSize())) {
			//一度離れてからじゃないともう一度当たった判定にはならない
			if (!m_PlayerEnemyNormalCol) {
				//ぶつかったフラグをオン
				m_PlayerEnemyNormalCol = true;

				//ダメージ数を増やす
				attacked = 1 * EnemyLaserManagement::ATTACK;
			}
		}
		else {
			m_PlayerEnemyNormalCol = false;
		}
	}

	return attacked;
}
