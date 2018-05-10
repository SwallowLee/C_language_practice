TITLE	HW2

; 
;========================================================
; Student Name:	§õ¨Î¿P
; Student ID:	0416039
; Email:		girlannie123@gmail.com
;========================================================
; Instructor: Sai-Keung WONG
; Email: cswingo@cs.nctu.edu.tw
; Assembly Language 
; Date: 2017/02/21
;========================================================

include Irvine32.inc
include Macros.inc

delayTime = 100
.data
	msg1	BYTE	0Dh, 0Ah, "  1) Change ship color ", 0Dh, 0Ah,
					"  2) Show a frame around the screen rectangular area", 0Dh, 0Ah,
					"  3) Play now!!!", 0Dh, 0Ah,
					"  4) Show author information", 0Dh, 0Ah,
					"  5) Quit game ƒº", 0Dh, 0Ah, 0Dh, 0Ah,
					"  Please enter an option¡K¡K", 0Dh, 0Ah, 0Dh, 0Ah, 0
	msg2	BYTE	"Student ID: 0416039", 0Dh, 0Ah,
					"Student name: §õ¨Î¿P", 0Dh, 0Ah,
					"Student email address: girlannie123@gmail.com", 0Dh, 0Ah,
					"Press Enter to hide the information", 0Dh, 0Ah, 0
	msg3	BYTE	"Please select a color for the space ship.", 0Dh, 0Ah, 0
	sound	BYTE	7
	X		BYTE	0
	Y		BYTE	0
	no		DWORD	0
	shipColor	DWORD	black + yellow*16
	one		DWORD	?
	two		DWORD	?
	num		BYTE	" 1   2   3", 0Dh, 0Ah, 0
.code

main PROC
S: call Clrscr
L0: mov X, 0
	mov Y, 0
	call SetPosition
	call showMenu
	call menuFrame
W1: call ReadKey
	cmp al, '1'
	je P1
	cmp al, '2'
	je P2
	cmp al, '3'
	je P3
	cmp al, '4'
	je P4
	cmp al, '5'
	je P5
	jmp W1
P1: call changeColor
	jmp S
P2: call showFrame
	jmp L0
P3: call play
	jmp S
P4: mov edx, OFFSET msg2
	call WriteString
Q:	call ReadChar
	cmp eax, 7181
	je S
	jmp Q
P5: exit
main ENDP

;;;;;;;;;;;;;;;;;;;;;;;;; play ;;;;;;;;;;;;;;;;;;;;;;;;;;;;

play PROC
	call Clrscr
	call showFrame
	mov no, 0
	mov X, 0
	mov Y, 11
	call setPosition
L0: call delete
	call ReadKey
	cmp al, 'e'
	je T
	cmp al, 'c'
	je D
	cmp al, ' '
	je Q
	jmp L1
T:	cmp Y, 1
	ja T1
	jmp L1
	T1:	call decY
		jmp L1
D:	cmp Y, 21
	jb T2
	jmp L1
	T2:	call incY
		jmp L1
L1: call incX
	cmp X, 77
	ja Q
	call showShip
	mov eax, delayTime
	call Delay
	mov al, 'q'
	jmp L0
Q:	mov eax, white + black*16
	call SetTextColor
	ret
play ENDP

delete PROC
	cmp no, 0
	je L1
	mov eax, white + black*16
	call SetTextColor
	call SetPosition
	call decX
	mov ebx, 0
L0: mov al, ' '
	call WriteChar
	inc ebx
	call decX
	cmp ebx, 2
	jne L0
L1:	cmp X, 0
	je L2
	mov al, ' '
	call WriteChar
L2:	mov no, 1
	ret
delete ENDP

showShip PROC
	mov eax, shipColor
	call SetTextColor
	mov ebx, 3
L0: mov al, ' '
	call WriteChar
	dec ebx
	call incX
	cmp ebx, 0
	jne L0
	ret
showShip ENDP

;;;;;;;;;;;;;;;;;;;;;;;;; change color ;;;;;;;;;;;;;;;;;;;;;;;;

changeColor PROC
	call Clrscr
	mov edx, OFFSET msg3
	call WriteString
	mov eax, shipColor
	call SetTextColor
	mov X, 0
	mov Y, 1
	call SetPosition
L0: mov al, ' '
	call WriteChar
	call incX
	cmp X, 2
	jb L0
