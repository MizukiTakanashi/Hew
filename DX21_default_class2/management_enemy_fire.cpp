//=======================================
// ���ʂ̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#include "management_enemy_fire.h"
#include "sound.h"

//==========================
// �萔�̏�����
//==========================
const int EnemyFireManagement::ENEMY_NUM[(int)STAGE::NUM] = { 0, 0, 9, 0, 0 };
const float EnemyFireManagement::BULLET_SIZE_X = 20.0f;
const float EnemyFireManagement::BULLET_SIZE_Y = 20.0f;
const float EnemyFireManagement::BULLET_SPEED = 5.0f;

//=========================
// �����t���R���X�g���N�^
//=========================
EnemyFireManagement::EnemyFireManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage)
	:EnemyManagement(EnemyManagement::TYPE::FIRE, ENEMY_NUM[stage], ATTACK, BULLET_ATTACK),
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_stage_num = stage;
	m_pEnemy = new EnemyNormal[ENEMY_NUM[stage]];
	m_pBullet = new Bullet[BULLET_NUM];

	//���ˉ�
	m_SE_15_1 = LoadSound((char*)"data\\SE\\1_15_1.wav");
}

//======================
// �X�V����
//======================
void EnemyFireManagement::Update()
{
	m_FlameNum++; //�t���[�����𑝉�

	if (m_FlameNum == m_SetEnemyTime[m_stage_num][m_EnemyNum] &&
		m_EnemyNum < ENEMY_NUM[m_stage_num])
	{
		EnemyNormal temp(m_pDrawObjectEnemy, m_SetEnemy[m_stage_num][m_EnemyNum]);
		m_pEnemy[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	if (m_EnemyNum == ENEMY_NUM[m_stage_num])
	{
		m_tutorial_clear = true;
	}
	//������G�̏���
	for (int i = 0; i < GetObjNum(); i++) {
		m_tutorial_clear = false;
		m_pEnemy[i].Update();

		//�ޏo���ԗ�����...
		if (m_pEnemy[i].GetAppearanceTime() > EXIT_TIME &&
			m_FlameNum < m_SetEnemyTime[m_stage_num][ENEMY_NUM[m_stage_num] - 1]) {
			//�����Ă�
			m_pEnemy[i].OnAlphaFlag();
			if (m_pEnemy[i].GetAlpha() <= 0.0f) {
				DeleteObj(i);
			}
			continue;
		}

		//�e�����
		if (m_pEnemy[i].GetFlagBulletMake()) {
			Bullet temp(m_pDrawObjectBullet, m_pEnemy[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), D3DXVECTOR2(0.0f, BULLET_SPEED), 0.0f);
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemy[i].BulletMake();

			PlaySound(m_SE_15_1, 0);
		}

		//��ʊO�ɏo�������
		if (m_pEnemy[i].GetScreenOut()) {
			DeleteObj(i);
			break;
		}
	}

	//������e�̏���
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		//�e�̍X�V����
		m_pBullet[i].Update();

		//��ʊO����o����A���Ԍo�߂�����...
		if (m_pBullet[i].GetScreenOut() || m_pBullet[i].GetTime() > BULLET_BREAK_TIME) {
			//�e������
			DeleteBullet(i);
		}
	}
}

//==========================
// �`�揈��
//==========================
void EnemyFireManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemy[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// �G��HP�����炷
//======================
bool EnemyFireManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemy[index_num].ReduceHP(reduceHP);

	if (m_pEnemy[index_num].GetHP() <= 0)
	{//HP���O�ȉ��Ȃ�G������

		return true;
	}
	return false;
}

//======================
// �G������
//======================
void EnemyFireManagement::DeleteObj(int index_num)
{
	m_delete_enemy++;
	//�G������
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemy[i] = m_pEnemy[i + 1];
	}

	//�p�����̓G���������Ă�
	EnemyManagement::DeleteObj(index_num);

	if (m_delete_enemy == ENEMY_NUM[m_stage_num]) {
		m_tutorial_clear = true;
	}
}

//======================
// �e������
//======================
void EnemyFireManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}