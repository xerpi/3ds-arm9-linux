.arm

#define FB_TOP_LEFT1  (0x20184E60)
#define FB_TOP_LEFT2  (0x201CB370)
#define FB_DIFF       (FB_TOP_LEFT2-FB_TOP_LEFT1)
#define FB_TOP_SIZE	  (0x46500)

.global black_screen
black_screen:
	stmfd sp!, {r0-r6, lr}
	ldr r0, =FB_TOP_LEFT1
	ldr r1, =FB_TOP_SIZE
	ldr r5, =FB_DIFF
	mov r2, #0 @ Color
	mov r3, #0
loop:
	add r4, r0, r3
	str r2, [r4]
	add r6, r4, r5
	str r2, [r6]
	add r3, r3, #4
	cmp r3, r1
	blt loop
	ldmfd sp!, {r0-r6, pc}

.global red_screen
red_screen:
	stmfd sp!, {r0-r7, lr}
	ldr r0, =FB_TOP_SIZE
	ldr r1,	=FB_TOP_LEFT1
	ldr r6, =FB_DIFF
	add r2, r1, r0 @limit_addr

	mov r3, #0x0
	mov r4, #0xFF

	mov r5, r1 @ ptr
for_red:
	strb r3, [r5, #0]
	strb r3, [r5, #1]
	strb r4, [r5, #2]
	add r7, r5, r6
	strb r3, [r7, #0]
	strb r3, [r7, #1]
	strb r4, [r7, #2]

	add r5, r5, #3
	cmp r5, r2
	blt for_red

	ldmfd sp!, {r0-r7, pc}

.global green_screen
green_screen:
	stmfd sp!, {r0-r7, lr}
	ldr r0, =FB_TOP_SIZE
	ldr r1,	=FB_TOP_LEFT1
	ldr r6, =FB_DIFF
	add r2, r1, r0 @limit_addr

	mov r3, #0x0
	mov r4, #0xFF

	mov r5, r1 @ ptr
for_green:
	strb r3, [r5, #0]
	strb r4, [r5, #1]
	strb r3, [r5, #2]
	add r7, r5, r6
	strb r3, [r7, #0]
	strb r4, [r7, #1]
	strb r3, [r7, #2]

	add r5, r5, #3
	cmp r5, r2
	blt for_green

	ldmfd sp!, {r0-r7, pc}
	
.global blue_screen
blue_screen:
	stmfd sp!, {r0-r7, lr}
	ldr r0, =FB_TOP_SIZE
	ldr r1,	=FB_TOP_LEFT1
	ldr r6, =FB_DIFF
	add r2, r1, r0 @limit_addr

	mov r3, #0x0
	mov r4, #0xFF

	mov r5, r1 @ ptr
for_blue:
	strb r4, [r5, #0]
	strb r3, [r5, #1]
	strb r3, [r5, #2]
	add r7, r5, r6
	strb r4, [r7, #0]
	strb r3, [r7, #1]
	strb r3, [r7, #2]

	add r5, r5, #3
	cmp r5, r2
	blt for_blue

	ldmfd sp!, {r0-r7, pc}

