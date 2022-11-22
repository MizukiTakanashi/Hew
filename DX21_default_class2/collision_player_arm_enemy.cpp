//===============================================
// 腕から出る弾と敵の当たり判定(cppファイル)
// 作成日：2022/11/01
// 作成者：山本亮太
//===============================================
#include "collision_player_arm_enemy.h"
#include "collision.h"

PlayerArmEnemyCol::PlayerArmEnemyCol(EnemyManagement* p1, EnemyManagement* p2, EnemyManagement* p3,
	ExplosionManagement* pExplosion, ItemManagement* pItem, Score* pNumber) 
	:m_pExplosion(pExplosion), m_pItem(pItem), m_pScore(pNumber)
{
	m_pEnemy[0] = p1;
	m_pEnemy[1] = p2;
	m_pEnemy[2] = p3;
}

void PlayerArmEnemyCol::Collision(void)
{
	//もしも腕のポインタに何もなければ終了
	if (m_pArm == nullptr){
		return;
	}

	for (int k = 0; k < ENEMY_NUM; k++) {
		//腕の弾の方
		//敵の方

		//弾
		//自身
		for (int i = 0; i < m_pArm->GetBulletNum(); i++) {
			for (int j = 0; j < m_pEnemy[k]->GetObjNum(); j++) {

				//もしも画面外にいたら壊せないようにする
				if (!ScreenOut::GetScreenOut(m_pEnemy[k]->GetObjPos(j),
					m_pEnemy[k]->GetObjSize())) {

					//当たったか判定
					if (Collision::ColBox(m_pArm->GetBulletPos(i), m_pEnemy[k]->GetObjPos(j),
						m_pArm->GetBulletSize(), m_pEnemy[k]->GetObjSize())) {
						//爆発をセット
						m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));
						//敵アイテムのドロップ
						m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), 1);

						//腕についている種類がTYPE2(レーザー)でなければ...
						if (m_pArm->GetType() != inhPlayerArm::TYPE::TYPE2) {
							//プレイヤーの弾を消す
							m_pArm->DeleteBullet(i);
							i--;
						}
						
						//敵を消す
						m_pEnemy[k]->DeleteObj(j);
						j--;

						//倒した敵の数を増やす
						m_pScore->AddScore(1);
					}
				}
			}
		}

		//弾
		//弾
		for (int i = 0; i < m_pArm->GetBulletNum(); i++) {
			for (int j = 0; j < m_pEnemy[k]->GetBulletNum(); j++) {
				if (Collision::ColBox(m_pArm->GetBulletPos(i), m_pEnemy[k]->GetBulletPos(j),
					m_pArm->GetBulletSize(), m_pEnemy[k]->GetBulletSize())) {
					//爆発をセット
					m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));

					//腕についている種類がTYPE2(レーザー)でなければ...
					if (m_pArm->GetType() != inhPlayerArm::TYPE::TYPE2) {
						//プレイヤーの弾を消す
						m_pArm->DeleteBullet(i);
						i--;
					}

					//敵の弾を消す
					m_pEnemy[k]->DeleteBullet(j);
					j--;
				}
			}
		}
	}
}
