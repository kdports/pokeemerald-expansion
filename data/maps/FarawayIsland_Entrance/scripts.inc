FarawayIsland_Historian1::
	faceplayer
	msgbox FarawayIsland_Historian1_Text_0
	closemessage
	return


FarawayIsland_Historian2::
	faceplayer
	msgbox FarawayIsland_Historian2_Text_0
	closemessage
	return


FarawayIsland_LevelCapManTalk::
	msgbox FarawayIsland_LevelCapManTalk_Text_0
	giveitem ITEM_RARE_CANDY, 99
	closemessage
	return


FarawayIsland_NickBattle::
	faceplayer
	lockall
	msgbox FarawayIsland_NickBattle_Text_0
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, FarawayIsland_NickBattle_3
	case 0, FarawayIsland_NickBattle_4
FarawayIsland_NickBattle_1:
	msgbox FarawayIsland_NickBattle_Text_1
	multichoicedefault 20, 8, MULTI_EASYHARD, 1, FALSE
	switch VAR_RESULT
	case 1, FarawayIsland_NickBattle_7
	case 0, FarawayIsland_NickBattle_8
FarawayIsland_NickBattle_5:
	closemessage
	releaseall
	return

FarawayIsland_NickBattle_3:
	call FarawayIsland_NickNo
	goto FarawayIsland_NickBattle_1

FarawayIsland_NickBattle_4:
	call FarawayIsland_NickYes
	goto FarawayIsland_NickBattle_1

FarawayIsland_NickBattle_7:
	call FarawayIsland_NickHardFight
	goto FarawayIsland_NickBattle_5

FarawayIsland_NickBattle_8:
	call FarawayIsland_NickEasyFight
	goto FarawayIsland_NickBattle_5


FarawayIsland_NickYes::
	msgbox FarawayIsland_NickYes_Text_0
	giveitem ITEM_TM11
	closemessage
	return


FarawayIsland_NickNo::
	msgbox FarawayIsland_NickNo_Text_0
	giveitem ITEM_TM37
	closemessage
	return


FarawayIsland_NickEasyFight::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route116_LeaderBattleIntro, FarawayIsland_BossDefeated, FarawayIsland_EndBossFight, NO_MUSIC
	release
	return


FarawayIsland_NickHardFight::
	trainerbattle_double TRAINER_GRUNT_WEATHER_INST_2, Route116_LeaderBattleIntro, FarawayIsland_BossDefeated, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, FarawayIsland_EndBossFight, NO_MUSIC
	release
	return


FarawayIsland_EndBossFight::
	msgbox FarawayIsland_EndBossFight_Text_0
	giveitem ITEM_POKE_BALL, 15
	fadescreen FADE_TO_BLACK
	warp MAP_ABANDONED_SHIP_DECK, 13, 15
	waitstate
	fadescreen FADE_FROM_BLACK
	return


.set LOCALID_SAILOR, 1
.set LOCALID_SS_TIDAL, 2

FarawayIsland_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Entrance_OnTransition
	.byte 0

FarawayIsland_Entrance_OnTransition:
	setflag FLAG_ARRIVED_ON_FARAWAY_ISLAND
	end

FarawayIsland_Entrance_EventScript_SetCloudsWeather::
	setweather WEATHER_RAIN
	doweather
	end

FarawayIsland_Entrance_EventScript_ClearWeather::
	setweather WEATHER_NONE
	doweather
	end

FarawayIsland_Entrance_EventScript_Sailor::
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FarawayIsland_Entrance_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SAILOR, MAP_FARAWAY_ISLAND_ENTRANCE
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

FarawayIsland_Entrance_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

FarawayIsland_Entrance_EventScript_Sign::
	msgbox FarawayIsland_Entrance_Text_Sign, MSGBOX_SIGN
	end

FarawayIsland_Historian1_Text_0:
	.string "HISTORIAN: Many years ago, bandits\n"
	.string "attacked and kidnapped the child of\l"
	.string "the lowliest man in a village. The child\l"
	.string "was killed, and its head was sent to the\l"
	.string "village chieftan.$"

FarawayIsland_Historian2_Text_0:
	.string "HISTORIAN: The village priest saw the\n"
	.string "killing as an ill omen. She instructed\l"
	.string "the people to not fish for five days.\l"
	.string "During those five days, a typhoon came\l"
	.string "and killed the fishermen from nearby\l"
	.string "villages.$"

FarawayIsland_LevelCapManTalk_Text_0:
	.string "MR. MAN: Ah, all this philosophy is so\n"
	.string "boring. The level cap here is 36, and\l"
	.string "Nick will stick to his grass types.$"

FarawayIsland_NickBattle_Text_0:
	.string "NICK: On your way here you heard a\n"
	.string "story from two men. Some people believe\l"
	.string "that the story you heard portrays the\l"
	.string "gods' compassion. Do you think that\l"
	.string "those men agree that their story shows\l"
	.string "compassion?$"

FarawayIsland_NickBattle_Text_1:
	.string "But, you aren't here for stories. Ready\n"
	.string "to begin?$"

FarawayIsland_NickYes_Text_0:
	.string "I agree. The men you spoke to used to\n"
	.string "live in that village. They likely viewed\l"
	.string "the omen as an act of benevolence.$"

FarawayIsland_NickNo_Text_0:
	.string "Interesting. If you had known that the\n"
	.string "men were from the village, would you\l"
	.string "have changed your answer?$"

FarawayIsland_EndBossFight_Text_0:
	.string "NICK: Superb. Toodaloo!$"

FarawayIsland_BossDefeated::
	.string "Gaaaaaaaaaah!$"
