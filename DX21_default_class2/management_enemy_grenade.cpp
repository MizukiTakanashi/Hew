//=======================================
// �O���|���̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/12/27
// �쐬�ҁF��������
//=======================================
#include "management_enemy_grenade.h"
//#define _USE_MATH_DEFINES
//#include <math.h>

//==========================
// �萔�̏�����
//==========================
//private
const int EnemyGrenadeManagement::ENEMY_NUM[(int)STAGE::NUM] = { 5 };
const float EnemyGrenadeManagement::BULLET_SPEED = 5.0f;
const D3DXVECTOR2 EnemyGrenadeManagement::BULLET_SIZE = D3DXVECTOR2(50.0f, 50.0f);
const D3DXVECTOR2 EnemyGrenadeManagement::EXPLOSION_RANGE = D3DXVECTOR2(200.0f, 200.0f);

//=========================
// �����t���R���X�g���N�^
//=========================
EnemyGrenadeManagement::EnemyGrenadeManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, 
	DrawObject& pDrawObject3, int stage)
	:EnemyManagement(ENEMY_NUM[stage], ATTACK, BULLET_ATTACK), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2),
	m_pDrawObjectExplosion(pDrawObject3), m_stage_num(stage)
{
	m_pEnemy = new EnemyGrenade[ENEMY_NUM[stage]];
	m_pBullet = new Bullet[ENEMY_NUM[stage]];

	for (int i = 0; i < ENEMY_NUM[stage]; i++) {
		m_pExplosion[i] = nullptr;
	}
}

//======================
// �X�V����
//======================
void EnemyGrenadeManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	m_FlameNum++; //�t���[�����𑝉�

	//�G�̒ǉ�
	if (m_FlameNum == m_SetEnemyTime[m_stage_num][m_EnemyNum] &&
		m_EnemyNum < ENEMY_NUM[m_stage_num])
	{
		EnemyGrenade temp(m_pDrawObjectEnemy, m_SetEnemy[m_stage_num][m_EnemyNum]);
		m_pEnemy[GetObjNum()] = temp;
		EnemyManagement::IncreaseObjNum(1);

		m_EnemyNum++;
	}

	//������G�̏���
	for (int i = 0; i < GetObjNum(); i++) {
		m_pEnemy[i].Update();

		//�ޏo���ԗ�����...
		//if (m_pEnemy[i].GetAppearanceTime() > EXIT_TIME) {
		//	//�����Ă�
		//	m_pEnemy[i].OnAlphaFlag();
		//	if (m_pEnemy[i].GetAlpha() <= 0.0f) {
		//		DeleteObj(i);
		//	}
		//	continue;
		//}

		//�e�����
		if (m_pEnemy[i].GetFlagBulletMake()) {
			//�v���C���[�̌��ǂ��悤�ɂ��āA�e�𐶐�
			D3DXVECTOR2 movTemp = PlayerPos - m_pEnemy[i].GetPos();
			D3DXVECTOR2 rotposTemp = m_pEnemy[i].GetPos() - PlayerPos;
			D3DXVec2Normalize(&movTemp, &movTemp);
			movTemp *= BULLET_SPEED;

			//float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 90.0f;

			Bullet temp(m_pDrawObjectBullet, m_pEnemy[i].GetPos(),
				BULLET_SIZE, movTemp, 0.0f);
			m_pBullet[EnemyManagement::GetBulletNum()] = temp;

			EnemyManagement::IncreaseObjNum(1);

			m_pEnemy[i].BulletMake();
		}
	}

	//������e�̏���(�ʃI�u�W�F�N�g)
	for (int i = 0; i < EnemyManagement::GetOtherNum(); i++) {
		//�e�̍X�V����
		m_pBullet[i].Update();

		//��ʊO����o����A���Ԍo�߂�����...
		if (m_pBullet[i].GetScreenOut() || m_pBullet[i].GetTime() > BULLET_BREAK_TIME) {
			for (int j = i; i < EnemyManagement::GetOtherNum() - 1; i++) {
				m_pBullet[i] = m_pBullet[i + 1];
			}

			EnemyManagement::IncreaseOtherNum(-1);
		}
	}

	//������e�̏���(����)
	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		//�e�̍X�V����
		m_pExplosion[i]->Update();

		//�������ԂɂȂ�����...
		if (m_pExplosion[i]->GetTime() > EXPLOSION_WAIT_TIME) {
			m_pExplosion[i]->SetSize(EXPLOSION_RANGE);
		}

		//�������Ԃ��I�������...
		if (m_pExplosion[i]->GetTime() > EXPLOSION_WAIT_TIME + EXPLOSION_TIME) {
			DeleteBullet(i);
		}
	}
}

//==========================
// �`�揈��
//==========================
void EnemyGrenadeManagement::Draw(void)const
{
	for (int i = 0; i < EnemyManagement::GetObjNum(); i++) {
		m_pEnemy[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// �������Z�b�g
//======================
void EnemyGrenadeManagement::SetExplosion(D3DXVECTOR2 pos) 
{
	m_pExplosion[EnemyManagement::GetBulletNum()] =
		new Bullet(m_pDrawObjectExplosion, pos, D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(0.0f, 0.0f), 0.0f);

	EnemyManagement::IncreaseBulletNum(1);
}

//======================
// �G��HP�����炷
//======================
bool EnemyGrenadeManagement::ReduceHP(int index_num, int reduceHP)
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
void EnemyGrenadeManagement::DeleteObj(int index_num)
{
	//�G������
	for (int i = index_num; i < EnemyManagement::GetObjNum() - 1; i++) {
		m_pEnemy[i] = m_pEnemy[i + 1];
	}

	//�p�����̓G���������Ă�
	EnemyManagement::DeleteObj(index_num);
}

//======================
// �e������
//======================
void EnemyGrenadeManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pExplosion[i] = m_pExplosion[i + 1];
	}
	EnemyManagement::IncreaseBulletNum(-1);
}