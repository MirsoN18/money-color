/*******************************************************************************
* Filename:        money-color.inc
*
* Description:
*       This include changes the color of the player's money bar to the color you want.
*		You can define the color in your main script.
*
* Thanks:
*       SA:MP Team past, present and future.
*		Y_Less - YSI.
*		Danis (a.k.a. Slade) - Scripting contribution
*
********************************************************************************/

// | ----------------------- Includes ----------------------- |
#include <a_samp>

// | ----------------------- Defines ----------------------- |
#if !defined MONEY_BAR_COLOR
	#define MONEY_BAR_COLOR 0x007AEDFF 
#endif

#define MoneyControl::										MnyCTD_

// | ----------------------- Variables ----------------------- |
static PlayerText:playerMoney[MAX_PLAYERS] = {PlayerText:INVALID_TEXT_DRAW, ...};

// | ----------------------- Functions ----------------------- |
MoneyControl::Update(playerid)
{
		if(GetPlayerMoney(playerid) >= 0) 
		{
			if(playerMoney[playerid] == PlayerText:INVALID_TEXT_DRAW)
			{
				playerMoney[playerid] = CreatePlayerTextDraw(playerid, 498.999938, 77.617019, "$00000000");
				PlayerTextDrawLetterSize(playerid, playerMoney[playerid], 0.548624, 2.083333);
				PlayerTextDrawAlignment(playerid, playerMoney[playerid], 1);
				PlayerTextDrawColor(playerid, playerMoney[playerid], MONEY_BAR_COLOR);
				PlayerTextDrawSetShadow(playerid, playerMoney[playerid], 0);
				PlayerTextDrawSetOutline(playerid, playerMoney[playerid], 2);
				PlayerTextDrawBackgroundColor(playerid, playerMoney[playerid], 255);
				PlayerTextDrawFont(playerid, playerMoney[playerid], 3);
				PlayerTextDrawSetProportional(playerid, playerMoney[playerid], 1);
				PlayerTextDrawSetShadow(playerid, playerMoney[playerid], 0);
			}
			new moneyString[16];
			format(moneyString, sizeof(moneyString), "$%08d", GetPlayerMoney(playerid));
			PlayerTextDrawSetString(playerid, playerMoney[playerid], moneyString);
			PlayerTextDrawShow(playerid, playerMoney[playerid]);
		}
		else MoneyControl::Hide(playerid);
}

MoneyControl::Hide(playerid) {
	if(playerMoney[playerid] != PlayerText:INVALID_TEXT_DRAW) {
		PlayerTextDrawDestroy(playerid, playerMoney[playerid]);
		playerMoney[playerid] = PlayerText:INVALID_TEXT_DRAW;
	}
}

//-------------------------------------------------------------//

hook OnPlayerSpawn(playerid)
{
	MoneyControl::Update(playerid);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
	MoneyControl::Update(playerid);
	return 1;
}

hook OnPlayerUpdate(playerid)
{
	MoneyControl::Update(playerid);
	return 1;
}

