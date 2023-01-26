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

	m_pEnemyFireballManagement = new EnemyFireballManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIREBALL], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_FIREBALL]);

	//�_���J�̓G
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ACID].SetTextureName((char*)"data\\texture\\enemy_acid.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_ACID].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_ACID]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ACID].SetTextureName((char*)"data\\texture\\bullet_acid.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_ACID]);

	m_pEnemyAcidManagement = new EnemyAcidManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ACID], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID]);

	//���E����������G
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_POOR].SetTextureName((char*)"data\\texture\\enemy_poorvision.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_POOR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_POOR]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MIST].SetTextureName((char*)"data\\texture\\bullet_mist.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_MIST].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MIST]);

	m_pEnemuPoorvisionManagement = new EnemyPoorvisionManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_POOR], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_MIST]);

	//�v���C���[�̃X�s�[�h��x������G
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_SPEEDDOWN].SetTextureName((char*)"data\\texture\\enemy_speeddown.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_SPEEDDOWN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_SPEEDDOWN]);
	m_pDrawObject[(int)DRAW_TYPE::BULLET_SPEEDDOWN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MIST], 
		1.0f, 1.0f, 1.0f, 1, D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f));

	m_pEnemySpeeddownManagement = new EnemySpeeddownManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_SPEEDDOWN], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_SPEEDDOWN]);

	//�K�g�����O�G
	m_pEnemyGatoring = new EnemyGatoringManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_GATORING],
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY], 4);

	//�G�̊Ǘ�
	//m_pAllEnemyManagement->AddPointer(m_pEnemyFireballManagement);
	
	//�����蔻��
	m_pColAll = new CollisionAll(CollisionAll::STAGE::VENUS, m_pPlayer, m_pPlayerLeft, m_pPlayerRight,
		m_pExplosionManagement, m_pItemManagement, m_pScore, m_pBom);
	//�G�̃|�C���^���Z�b�g
	m_pColAll->AddEnemyPointer(m_pEnemyFireballManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyAcidManagement);
	m_pColAll->AddEnemyPointer(m_pEnemuPoorvisionManagement);
	m_pColAll->AddEnemyPointer(m_pEnemySpeeddownManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyGatoring);

	m_pPlayerCenter->DrawSetAcid(&m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID]);
	m_pPlayerRight->DrawSetAcid(&m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID]);
	m_pPlayerLeft->DrawSetAcid(&m_pDrawObject[(int)DRAW_TYPE::BULLET_ACID]);

}

//==========================
// �f�X�g���N�^
//==========================
StageVenus::~StageVenus()
{
	delete m_pColAll;
	delete m_pEnemyFireballManagement;
	delete m_pEnemuPoorvisionManagement;
	delete m_pEnemySpeeddownManagement;
	delete m_pEnemyAcidManagement;
	delete m_pEnemyGatoring;
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
	m_pEnemyGatoring->Update();

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
	attack_num += m_pColAll->Collision();

	//��
	m_pColAll->HeelCollision();

	//���E���������邩
	if (m_pColAll->IsPoorVision()) {
		InhStage::SetPoorVision();
		m_pColAll->SetPoorVision(false);
	}

	//�v���C���[��HP���U�����ɂ���Č��炷
	if (attack_num != 0) {
		m_pPlayerHP->ReduceHP((float)attack_num);
	}

	//�v���C���[��HP��0�ɂȂ�����...
	if (m_pPlayerHP->GetHP0Flag()) {
		SetStageClear(false);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_VENUS);
	}
	//�Ō�̗�̓G��S�ē|������
	if (m_pEnemuPoorvisionManagement->IsClear() && m_pEnemyAcidManagement->IsClear() && m_pEnemySpeeddownManagement->IsClear() && m_pEnemyFireballManagement->IsClear() && m_pEnemyGatoring->IsClear()) {
		//���U���g��ʂɍs��
		SetStageClear(true);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_SATURN);
	}
}

//==========================
// �`�揈��
//==========================
void StageVenus::Draw(void) const
{
	m_pBG->DrawBG();
	m_pBG_Moon->DrawBG();

	//UI�̕`��
	m_pFrame->Draw();
	m_pPlayerHP->DrawHP();
	m_pScore->DrawNumber();
	m_pComboNum->SetNumber(m_pScore->GetComboNum());
	m_pComboNum->DrawNumber();
	m_pMultiply->Draw();
	m_pStageVenus->Draw();


	//�v���C���[�̘r�̕`�揈��
	m_pPlayer->Draw();
	m_pPlayer->DrawBullet();
	m_pPlayerLeft->ArmDraw();
	m_pPlayerRight->ArmDraw();
	m_pPlayerCenter->ArmDraw();

	//�G�̕`��
	m_pEnemyFireballManagement->Draw();
	m_pEnemyAcidManagement->Draw();
	m_pEnemuPoorvisionManagement->Draw();
	m_pEnemySpeeddownManagement->Draw();
	m_pEnemyGatoring->Draw();

	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	//�{���̕`��
	m_pBom->BomDraw();

	m_pPoorvision->Draw();
}
