LittlerootTown_ResearchLab_TrainerBattle1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_3, LittlerootTown_ResearchLab_Text_Trainer1Intro, LittlerootTown_ResearchLab_Text_Trainer1Defeated
	msgbox LittlerootTown_ResearchLab_TrainerBattle1_Text_0
	release
	return


LittlerootTown_ResearchLab_TrainerBattle2::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, LittlerootTown_ResearchLab_Text_Trainer2Intro, LittlerootTown_ResearchLab_Text_Trainer2Defeated
	msgbox LittlerootTown_ResearchLab_TrainerBattle2_Text_0
	release
	return


LittlerootTown_ResearchLab_TrainerBattle3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, LittlerootTown_ResearchLab_Text_Trainer3Intro, LittlerootTown_ResearchLab_Text_Trainer3Defeated
	msgbox LittlerootTown_ResearchLab_TrainerBattle3_Text_0
	release
	return


LittlerootTown_ResearchLab_GetItemQuickClaw::
	giveitem ITEM_QUICK_CLAW, 1
	setflag FLAG_ITEM_ROUTE_102_POTION
	return


LittlerootTown_ResearchLab_MapScripts::
	.byte 0

LittlerootTown_ResearchLab_TrainerBattle1_Text_0:
	.string "Mrgrgr...$"

LittlerootTown_ResearchLab_TrainerBattle2_Text_0:
	.string "Now I have to clean it up.$"

LittlerootTown_ResearchLab_TrainerBattle3_Text_0:
	.string "How awkward.$"

LittlerootTown_ResearchLab_Text_Trainer1Intro::
	.string "Hey, show some respect here!$"

LittlerootTown_ResearchLab_Text_Trainer1Defeated::
	.string "Kids these days!$"

LittlerootTown_ResearchLab_Text_Trainer2Intro::
	.string "Woah, hey, I'm carrying a beaker!$"

LittlerootTown_ResearchLab_Text_Trainer2Defeated::
	.string "I dropped the beaker...$"

LittlerootTown_ResearchLab_Text_Trainer3Intro::
	.string "I'm the head scientist, so I'll take the\n"
	.string "lead.$"

LittlerootTown_ResearchLab_Text_Trainer3Defeated::
	.string "Should I step down?$"
