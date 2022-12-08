//=======================================
// �o���A�̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/12/08
// �쐬�ҁF��������
//=======================================
#include "management_enemy_barrier.h"

//=========================
// �����t���R���X�g���N�^
//=========================
EnemyBarrierManagement::EnemyBarrierManagement(DrawObject& pDrawObject1)
	:EnemyManagement(ENEMY_NUM, ATTACK, 0), m_pDrawObjectEnemy(pDrawObject1)
{
	m_pEnemy = new EnemyBarrier[ENEMY_NUM];
}

//======================
// �X�V����
//======================
void EnemyBarrierManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //�t���[�����𑝉�

	//�Z�b�g���鎞�ԂɂȂ��...
	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		//�G���Z�b�g����
		EnemyBarrier temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemy[EnemyManagement::GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		//�Z�b�g�����G�̐��𑝂₷
		m_EnemyNum++;
	}

	//������G�̏���
	for (int i = 0; i < GetObjNum(); i++) {
		m_pEnemy[i].Update();
	}
}

//==========================
// �`�揈��
//==========================
void EnemyBarrierManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemy[i].Draw();
	}
}

//======================
// �G��HP�����炷
//======================
bool EnemyBarrierManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemy[index_num].ReduceHP(reduceHP);

	//HP��0�ȉ��Ȃ�...
	if (m_pEnemy[index_num].GetHP() <= 0)
	{
		//�G�����񂾃t���O��Ԃ�
		return true;
	}

	//�G������łȂ��t���O��Ԃ�
	return false;
}

//======================
// �G������
//======================
void EnemyBarrierManagement::DeleteObj(int index_num)
{
	//�G������
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemy[i] = m_pEnemy[i + 1];
	}

	//�p�����̓G���������Ă�
	EnemyManagement::DeleteObj(index_num);
}