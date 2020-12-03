	.global expand
	.type expand, %function
	//Method to take in a hex array and convert it to a binary array of 1's and 0's
expand: 
	push	{r0-r9,lr}
	//Store hex[0] and binstring[0] on stack
	mov		r2, #0
	mov		r4, r1
	mov		r5, #48
	mov		r6, #49
	//Start for loop
expandloop:
	cmp 	r2, #40
	beq		expandloopexit
	ldrb		r3, [r0]
	//r3 = hex[counter]
	//start of switch statement
	//compare hex[x] with 0, if not equal go to check if it equals 1
switchbegining:
	cmp 	r3, #48
	bne		switch1
	//store 0000 in binstring
	mov		r5, #48
	mov		r6, #49
	strb	r5, [r4]
	add		r4, r4, #1
	strb	r5, [r4]
	add		r4, r4, #1
	strb	r5, [r4]
	add		r4, r4, #1
	strb	r5, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch1:
	//compare hex[x] with 1, if not equal go to check if it equals 2
	cmp 	r3, r6
	bne		switch2
	//store 0001 in binstring
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch2:
	//compare hex[x] with 2, if not equal go to check if it equals 3
	cmp 	r3, #50
	bne		switch3
	//store 0010 in binstrbing
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch3:
	//compare hex[x] with 3, if not equal go to check if it equals 4
	cmp 	r3, #51
	bne		switch4
	//store 0011 in binstrbing
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch4:
	//compare hex[x] with 4, if not equal go to check if it equals 5
	cmp 	r3, #52
	bne		switch5
	//store 0100 in binstrbing
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch5:
	//compare hex[x] with 5, if not equal go to check if it equals 6
	cmp 	r3, #53
	bne		switch6
	//store 0101 in binstrbing
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch6:
	//compare hex[x] with 6, if not equal go to check if it equals 7
	cmp 	r3, #54
	bne		switch7
	//store 0110 in binstrbing
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch7:
	//compare hex[x] with 7, if not equal go to check if it equals 8
	cmp 	r3, #55
	bne		switch8
	//store 0111 in binstrbing
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch8:
	//compare hex[x] with 8, if not equal go to check if it equals 9
	cmp 	r3, #56
	bne		switch9
	//store 1000 in binstrbing
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch9:
	//compare hex[x] with 9, if not equal go to check if it equals 10 (A)
	cmp 	r3, #57
	bne		switch10
	//store 1001 in binstrbing
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch10:
	//compare hex[x] with 10, if not equal go to check if it equals 11 (B)
	cmp 	r3, #65
	bne		switch11
	//store 1010 in binstrbing
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch11:
	//compare hex[x] with 11, if not equal go to check if it equals 12 (C)
	cmp 	r3, #66
	bne		switch12
	//store 1011 in binstrbing
	strb	r6, [r4]
	add		r4, r4, #1
	strb	r5, [r4]
	add		r4, r4, #1
	strb	r6, [r4]
	add		r4, r4, #1
	strb	r6, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch12:
	//compare hex[x] with 12, if not equal go to check if it equals 13 (D)
	cmp 	r3, #67
	bne		switch13
	//store 1100 in binstrbing
	strb	r6, [r4]
	add		r4, r4, #1
	strb	r6, [r4]
	add		r4, r4, #1
	strb	r5, [r4]
	add		r4, r4, #1
	strb	r5, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch13:
	//compare hex[x] with 13, if not equal go to check if it equals 14 (E)
	cmp 	r3, #68
	bne		switch14
	//store 1101 in binstrbing
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch14:
	//compare hex[x] with 14, if not equal go to check if it equals 15 (F)
	cmp 	r3, #69
	bne		switch15
	//store 1110 in binstrbing
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r5, [r4]
	add		r4, r4, #1
	b		expandswitchexit

switch15:
	//compare hex[x] with 15
	cmp 	r3, #70
	bne		expandswitchexit
	//store 1111 in binstrbing
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
	strb		r6, [r4]
	add		r4, r4, #1
expandswitchexit:
	add r2, r2, #1
	add r0, r0, #1
	b		expandloop
expandloopexit:
	pop		{r0-r9, pc}
//End of Expand function

	.global byte_at
	.type byte_at, %function
	//This function takes a starting position and the array of ‘1’ and ‘0’ and returns the character
	//representation of the five bits at that location
