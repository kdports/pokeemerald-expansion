AbandonedShip_GamerTalk::
	msgbox AbandonedShip_GamerTalk_Text_0
	closemessage
	return


AbandonedShip_LevelCapManTalk::
	msgbox AbandonedShip_LevelCapManTalk_Text_0
	giveitem ITEM_RARE_CANDY, 99
	closemessage
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
	.string "MR. MAN: It's a me! You know, this job\n"
	.string "has started to really get to me. I'm\l"
	.string "thinking of taking a vacation. Anyway,\l"
	.string "the level cap is 29. This place sure is\l"
	.string "spooky. Watch out for ghost types!$"
