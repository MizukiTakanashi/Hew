//=======================================
// Ž©‹@‚Ì¶(ƒwƒbƒ_)
// ì¬“úF2022/10/25
// ì¬ŽÒF¬¼ ˜@
//=======================================
#include "player_left.h"

//#include "input.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// ’è”‚Ì‰Šú‰»
//==========================
const D3DXVECTOR2 PlayerLeft::FROM_PLAYER_POS = D3DXVECTOR2(-40.0f, 0.0f);

void PlayerLeft::ArmDraw(void) const
{
	//˜r‚É‚È‚É‚©‚Â‚¢‚Ä‚¢‚ê‚Î•`‰æ
	if (m_type != TYPE::TYPE_NONE)
	{
		if (m_type != TYPE::TYPE_OLD) {
			//˜r‚É‚Â‚¢‚Ä‚¢‚éƒAƒCƒeƒ€Ž©g‚Ì•`‰æ
			DrawReverse();
			//Žc’e”‰¡‚Ì“GƒAƒCƒRƒ“•\Ž¦
			Draw(m_Remaining_Icon_Pos, ICON_SIZE);
		}

		if (m_pEnemyItem != nullptr) {
			//˜r‚É‚Â‚¢‚Ä‚¢‚éƒAƒCƒeƒ€‚Ì’e“™•`‰æ
			m_pEnemyItem->PlayerArmDraw();
			if (m_type != TYPE::TYPE_OLD)
			{
				m_pRemaining_Num->DrawNumber();
			}
		}

	}

}

//==========================
// ƒ{ƒ^ƒ“”»’è
//==========================
void PlayerLeft::ButtonPress(void)
{
	//Ø‚è—£‚µƒ{ƒ^ƒ“
	inhPlayerArmBoth::SetSeparationButton(InputGetKeyDown(KK_Z) || IsButtonTriggered(0, XINPUT_GAMEPAD_LEFT_SHOULDER));

	//’e”­ŽËƒ{ƒ^ƒ“(‰Ÿ‚µ‚Ä‚¢‚éŠÔ)
	inhPlayerArmBoth::SetBulletShotButton(InputGetKey(KK_SPACE) || (GetRightTrigger(0) > TRIGGER) || (GetLeftTrigger(0) > TRIGGER));

	//’e”­ŽËƒ{ƒ^ƒ“(‰Ÿ‚µ‚½Žž)
	inhPlayerArmBoth::SetBulletShotButtonTrigger(InputGetKeyDown(KK_SPACE) || GetRightTriggerTriggered(0, TRIGGER) || GetLeftTriggerTriggered(0, TRIGGER));
}
