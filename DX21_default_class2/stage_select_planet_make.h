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
// �ΐ�
//==========================
class StageSelectMars :public GameObject
{
	//�萔
private:
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY


	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectMars() {}

	//�����t���R���X�g���N�^
	StageSelectMars(DrawObject& pDrawObj) 
		:GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectMars() {}
};

//==========================
// ����
//==========================
class StageSelectMercury :public GameObject
{
	//�萔
private:
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY


	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectMercury() {}

	//�����t���R���X�g���N�^
	StageSelectMercury(DrawObject& pDrawObj) 
		:GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectMercury() {}
};

//==========================
// �ؐ�
//==========================
class StageSelectJupiter :public GameObject
{
	//�萔
private:
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY


	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectJupiter() {}

	//�����t���R���X�g���N�^
	StageSelectJupiter(DrawObject& pDrawObj) 
		:GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectJupiter() {}
};

//==========================
// ����
//==========================
class StageSelectVenus :public GameObject
{
	//�萔
private:
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY


	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectVenus() {}

	//�����t���R���X�g���N�^
	StageSelectVenus(DrawObject& pDrawObj)
		:GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectVenus() {}
};

//==========================
// �y��
//==========================
class StageSelectSaturn :public GameObject
{
	//�萔
private:
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY


	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectSaturn() {}

	//�����t���R���X�g���N�^
	StageSelectSaturn(DrawObject& pDrawObj)
		:GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectSaturn() {}
};

//==========================
// ���z
//==========================
class StageSelectSun :public GameObject
{
	//�萔
private:
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY


	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectSun() {}

	//�����t���R���X�g���N�^
	StageSelectSun(DrawObject& pDrawObj)
		:GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectSun() {}
};

#endif // !_STAGE_SELECT_PLANET_MAKE_H_