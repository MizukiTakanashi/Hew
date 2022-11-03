//=======================================
// レーザー関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "laser.h"

//==========================
// 定数初期化
//==========================
const float Laser::SPEED_Y = 15.0f;
const int Laser::LASER_TIME = 150;

void Laser::Update(const D3DXVECTOR2& pos, bool down)
{
	//レーザーの残り時間減少
	m_lasertime--;

	if (m_lasertime < 0) //レーザーの射出時間が終わったか
	{
		//下向きなのであれば...
		if(down){
			//レーザーを下へ移動
			GameObject::SetPos(D3DXVECTOR2(GameObject::GetPos().x, GameObject::GetPos().y + SPEED_Y));
		}
		//上向きなのであれば...
		else {
			//レーザーを上へ移動
			GameObject::SetPos(D3DXVECTOR2(GameObject::GetPos().x, GameObject::GetPos().y - SPEED_Y));
		}
	}
	else
	{
		//下向きなのであれば...
		if (down) {
			//レーザーを長くする
			GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x, GameObject::GetSize().y + SPEED_Y * 2));
			//レーザーのX座標をエネミーに合わせる、レーザーを下へ移動
			GameObject::SetPos(D3DXVECTOR2(pos.x, GameObject::GetPos().y + SPEED_Y));
		}
		//上向きなのであれば...
		else {
			//レーザーを長くする
			GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x, GameObject::GetSize().y + SPEED_Y * 2));
			//レーザーのX座標をエネミーに合わせる、レーザーを上へ移動
			GameObject::SetPos(D3DXVECTOR2(pos.x, GameObject::GetPos().y - SPEED_Y));
		}
	}

}