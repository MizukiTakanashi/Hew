//=======================================
// レーザー関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "laser.h"

//==========================
// 定数初期化
//==========================
const float Laser::SPEED_X = 15.0f;
const float Laser::SPEED_Y = 15.0f;

//==========================
// 更新処理
//==========================
void Laser::Update(const D3DXVECTOR2& pos, bool down)
{
	//レーザーの残り時間減少
	m_lasertime--;

	if (m_lasertime < 0) //レーザーの射出時間が終わったか
	{
		switch (m_direction) {

		case DIRECTION::NONE:
			//下向きなのであれば...
			if (down) {
				//レーザーを下へ移動
				GameObject::SetPos(D3DXVECTOR2(GameObject::GetPos().x, GameObject::GetPos().y + SPEED_Y));
			}
			//上向きなのであれば...
			else {
				//レーザーを上へ移動
				GameObject::SetPos(D3DXVECTOR2(GameObject::GetPos().x, GameObject::GetPos().y - SPEED_Y));
			}

			break;

		case DIRECTION::LEFT:
			//レーザーを左へ移動
			GameObject::MovePos(D3DXVECTOR2(-SPEED_X, 0.0f));

			break;

		case DIRECTION::RIGHT:
			//レーザーを左へ移動
			GameObject::MovePos(D3DXVECTOR2(SPEED_X, 0.0f));

			break;
		}
	}
	else
	{
		switch (m_direction) {

		case DIRECTION::NONE:
			//下向きなのであれば...
			if (down) {
				//レーザーを長くする
				GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x, GameObject::GetSize().y + SPEED_Y * 2));
				//レーザーのX座標をエネミーに合わせる、レーザーを下へ移動
				GameObject::SetPos(D3DXVECTOR2(pos.x, pos.y + GameObject::GetSize().y / 2));
			}
			//上向きなのであれば...
			else {
				//レーザーを長くする
				GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x, GameObject::GetSize().y + SPEED_Y * 2));
				//レーザーのX座標をエネミーに合わせる、レーザーを上へ移動
				GameObject::SetPos(D3DXVECTOR2(pos.x, pos.y - GameObject::GetSize().y / 2));
			}

			break;

		case DIRECTION::LEFT:
			//レーザーを長くする
			GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x + SPEED_X * 2, GameObject::GetSize().y));
			//レーザーのY座標をエネミーに合わせる、レーザーを左へ移動
			GameObject::SetPos(D3DXVECTOR2(pos.x - GameObject::GetSize().x / 2, pos.y));

			break;

		case DIRECTION::RIGHT:
			//レーザーを長くする
			GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x + SPEED_X * 2, GameObject::GetSize().y));
			//レーザーのY座標をエネミーに合わせる、レーザーを右へ移動
			GameObject::SetPos(D3DXVECTOR2(pos.x + GameObject::GetSize().x / 2, pos.y));

			break;
		}
	}

}