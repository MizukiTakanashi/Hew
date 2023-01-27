//=======================================
// �ΐ��̃X�e�[�W�֌W(cpp�t�@�C��)
// �쐬���F2022/12/15
// �쐬�ҁF��������
//=======================================
#include "stage_mercury.h"
#include "sound.h"

//==========================
// �����t���R���X�g���N�^
//==========================
StageMercury::StageMercury(Score* pNumber):InhStage(pNumber)
{
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\mercury.png");

	//�v���C���[�̉���Ԃ��Z�b�g
	m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_FIRE].SetTextureName((char*)"data\\texture\\player_fire.png");
	m_pDrawObject[(int)DRAW_TYPE::PLAYER_FIRE].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::PLAYER_FIRE]);
	m_pPlayer->SetDrawFire(m_pDrawObject[(int)DRAW_TYPE::PLAYER_FIRE]);

	//======================
	// �G
	//���[�U�[
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER].SetTextureName((char*)"data\\texture\\laser.png");
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
	m_pEnemyMissile = new EnemyMissileManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_NORMAL],
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY], 2);

	m_pBossManagement = new BossManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_FIRE], m_pDrawObject[(int)DRAW_TYPE::BULLET_FIRE], 1);
	//�r
	m_pPlayerLeft->DrawSetFireE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_FIRE]);
	m_pPlayerLeft->DrawSetFire(&m_pDrawObject[(int)DRAW_TYPE::BULLET_FIRE]);
	m_pPlayerRight->DrawSetFireE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_FIRE]);
	m_pPlayerRight->DrawSetFire(&m_pDrawObject[(int)DRAW_TYPE::BULLET_FIRE]);
	m_pPlayerCenter->DrawSetFireE(&m_pDrawObject[(int)DRAW_TYPE::ITEM_FIRE]);
	m_pPlayerCenter->DrawSetFire(&m_pDrawObject[(int)DRAW_TYPE::BULLET_FIRE]);

	//���M�~�b�N
	m_pTexUseful[(int)TEXTURE_TYPE::FIREFIELD].SetTextureName((char*)"data\\texture\\gimmick_Mercury2.png");
	m_pDrawObject[(int)DRAW_TYPE::FIREFIELD].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::FIREFIELD], 2.0f, 1.0, 1.0f, 3);
	m_pManagement_FireField = new Management_FireField(m_pDrawObject[(int)DRAW_TYPE::FIREFIELD]);

	//�X�M�~�b�N
	m_pTexUseful[(int)TEXTURE_TYPE::ICEFIELD].SetTextureName((char*)"data\\texture\\gimmick_Mercury .png");
	m_pDrawObject[(int)DRAW_TYPE::ICEFIELD].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ICEFIELD], 2.0f, 1.0, 1.0f, 3);
	m_pManagement_IceField = new Management_IceField(m_pDrawObject[(int)DRAW_TYPE::ICEFIELD]);
	
	//�G�̊Ǘ�
	m_pAllEnemyManagement = new AllEnemyManagement;
	m_pAllEnemyManagement->AddPointer(m_pEnemyLaser);
	m_pAllEnemyManagement->AddPointer(m_pEnemyIce);
	m_pAllEnemyManagement->AddPointer(m_pEnemyFire);
	m_pAllEnemyManagement->AddPointer(m_pEnemyMissile);
	m_pAllEnemyManagement->AddPointer(m_pBossManagement);

	//========================================================
	// �S�Ă̓����蔻��
	m_pColAll = new CollisionAll(CollisionAll::STAGE::MERCURY, m_pPlayer, m_pPlayerLeft, m_pPlayerRight, m_pExplosionManagement,
		m_pItemManagement, m_pScore, m_pBom);
	m_pColAll->SetHP(m_pPlayerHP);
	m_pColAll->SetIceField(m_pManagement_IceField);
	m_pColAll->SetFireField(m_pManagement_FireField);

	//�G�̃|�C���^���Z�b�g
	m_pColAll->AddEnemyPointer(m_pEnemyLaser);
	m_pColAll->AddEnemyPointer(m_pEnemyIce);
	m_pColAll->AddEnemyPointer(m_pEnemyFire);
	m_pColAll->AddEnemyPointer(m_pEnemyMissile);
	m_pColAll->AddEnemyPointer(m_pBossManagement);
}

