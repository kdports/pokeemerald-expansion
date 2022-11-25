LittlerootTown_Mart_MapScripts::
	.byte 0
	
LittlerootTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LittlerootTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LittlerootTown_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	release
	end
