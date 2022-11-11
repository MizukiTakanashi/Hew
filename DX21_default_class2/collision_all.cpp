//============================================================
// 全てのゲームオブジェクトの当たり判定関係(cppファイル)
// 作成日：2022/11/10
// 作成者：高梨水希
//============================================================
#include "collision_all.h"
#include "collision.h"

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
CollisionAll::CollisionAll(Player* pPlayer, ExplosionManagement* pExplosion,
	ItemManagement* pItem, Number* pNumber)
	:m_pPlayer(pPlayer), m_pExplosion(pExplosion), m_pItem(pItem), m_pNumber(pNumber)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pEnemy[i] = nullptr;
	}
}

//==========================
// 当たり判定
//==========================
int CollisionAll::Collision(void)
{
	//プレイヤー自身が受けたダメージ数
	int attacked = 0;

	//敵の種類の数分ループ
	for (int k = 0; k < m_enemy_num; k++) {

		//=================================================
		//

		//プレイヤーの方
		//敵の方

			//弾
			//自身
		for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
			for (int j = 0; j < m_pEnemy[k]->GetObjNum(); j++) {

				//もしも画面外にいたら壊せないようにする
				if (!ScreenOut::GetScreenOut(m_pEnemy[k]->GetObjPos(j),
					m_pEnemy[k]->GetObjSize())) {

					//当たったか判定
					if (Collision::ColBox(m_pPlayer->GetBulletPos(i), m_pEnemy[k]->GetObjPos(j),
						m_pPlayer->GetBulletSize(), m_pEnemy[k]->GetObjSize())) {
						//爆発をセット
						m_pExplosion->SetExplosion(m_pEnemy[k]->GetObjPos(j));
						//敵アイテムのドロップ
						m_pItem->SetItem(m_pEnemy[k]->GetObjPos(j), k);

						//プレイヤーの弾を消す
						m_pPlayer->DeleteBullet(i);
						i--;
						//敵を消す
						m_pEnemy[k]->DeleteObj(j);
						j--;

						//倒した敵の数を増やす
						m_pNumber->AddNumber(1);
					}
				}
			}
		}

		//弾
		//弾
		for (int i = 0; i < m_pPlayer->GetBulletNum(); i++) {
			for (int j = 0; j < m_pEnemy[k]->GetBulletNum(); j++) {
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
		}

		//自身
		//弾
		for (int j = 0; j < m_pEnemy[k]->GetBulletNum(); j++) {
			if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetBulletPos(j),
				m_pPlayer->GetSize(), m_pEnemy[k]->GetBulletSize())) {

				//敵の弾を消す
				m_pEnemy[k]->DeleteBullet(j);
				j--;
				//ダメージ数を増やす
				attacked += m_pEnemy[k]->GetBulletAttack();
			}
		}

		//自身
		//自身
		for (int j = 0; j < m_pEnemy[k]->GetObjNum(); j++) {
			D3DXVECTOR2 Hoge = m_pEnemy[k]->GetObjPos(0);

			if (Collision::ColBox(m_pPlayer->GetPos(), m_pEnemy[k]->GetObjPos(0),
				m_pPlayer->GetSize(), m_pEnemy[k]->GetObjSize())) {
				//一度離れてからじゃないともう一度当たった判定にはならない
				if (!m_player_enemy_col) {
					//ぶつかったフラグをオン
					m_player_enemy_col = true;

					//ダメージ数を増やす
					attacked += m_pEnemy[k]->GetObjAttack();
				}
			}
			else {
				m_player_enemy_col = false;
			}
		}

		if (m_pPlayerRight->GetType() == inhPlayerArmBoth::TYPE::TYPE_SHOOT) {

		}
	}

	return attacked;
}
