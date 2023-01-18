//=======================================
// Ž©‹@‚Ì^‚ñ’†(ƒwƒbƒ_)
// ì¬“úF
// ì¬ŽÒF‰¶“c—ms
//=======================================
#include "player_center.h"
#include "inputx.h"
#include "keyboard.h"

//==========================
// ’è”‚Ì‰Šú‰»
//==========================
const D3DXVECTOR2 PlayerCenter::FROM_PLAYER_POS = D3DXVECTOR2(0.0f, 30.0f);

void PlayerCenter::ArmDraw(void) const
{
	//˜r‚É‚È‚É‚©‚Â‚¢‚Ä‚¢‚ê‚Î•`‰æ
	if (m_type != TYPE::TYPE_NONE)
	{
		if (m_type != TYPE::TYPE_OLD) {
			//˜r‚É‚Â‚¢‚Ä‚¢‚éƒAƒCƒeƒ€Ž©g‚Ì•`‰æ
			//DrawReverse();
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
void PlayerCenter::ButtonPress(void)
{

}
