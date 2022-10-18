//=======================================
// 爆発関係(ヘッダファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================

#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

#include "GameObject.h"
#include "DrawObject.h"
#include "main.h"

class Explosion:public GameObject
{
private:
	//定数
	//ここで初期化
	static const int ANIME_MAX = 7;	//アニメーション数

	//cppで初期化
	static const float SIZE_X;		//サイズX
	static const float SIZE_Y;		//サイズY
	static const float ANIME_SPEED;	//アニメーションのスピード

private:
	//メンバ変数
	float m_AnimationNum = 0.0f;
	bool m_EndAnimation = false;

public:
	Explosion(){}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	Explosion(DrawObject& DrawObject, const D3DXVECTOR2& pos)
		:GameObject(DrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)){}

	~Explosion(){}

	//更新処理
	void Update(void);

	//アニメーションが終わったかフラグを返す
	bool GetEndAnimation(void)const { return m_EndAnimation; }
};

#endif // !_EXPLOSION_H_
