//====================================================
// テキストの管理関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//====================================================
#pragma once


class TextManagement
{
//定数
public:
	const static float FLAME_SIZE_X; //フレームサイズ
	const static float FLAME_SIZE_Y; //フレームサイズ

private:

//メンバ変数
private:
	int m_TextNum = 0; //何回チュートリアルテキストを表示したか

//メンバ関数
public:
	//デフォルトコンストラクタ
	TextManagement();

	//引数付きコンストラクタ

	//デストラクタ

	
	//更新処理
	void Update(void);
	//描画処理
	void Draw(void);
};
