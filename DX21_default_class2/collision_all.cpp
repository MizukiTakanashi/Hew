//============================================================
// 全てのゲームオブジェクトの当たり判定関係(cppファイル)
// 作成日：2022/11/10
// 作成者：高梨水希
//============================================================
#include "collision_all.h"
#include "collision.h"
#include "inh_player_arm.h"
#include "sound.h"

//==========================
// デフォルトコンストラクタ
//==========================
CollisionAll::CollisionAll()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pEnemy[i] = nullptr;
	}

	m_SE = LoadSound((char*)"data\\SE\\bomb000.wav");	//サウンドのロード
}

//==========================
// 引数付きコンストラクタ
//==========================
CollisionAll::CollisionAll(Player* pPlayer, inhPlayerArmBoth* pL, inhPlayerArmBoth* pR,
	ExplosionManagement* pExplosion, ItemManagement* pItem, Score* pNumber, Bom* pBom, 
	Management_Meteo* pMeteo)
	:m_pPlayer(pPlayer), m_pPlayerLeft(pL), m_pPlayerRight(pR), m_pExplosion(pExplosion),
	m_pItem(pItem), m_pScore(pNumber), m_pBom(pBom), m_pMeteo(pMeteo)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pEnemy[i] = nullptr;
	}

	m_SE = LoadSound((char*)"data\\SE\\bomb000.wav");	//サウンドのロード
}

