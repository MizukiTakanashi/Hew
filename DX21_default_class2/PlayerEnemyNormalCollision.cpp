//============================================================
// プレイヤーと普通の敵の諸々の当たり判定関係(cppファイル)
// 作成日：2022/09/22
// 作成者：高梨水希
//============================================================
#include "PlayerEnemyNormalCollision.h"
#include "collision.h"
#include "ScreenOut.h"
#include "itemP.h"

//======================
// 更新処理
//======================
int PlayerEnemyNormalCollision::Update(void)
{
	//プレイヤーの方
	//敵の方

	//弾
	//自身
	for (int i = 0; i < m_rPlayer->GetBulletNum(); i++) {
		for (int j = 0; j < m_rEnemyNormalManagement->GetEnemyNum(); j++) {

			//もしも画面外にいたら壊せないようにする
			if (!ScreenOut::GetScreenOut(m_rEnemyNormalManagement->GetEnemyPos(j),
				m_rEnemyNormalManagement->GetEnemySize())) {
				
				//当たったか判定
				if (Collision::ColBox(m_rPlayer->GetBulletPos(i), m_rEnemyNormalManagement->GetEnemyPos(j),
						m_rPlayer->GetBulletSize(), m_rEnemyNormalManagement->GetEnemySize())) {
					//爆発をセット
					m_rExplosionManagement->SetExplosion(m_rEnemyNormalManagement->GetEnemyPos(j));
					//敵アイテムのドロップ
					m_rItemManagement->SetItem(m_rEnemyNormalManagement->GetEnemyPos(j),1);

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
				m_rEnemyNormalManagement->DeleteBullet(j);
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
			//爆発をセット
			m_rExplosionManagement->SetExplosion(m_rEnemyNormalManagement->GetBulletPos(j));

			//敵の弾を消す
			m_rEnemyNormalManagement->DeleteBullet(j);
			j--;
			//ダメージ数を増やす
			attacked = 1 * EnemyNormalManagement::BULLET_ATTACK;
		}
	}

	//自身
	//自身
	for (int j = 0; j < m_rEnemyNormalManagement->GetEnemyNum(); j++) {
		if (Collision::ColBox(m_rPlayer->GetPos(), m_rEnemyNormalManagement->GetEnemyPos(j),
			m_rPlayer->GetSize(), m_rEnemyNormalManagement->GetEnemySize())) {
			//一度離れてからじゃないともう一度当たった判定にはならない
			if (!m_PlayerEnemyNormalCol) {
				//ぶつかったフラグをオン
				m_PlayerEnemyNormalCol = true;

				//爆発をセット
				m_rExplosionManagement->SetExplosion(m_rPlayer->GetPos());

				//ダメージ数を増やす
				attacked = 1 * EnemyNormalManagement::ATTACK;
			}
		}
		else {
			m_PlayerEnemyNormalCol = false;
		}
	}

	return attacked;
}