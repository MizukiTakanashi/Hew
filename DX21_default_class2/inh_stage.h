//=======================================
// �p���p�̃X�e�[�W�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#include "main.h"
#include "sprite.h"
#include "texture_useful.h"
#include "draw_object.h"
#include "BG.h"
#include "bg_planet.h"
#include "number.h"
#include "score.h"
#include "player.h"
#include "player_hp.h"
#include "player_left.h"
#include "player_right.h"
#include "player_center.h"
#include "player_arm_change.h"
#include "Bom.h"
#include "management_item.h"
#include "management_explosion.h"
#include "management_meteo.h"
#include "poorvision.h"


class InhStage
{
//�萔
protected:
	//�����ŏ�����
	static const int NUMBER_DIGIT = 5;		//�����̌�
	static const int HIT_STOP_UNION = 30;	//���̂����Ƃ��̃q�b�g�X�g�b�v����
	static const int HIT_STOP_TIME = 60 * 3;		//�Q�[���I�[�o�[���Q�[���N���A�����Ƃ��̎���
	static const int HIT_STOP_SLOW_INTERVAL = 7;	//�������ɂȂ�

	//cpp�ŏ�����
	static const D3DXVECTOR2 NUMBER_SIZE;	//�����̃T�C�Y
	static const D3DXVECTOR2 NUMBER_POS;	//�����̈ʒu

	enum class TEXTURE_TYPE :int
	{//�X���b�V�����t���Ă���Ƃ����InhStage�œǂݍ��ݍς�(�e�X�e�[�W�œǂݍ��ޕK�v�͂Ȃ�)
		NUMBER,//
		MULTIPLY,//
		FRAME,//
		PLAYER,//
		PLAYER_FIRE,
		PLAYER_HP,//
		EXPLOSION,//
		MOON,//��
		MARCURY,//����
		VENUS,//����
		MARS,//�ΐ�
		JUPITOR,//�ؐ�
		SATAURN,//�y��
		SUN,//���z

		ITEM_MISSILE,//
		ITEM_GATORING,//
		ITEM_LASER,//
		ITEM_BARRIER,//
		ITEM_ACID,//
		ITEM_STOP,//
		ITEM_HOTAIRLASER,//
		ITEM_ICERAIN,//
		ITEM_GRENADE,//
		ITEM_ICE,//
		ITEM_POISONLASER,//
		ITEM_FIRE,//
		ITEM_FIREBALL,//

		ENEMY_ITEM,//
		ENEMY_NORMAL,//
		ENEMY_LASER,//
		ENEMY_GATORING,//
		ENEMY_BARRIER,//
		ENEMY_ICE,//
		ENEMY_STOP,//
		ENEMY_MEGUMIN,
		ENEMY_FIREBALL,
		ENEMY_GREANADE,
		ENEMY_METEO,
		ENEMY_POOR,
		ENEMY_SPEEDDOWN,
		ENEMY_ACID,
		ENEMY_FIRE,
		ENEMY_PUBLIC,
		POISON,
		FIREFIELD,
		ICEFIELD,

		BULLET_CIRCLE_RED,//
		BULLET_CIRCLE_GREEN,//
		BULLET_LASER,
		BULLET_BARRIER,//
		BULLET_STOP,//
		BULLET_ICE,//
		BULLET_FIREBALL,
		BULLET_FIRE,
		BULLET_MIST,
		BULLET_MEGUMIN,
		BULLET_ACID,

		GIMMICK_MARS,
		BOM,

		NUM
	};

	enum class DRAW_TYPE :int
	{
		PLAYER,//
		PLAYER_FIRE,
		PLAYER_HP_BAR,//
		NUMBER,//
		MULTIPLY,//
		BOMB,//
		FRAME,//
		EXPLOSION,//
		MOON,//��
		MARCURY,//����
		VENUS,//����
		MARS,//�ΐ�
		JUPITOR,//�ؐ�
		SATAURN,//�y��
		SUN,//���z

