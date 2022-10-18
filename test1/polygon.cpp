//==============================================
//
//	[.cpp]
//	Author	:
//	Date	:
//==============================================

//==============================================
//�C���N���[�h
//==============================================
#include "polygon.h"


//==============================================
// �}�N����`
//==============================================
#define NUM_VERTEX_LINESTRIP (64)	//���C���X�g���b�v���_�ő吔

//==============================================
// �v���g�^�C�v�錾
//==============================================
void	SetVertexLineStrip(int);							//���C���X�g���b�v���_�i�[����
void	SetVertexLine(float, float, float, float);			//�����p���_�i�[����
void	SetVertexCircle(float, float, float, int, D3DXCOLOR);	//���p�`�̕\��


//==============================================
// �O���[�o���ϐ�
//==============================================
static	ID3D11Buffer		*g_VertexBufferLineStrip = NULL;//���C���X�g���b�v�p
//static	ID3D11Buffer		*g_VertexBufferTriangle = NULL;	//�l�p�`�p
static	ID3D11Buffer		*g_VertexBufferLine = NULL;		//�����p

static	ID3D11Buffer		*g_VertexBufferCircle = NULL;	//���p�`�p

float	PositionX = SCREEN_WIDTH / 2;//��ʒ������W
float	PositionY = SCREEN_HEIGHT / 2;

//float	Kakudo = 0; //�l�p�`�̉�]�p�x

float	StartPositionX = 0;				//�����̃X�^�[�g���Wz
float	StartPositionY = 0;
float	EndPositionX = SCREEN_WIDTH;	//�����̏I�����W
float	EndPositionY = SCREEN_HEIGHT;


D3DXVECTOR3		Goal = D3DXVECTOR3(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 0);//��ʒ���
D3DXVECTOR3		Speed;
D3DXVECTOR3		Start;




//==============================================
// ����������
//==============================================
HRESULT InitPolygon(void)
{
	//�����̏�����
	srand(timeGetTime());
	//�|���S���̕\�����W�������_���Ɍ���
	//PositionX = rand() % SCREEN_WIDTH;
	//PositionY = rand() % SCREEN_HEIGHT;

	Start.x = PositionX;
	Start.y = PositionY;
	Start.z = 0.0f;

	//�ړI�n�܂ł̃x�N�g�������
	Speed = Goal - Start;
	//���K�����Ē�����1�ɂ���
	D3DXVec3Normalize(&Speed, &Speed);
	//�x�N�g����C�ӂ̒����ɂ���
	Speed *= 1.5f;



	// ���_�o�b�t�@����
	{
		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DYNAMIC;
		bd.ByteWidth = sizeof(VERTEX_3D) * NUM_VERTEX_LINESTRIP;//���_1�����_���̃T�C�Y�ō��
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBufferLineStrip);
		// ���_�o�b�t�@�X�V
		SetVertexLineStrip(4);
	}

	//�����p
	{
		// ���_�o�b�t�@����
		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DYNAMIC;
		bd.ByteWidth = sizeof(VERTEX_3D) * 2;			//���_1�����_���̃T�C�Y�ō��
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBufferLine);
		//�����p���_�i�[����
		SetVertexLine(StartPositionX, StartPositionY, EndPositionX, EndPositionY );
	}

	//���p�`�p
	{
		// ���_�o�b�t�@����
		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DYNAMIC;
		bd.ByteWidth = sizeof(VERTEX_3D) * 64;	//���_1�����_���̃T�C�Y�ō��
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBufferCircle);

		//���p�`�p���_�i�[����
		D3DXCOLOR	col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		SetVertexCircle(300.0f, 500.0f, 100.0f, 32, col);

	}



	return S_OK;
}

//==============================================
// �I������
//==============================================
void UninitPolygon(void)
{
	// ���_�o�b�t�@�̉��
	if (g_VertexBufferLineStrip)
	{
		g_VertexBufferLineStrip->Release();//�g���I������̂ŉ������
		g_VertexBufferLineStrip = NULL;
	}

	if (g_VertexBufferLine)
	{
		g_VertexBufferLine->Release();//�g���I������̂ŉ������
		g_VertexBufferLine = NULL;
	}

	if (g_VertexBufferCircle)
	{
		g_VertexBufferCircle->Release();//�g���I������̂ŉ������
		g_VertexBufferCircle = NULL;
	}


}

