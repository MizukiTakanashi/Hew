//=======================================
// �ΐ��̃X�e�[�W�֌W(cpp�t�@�C��)
// �쐬���F2022/12/15
// �쐬�ҁF��������
//=======================================
#include "stage_mercury.h"
#include "sound.h"

//==========================
// �萔������
//==========================
const D3DXVECTOR2 StageMercury::NUMBER_POS = D3DXVECTOR2(1230.0f, 30.0f);
const D3DXVECTOR2 StageMercury::NUMBER_SIZE = D3DXVECTOR2(30.0f, 30.0f);

//==========================
// �O���[�o���ϐ�
//==========================
int MercuryStopFlame = 0; //�q�b�g�X�g�b�v�p
bool isDownMercury = false; //�{�X�����񂾂�

//==========================
// �����t���R���X�g���N�^
//==========================
StageMercury::StageMercury(Score* pNumber):m_pScore(pNumber)
{
	m_BGM = LoadSound((char*)"data\\BGM\\opportunity (online-audio-converter.com).wav");	//�T�E���h�̃��[�h
	PlaySound(m_BGM, -1);	//BGM�Đ�
	SetVolume(m_BGM, 0.1f);

	m_pTexUseful = new TextureUseful[(int)TEXTURE_TYPE::NUM];
	m_pDrawObject = new DrawObject[(int)DRAW_TYPE::NUM];

	//�w�i�̏���������
	m_pBG = new BG((char*)"data\\texture\\game_bg_scroll.jpg");
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\mercury.png");

	//=======================
	// �e
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_RED].SetTextureName((char*)"data\\texture\\bullet_red.png");
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN].SetTextureName((char*)"data\\texture\\bullet_green.png");
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_SQUARE_GREEN].SetTextureName((char*)"data\\texture\\bullet02.png");
	//�v���C���[���̒e
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_SQUARE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	//���e
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	//�G���̒e
	m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_RED]);

	//�o���A
	m_pTexUseful[(int)TEXTURE_TYPE::BARRIER].SetTextureName((char*)"data\\texture\\Barrier.png");

	//�v���C���[
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER].SetTextureName((char*)"data\\texture\\player_anime.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER], 1.0f, 0.25f, 1.0f, 4);
	m_pPlayer = new Player(m_pDrawObject[(int)DRAW_TYPE::PLAYER], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET], m_pDrawObject[(int)DRAW_TYPE::PLAYER_BULLET]);

	//=======================
	// �G
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY].SetTextureName((char*)"data\\texture\\teki2.png");

	//�o���A�̓G
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_BARRIER].SetTextureName((char*)"data\\texture\\monster11.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_BARRIER]);
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER_BARRIER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BARRIER]);

	m_pEnemyBarrierManagement = new EnemyBarrierManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER], m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER_BARRIER]);

	//=======================
	// �c�e�\��
	m_pTexUseful[(int)TEXTURE_TYPE::NUMBER].SetTextureName((char*)"data\\texture\\number.png");
	m_pDrawObject[(int)DRAW_TYPE::NUMBER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::NUMBER], 0.0f, 0.0909f, 1.0f, 11);

	//=======================
	// �R���{���̉��́~
	m_pTexUseful[(int)TEXTURE_TYPE::MULTIPLY].SetTextureName((char*)"data\\texture\\multiply.png");
	m_pDrawObject[(int)DRAW_TYPE::MULTIPLY].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::MULTIPLY], 0.0f, 1.0f, 1.0f, 1);
	m_pMultiply = new UI(m_pDrawObject[(int)DRAW_TYPE::MULTIPLY], D3DXVECTOR2(SCREEN_WIDTH - 130, SCREEN_HEIGHT - 40), D3DXVECTOR2(40.0f, 40.0f), D3DXCOLOR());

	//=======================
	// �R���{�p�����\��
	m_pComboNum = new Number(m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(40.0f, 60.0f), 2);
	m_pComboNum->SetInitPos(D3DXVECTOR2(SCREEN_WIDTH - 30, SCREEN_HEIGHT - 40));

	//=======================
	// �v���C���[�̘r�̍�
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 0.0f, 0.33f, 1.0f, 3);
	//�e
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.2f, 1.0f, 0.2f, 1.0f));
	//���[�U�[
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));
	m_pPlayerLeft = new PlayerLeft(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT], m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(130.0f, 600.0f), D3DXVECTOR2(30.0f, 600.0f));

	//=======================
	// �v���C���[�̘r�̉E
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 0.0f, 0.33f, 1.0f, 3);
	//�e
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.2f, 1.0f, 0.2f, 1.0f));
	//���[�U�[
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));
	m_pPlayerRight = new PlayerRight(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_RIGHT], m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(130.0f, 680.0f), D3DXVECTOR2(30.0f, 680.0f));

	//=======================
	// �v���C���[�̘r�̐^��
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY], 0.0f, 0.33f, 1.0f, 3);
	//�e
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTTER_BULLET].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.2f, 1.0f, 0.2f, 1.0f));
	//���[�U�[
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTER_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER], 0.0f, 1.0f, 1.0f, 1,
		D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));
	m_pPlayerCenter = new PlayerCenter(m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_CENTER], m_pPlayer->GetPos(), m_pDrawObject[(int)DRAW_TYPE::NUMBER], D3DXVECTOR2(130.0f, 520.0f), D3DXVECTOR2(30.0f, 520.0f));

	m_pPlayerLeft->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_BULLET]);
	m_pPlayerLeft->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_LASER]);
	m_pPlayerRight->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_BULLET]);
	m_pPlayerRight->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_LASER]);
	m_pPlayerCenter->DrawSetSurcleBullet(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_BULLET]);
	m_pPlayerCenter->DrawSetLaser(&m_pDrawObject[(int)DRAW_TYPE::PLAYER_ARM_LEFT_LASER]);

	//�r�̌���
	m_pPlayerArmChange = new PlayerArmChange(m_pPlayerLeft, m_pPlayerRight, m_pPlayerCenter);

	//����
	m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION].SetTextureName((char*)"data\\texture\\explosion000.png");
	m_pDrawObject[(int)DRAW_TYPE::EXPLOSION].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION], 0.0f, 0.125f, 1.0f, 7);
	m_pExplosionManagement = new ExplosionManagement(m_pDrawObject[(int)DRAW_TYPE::EXPLOSION]);

	//�G�̃A�C�e��
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ITEM].SetTextureName((char*)"data\\texture\\EnemyItem.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_ITEM].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ITEM], 0.0f, 1.0f, 1.0f, 1);
	m_pItemManagement = new ItemManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ITEM]);

	//�����̏�����
	m_pScore->SetInitPos(NUMBER_POS);
	m_pScore->SetPos(NUMBER_POS);
	m_pScore->SetSize(NUMBER_SIZE);
	m_pScore->SetDigit(NUMBER_DIGIT);

	//�v���C���[��HP
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP].SetTextureName((char*)"data\\texture\\hp.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_HP], 0.0f, 0.5f, 1.0f, 2);

	m_pPlayerHP = new PlayerHP(m_pDrawObject[(int)DRAW_TYPE::PLAYER_HP_BAR], m_pExplosionManagement, m_pPlayer);

	//�{��
	m_pDrawObject[(int)DRAW_TYPE::BOMB].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_CIRCLE_GREEN]);
	m_pBom = new Bom(m_pDrawObject[(int)DRAW_TYPE::BOMB], 3);

	//�G�̊Ǘ�
	m_pAllEnemyManagement = new AllEnemyManagement;
	m_pAllEnemyManagement->AddPointer(m_pEnemyBarrierManagement);
	
	//========================================================
	// �S�Ă̓����蔻��
	//m_pColAll = new CollisionAll(m_pPlayer, m_pPlayerLeft, m_pPlayerRight, m_pExplosionManagement,
	//	m_pItemManagement, m_pScore, m_pBom, );

	//�G�̃|�C���^���Z�b�g�i���ԕς����NG�j
	//m_pColAll->AddEnemyPointer(m_pEnemyBarrierManagement);
}

