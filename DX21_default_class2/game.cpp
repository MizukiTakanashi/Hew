//=======================================
// �Q�[����ʊ֌W(cpp�t�@�C��)
// �쐬���F2022/07/14
// �쐬�ҁF��������
//=======================================
#include "game.h"
#include "input.h"
#include "scene.h"
#include "sound.h"

//==========================
// �萔������
//==========================
const D3DXVECTOR2 Game::NUMBER_POS = D3DXVECTOR2(350.0f, 30.0f);
const D3DXVECTOR2 Game::NUMBER_SIZE = D3DXVECTOR2(40.0f, 40.0f);

//==========================
// ����������
//==========================
Game::Game()
{
	m_BGM = LoadSound((char*)"data\\BGM\\opportunity (online-audio-converter.com).wav");	//�T�E���h�̃��[�h
	PlaySound(m_BGM, -1);	//BGM�Đ�

	m_pTexUseful = new TextureUseful[10];
	m_pDrawObject = new DrawObject[10];

	//�w�i�̏���������
	m_pBG = new BG((char*)"data\\texture\\game_BG.jpg");	

	//�e
	m_pTexUseful[2].SetTextureName((char*)"data\\texture\\bullet00.png");
	m_pDrawObject[2].SetDrawObject(m_pTexUseful[2]);

	//�v���C���[
	m_pTexUseful[0].SetTextureName((char*)"data\\texture\\player.png");
	m_pDrawObject[0].SetDrawObject(m_pTexUseful[0]);
	m_pPlayer = new Player(m_pDrawObject[0], m_pDrawObject[2]);

	//�G�̔z�u�ꏊ
	m_pEnemySetPos = new EnemySetPos;

	//���ʂ̓G
	m_pTexUseful[1].SetTextureName((char*)"data\\texture\\enemy.png");
	m_pDrawObject[1].SetDrawObject(m_pTexUseful[1]);

	m_pEnemyNormalManagement = new EnemyNormalManagement(m_pDrawObject[1], m_pDrawObject[2],
		*m_pEnemySetPos);

	//�v���C���[��HP
	m_pTexUseful[3].SetTextureName((char*)"data\\texture\\playerHP.png");
	m_pDrawObject[3].SetDrawObject(m_pTexUseful[3], 0.0f, 1.0f, 0.5f, 1);

	m_pDrawObject[4].SetDrawObject(m_pTexUseful[3], 1.0f, 1.0f, 0.5f, 1);
	m_pPlayerHP = new PlayerHP(m_pDrawObject[3], m_pDrawObject[4]);

	//����
	m_pTexUseful[4].SetTextureName((char*)"data\\texture\\explosion000.png");
	m_pDrawObject[5].SetDrawObject(m_pTexUseful[4], 0.0f, 0.125f, 1.0f, 7);
	m_pExplosionManagement = new ExplosionManagement(m_pDrawObject[5]);

	//�����̏�����
	m_pNumber->SetInitPos(NUMBER_POS);
	m_pNumber->SetPos(NUMBER_POS);
	m_pNumber->SetSize(NUMBER_SIZE);
	m_pNumber->SetDigit(NUMBER_DIGIT);

	//�v���C���[�ƕ��ʂ̓G�̓����蔻��
	m_pPlayerEnemyNormalCol = new PlayerEnemyNormalCollision(m_pPlayer, m_pEnemyNormalManagement, 
		m_pExplosionManagement, m_pNumber);
}