//==============================================
// �X�V����
//==============================================
void UpdatePolygon(void)
{

	Start += Speed;	//�ړ�����
	//PositionX = Start.x;
	//PositionY = Start.y;


}

//==============================================
// �`�揈��
//==============================================
void DrawPolygon(void)
{

	// �Q�c�\�������邽�߂̃}�g���N�X��ݒ�
	SetWorldViewProjection2D();


}


//==============================================
// ���_�f�[�^�ݒ�
//in
//  ���_�̐�
//==============================================
void SetVertexLineStrip(int	NumVertex)
{
	D3D11_MAPPED_SUBRESOURCE msr;
	//���_�o�b�t�@�ւ̏������݋������炤
	GetDeviceContext()->Map(g_VertexBufferLineStrip, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

	VERTEX_3D *vertex = (VERTEX_3D*)msr.pData;

	//��{�ڂ̒����̒��_���Z�b�g
	vertex[0].Position = D3DXVECTOR3(100.0f, 100.0f, 0.0f);
	vertex[0].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(SCREEN_WIDTH-100.0f, SCREEN_HEIGHT-100.0f, 0.0f);
	vertex[1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	//��{�ڂ̒����̒��_���Z�b�g
	vertex[2].Position = D3DXVECTOR3(SCREEN_WIDTH / 2, 0.0f + 50.0f, 0.0f);
	vertex[2].Diffuse = D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 50.0f, 0.0f);
	vertex[3].Diffuse = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);


	GetDeviceContext()->Unmap(g_VertexBufferLineStrip, 0);
}


//==============================================
//�����̒��_���i�[
//in
//  �J�n���WX, �J�n���WY, �I�����WX, �I�����WY
//==============================================
void	SetVertexLine(float StartX, float StartY, float EndX, float EndY)
{
	D3D11_MAPPED_SUBRESOURCE msr;
	//���_�o�b�t�@�ւ̏������݋������炤
	GetDeviceContext()->Map(g_VertexBufferLine, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	//���_�\���̂̌^�Ƀ|�C���^�[�^��ϊ�������
	VERTEX_3D *vertex = (VERTEX_3D*)msr.pData;

	//���_ V0���Z�b�g
	vertex[0].Position = D3DXVECTOR3(StartX, StartY, 0.0f);
	vertex[0].Diffuse = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
	//���_ V1���Z�b�g
	vertex[1].Position = D3DXVECTOR3(EndX, EndY, 0.0f);
	vertex[1].Diffuse = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	GetDeviceContext()->Unmap(g_VertexBufferLine, 0);//�������ݏI��

}

//==============================================
//���C���ő��p�`�̕\��
//in
//�@�\�����WX, �\�����WY, ���a, ���_��, �p�x, �F
//==============================================
void	SetVertexCircle(float PosX, float PosY, float Rad, int NumVertex, D3DXCOLOR col)
{

	D3D11_MAPPED_SUBRESOURCE msr;
	//���_�o�b�t�@�ւ̏������݋������炤
	GetDeviceContext()->Map(g_VertexBufferCircle, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	//���_�\���̂̌^�Ƀ|�C���^�[�^��ϊ�������
	VERTEX_3D *vertex = (VERTEX_3D*)msr.pData;

	float	kakudo = 0;
	for (int i = 0; i < NumVertex; i++)
	{
		vertex[i].Position.x = cosf(D3DXToRadian(kakudo)) * Rad + PosX;
		vertex[i].Position.y = sinf(D3DXToRadian(kakudo)) * Rad + PosY;
		vertex[i].Position.z = 0.0f;
		vertex[i].Diffuse = col;
		vertex[i].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
		kakudo += (360.0f / NumVertex);
	}
	//�Ō�̒��_�ɍŏ��̒��_���R�s�[���Đ}�`�����
	vertex[NumVertex].Position = vertex[0].Position;
	vertex[NumVertex].Diffuse = vertex[0].Diffuse;
	vertex[NumVertex].TexCoord = vertex[0].TexCoord;

	GetDeviceContext()->Unmap(g_VertexBufferCircle, 0);//�������ݏI��



}

