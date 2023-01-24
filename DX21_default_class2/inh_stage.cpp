//=======================================
// �p���p�̃X�e�[�W�֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "inh_stage.h"
#include "sound.h"

//==========================
// �萔������
//==========================
const D3DXVECTOR2 InhStage::NUMBER_POS = D3DXVECTOR2(1260.0f, 15.0f);
const D3DXVECTOR2 InhStage::NUMBER_SIZE = D3DXVECTOR2(25.0f, 25.0f);

//==========================
// �����t���R���X�g���N�^
//==========================
InhStage::InhStage(Score* pNumber):m_pScore(pNumber)
{
	//�����̏�����
	m_pScore->SetInitPos(NUMBER_POS);
	m_pScore->SetPos(NUMBER_POS);
	m_pScore->SetSize(NUMBER_SIZE);
	m_pScore->SetDigit(NUMBER_DIGIT);

	m_BGM = LoadSound((char*)"data\\BGM\\opportunity (online-audio-converter.com).wav");	//�T�E���h�̃��[�h
	PlaySound(m_BGM, -1);	//BGM�Đ�
	SetVolume(m_BGM, 0.1f);

	//�w�i�̏���������
	m_pBG = new BG((char*)"data\\texture\\game_bg_scroll.jpg");

	m_pPoorvision = new PoorVision((char*)"data\\texture\\poorvision.png");

	m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawObject = new DrawObject[(int)DRAW_TYPE::NUM];


	//=======================
	// �e
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_RED].SetTextureName((char*)"data\\texture\\bullet_red.png");
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN].SetTextureName((char*)"data\\texture\\bullet_green.png");
	//�΂̒e
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	//�G���̒e
	m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_RED]);
	//�{��
	m_pDrawObject[(int)DRAW_TYPE::BOMB].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN]);
	m_pBom = new Bom(m_pDrawObject[(int)DRAW_TYPE::BOMB], 3);


	//=======================
	//�����֘A
	m_pTexUseful[(int)TEXTURE_TYPE::NUMBER].SetTextureName((char*)"data\\texture\\number.png");
	// �c�e�\��
	m_pDrawObject[(int)DRAW_TYPE::NUMBER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::NUMBER], 0.0f, 0.0909f, 1.0f, 11);
	// �R���{�p�����\��
	m_pComboNum = new Number(m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(SCREEN_WIDTH - 30, 50), D3DXVECTOR2(25.0f, 25.0f), 2);

	//=======================
	// �R���{���̉��́~
	m_pTexUseful[(int)TEXTURE_TYPE::MULTIPLY].SetTextureName((char*)"data\\texture\\multiply.png");
	m_pDrawObject[(int)DRAW_TYPE::MULTIPLY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MULTIPLY], 0.0f, 1.0f, 1.0f, 1);
	m_pMultiply = new UI(m_pDrawObject[(int)DRAW_TYPE::MULTIPLY], D3DXVECTOR2(SCREEN_WIDTH - 110, 50), D3DXVECTOR2(25.0f, 25.0f), D3DXCOLOR());

	//�v���C���[
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER].SetTextureName((char*)"data\\texture\\player_anime.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER], 1.0f, 0.25f, 1.0f, 4);
	m_pPlayer = new Player(m_pDrawObject[(int)DRAW_TYPE::PLAYER], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET]);

	//�t���[��
	m_pTexUseful[(int)TEXTURE_TYPE::FRAME].SetTextureName((char*)"data\\texture\\ui.png");
	m_pDrawObject[(int)DRAW_TYPE::FRAME].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::FRAME]);
	m_pFrame = new UI(m_pDrawObject[(int)DRAW_TYPE::FRAME], D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2),
		D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	//����
	m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION].SetTextureName((char*)"data\\texture\\explosion000.png");
	m_pDrawObject[(int)DRAW_TYPE::EXPLOSION].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION], 0.0f, 0.125f, 1.0f, 7);
	m_pExplosionManagement = new ExplosionManagement(m_pDrawObject[(int)DRAW_TYPE::EXPLOSION]);

	//�v���C���[��HP
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP].SetTextureName((char*)"data\\texture\\hp.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP], 0.0f, 0.5f, 1.0f, 2);
	m_pPlayerHP = new PlayerHP(m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR], m_pExplosionManagement, m_pPlayer, this);

	//�X�e�[�W�\���ǂݍ���
	//��
	m_pTexUseful[(int)TEXTURE_TYPE::MOON].SetTextureName((char*)"data\\texture\\moon_name.png");
	m_pDrawObject[(int)DRAW_TYPE::MOON].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MOON], 0.0f, 1.0f, 1.0f, 1);
	m_pStageMoon = new UI(m_pDrawObject[(int)DRAW_TYPE::MOON], D3DXVECTOR2(160.0f, 40.0f), D3DXVECTOR2(100.0f, 50.0f), D3DXCOLOR());
	
	//����
	m_pTexUseful[(int)TEXTURE_TYPE::MARCURY].SetTextureName((char*)"data\\texture\\mercury_name.png");
	m_pDrawObject[(int)DRAW_TYPE::MARCURY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MARCURY], 0.0f, 1.0f, 1.0f, 1);
	m_pStageMarcury = new UI(m_pDrawObject[(int)DRAW_TYPE::MARCURY], D3DXVECTOR2(160.0f, 40.0f), D3DXVECTOR2(100.0f, 50.0f), D3DXCOLOR());

	//����
	m_pTexUseful[(int)TEXTURE_TYPE::VENUS].SetTextureName((char*)"data\\texture\\venus_name.png");
	m_pDrawObject[(int)DRAW_TYPE::VENUS].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::VENUS], 0.0f, 1.0f, 1.0f, 1);
	m_pStageVenus = new UI(m_pDrawObject[(int)DRAW_TYPE::VENUS], D3DXVECTOR2(160.0f,40.0f), D3DXVECTOR2(100.0f, 50.0f), D3DXCOLOR());

	//�ΐ�
	m_pTexUseful[(int)TEXTURE_TYPE::MARS].SetTextureName((char*)"data\\texture\\mars_name.png");
	m_pDrawObject[(int)DRAW_TYPE::MARS].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MARS], 0.0f, 1.0f, 1.0f, 1);
	m_pStageMars = new UI(m_pDrawObject[(int)DRAW_TYPE::MARS], D3DXVECTOR2(160.0f, 40.0f), D3DXVECTOR2(100.0f, 50.0f), D3DXCOLOR());

	//�ؐ�
	m_pTexUseful[(int)TEXTURE_TYPE::JUPITOR].SetTextureName((char*)"data\\texture\\jupiter_name.png");
	m_pDrawObject[(int)DRAW_TYPE::JUPITOR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::JUPITOR], 0.0f, 1.0f, 1.0f, 1);
	m_pStageJupitor = new UI(m_pDrawObject[(int)DRAW_TYPE::JUPITOR], D3DXVECTOR2(160.0f, 40.0f), D3DXVECTOR2(100.0f, 50.0f), D3DXCOLOR());

	//�y��
	m_pTexUseful[(int)TEXTURE_TYPE::SATAURN].SetTextureName((char*)"data\\texture\\saturn_name.png");
	m_pDrawObject[(int)DRAW_TYPE::SATAURN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::SATAURN], 0.0f, 1.0f, 1.0f, 1);
	m_pStageSataurn = new UI(m_pDrawObject[(int)DRAW_TYPE::SATAURN], D3DXVECTOR2(160.0f, 40.0f), D3DXVECTOR2(100.0f, 50.0f), D3DXCOLOR());

	//���z
	m_pTexUseful[(int)TEXTURE_TYPE::SUN].SetTextureName((char*)"data\\texture\\sun_name.png");
	m_pDrawObject[(int)DRAW_TYPE::SUN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::SUN], 0.0f, 1.0f, 1.0f, 1);
	m_pStageSun = new UI(m_pDrawObject[(int)DRAW_TYPE::SUN], D3DXVECTOR2(160.0f, 40.0f), D3DXVECTOR2(100.0f, 50.0f), D3DXCOLOR());

	//=======================
	//�G�̃A�C�e��
	m_pItemManagement = new ItemManagement();
	//�摜�ǂݍ���
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_MISSILE].SetTextureName((char*)"data\\texture\\item_missile.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_MISSILE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_MISSILE]);
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_LASER].SetTextureName((char*)"data\\texture\\item_laser.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_LASER]);
	m_pTexUseful[(int)TEXTURE_TYPE::ITEM_GATORING].SetTextureName((char*)"data\\texture\\item_gatoring.png");
	m_pDrawObject[(int)DRAW_TYPE::ITEM_GATORING].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ITEM_GATORING]);
	//�摜�Z�b�g
	m_pItemManagement->SetDrawMissile(&m_pDrawObject[(int)DRAW_TYPE::ITEM_MISSILE]);
	m_pItemManagement->SetDrawLaser(&m_pDrawObject[(int)DRAW_TYPE::ITEM_LASER]);
	m_pItemManagement->SetDrawGatoring(&m_pDrawObject[(int)DRAW_TYPE::ITEM_GATORING]);



	//=======================
	// �v���C���[�̘r
	m_pPlayerCenter = new PlayerCenter(m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(120.0f, 590.0f), D3DXVECTOR2(230.0f, 590.0f));
	m_pPlayerLeft = new PlayerLeft(m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(120.0f, 640.0f), D3DXVECTOR2(230.0f, 640.0f));
	m_pPlayerRight = new PlayerRight(m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(120.0f, 690.0f), D3DXVECTOR2(230.0f, 690.0f));

	//���̂ł���G�̉摜�ǂݍ���(�G�̒e)
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1, D3DXCOLOR(0.2f, 1.0f, 0.2f, 1.0f));
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER], 0.0f, 1.0f, 1.0f, 1, D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));

	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_BARRIER].SetTextureName((char*)"data\\texture\\bullet_barrier.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_BARRIER]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_STOP].SetTextureName((char*)"data\\texture\\bullet_stop.jpg");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_STOP].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_STOP]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ICE].SetTextureName((char*)"data\\texture\\bullet_ice.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ICE]);


	//�r�̉摜�Z�b�g�i�e�j
	m_pPlayerLeft->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_BULLET]);
	m_pPlayerLeft->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LASER]);
	m_pPlayerLeft->DrawSetBarrier(&m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER]);
	m_pPlayerLeft->DrawSetBulleStop(&m_pDrawObject[(int)DRAW_TYPE::BULLET_STOP]);
	m_pPlayerLeft->DrawSetIceRain(&m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE]);
	
	m_pPlayerRight->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_BULLET]);
	m_pPlayerRight->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LASER]);
	m_pPlayerRight->DrawSetBarrier(&m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER]);
	m_pPlayerRight->DrawSetBulleStop(&m_pDrawObject[(int)DRAW_TYPE::BULLET_STOP]);
	m_pPlayerRight->DrawSetIceRain(&m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE]);
	
	m_pPlayerCenter->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_BULLET]);
	m_pPlayerCenter->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LASER]);
	m_pPlayerCenter->DrawSetBarrier(&m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER]);
	m_pPlayerCenter->DrawSetBulleStop(&m_pDrawObject[(int)DRAW_TYPE::BULLET_STOP]);
	m_pPlayerCenter->DrawSetIceRain(&m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE]);
	

	//���̂ł���G�̉摜�ǂݍ���(�G�{��)
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_NORMAL].SetTextureName((char*)"data\\texture\\enemy_missile.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_NORMAL].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_NORMAL]);
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_LASER].SetTextureName((char*)"data\\texture\\enemy_laser.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_LASER]);
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_GATORING].SetTextureName((char*)"data\\texture\\enemy_gatoring.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_GATORING]);
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_BARRIER].SetTextureName((char*)"data\\texture\\enemy_barrier.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_BARRIER]);
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ICE].SetTextureName((char*)"data\\texture\\enemy_icerain.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_ICE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ICE]);
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_STOP].SetTextureName((char*)"data\\texture\\enemy_stop.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_STOP].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_STOP]);


	//�r�̉摜�Z�b�g�i�{�́j
	m_pPlayerLeft->DrawSetHomingE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_MISSILE]);
	m_pPlayerLeft->DrawSetLaserE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_LASER]);
	m_pPlayerLeft->DrawSetGatoringE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_GATORING]);
	m_pPlayerLeft->DrawSetBarriarE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER]);
	m_pPlayerLeft->DrawSetIceRainE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_ICE]);
	m_pPlayerLeft->DrawSetStopE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_STOP]);

	m_pPlayerRight->DrawSetHomingE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_MISSILE]);
	m_pPlayerRight->DrawSetLaserE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_LASER]);
	m_pPlayerRight->DrawSetGatoringE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_GATORING]);
	m_pPlayerRight->DrawSetBarriarE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER]);
	m_pPlayerRight->DrawSetIceRainE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_ICE]);
	m_pPlayerRight->DrawSetStopE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_STOP]);

	m_pPlayerCenter->DrawSetHomingE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_MISSILE]);
	m_pPlayerCenter->DrawSetLaserE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_LASER]);
	m_pPlayerCenter->DrawSetGatoringE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_GATORING]);
	m_pPlayerCenter->DrawSetBarriarE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER]);
	m_pPlayerCenter->DrawSetIceRainE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_ICE]);
	m_pPlayerCenter->DrawSetStopE(&m_pDrawObject[(int)DRAW_TYPE::ENEMY_STOP]);

	//�r�̌���
	m_pPlayerArmChange = new PlayerArmChange(m_pPlayerLeft, m_pPlayerRight, m_pPlayerCenter);
}

//==========================
// �f�X�g���N�^
//==========================
InhStage::~InhStage()
{
	//�`�悪�Ȃ�����������Ă���
	delete m_pPlayerArmChange;

	//�Q�[���I�u�W�F�N�g������
	delete m_pBom;
	delete m_pBG;
	delete m_pPoorvision;
	delete m_pBG_Moon;
	delete m_pExplosionManagement;
	delete m_pMeteoManagement;
	delete m_pItemManagement;
	delete m_pPlayer;
	delete m_pPlayerHP;
	delete m_pPlayerLeft;
	delete m_pPlayerRight;
	delete m_pPlayerCenter;
	delete m_pComboNum;
	delete m_pMultiply;

	//���̂ق�
	delete[] m_pDrawObject;
	delete[] m_pTexUseful;

	//BGM���X�g�b�v
	StopSound(m_BGM);
}