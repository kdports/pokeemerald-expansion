EverGrandeCity_E4Battle1_CenterTrigger::
	applymovement OBJ_EVENT_ID_PLAYER, E4_CenterTrigger
	waitmovement 0
	call EverGrandeCity_E4Battle1_PrepDialogue
	return


EverGrandeCity_E4Battle1_PrepDialogue::
	msgbox EverGrandeCity_E4Battle1_PrepDialogue_Text_0
	multichoicedefault 20, 8, MULTI_EASYHARD, 1, FALSE
	switch VAR_RESULT
	case 1, EverGrandeCity_E4Battle1_PrepDialogue_3
	case 0, EverGrandeCity_E4Battle1_PrepDialogue_4
EverGrandeCity_E4Battle1_PrepDialogue_1:
	closemessage
	return

EverGrandeCity_E4Battle1_PrepDialogue_3:
	trainerbattle_double TRAINER_ZANDER, Route116_LeaderBattleIntro, E4Battle1_BossDefeated, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, E4Battle1_EndBossFight, NO_MUSIC
	goto EverGrandeCity_E4Battle1_PrepDialogue_1

EverGrandeCity_E4Battle1_PrepDialogue_4:
	trainerbattle_double TRAINER_LEAH, Route116_LeaderBattleIntro, E4Battle1_BossDefeated, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, E4Battle1_EndBossFight, NO_MUSIC
	goto EverGrandeCity_E4Battle1_PrepDialogue_1


E4Battle1_EndBossFight::
	msgbox E4Battle1_EndBossFight_Text_0
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	closemessage
	return


E4_CenterTrigger:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

E4_RightTrigger:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

E4_LeftTrigger:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

.set LOCALID_NURSE, 1
.set LOCALID_GUARD_1, 3
.set LOCALID_GUARD_2, 4

EverGrandeCity_PokemonLeague_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonLeague_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor::
	setobjectxyperm LOCALID_GUARD_1, 8, 2
	setobjectxyperm LOCALID_GUARD_2, 11, 2
	return

EverGrandeCity_PokemonLeague_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EverGrandeCity_PokemonLeague_1F_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

@ The door guards only check for FLAG_BADGE06_GET because Winonas badge is the only one that can be skipped
@ Its assumed the player has the remaining badges
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard::
	lockall
	playfanfare MUS_OBTAIN_BADGE
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
	waitmessage
	waitfanfare
	closemessage
	copyobjectxytoperm LOCALID_GUARD_1
	copyobjectxytoperm LOCALID_GUARD_2
	setflag FLAG_ENTERED_ELITE_FOUR
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight::
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft::
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges::
	playse SE_FAILURE
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GoForth::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight:
	walk_down
	walk_left
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft:
	walk_down
	walk_right
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay:
	walk_left
	walk_in_place_faster_down
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay:
	walk_right
	walk_in_place_faster_down
	step_end

EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges:
	.string "Beyond this point, only those TRAINERS\n"
	.string "who have collected all the GYM BADGES\l"
	.string "are permitted to enter.\p"
	.string "TRAINER, let us confirm that you have\n"
	.string "all the GYM BADGES.$"

EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges:
	.string "You haven't obtained all the BADGES.\p"
	.string "If you're bound for the POKéMON\n"
	.string "LEAGUE, you must return with them.$"

EverGrandeCity_PokemonLeague_1F_Text_GoForth:
	.string "TRAINER! Believe in yourself and your\n"
	.string "POKéMON, and go forth!$"

EverGrandeCity_E4Battle1_PrepDialogue_Text_0:
	.string "CAROLINE: Think you're ready for this,\n"
	.string "bitch?\p"
	.string "BRANDON: Caroline, calm down. No need to\n"
	.string "be so worked up.\p"
	.string "CAROLINE: Whatever, I'm ready to go! No\n"
	.string "need for a warm up!$"

E4Battle1_EndBossFight_Text_0:
	.string "CAROLINE: Good job, I guess.\p"
	.string "BRANDON: I hope you're ready for what\n"
	.string "comes next.$"

E4Battle1_BossDefeated::
	.string "CAROLINE: Wha- argh, I thought we were\n"
	.string "in tune!\p"
	.string "BRANDON: ...Congratulations. This was\n"
	.string "well done.$"
