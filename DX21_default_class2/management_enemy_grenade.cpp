//=======================================
// �O���|���̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/12/27
// �쐬�ҁF��������
//=======================================
#include "management_enemy_grenade.h"
//#define _USE_MATH_DEFINES
//#include <math.h>
#include "sound.h"

//==========================
// �萔�̏�����
//==========================
//public
const D3DXVECTOR2 EnemyGrenadeManagement::OTHER_RANGE = D3DXVECTOR2(100.0f, 100.0f);

//private
const int EnemyGrenadeManagement::ENEMY_NUM[(int)STAGE::NUM] = { 0, 5, 0, 0, 0 };
const float EnemyGrenadeManagement::BULLET_SPEED = 5.0f;
const D3DXVECTOR2 EnemyGrenadeManagement::BULLET_SIZE = D3DXVECTOR2(20.0f, 20.0f);
const D3DXVECTOR2 EnemyGrenadeManagement::EXPLOSION_RANGE = D3DXVECTOR2(200.0f, 200.0f);

//=========================
// �����t���R���X�g���N�^
//=========================
EnemyGrenadeManagement::EnemyGrenadeManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, 
	DrawObject& pDrawObject3, int stage)
	:EnemyManagement(EnemyManagement::TYPE::GRENADE, ENEMY_NUM[stage], ATTACK, BULLET_ATTACK), 
	m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2),
	m_pDrawObjectExplosion(pDrawObject3), m_stage_num(stage)
{
	m_pEnemy = new EnemyGrenade[ENEMY_NUM[stage]];
	m_pBullet = new Bullet[ENEMY_NUM[stage]];

	for (int i = 0; i < ENEMY_NUM[stage]; i++) {
		m_pExplosion[i] = nullptr;
		m_pExplosionDraw[i] = nullptr;
	}

	m_SE_12 = LoadSound((char*)"data\\SE\\1_12.wav");
}

//==========================
// �f�X�g���N�^
//==========================
EnemyGrenadeManagement::~EnemyGrenadeManagement()
{
	delete[] m_pEnemy; 
	delete[] m_pBullet;

	for (int i = 0; i < ENEMY_NUM[m_stage_num]; i++) {
		if (m_pExplosion[i] != nullptr) {
			delete m_pExplosion[i];
		}
		if (m_pExplosionDraw[i] != nullptr) {
			delete m_pExplosionDraw[i];
		}
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

	if (m_EnemyNum == ENEMY_NUM[m_stage_num])
	{
		m_tutorial_clear = true;
	}
	//������G�̏���
	for (int i = 0; i < GetObjNum(); i++) {
		m_tutorial_clear = false;
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
			m_pBullet[EnemyManagement::GetOtherNum()] = temp;

			EnemyManagement::IncreaseOtherNum(1);

			m_pEnemy[i].BulletMake();

			PlaySound(m_SE_12, 0);
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
			m_pExplosionDraw[i]->Update();
			m_pExplosion[i]->SetSize(EXPLOSION_RANGE);
		}

		//�������Ԃ��I�������...
		if (m_pExplosionDraw[i]->GetEndAnimation()) {
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

	for (int i = 0; i < EnemyManagement::GetOtherNum(); i++) {
		m_pBullet[i].Draw();
	}

	for (int i = 0; i < EnemyManagement::GetBulletNum(); i++) {
		if (m_pExplosion[i]->GetSize() == EXPLOSION_RANGE) {
			m_pExplosionDraw[i]->Draw();
		}
	}
}

//======================
// �������Z�b�g
//======================
void EnemyGrenadeManagement::SetExplosion(D3DXVECTOR2 pos) 
{
	m_pExplosion[EnemyManagement::GetBulletNum()] =
		new Bullet(m_pDrawObjectExplosion, pos, D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(0.0f, 0.0f), 0.0f);

	m_pExplosionDraw[EnemyManagement::GetBulletNum()] =
		new Explosion(m_pDrawObjectExplosion, pos);
	m_pExplosionDraw[EnemyManagement::GetBulletNum()]->SetSize(EXPLOSION_RANGE);

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

	if (m_delete_enemy == ENEMY_NUM[m_stage_num]) {
		m_tutorial_clear = true;
	}
}

//======================
// �e������
//======================
void EnemyGrenadeManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetBulletNum() - 1; i++) {
		m_pExplosion[i] = m_pExplosion[i + 1];
		m_pExplosion[i + 1] = nullptr;
		m_pExplosionDraw[i] = m_pExplosionDraw[i + 1];
		m_pExplosionDraw[i + 1] = nullptr;
	}
	EnemyManagement::IncreaseBulletNum(-1);
}

//======================
// �ʃI�u�W�F�N�g������
//======================
void EnemyGrenadeManagement::DeleteOther(int index_num)
{
	for (int i = index_num; i < EnemyManagement::GetOtherNum() - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	EnemyManagement::IncreaseOtherNum(-1);
}