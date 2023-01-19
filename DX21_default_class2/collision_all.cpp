//============================================================
// 全てのゲームオブジェクトの当たり判定関係(cppファイル)
// 作成日：2022/11/10
// 作成者：高梨水希
//============================================================
#include "collision_all.h"
#include "collision.h"
#include "inh_player_arm.h"
#include "sound.h"

//各ステージ
#include "management_enemy_grenade.h"
#include "player_arm_grenade.h"

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
CollisionAll::CollisionAll(STAGE stage, Player* pPlayer, inhPlayerArmBoth* pL, inhPlayerArmBoth* pR,
	ExplosionManagement* pExplosion, ItemManagement* pItem, Score* pNumber, Bom* pBom)
	:m_stage(stage), m_pPlayer(pPlayer), m_pPlayerLeft(pL), m_pPlayerRight(pR), m_pExplosion(pExplosion),
	m_pItem(pItem), m_pScore(pNumber), m_pBom(pBom)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pEnemy[i] = nullptr;
	}

	//音
	m_SE = LoadSound((char*)"data\\SE\\bomb000.wav");	//サウンドのロード

	switch (m_stage) {

	case STAGE::MARS:
		//バリアが弾を跳ね返す音
		m_SE_08 = LoadSound((char*)"data\\SE\\2_08.wav");

		//バリアが壊れる音
		m_SE_09 = LoadSound((char*)"data\\SE\\1_09.wav");
		//SetVolume(m_SE_09, 2.0f);

		//冷気を浴びた音
		m_SE_10 = LoadSound((char*)"data\\SE\\1_10.wav");

		break;

	default:
		break;
	}
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
							m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), (int)m_pEnemy[k]->GetType());

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
					m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), (int)m_pEnemy[k]->GetType());

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
							m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), (int)m_pEnemy[k]->GetType());

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
			//腕のポインタを取ってくる(初期は左から)
			pArm = m_pPlayerLeft;

			//右と左、両方行う
			for (int m = 0; m < 2; m++) {
				//ポインターがヌルであれば処理を行わない
				if (pArmItem == nullptr) {
					//腕についているアイテムのポインタを取ってくる(二回目は右)
					pArmItem = m_pPlayerRight->GetArmPointer();

					//腕のポインタを取ってくる(二回目は右)
					pArm = m_pPlayerRight;
					continue;
				}

				bool next_right = false;

				//ステージごとの処理
				switch (m_stage) {

				case STAGE::MARS:
					//バリアであれば何もしない
					if (pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE_BARRIAR) {
						next_right = true;
					}
					//グレネード敵であれば何もしない
					else if (pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE7) {
						for (int i = 0; i < pArmItem->GetBulletNum(); i++) {
							//敵を探している最中
							if (pArmItem->GetBulletSize(i) == PlayerArmGrenade::FIND_BULLET_SIZE) {
								if (Collision::ColBox(pArmItem->GetBulletPos(i), m_pEnemy[k]->GetObjPos(j),
									PlayerArmGrenade::FIND_RANGE, m_pEnemy[k]->GetObjSize())) {
									pArmItem->Action(i);
								}
							}
							//爆発待ち時間か爆発中
							else if (Collision::ColBox(pArmItem->GetBulletPos(i), m_pEnemy[k]->GetObjPos(j),
								pArmItem->GetBulletSize(i), m_pEnemy[k]->GetObjSize())) {
								//プレイヤーの弾を消す
								pArmItem->DeleteBullet(i);
								i--;

								//爆発をセット
								m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));
								explosion_sound = true;

								//敵のHPを減らす
								//敵が死んだら...
								if (m_pEnemy[k]->ReduceHP(j, 1))
								{
									//敵アイテムのドロップ
									m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), (int)m_pEnemy[k]->GetType());

									//敵を消す
									m_pEnemy[k]->DeleteObj(j);

									j--;

									//倒した敵の数を増やす
									m_pScore->AddScore(1);

									if (j < 0) {
										next = true;
										break;
									}
								}

								if (i == -1) {
									break;
								}
							}
						}
						next_right = true;
					}

					break;

				default:
					break;
				}

				if (next_right) {
					//腕についているアイテムのポインタを取ってくる(二回目は右)
					pArmItem = m_pPlayerRight->GetArmPointer();

					//腕のポインタを取ってくる(二回目は右)
					pArm = m_pPlayerRight;

					continue;
				}

				//全部の処理
				for (int i = 0; i < pArmItem->GetBulletNum(); i++) {
					//もしも画面外にいたら壊せないようにする
					if (!ScreenOut::GetScreenOut(m_pEnemy[k]->GetObjPos(j),
						m_pEnemy[k]->GetObjSize())) {

						//当たったか判定
						if (Collision::ColBox(pArmItem->GetBulletPos(i), m_pEnemy[k]->GetObjPos(j),
							pArmItem->GetBulletSize(), m_pEnemy[k]->GetObjSize())) {

							//火星であれば...
							//腕の弾がSTOPなら
							if (pArmItem->GetType() == inhPlayerArm::TYPE::TYPE_STOP && m_stage == STAGE::MARS)
							{
								//敵の動きを１２０F止める
								PlaySound(m_SE_10, 0);
								m_pEnemy[k]->StopEnemy(j, 120);
								continue;
							}
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
								m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), (int)m_pEnemy[k]->GetType());

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

				//腕についているアイテムのポインタを取ってくる(二回目は右)
				pArmItem = m_pPlayerRight->GetArmPointer();

				//腕のポインタを取ってくる(二回目は右)
				pArm = m_pPlayerRight;
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

				//火星であれば...
				//冷気を出す敵であれば...
				if (m_pEnemy[k]->GetType() == EnemyManagement::TYPE::STOP && m_stage == STAGE::MARS)
				{
					//プレイヤーを動けなくする
					PlaySound(m_SE_10, 0);
					m_pPlayer->StopPlayer(60);
				}
				else
				{
					//爆発をセット
					m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));
					explosion_sound = true;

					//敵の弾を消す
					m_pEnemy[k]->DeleteBullet(j);
					j--;

				}
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
			inhPlayerArm* pArmItem = m_pPlayerLeft->GetArmPointer();
			//腕のポインタを取ってくる(初期は左から)
			inhPlayerArmBoth* pArm = m_pPlayerLeft;

			//右と左、両方行う
			for (int m = 0; m < 2; m++) {
				//ポインターがヌルであれば...
				// 火星でなければ...
				//バリアでなければ処理を行わない
				if (pArmItem != nullptr && pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE_BARRIAR &&
					m_stage == STAGE::MARS) {
					for (int i = 0; i < pArmItem->GetBulletNum(); i++) {
						if (Collision::ColBox(pArmItem->GetBulletPos(i), m_pEnemy[k]->GetBulletPos(j),
							pArmItem->GetBulletSize(), m_pEnemy[k]->GetBulletSize())) {
							//爆発をセット
							m_pExplosion->SetExplosion(m_pEnemy[k]->GetBulletPos(j));
							explosion_sound = true;

							//バリアのHPがなくなったら
							if (pArmItem->ReduceHP(m_pEnemy[k]->GetBulletAttack())) {
								//バリアを壊す
								pArmItem->DeleteBullet(i);
								PlaySound(m_SE_09, 0);
								i--;
							}

							//敵の弾を消す
							m_pEnemy[k]->DeleteBullet(j);
							j--;

							PlaySound(m_SE_08, 0);

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
				//腕のポインタを取ってくる(二回目は右)
				pArm = m_pPlayerRight;
			}
		}

		//=================================================
		// 敵の別オブジェクト分ループ
		
		//火星
		//バリア
		//グレネード敵
		for (int j = 0; j < m_pEnemy[k]->GetOtherNum() && m_stage == STAGE::MARS; j++) {
			bool next = false;

			//=================================================
			// プレイヤーと敵の別オブジェクト

			//プレイヤー
			//敵の別オブジェクト

				//自身
				//別オブジェクト
			switch (m_pEnemy[k]->GetType()) {

			case EnemyManagement::TYPE::BULLET_BARRIER:
				if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetOtherPos(j),
					m_pPlayer->GetSize() / 3, m_pEnemy[k]->GetOtherSize())) {
					if (m_pEnemy[k]->GetOtherAttack() != 0) {
						//爆発をセット
						m_pExplosion->SetExplosion(m_pEnemy[k]->GetOtherPos(j));
						explosion_sound = true;

						//ダメージ数を増やす
						attacked += m_pEnemy[k]->GetOtherAttack();
						//コンボを途切れさせる
						m_pScore->InitCombo();
					}
				}
				break;

			case EnemyManagement::TYPE::GRENADE:
				if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetOtherPos(j),
					m_pPlayer->GetSize() / 3, EnemyGrenadeManagement::OTHER_RANGE)) {
					m_pGrenade->SetExplosion(m_pEnemy[k]->GetOtherPos(j));
					m_pEnemy[k]->DeleteOther(j);
				}
				break;

			default:
				break;
			}

			//グレネード敵であればこれ以降の処理を行わない
			if (m_pEnemy[k]->GetType() == EnemyManagement::TYPE::GRENADE) {
				break;
			}
			//弾
			//別オブジェクト
			for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
				//もしも画面外にいたら壊せないようにする
				if (ScreenOut::GetScreenOut(m_pEnemy[k]->GetOtherPos(j),
					m_pEnemy[k]->GetOtherSize())) {
					continue;
				}

				//当たってなければ次行く
				if (!Collision::ColBox(m_pPlayer->GetBulletPos(i), m_pEnemy[k]->GetOtherPos(j),
					m_pPlayer->GetBulletSize(), m_pEnemy[k]->GetOtherSize())) {
					continue;
				}

				//プレイヤーの弾を消す
				m_pPlayer->DeleteBullet(i);
				i--;

				//爆発をセット
				m_pExplosion->SetExplosion(m_pEnemy[k]->GetOtherPos(j));
				explosion_sound = true;

				//敵の別オブジェクトのHPを減らす
				//敵の別オブジェクトのHPがなくなったら...
				if (m_pEnemy[k]->ReduceOtherHP(j, 1))
				{
					//敵の別オブジェクトを消す
					m_pEnemy[k]->DeleteOther(j);
					PlaySound(m_SE_09, 0);

					j--;
					if (j < 0) {
						next = true;
						break;
					}
				}
				else {
					PlaySound(m_SE_08, 0);
				}
			}

			if (next) {
				break;
			}

			//=================================================
			// プレイヤーの腕の弾と敵の別オブジェクト

			//プレイヤーの腕の弾方
			//敵の別オブジェクトの方

			//腕についているアイテムのポインタを取ってくる(初期は左から)
			inhPlayerArm* pArmItem = m_pPlayerLeft->GetArmPointer();
			//腕のポインタを取ってくる(初期は左から)
			inhPlayerArmBoth* pArm = m_pPlayerLeft;

			//右と左、両方行う
			for (int m = 0; m < 2; m++) {
				//ポインターがヌルであれば処理を行わない
				//バリアであれば処理を行わない
				if (pArmItem == nullptr || pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE_BARRIAR) {
					//腕についているアイテムのポインタを取ってくる(二回目は右)
					pArmItem = m_pPlayerRight->GetArmPointer();
					//腕のポインタを取ってくる(二回目は右)
					pArm = m_pPlayerLeft;

					continue;
				}

				for (int i = 0; i < pArmItem->GetBulletNum(); i++) {
					if (Collision::ColBox(pArmItem->GetBulletPos(i), m_pEnemy[k]->GetOtherPos(j),
						pArmItem->GetBulletSize(), m_pEnemy[k]->GetOtherSize())) {
						//爆発をセット
						m_pExplosion->SetExplosion(m_pEnemy[k]->GetOtherPos(j));
						explosion_sound = true;

						//腕についている種類がTYPE2(レーザー)でなければ...
						if (pArmItem->GetType() != inhPlayerArm::TYPE::TYPE_LASER) {
							//プレイヤーの弾を消す
							pArmItem->DeleteBullet(i);
							i--;
						}

						//敵の別オブジェクトのHPを減らす
						//敵の別オブジェクトのHPがなくなったら...
						if (m_pEnemy[k]->ReduceOtherHP(j, 1))
						{
							//敵の別オブジェクトを消す
							m_pEnemy[k]->DeleteOther(j);
							PlaySound(m_SE_09, 0);

							j--;
							if (j < 0) {
								next = true;
								break;
							}
						}
						else {
							PlaySound(m_SE_08, 0);
						}
					}
				}

				if (next) {
					break;
				}

				//腕についているアイテムのポインタを取ってくる(二回目は右)
				pArmItem = m_pPlayerRight->GetArmPointer();
				//腕のポインタを取ってくる(二回目は右)
				pArm = m_pPlayerLeft;
			}
		}
	}

	//===========================
	// 月、隕石
	if (m_stage == STAGE::MOON) {
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
				/*if (pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE_NONE ||
					pArm->GetType() == inhPlayerArmBoth::TYPE::TYPE_OLD)
				{
				}*/
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
