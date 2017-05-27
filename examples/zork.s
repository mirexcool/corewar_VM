.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1

l5:		and r2, %0, r1

live:	live %1
	fork %:l5