		ITEM_MISSILE,//
		ITEM_GATORING,//
		ITEM_LASER,//
		ITEM_BARRIER,//
		ITEM_ACID,//
		ITEM_STOP,//
		ITEM_HOTAIRLASER,//
		ITEM_ICERAIN,//
		ITEM_GRENADE,//
		ITEM_ICE,//
		ITEM_POISONLASER,//
		ITEM_FIRE,//
		ITEM_FIREBALL,//

		ENEMY_ITEM,//
		ENEMY_NORMAL,//
		ENEMY_LASER,//
		ENEMY_GATORING,//
		ENEMY_BARRIER,//
		ENEMY_ICE,//
		ENEMY_STOP,//
		ENEMY_METEO,
		ENEMY_MEGUMIN,
		ENEMY_FIREBALL,
		ENEMY_ACID,
		ENEMY_FIRE,
		ENEMY_POOR,
		ENEMY_SPEEDDOWN,
		ENEMY_GRENADE,
		ENEMY_GRENADE_EXPLOSION,
		ENEMY_PUBLIC,
		POISON,
		FIREFIELD,
		ICEFIELD,

		BULLET_ENEMY,//
		BULLET_LASER,
		BULLET_BARRIER,//
		BULLET_STOP,//
		BULLET_ICE,//
		BULLET_FIREBALL,
		BULLET_MIST,
		BULLET_SPEEDDOWN,
		BULLET_ACID,
		BULLET_FIRE,
		BULLET_MEGUMIN,

		PLAYER_ARM_BULLET,//
		PLAYER_ARM_LASER,//
		PLAYER_BULLET,//
		PLAYER_ARM_GRENADE_EXPLOSION,

		GIMMICK_MARS,

		NUM
	};


//�����o�ϐ�
protected:
	int m_StopFlame = 0;
	bool m_isBossDown = false;

	int m_BGM = 0;

	Score* m_pScore = nullptr;
	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;
	BG* m_pBG = nullptr;
	BGPlanet* m_pBG_Moon = nullptr;
	PoorVision* m_pPoorvision = nullptr;
	Player* m_pPlayer = nullptr;
	PlayerHP* m_pPlayerHP = nullptr;
	ExplosionManagement* m_pExplosionManagement = nullptr;
	ItemManagement* m_pItemManagement = nullptr;
	PlayerLeft* m_pPlayerLeft = nullptr;
	PlayerRight* m_pPlayerRight = nullptr;
	PlayerCenter* m_pPlayerCenter = nullptr;
	UI* m_pFrame = nullptr;
	UI* m_pMultiply = nullptr;
	UI* m_pStageMoon = nullptr;//��
	UI* m_pStageMarcury = nullptr;//����
	UI* m_pStageVenus = nullptr;//����
	UI* m_pStageMars = nullptr;//�ΐ�
	UI* m_pStageJupitor = nullptr;//�ؐ�
	UI* m_pStageSataurn = nullptr;//�y��
	UI* m_pStageSun = nullptr;//���z
	Number* m_pComboNum = nullptr;
	PlayerArmChange* m_pPlayerArmChange = nullptr;	//�r�̌���
	Bom* m_pBom = nullptr;					//�{��
	Management_Meteo* m_pMeteoManagement = nullptr;

	//�Q�[���I�[�o�[���N���A��
	bool m_GameoverHitstop = true;	//�Q�[���I�[�o�[���̃q�b�g�X�g�b�v
	bool m_GameclearHitstop = true;	//�Q�[���N���A���̃q�b�g�X�g�b�v
	int m_HitStopSlow = -1;			//������Ƃ������ɂȂ�

//�����o�֐�
public:
	InhStage(Score* pNumber);

	virtual ~InhStage();	//�f�X�g���N�^

	//�X�V
	virtual void Update(void) = 0;

	//�`��
	virtual void Draw(void)const = 0;

	//�X�R�A��Ԃ�
	int GetScore(void)const { return m_pScore->GetNumber(); }

	void HitStop(int flame) { m_StopFlame = flame; }
	void BossDown() { m_isBossDown = true; }

	void SetPoorVision() { m_pPoorvision->SetPV(); }
};