//=========================
// �����t���R���X�g���N�^
//=========================
Game::Game(Number * pNumber):m_pNumber(pNumber)
{
	m_BGM = LoadSound((char*)"data\\BGM\\opportunity (online-audio-converter.com).wav");	//�T�E���h�̃��[�h
	PlaySound(m_BGM, -1);	//BGM�Đ�

	m_pTexUseful = new TextureUseful[10];
	m_pDrawObject = new DrawObject[10];

	//�w�i�̏���������
	m_pBG = new BG((char*)"data\\texture\\game_BG.jpg");

	//�e
	m_pTexUseful[2].SetTextureName((char*)"data\\texture\\bullet00.png");
	m_pDrawObject[2].SetDrawObject(m_pTexUseful[2]);

	//�v���C���[
	m_pTexUseful[0].SetTextureName((char*)"data\\texture\\player.png");
	m_pDrawObject[0].SetDrawObject(m_pTexUseful[0]);
	m_pPlayer = new Player(m_pDrawObject[0], m_pDrawObject[2]);

	//�G�̔z�u�ꏊ
	m_pEnemySetPos = new EnemySetPos;

	//���ʂ̓G
	m_pTexUseful[1].SetTextureName((char*)"data\\texture\\enemy.png");
	m_pDrawObject[1].SetDrawObject(m_pTexUseful[1]);

	m_pEnemyNormalManagement = new EnemyNormalManagement(m_pDrawObject[1], m_pDrawObject[2],
		*m_pEnemySetPos);

	//�v���C���[��HP
	m_pTexUseful[3].SetTextureName((char*)"data\\texture\\playerHP.png");
	m_pDrawObject[3].SetDrawObject(m_pTexUseful[3], 0.0f, 1.0f, 0.5f, 1);

	m_pDrawObject[4].SetDrawObject(m_pTexUseful[3], 1.0f, 1.0f, 0.5f, 1);
	m_pPlayerHP = new PlayerHP(m_pDrawObject[3], m_pDrawObject[4]);

	//����
	m_pTexUseful[4].SetTextureName((char*)"data\\texture\\explosion000.png");
	m_pDrawObject[5].SetDrawObject(m_pTexUseful[4], 0.0f, 0.125f, 1.0f, 7);
	m_pExplosionManagement = new ExplosionManagement(m_pDrawObject[5]);

	//�����̏�����
	m_pNumber->SetInitPos(NUMBER_POS);
	m_pNumber->SetPos(NUMBER_POS);
	m_pNumber->SetSize(NUMBER_SIZE);
	m_pNumber->SetDigit(NUMBER_DIGIT);

	//�v���C���[�ƕ��ʂ̓G�̓����蔻��
	m_pPlayerEnemyNormalCol = new PlayerEnemyNormalCollision(m_pPlayer, m_pEnemyNormalManagement, 
		m_pExplosionManagement, m_pNumber);
}

//==========================
// �I������
//==========================
Game::~Game()
{
	//�`�悪�Ȃ�����������Ă���
	delete m_pEnemySetPos;

	//�Q�[���I�u�W�F�N�g������
	delete m_pExplosionManagement;
	delete m_pEnemyNormalManagement;
	delete m_pPlayerHP;
	delete m_pPlayer;
	delete m_pBG;

	//���̂ق�
	delete[] m_pDrawObject;
	delete[] m_pTexUseful;

	//BGM���X�g�b�v
	StopSound(m_BGM);
}

//======================
// �X�V����
//======================
void Game::Update(void)
{
	m_pBG->Update();

	m_pPlayer->Update();

	m_pExplosionManagement->Update();

	//���ʂ̓G�̍X�V����
	m_pEnemyNormalManagement->Update(m_pPlayer->GetPos());


	//====================================
	//�v���C���[��HP�ɑ΂���U���̏���
	int attack_num = 0;

	//���ʂ̓G
	attack_num += m_pPlayerEnemyNormalCol->Update();
	
	//�v���C���[��HP���U�����ɂ���Č��炷
	if (attack_num != 0) {
		m_pPlayerHP->ReduceHP((float)attack_num);
		m_pExplosionManagement->SetExplosion(m_pPlayer->GetPos());
	}


	//�v���C���[��HP��0�ɂȂ�����...
	if (m_pPlayerHP->GetHP0Flag()) {
		SetScene(SCENE::SCENE_RESULT);
	}
}

//==========================
// �`�揈��
//==========================
void Game::Draw(void)const
{
	m_pBG->DrawBG();
	m_pPlayer->Draw();
	m_pEnemyNormalManagement->Draw();

	m_pPlayer->DrawBullet();
	m_pExplosionManagement->Draw();

	//UI�̕`��
	m_pPlayerHP->DrawHP();
	m_pNumber->DrawNumber();
}
