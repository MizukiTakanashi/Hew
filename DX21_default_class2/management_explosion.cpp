//=======================================
// �����Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/09/18
// �쐬�ҁF��������
//=======================================
#include "management_explosion.h"
#include "sound.h"
#include "collision.h"

//==========================
// �萔�̏�����
//==========================
const D3DXVECTOR2 ExplosionManagement::CLOTH_INTERVAL = D3DXVECTOR2(5.0f, 5.0f);

//============================
// �f�t�H���g�R���X�g���N�^
//============================
ExplosionManagement::ExplosionManagement()
{
	m_pExplosion = new Explosion[ENEMY_NUM];
}

//=========================
// �����t���R���X�g���N�^
//=========================
ExplosionManagement::ExplosionManagement(DrawObject & DrawObject) :m_DrawObject(DrawObject)
{
	m_pExplosion = new Explosion[ENEMY_NUM];
}

//======================
// �X�V����
//======================
void ExplosionManagement::Update(void)
{
	for (int i = 0; i < m_ExplosionNum; i++) {
		m_pExplosion[i].Update();

		//�A�j���[�V�������I����������
		if (m_pExplosion[i].GetEndAnimation()) {
			for (int j = i; j < m_ExplosionNum - 1; j++) {
				m_pExplosion[j] = m_pExplosion[j + 1];
			}
			m_ExplosionNum--;
		}
	}
}

//==========================
// �������Z�b�g
//==========================
void ExplosionManagement::SetExplosion(const D3DXVECTOR2& pos)
{
	for (int i = 0; i < m_ExplosionNum; i++) {
		//�ǂ����̔����Ɣ���Ă���...
		if (Collision::ColBox(m_pExplosion[i].GetPos(), pos,
			m_pExplosion[i].GetSize(), CLOTH_INTERVAL)) {
			return;
		}
	}
	Explosion Temp(m_DrawObject, pos);
	m_pExplosion[m_ExplosionNum] = Temp;
	m_ExplosionNum++;
}
