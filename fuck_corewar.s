.name		"Fuck Corewar"
.comment	"Corewar is live"

entry:
	sti		r1, %:beegees_gen, %1
	sti		r1, %:beegees, %1
	sti		r1, %:wtf, %1
	sti		r1, %:is_live, %1
	fork	%:jp
	sti		r1, %:wtf, %1
	sti		r1, %:lfork, %1
	sti		r1, %:lfork, %9
	sti		r1, %:lfork, %17
	ld		%0, r1

beegees_gen:
	live	%42
	fork	%:beegees_gen
	ld		%0, r3

beegees:
	live	%4242302
	zjmp	%:beegees

wtf:
	live	%42
	st		r2, -120
	st		r2, -158
	st		r2, -260
	st		r2, -320
	st		r2, -154
	st		r2, -784
	st		r2, -365
	st		r2, -264
	st		r2, -560
	st		r2, 120
	st		r2, 158
	st		r2, 260
	st		r2, 320
	st		r2, 154
	st		r2, 784
	st		r2, 365
	st		r2, 264
	st		r2, 560
	ld		%0, r2
	zjmp	%:wtf

is_live:
	live	%42
	st		r14, -51
	st		r14, -61
	st		r14, -74
	st		r14, -25
	st		r14, -16
	st		r14, -124
	st		r14, 210
	st		r14, 570
	st		r14, 426
	st		r14, 845
	st		r14, 238
	st		r14, 321
	st		r14, 105
	st		r14, 348
	st		r14, 238
	st		r14, 197
	st		r14, 560
	st		r14, 841
	ld		%0, r14
	zjmp	%:is_live

lfork:
	live	%34	
	lfork	%925
	live	%567
	lfork	%1941
	live	%689
	lfork	%2957

jp:
	live	%42
	fork	%:jp
	live	%42
	fork	%:wtf
	live	%42
	zjmp	%:is_live
