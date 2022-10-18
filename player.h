//=======================================
// �v���C���[�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/06/27
// �쐬�ҁF��������
//=======================================

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "main.h"
#include "DrawObject.h"
#include "GameObject.h"
#include "bullet.h"

//======================
// �}�N����`
//======================

class Player:public GameObject
{
private:
	//�萔

	//�v���C���[�{��
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY
	static const float SPEED_X;		//�X�s�[�hX
	static const float SPEED_Y;		//�X�s�[�hY
	static const float SPEED;		//�X�s�[�h

	//�e
	//�����ŏ�����
	static const int BULLET_MAX_NUM = 100;		//�v���C���[�̒e�̑���
	static const int BULLET_INTERVAL_TIME = 50;	//�e�̔��ˊԊu
	
	static const float BULLET_SIZE_X;			//�e�̃T�C�YX
	static const float BULLET_SIZE_Y;			//�e�̃T�C�YY
	static const float BULLET_SPEED_X;			//�e�̃X�s�[�hX

private:
	Bullet* m_pBullet = nullptr;
	int m_BulletNum = 0;			//�e�̌��݂̐�
	DrawObject m_BulletDrawObject;
	int m_BulletInterval = 0;		//�e�̔��ˊԊu

public:
	//�f�t�H���g�R���X�g���N�^
	Player() { m_pBullet = new Bullet[BULLET_MAX_NUM]; }

	//�����t���R���X�g���N�^
	Player(DrawObject& pDrawObject, DrawObject& BulletDrawObject)
		:GameObject(pDrawObject, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)),
		m_BulletDrawObject(BulletDrawObject)
	{ m_pBullet = new Bullet[BULLET_MAX_NUM]; }

	~Player() { delete[] m_pBullet; }		//�f�X�g���N�^

	//�X�V����
	void Update();

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
};

#endif // !_PLAYER_H_