byte_at:
	push	{r2-r9,lr} 
	mov		r5, #48
	mov		r6, #49
	add r2, r0, r1
	
	//check if the char array matches 10000
	ldrb r3, [r2]
	cmp r6, r3
	bne check1
	ldrb r3, [r2, #1]
	cmp r5, r3
	bne check1
	ldrb r3, [r2, #2]
	cmp r5, r3
	bne check1
	ldrb r3, [r2, #3]
	cmp r5, r3
	bne check1
	ldrb r3, [r2, #4]
	cmp r5, r3
	bne check1
	//assign return value to 0
	mov r0, #48
	b byte_at_end

check1:
	//check if the char array matches 00001
	ldrb r3, [r2]
	cmp r5, r3
	bne check2
	ldrb r3, [r2, #1]
	cmp r5, r3
	bne check2
	ldrb r3, [r2, #2]
	cmp r5, r3
	bne check2
	ldrb r3, [r2, #3]
	cmp r5, r3
	bne check2
	ldrb r3, [r2, #4]
	cmp r6, r3
	bne check2
	//assign return value to 1
	mov r0, #49
	b byte_at_end

check2:
	//check if the char array matches 00010
	ldrb r3, [r2]
	cmp r5, r3
	bne check3
	ldrb r3, [r2, #1]
	cmp r5, r3
	bne check3
	ldrb r3, [r2, #2]
	cmp r5, r3
	bne check3
	ldrb r3, [r2, #3]
	cmp r6, r3
	bne check3
	ldrb r3, [r2, #4]
	cmp r5, r3
	bne check3
	//assign return value to 2
	mov r0, #50
	b byte_at_end

check3:
	//check if the char array matches 10011
	ldrb r3, [r2]
	cmp r6, r3
	bne check4
	ldrb r3, [r2, #1]
	cmp r5, r3
	bne check4
	ldrb r3, [r2, #2]
	cmp r5, r3
	bne check4
	ldrb r3, [r2, #3]
	cmp r6, r3
	bne check4
	ldrb r3, [r2, #4]
	cmp r6, r3
	bne check4
	//assign return value to 3
	mov r0, #51
	b byte_at_end

check4:
	//check if the char array matches 00100
	ldrb r3, [r2]
	cmp r5, r3
	bne check5
	ldrb r3, [r2, #1]
	cmp r5, r3
	bne check5
	ldrb r3, [r2, #2]
	cmp r6, r3
	bne check5
	ldrb r3, [r2, #3]
	cmp r5, r3
	bne check5
	ldrb r3, [r2, #4]
	cmp r5, r3
	bne check5
	mov r0, #52
	b byte_at_end

check5:
	//check if the char array matches 10101
	ldrb r3, [r2]
	cmp r6, r3
	bne check6
	ldrb r3, [r2, #1]
	cmp r5, r3
	bne check6
	ldrb r3, [r2, #2]
	cmp r6, r3
	bne check6
	ldrb r3, [r2, #3]
	cmp r5, r3
	bne check6
	ldrb r3, [r2, #4]
	cmp r6, r3
	bne check6
	//assign return value to 5
	mov r0, #53
	b byte_at_end

check6:
	//check if the char array matches 10110
	ldrb r3, [r2]
	cmp r6, r3
	bne check7
	ldrb r3, [r2, #1]
	cmp r5, r3
	bne check7
	ldrb r3, [r2, #2]
	cmp r6, r3
	bne check7
	ldrb r3, [r2, #3]
	cmp r6, r3
	bne check7
	ldrb r3, [r2, #4]
	cmp r5, r3
	bne check7
	//assign return value to 6
	mov r0, #54
	b byte_at_end

check7:
	//check if the char array matches 00111
	ldrb r3, [r2]
	cmp r5, r3
	bne check8
	ldrb r3, [r2, #1]
	cmp r5, r3
	bne check8
	ldrb r3, [r2, #2]
	cmp r6, r3
	bne check8
	ldrb r3, [r2, #3]
	cmp r6, r3
	bne check8
	ldrb r3, [r2, #4]
	cmp r6, r3
	bne check8
	//assign return value to 7
	mov r0, #55
	b byte_at_end

check8:
	//check if the char array matches 01000
	ldrb r3, [r2]
	cmp r5, r3
	bne check9
	ldrb r3, [r2, #1]
	cmp r6, r3
	bne check9
	ldrb r3, [r2, #2]
	cmp r5, r3
	bne check9
	ldrb r3, [r2, #3]
	cmp r5, r3
	bne check9
	ldrb r3, [r2, #4]
	cmp r5, r3
	bne check9
	//assign return value to 8
	mov r0, #56
	b byte_at_end

check9:
	//check if the char array matches 11001
	ldrb r3, [r2]
	cmp r6, r3
	bne check10
	ldrb r3, [r2, #1]
	cmp r6, r3
	bne check10
	ldrb r3, [r2, #2]
	cmp r5, r3
	bne check10
	ldrb r3, [r2, #3]
	cmp r5, r3
	bne check10
	ldrb r3, [r2, #4]
	cmp r6, r3
	bne check10
	//assign return value to 9
	mov r0, #57
	b byte_at_end

check10:
	//check if the char array matches 11010
	ldrb r3, [r2]
	cmp r6, r3
	bne check11
	ldrb r3, [r2, #1]
	cmp r6, r3
	bne check11
	ldrb r3, [r2, #2]
	cmp r5, r3
	bne check11
	ldrb r3, [r2, #3]
	cmp r6, r3
	bne check11
	ldrb r3, [r2, #4]
	cmp r5, r3
	bne check11
	//assign return value to 10
	mov r0, #58
	b byte_at_end

check11:
	//check if the char array matches 01011
	ldrb r3, [r2]
	cmp r5, r3
	bne check12
	ldrb r3, [r2, #1]
	cmp r6, r3
	bne check12
	ldrb r3, [r2, #2]
	cmp r5, r3
	bne check12
	ldrb r3, [r2, #3]
	cmp r6, r3
	bne check12
	ldrb r3, [r2, #4]
	cmp r6, r3
	bne check12
	//assign return value to 11
	mov r0, #59
	b byte_at_end

check12:
	//check if the char array matches 11100
	ldrb r3, [r2]
	cmp r6, r3
	bne check13
	ldrb r3, [r2, #1]
	cmp r6, r3
	bne check13
	ldrb r3, [r2, #2]
	cmp r6, r3
	bne check13
	ldrb r3, [r2, #3]
	cmp r5, r3
	bne check13
	ldrb r3, [r2, #4]
	cmp r5, r3
	bne check13
	//assign return value to 12
	mov r0, #60
	b byte_at_end

check13:
	//check if the char array matches 01101
	ldrb r3, [r2]
	cmp r5, r3
	bne check14
	ldrb r3, [r2, #1]
	cmp r6, r3
	bne check14
	ldrb r3, [r2, #2]
	cmp r6, r3
	bne check14
	ldrb r3, [r2, #3]
	cmp r5, r3
	bne check14
	ldrb r3, [r2, #4]
	cmp r6, r3
	bne check14
	//assign return value to 13
	mov r0, #61
	b byte_at_end

check14:
	//check if the char array matches 01110
	ldrb r3, [r2]
	cmp r5, r3
	bne check15
	ldrb r3, [r2, #1]
	cmp r6, r3
	bne check15
	ldrb r3, [r2, #2]
	cmp r6, r3
	bne check15
	ldrb r3, [r2, #3]
	cmp r6, r3
	bne check15
	ldrb r3, [r2, #4]
	cmp r5, r3
	bne check15
	//assign return value to 14
	mov r0, #62
	b byte_at_end

check15:
	//check if the char array matches 11111
	ldrb r3, [r2]
	cmp r6, r3
	bne error
	ldrb r3, [r2, #1]
	cmp r6, r3
	bne error
	ldrb r3, [r2, #2]
	cmp r6, r3
	bne error
	ldrb r3, [r2, #3]
	cmp r6, r3
	bne error
	ldrb r3, [r2, #4]
	cmp r6, r3
	bne error
	//assign return value to 15
	mov r0, #63
	b byte_at_end

error:

	mov r0, #69
byte_at_end:
	pop		{r2-r9, pc}

	.global digits
	.type digits, %function
	//This function will return true or false (something not zero, or zero, in other words). It returns true
	//if, starting in the “binstring” at “position”, the next “length” characters are all digits. 
digits: 
	push	{r3-r9,lr}
	mov 	r3, #0


digitsforloop:
	cmp 	r3, r1
	beq		digitsloopexit
	push	{r0-r5}
	mov		r4, #5
	mov		r1, r2
	mul     r5,r3, r4
	add     r0, r5, r0
	bl		byte_at
	cmp		r0, #69
	beq		returnfalse
	cmp		r0, #48
	blt		returnfalse
	cmp		r0, #57
	pop		{r0-r5}
	bgt		returnfalse
	add		r3, r3, #1
	b		digitsforloop

returnfalse:
	mov 	r0, #0
	b		digitsexit	

digitsloopexit:

returntrue:
	mov 	r0, #1
	b		digitsexit


digitsexit:
	pop		{r3-r9, pc}