L1: mov al, ' '
	call WriteChar
	call incY
	cmp Y, 3
	jb L1
	call decY
L2: mov al, ' '
	call WriteChar
	call decX
	cmp X, -1
	jg L2

	mov eax, shipColor
	add eax, 16
	call SetTextColor
	mov X, 4
	mov Y, 1
	call SetPosition
Q0: mov al, ' '
	call WriteChar
	call incX
	cmp X, 6
	jb Q0
Q1: mov al, ' '
	call WriteChar
	call incY
	cmp Y, 3
	jb Q1
	call decY
Q2: mov al, ' '
	call WriteChar
	call decX
	cmp X, 3
	ja Q2

	mov eax, shipColor
	add eax, 48
	call SetTextColor
	mov X, 8
	mov Y, 1
	call SetPosition
W0: mov al, ' '
	call WriteChar
	call incX
	cmp X, 10
	jb W0
W1: mov al, ' '
	call WriteChar
	call incY
	cmp Y, 3
	jb W1
	call decY
W2: mov al, ' '
	call WriteChar
	call decX
	cmp X, 7
	ja W2

	mov eax, white + black*16
	call SetTextColor
	mov X, 0
	mov Y, 3
	call SetPosition
	mov edx, OFFSET num
	call WriteString

P0:	call ReadKey
	cmp al, '1'
	je P1
	cmp al, '2'
	je P2
	cmp al, '3'
	je P3
	jmp P0
P1: jmp R 
P2: mov eax, shipColor
	add eax, 16
	mov shipColor, eax
	jmp R
P3: mov eax, shipColor
	add eax, 48
	mov shipColor, eax
	jmp R
R:	mov edx, OFFSET sound
	call WriteString
	ret
changeColor ENDP

;;;;;;;;;;;;;;;;;;;;;; show Menu and Frame ;;;;;;;;;;;;;;;;;;;;;;;;;
showFrame PROC
	mov X, 0
	mov Y, 0
	call SetPosition
	mov eax, shipColor
	call SetTextColor
L1: mov al, ' '
	call WriteChar
	call incY
	mov eax, delayTime
	call Delay
	cmp Y, 22
	jb L1
L0: mov al, ' '
	call WriteChar
	call incX
	mov eax, delayTime
	call Delay
	cmp X, 80
	jb L0
L3: mov al, ' '
	call WriteChar
	call decY
	mov eax, delayTime
	call Delay
	cmp Y, 0
	ja L3
L2: mov al, ' '
	call WriteChar
	call decX
	mov eax, delayTime
	call Delay
	cmp X, 0
	ja L2

	mov X, 0
	mov Y, 10
	call SetPosition
	mov eax, white + black*16
	call SetTextColor
	ret
showFrame ENDP

menuFrame PROC
	mov eax, shipColor
	call SetTextColor
	call setPosition
L0: mov al, ' '
	call WriteChar
	call incX
	cmp X, 60
	jb L0
L1: mov al, ' '
	call WriteChar
	call incY
	cmp Y, 9
	jb L1
L2: mov al, ' '
	call WriteChar
	call decX
	cmp X, 0
	ja L2
L3: mov al, ' '
	call WriteChar
	call decY
	cmp Y, 0
	ja L3
	mov X, 0
	mov Y, 10
	call SetPosition
	mov eax, white + black*16
	call SetTextColor
	ret
menuFrame ENDP

showMenu PROC
	mov edx, OFFSET msg1
	call WriteString
	ret
showMenu ENDP

;;;;;;;;;;;;;;;;;;;;;;;;; handle X, Y ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
setPosition PROC
	mov dl, X
	mov dh, Y
	call GotoXY
	ret
setPosition ENDP

incX PROC
	mov dl, X
	mov dh, Y
	inc dl
	mov X, dl
	call GotoXY
	ret
incX ENDP

incY PROC
	mov dl, X
	mov dh, Y
	inc dh
	mov Y, dh
	call GotoXY
	ret
incY ENDP

decX PROC
	mov dl, X
	mov dh, Y
	dec dl
	mov X, dl
	call GotoXY
	ret
decX ENDP

decY PROC
	mov dl, X
	mov dh, Y
	dec dh
	mov Y, dh
	call GotoXY
	ret
decY ENDP

END main