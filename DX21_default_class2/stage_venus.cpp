//=======================================
// �����̃X�e�[�W�֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "stage_venus.h"
#include "sound.h"

//==========================
// �����t���R���X�g���N�^
//==========================
StageVenus::StageVenus(Score* pNumber):InhStage(pNumber)
{
	//�摜�ǂݍ���
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\venus.png");

	//=======================
	// �G
	//�΋��̓G
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_FIREBALL].SetTextureName((char*)"data\\texture\\enemy_fireball.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIREBALL].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_FIREBALL]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_FIREBALL].SetTextureName((char*)"data\\texture\\sun.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_FIREBALL].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_FIREBALL]);

	m_pEnemyFireballManagement = new EnemyFireballManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIREBALL], m_pDrawObject[(int)DRAW_TYPE::BULLET_FIREBALL]);

	//�_���J�̓G
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ACID].SetTextureName((char*)"data\\texture\\enemy_acid.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_ACID].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ACID]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ACID].SetTextureName((char*)"data\\texture\\bullet_acid.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ACID]);

	m_pEnemyAcidManagement = new EnemyAcidManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ACID], m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID]);

	//���E����������G
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_POOR].SetTextureName((char*)"data\\texture\\enemy_poorvision.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_POOR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_POOR]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MIST].SetTextureName((char*)"data\\texture\\bullet_mist.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_MIST].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MIST]);

	m_pEnemuPoorvisionManagement = new EnemyPoorvisionManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_POOR], m_pDrawObject[(int)DRAW_TYPE::BULLET_MIST]);

	//�v���C���[�̃X�s�[�h��x������G
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_SPEEDDOWN].SetTextureName((char*)"data\\texture\\enemy_speeddown.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_SPEEDDOWN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_SPEEDDOWN]);
	m_pDrawObject[(int)DRAW_TYPE::BULLET_SPEEDDOWN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MIST], 1.0f, 1.0f, 1.0f, 1, D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));

	m_pEnemySpeeddownManagement = new EnemySpeeddownManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_SPEEDDOWN], m_pDrawObject[(int)DRAW_TYPE::BULLET_SPEEDDOWN]);


	//�G�̊Ǘ�
	//m_pAllEnemyManagement->AddPointer(m_pEnemyFireballManagement);
	

	//�G�̃|�C���^���Z�b�g�i���ԕς����NG�j
	//m_pColAll->AddEnemyPointer(m_pEnemyFireballManagement);
}

//==========================
// �f�X�g���N�^
//==========================
StageVenus::~StageVenus()
{
	delete m_pEnemyFireballManagement;
	delete m_pEnemuPoorvisionManagement;
	delete m_pEnemySpeeddownManagement;
	delete m_pEnemyAcidManagement;
	delete m_pColAll;
}

//==========================
// �X�V����
//==========================
void StageVenus::Update(void)
{
	//�q�b�g�X�g�b�v
	if (m_StopFlame > 0)
	{
		m_StopFlame--;
		return;
	}

	//�{�X�����񂾂�
	if (m_isBossDown)
	{
		SetStageClear(true);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_VENUS);
	}

	//�w�i
	m_pBG->Update();
	m_pBG_Moon->Update();

	//�r�̐؂�ւ�
	m_pPlayerArmChange->Change();

	//�v���C���[
	m_pPlayer->Update(m_pPlayerHP->IsPlayerInvincible());
	m_pPoorvision->Update(m_pPlayer->GetPos());

	m_pPlayerHP->Update();

	//����
	m_pExplosionManagement->Update();

	//�G���痎����A�C�e��
	m_pItemManagement->Update();

	//=======================
	// �G
	m_pEnemyFireballManagement->Update(m_pPlayer->GetPos());
	m_pEnemyAcidManagement->Update();
	m_pEnemuPoorvisionManagement->Update();
	m_pEnemySpeeddownManagement->Update();

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
		SetStageClear(false);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_VENUS);
	}
}

//==========================
// �`�揈��
//==========================
void StageVenus::Draw(void) const
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
	m_pEnemyFireballManagement->Draw();
	m_pEnemyAcidManagement->Draw();
	m_pEnemuPoorvisionManagement->Draw();
	m_pEnemySpeeddownManagement->Draw();

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

	m_pPoorvision->Draw();
}
