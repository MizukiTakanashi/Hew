//=======================================
// �����蔻��֌W(cpp�t�@�C��)
// �쐬���F2022/06/27
// �쐬�ҁF��������
//=======================================
#include "collision.h"

//=========================
// �l�p�`���m�̓����蔻��
//=========================
bool Collision::ColBox(const D3DXVECTOR2& pos1, const D3DXVECTOR2& pos2, 
	const D3DXVECTOR2& size1, const D3DXVECTOR2& size2)
{
	D3DXVECTOR2 min1, min2;	//�l�p�`�ŏ����W
	D3DXVECTOR2 max1, max2;	//�l�p�`�ő���W

	//�l�p�`1�A����̍��W
	min1 = pos1 - size1 / 2;
	//�l�p�`1�A�E���̍��W
	max1 = pos1 + size1 / 2;

	//�l�p�`2�A����̍��W
	min2 = pos2 - size2 / 2;
	//�l�p�`2�A�E���̍��W
	max2 = pos2 + size2 / 2;

	//�l�p�`1����ɂ��Ĕ�������
	if (max1.x < min2.x) return false;
	if (max1.y < min2.y) return false;
	if (min1.x > max2.x) return false;
	if (min1.y > max2.y) return false;

	return true;
}

//=========================
// �ۓ��m�̓����蔻��
//=========================
bool Collision::ColCircle(const D3DXVECTOR2& pos1, const D3DXVECTOR2& pos2, float rot1, float rot2)
{
	//���S���m�̃x�N�g��
	D3DXVECTOR2 distance = pos1 - pos2;

	//�x�N�g���̒��������
	float length;
	length = D3DXVec2LengthSq(&distance);	//���[�g���g��Ȃ�ver
	//length = D3DXVec2Length(&distance);	//���[�g���g��ver(���m�Ȓ���)

	//length�����̂܂܂̒l�̂��߁A���������悷��
	float size = (rot1 + rot2) * (rot1 + rot2);

	//�������~�Ɖ~�̒��S���W�̒�����
	//��̉~�̔��a�̒��������Z����Γ������Ă���
	if (length < size) return true;

	return false;
}
