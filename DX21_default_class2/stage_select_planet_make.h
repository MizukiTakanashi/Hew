#pragma once
//=======================================
// �f������֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/30
// �쐬�ҁF��������
//=======================================

#ifndef _STAGE_SELECT_PLANET_MAKE_H_
#define _STAGE_SELECT_PLANET_MAKE_H_

#include "game_object.h"

//==========================
// �f��(�|�����[�t�B�Y���p)
//==========================
class inhStageSelectPlanetMake :public GameObject
{
//�����o�ϐ�
private:
	D3DXVECTOR2 m_small_size = D3DXVECTOR2(0.0f, 0.0f);
	D3DXVECTOR2 m_big_size = D3DXVECTOR2(0.0f, 0.0f);


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	inhStageSelectPlanetMake(){}

	//�����t���R���X�g���N�^
	inhStageSelectPlanetMake(DrawObject& pDrawObj, D3DXVECTOR2 pos, D3DXVECTOR2 small_size, D3DXVECTOR2 big_size)
		:GameObject(pDrawObj, pos, small_size), m_small_size(small_size), m_big_size(big_size) {}

	//�f�X�g���N�^
	virtual ~inhStageSelectPlanetMake()override{}

	//����������
	void SetSizeSmaller(void) { GameObject::SetSize(m_small_size); }

	//�傫������
	void SetSizeBigger(void) { GameObject::SetSize(m_big_size); }
};

//==========================
// �ΐ�
//==========================
class StageSelectMars :public inhStageSelectPlanetMake
{
//�萔
private:
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float BIG_BOX_W;	//�傫���Ȃ鎞�̎l�p�`�̉��̃T�C�Y
	static const float BIG_BOX_H;	//�傫���Ȃ鎞�̎l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectMars() {}

	//�����t���R���X�g���N�^
	StageSelectMars(DrawObject& pDrawObj) 
		:inhStageSelectPlanetMake(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y),
			D3DXVECTOR2(BOX_W, BOX_H), D3DXVECTOR2(BIG_BOX_W, BIG_BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectMars()override {}
};

//==========================
// ����
//==========================
class StageSelectMercury :public inhStageSelectPlanetMake
{
//�萔
private:
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float BIG_BOX_W;	//�傫���Ȃ鎞�̎l�p�`�̉��̃T�C�Y
	static const float BIG_BOX_H;	//�傫���Ȃ鎞�̎l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectMercury() {}

	//�����t���R���X�g���N�^
	StageSelectMercury(DrawObject& pDrawObj) 
		:inhStageSelectPlanetMake(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), 
			D3DXVECTOR2(BOX_W, BOX_H), D3DXVECTOR2(BIG_BOX_W, BIG_BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectMercury()override {}
};

//==========================
// �ؐ�
//==========================
class StageSelectJupiter :public inhStageSelectPlanetMake
{
//�萔
private:
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float BIG_BOX_W;	//�傫���Ȃ鎞�̎l�p�`�̉��̃T�C�Y
	static const float BIG_BOX_H;	//�傫���Ȃ鎞�̎l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectJupiter() {}

	//�����t���R���X�g���N�^
	StageSelectJupiter(DrawObject& pDrawObj) 
		:inhStageSelectPlanetMake(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), 
			D3DXVECTOR2(BOX_W, BOX_H), D3DXVECTOR2(BIG_BOX_W, BIG_BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectJupiter()override {}
};

//==========================
// ����
//==========================
class StageSelectVenus :public inhStageSelectPlanetMake
{
//�萔
private:
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float BIG_BOX_W;	//�傫���Ȃ鎞�̎l�p�`�̉��̃T�C�Y
	static const float BIG_BOX_H;	//�傫���Ȃ鎞�̎l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectVenus() {}

	//�����t���R���X�g���N�^
	StageSelectVenus(DrawObject& pDrawObj)
		:inhStageSelectPlanetMake(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), 
			D3DXVECTOR2(BOX_W, BOX_H), D3DXVECTOR2(BIG_BOX_W, BIG_BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectVenus()override {}
};

//==========================
// �y��
//==========================
class StageSelectSaturn :public inhStageSelectPlanetMake
{
//�萔
private:
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float BIG_BOX_W;	//�傫���Ȃ鎞�̎l�p�`�̉��̃T�C�Y
	static const float BIG_BOX_H;	//�傫���Ȃ鎞�̎l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectSaturn() {}

	//�����t���R���X�g���N�^
	StageSelectSaturn(DrawObject& pDrawObj)
		:inhStageSelectPlanetMake(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), 
			D3DXVECTOR2(BOX_W, BOX_H), D3DXVECTOR2(BIG_BOX_W, BIG_BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectSaturn()override {}
};

//==========================
// ���z
//==========================
class StageSelectSun :public inhStageSelectPlanetMake
{
//�萔
private:
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float BIG_BOX_W;	//�傫���Ȃ鎞�̎l�p�`�̉��̃T�C�Y
	static const float BIG_BOX_H;	//�傫���Ȃ鎞�̎l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectSun() {}

	//�����t���R���X�g���N�^
	StageSelectSun(DrawObject& pDrawObj)
		:inhStageSelectPlanetMake(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), 
			D3DXVECTOR2(BOX_W, BOX_H), D3DXVECTOR2(BIG_BOX_W, BIG_BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectSun()override {}
};

#endif // !_STAGE_SELECT_PLANET_MAKE_H_