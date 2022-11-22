#include "meteo.h"
//public
const float Meteo::SIZE_X = 100.0f;
const float Meteo::SIZE_Y = 120.0f;

//private
const float Meteo::SPEED_X = 1.5f;
const float Meteo::SPEED_Y = 2.5f;
const int Meteo::HP_MAX = 100;

void Meteo::Update(void)
{
		GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));

}