//================================================
// 当たり判定(プレイヤーのHPが削れる当たり判定)
//================================================
int CollisionAll::Collision(void)
{
	//プレイヤー自身が受けたダメージ数
	int attacked = 0;

	//爆発音を鳴らすか否か
	bool explosion_sound = false;

	//=================================================
	// 敵と○○

	//敵の種類の数分ループ
	for (int k = 0; k < m_enemy_num; k++) {

		//=================================================
		// 敵の数分ループ
		for (int j = 0; j < m_pEnemy[k]->GetObjNum(); j++) {
			bool next = false;

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

						//プレイヤーの弾を消す
						m_pPlayer->DeleteBullet(i);
						i--;

						//爆発をセット
						m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));
						explosion_sound = true;

						//敵のHPを減らす
						//敵が死んだら...
						if (m_pEnemy[k]->ReduceHP(j, 1))
						{
							//敵アイテムのドロップ
							m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k);

							//敵を消す
							m_pEnemy[k]->DeleteObj(j);

							j--;
							if (j < 0) {
								next = true;
								break;
							}

							//倒した敵の数を増やす
							m_pScore->AddScore(1);
						}
					}
				}
			}

			if (next) {
				break;
			}

			//自身
			//自身
			if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetObjPos(j),
				m_pPlayer->GetSize() / 3, m_pEnemy[k]->GetObjSize())) {
				//一度離れてからじゃないともう一度当たった判定にはならない
				if (!m_player_enemy_col) {
					//ぶつかったフラグをオン
					m_player_enemy_col = true;

					//ダメージ数を増やす
					attacked += m_pEnemy[k]->GetObjAttack();

					//コンボを途切れさせる
					m_pScore->InitCombo();
				}
			}
			else {
				m_player_enemy_col = false;
			}

			//ボム
			//自身
			if (m_pBom->IsBomb()) {
				//爆発をセット
				m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));
				explosion_sound = true;

				//敵のHPを減らす
				//敵が死んだら...
				if (m_pEnemy[k]->ReduceHP(j, m_pBom->GetBombAttack()))
				{
					//敵アイテムのドロップ
					m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k);

					//敵を消す
					m_pEnemy[k]->DeleteObj(j);

					j--;

					if (j < 0) {
						next = true;
						break;
					}

					//倒した敵の数を増やす
					m_pScore->AddScore(1);
				}
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
						//敵が死んだら...
						if (m_pEnemy[k]->ReduceHP(j, 1))
						{
							//敵アイテムのドロップ
							m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k);

							//敵を消す
							m_pEnemy[k]->DeleteObj(j);

							j--;

							if (j < 0) {
								next = true;
								break;
							}

							//倒した敵の数を増やす
							m_pScore->AddScore(1);
						}
					}
				}

				//腕のポインタを取ってくる(二回目は右)
				pArm = m_pPlayerRight;
			}

			if (next) {
				break;
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

								//腕についている種類がレーザーでなければ...
								if (pArmItem->GetType() != inhPlayerArm::TYPE::TYPE_LASER) {
									//プレイヤーの弾を消す
									pArmItem->DeleteBullet(i);
									i--;
								}

								//爆発をセット
								m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));
								explosion_sound = true;

								//敵のHPを減らす
								//敵が死んだら...
								if (m_pEnemy[k]->ReduceHP(j, 1))
								{
									//敵アイテムのドロップ
									m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k);

									//敵を消す
									m_pEnemy[k]->DeleteObj(j);

									j--;

									if (j < 0) {
										next = true;
										break;
									}

									//倒した敵の数を増やす
									m_pScore->AddScore(1);
								}
							}
						}
					}

					if (next) {
						break;
					}
				}

				//腕についているアイテムのポインタを取ってくる(二回目は右)
				pArmItem = m_pPlayerRight->GetArmPointer();
			}
		}

		//=================================================
		// 敵の弾分ループ
		for (int j = 0; j < m_pEnemy[k]->GetBulletNum(); j++) {
			bool next = false;

			//=================================================
			// プレイヤーと敵の弾

			//プレイヤーの方
			//敵の方

				//弾
				//弾
			/*for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
				if (Collision::ColBox(m_pPlayer->GetBulletPos(i), m_pEnemy[k]->GetBulletPos(j),
					m_pPlayer->GetBulletSize(), m_pEnemy[k]->GetBulletSize())) {
					//爆発をセット
					m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));
					explosion_sound = true;

					//プレイヤーの弾を消す
					m_pPlayer->DeleteBullet(i);
					i--;
					//敵の弾を消す
					m_pEnemy[k]->DeleteBullet(j);
					j--;

					if (j < 0) {
						next = true;
						break;
					}
				}
			}*/

			//自身
			//弾
			if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetBulletPos(j),
				m_pPlayer->GetSize() / 3, m_pEnemy[k]->GetBulletSize())) {

				//爆発をセット
				m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));
				explosion_sound = true;

				//敵の弾を消す
				m_pEnemy[k]->DeleteBullet(j);
				j--;
				//ダメージ数を増やす
				attacked += m_pEnemy[k]->GetBulletAttack();
				//コンボを途切れさせる
				m_pScore->InitCombo();

				if (j < 0) {
					next = true;
					break;
				}
			}

			//ボム
			//弾
			if (m_pBom->IsBomb()) {
				//爆発をセット
				m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));
				explosion_sound = true;

				//敵の弾を消す
				m_pEnemy[k]->DeleteBullet(j);
				j--;

				if (j < 0) {
					next = true;
					break;
				}
			}

			//=================================================
			// プレイヤーの腕の弾と敵

			//プレイヤーの腕の弾方
			//敵の方

				//弾
				//弾

			//腕についているアイテムのポインタを取ってくる(初期は左から)
			//inhPlayerArm* pArmItem = m_pPlayerLeft->GetArmPointer();

			//右と左、両方行う
			/*for (int m = 0; m < 2; m++) {
				//ポインターがヌルであれば処理を行わない
				if (pArmItem != nullptr) {
					for (int i = 0; i < pArmItem->GetBulletNum(); i++) {
						if (Collision::ColBox(pArmItem->GetBulletPos(i), m_pEnemy[k]->GetBulletPos(j),
							pArmItem->GetBulletSize(), m_pEnemy[k]->GetBulletSize())) {
							//爆発をセット
							m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));
							explosion_sound = true;

							//腕についている種類がTYPE2(レーザー)でなければ...
							if (pArmItem->GetType() != inhPlayerArm::TYPE::TYPE2) {
								//プレイヤーの弾を消す
								pArmItem->DeleteBullet(i);
								i--;
							}

							//敵の弾を消す
							m_pEnemy[k]->DeleteBullet(j);
							j--;

							if (j < 0) {
								next = true;
								break;
							}
						}
					}

					if (next) {
						break;
					}
				}

				//腕についているアイテムのポインタを取ってくる(二回目は右)
				pArmItem = m_pPlayerRight->GetArmPointer();
			}*/
		}

		//=================================================
		// 敵の別オブジェクト分ループ

		////バリア以外の敵であれば処理しない
		//if (k != (int)TYPE::BULLET_BARRIER) {
		//	continue;
		//}

		//for (int j = 0; j < m_pEnemy[k]->GetOtherNum(); j++) {
		//	bool next = false;

		//	//=================================================
		//	// プレイヤーと敵の別オブジェクト

		//	//プレイヤーの方
		//	//敵の別オブジェクトの方

		//		//弾
		//		//別オブジェクト
		//	for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
		//		//もしも画面外にいたら壊せないようにする
		//		if (ScreenOut::GetScreenOut(m_pEnemy[k]->GetOtherPos(j),
		//			m_pEnemy[k]->GetOtherSize())) {
		//			continue;
		//		}

		//		//当たってなければ次行く
		//		if (!Collision::ColBox(m_pPlayer->GetBulletPos(i), m_pEnemy[k]->GetOtherPos(j),
		//			m_pPlayer->GetBulletSize(), m_pEnemy[k]->GetOtherSize())) {
		//			continue;
		//		}

		//		//プレイヤーの弾を消す
		//		m_pPlayer->DeleteBullet(i);
		//		i--;

		//		//爆発をセット
		//		m_pExplosion->SetExplosion(m_pEnemy[k]->GetOtherPos(j));
		//		explosion_sound = true;

		//		//敵の別オブジェクトのHPを減らす
		//		//敵の別オブジェクトのHPがなくなったら...
		//		if (m_pEnemy[k]->ReduceOtherHP(j, 1))
		//		{
		//			//敵の別オブジェクトを消す
		//			m_pEnemy[k]->DeleteOther(j);

		//			j--;
		//			if (j < 0) {
		//				next = true;
		//				break;
		//			}
		//		}
		//	}

		//	if (next) {
		//		break;
		//	}


		//	//自身
		//	//別オブジェクト
		//	if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetOtherPos(j),
		//		m_pPlayer->GetSize() / 3, m_pEnemy[k]->GetOtherSize())) {

		//		//爆発をセット
		//		m_pExplosion->SetExplosion(m_pEnemy[k]->GetOtherPos(j));
		//		explosion_sound = true;

		//		//敵の別オブジェクトのHPを減らす
		//		//敵の別オブジェクトのHPがなくなったら...
		//		if (m_pEnemy[k]->ReduceOtherHP(j, 1))
		//		{
		//			//敵の別オブジェクトを消す
		//			m_pEnemy[k]->DeleteOther(j);

		//			j--;
		//			if (j < 0) {
		//				next = true;
		//				break;
		//			}
		//		}

		//		if (m_pEnemy[k]->GetOtherAttack() != 0) {
		//			//ダメージ数を増やす
		//			attacked += m_pEnemy[k]->GetOtherAttack();
		//			//コンボを途切れさせる
		//			m_pScore->InitCombo();
		//		}
		//	}

		//	//=================================================
		//	// プレイヤーの腕の弾と敵の別オブジェクト

		//	//プレイヤーの腕の弾方
		//	//敵の別オブジェクトの方

		//	//腕についているアイテムのポインタを取ってくる(初期は左から)
		//	inhPlayerArm* pArmItem = m_pPlayerLeft->GetArmPointer();

		//	//右と左、両方行う
		//	for (int m = 0; m < 2; m++) {
		//		//ポインターがヌルであれば処理を行わない
		//		if (pArmItem == nullptr) {
		//			continue;
		//		}

		//		for (int i = 0; i < pArmItem->GetBulletNum(); i++) {
		//			if (Collision::ColBox(pArmItem->GetBulletPos(i), m_pEnemy[k]->GetOtherPos(j),
		//				pArmItem->GetBulletSize(), m_pEnemy[k]->GetOtherSize())) {
		//				//爆発をセット
		//				m_pExplosion->SetExplosion(m_pEnemy[k]->GetOtherPos(j));
		//				explosion_sound = true;

		//				//腕についている種類がTYPE2(レーザー)でなければ...
		//				if (pArmItem->GetType() != inhPlayerArm::TYPE::TYPE2) {
		//					//プレイヤーの弾を消す
		//					pArmItem->DeleteBullet(i);
		//					i--;
		//				}

		//				//敵の別オブジェクトのHPを減らす
		//				//敵の別オブジェクトのHPがなくなったら...
		//				if (m_pEnemy[k]->ReduceOtherHP(j, 1))
		//				{
		//					//敵の別オブジェクトを消す
		//					m_pEnemy[k]->DeleteOther(j);

		//					j--;
		//					if (j < 0) {
		//						next = true;
		//						break;
		//					}
		//				}
		//			}
		//		}

		//		if (next) {
		//			break;
		//		}

		//		//腕についているアイテムのポインタを取ってくる(二回目は右)
		//		pArmItem = m_pPlayerRight->GetArmPointer();
		//	}
		//}
	}

	//===========================
	// 隕石
	for (int j = 0; j < m_pMeteo->GetMeteoNum(); j++) {
		for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
			//もしも画面外にいたら壊せないようにする
			if (!ScreenOut::GetScreenOut(m_pMeteo->GetObjPos(j),
				m_pMeteo->GetObjSize())) {

				//当たったか判定
				if (Collision::ColBox(m_pPlayer->GetBulletPos(i), m_pMeteo->GetObjPos(j),
					m_pPlayer->GetBulletSize(), m_pMeteo->GetObjSize())) {
					//爆発をセット
					m_pExplosion->SetExplosion(m_pPlayer->GetBulletPos(i));
					explosion_sound = true;

					//プレイヤーの弾を消す
					m_pPlayer->DeleteBullet(i);
					i--;
				}
			}
		}

		//自身
		//自身
		if (Collision::ColBox(m_pPlayer->GetPos(), m_pMeteo->GetObjPos(j),
			m_pPlayer->GetSize() / 3, m_pMeteo->GetObjSize())) {
			//一度離れてからじゃないともう一度当たった判定にはならない
			if (!m_player_enemy_col) {
				//ぶつかったフラグをオン
				m_player_enemy_col = true;

				//ダメージ数を増やす
				attacked += m_pMeteo->GetMeteoAttack();

				//コンボを途切れさせる
				m_pScore->InitCombo();
			}
		}
		else {
			m_player_enemy_col = false;
		}

		//ボム
		//自身
		if (m_pBom->IsBomb()) {
			//爆発をセット
			m_pExplosion->SetExplosion(m_pMeteo->GetObjPos(j));
			explosion_sound = true;

			//敵を消す
			m_pMeteo->DeleteObj(j);

			j--;
			if (j < 0) {
				break;
			}
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
				if (Collision::ColBox(pArm->GetPos(), m_pMeteo->GetObjPos(j),
					pArm->GetSize(), m_pMeteo->GetObjSize())) {
					//腕と隕石があたったらタイプを消す
					pArm->BreakShootingArm();
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
					if (!ScreenOut::GetScreenOut(m_pMeteo->GetObjPos(j),
						m_pMeteo->GetObjSize())) {

						//当たったか判定
						if (Collision::ColBox(pArmItem->GetBulletPos(i), m_pMeteo->GetObjPos(j),
							pArmItem->GetBulletSize(), m_pMeteo->GetObjSize())) {
							//爆発をセット
							m_pExplosion->SetExplosion(pArmItem->GetBulletPos(i));
							explosion_sound = true;

							//腕についている種類がレーザーでなければ...
							if (pArmItem->GetType() != inhPlayerArm::TYPE::TYPE_LASER) {
								//プレイヤーの弾を消す
								pArmItem->DeleteBullet(i);
								i--;
							}
						}
					}
				}
			}

			//腕についているアイテムのポインタを取ってくる(二回目は右)
			pArmItem = m_pPlayerRight->GetArmPointer();
		}
	}
	
	//=======================================
	// 攻撃を受けたら、腕の切り離しを行う
	if (attacked > 0) {
		//片方から切り離し
		if (m_pPlayerLeft->GetType() != inhPlayerArmBoth::TYPE::TYPE_NONE &&
			m_pPlayerLeft->GetType() != inhPlayerArmBoth::TYPE::TYPE_OLD &&
			m_pPlayerLeft->GetType() != inhPlayerArmBoth::TYPE::TYPE_SHOOT) {
			m_pPlayerLeft->SetType(inhPlayerArmBoth::TYPE::TYPE_OLD, false);
			attacked--;
		}
		else if (m_pPlayerRight->GetType() != inhPlayerArmBoth::TYPE::TYPE_NONE &&
			m_pPlayerRight->GetType() != inhPlayerArmBoth::TYPE::TYPE_OLD &&
			m_pPlayerRight->GetType() != inhPlayerArmBoth::TYPE::TYPE_SHOOT) {
			m_pPlayerRight->SetType(inhPlayerArmBoth::TYPE::TYPE_OLD, false);
			attacked--;
		}
	}

	//爆発の音の間隔を一定時間過ぎていたら(ここでカウント)...
	//一回でも爆発がセットされていたら...
	if (m_SE_interval_count++ > SE_INTERVAL && explosion_sound) {

		//音を鳴らす
		PlaySound(m_SE, 0);
		SetVolume(m_SE, 0.1f);

		//爆発の音の間隔をリセット
		m_SE_interval_count = 0;
	}

	//受けたダメージを返す
	return attacked;
}

//=======================================
// プレイヤーのHPが回復する当たり判定
//=======================================
void CollisionAll::HeelCollision(void)
{

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
				}
				//タイプが同じだったら残弾数を回復する
				if (pArm->GetType() == (inhPlayerArmBoth::TYPE)(m_pItem->GetItemType(i)))
				{
					pArm->HeelBullet();
				}
				pArm->SetType((inhPlayerArmBoth::TYPE)(m_pItem->GetItemType(i)));
				m_pItem->DeleteItem(i);
				i--;
			}
		}

		//腕のポインタを取ってくる(二回目は右)
		pArm = m_pPlayerRight;
	}

}
