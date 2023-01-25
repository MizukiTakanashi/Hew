//=======================================
// �v���C���[�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/06/27
// �쐬�ҁF��������
//=======================================

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "main.h"
#include "draw_object.h"
#include "game_object.h"
#include "bullet.h"
#include "sound.h"

//======================
// �}�N����`
//======================

class Player:public GameObject
{
//�萔
private:
	//�v���C���[�{��
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY
	static const float SPEED_X;		//�X�s�[�hX
	static const float SPEED_Y;		//�X�s�[�hY
	static const float SPEED;		//�X�s�[�h
	static const float SLOW_SPEED_X;//�������x�����̃X�s�[�hX
	static const float SLOW_SPEED_Y;//�������x�����̃X�s�[�hY
	static const float SLOW_SPEED;	//�������x�����̃X�s�[�h

	//�e
	//�����ŏ�����
	static const int BULLET_MAX_NUM = 100;		//�v���C���[�̒e�̑���
	static const int BULLET_INTERVAL_TIME = 20;	//�e�̔��ˊԊu
	
	//cpp�ŏ�����
	static const float BULLET_SIZE_X;			//�e�̃T�C�YX
	static const float BULLET_SIZE_Y;			//�e�̃T�C�YY
	static const float BULLET_SPEED_X;			//�e�̃X�s�[�hX
	static const float BULLET_SPEED_Y;			//�e�̃X�s�[�hY

	static const D3DXCOLOR INVINCIBLE__COLOR;	//�v���C���[���G���Ԃ̐F

//�����o�ϐ�
private:
	DrawObject m_draw_default;		//�f�t�H���g�`��I�u�W�F�N�g
	DrawObject m_draw_fire;			//���`��I�u�W�F�N�g

	Bullet* m_pBullet = nullptr;
	DrawObject m_BulletDrawObject;
	int m_BulletNum = 0;			//�e�̌��݂̐�
	int m_BulletInterval = 0;		//�e�̔��ˊԊu
	
	DrawObject m_BomDrawObject;
	int m_BomNum = 0;				//���e�̌��݂̐�
	int m_BomInterval = 0;			//���e�̔��ˊԊu

	int m_stop_time = 0;			//player�̃A�b�v�f�[�g���~�߂鎞��
	bool m_slow = false;			//�������x���t���O
	int m_slow_time = -1;			//�������x���Ԃ̍ő厞��

	int m_SE_20 = 0;				//���ˉ�

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	Player() {
		m_pBullet = new Bullet[BULLET_MAX_NUM];
	}

	//�����t���R���X�g���N�^
	Player(DrawObject& pDrawObject, DrawObject& BulletDrawObject,DrawObject& BomDrawObject)
		:GameObject(pDrawObject, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)),
		m_BulletDrawObject(BulletDrawObject),m_BomDrawObject(BomDrawObject), m_draw_default(pDrawObject) {
		m_pBullet = new Bullet[BULLET_MAX_NUM];
		m_SE_20 = LoadSound((char*)"data\\SE\\2_22.wav");
		SetVolume(m_SE_20, 0.2f);
	}

	~Player()override {
		delete[] m_pBullet;
	}		//�f�X�g���N�^

	//�X�V����
	void Update(bool);

	//�e�̕`�揈��
	void DrawBullet(void)const;

	//���ݒe�̐���Ԃ�
	int GetBulletNum(void)const { return m_BulletNum; }

	//�w�肵���e������
	void DeleteBullet(int index_num);

	//�w�肵���e�̍��W��Ԃ�
	const D3DXVECTOR2& GetBulletPos(int index_num)const { return m_pBullet[index_num].GetPos(); }

	//�e�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetBulletSize(void)const { return m_pBullet[0].GetSize(); }

	//���ݔ��e�̐���Ԃ�
	int GetBomNum(void)const { return m_BomNum; }

	//�~�߂鎞�Ԃ��Z�b�g
	void StopPlayer(int time) { m_stop_time = time; }

	//�������x���t���O���Z�b�g
	void SetSlow(bool slow, int time = -100) { 
		m_slow = slow; 
		m_slow_time = time;
	}

	//===================
	// ����
	//����Ԃ̕`��I�u�W�F�N�g���Z�b�g
	void SetDrawFire(DrawObject& pDraw) { m_draw_fire = pDraw; }

	//����Ԃ��ǂ������Z�b�g
	void SetFire(bool fire);
};

#endif // !_PLAYER_H_
