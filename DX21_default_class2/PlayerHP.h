//=======================================
// �v���C���[��HP�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/17
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _PLAYER_HP_H_
#define _PLAYER_HP_H_

#include "DrawObject.h"
#include "UI.h"

//======================
// �}�N����`
//======================
#define PLAYER_HP_POS_Y (PLAYER_HP_SIZE_Y / 2 + PLAYER_HP_POS_SPACE_X)

class PlayerHP:public UI
{
private:
	//�萔
	//cpp�ŏ�����
	static const float HP_MAX;			//�ő�HP
	static const float SIZE_X;			//�T�C�YX
	static const float SIZE_Y;			//�T�C�YY
	static const float FLAME_SIZE_X;	//�t���[���T�C�YX
	static const float FLAME_SIZE_Y;	//�t���[���T�C�YY
	static const float POS_SPACE_X;		//�[����ǂꂭ�炢����Ă��邩X
	static const float POS_SPACE_Y;		//�[����ǂꂭ�炢����Ă��邩Y
	static const float POS_X;			//�\���ʒu
	static const float POS_Y;			//�\���ʒu

private:
	bool m_HP0 = false;
	DrawObject m_frame_DrawObject;
	float m_hp = HP_MAX;

public:
	PlayerHP() { m_hp = HP_MAX; }	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerHP(DrawObject& DrawObject1, DrawObject& DrawObject2) 
		:UI(DrawObject1, D3DXVECTOR2(POS_X, POS_Y),
		D3DXVECTOR2(SIZE_X, SIZE_Y)), m_frame_DrawObject(DrawObject2){}

	~PlayerHP(){}							//�f�X�g���N�^

	//HP�����炷
	void ReduceHP(float reduce_num);

	//�`��
	void DrawHP(void)const;

	//HP��0�ɂȂ������ǂ����̃t���O��Ԃ�
	bool GetHP0Flag(void)const { return m_HP0; }
};

#endif // !_PLAYER_HP_H_