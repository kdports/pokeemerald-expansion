AbandonedShip_GamerTalk::
	msgbox AbandonedShip_GamerTalk_Text_0
	closemessage
	return


AbandonedShip_LevelCapManTalk::
	msgbox AbandonedShip_LevelCapManTalk_Text_0
	giveitem ITEM_RARE_CANDY, 99
	closemessage
	return


AbandonedShip_Ghost1::
	lockall
	msgbox AbandonedShip_Ghost1_Text_0
	closemessage
	releaseall
	removeobject 3
	return


AbandonedShip_Ghost2::
	lockall
	msgbox AbandonedShip_Ghost2_Text_0
	closemessage
	releaseall
	removeobject 3
	return


AbandonedShip_Ghost3::
	lockall
	msgbox AbandonedShip_Ghost3_Text_0
	closemessage
	releaseall
	removeobject 4
	return


AbandonedShip_Ghost4::
	lockall
	msgbox AbandonedShip_Ghost4_Text_0
	closemessage
	releaseall
	removeobject 5
	return


AbandonedShip_CarolineBattle::
	faceplayer
	lockall
	msgbox AbandonedShip_CarolineBattle_Text_0
	multichoicedefault 20, 8, MULTI_EASYHARD, 1, FALSE
	switch VAR_RESULT
	case 1, AbandonedShip_CarolineBattle_3
	case 0, AbandonedShip_CarolineBattle_4
AbandonedShip_CarolineBattle_1:
	closemessage
	releaseall
	return

AbandonedShip_CarolineBattle_3:
	call AbandonedShip_CarolineHardFight
	goto AbandonedShip_CarolineBattle_1

AbandonedShip_CarolineBattle_4:
	call AbandonedShip_CarolineEasyFight
	goto AbandonedShip_CarolineBattle_1


AbandonedShip_CarolineEasyFight::
	trainerbattle_single TRAINER_DECLAN, Route116_LeaderBattleIntro, Route101_Text_Trainer1Defeated, AbandonedShip_EndBossFight, NO_MUSIC
	release
	return


AbandonedShip_CarolineHardFight::
	trainerbattle_double TRAINER_GRUNT_RUSTURF_TUNNEL, Route116_LeaderBattleIntro, Route101_Text_Trainer1Defeated, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_EndBossFight, NO_MUSIC
	release
	return


AbandonedShip_EndBossFight::
	msgbox AbandonedShip_EndBossFight_Text_0
	giveitem ITEM_POKE_BALL, 15
	fadescreen FADE_TO_BLACK
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 14, 38
	waitstate
	fadescreen FADE_FROM_BLACK
	return


AbandonedShip_Deck_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AbandonedShip_Deck_OnTransition
	.byte 0

AbandonedShip_Deck_OnTransition:
	setflag FLAG_LANDMARK_ABANDONED_SHIP
	end

AbandonedShip_GamerTalk_Text_0:
	.string "GAMER: Gamer time! Gastly is great! Go,\n"
	.string "go gastly!$"

AbandonedShip_LevelCapManTalk_Text_0:
	.string "MR. MAN: Why'd the challenge have to be\n"
	.string "here? There are ghost types\l"
	.string "everywhere, and the level cap is only\l"
	.string "29... By the way, some items can be used\l"
	.string "to evolve Pokemon. If you see any\l"
	.string "stones, try using them on your Eevee.$"

AbandonedShip_Ghost1_Text_0:
	.string "It's cold here...$"

AbandonedShip_Ghost2_Text_0:
	.string "I like when she sings to us...$"

AbandonedShip_Ghost3_Text_0:
	.string "Why did this happen to me? I didn't do\n"
	.string "anything wrong.$"

AbandonedShip_Ghost4_Text_0:
	.string "She can help me...$"

AbandonedShip_CarolineBattle_Text_0:
	.string "CAROLINE: Oh my god, hey! A real person!\n"
	.string "I've been singing to help get rid of\l"
	.string "these ghosts, but it's been so long\l"
	.string "since I saw a live human. Are you ready\l"
	.string "for a fight?$"

AbandonedShip_EndBossFight_Text_0:
	.string "CAROLINE: Aww, dammit, man! Tch, get out\n"
	.string "of here. I've got stuff to do!$"
