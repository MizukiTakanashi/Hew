//============================================================
// 全てのゲームオブジェクトの当たり判定関係(cppファイル)
// 作成日：2022/11/10
// 作成者：高梨水希
//============================================================
#include "collision_all.h"
#include "collision.h"
#include "inh_player_arm.h"

//==========================
// デフォルトコンストラクタ
//==========================
CollisionAll::CollisionAll()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pEnemy[i] = nullptr;
	}
}

//==========================
// 引数付きコンストラクタ
//==========================
CollisionAll::CollisionAll(Player* pPlayer, inhPlayerArmBoth* pL, inhPlayerArmBoth* pR,
	ExplosionManagement* pExplosion, ItemManagement* pItem, Score* pNumber)
	:m_pPlayer(pPlayer), m_pPlayerLeft(pL), m_pPlayerRight(pR), m_pExplosion(pExplosion), 
	m_pItem(pItem), m_pNumber(pNumber)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pEnemy[i] = nullptr;
	}
}

//================================================
// 当たり判定(プレイヤーのHPが削れる当たり判定)
//================================================
int CollisionAll::Collision(void)
{
	//プレイヤー自身が受けたダメージ数
	int attacked = 0;

	//=================================================
	// 敵と○○

	//敵の種類の数分ループ
	for (int k = 0; k < m_enemy_num; k++) {

		//=================================================
		// 敵の数分ループ
		for (int j = 0; j < m_pEnemy[k]->GetObjNum(); j++) {

			//=================================================
			// プレイヤーと敵

			//プレイヤーの方
			//敵の方

				//弾
				//自身
			for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
				//もしも画面外にいたら壊せないようにする
				if (!ScreenOut::GetScreenOut(m_pEnemy[k]->GetObjPos(j),
					m_pEnemy[k]->GetObjSize())) {

					//当たったか判定
					if (Collision::ColBox(m_pPlayer->GetBulletPos(i), m_pEnemy[k]->GetObjPos(j),
						m_pPlayer->GetBulletSize(), m_pEnemy[k]->GetObjSize())) {
						//爆発をセット
						m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));

						//プレイヤーの弾を消す
						m_pPlayer->DeleteBullet(i);
						i--;
						//敵のHPを減らす
						if (m_pEnemy[k]->ReduceHP(j, 1))
						{//敵が死んだ場合の処理
							//敵アイテムのドロップ
							m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k);
						}
						j--;

						//倒した敵の数を増やす
						m_pNumber->AddScore(1);
					}
				}
			}

				//自身
				//自身
			if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetObjPos(j),
				m_pPlayer->GetSize(), m_pEnemy[k]->GetObjSize())) {
				//一度離れてからじゃないともう一度当たった判定にはならない
				if (!m_player_enemy_col) {
					//ぶつかったフラグをオン
					m_player_enemy_col = true;

					//ダメージ数を増やす
					attacked += m_pEnemy[k]->GetObjAttack();
					//コンボを途切れさせる
					m_pNumber->InitCombo();
				}
			}
			else {
				m_player_enemy_col = false;
			}

			//=================================================
			// プレイヤーの腕と敵

			//腕の方
			//敵の方

				//自身
				//自身

			//腕のポインタを取ってくる(初期は左から)
			inhPlayerArmBoth* pArm = m_pPlayerLeft;

			for (int m = 0; m < 2; m++) {
				//発射中であれば
				if (pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE_SHOOT) {
					if (Collision::ColBox(pArm->GetPos(), m_pEnemy[k]->GetObjPos(j),
						pArm->GetSize(), m_pEnemy[k]->GetObjSize(j))) {
						//TYPE_OLDにセット
						pArm->SetType(inhPlayerArmBoth::TYPE::TYPE_OLD);

						//敵のHPを減らす
						if (m_pEnemy[k]->ReduceHP(j, 1))
						{//敵が死んだ場合の処理
							
						}
						//爆発をセット
						m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));
					}
				}

				//腕のポインタを取ってくる(二回目は右)
				pArm = m_pPlayerRight;
			}

			//=================================================
			// プレイヤーの腕の弾と敵

			//プレイヤーの腕の弾方
			//敵の方

				//弾
				//自身

			//腕についているアイテムのポインタを取ってくる(初期は左から)
			inhPlayerArm* pArmItem = m_pPlayerLeft->GetArmPointer();

			//右と左、両方行う
			for (int m = 0; m < 2; m++) {
				//ポインターがヌルであれば処理を行わない
				if (pArmItem != nullptr) {
					for (int i = 0; i < pArmItem->GetBulletNum(); i++) {
						//もしも画面外にいたら壊せないようにする
						if (!ScreenOut::GetScreenOut(m_pEnemy[k]->GetObjPos(j),
							m_pEnemy[k]->GetObjSize())) {

							//当たったか判定
							if (Collision::ColBox(pArmItem->GetBulletPos(i), m_pEnemy[k]->GetObjPos(j),
								pArmItem->GetBulletSize(), m_pEnemy[k]->GetObjSize())) {
								//爆発をセット
								m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));

								//腕についている種類がTYPE2(レーザー)でなければ...
								if (pArmItem->GetType() != inhPlayerArm::TYPE::TYPE2) {
									//プレイヤーの弾を消す
									pArmItem->DeleteBullet(i);
									i--;
								}

								//敵のHPを減らす
								if (m_pEnemy[k]->ReduceHP(j, 1))
								{//敵が死んだ場合の処理
									//敵アイテムのドロップ
									m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k);
								}
								j--;

								//倒した敵の数を増やす
								m_pNumber->AddScore(1);
							}
						}
					}
				}

				//腕についているアイテムのポインタを取ってくる(二回目は右)
				pArmItem = m_pPlayerRight->GetArmPointer();
			}
		}

		//=================================================
		// 敵の弾分ループ
		for (int j = 0; j < m_pEnemy[k]->GetBulletNum(); j++) {

			//=================================================
			// プレイヤーと敵の弾

			//プレイヤーの方
			//敵の方
			
				//弾
				//弾
			for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
				if (Collision::ColBox(m_pPlayer->GetBulletPos(i), m_pEnemy[k]->GetBulletPos(j),
					m_pPlayer->GetBulletSize(), m_pEnemy[k]->GetBulletSize())) {
					//爆発をセット
					m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));

					//プレイヤーの弾を消す
					m_pPlayer->DeleteBullet(i);
					i--;
					//敵の弾を消す
					m_pEnemy[k]->DeleteBullet(j);
					j--;
				}
			}

				//自身
				//弾
			if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetBulletPos(j),
				m_pPlayer->GetSize(), m_pEnemy[k]->GetBulletSize())) {

				//敵の弾を消す
				m_pEnemy[k]->DeleteBullet(j);
				j--;
				//ダメージ数を増やす
				attacked += m_pEnemy[k]->GetBulletAttack();
				//コンボを途切れさせる
				m_pNumber->InitCombo();
			}


			//=================================================
			// プレイヤーの腕の弾と敵

			//プレイヤーの腕の弾方
			//敵の方

				//弾
				//弾

			//腕についているアイテムのポインタを取ってくる(初期は左から)
			inhPlayerArm* pArmItem = m_pPlayerLeft->GetArmPointer();

			//右と左、両方行う
			for (int m = 0; m < 2; m++) {
				//ポインターがヌルであれば処理を行わない
				if (pArmItem != nullptr) {
					for (int i = 0; i < pArmItem->GetBulletNum(); i++) {
						if (Collision::ColBox(pArmItem->GetBulletPos(i), m_pEnemy[k]->GetBulletPos(j),
							pArmItem->GetBulletSize(), m_pEnemy[k]->GetBulletSize())) {
							//爆発をセット
							m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));

							//腕についている種類がTYPE2(レーザー)でなければ...
							if (pArmItem->GetType() != inhPlayerArm::TYPE::TYPE2) {
								//プレイヤーの弾を消す
								pArmItem->DeleteBullet(i);
								i--;
							}

							//敵の弾を消す
							m_pEnemy[k]->DeleteBullet(j);
							j--;
						}
					}
				}

				//腕についているアイテムのポインタを取ってくる(二回目は右)
				pArmItem = m_pPlayerRight->GetArmPointer();
			}
		}
	}

	//攻撃を受けたら、腕の切り離しを行う
	if (attacked > 0) {
		//片方から切り離し
		if (m_pPlayerLeft->GetType() != inhPlayerArmBoth::TYPE::TYPE_NONE &&
			m_pPlayerLeft->GetType() != inhPlayerArmBoth::TYPE::TYPE_OLD &&
			m_pPlayerLeft->GetType() != inhPlayerArmBoth::TYPE::TYPE_SHOOT) {
			m_pPlayerLeft->SetType(inhPlayerArmBoth::TYPE::TYPE_SHOOT, false);
		}
		else if (m_pPlayerRight->GetType() != inhPlayerArmBoth::TYPE::TYPE_NONE &&
			m_pPlayerRight->GetType() != inhPlayerArmBoth::TYPE::TYPE_OLD &&
			m_pPlayerRight->GetType() != inhPlayerArmBoth::TYPE::TYPE_SHOOT) {
			m_pPlayerRight->SetType(inhPlayerArmBoth::TYPE::TYPE_SHOOT, false);
		}

		//2回食らっていたら次にもう片方を切り離し
		if (attacked > 1) {
			if (m_pPlayerLeft->GetType() != inhPlayerArmBoth::TYPE::TYPE_NONE &&
				m_pPlayerLeft->GetType() != inhPlayerArmBoth::TYPE::TYPE_OLD &&
				m_pPlayerLeft->GetType() != inhPlayerArmBoth::TYPE::TYPE_SHOOT) {
				m_pPlayerLeft->SetType(inhPlayerArmBoth::TYPE::TYPE_SHOOT, false);
			}
			else if (m_pPlayerRight->GetType() != inhPlayerArmBoth::TYPE::TYPE_NONE &&
				m_pPlayerRight->GetType() != inhPlayerArmBoth::TYPE::TYPE_OLD &&
				m_pPlayerRight->GetType() != inhPlayerArmBoth::TYPE::TYPE_SHOOT) {
				m_pPlayerRight->SetType(inhPlayerArmBoth::TYPE::TYPE_SHOOT, false);
			}
		}
	}

	return attacked;
}

