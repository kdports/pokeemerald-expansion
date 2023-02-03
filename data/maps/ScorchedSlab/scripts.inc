ScorchedSlab_AvaaniBattle::
	faceplayer
	lockall
	msgbox ScorchedSlab_AvaaniBattle_Text_0
	multichoicedefault 20, 8, MULTI_EASYHARD, 1, FALSE
	switch VAR_RESULT
	case 1, ScorchedSlab_AvaaniBattle_3
	case 0, ScorchedSlab_AvaaniBattle_4
ScorchedSlab_AvaaniBattle_1:
	closemessage
	releaseall
	return

ScorchedSlab_AvaaniBattle_3:
	call ScorchedSlab_AvaaniHardFight
	goto ScorchedSlab_AvaaniBattle_1

ScorchedSlab_AvaaniBattle_4:
	call ScorchedSlab_AvaaniEasyFight
	goto ScorchedSlab_AvaaniBattle_1


ScorchedSlab_AvaaniEasyFight::
	trainerbattle_single TRAINER_GRUNT_MUSEUM_2, Route116_LeaderBattleIntro, ScorchedSlab_BossDefeated, ScorchedSlab_EndBossFight, NO_MUSIC
	release
	return


ScorchedSlab_AvaaniHardFight::
	trainerbattle_double TRAINER_GRUNT_SPACE_CENTER_1, Route116_LeaderBattleIntro, ScorchedSlab_BossDefeated, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, ScorchedSlab_EndBossFight, NO_MUSIC
	release
	return


ScorchedSlab_LevelCapManTalk::
	msgbox ScorchedSlab_LevelCapManTalk_Text_0
	giveitem ITEM_RARE_CANDY, 99
	closemessage
	return


ScorchedSlab_EndBossFight::
	msgbox ScorchedSlab_EndBossFight_Text_0
	giveitem ITEM_ULTRA_BALL, 25
	fadescreen FADE_TO_BLACK
	warp MAP_SCORCHED_SLAB, 7, 16
	waitstate
	fadescreen FADE_FROM_BLACK
	return


ScorchedSlab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_OnTransition
	.byte 0

ScorchedSlab_OnTransition:
	setflag FLAG_LANDMARK_SCORCHED_SLAB
	end

ScorchedSlab_AvaaniBattle_Text_0:
	.string "AVAANI: Hey!!!!!!!!\p"
	.string "Did you have fun swimming? I moved all\n"
	.string "those rocks into the river. Hope that\l"
	.string "wasn't too annoying! So...$"

ScorchedSlab_LevelCapManTalk_Text_0:
	.string "MR. MAN: Gasp... I'm so tired. I'm not\n"
	.string "made for that swim... Believe it or not,\l"
	.string "Avaani uses fighting types. So why is\l"
	.string "she in an underground river? Training,\l"
	.string "obviously.$"

ScorchedSlab_EndBossFight_Text_0:
	.string "AVAANI: That was great, high five!\n"
	.string "Ready to leave?$"

ScorchedSlab_BossDefeated::
	.string "Yipee! ...wait, I lost, didn't I?$"