//==========================
// �f�X�g���N�^
//==========================
StageMercury::~StageMercury()
{
	//�`�悪�Ȃ�����������Ă���
	delete m_pAllEnemyManagement;
	delete m_pPlayerArmChange;
	//delete m_pColAll;

	//�Q�[���I�u�W�F�N�g������
	delete m_pBom;
	delete m_pBG;
	delete m_pBG_Moon;
	delete m_pExplosionManagement;
	delete m_pEnemyBarrierManagement;
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

//==========================
// �X�V����
//==========================
void StageMercury::Update(void)
{
	//�q�b�g�X�g�b�v
	if (MercuryStopFlame > 0)
	{
		MercuryStopFlame--;
		return;
	}

	//�{�X�����񂾂�
	if (isDownMercury)
		Fade(SCENE::SCENE_RESULT);

	//�w�i
	m_pBG->Update();
	m_pBG_Moon->Update();

	//�r�̐؂�ւ�
	m_pPlayerArmChange->Change();

	//�v���C���[
	m_pPlayer->Update(m_pPlayerHP->IsPlayerInvincible());

	m_pPlayerHP->Update();

	//����
	m_pExplosionManagement->Update();

	//�G���痎����A�C�e��
	m_pItemManagement->Update();

	//=======================
	// �G
	m_pEnemyBarrierManagement->Update();

	//�{��
	m_pBom->Update();

	//====================================
	//�v���C���[��HP�ɑ΂��鏈��
	int attack_num = 0;

	//�v���C���[�̘r

	//�z�[�~���O�e�p
	D3DXVECTOR2 temp_pos = m_pAllEnemyManagement->GetCloltestEnemyPos(m_pPlayerLeft->GetPos());

	//�r�̃A�b�v�f�[�g
	m_pPlayerLeft->ButtonPress();
	m_pPlayerLeft->Update(m_pPlayer->GetPos(), temp_pos);
	m_pPlayerRight->ButtonPress();
	m_pPlayerRight->Update(m_pPlayer->GetPos(), temp_pos);
	m_pPlayerCenter->ButtonPress();
	m_pPlayerCenter->Update(m_pPlayer->GetPos(), temp_pos);

	//�G�ƃv���C���[�̓����蔻��
	//attack_num += m_pColAll->Collision();

	//��
	//m_pColAll->HeelCollision();

	//�v���C���[��HP���U�����ɂ���Č��炷
	if (attack_num != 0) {
		m_pPlayerHP->ReduceHP((float)attack_num);
	}

	//�v���C���[��HP��0�ɂȂ�����...
	if (m_pPlayerHP->GetHP0Flag()) {
		Fade(SCENE::SCENE_RESULT);
	}
}

//==========================
// �`�揈��
//==========================
void StageMercury::Draw(void) const
{
	m_pBG->DrawBG();
	m_pBG_Moon->DrawBG();
	m_pPlayer->Draw();

	//�v���C���[�̘r�̕`�揈��
	m_pPlayerLeft->ArmDraw();
	m_pPlayerRight->ArmDraw();
	m_pPlayerCenter->ArmDraw();

	//�G�̕`��
	m_pEnemyBarrierManagement->Draw();

	//�v���C���[�̒e�̕\��
	m_pPlayer->DrawBullet();

	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	//�{���̕`��
	m_pBom->BomDraw();

	//UI�̕`��
	m_pPlayerHP->DrawHP();
	m_pScore->DrawNumber();
	m_pComboNum->SetNumber(m_pScore->GetComboNum());
	m_pComboNum->DrawNumber();
	m_pMultiply->Draw();
}

//==========================
// �q�b�g�X�g�b�v
//==========================
void MercuryHitStop(int flame)
{
	MercuryStopFlame = flame;
}

void MercuryBossDown()
{
	isDownMercury = true;
}