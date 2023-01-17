//=======================================
// �o���A�̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/12/08
// �쐬�ҁF��������
//=======================================
#include "management_enemy_barrier.h"

//==========================
// �萔�̏�����
//==========================
const D3DXVECTOR2 EnemyBarrierManagement::BARRIER_SIZE = D3DXVECTOR2(50.0f, 10.0f);
const D3DXVECTOR2 EnemyBarrierManagement::INTERVAL_POS = D3DXVECTOR2(0.0f, 60.0f);

//=========================
// �����t���R���X�g���N�^
//=========================
EnemyBarrierManagement::EnemyBarrierManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2)
	:EnemyManagement(EnemyManagement::TYPE::BARRIER, ENEMY_NUM, ATTACK, 0, BARRIER_ATTACK), 
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBarrier(pDrawObject2)
{
	m_pEnemy = new EnemyBarrier[ENEMY_NUM];
	m_pBarrier = new GameObject[ENEMY_NUM];

	//�o���A��HP������
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_BarrierHP[i] = BARRIER_HP_MAX;
	}
}

//======================
// �X�V����
//======================
void EnemyBarrierManagement::Update()
{
	m_FlameNum++; //�t���[�����𑝉�

	//�Z�b�g���鎞�ԂɂȂ��...
	if (m_FlameNum == m_SetEnemyTime[m_EnemyNum])
	{
		//�G���Z�b�g����
		EnemyBarrier temp(m_pDrawObjectEnemy, m_SetEnemy[m_EnemyNum]);
		m_pEnemy[EnemyManagement::GetObjNum()] = temp;

		//�o���A���Z�b�g����
		GameObject temp1(m_pDrawObjectBarrier, m_SetEnemy[m_EnemyNum], BARRIER_SIZE);
		m_pBarrier[EnemyManagement::GetOtherNum()] = temp1;
		m_BarrierHP[EnemyManagement::GetOtherNum()] = BARRIER_HP_MAX;
		m_pEnemy[EnemyManagement::GetObjNum()].SetBarrierIndex(EnemyManagement::GetOtherNum());
		
		EnemyManagement::IncreaseObjNum(1);
		EnemyManagement::IncreaseOtherNum(1);

		//�Z�b�g�����G�̐��𑝂₷
		m_EnemyNum++;
	}

	//������G�̏���
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemy[i].Update();

		//������o���A�̏���
		for (int j = 0; j < EnemyManagement::GetOtherNum(); j++) {
			//�G�������Ă���o���A�̃C���f�b�N�X�ԍ��Ɠ����ł����...
			if (m_pEnemy[i].GetBarrierIndex() == j) {
				//�o���A��G�̑O�ɒu��
				m_pBarrier[j].SetPos(m_pEnemy[i].GetPos() + INTERVAL_POS);
			}
		}
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

	for (int i = 0; i < EnemyManagement::GetOtherNum(); i++) {
		m_pBarrier[i].Draw();
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
// �o���A��HP�����炷
//======================
bool EnemyBarrierManagement::ReduceOtherHP(int index_num, int reduceHP)
{
	m_BarrierHP[index_num] -= reduceHP;

	//HP��0�ȉ��Ȃ�...
	if (m_BarrierHP[index_num] <= 0)
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
	m_delete_enemy++;
	//�G�ɕt�����Ă���o���A���܂����Ă��Ȃ�������...
	if (m_BarrierHP[m_pEnemy[index_num].GetBarrierIndex()] != -1) {
		//�G�ɕt�����Ă���o���A������
		DeleteOther(m_pEnemy[index_num].GetBarrierIndex());
	}

	//�G������
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemy[i] = m_pEnemy[i + 1];
	}

	//�p�����̓G���������Ă�
	EnemyManagement::DeleteObj(index_num);

	if (m_delete_enemy == ENEMY_NUM) {
		m_tutorial_clear = true;
	}

}

//======================
// �o���A������
//======================
void EnemyBarrierManagement::DeleteOther(int index_num)
{
	//�󂳂ꂽ�����L�^
	m_BarrierHP[index_num] = -1;

	for (int i = index_num; i < EnemyManagement::GetOtherNum() - 1; i++) {
		m_pBarrier[i] = m_pBarrier[i + 1];

		//�o���A�̃C���f�b�N�X�ԍ�����������
		for (int j = 0; j < EnemyManagement::GetObjNum(); j++) {
			if (m_pEnemy[j].GetBarrierIndex() == i + 1) {
				m_pEnemy[j].SetBarrierIndex(m_pEnemy[j].GetBarrierIndex() - 1);
			}
		}

		m_BarrierHP[i] = m_BarrierHP[i + 1];
	}

	//�p�����̕ʃI�u�W�F�N�g���������Ă�
	EnemyManagement::DeleteOther(index_num);
}