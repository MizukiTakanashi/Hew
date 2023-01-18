//=======================================
// �ΐ��̃X�e�[�W�֌W(cpp�t�@�C��)
// �쐬���F2022/12/15
// �쐬�ҁF��������
//=======================================
#include "stage_mars.h"
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
StageMars::StageMars(Score* pNumber):InhStage(pNumber)
{
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\mars.png");

	//�o���A�̓G
	m_pEnemyBarrierManagement = new EnemyBarrierManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER], m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER]);

	//�X�̓G
	m_pEnemyIceRainManagement = new EnemyIceRainManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_ICE], m_pDrawObject[(int)DRAW_TYPE::BULLET_ICE], 1);

	//�������~�߂�G
	m_pEnemyStopManagement = new EnemyStopManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_STOP], m_pDrawObject[(int)DRAW_TYPE::BULLET_STOP]);
	
	//�z�[�~���O�̓G
	m_pEnemyMissileManagement = new EnemyMissileManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_NORMAL], m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY], 1);

	//�O���l�[�h�G
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_GREANADE].SetTextureName((char*)"data\\texture\\grenade.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_GRENADE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_GREANADE]);
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_GRENADE_EXPLOSION].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::EXPLOSION], 0.0f, 0.125f, 1.0f, 7);
	m_pEnemyGrenadeManagement = new EnemyGrenadeManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_GRENADE],
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY], m_pDrawObject[(int)DRAW_TYPE::ENEMY_GRENADE_EXPLOSION], 1);



	//�G�̊Ǘ�
	m_pAllEnemyManagement = new AllEnemyManagement;
	m_pAllEnemyManagement->AddPointer(m_pEnemyBarrierManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyStopManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyIceRainManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyGrenadeManagement);
	m_pAllEnemyManagement->AddPointer(m_pEnemyMissileManagement);

	//========================================================
	// �S�Ă̓����蔻��
	m_pColAll = new MarsCollisionAll(m_pPlayer, m_pPlayerLeft, m_pPlayerRight, m_pExplosionManagement,
		m_pItemManagement, m_pScore, m_pBom, m_pEnemyGrenadeManagement);

	//�G�̃|�C���^���Z�b�g�i���ԕς����NG�j
	m_pColAll->AddEnemyPointer(m_pEnemyBarrierManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyStopManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyIceRainManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyGrenadeManagement);
	m_pColAll->AddEnemyPointer(m_pEnemyMissileManagement);
}

//==========================
// �f�X�g���N�^
//==========================
StageMars::~StageMars()
{
	//�`�悪�Ȃ�����������Ă���
	delete m_pAllEnemyManagement;
	delete m_pColAll;

	//�Q�[���I�u�W�F�N�g������
	if(m_pBoss)
	delete m_pBoss;
	delete m_pEnemyBarrierManagement;
	delete m_pEnemyMissileManagement;
	delete m_pEnemyGrenadeManagement;
	delete m_pEnemyIceRainManagement;
	delete m_pEnemyStopManagement;
}

//==========================
// �X�V����
//==========================
void StageMars::Update(void)
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
	m_pEnemyMissileManagement->Update(m_pPlayer->GetPos());
	m_pEnemyBarrierManagement->Update();
	m_pEnemyIceRainManagement->Update(m_pPlayer->GetPos());
	m_pEnemyStopManagement->Update();
	m_pEnemyGrenadeManagement->Update(m_pPlayer->GetPos());

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

	//�{�X����
	if (m_pBoss)
	{
		m_pBoss->Update();
	}
	else if(m_pEnemyBarrierManagement->IsClear() && m_pEnemyStopManagement->IsClear())
	{
		m_pBoss = new Boss(m_pDrawObject[(int)DRAW_TYPE::ENEMY_STOP], this);
	}


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
		Fade(SCENE::SCENE_RESULT);
	}

}

//==========================
// �`�揈��
//==========================
void StageMars::Draw(void) const
{
	m_pBG->DrawBG();
	m_pBG_Moon->DrawBG();


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

	//�v���C���[�̕`�揈��
	m_pPlayer->Draw();
	m_pPlayer->DrawBullet();
	m_pPlayerLeft->ArmDraw();
	m_pPlayerRight->ArmDraw();
	m_pPlayerCenter->ArmDraw();

	//�G�̕`��
	m_pEnemyMissileManagement->Draw();
	m_pEnemyBarrierManagement->Draw();
	m_pEnemyIceRainManagement->Draw();
	m_pEnemyStopManagement->Draw();
	m_pEnemyGrenadeManagement->Draw();
	if (m_pBoss)
		m_pBoss->Draw();


}
