//=======================================
// 爆発関係(cppファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================

#include "explosion.h"

//==========================
// 定数初期化
//==========================
const float Explosion::SIZE_X = 50.0f;
const float Explosion::SIZE_Y = 50.0f;
const float Explosion::ANIME_SPEED = 0.2f;

//======================
// 更新処理
//======================
void Explosion::Update(void)
{
	//アニメーション番号を変えていく
	if (m_AnimationNum <= ANIME_MAX) {
		m_AnimationNum += ANIME_SPEED;
		GameObject::SetAnimationNum(m_AnimationNum);
	}
	else {
		m_EndAnimation = true;
	}
}