//=======================================
// �����֌W(�w�b�_�t�@�C��)
// �쐬���F2022/07/14
// �쐬�ҁF��������
//=======================================

#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

#include "GameObject.h"
#include "DrawObject.h"
#include "main.h"

class Explosion:public GameObject
{
private:
	//�萔
	//�����ŏ�����
	static const int ANIME_MAX = 7;	//�A�j���[�V������

	//cpp�ŏ�����
	static const float SIZE_X;		//�T�C�YX
	static const float SIZE_Y;		//�T�C�YY
	static const float ANIME_SPEED;	//�A�j���[�V�����̃X�s�[�h

private:
	//�����o�ϐ�
	float m_AnimationNum = 0.0f;
	bool m_EndAnimation = false;

public:
	Explosion(){}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	Explosion(DrawObject& DrawObject, const D3DXVECTOR2& pos)
		:GameObject(DrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)){}

	~Explosion(){}

	//�X�V����
	void Update(void);

	//�A�j���[�V�������I��������t���O��Ԃ�
	bool GetEndAnimation(void)const { return m_EndAnimation; }
};

#endif // !_EXPLOSION_H_
