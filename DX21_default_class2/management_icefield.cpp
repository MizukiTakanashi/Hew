#include "management_icefield.h"
#include "screen_out.h"

//==========================
// �����t���R���X�g���N�^
//==========================
Management_IceField::Management_IceField(DrawObject& pDrawObject)
	:m_pDrawObjectIceField(pDrawObject)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pIceField[i] = nullptr;
	}
}

//==========================
// �X�V����
//==========================
void Management_IceField::Update()
{
	m_FlameNum++; //�t���[�����𑝉�

	if (m_FlameNum == m_SetEnemyTime[m_EnemyMakedNum])
	{
		m_pIceField[m_EnemyNum] = new IceField(m_pDrawObjectIceField, m_SetEnemy[m_EnemyMakedNum]);
		m_EnemyNum++;

		m_EnemyMakedNum++;
	}

	//������覐΂̏���
	for (int i = 0; i < m_EnemyNum; i++)
	{
		m_pIceField[i]->Update();

		//��ʊO�ɏo�������
		if (m_pIceField[i]->GetScreenOut()) {
			DeleteObj(i);
		}
	}
}

//==========================
// �`�揈��
//==========================
void Management_IceField::Draw(void) const
{
	SetBlendState(BLEND_MODE_ADD);
	for (int i = 0; i < m_EnemyNum; i++) {
		m_pIceField[i]->Draw();
	}
	SetBlendState(BLEND_MODE_ALPHABLEND);
}
