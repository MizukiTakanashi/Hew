//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================

//==============================================
//�C���N���[�h
//==============================================
#include "collision.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "explosion.h"

//==============================================
// �}�N����`
//==============================================


//==============================================
// �v���g�^�C�v�錾
//==============================================
bool CollisionBB(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2,
				 D3DXVECTOR2 size1, D3DXVECTOR2 size2);

bool CollisionBC(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2,
				 float size1, float size2);


//==============================================
// �O���[�o���ϐ�
//==============================================


//==============================================
// ����������
//==============================================


//==============================================
// �I������
//==============================================


//==============================================
// �X�V����
//==============================================
void UpdateCollision(void)
{
	//�v���C���[�@�΁@�G�L����
	PLAYER* player = GetPlayer();		//�v���C���[�\���̂̃|�C���^�擾
	ENEMY* enemy = GetEnemy();			//�G�l�~�[�\���̂̃|�C���^�擾
	BULLET* bullet = GetBullet();		//�o���b�g�\���̂̃|�C���^�擾

	//�v���C���[�ƃG�l�~�[�̓����蔻��
	for (int j = 0; j < PLAYER_MAX; j++)
	{
		if (player[j].isUse)
		{
			for (int i = 0; i < ENEMY_MAX; i++)
			{
				if (enemy[i].isUse  && enemy[i].FrameWait == 0)
				{
					//�����蔻����s��
					bool hit = CollisionBB(player[j].Position, enemy[i].Position,
										   player[j].Size, enemy[i].Size);
					if (hit)	//�������Ă��邩�H
					{//�������Ă���
						player[j].HP--;	//HP����
						player[j].DamageWait = 60 * 0.5f;	//0.5�b�Ԃ��炢

					}
					else
					{//�������Ă��Ȃ�

					}
				}
			}
		}
	}

	//�G�l�~�[�ƃo���b�g�̓����蔻��
	for (int j = 0; j < BULLET_MAX; j++)
	{
		if (bullet[j].isUse)
		{
			for (int i = 0; i < ENEMY_MAX; i++)
			{
				if (enemy[i].isUse && enemy[i].FrameWait == 0)
				{
					//�����蔻����s��
					bool hit = CollisionBB(bullet[j].Position, enemy[i].Position,
						bullet[j].Size, enemy[i].Size);
					if (hit)	//�������Ă��邩�H
					{//�������Ă���
						bullet[j].isUse = false;
						enemy[i].isUse = false;
						SetExplosion(enemy[i].Position, 0.1f);
					}
					else
					{//�������Ă��Ȃ�

					}
				}
			}
		}
	}




	//�v���C���[�@�΁@�G�e
	//�v���C���[�e�@�΁@�G�L����
	//�ȂǕK�v�ȏ����������֑S�č��

}


//==============================================
// �`�揈��
//==============================================


//==============================================
//�l�p�`�Ǝl�p�`�̓����蔻�菈��
//in  ���S���W�P�C���S���W�Q�A�@�T�C�Y�P�A�@�T�C�Y�Q
//out true:�Փ˂��Ă��� false:�Փ˂��Ă��Ȃ�
//==============================================
bool CollisionBB(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2,
				 D3DXVECTOR2 size1, D3DXVECTOR2 size2)
{
	D3DXVECTOR2 min1, min2;		//�l�p�`�ŏ����W
	D3DXVECTOR2 max1, max2;		//�l�p�`�ő���W

	min1.x = pos1.x - size1.x / 2;	//�l�p�`�P�@����
	min1.y = pos1.y - size1.y / 2;

	max1.x = pos1.x + size1.x / 2;	//�l�p�`�P�@�E��
	max1.y = pos1.y + size1.y / 2;

	min2.x = pos2.x - size2.x / 2;	//�l�p�`�Q�@����
	min2.y = pos2.y - size2.y / 2;

	max2.x = pos2.x + size2.x / 2;	//�l�p�`�Q�@�E��
	max2.y = pos2.y + size2.y / 2;


	//�Փ˂̔���
	if (max1.x < min2.x) return false;	//����P
	if (max1.y < min2.y) return false;	//����Q

	if (max2.x < min1.x) return false;	//����R
	if (max2.y < min1.y) return false;	//����S


	//�Փ˂��Ă���
	return true;

}

//==============================================
//�~�Ɖ~�̓����蔻�菈��
//in  ���S���W�P�C���S���W�Q�A�@���a�P�A�@���a�Q
//out true:�Փ˂��Ă��� false:�Փ˂��Ă��Ȃ�
//==============================================
bool CollisionBC(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2,
				 float size1, float size2)
{
	//���S���m�̃x�N�g��
	D3DXVECTOR2 vDistance = pos1 - pos2;
	//�x�N�g���̒��������
	float Length;
	Length = D3DXVec2LengthSq(&vDistance);	//���[�g���g��Ȃ���
	//Length = D3DXVec2Length(&vDistance);	//���[�g���g����(���m�Ȓ���)

	//���a�̑��a
	float size = (size1 + size2) * (size1 * size2);	//���[�g�g��Ȃ�2���
	//float size = (size1 + size2);	//���[�g�g����

	//Lenght��size���Z����ΏՓ˂��Ă���
	if (Length < size)
	{
		return true;	//�Փ˂��Ă���
	}

	return false;		//�Փ˂��Ă��Ȃ�
}

