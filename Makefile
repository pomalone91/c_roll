hello: main.c
	gcc -o roll -g main.c helper.c Structures/NCArray.c Structures/roll.c Modes/Batch.c Modes/Interactive.c Modes/Static.c