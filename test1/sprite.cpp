//==========================================================
//
//   �X�v���C�g�`�� [sprite.cpp]
//									 Author :
//									 Date   :
//==========================================================
#include	"renderer.h"
#include	"sprite.h"

//==================================
//�}�N����`
//==================================
#define		NUM_VERTEX	(4)	//�X�v���C�g���_��

//==================================
//�v���g�^�C�v�錾
//sprite.cpp���Ŏg���֐��ɑ΂������
//==================================


//==================================
//�O���[�o���ϐ�
//==================================
static	ID3D11Buffer		*g_VertexBufferTriangle = NULL;	//���_�o�b�t�@

//=================================================
//�O�p�`�p���_�i�[����
//in �\�����WX, �\�����WY, ���T�C�Y, �c�T�C�Y, ��]�p�x, �F
//=================================================
void DrawSpriteColorRotation(float PosX, float PosY, int Size_W, int Size_H,
	float Kakudo, D3DXCOLOR col,
	static	float PaternNo, float uv_w, float uv_h, int NumPatern)
{
	D3D11_MAPPED_SUBRESOURCE msr;
	//���_�o�b�t�@�ւ̏������݋������炤
	GetDeviceContext()->Map(g_VertexBufferTriangle, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	//���_�\���̂̌^�Ƀ|�C���^�[�^��ϊ�������
	VERTEX_3D *vertex = (VERTEX_3D*)msr.pData;

	static	float offset = 0.0f;
	//���_ V0���Z�b�g
	vertex[0].Position = D3DXVECTOR3(-Size_W / 2, -Size_H / 2, 0.0f);
	vertex[0].Diffuse = col;
	vertex[0].TexCoord = D3DXVECTOR2(0.0f + offset, 0.0f);
	//���_ V1���Z�b�g
	vertex[1].Position = D3DXVECTOR3(+Size_W / 2, -Size_H / 2, 0.0f);
	vertex[1].Diffuse = col;
	vertex[1].TexCoord = D3DXVECTOR2(1.0f + offset, 0.0f);
	//���_ V2���Z�b�g
	vertex[2].Position = D3DXVECTOR3(-Size_W / 2, +Size_H / 2, 0.0f);
	vertex[2].Diffuse = col;
	vertex[2].TexCoord = D3DXVECTOR2(0.0f + offset, 1.0);
	//���_ V3���Z�b�g
	vertex[3].Position = D3DXVECTOR3(+Size_W / 2, +Size_H / 2, 0.0f);
	vertex[3].Diffuse = col;
	vertex[3].TexCoord = D3DXVECTOR2(1.0f + offset, 1.0f);
	//	offset += 1.0f / 60.0f;


	//UV���W�̌v�Z
	int no = PaternNo;	//�p�^�[���ԍ��𐮐��l�ɂ��� �����_�ȉ����̂Ă�
	float	u = (no % NumPatern) * uv_w;
	float	v = (no / NumPatern) * uv_h;

	//UV���W�̏�������
	vertex[0].TexCoord = D3DXVECTOR2(u, v);				//LEFT-TOP
	vertex[1].TexCoord = D3DXVECTOR2(u + uv_w, v);		//RIGHT-TOP
	vertex[2].TexCoord = D3DXVECTOR2(u, v + uv_h);		//LEFT-BOTTOM
	vertex[3].TexCoord = D3DXVECTOR2(u + uv_w, v + uv_h);	//RIGHT-BOTTOM


	//�x�����W�A���֕ϊ�����
	float	rad = D3DXToRadian(Kakudo);
	float	x, y;

	for (int i = 0; i < 4; i++)
	{
		//���@�藝		
		x = vertex[i].Position.x * cosf(rad) - vertex[i].Position.y * sinf(rad);
		y = vertex[i].Position.y * cosf(rad) + vertex[i].Position.x * sinf(rad);

		vertex[i].Position.x = x + PosX;	//���s�ړ��i���S�����炷�j
		vertex[i].Position.y = y + PosY;
	}

	GetDeviceContext()->Unmap(g_VertexBufferTriangle, 0);//�������ݏI��



	//�`��ݒ�
	{
		UINT stride = sizeof(VERTEX_3D);
		UINT offset = 0;
		GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBufferTriangle, &stride, &offset);
		// �v���~�e�B�u�g�|���W�ݒ�
		GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	}
	//�e�N�X�`���̐ݒ�


	// �|���S���`��
	GetDeviceContext()->Draw(NUM_VERTEX, 0);


}

//====================================
//�X�v���C�g������
//====================================
void	InitSprite()
{

	{// ���_�o�b�t�@����
		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DYNAMIC;
		bd.ByteWidth = sizeof(VERTEX_3D) * NUM_VERTEX;//���_1�����_���̃T�C�Y�ō��
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBufferTriangle);
	}

}

//====================================
//�X�v���C�g�I������
//====================================
void	UninitSprite()
{

	if (g_VertexBufferTriangle)
	{
		g_VertexBufferTriangle->Release();//�g���I������̂ŉ������
		g_VertexBufferTriangle = NULL;
	}

}

