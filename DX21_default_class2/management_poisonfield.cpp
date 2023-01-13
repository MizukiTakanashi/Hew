//=======================================
// 覐΂̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2023/01/03
// �쐬�ҁF��������
//=======================================
#include "management_poisonfield.h"
#include "screen_out.h"

//==========================
// �����t���R���X�g���N�^
//==========================
Management_PoisonField::Management_PoisonField(DrawObject& pDrawObject)
	:m_pDrawObjectPoisonField(pDrawObject)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pPoisonField[i] = nullptr;
	}
}

//==========================
// �X�V����
//==========================
void Management_PoisonField::Update()
{
	m_FlameNum++; //�t���[�����𑝉�

	if (m_FlameNum == m_SetEnemyTime[m_EnemyMakedNum])
	{
		m_pPoisonField[m_EnemyNum] = new PoisonField(m_pDrawObjectPoisonField, m_SetEnemy[m_EnemyMakedNum]);
		m_EnemyNum++;

		m_EnemyMakedNum++;
	}

	//������覐΂̏���
	for (int i = 0; i < m_EnemyNum; i++)
	{
		m_pPoisonField[i]->Update();
	}
}

//==========================
// �`�揈��
//==========================
void Management_PoisonField::Draw(void) const
{
	for (int i = 0; i < m_EnemyNum; i++) {
		m_pPoisonField[i]->Draw();
	}
}