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

//==========================
// �O���[�o���ϐ�
//==========================
int MercuryStopFlame = 0;	//�q�b�g�X�g�b�v�p
bool isDownMercury = false; //�{�X�����񂾂�

//==========================
// �����t���R���X�g���N�^
//==========================
StageMercury::StageMercury(Score* pNumber):InhStage(pNumber)
{
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\mercury.png");

	//======================
	// �G
	//���[�U�[
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER].SetTextureName((char*)"data\\texture\\laser00.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER]);
	m_pEnemyLaser = new EnemyLaserManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER], 2);

	//�X
	m_pEnemyIce = new EnemyIceRainManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ICE], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE], 2);

	//��
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_FIRE].SetTextureName((char*)"data\\texture\\enemy_fire.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIRE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_FIRE]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_FIRE].SetTextureName((char*)"data\\texture\\bullet_fire.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_FIRE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_FIRE]);
	m_pEnemyFire = new EnemyFireManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIRE], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_FIRE], 2);

	//�~�T�C��

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
	//delete m_pColAll;

	delete m_pEnemyLaser;
	delete m_pEnemyIce;
	delete m_pEnemyFire;
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
	m_pEnemyLaser->Update();
	m_pEnemyIce->Update();
	m_pEnemyFire->Update();

	//�{��
	m_pBom->Update();

	//====================================
	//�v���C���[��HP�ɑ΂��鏈��
	int attack_num = 0;

	//�v���C���[�̘r
	//�r�̃A�b�v�f�[�g
	m_pPlayerLeft->ButtonPress();
	m_pPlayerLeft->Update(m_pPlayer->GetPos(), D3DXVECTOR2(0.0f, 0.0f));
	m_pPlayerRight->ButtonPress();
	m_pPlayerRight->Update(m_pPlayer->GetPos(), D3DXVECTOR2(0.0f, 0.0f));
	m_pPlayerCenter->ButtonPress();
	m_pPlayerCenter->Update(m_pPlayer->GetPos(), D3DXVECTOR2(0.0f, 0.0f));

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
	m_pFrame->Draw();
	m_pPlayer->Draw();

	//�v���C���[�̘r�̕`�揈��
	m_pPlayerLeft->ArmDraw();
	m_pPlayerRight->ArmDraw();
	m_pPlayerCenter->ArmDraw();

	//�G�̕`��
	m_pEnemyLaser->Draw();
	m_pEnemyIce->Draw();
	m_pEnemyFire->Draw();

	//�v���C���[�̒e�̕\��
	m_pPlayer->DrawBullet();

	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	//�{���̕`��
	m_pBom->BomDraw();

	//UI�̕`��
	m_pFrame->Draw();
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