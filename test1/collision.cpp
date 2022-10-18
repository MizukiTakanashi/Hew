//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================

//==============================================
//インクルード
//==============================================
#include "collision.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "explosion.h"

//==============================================
// マクロ定義
//==============================================


//==============================================
// プロトタイプ宣言
//==============================================
bool CollisionBB(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2,
				 D3DXVECTOR2 size1, D3DXVECTOR2 size2);

bool CollisionBC(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2,
				 float size1, float size2);


//==============================================
// グローバル変数
//==============================================


//==============================================
// 初期化処理
//==============================================


//==============================================
// 終了処理
//==============================================


//==============================================
// 更新処理
//==============================================
void UpdateCollision(void)
{
	//プレイヤー　対　敵キャラ
	PLAYER* player = GetPlayer();		//プレイヤー構造体のポインタ取得
	ENEMY* enemy = GetEnemy();			//エネミー構造体のポインタ取得
	BULLET* bullet = GetBullet();		//バレット構造体のポインタ取得

	//プレイヤーとエネミーの当たり判定
	for (int j = 0; j < PLAYER_MAX; j++)
	{
		if (player[j].isUse)
		{
			for (int i = 0; i < ENEMY_MAX; i++)
			{
				if (enemy[i].isUse  && enemy[i].FrameWait == 0)
				{
					//当たり判定を行う
					bool hit = CollisionBB(player[j].Position, enemy[i].Position,
										   player[j].Size, enemy[i].Size);
					if (hit)	//当たっているか？
					{//当たっている
						player[j].HP--;	//HP減小
						player[j].DamageWait = 60 * 0.5f;	//0.5秒間くらい

					}
					else
					{//当たっていない

					}
				}
			}
		}
	}

	//エネミーとバレットの当たり判定
	for (int j = 0; j < BULLET_MAX; j++)
	{
		if (bullet[j].isUse)
		{
			for (int i = 0; i < ENEMY_MAX; i++)
			{
				if (enemy[i].isUse && enemy[i].FrameWait == 0)
				{
					//当たり判定を行う
					bool hit = CollisionBB(bullet[j].Position, enemy[i].Position,
						bullet[j].Size, enemy[i].Size);
					if (hit)	//当たっているか？
					{//当たっている
						bullet[j].isUse = false;
						enemy[i].isUse = false;
						SetExplosion(enemy[i].Position, 0.1f);
					}
					else
					{//当たっていない

					}
				}
			}
		}
	}




	//プレイヤー　対　敵弾
	//プレイヤー弾　対　敵キャラ
	//など必要な条件をここへ全て作る

}


//==============================================
// 描画処理
//==============================================


//==============================================
//四角形と四角形の当たり判定処理
//in  中心座標１，中心座標２、　サイズ１、　サイズ２
//out true:衝突している false:衝突していない
//==============================================
bool CollisionBB(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2,
				 D3DXVECTOR2 size1, D3DXVECTOR2 size2)
{
	D3DXVECTOR2 min1, min2;		//四角形最小座標
	D3DXVECTOR2 max1, max2;		//四角形最大座標

	min1.x = pos1.x - size1.x / 2;	//四角形１　左上
	min1.y = pos1.y - size1.y / 2;

	max1.x = pos1.x + size1.x / 2;	//四角形１　右下
	max1.y = pos1.y + size1.y / 2;

	min2.x = pos2.x - size2.x / 2;	//四角形２　左上
	min2.y = pos2.y - size2.y / 2;

	max2.x = pos2.x + size2.x / 2;	//四角形２　右下
	max2.y = pos2.y + size2.y / 2;


	//衝突の判定
	if (max1.x < min2.x) return false;	//判定１
	if (max1.y < min2.y) return false;	//判定２

	if (max2.x < min1.x) return false;	//判定３
	if (max2.y < min1.y) return false;	//判定４


	//衝突している
	return true;

}

//==============================================
//円と円の当たり判定処理
//in  中心座標１，中心座標２、　半径１、　半径２
//out true:衝突している false:衝突していない
//==============================================
bool CollisionBC(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2,
				 float size1, float size2)
{
	//中心同士のベクトル
	D3DXVECTOR2 vDistance = pos1 - pos2;
	//ベクトルの長さを作る
	float Length;
	Length = D3DXVec2LengthSq(&vDistance);	//ルートを使わない版
	//Length = D3DXVec2Length(&vDistance);	//ルートを使う版(正確な長さ)

	//半径の総和
	float size = (size1 + size2) * (size1 * size2);	//ルート使わない2乗版
	//float size = (size1 + size2);	//ルート使う版

	//Lenghtがsizeより短ければ衝突している
	if (Length < size)
	{
		return true;	//衝突している
	}

	return false;		//衝突していない
}

