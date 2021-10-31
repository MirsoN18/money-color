/*******************************************************************************
* Filename:        money-color.inc
*
* Description:
*       This include changes the color of the player's money bar to the color you want.
*	You can define the color in your main script.
*
* Thanks:
*       SA:MP Team past, present and future - SA:MP.
*	Y_Less - YSI.
*/

// A_Samp include
#include <a_samp>

// Libraries
#include <YSI\y_hooks>

// Color of money bar
#if !defined MONEY_BAR_COLOR
	#define MONEY_BAR_COLOR 0x007AEDFF // blue
#endif

// Variables
static PlayerText:playerMoney[MAX_PLAYERS];
static bool:moneyShowed[MAX_PLAYERS];

// Callbacks

hook OnPlayerConnect(playerid)
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
	return 1;
}

hook OnPlayerSpawn(playerid)
{
	if(!moneyShowed || GetPlayerMoney(playerid) >= 0)
	{
		PlayerTextDrawShow(playerid, playerMoney[playerid]);
		moneyShowed = true;
	}
	return 1;
}

hook OnPlayerUpdate(playerid)
{
	new moneyString[16];
	if(GetPlayerMoney(playerid) >= 0)
	{
		PlayerTextDrawShow(playerid, playerMoney[playerid]);
 		format(moneyString, sizeof(moneyString), "$%08d", GetPlayerMoney(playerid));
 		PlayerTextDrawSetString(playerid, playerMoney[playerid], moneyString);
		moneyShowed = true;
	}
	else if(GetPlayerMoney(playerid) < 0 && GetPlayerMoney(playerid) > -100000000)
	{
 		PlayerTextDrawHide(playerid, playerMoney[playerid]);
		moneyShowed = hide;
	}
	return 1;
}
