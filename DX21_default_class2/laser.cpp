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


void Laser::Update(void)
{
	//レーザーの残り時間減少
	m_lasertime--;

	if (GameObject::GetSize().y > SCREEN_HEIGHT) //レーザーが十分な長さになったか
	{
		if (m_lasertime < 0) //レーザーの射出時間が終わったか
		{
			//レーザーを短くする
			GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x, GameObject::GetSize().y - SPEED_Y * 2));
		}
		//レーザーのX座標をエネミーに合わせる
		GameObject::SetPos(D3DXVECTOR2(m_pEnemynum->GetPos().x, GameObject::GetPos().y));
	}
	else
	{
		//レーザーを長くする
		GameObject::SetSize(D3DXVECTOR2(GameObject::GetSize().x, GameObject::GetSize().y + SPEED_Y * 2));
		//レーザーのX座標をエネミーに合わせる
		GameObject::SetPos(D3DXVECTOR2(m_pEnemynum->GetPos().x, GameObject::GetPos().y + SPEED_Y));
	}


}