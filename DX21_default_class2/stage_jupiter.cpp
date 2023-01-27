//=======================================
// �ؐ��̃X�e�[�W�֌W(cpp�t�@�C��)
// �쐬���F2023/01/26
// �쐬�ҁF��������
//=======================================
#include "stage_jupiter.h"
#include "sound.h"

//==========================
// �����t���R���X�g���N�^
//==========================
StageJupiter::StageJupiter(Score* pNumber) :InhStage(pNumber)
{
	m_pBG_Moon = new BGPlanet((char*)"data\\texture\\jupiter.png");

	//�ؐ�
	m_pTexUseful[(int)TEXTURE_TYPE::JUPITOR].SetTextureName((char*)"data\\texture\\jupiter_name.png");
	m_pDrawObject[(int)DRAW_TYPE::JUPITOR].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::JUPITOR], 0.0f, 1.0f, 1.0f, 1);
	m_pStageJupitor = new UI(m_pDrawObject[(int)DRAW_TYPE::JUPITOR], D3DXVECTOR2(160.0f, 40.0f), D3DXVECTOR2(80.0f, 25.0f), D3DXCOLOR());

	//======================
	// �G
	//���[�U�[
	m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER].SetTextureName((char*)"data\\texture\\laser.png");
	m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::BULLET_LASER]);
	m_pEnemyLaser = new EnemyLaserManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER],
		m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER], 5);

	//�~�T�C��
	m_pEnemyMissile = new EnemyMissileManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_NORMAL],
		m_pDrawObject[(int)DRAW_TYPE::BULLET_ENEMY], 5);

	//�o���A
	m_pEnemyBarrier = new EnemyBarrierManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_BARRIER],
		m_pDrawObject[(int)DRAW_TYPE::BULLET_BARRIER], 5);

	//�������Ă��Ȃ��G
	m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_PUBLIC].SetTextureName((char*)"data\\texture\\enemy_normal.png");
	m_pDrawObject[(int)DRAW_TYPE::ENEMY_PUBLIC].SetDrawObject(m_pTexUseful[(int)TEXTURE_TYPE::ENEMY_PUBLIC]);
	m_pEnemyPublic = new Management_EnemyPublic(m_pDrawObject[(int)DRAW_TYPE::ENEMY_PUBLIC]);

	m_pBossManagement = new BossManagement(m_pDrawObject[(int)DRAW_TYPE::ENEMY_LASER], m_pDrawObject[(int)DRAW_TYPE::BULLET_LASER], 5);

	//�G�̊Ǘ�
	m_pAllEnemyManagement = new AllEnemyManagement;
	m_pAllEnemyManagement->AddPointer(m_pEnemyLaser);
	m_pAllEnemyManagement->AddPointer(m_pEnemyMissile);
	m_pAllEnemyManagement->AddPointer(m_pEnemyPublic);
	m_pAllEnemyManagement->AddPointer(m_pEnemyBarrier);
	m_pAllEnemyManagement->AddPointer(m_pBossManagement);

	//========================================================
	// �S�Ă̓����蔻��
	m_pColAll = new CollisionAll(CollisionAll::STAGE::JUPITER, m_pPlayer, m_pPlayerLeft, m_pPlayerRight, m_pExplosionManagement,
		m_pItemManagement, m_pScore, m_pBom);

	//�G�̃|�C���^���Z�b�g
	m_pColAll->AddEnemyPointer(m_pEnemyLaser);
	m_pColAll->AddEnemyPointer(m_pEnemyMissile);
	m_pColAll->AddEnemyPointer(m_pEnemyBarrier);
	m_pColAll->AddEnemyPointer(m_pEnemyPublic);
	m_pColAll->AddEnemyPointer(m_pBossManagement);
}

//==========================
// �f�X�g���N�^
//==========================
StageJupiter::~StageJupiter()
{
	delete m_pColAll;
	delete m_pAllEnemyManagement;

	delete m_pEnemyLaser;
	delete m_pEnemyMissile;
	delete m_pEnemyBarrier; 
	delete m_pEnemyPublic;
	delete m_pBossManagement;
}

//==========================
// �X�V����
//==========================
void StageJupiter::Update(void)
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
			else {
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
				Fade(SCENE::SCENE_RESULT, STAGE::STAGE_JUPITER);
				return;
			}
		}
	}

	//�Ō�̗�̓G��S�ē|������
	if (m_pEnemyLaser->IsClear() && m_pEnemyPublic->IsClear() &&
		m_pEnemyBarrier->IsClear() && m_pEnemyMissile->IsClear() && m_pBossManagement->IsClear()) {
		if (m_GameclearHitstop) {
			m_StopFlame = HIT_STOP_TIME;
			m_GameclearHitstop = false;
			m_HitStopSlow = 0;
		}
		else {
			if (m_StopFlame <= 0) {
				//���U���g��ʂɍs��
				SetStageClear(true);
				Fade(SCENE::SCENE_RESULT, STAGE::STAGE_JUPITER);
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
	m_pEnemyPublic->Update();
	m_pEnemyBarrier->Update();
	m_pBossManagement->Update();
	m_pEnemyMissile->Update(m_pPlayer->GetPos());

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
void StageJupiter::Draw(void) const
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
	m_pStageJupitor->Draw();

	//�v���C���[�̕`�揈��
	if (m_pPlayerHP->IsDrawPlayer()) {
		m_pPlayer->Draw();
	}
	m_pPlayer->DrawBullet();
	if (m_pPlayerHP->IsDrawPlayer()) {
		m_pPlayerLeft->ArmDraw();
		m_pPlayerRight->ArmDraw();
		m_pPlayerCenter->ArmDraw();
	}

	//�G�̕`��
	m_pEnemyLaser->Draw();
	m_pEnemyPublic->Draw();
	m_pEnemyBarrier->Draw();
	m_pEnemyMissile->Draw();
	m_pBossManagement->Draw();

	m_pExplosionManagement->Draw();

	m_pItemManagement->Draw();

	//�{���̕`��
	m_pBom->BomDraw();
}
