//=======================================
// �����̃X�e�[�W�֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "stage_venus.h"
#include "sound.h"

//==========================
// �萔������
//==========================

//==========================
// �O���[�o���ϐ�
//==========================

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
	m_pEnemyFireballManagement->Update(m_pPlayer->GetPos());

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
