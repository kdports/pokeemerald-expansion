AquaHideout_GamerTalk::
	msgbox AquaHideout_GamerTalk_Text_0
	closemessage
	return


AquaHideout_KevinBattle::
	faceplayer
	lockall
	msgbox AquaHideout_KevinBattle_Text_0
	multichoicedefault 20, 8, MULTI_EASYHARD, 1, FALSE
	switch VAR_RESULT
	case 1, AquaHideout_KevinBattle_3
	case 0, AquaHideout_KevinBattle_4
AquaHideout_KevinBattle_1:
	closemessage
	releaseall
	return

AquaHideout_KevinBattle_3:
	call AquaHideout_KevinHardFight
	goto AquaHideout_KevinBattle_1

AquaHideout_KevinBattle_4:
	call AquaHideout_KevinEasyFight
	goto AquaHideout_KevinBattle_1


AquaHideout_KevinEasyFight::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route116_LeaderBattleIntro, AquaHideout_BossDefeated, AquaHideout_EndBossFight, NO_MUSIC
	release
	return


AquaHideout_KevinHardFight::
	trainerbattle_double TRAINER_GRUNT_MUSEUM_1, Route116_LeaderBattleIntro, AquaHideout_BossDefeated, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AquaHideout_EndBossFight, NO_MUSIC
	release
	return


AquaHideout_EndBossFight::
	msgbox AquaHideout_EndBossFight_Text_0
	giveitem ITEM_ULTRA_BALL, 25
	giveitem ITEM_TM29, 1
	fadescreen FADE_TO_BLACK
	warp MAP_SCORCHED_SLAB, 7, 16
	dofieldeffect FLDEFF_USE_SURF
	waitstate
	fadescreen FADE_FROM_BLACK
	return


AquaHideout_LevelCapManTalk::
	msgbox AquaHideout_LevelCapManTalk_Text_0
	giveitem ITEM_RARE_CANDY, 99
	closemessage
	return


AquaHideout_Server::
	msgbox AquaHideout_Server_Text_0
	closemessage
	return


AquaHideout_Ship::
	msgbox AquaHideout_Ship_Text_0
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, AquaHideout_Ship_3
	case 0, AquaHideout_Ship_4
AquaHideout_Ship_1:
	closemessage
	return

AquaHideout_Ship_3:
	call AquaHideout_BackOutAnswer
	goto AquaHideout_Ship_1

AquaHideout_Ship_4:
	call AquaHideout_WrongAnswer
	setwildbattle SPECIES_STARMIE, 36, ITEM_NONE
	dowildbattle
	warp MAP_AQUA_HIDEOUT_1F, 13, 25
	goto AquaHideout_Ship_1


AquaHideout_Tree::
	msgbox AquaHideout_Tree_Text_0
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, AquaHideout_Tree_3
	case 0, AquaHideout_Tree_4
AquaHideout_Tree_1:
	closemessage
	return

AquaHideout_Tree_3:
	call AquaHideout_BackOutAnswer
	goto AquaHideout_Tree_1

AquaHideout_Tree_4:
	call AquaHideout_WrongAnswer
	setwildbattle SPECIES_MEGANIUM, 36, ITEM_NONE
	dowildbattle
	warp MAP_AQUA_HIDEOUT_1F, 13, 25
	goto AquaHideout_Tree_1


AquaHideout_Shrub::
	msgbox AquaHideout_Shrub_Text_0
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, AquaHideout_Shrub_3
	case 0, AquaHideout_Shrub_4
AquaHideout_Shrub_1:
	closemessage
	return

AquaHideout_Shrub_3:
	call AquaHideout_BackOutAnswer
	goto AquaHideout_Shrub_1

AquaHideout_Shrub_4:
	call AquaHideout_WrongAnswer
	setwildbattle SPECIES_LEAVANNY, 36, ITEM_NONE
	dowildbattle
	warp MAP_AQUA_HIDEOUT_1F, 13, 25
	goto AquaHideout_Shrub_1


