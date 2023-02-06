ShoalCave_GamerTalk::
	msgbox ShoalCave_GamerTalk_Text_0
	closemessage
	return


ShoalCave_LevelCapManTalk::
	msgbox ShoalCave_LevelCapManTalk_Text_0
	giveitem ITEM_RARE_CANDY, 99
	closemessage
	return


ShoalCave_EndBossFight::
	msgbox ShoalCave_EndBossFight_Text_0
	giveitem ITEM_ULTRA_BALL, 15
	giveitem ITEM_TM14, 1
	fadescreen FADE_TO_BLACK
	warp MAP_AQUA_HIDEOUT_1F, 13, 27
	waitstate
	fadescreen FADE_FROM_BLACK
	return


ShoalCave_BelindaBattle::
	faceplayer
	lockall
	msgbox ShoalCave_BelindaBattle_Text_0
	multichoicedefault 20, 8, MULTI_EASYHARD, 1, FALSE
	switch VAR_RESULT
	case 1, ShoalCave_BelindaBattle_3
	case 0, ShoalCave_BelindaBattle_4
ShoalCave_BelindaBattle_1:
	closemessage
	releaseall
	return

ShoalCave_BelindaBattle_3:
	call ShoalCave_BelindaHardFight
	goto ShoalCave_BelindaBattle_1

ShoalCave_BelindaBattle_4:
	call ShoalCave_BelindaEasyFight
	goto ShoalCave_BelindaBattle_1


ShoalCave_BelindaEasyFight::
	trainerbattle_single TRAINER_FREDRICK, Route116_LeaderBattleIntro, ShoalCave_BossDefeated, ShoalCave_EndBossFight, NO_MUSIC
	release
	return


ShoalCave_BelindaHardFight::
	trainerbattle_double TRAINER_MATT, Route116_LeaderBattleIntro, ShoalCave_BossDefeated, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, ShoalCave_EndBossFight, NO_MUSIC
	release
	return


ShoalCave_LowTideIceRoom_MapScripts::
	.byte 0

ShoalCave_GamerTalk_Text_0:
	.string "GAMER: Am I in your way? I-I'm so cold I\n"
	.string "can't even move! The worst part is the\l"
	.string "ice falling from the ceiling. Seriously,\l"
	.string "who made this place?$"

ShoalCave_LevelCapManTalk_Text_0:
	.string "MR. MAN: It feels good to be out of the\n"
	.string "cold. Belinda's level cap is 64. Watch\l"
	.string "out for her ice types!$"

ShoalCave_EndBossFight_Text_0:
	.string "BELINDA: Pretty good.$"

ShoalCave_BelindaBattle_Text_0:
	.string "BELINDA: Hello. Did you make it here\n"
	.string "okay? I am the final battle before the\l"
	.string "gauntlet. So you better be ready.$"

ShoalCave_BossDefeated::
	.string "Urgh... alright.$"