//==========================
// �f�X�g���N�^
//==========================
StageMercury::~StageMercury()
{
	delete m_pColAll;
	delete m_pAllEnemyManagement;

	delete m_pEnemyLaser;
	delete m_pEnemyIce;
	delete m_pEnemyFire;
	delete m_pEnemyMissile;
	delete m_pManagement_IceField;
	delete m_pManagement_FireField;
	delete m_pBossManagement;
	;
}

//==========================
// �X�V����
//==========================
void StageMercury::Update(void)
{
	//�q�b�g�X�g�b�v
	if (m_StopFlame > 0)
	{
		m_StopFlame--;

		//�������ɂȂ�̂ł����...
		if (m_HitStopSlow != -1) {
			//���Ԃ������珈����������
			if (++m_HitStopSlow >= HIT_STOP_SLOW_INTERVAL) {
				m_HitStopSlow = 0;
			}
			else{
				return;
			}
		}
		//�������ɂȂ�Ȃ��̂ł����...
		else {
			//�������΂�
			return;
		}
	}

	//�v���C���[��HP��0�ɂȂ�����...
	if (m_pPlayerHP->GetHP0Flag()) {
		if (m_GameoverHitstop) {
			m_StopFlame = HIT_STOP_TIME;
			m_GameoverHitstop = false;
			m_HitStopSlow = 0;
		}
		else {
			if (m_StopFlame <= 0) {
				SetStageClear(false);
				Fade(SCENE::SCENE_RESULT, STAGE::STAGE_MERCURY);
				return;
			}
		}
	}

	//�Ō�̗�̓G��S�ē|������
	if (m_pEnemyLaser->IsClear() && m_pEnemyIce->IsClear() &&
		m_pEnemyFire->IsClear() && m_pEnemyMissile->IsClear() && m_pBossManagement->IsClear()) {
		if (m_GameclearHitstop) {
			m_StopFlame = HIT_STOP_TIME;
			m_GameclearHitstop = false;
			m_HitStopSlow = 0;
		}
		else {
			if (m_StopFlame <= 0) {
				//���U���g��ʂɍs��
				SetStageClear(true);
				Fade(SCENE::SCENE_RESULT, STAGE::STAGE_MERCURY);
				return;
			}
		}
	}

	////�{�X�����񂾂�
	//if (m_isBossDown)
	//{
	//	SetStageClear(true);
	//	Fade(SCENE::SCENE_RESULT, STAGE::STAGE_MERCURY);
	//}

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
	m_pEnemyMissile->Update(m_pPlayer->GetPos());
	m_pBossManagement->Update();

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
		//���̂������̃q�b�g�X�g�b�v
	if (m_pPlayerLeft->IsHitStop()) {
		m_StopFlame = HIT_STOP_UNION;
		m_pPlayerLeft->SetHitStop(false);
	}
	if (m_pPlayerRight->IsHitStop()) {
		m_StopFlame = HIT_STOP_UNION;
		m_pPlayerRight->SetHitStop(false);
	}
	
	//�X�e�[�W�M�~�b�N
	m_pManagement_FireField->Update();
	m_pManagement_IceField->Update();

	//�G�ƃv���C���[�̓����蔻��
	attack_num += m_pColAll->Collision();

	//��
	m_pColAll->HeelCollision();

	//�v���C���[��HP���U�����ɂ���Č��炷
	if (attack_num != 0) {
		m_pPlayerHP->ReduceHP((float)attack_num);
	}
}

//==========================
// �`�揈��
//==========================
void StageMercury::Draw(void) const
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
	m_pStageMarcury->Draw();

	//�v���C���[�̕`�揈��
	m_pPlayer->Draw();
	m_pPlayer->DrawBullet();
	m_pPlayerLeft->ArmDraw();
	m_pPlayerRight->ArmDraw();
	m_pPlayerCenter->ArmDraw();

	//�G�̕`��
	m_pEnemyLaser->Draw();
	m_pEnemyIce->Draw();
	m_pEnemyFire->Draw();
	m_pEnemyMissile->Draw();
	m_pBossManagement->Draw();

	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	m_pManagement_IceField->Draw();
	m_pManagement_FireField->Draw();


	//�{���̕`��
	m_pBom->BomDraw();

}
