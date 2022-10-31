//=======================================
// ���ʂ̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _ENEMY_NORMAL_MANAGEMENT_H_
#define _ENEMY_NORMAL_MANAGEMENT_H_

#include "main.h"
#include "EnemyManagement.h"
#include "EnemyNormal.h"
#include "bullet.h"
#include "DrawObject.h"
#include "EnemySetPos.h"

class EnemyNormalManagement:public EnemyManagement
{
//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int MAX_NUM = 10;				//�G�̍ő吔
	static const int APPEARANCE_TIME = 200;		//�G�̏o���X�s�[�h
	static const int BULLET_BREAK_TIME = 200;	//�z�[�~���O�e�����鎞��

	//cpp�ŏ�����
	//�e
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY
	static const float BULLET_SPEED;		//�X�s�[�h

public:
	//�����ŏ�����
	//�G���g
	static const int ATTACK = 1;			//�U���l
	//�e
	static const int BULLET_ATTACK = 1;		//�U���l


private:
	//�����o�ϐ�
	EnemyNormal* m_pEnemyNormal = nullptr;
	Bullet* m_pBullet = nullptr;
	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectBullet;
	EnemySetPos m_pEnemySetPos;

	int m_EnemyItem_num = 0;	//�G�̃A�C�e���̐�

	int m_count = 0;		//�G�̏o�����x

public:
	//�f�t�H���g�R���X�g���N�^
	EnemyNormalManagement(){
		m_pEnemyNormal = new EnemyNormal[MAX_NUM];
		m_pBullet = new Bullet[MAX_NUM];
	}	

	//�����t���R���X�g���N�^
	EnemyNormalManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2,
		EnemySetPos& pEnemySetPos );

	//�f�X�g���N�^
	~EnemyNormalManagement()override { delete[] m_pEnemyNormal; delete[] m_pBullet; }

	//�X�V����
	void Update(const D3DXVECTOR2& PlayerPos);

	//�`�揈��
	void Draw(void)const;			

	//�w�肵���G������
	void DeleteObj(int index_num)override;

	//�w�肵���e������
	void DeleteBullet(int index_num)override;

	//�w�肵���ԍ��̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyNormal[index_num].GetPos(); }

	//�w�肵���ԍ��̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyNormal[index_num].GetSize(); }

	//�w�肵���e�̍��W��Ԃ�
	const D3DXVECTOR2& GetBulletPos(int index_num)const override{ return m_pBullet[index_num].GetPos(); }

	//�e�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override{ return m_pBullet[index_num].GetSize(); }
};

#endif // !_ENEMY_NORMAL_MANAGEMENT_H_