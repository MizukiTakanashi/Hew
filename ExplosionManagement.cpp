//=======================================
// �����Ǘ��֌W(cpp�t�@�C��)
// �쐬���F2022/09/18
// �쐬�ҁF��������
//=======================================
#include "ExplosionManagement.h"
#include "sound.h"

//============================
// �f�t�H���g�R���X�g���N�^
//============================
ExplosionManagement::ExplosionManagement()
{
	m_pExplosion = new Explosion[MAX_NUM];

	m_SE = LoadSound((char*)"data\\SE\\bomb000.wav");	//�T�E���h�̃��[�h
}

//=========================
// �����t���R���X�g���N�^
//=========================
ExplosionManagement::ExplosionManagement(DrawObject & DrawObject) :m_DrawObject(DrawObject)
{
	m_pExplosion = new Explosion[MAX_NUM];

	m_SE = LoadSound((char*)"data\\SE\\bomb000.wav");	//�T�E���h�̃��[�h
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
	Explosion Temp(m_DrawObject, pos);
	m_pExplosion[m_ExplosionNum] = Temp;
	m_ExplosionNum++;

	PlaySound(m_SE, 0);
}
