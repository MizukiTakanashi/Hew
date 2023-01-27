#include "management_firefield.h"
#include "screen_out.h"

//==========================
// �����t���R���X�g���N�^
//==========================
Management_FireField::Management_FireField(DrawObject& pDrawObject)
	:m_pDrawObjectFireField(pDrawObject)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pFireField[i] = nullptr;
	}
}

//==========================
// �X�V����
//==========================
void Management_FireField::Update()
{
	m_FlameNum++; //�t���[�����𑝉�

	if (m_FlameNum == m_SetEnemyTime[m_EnemyMakedNum])
	{
		m_pFireField[m_EnemyNum] = new FireField(m_pDrawObjectFireField, m_SetEnemy[m_EnemyMakedNum]);
		m_EnemyNum++;

		m_EnemyMakedNum++;
	}

	//������覐΂̏���
	for (int i = 0; i < m_EnemyNum; i++)
	{
		m_pFireField[i]->Update();

		//��ʊO�ɏo�������
		if (m_pFireField[i]->GetScreenOut()) {
			DeleteObj(i);
		}
	}
}

//==========================
// �`�揈��
//==========================
void Management_FireField::Draw(void) const
{
	SetBlendState(BLEND_MODE_ADD);
	for (int i = 0; i < m_EnemyNum; i++) {
		m_pFireField[i]->Draw();
	}
	SetBlendState(BLEND_MODE_ALPHABLEND);
}
