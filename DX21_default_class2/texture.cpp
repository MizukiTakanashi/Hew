
//====================
//�e�N�X�`���Ǘ�
//====================

#include	"texture.h"

//=====================
//�}�N����`
//=====================
#define		MAX_TEXTURE_NUM		(100)	//�e�N�X�`�������[�h�ł��閇��

//=====================
//�O���[�o���ϐ�
//=====================
//���[�h�����e�N�X�`���̏��z��
static	ID3D11ShaderResourceView*	g_pTexture[MAX_TEXTURE_NUM];

//���[�h�����e�N�X�`���̖�����\��
static	UINT	g_TextureIndex = 0;

//���[�h�����e�N�X�`���t�@�C�����̃o�b�t�@
static	char	g_TextureName[MAX_TEXTURE_NUM][256];

//=====================
//�v���g�^�C�v�錾
//=====================


//======================================
//�e�N�X�`���̃��[�h
//in	�t�@�C����
//out	�e�N�X�`���C���f�b�N�X
//======================================
int		LoadTexture(char* filename)
{
	//���łɓǂݍ��܂ꂽ�e�N�X�`�����𒲂ׂē�����
	//�e�N�X�`����������ꍇ�́A���̔ԍ���Ԃ��B
	for (int i = 0; i < g_TextureIndex; i++)
	{
		//�e�N�X�`�����̔�r
		if (strcmp(g_TextureName[i], filename) == 0 )
		//if (strcmp(&g_TextureName[i][0], filename))
		{
			return	i;
		}
	}
	//�ǂݍ��ݍő吔�𒴂��Ă�����G���[
	if (g_TextureIndex == MAX_TEXTURE_NUM)
	{
		return	-1;	//�G���[�l�Ƃ��ă}�C�i�X�l��Ԃ�
	}

	//�e�N�X�`���̃��[�h
	HRESULT		hr = D3DX11CreateShaderResourceViewFromFile(
					GetDevice(),
					filename,
					NULL,
					NULL,
					&g_pTexture[g_TextureIndex],
					NULL);
	if (hr != S_OK)
	{
		return	-1;	//�G���[�l�Ƃ��ă}�C�i�X�l��Ԃ�
	}

	//�e�N�X�`�����̓o�^
	strcpy_s(g_TextureName[g_TextureIndex], 256, filename);
//	strcpy_s(&g_TextureName[g_TextureIndex][0], 256, filename);

	int		retIndex = g_TextureIndex;	//���݂̐���ۑ�

	g_TextureIndex++;					//�ǂݍ��ݐ����C���N�������g

	return	retIndex;					//�ǂݍ��񂾃e�N�X�`���̔ԍ���Ԃ�
}
//=====================================
//�e�N�X�`���̉��
//=====================================
void	UninitTexture()
{
	//�ǂݍ��񂾑S�Ẵe�N�X�`�����������
	for (int i = 0; i < g_TextureIndex; i++)
	{
		if (g_pTexture[i] != NULL)//�|�C���^�������Ă��邩�H
		{
			g_pTexture[i]->Release();	//�e�N�X�`�����������
			g_pTexture[i] = NULL;		//�|�C���^������������
		}
	}

}
//=====================================
//�e�N�X�`���̎擾
//in	�e�N�X�`���C���f�b�N�X
//out	�e�N�X�`�����̂���|�C���^
//=====================================
ID3D11ShaderResourceView**	GetTexture(int index)
{
	//�s���l�̃`�F�b�N
	if (index < 0)				//0�����̎�
	{
		return	NULL;
	}
	if(index >= g_TextureIndex)	//�ǂݍ��ݐ��I�[�o�[
	{ 
		return	NULL;
	}

	return	&g_pTexture[index];//index���\���z��̃|�C���^

}