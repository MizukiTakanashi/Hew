//=======================================
// ���ʂ̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _ENEMY_NORMAL_MANAGEMENT_H_
#define _ENEMY_NORMAL_MANAGEMENT_H_

#include "main.h"
#include "EnemyNormal.h"
#include "bullet.h"
#include "DrawObject.h"
#include "EnemySetPos.h"
#include "player.h"

class EnemyNormalManagement
{
//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int MAX_NUM = 10;			//�G�̍ő吔
	static const int APPEARANCE_TIME = 200;	//�G�̏o���X�s�[�h

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

	int m_enemy_num = 0;	//�G�̐�
	int m_bullet_num = 0;	//�e�̐�

	int m_count = 0;		//�G�̏o�����x

public:
	//�f�t�H���g�R���X�g���N�^
	EnemyNormalManagement(){
		m_pEnemyNormal = new EnemyNormal[MAX_NUM];
		m_pBullet = new Bullet[MAX_NUM];
	}	

	//�����t���R���X�g���N�^
	EnemyNormalManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, 
		EnemySetPos& pEnemySetPos);

	//�X�V����
	void Update(const D3DXVECTOR2& PlayerPos);

	//�`�揈��
	void Draw(void)const;			


	//�w�肵���G������
	void DeleteEnemy(int index_num);

	//���݂̓G�̐���Ԃ�
	int GetEnemyNum(void)const { return m_enemy_num; }

	//�w�肵���G�̍��W��Ԃ�
	const D3DXVECTOR2& GetEnemyPos(int index_num)const { return m_pEnemyNormal[index_num].GetPos(); }

	//�G�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetEnemySize(void)const { return m_pEnemyNormal[0].GetSize(); }


	//�w�肵���e������
	void DeleteBullet(int index_num);

	//���݂̒e�̐���Ԃ�
	int GetBulletNum(void)const { return m_bullet_num; }

	//�w�肵���e�̍��W��Ԃ�
	const D3DXVECTOR2& GetBulletPos(int index_num)const { return m_pBullet[index_num].GetPos(); }

	//�e�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetBulletSize(void)const { return m_pBullet[0].GetSize(); }
};

#endif // !_ENEMY_NORMAL_MANAGEMENT_H_