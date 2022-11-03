//=======================================
// �����Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/18
// �쐬�ҁF��������
//=======================================
#pragma once

#include "explosion.h"
#include "main.h"

#ifndef _EXPLOSION_MANAGEMENT_H_
#define _EXPLOSION_MANAGEMENT_H_

class ExplosionManagement
{
//�萔
private:
	static const int MAX_NUM = 50;	//�����̍ő吔


//�����o�ϐ�
private:
	int m_SE = 0;

	DrawObject m_DrawObject;
	Explosion* m_pExplosion = nullptr;
	int m_ExplosionNum = 0;

public:
	//�f�t�H���g�R���X�g���N�^
	ExplosionManagement();

	//�����t���R���X�g���N�^
	ExplosionManagement(DrawObject& DrawObject);

	~ExplosionManagement() { delete[] m_pExplosion; }	//�f�X�g���N�^

	//�X�V����
	void Update(void);

	//�`�揈��
	void Draw(void)const{
		for (int i = 0; i < m_ExplosionNum; i++) {
			m_pExplosion[i].Draw();
		}
	}

	//�������Z�b�g
	void SetExplosion(const D3DXVECTOR2& pos);
};

#endif // !_EXPLOSION_MANAGEMENT_H_