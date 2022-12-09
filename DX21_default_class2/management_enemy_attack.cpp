#include "management_enemy_attack.h"
#define _USE_MATH_DEFINES
#include <math.h>


const float EnemyAttackManagement::ATTACK_SPEED = 5.0f;
//=========================
// �����t���R���X�g���N�^
//=========================
EnemyAttackManagement::EnemyAttackManagement(DrawObject& pDrawObject1)
	:EnemyManagement(ENEMY_NUM, ATTACK, 0), m_pDrawObjectEnemy(pDrawObject1)
{
	m_pEnemyAttack = new EnemyAttack[ENEMY_NUM];
}

//======================
// �X�V����
//======================
void EnemyAttackManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //�t���[�����𑝉�

	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		EnemyAttack temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemyAttack[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//������G�̏���
	for (int i = 0; i < GetObjNum(); i++) {
		m_pEnemyAttack[i].Update();

		//���ԂɂȂ�����˂�����
		if (m_pEnemyAttack[i].GetFlagAttack()) {
			//�v���C���[�̌��ǂ�(�z�[�~���O�e)
			D3DXVECTOR2 movTemp = PlayerPos - m_pEnemyAttack[i].GetPos();
			D3DXVECTOR2 rotposTemp = m_pEnemyAttack[i].GetPos() - PlayerPos;
			D3DXVec2Normalize(&movTemp, &movTemp);
			movTemp *= ATTACK_SPEED;
			m_pEnemyAttack[i].MovePos(movTemp);
		
			if (m_pEnemyAttack[i].GetFlagExplosion())
			{
				
				m_pEnemyAttack[i].MovePos(D3DXVECTOR2(0.0f, 0.0f));
				//DeleteObj(i);
			}
		}
	}
}

//==========================
// �`�揈��
//==========================
void EnemyAttackManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemyAttack[i].Draw();
	}


}

//======================
// �G��HP�����炷
//======================
bool EnemyAttackManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyAttack[index_num].ReduceHP(reduceHP);
	if (m_pEnemyAttack[index_num].GetHP() <= 0)
	{//HP���O�ȉ��Ȃ�G������

		return true;
	}
	return false;
}
//==========================
// �G������
//==========================
void EnemyAttackManagement::DeleteObj(int index_num)
{
	//�G������
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyAttack[i] = m_pEnemyAttack[i + 1];
	}

	//�p�����̓G���������Ă�
	EnemyManagement::DeleteObj(index_num);
}