//=======================================
// プレイヤーのHPが回復する当たり判定
//=======================================
int CollisionAll::HeelCollision(void)
{
	//プレイヤーの回復数
	int heel = 0;

	//=================================================
	// 腕と○○
	
	//腕のポインタを取ってくる(初期は左から)
	inhPlayerArmBoth* pArm = m_pPlayerLeft;

	for (int m = 0; m < 2; m++) {
		//=================================================
		// プレイヤーの腕と敵のアイテム
		
		//プレイヤーの腕の方
		//敵のアイテムの方
		
			//腕の方
			//敵の方
		
				//自身
				//自身

		for (int i = 0; i < m_pItem->GetItemNum(); i++) {
			if (Collision::ColBox(pArm->GetPos(), m_pItem->GetItemPos(i),
				pArm->GetSize(), m_pItem->GetItemSize()))
			{
				if (pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE_NONE ||
					pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE_OLD)
				{
					heel++;
				}
				//タイプが同じだったら残弾数を回復する
				if (pArm->GetType() == (inhPlayerArmBoth::TYPE)(m_pItem->GetItemType(i) + 1))
				{
					pArm->HeelBullet();
				}
				pArm->SetType((inhPlayerArmBoth::TYPE)(m_pItem->GetItemType(i) + 1));
				m_pItem->DeleteItem(i);
				i--;
			}
		}

		//腕のポインタを取ってくる(二回目は右)
		pArm = m_pPlayerRight;
	}

	return heel;
}
