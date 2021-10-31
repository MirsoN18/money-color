/*******************************************************************************
* Filename:        money-color.inc
*
* Description:
*       This include changes the color of the player's money bar to the color you want.
*	You can define the color in your main script.
*
* Thanks:
*       SA:MP Team past, present and future - SA:MP.
*       Y_Less - YSI.
*/

// A_Samp include
#include <a_samp>

// Libraries
#include <YSI\y_hooks>

// Color of money bar
#if !defined MONEY_BAR_COLOR
	#define MONEY_BAR_COLOR 0x007AEDFF // blue
#endif

// Money bar textdraw
static PlayerText:playerMoney[MAX_PLAYERS];

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
	PlayerTextDrawShow(playerid, playerMoney[playerid]);
	return 1;
}

hook OnPlayerUpdate(playerid)
{
	new string[16];
	if(GetPlayerMoney(playerid) == 0)
	{
	    PlayerTextDrawShow(playerid, playerMoney[playerid]);
 		format(string, sizeof(string), "$0000000%d", GetPlayerMoney(playerid));
 		PlayerTextDrawSetString(playerid, playerMoney[playerid], string);
	}
	else if(GetPlayerMoney(playerid) > 0 && GetPlayerMoney(playerid) < 10)
	{
	    PlayerTextDrawShow(playerid, playerMoney[playerid]);
 		format(string, sizeof(string), "$0000000%d", GetPlayerMoney(playerid));
 		PlayerTextDrawSetString(playerid, playerMoney[playerid], string);
	}
	else if(GetPlayerMoney(playerid) >= 10 && GetPlayerMoney(playerid) < 100)
	{
	    PlayerTextDrawShow(playerid, playerMoney[playerid]);
 		format(string, sizeof(string), "$000000%d", GetPlayerMoney(playerid));
 		PlayerTextDrawSetString(playerid, playerMoney[playerid], string);
	}
	else if(GetPlayerMoney(playerid) >= 100 && GetPlayerMoney(playerid) < 1000)
	{
	    PlayerTextDrawShow(playerid, playerMoney[playerid]);
 		format(string, sizeof(string), "$00000%d", GetPlayerMoney(playerid));
 		PlayerTextDrawSetString(playerid, playerMoney[playerid], string);
	}
	else if(GetPlayerMoney(playerid) >= 1000 && GetPlayerMoney(playerid) < 10000)
	{
	    PlayerTextDrawShow(playerid, playerMoney[playerid]);
 		format(string, sizeof(string), "$0000%d", GetPlayerMoney(playerid));
 		PlayerTextDrawSetString(playerid, playerMoney[playerid], string);
	}
	else if(GetPlayerMoney(playerid) >= 10000 && GetPlayerMoney(playerid) < 100000)
	{
	    PlayerTextDrawShow(playerid, playerMoney[playerid]);
 		format(string, sizeof(string), "$000%d", GetPlayerMoney(playerid));
 		PlayerTextDrawSetString(playerid, playerMoney[playerid], string);
	}
	else if(GetPlayerMoney(playerid) >= 100000 && GetPlayerMoney(playerid) < 1000000)
	{
	    PlayerTextDrawShow(playerid, playerMoney[playerid]);
 		format(string, sizeof(string), "$00%d", GetPlayerMoney(playerid));
 		PlayerTextDrawSetString(playerid, playerMoney[playerid], string);
	}
	else if(GetPlayerMoney(playerid) >= 1000000 && GetPlayerMoney(playerid) < 10000000)
	{
	    PlayerTextDrawShow(playerid, playerMoney[playerid]);
 		format(string, sizeof(string), "$0%d", GetPlayerMoney(playerid));
 		PlayerTextDrawSetString(playerid, playerMoney[playerid], string);
	}
	else if(GetPlayerMoney(playerid) >= 10000000 && GetPlayerMoney(playerid) < 100000000)
	{
	    PlayerTextDrawShow(playerid, playerMoney[playerid]);
 		format(string, sizeof(string), "$%d", GetPlayerMoney(playerid));
 		PlayerTextDrawSetString(playerid, playerMoney[playerid], string);
	}
	else if(GetPlayerMoney(playerid) < 0 && GetPlayerMoney(playerid) > -100000000)
	{
 		PlayerTextDrawHide(playerid, playerMoney[playerid]);
	}
	return 1;
}
