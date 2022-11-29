#pragma once
//=======================================
// ゲーム画面関係(ヘッダファイル)
// 作成日：2022/07/14
// 作成者：高梨水希
//=======================================

#ifndef _STAGE_SELECT_H_
#define _STAGE_SELECT_H_

#include "main.h"
#include "sprite.h"
#include "BG.h"
#include "draw_object.h"
#include "number.h"

class StageSelect
{
	//定数
private:
	//ここで初期化
	static const int NUMBER_DIGIT = 10;		//数字の桁

	//cppで初期化
	static const D3DXVECTOR2 NUMBER_SIZE;	//数字のサイズ
	static const D3DXVECTOR2 NUMBER_POS;	//数字の位置

	enum class TEXTURE_TYPE :int
	{
		PLAYER,
		PLAYER_HP,
		ENEMY,
		ENEMY_PUBLIC,
		ENEMY_ITEM,
		BULLET_CIRCLE_RED,
		BULLET_CIRCLE_GREEN,
		BULLET_SQUARE_GREEN,
		LASER,
		EXPLOSION,
		NUMBER,
		MULTIPLY,
		METEO,
		NUM
	};

	enum class DRAW_TYPE :int
	{
		PLAYER,
		PLAYER_HP_BAR,
		ENEMY_NOREMAL,
		ENEMY_LASER,
		ENEMY_GATORING,
		ENEMY_PUBLIC,
		ENEMY_METEO,
		ENEMY_ITEM,
		PLAYER_BULLET,
		BULLET_ENEMY,
		ENEMY_LASER_LASER,
		EXPLOSION,
		PLAYER_ARM_LEFT,
		PLAYER_ARM_LEFT_BULLET,
		PLAYER_ARM_LEFT_LASER,
		PLAYER_ARM_RIGHT,
		PLAYER_ARM_RIGHT_BULLET,
		PLAYER_ARM_RIGHT_LASER,
		PLAYER_ARM_CENTER,
		PLAYER_ARM_CENTTER_BULLET,
		PLAYER_ARM_CENTER_LASER,
		NUMBER,
		MULTIPLY,
		NUM
	};


	//メンバ変数
private:
	int m_BGM = 0;

	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;

	BG* m_pBG = nullptr;

	Number* m_pRemaining_Left = nullptr;
	Number* m_pRemaining_Right = nullptr;
	Number* m_pRemaining_Center = nullptr;

	UI* m_pMultiply = nullptr;
	Number* m_pComboNum = nullptr;

	//メンバ関数
public:
	StageSelect();	//デフォルトコンストラクタ

	~StageSelect() {}	//デストラクタ

	//更新
	void Update(void) {}

	//描画
	void Draw(void)const{}
};
#endif // !_STAGE_SELECT_H_