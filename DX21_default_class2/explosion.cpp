//=======================================
// �����֌W(cpp�t�@�C��)
// �쐬���F2022/07/14
// �쐬�ҁF��������
//=======================================

#include "explosion.h"

//==========================
// �萔������
//==========================
const float Explosion::SIZE_X = 50.0f;
const float Explosion::SIZE_Y = 50.0f;
const float Explosion::ANIME_SPEED = 0.2f;

//======================
// �X�V����
//======================
void Explosion::Update(void)
{
	//�A�j���[�V�����ԍ���ς��Ă���
	if (m_AnimationNum <= ANIME_MAX) {
		m_AnimationNum += ANIME_SPEED;
		GameObject::SetAnimationNum(m_AnimationNum);
	}
	else {
		m_EndAnimation = true;
	}
}