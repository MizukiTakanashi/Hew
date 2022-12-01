//=============================================
// ステージ選択画面の惑星関係(cppファイル)
// 作成日：2022/11/30
// 作成者：高梨水希
//=============================================

#include "stage_select_planet.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// 更新処理
//==========================
void StageSelectPlanet::Update()
{
	//=======================
	// キーボード

	//Aキーを押したら...
	if (InputGetKeyDown(KK_A)) {
		//左にずらす
		m_planet_index--;
	}
	//Dキーを押したら...
	if (InputGetKeyDown(KK_D)) {
		//右にずらす
		m_planet_index++;
	}


	//=======================
	// パッド

	//十字キー左を押したら...
	if (IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_LEFT)) {
		//左にずらす
		m_planet_index--;
	}
	//十字キー右を押したら...
	if (IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_RIGHT)) {
		//右にずらす
		m_planet_index++;
	}

	//左スティックで左に倒されたら...
	if (GetThumbLeftX(0) < 0) {
		//左にずらす
		m_planet_index--;
	}
	//左スティックで右に倒されたら...
	if (GetThumbLeftX(0) > 0) {
		//右にずらす
		m_planet_index++;
	}

	//太陽がなかったら...
	if (!m_sun_appearance) {
		//右端に行ったら...
		if (m_planet_index == (int)PLANET::SUN) {
			//左端に戻す
			m_planet_index = 0;
		}
		//左端に行ったら...
		if (m_planet_index == -1) {
			//右端に戻す
			m_planet_index = (int)PLANET::SUN - 1;
		}
	}
	//太陽があったら...
	else {
		//右端に行ったら...
		if (m_planet_index == (int)PLANET::NUM) {
			//左端に戻す
			m_planet_index = 0;
		}
		//左端に行ったら...
		if (m_planet_index == -1) {
			//右端に戻す
			m_planet_index = (int)PLANET::NUM - 1;
		}
	}

	//
}

//==========================
// 描画処理
//==========================
void StageSelectPlanet::Draw() const
{
	//火星
	m_mars->Draw();

	//水星
	m_mercury->Draw();

	//木星
	m_jupiter->Draw();

	//金星
	m_venus->Draw();

	//土星
	m_saturn->Draw();

	if (m_sun_appearance) {
		//太陽
		m_sun->Draw();
	}
}