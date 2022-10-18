//=======================================
// �V�[���֌W(�w�b�_�t�@�C��)
// �쐬���F2022/07/14
// �쐬�ҁF��������
//=======================================

#ifndef _SCENE_H_
#define _SCENE_H_

//======================
// �}�N����`
//======================
typedef enum {
	SCENE_NONE,
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_RESULT,
	SCENE_NUM
}SCENE;

//======================
// �v���g�^�C�v�錾
//======================
void InitScene(SCENE s);
void InitScene2(SCENE s);
void UninitScene(void);
void UninitScene2(void);
void UpdateScene(void);
void DrawScene(void);

void SetScene(SCENE s);
void CheckScene(void);

#endif // !_SCENE_H_