AquaHideout_Computer::
	msgbox AquaHideout_Computer_Text_0
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, AquaHideout_Computer_3
	case 0, AquaHideout_Computer_4
AquaHideout_Computer_1:
	closemessage
	return

AquaHideout_Computer_3:
	call AquaHideout_BackOutAnswer
	goto AquaHideout_Computer_1

AquaHideout_Computer_4:
	call AquaHideout_WrongAnswer
	setwildbattle SPECIES_ELECTRODE, 36, ITEM_NONE
	dowildbattle
	warp MAP_AQUA_HIDEOUT_1F, 13, 25
	goto AquaHideout_Computer_1


AquaHideout_Sign::
	msgbox AquaHideout_Sign_Text_0
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, AquaHideout_Sign_3
	case 0, AquaHideout_Sign_4
AquaHideout_Sign_1:
	closemessage
	return

AquaHideout_Sign_3:
	call AquaHideout_BackOutAnswer
	goto AquaHideout_Sign_1

AquaHideout_Sign_4:
	call AquaHideout_WrongAnswer
	setwildbattle SPECIES_GARDEVOIR, 36, ITEM_NONE
	dowildbattle
	warp MAP_AQUA_HIDEOUT_1F, 13, 25
	goto AquaHideout_Sign_1


AquaHideout_Flowers::
	msgbox AquaHideout_Flowers_Text_0
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, AquaHideout_Flowers_3
	case 0, AquaHideout_Flowers_4
AquaHideout_Flowers_1:
	closemessage
	return

AquaHideout_Flowers_3:
	call AquaHideout_BackOutAnswer
	goto AquaHideout_Flowers_1

AquaHideout_Flowers_4:
	call AquaHideout_WrongAnswer
	setwildbattle SPECIES_FLORGES, 36, ITEM_NONE
	dowildbattle
	warp MAP_AQUA_HIDEOUT_1F, 13, 25
	goto AquaHideout_Flowers_1


AquaHideout_TrashCan::
	msgbox AquaHideout_TrashCan_Text_0
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, AquaHideout_TrashCan_3
	case 0, AquaHideout_TrashCan_4
AquaHideout_TrashCan_1:
	closemessage
	return

AquaHideout_TrashCan_3:
	call AquaHideout_BackOutAnswer
	goto AquaHideout_TrashCan_1

AquaHideout_TrashCan_4:
	call AquaHideout_WrongAnswer
	setwildbattle SPECIES_GARBODOR, 36, ITEM_NONE
	dowildbattle
	warp MAP_AQUA_HIDEOUT_1F, 13, 25
	goto AquaHideout_TrashCan_1


AquaHideout_Cabinets::
	msgbox AquaHideout_Cabinets_Text_0
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, AquaHideout_Cabinets_3
	case 0, AquaHideout_Cabinets_4
AquaHideout_Cabinets_1:
	closemessage
	return

AquaHideout_Cabinets_3:
	call AquaHideout_BackOutAnswer
	goto AquaHideout_Cabinets_1

AquaHideout_Cabinets_4:
	msgbox AquaHideout_Cabinets_Text_1
	warp MAP_AQUA_HIDEOUT_B1F, 7, 5
	goto AquaHideout_Cabinets_1


AquaHideout_TriggerRiddle::
	msgbox AquaHideout_TriggerRiddle_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, AquaHideout_WalkUp
	waitmovement 0
	return


AquaHideout_WrongAnswer::
	msgbox AquaHideout_WrongAnswer_Text_0
	closemessage
	return


AquaHideout_BackOutAnswer::
	msgbox AquaHideout_BackOutAnswer_Text_0
	closemessage
	return


AquaHideout_WalkUp:
	face_up
	walk_up
	step_end

AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "What? What? What do you want with \n"
	.string "TEAM AQUA?\p"
	.string "Our BOSS isn't here! He's gone off to\n"
	.string "snatch something important!\p"
	.string "… …\n"
	.string "Where did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "What? What?\n"
	.string "Are you a TEAM MAGMA grunt?\p"
	.string "I hear that TEAM MAGMA is trying to\n"
	.string "awaken an awesome POKéMON at their\l"
	.string "HIDEOUT.\p"
	.string "But where might their HIDEOUT be?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "What? What? What do you want with \n"
	.string "TEAM AQUA?\p"
	.string "Our BOSS isn't here!\n"
	.string "He's gone off to jack a submarine!\p"
	.string "… …\n"
	.string "Where did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "What? What? What do you want with \n"
	.string "TEAM AQUA?\p"
	.string "Our BOSS isn't here! He's on his way to\n"
	.string "MT. PYRE on ROUTE 122!\p"
	.string "… …\n"
	.string "Why did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "What? What?\n"
	.string "Are you a TEAM MAGMA grunt?\p"
	.string "I hear that TEAM MAGMA is after\n"
	.string "an awesome POKéMON at MT. CHIMNEY.\p"
	.string "But what is that POKéMON like?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "What? What? What do you want with\n"
	.string "TEAM AQUA?\p"
	.string "Our BOSS isn't here!\n"
	.string "He's on his way to SLATEPORT CITY!\p"
	.string "… …\n"
	.string "Why did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Ayiyiyi!\n"
	.string "Suspicious character spotted!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Grrrrr…\n"
	.string "I lost it!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "I took the loss for the TEAM,\n"
	.string "but I did my job…$"

AquaHideout_GamerTalk_Text_0:
	.string "GAMER: Skarmory can set spikes! Also,\n"
	.string "Klefki is a must-have.$"

AquaHideout_KevinBattle_Text_0:
	.string "KEVIN: I'm not sure if anything you\n"
	.string "just played through was fun at all. But,\l"
	.string "it's in the game, so, eh. You ready?$"

AquaHideout_EndBossFight_Text_0:
	.string "KEVIN: You only have a few bosses left!\n"
	.string "Good luck.$"

AquaHideout_LevelCapManTalk_Text_0:
	.string "MR. MAN: The level cap here is 40. My\n"
	.string "mind is boggled after all of this... so\l"
	.string "it's no surprise Kevin uses psychic\l"
	.string "types.$"

AquaHideout_Server_Text_0:
	.string "KEVIN: I don't know what this is, but it\n"
	.string "isn't the answer.$"

AquaHideout_Ship_Text_0:
	.string "KEVIN: So, is the answer a ship?$"

AquaHideout_Tree_Text_0:
	.string "KEVIN: So, is the answer a tree?$"

AquaHideout_Shrub_Text_0:
	.string "KEVIN: So, is the answer a shrub?$"

AquaHideout_Computer_Text_0:
	.string "KEVIN: So, is the answer a computer?$"

AquaHideout_Sign_Text_0:
	.string "KEVIN: So, is the answer a sign?$"

AquaHideout_Flowers_Text_0:
	.string "KEVIN: So, is the answer a flower?$"

AquaHideout_TrashCan_Text_0:
	.string "KEVIN: So, is the answer a trash can?$"

AquaHideout_Cabinets_Text_0:
	.string "KEVIN: So, is the answer a cabinet?$"

AquaHideout_Cabinets_Text_1:
	.string "Correct! I guess I'll see you soon.$"

AquaHideout_TriggerRiddle_Text_0:
	.string "KEVIN: Well, hi there. You're over\n"
	.string "halfway done! That's impressive. Now,\l"
	.string "I'm not gonna make this easy. In order\l"
	.string "to reach me, I'll first you need to\l"
	.string "solve a riddle.\p"
	.string "I cannot be carried by one person, am\n"
	.string "often found inside, and am often\l"
	.string "searched through. What am I?$"

AquaHideout_WrongAnswer_Text_0:
	.string "KEVIN: Nope! I'll give you another try,\n"
	.string "but, first...$"

AquaHideout_BackOutAnswer_Text_0:
	.string "KEVIN: Reconsidering your answer?$"

AquaHideout_BossDefeated::
	.string "...Fuck! I threw.$"
