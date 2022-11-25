LittlerootTown_ProfessorBirchsLab_TrainerBattle1::
	trainerbattle_double TRAINER_GRUNT_SEAFLOOR_CAVERN_2, LittlerootTown_ProfessorBirchsLab_Text_Trainer1Intro, LittlerootTown_ProfessorBirchsLab_Text_Trainer1Defeated, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons
	msgbox LittlerootTown_ProfessorBirchsLab_TrainerBattle1_Text_0
	release
	return


LittlerootTown_ProfessorBirchsLab_TrainerBattle2::
	trainerbattle_double TRAINER_GRUNT_SEAFLOOR_CAVERN_3, LittlerootTown_ProfessorBirchsLab_Text_Trainer1Intro, LittlerootTown_ProfessorBirchsLab_Text_Trainer1Defeated, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons
	msgbox LittlerootTown_ProfessorBirchsLab_TrainerBattle2_Text_0
	release
	return


LittlerootTown_ProfessorBirchsLab_TrainerBattle3::
	trainerbattle_double TRAINER_GABRIELLE_1, LittlerootTown_ProfessorBirchsLab_Text_Trainer1Intro, LittlerootTown_ProfessorBirchsLab_Text_Trainer1Defeated, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons
	msgbox LittlerootTown_ProfessorBirchsLab_TrainerBattle3_Text_0
	release
	return


LittlerootTown_ProfessorBirchsLab_TrainerBattle4::
	trainerbattle_double TRAINER_GRUNT_PETALBURG_WOODS, LittlerootTown_ProfessorBirchsLab_Text_Trainer4Intro, LittlerootTown_ProfessorBirchsLab_Text_Trainer4Defeated, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons
	msgbox LittlerootTown_ProfessorBirchsLab_TrainerBattle4_Text_0
	release
	return


LittlerootTown_ProfessorBirchsLab_CampLeaderBattle::
	trainerbattle_double TRAINER_MARCEL, LittlerootTown_ProfessorBirchsLab_Text_Trainer4Intro, LittlerootTown_ProfessorBirchsLab_Text_Trainer4Defeated, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons
	msgbox LittlerootTown_ProfessorBirchsLab_CampLeaderBattle_Text_0
	release
	return


LittlerootTown_ProfessorBirchsLab_MapScripts::
	.byte 0

LittlerootTown_ProfessorBirchsLab_TrainerBattle1_Text_0:
	.string "Keep going, you got this.$"

LittlerootTown_ProfessorBirchsLab_TrainerBattle2_Text_0:
	.string "Huh, I didn't expect that.$"

LittlerootTown_ProfessorBirchsLab_TrainerBattle3_Text_0:
	.string "Shoot.$"

LittlerootTown_ProfessorBirchsLab_TrainerBattle4_Text_0:
	.string "The camp leader is next.$"

LittlerootTown_ProfessorBirchsLab_CampLeaderBattle_Text_0:
	.string "MATTHEW: We hope your journey goes\n"
	.string "well.$"

LittlerootTown_ProfessorBirchsLab_Text_Trainer1Intro::
	.string "Ready to go?$"

LittlerootTown_ProfessorBirchsLab_Text_Trainer1Defeated::
	.string "Not too shabby.$"

LittlerootTown_ProfessorBirchsLab_Text_Trainer2Intro::
	.string "I'm a challenging foe.$"

LittlerootTown_ProfessorBirchsLab_Text_Trainer2Defeated::
	.string "You're somehow better!$"

LittlerootTown_ProfessorBirchsLab_Text_Trainer3Intro::
	.string "Have you considered not battling me?$"

LittlerootTown_ProfessorBirchsLab_Text_Trainer3Defeated::
	.string "Ah, well, I see I was too late.$"

LittlerootTown_ProfessorBirchsLab_Text_Trainer4Intro::
	.string "I'm the last camp trainer.$"

LittlerootTown_ProfessorBirchsLab_Text_Trainer4Defeated::
	.string "You've surpassed me!$"

LittlerootTown_ProfessorBirchsLab_Text_CampLeaderBattleIntro::
	.string "NATASHA: I'm surprised you've made it\n"
	.string "this far.\p"
	.string "MATTHEW: Pleasantly surprised.\p"
	.string "NATASHA: I hope you and your partner\n"
	.string "are ready.\p"
	.string "MATTHEW: Alright, let's get going!$"

LittlerootTown_ProfessorBirchsLab_Text_CampLeaderBattleDefeated::
	.string "NATASHA: Good work.\p"
	.string "MATTHEW: That was an impressive\n"
	.string "strategy!\p"
	.string "NATASHA: As your reward for defeating\n"
	.string "us, I award you both the First Cert.\p"
	.string "MATTHEW: This will allow you to truly\n"
	.string "begin your climb and make your way to\l"
	.string "the next camp.$"
