//====================================================
// テキストの管理関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//====================================================
#pragma once
#include "draw_object.h"

class TextManagement
{
//定数
private:
	//cppで初期化
	const static float FLAME_SIZE_X; //フレームサイズ
	const static float FLAME_SIZE_Y; //フレームサイズ
	const static float FLAME_POS_X;
	const static float FLAME_POS_Y;

	const static float TEXT_SIZE_X; //フレームサイズ
	const static float TEXT_SIZE_Y; //フレームサイズ
	const static float TEXT_BET_X; 
	const static float TEXT_BET_Y; 
	const static float TEXT_POS_X;
	const static float TEXT_POS_Y;

	//ここで初期化
	const static int TEXT_NUM_X = 40;


//メンバ変数
private:
	int m_FlameCount = 0;
	int m_TextCount = 0;	//何回チュートリアルテキストを表示したか
	int m_PaternNum = 0;
	int m_PaternMax = 0;
	bool m_RunText = false; //テキストが進んでいる途中か
	DrawObject m_TextFrame;
	DrawObject m_Text;
	DrawObject m_Triangle;

	int m_SE_01 = 0;		//テキストを送る時の音

	//ひとつ前のテキストが閉じてからの時間
	int m_TexTime[5] = {
		60 * 1,
		60 * 10,
		60 * 20,
		60 * 25,
		60 * 15
	};

//メンバ関数
public:
	//デフォルトコンストラクタ
	TextManagement();

	//デストラクタ
	~TextManagement(){}
	
	//更新処理
	void Update(void);

	//描画処理
	void Draw(void);

	void SetText(void);
	void EndText(void);
};
