#include "meteo.h"
//public
const float Meteo::SIZE_X = 50.0f;
const float Meteo::SIZE_Y = 60.0f;

//private
const float Meteo::SPEED_X = 1.5f;
const float Meteo::SPEED_Y = 2.5f;
void Meteo::Update(void)
{
		GameObject::MovePos(D3DXVECTOR2(0.0f, SPEED_Y));

}
