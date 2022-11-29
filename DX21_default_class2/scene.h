//=======================================
// シーン関係(ヘッダファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================

#ifndef _SCENE_H_
#define _SCENE_H_

//======================
// マクロ定義
//======================
typedef enum {
	SCENE_NONE,
	SCENE_TITLE,
	SCENE_STAGE_SELECT,
	SCENE_GAME,
	SCENE_RESULT,
	SCENE_NUM
}SCENE;

typedef enum {
	STAGE_MOON,
	STAGE_MARS,
	STAGE_MERCURY,
	STAGE_JUPITER,
	STAGE_VENUS,
	STAGE_SATURN,
	STAGE_SUN,
	STAGE_NUM
}STAGE;

//======================
// プロトタイプ宣言
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
