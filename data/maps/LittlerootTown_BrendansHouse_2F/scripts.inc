LittlerootTown_BrendansHouse_2F_EventScript_BlockBackroom::
	msgbox LittlerootTown_BackroomScary, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_DontEnterRoom
	waitmovement 0
	return


LittlerootTown_BrendansHouse_2F_DontEnterRoom:
	walk_down
	step_end

LittlerootTown_BrendansHouse_2F_EventScript_EmersonTalk::
	msgbox LittlerootTown_EmersonGetsStarter, MSGBOX_DEFAULT
	closemessage
	return


LittlerootTown_BrendansHouse_2F_EventScript_HopeTalk::
	msgbox LittlerootTown_HopeGetsStarter, MSGBOX_DEFAULT
	closemessage
	return


LittlerootTown_BrendansHouse_2F_EventScript_DontLeave::
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_DontLeave_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_GoUp
	waitmovement 0
	return


LittlerootTown_BrendansHouse_2F_GoUp:
	walk_up
	step_end

LittlerootTown_BrendansHouse_2F_EventScript_TTileLeft::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_PlayerViewFight
	goto LittlerootTown_BrendansHouse_2F_EventScript_HouseFight
	return


LittlerootTown_BrendansHouse_2F_EventScript_TTileBottom::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_PlayerViewFight2
	goto LittlerootTown_BrendansHouse_2F_EventScript_HouseFight
	return


LittlerootTown_BrendansHouse_2F_EventScript_TTileRight::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_PlayerViewFight3
	goto LittlerootTown_BrendansHouse_2F_EventScript_HouseFight
	return


LittlerootTown_BrendansHouse_2F_EventScript_HouseFight::
	applymovement LOCALID_NATASHA, LittlerootTown_BrendansHouse_2F_LeadersApproach
	applymovement LOCALID_MATTHEW, LittlerootTown_BrendansHouse_2F_LeadersApproach
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_HouseFight_Text_0
	closemessage
	msgbox LittlerootTown_BrendansHouse_2F_EventScript_HouseFight_Text_1
	closemessage
	giveitem ITEM_POKE_BALL, 20
	fadescreen FADE_TO_BLACK
	warp MAP_ROUTE116, 0, 10
	waitstate
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_STARTER_HOUSE_INTRO
	setflag FLAG_HIDE_LITTLEROOT_TOWN_STARTER_HOUSE_FIGHT
	setflag FLAG_HIDE_LITTLEROOT_TOWN_INTRO_CROWD
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	setvar VAR_NUM_WON_PINS, 0
	release
	return


LittlerootTown_BrendansHouse_2F_PlayerViewFight:
	walk_left
	face_left
	step_end

LittlerootTown_BrendansHouse_2F_PlayerViewFight2:
	walk_left
	walk_up
	face_left
	step_end

LittlerootTown_BrendansHouse_2F_PlayerViewFight3:
	walk_left
	walk_left
	face_left
	step_end

LittlerootTown_BrendansHouse_2F_EmersonViewFight:
	walk_left
	walk_up
	face_up
	step_end

LittlerootTown_BrendansHouse_2F_HopeViewFight:
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

LittlerootTown_BrendansHouse_2F_JaceRetreat:
	walk_down
	walk_down
	face_up
	step_end

LittlerootTown_BrendansHouse_2F_JaceMoveUp:
	walk_up
	face_down
	step_end

LittlerootTown_BrendansHouse_2F_SadieMovePast:
	walk_down
	walk_down
	walk_right
	face_down
	step_end

LittlerootTown_BrendansHouse_2F_SadieMovePast2:
	walk_down
	walk_down
	step_end

LittlerootTown_BrendansHouse_2F_FaceDown:
	face_down
	step_end

LittlerootTown_BrendansHouse_2F_EmersonBackUp:
	jump_right
	face_left
	step_end

LittlerootTown_BrendansHouse_2F_LeadersApproach:
	face_up
	walk_up
	step_end

