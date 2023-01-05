//=======================================
// 覐΂̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2023/01/03
// �쐬�ҁF��������
//=======================================
#include "management_meteo.h"
#include "screen_out.h"

//==========================
// �����t���R���X�g���N�^
//==========================
Management_Meteo::Management_Meteo(DrawObject& pDrawObject)
	:m_pDrawObjectMeteo(pDrawObject)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_pMeteo[i] = nullptr;
	}
}

//==========================
// �X�V����
//==========================
void Management_Meteo::Update()
{
	m_FlameNum++; //�t���[�����𑝉�

	if (m_FlameNum == m_SetEnemyTime[m_EnemyMakedNum])
	{
		m_pMeteo[m_EnemyNum] = new Meteo(m_pDrawObjectMeteo, m_SetEnemy[m_EnemyMakedNum]);
		m_EnemyNum++;

		m_EnemyMakedNum++;
	}

	//������覐΂̏���
	for (int i = 0; i < m_EnemyNum; i++)
	{
		m_pMeteo[i]->Update();
	}
}

//==========================
// �`�揈��
//==========================
void Management_Meteo::Draw(void) const
{
	for (int i = 0; i < m_EnemyNum; i++) {
		m_pMeteo[i]->Draw();
	}
}