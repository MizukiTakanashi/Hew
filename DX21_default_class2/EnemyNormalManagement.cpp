//=======================================
// ���ʂ̓G�̊Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#include "EnemyNormalManagement.h"
#define _USE_MATH_DEFINES
#include <math.h>

//==========================
// �萔�̏�����
//==========================
const float EnemyNormalManagement::BULLET_SIZE_X = 40.0f;
const float EnemyNormalManagement::BULLET_SIZE_Y = 40.0f;
const float EnemyNormalManagement::BULLET_SPEED = 2.5f;

//=========================
// �����t���R���X�g���N�^
//=========================
EnemyNormalManagement::EnemyNormalManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, EnemySetPos& pEnemySetPos)
	:Management(m_pEnemyNormal, MAX_NUM), m_pDrawObjectEnemy(pDrawObject1), m_pDrawObjectBullet(pDrawObject2), m_pEnemySetPos(pEnemySetPos)
{
	m_pEnemyNormal = new EnemyNormal[MAX_NUM];
	m_pBullet = new Bullet[MAX_NUM];

	Management::SetPoint(m_pEnemyNormal);
}

//======================
// �X�V����
//======================
void EnemyNormalManagement::Update(const D3DXVECTOR2& PlayerPos)
{
	//���Ԃ�������G��z�u
	if (m_count++ > APPEARANCE_TIME && GetObjNum() != MAX_NUM) {
		//�����_���ŏo���ʒu�����߂�
		float x = rand() % (SCREEN_WIDTH - (int)EnemyNormal::SIZE_X / 2) + EnemyNormal::SIZE_X / 2;

		//�t���O�ɉ����ēG�����
		if (m_pEnemySetPos.SetEnemy(D3DXVECTOR2(x, EnemyNormal::STOP_POS_Y), D3DXVECTOR2(EnemyNormal::SIZE_X + EnemyNormal::RANGE * 2, EnemyNormal::SIZE_Y))) {
			EnemyNormal temp(m_pDrawObjectEnemy, D3DXVECTOR2(x, -EnemyNormal::SIZE_Y / 2));
			m_pEnemyNormal[GetObjNum()] = temp;
			IncreaseObjNum();
		}

		m_count = 0;
	}

	//������G�̏���
	for (int i = 0; i < GetObjNum(); i++) {
		m_pEnemyNormal[i].Update();

		//�e�����
		if (m_pEnemyNormal[i].GetFlagBulletMake() && m_bullet_num != MAX_NUM) {
			//�v���C���[�̌��ǂ��悤�ɂ��āA�e�𐶐�
			D3DXVECTOR2 movTemp = PlayerPos - m_pEnemyNormal[i].GetPos();
			D3DXVECTOR2 rotposTemp = m_pEnemyNormal[i].GetPos() - PlayerPos;
			D3DXVec2Normalize(&movTemp, &movTemp);
			movTemp *= BULLET_SPEED;

			float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;

			Bullet temp(m_pDrawObjectBullet, m_pEnemyNormal[i].GetPos(),
				D3DXVECTOR2(BULLET_SIZE_X, BULLET_SIZE_Y), movTemp, rotTemp);
			m_pBullet[m_bullet_num] = temp;

			m_bullet_num++;

			m_pEnemyNormal[i].BulletMake();
		}
	}

	//������e�̏���
	for (int i = 0; i < m_bullet_num; i++) {
		//�v���C���[�̌��ǂ�(�z�[�~���O�e)
		D3DXVECTOR2 movTemp = PlayerPos - m_pBullet[i].GetPos();
		D3DXVECTOR2 rotposTemp = m_pEnemyNormal[i].GetPos() - PlayerPos;
		D3DXVec2Normalize(&movTemp, &movTemp);
		movTemp *= BULLET_SPEED;

		float rotTemp = atan2(rotposTemp.y, rotposTemp.x) * (180 / M_PI) + 180.0f;

		m_pBullet[i].SetRot(rotTemp);
		m_pBullet[i].SetMove(movTemp);

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
void EnemyNormalManagement::Draw(void)const
{
	Management::DrawObj();

	for (int i = 0; i < m_bullet_num; i++) {
		m_pBullet[i].Draw();
	}
}

//======================
// �G������
//======================
void EnemyNormalManagement::DeleteEnemy(int index_num)
{
	m_pEnemySetPos.DeleteEnemy(m_pEnemyNormal[index_num].GetPos());

	Management::Delete(index_num);
}

//======================
// �e������
//======================
void EnemyNormalManagement::DeleteBullet(int index_num)
{
	for (int i = index_num; i < m_bullet_num - 1; i++) {
		m_pBullet[i] = m_pBullet[i + 1];
	}
	m_bullet_num--;
}