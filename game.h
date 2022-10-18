//=======================================
// �Q�[����ʊ֌W(�w�b�_�t�@�C��)
// �쐬���F2022/07/14
// �쐬�ҁF��������
//=======================================

#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"
#include "sprite.h"
#include "BG.h"
#include "player.h"
#include "DrawObject.h"
#include "EnemySetPos.h"
#include "EnemyNormalManagement.h"
#include "texture_useful.h"
#include "PlayerHP.h"
#include "ExplosionManagement.h"
#include "PlayerEnemyNormalCollision.h"
#include "number.h"

class Game
{
//�萔
private:
	//�����ŏ�����
	static const int NUMBER_DIGIT = 3;

	//cpp�ŏ�����
	static const D3DXVECTOR2 NUMBER_SIZE;	//�����̃T�C�Y
	static const D3DXVECTOR2 NUMBER_POS;	//�����̈ʒu


//�����o�ϐ�
private:
	int m_BGM = 0;

	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;

	Number* m_pNumber = nullptr;

	BG* m_pBG = nullptr;
	Player* m_pPlayer = nullptr;
	EnemySetPos* m_pEnemySetPos = nullptr;
	EnemyNormalManagement* m_pEnemyNormalManagement = nullptr;
	PlayerHP* m_pPlayerHP = nullptr;
	ExplosionManagement* m_pExplosionManagement = nullptr;

	PlayerEnemyNormalCollision* m_pPlayerEnemyNormalCol = nullptr;

public:
	Game();	//�f�t�H���g�R���X�g���N�^

	Game(Number* pNumber);

	~Game();	//�f�X�g���N�^

	//�X�V
	void Update(void);

	//�`��
	void Draw(void)const;
};
#endif // !_GAME_H_
