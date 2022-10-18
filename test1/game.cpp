//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================

//==============================================
//�C���N���[�h
//==============================================
#include "main.h"
#include "game.h"

#include "player.h"
#include "explosion.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "bggame.h"

//==============================================
//�}�N����`
//==============================================

//==============================================
//�O���[�o���ϐ�
//==============================================
int GameSoundNo;	//�Q�[���T�E���h�C���f�b�N�X

//==============================================
//������
//==============================================
void InitGame()
{
	//BGM�̃��[�h
	char filename[] = "data\\BGM\\Do you have any evidence.wav";
	GameSoundNo = LoadSound(filename);

	InitBgGame();

	InitPlayer();
	InitEnemy();
	InitBullet();
	InitExplosion();


	PlaySound(GameSoundNo, -1);
	SetVolume(GameSoundNo, 0.1);

}

//==============================================
//�I������
//==============================================
void UninitGame()
{
	UninitBgGame();

	UninitPlayer();
	UninitEnemy();
	UninitBullet();
	UninitExplosion();

	StopSoundAll();
}

//==============================================
//�X�V����
//==============================================
void UpdateGame()
{
	UpdateBgGame();

	UpdatePlayer();
	UpdateEnemy();
	UpdateBullet();
	UpdateCollision();
	UpdateExplosion();

}

//==============================================
//�`�揈��
//==============================================
void DrawGame()
{
	DrawBgGame();

	DrawExplosion();
	DrawPlayer();
	DrawEnemy();
	DrawBullet();
}
