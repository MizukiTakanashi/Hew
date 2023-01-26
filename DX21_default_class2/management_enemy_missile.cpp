//=======================================
// �~�T�C���̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "management_enemy_missile.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "sound.h"

//==========================
// �萔�̏�����
//==========================
const int EnemyMissileManagement::ENEMY_NUM[(int)STAGE::NUM] = { 5, 6, 7, 2, 0 };
const float EnemyMissileManagement::BULLET_SIZE_X = 20.0f;
const float EnemyMissileManagement::BULLET_SIZE_Y = 20.0f;
const float EnemyMissileManagement::BULLET_SPEED = 5.0f;

//=========================
// �����t���R���X�g���N�^
//=========================
EnemyMissileManagement::EnemyMissileManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage)
	:EnemyManagement(EnemyManagement::TYPE::MISSILE, ENEMY_NUM[stage], ATTACK, BULLET_ATTACK),
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2)
{
	m_stage_num = stage;
	m_pEnemyMissile = new EnemyNormal[ENEMY_NUM[stage]];
	m_pBullet = new Bullet[BULLET_NUM];

	m_SE_22 = LoadSound((char*)"data\\SE\\2_21.wav");
	SetVolume(m_SE_22, 0.1f);
}

//======================
// �X�V����
//======================
void EnemyMissileManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //�t���[�����𑝉�

	int i = m_FlameNum;
	if (m_FlameNum == m_SetEnemyTime[m_stage_num][m_EnemyNum] && 
		m_EnemyNum < ENEMY_NUM[m_stage_num])
	{
		EnemyNormal temp(m_pDrawObjectEnemy, m_SetEnemy[m_stage_num][m_EnemyNum]);
		m_pEnemyMissile[GetObjNum()] = temp;
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
		m_pEnemyMissile[i].Update();

		//�e�����
		if (m_pEnemyMissile[i].GetFlagBulletMake()) {
			//�v���C���[�̌��ǂ��悤�ɂ��āA�e�𐶐�
			D3DXVECTOR2 movTemp = PlayerPos - m_pEnemyMissile[i].GetPos();
			D3DXVECTOR2 rotposTemp = m_pEnemyMissile[i].GetPos() - PlayerPos;
			D3DXVec2Normalize(&movTemp, &movTemp);
			movTemp *= BULLET_SPEED;


			Bullet temp(m_pDrawObjectBullet, m_pEnemyMissile[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), movTemp, 0.0f);
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseBulletNum(1);

			m_pEnemyMissile[i].BulletMake();

			PlaySound(m_SE_22, 0);
		}

		//��ʊO����o�������
		if (m_pEnemyMissile[i].GetScreenOut()) {
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
void EnemyMissileManagement::Draw(void)const
{
	for (int i = 0; i < EnemyMissileManagement::GetObjNum(); i++) {
		m_pEnemyMissile[i].Draw();
	}

	for (int i = 0; i < EnemyMissileManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// �G��HP�����炷
//======================
bool EnemyMissileManagement::ReduceHP(int index_num, int reduceHP)
{
	m_pEnemyMissile[index_num].ReduceHP(reduceHP);
	if (m_pEnemyMissile[index_num].GetHP() <= 0)
	{//HP���O�ȉ��Ȃ�G������
		return true;
	}
	return false;
}

//======================
// �G������
//======================
void EnemyMissileManagement::DeleteObj(int index_num)
{
	m_delete_enemy++;
	//�G������
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemyMissile[i] = m_pEnemyMissile[i + 1];
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
void EnemyMissileManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyMissileManagement::GetBulletNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyMissileManagement::IncreaseBulletNum(-1);

	if (m_delete_enemy == ENEMY_NUM[m_stage_num]) {
		m_tutorial_clear = true;
	}
}