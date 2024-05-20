.extern arm_util_stuff


.global main
main:
    push	{r4-r11, lr}
   	mov	r9, sp


    bl util_stuff


    mov	sp, r9
	pop	{r4-r11, pc}



