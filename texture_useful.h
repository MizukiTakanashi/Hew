//=======================================
// テクスチャ(便利)関係(ヘッダファイル)
// 作成日：2022/09/11
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _TEXTURE_USEFUL_H_
#define _TEXTURE_USEFUL_H_

#include "texture.h"

class TextureUseful
{
private:
	char* m_tex_name = nullptr;
	int m_tex_index_num = 0;

public:
	TextureUseful(){}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	TextureUseful(char* tex_name) :m_tex_name(tex_name) { m_tex_index_num = LoadTexture(m_tex_name); }

	~TextureUseful(){}	//デストラクタ

	//テクスチャをセット
	void SetTextureName(char* tex_name) { 
		m_tex_name = tex_name; 
		m_tex_index_num = LoadTexture(m_tex_name);
	}

	//テクスチャの番号を返す
	int GetTexIndexNum(void)const { return m_tex_index_num; }
};

#endif // !_TEXTURE_USEFUL_H_
