//=======================================
// �y���̃X�e�[�W�֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "stage_saturn.h"
#include "sound.h"

//==========================
// �����t���R���X�g���N�^
//==========================
StageSaturn::StageSaturn(Score* pNumber):InhStage(pNumber)
{
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\saturn.png");

	//=======================
	// �G
	//���[�U�[�̓G
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER].SetTextureName((char*)"data\\texture\\bullet_gass.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER]);
	m_pEnemyLaserManagement = new EnemyLaserManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER], 3);

	//�߂��݂�
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_MEGUMIN].SetTextureName((char*)"data\\texture\\megumin.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_MEGUMIN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_MEGUMIN]);
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MEGUMIN].SetTextureName((char*)"data\\texture\\bullet_megumin.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_MEGUMIN].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_MEGUMIN]);
	m_pEnemyMeguminManagement = new EnemyMeguminManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_MEGUMIN], 
		m_pDrawObject[(int)DRAW_TYPE::BULLET_MEGUMIN]);

	//�ŏ�
	m_pTexUseful[(int)TEXTURE_TYPE::POISON].SetTextureName((char*)"data\\texture\\poison.jpg");
	m_pDrawObject[(int)DRAW_TYPE::POISON].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::POISON], 2.0f, 1.0, 1.0f, 3);
	m_pPoisonField = new Management_PoisonField(m_pDrawObject[(int)DRAW_TYPE::POISON]);

	//�G�̊Ǘ�
	m_pAllEnemyManagement = new AllEnemyManagement;
	m_pAllEnemyManagement->AddPointer(m_pEnemyLaserManagement);
	
	//========================================================
	// �S�Ă̓����蔻��
	m_pColAll = new CollisionAll(CollisionAll::STAGE::SATURN, m_pPlayer, m_pPlayerLeft, m_pPlayerRight, m_pExplosionManagement,
		m_pItemManagement, m_pScore, m_pBom);
	m_pColAll->SetPoison(m_pPoisonField);

	//�G�̃|�C���^���Z�b�g
	m_pColAll->AddEnemyPointer(m_pEnemyMeguminManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyLaserManagement);
}

//==========================
// �f�X�g���N�^
//==========================
StageSaturn::~StageSaturn()
{
	delete m_pAllEnemyManagement;
	delete m_pColAll;
	delete m_pEnemyLaserManagement;
	delete m_pEnemyMeguminManagement;
	delete m_pPoisonField;
}

//==========================
// �X�V����
//==========================
void StageSaturn::Update(void)
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
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_SATURN);
	}

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
	m_pEnemyLaserManagement->Update();
	m_pEnemyMeguminManagement->Update();

	m_pPoisonField->Update();
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
	attack_num += m_pColAll->Collision();

	//��
	m_pColAll->HeelCollision();

	//�v���C���[��HP���U�����ɂ���Č��炷
	if (attack_num != 0) {
		m_pPlayerHP->ReduceHP((float)attack_num);
	}

	//�v���C���[��HP��0�ɂȂ�����...
	if (m_pPlayerHP->GetHP0Flag()) {
		SetStageClear(false);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_SATURN);
	}

	//�Ō�̗�̓G��S�ē|������
	if (m_pEnemyLaserManagement->IsClear() && m_pEnemyMeguminManagement->IsClear()) {
		//���U���g��ʂɍs��
		SetStageClear(true);
		Fade(SCENE::SCENE_RESULT, STAGE::STAGE_SATURN);
	}
}

//==========================
// �`�揈��
//==========================
void StageSaturn::Draw(void) const
{
	m_pBG->DrawBG();
	m_pBG_Moon->DrawSaturn();

	//UI�̕`��
	m_pFrame->Draw();
	m_pPlayerHP->DrawHP();
	m_pScore->DrawNumber();
	m_pComboNum->SetNumber(m_pScore->GetComboNum());
	m_pComboNum->DrawNumber();
	m_pMultiply->Draw();
	m_pStageSataurn->Draw();

	//�v���C���[�̘r�̕`�揈��
	m_pPlayer->Draw();
	m_pPlayer->DrawBullet();
	m_pPlayerLeft->ArmDraw();
	m_pPlayerRight->ArmDraw();
	m_pPlayerCenter->ArmDraw();

	//�G�̕`��
	m_pEnemyLaserManagement->Draw();
	m_pEnemyMeguminManagement->Draw();

	m_pPoisonField->Draw();

	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	//�{���̕`��
	m_pBom->BomDraw();


}
