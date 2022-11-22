//=======================================
// ���ʂ̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _ENEMY_NORMAL_MANAGEMENT_H_
#define _ENEMY_NORMAL_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_normal.h"
#include "bullet.h"
#include "draw_object.h"
#include "enemy_set_pos.h"

class EnemyNormalManagement:public EnemyManagement
{
//�萔
private:
	//�����ŏ�����
	//�G���g
	static const int ENEMY_NUM = 12;		//�G���o�������鐔
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

//�����o�ϐ�
private:
	EnemyNormal* m_pEnemyNormal = nullptr;
	Bullet* m_pBullet = nullptr;
	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectBullet;
	EnemySetPos m_pEnemySetPos;

	int m_EnemyItem_num = 0;	//�G�̃A�C�e���̐�

	//�G�̔z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = { D3DXVECTOR2(52.5f + (105 * 1 - 1), -EnemyNormal::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 2 - 1), -EnemyNormal::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 3 - 1), -EnemyNormal::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 4 - 1), -EnemyNormal::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 5 - 1), -EnemyNormal::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 6 - 1), -EnemyNormal::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 7 - 1), -EnemyNormal::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 8 - 1), -EnemyNormal::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 9 - 1), -EnemyNormal::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 10 - 1), -EnemyNormal::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 11 - 1), -EnemyNormal::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 12 - 1), -EnemyNormal::SIZE_Y / 2) };

	int m_SetEnemyTime[ENEMY_NUM] = {	60 * 3,
								60 * 6,
								60 * 9,
								60 * 12,
								60 * 15,
								60 * 18,
								60 * 21,
								60 * 24,
								60 * 27,
								60 * 30,
								60 * 33,
								60 * 36};
//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyNormalManagement(){
		m_pEnemyNormal = new EnemyNormal[ENEMY_NUM];
		m_pBullet = new Bullet[ENEMY_NUM];
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