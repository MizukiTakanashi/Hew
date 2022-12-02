//=============================================
// ステージ選択画面の惑星関係(cppファイル)
// 作成日：2022/11/30
// 作成者：高梨水希
//=============================================

#include "stage_select_planet.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// 引数付きコンストラクタ
//==========================
StageSelectPlanet::StageSelectPlanet(DrawObject& mars, DrawObject& mercury, DrawObject& jupiter, 
	DrawObject& venus, DrawObject& saturn, DrawObject& sun, bool sun_appearance) :m_sun_appearance(sun_appearance)
{
	//惑星のセット
	m_planets[(int)PLANET::MARS] = new StageSelectMars(mars);
	m_planets[(int)PLANET::MERCURY] = new StageSelectMercury(mercury);
	m_planets[(int)PLANET::JUPITER] = new StageSelectJupiter(jupiter);
	m_planets[(int)PLANET::VENUS] = new StageSelectVenus(venus);
	m_planets[(int)PLANET::SATURN] = new StageSelectSaturn(saturn);
	m_planets[(int)PLANET::SUN] = new StageSelectSun(sun);

	//太陽が来るのであれば...
	if (sun_appearance) {
		//太陽以外の惑星を小さくする
		for (int i = 0; i < (int)PLANET::SUN; i++) {
			m_planets[i]->SetSunSizeSmaller();
		}
		//太陽を大きくする(選択中)
		m_planets[(int)PLANET::SUN]->SetSizeBigger();

		//インデックス番号を太陽にセット
		m_planet_index = (int)PLANET::SUN;
		m_planet_index_before = (int)PLANET::SUN;

		//動く時間カウントをセット
		m_move_time = 0;
	}
	else {
		//最初の惑星を大きくする(選択中)
		m_planets[0]->SetSizeBigger();
	}
}

//==========================
// 更新処理
//==========================
void StageSelectPlanet::Update()
{
	//惑星が動いていれば...
	if (m_move_time++ >= 0) {
		for (int i = 0; i < (int)PLANET::NUM; i++) {
			m_planets[i]->MovePos(D3DXVECTOR2(m_move_speed, 0.0f));
		}
	}

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
		//前フレームのスティックが右に倒されてたら...(連続押しを拒否)
		if (m_thumb_before >= 0) {
			//左にずらす
			m_planet_index--;
		}
	}
	//左スティックで右に倒されたら...
	if (GetThumbLeftX(0) > 0) {
		//前フレームのスティックが左に倒されてたら...(連続押しを拒否)
		if (m_thumb_before <= 0) {
			//右にずらす
			m_planet_index++;
		}
	}
	//スティックの値を保存
	m_thumb_before = GetThumbLeftX(0);

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

	//サイズを更新する
	//前のインデックス番号から変更があれば...
	if (m_planet_index != m_planet_index_before) {

		//太陽があれば...
		if (m_sun_appearance) {
			//太陽が次のインデックス番号であれば...
			if (m_planet_index == (int)PLANET::SUN) {
				//現在のインデックス番号の惑星を大きくする
				m_planets[m_planet_index]->SetSizeBigger();
			}
			else {
				//現在のインデックス番号の惑星を大きくする
				m_planets[m_planet_index]->SetSunSizeBigger();
			}

			//太陽が前のインデックス番号であれば...
			if (m_planet_index_before == (int)PLANET::SUN) {
				//前のインデックス番号の惑星を小さくする
				m_planets[m_planet_index_before]->SetSizeSmaller();
			}
			else {
				//前のインデックス番号の惑星を小さくする
				m_planets[m_planet_index_before]->SetSunSizeSmaller();
			}
		}
		else {
			//現在のインデックス番号の惑星を大きくする
			m_planets[m_planet_index]->SetSizeBigger();

			//前のインデックス番号の惑星を小さくする
			m_planets[m_planet_index_before]->SetSizeSmaller();
		}
	}

	//現在の惑星インデックス番号を保存
	m_planet_index_before = m_planet_index;
}

//==========================
// 描画処理
//==========================
void StageSelectPlanet::Draw() const
{
	//太陽以外の描画
	for (int i = 0; i < (int)PLANET::SUN; i++) {
		m_planets[i]->Draw();
	}

	//太陽がもし出てたなら...
	if (m_sun_appearance) {
		//太陽を描画
		m_planets[(int)PLANET::SUN]->Draw();
	}
}