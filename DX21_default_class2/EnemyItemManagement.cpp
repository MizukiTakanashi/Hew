//=======================================
// ���ʂ̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#include "EnemyItemManagemant.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// �萔�̏�����
//==========================
const float EnemyItemManagement::ENEMYITEM_SIZE_X = 40.0f;
const float EnemyItemManagement::ENEMYITEM_SIZE_Y = 40.0f;
const float EnemyItemManagement::ENEMYITEM_SPEED = 2.5f;

//=========================
// �����t���R���X�g���N�^
//=========================
EnemyItemManagement::EnemyItemManagement(DrawObject& pDrawObject3, EnemySetPos& pEnemySetPos) 
	: m_pDrawObjectEnemyItem(pDrawObject3), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyItem = new EnemyItem[MAX_NUM];
}

//======================
// �X�V����
//======================
void EnemyItemManagement::Update(const D3DXVECTOR2& PlayerPos)
{

	//������G�̃A�C�e���̏���
	for (int i = 0; i < m_bullet_num; i++) {
		m_pEnemyItem[i].Update();
		//��ʊO����o����...
		if (m_pEnemyItem[i].GetScreenOut()) {
			//�G�̃A�C�e��������
			DeleteEnemyItem(i);
		}
	}
}

//==========================
// �G�̃A�C�e���̕`�揈��
//==========================
void EnemyItemManagement::Draw(void)const
{
	for (int i = 0; i < m_enemyitem_num; i++) {
		m_pEnemyItem[i].Draw();
	}
}


//======================
// �G�̃A�C�e��������
//======================
void EnemyItemManagement::DeleteEnemyItem(int index_num)
{
	for (int i = index_num; i < m_bullet_num - 1; i++) {
		m_pEnemyItem[i] = m_pEnemyItem[i + 1];
	}
	m_bullet_num--;
}