.set LOCALID_EMERSON, 6
.set LOCALID_HOPE, 1
.set LOCALID_JACE, 2
.set LOCALID_SADIE, 3
.set LOCALID_NATASHA, 4
.set LOCALID_MATTHEW, 5

LittlerootTown_BrendansHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
	.byte 0

LittlerootTown_BrendansHouse_2F_OnTransition:
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos

	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos::
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_Ret
	goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos

LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_Ret
	@ Odd that the MaysHouse equivalent was used below instead
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
	setobjectxyperm LOCALID_JACE, 0, 2
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_2F_EventScript_Ret::
	return

LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
	return

LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan::
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	return

LittlerootTown_BrendansHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
	.2byte 0

LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SecretBase_EventScript_InitDecorations
	end

LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall::
	lockall
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan::
	delay 10
	addobject LOCALID_JACE
	applymovement LOCALID_JACE, LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_JACE, Common_Movement_Delay48
	waitmovement 0
	delay 10
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth::
	applymovement LOCALID_JACE, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth
	applymovement LOCALID_JACE, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth::
	applymovement LOCALID_JACE, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth
	applymovement LOCALID_JACE, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest::
	applymovement LOCALID_JACE, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest
	applymovement LOCALID_JACE, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast::
	applymovement LOCALID_JACE, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JACE, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth:
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest:
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest:
	delay_8
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast:
	walk_up
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

@ Unused, the player is already facing this direction so its unneeded
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_EventScript_PC::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC::
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Notebook::
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
	end

PlayersHouse_2F_EventScript_GameCube::
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
	end

PlayersHouse_2F_Text_ClockIsStopped:
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

PlayersHouse_2F_Text_HowDoYouLikeYourRoom:
	.string "MOM: {PLAYER}, how do you like your\n"
	.string "new room?\p"
	.string "Good! Everything's put away neatly!\p"
	.string "They finished moving everything in\n"
	.string "downstairs, too.\p"
	.string "POKéMON movers are so convenient!\p"
	.string "Oh, you should make sure that\n"
	.string "everything's all there on your desk.$"

PlayersHouse_2F_Text_Notebook:
	.string "{PLAYER} flipped open the notebook.\p"
	.string "ADVENTURE RULE NO. 1\n"
	.string "Open the MENU with START.\p"
	.string "ADVENTURE RULE NO. 2\n"
	.string "Record your progress with SAVE.\p"
	.string "The remaining pages are blank…$"

Common_Text_LookCloserAtMap:
	.string "{PLAYER} took a closer look at the\n"
	.string "HOENN region map.$"

PlayersHouse_2F_Text_ItsAGameCube:
	.string "It's a Nintendo GameCube.\p"
	.string "A Game Boy Advance is connected to\n"
	.string "serve as the Controller.$"

LittlerootTown_BrendansHouse_2F_EventScript_DontLeave_Text_0:
	.string "You still need to find your Pokémon...$"

LittlerootTown_BrendansHouse_2F_EventScript_HouseFight_Text_0:
	.string "MATTHEW: Are you ready?$"

LittlerootTown_BrendansHouse_2F_EventScript_HouseFight_Text_1:
	.string "NATASHA: Press Start to enter your\n"
	.string "menu. You can view your Pokemon and\l"
	.string "save your game there.\p"
	.string "NATASHA: Check in with nurses to heal\n"
	.string "your Pokemon.\p"
	.string "MATTHEW: And make sure to catch more\n"
	.string "Pokemon!\p"
	.string "NATASHA: We'll see you again soon!$"

LittlerootTown_BackroomScary::
	.string "Sounds of a fierce battle emanate from\n"
	.string "the back. It may be best not to go\l"
	.string "there yet...$"

LittlerootTown_EmersonGetsStarter::
	.string "EMERSON: Alright Poliwhirl, let's do\n"
	.string "this!\p"
	.string "We're going all the way to the top.$"

LittlerootTown_HopeGetsStarter::
	.string "HOPE: You can come out from under the\n"
	.string "table Ralts.\p"
	.string "I know it's scary, but I promise I'm not\n"
	.string "mean!$"

LittlerootTown_JaceConcedetoSadie::
	.string "JACE:$"
