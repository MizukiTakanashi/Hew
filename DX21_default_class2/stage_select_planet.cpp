//=============================================
// ステージ選択画面の惑星関係(cppファイル)
// 作成日：2022/11/30
// 作成者：高梨水希
//=============================================

#include "stage_select_planet.h"
#include "inputx.h"
#include "keyboard.h"
#include "sound.h"

//==========================
// 定数の初期化
//==========================
const float StageSelectPlanet::MOVE_SPEED = -1.0f;
const float StageSelectPlanet::SUN_MOVE_SPEED_Y = 0.6f;

//==========================
// デフォルトコンストラクタ
//==========================
StageSelectPlanet::StageSelectPlanet()
{
	for (int i = 0; i < (int)PLANET::NUM; i++) {
		m_planets[i] = nullptr;
	}

	for (int i = 0; i < (int)PLANET::NUM - 1; i++) {
		m_pWhiteLine[i] = nullptr;
	}
}

//==========================
// 引数付きコンストラクタ
//==========================
StageSelectPlanet::StageSelectPlanet(DrawObject& mars, DrawObject& mercury, DrawObject& jupiter, 
	DrawObject& venus, DrawObject& saturn, DrawObject& sun, DrawObject& white_line, 
	bool stage_clear[], bool sun_appearance) :m_sun_appearance(sun_appearance)
{
	//惑星のセット
	m_planets[(int)PLANET::MARS] = new StageSelectMars(mars);
	m_planets[(int)PLANET::MERCURY] = new StageSelectMercury(mercury);
	m_planets[(int)PLANET::JUPITER] = new StageSelectJupiter(jupiter);
	m_planets[(int)PLANET::VENUS] = new StageSelectVenus(venus);
	m_planets[(int)PLANET::SATURN] = new StageSelectSaturn(saturn);
	m_planets[(int)PLANET::SUN] = new StageSelectSun(sun);

	//惑星の色のセット(クリアしてなかったら黒目にする)
	for(int i = 0; i < STAGE_MOON; i++) {
		if (!stage_clear[i]) {
			//暗い色にする
			m_planets[i]->SetDarker();
		}
	}

	//白い線の初期化
	for (int i = 0; i < (int)PLANET::NUM - 1; i++) {
		m_pWhiteLine[i] = new GameObject(white_line, D3DXVECTOR2(SCREEN_WIDTH, 0.0f), D3DXVECTOR2(0.0f, 0.0f));
	}

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

	//白い線をセット
	for (int i = 0; i < (int)PLANET::NUM - 1; i++) {
		WhiteLineSet(m_planets[i]->GetPos(), i);
	}

	//=====================
	// 音

	//決定音
	m_SE_01 = LoadSound((char*)"data\\SE\\2_01.wav");
	//SetVolume(g_SE, 0.1f);

	//カーソル移動音
	m_SE_03 = LoadSound((char*)"data\\SE\\2_03.wav");
}

//==========================
// デストラクタ
//==========================
StageSelectPlanet::~StageSelectPlanet()
{
	for (int i = 0; i < (int)PLANET::NUM; i++) {
		delete m_planets[i];
	}

	for (int i = 0; i < (int)PLANET::NUM - 1; i++) {
		if (m_pWhiteLine[i] != nullptr) {
			delete m_pWhiteLine[i];
		}
	}
}

//==========================
// 更新処理
//==========================
void StageSelectPlanet::Update()
{
	//惑星が動く時間であれば...
	if (m_move_time >= 0) {
		//惑星を動かす
		for (int i = 0; i < (int)PLANET::NUM; i++) {
			if (i == (int)PLANET::SUN) {
				m_planets[i]->MovePos(D3DXVECTOR2(0.0f, StageSelectPlanet::SUN_MOVE_SPEED_Y));
			}
			m_planets[i]->MovePos(D3DXVECTOR2(StageSelectPlanet::MOVE_SPEED, 0.0f));
		}

		//白い線をセット
		for (int i = 0; i < (int)PLANET::NUM - 1; i++) {
			WhiteLineSet(m_planets[i]->GetPos(), i);
		}

		//惑星が止まる時間が来たら...
		if (m_move_time++ >= StageSelectPlanet::MOVE_TIME_LIMIT) {
			//カウントをストップ
			m_move_time = -1;
		}

		return;
	}

	//=======================
	// キーボード

	//Aキーを押したら...
	if (InputGetKeyDown(KK_A)) {
		//左にずらす
		m_planet_index++;
		PlaySound(m_SE_03, 0);
	}
	//Dキーを押したら...
	if (InputGetKeyDown(KK_D)) {
		//右にずらす
		m_planet_index--;
		PlaySound(m_SE_03, 0);
	}


	//=======================
	// パッド

	//十字キー左を押したら...
	if (IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_LEFT)) {
		//左にずらす
		m_planet_index++;
		PlaySound(m_SE_03, 0);
	}
	//十字キー右を押したら...
	if (IsButtonTriggered(0, XINPUT_GAMEPAD_DPAD_RIGHT)) {
		//右にずらす
		m_planet_index--;
		PlaySound(m_SE_03, 0);
	}

	//左スティックで左に倒されたら...
	if (GetThumbLeftX(0) < 0) {
		//前フレームのスティックが右に倒されてたら...(連続押しを拒否)
		if (m_thumb_before >= 0) {
			//左にずらす
			m_planet_index++;
			PlaySound(m_SE_03, 0);
		}
	}
	//左スティックで右に倒されたら...
	if (GetThumbLeftX(0) > 0) {
		//前フレームのスティックが左に倒されてたら...(連続押しを拒否)
		if (m_thumb_before <= 0) {
			//右にずらす
			m_planet_index--;
			PlaySound(m_SE_03, 0);
		}
	}
	//スティックの値を保存
	m_thumb_before = (int)GetThumbLeftX(0);

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

	//パッドのBボタンを押したら...
	if (IsButtonTriggered(0, XINPUT_GAMEPAD_B)) {
		PlaySound(m_SE_01, 0);
		Fade((SCENE)(SCENE::SCENE_MERCURY + m_planet_index), STAGE::STAGE_MERCURY);
	}
	//キーボードのEnterを押したら...
	else if (InputGetKeyDown(KK_ENTER)) {
		PlaySound(m_SE_01, 0);
		Fade((SCENE)(SCENE::SCENE_MERCURY + m_planet_index), STAGE::STAGE_MERCURY);
	}
}

//==========================
// 描画処理
//==========================
void StageSelectPlanet::Draw() const
{
	//白い線の描画
	for (int i = 0; i < (int)PLANET::SUN; i++) {
		m_pWhiteLine[i]->Draw();
	}

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

//==========================
// 白い線をセットする
//==========================
void StageSelectPlanet::WhiteLineSet(const D3DXVECTOR2& planet_pos, int type)
{
	//ベクトル確保
	D3DXVECTOR2 vec = m_pWhiteLine[type]->GetPos() - planet_pos;

	if (vec.x < 0) {
		vec.x *= -1;
	}
	if (vec.y < 0) {
		vec.y *= -1;
	}

	float length = D3DXVec2Length(&vec);

	m_pWhiteLine[type]->SetSize(D3DXVECTOR2(length * 2, length * 2));
}
