;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; National Chiao Tung University
; Department Of Computer Science
; 
; Assembly Programming Tests
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Write programs in the Release mode
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; $Student Name: §õ¨Î¿P
; $Student ID: 0416039
; $Student Email:	girlannie123@gmail.com
;
; Instructor Name: Sai-Keung Wong 
;
TITLE 

include Irvine32.inc
include Macros.inc

delayTime = 100
.data
	first	DWORD	yellow + yellow*16
	sec		DWORD	?
	X	BYTE	0
	Y	BYTE	0
	X1	BYTE	1
	Y1	BYTE	1
	cal	DWORD	0
	change		DWORD	0
	one			DWORD	1
	two			DWORD	2
	line		DWORD	0
	none		DWORD	1
	msg				BYTE		"Student ID: 0416039", 0Dh, 0Ah,
								"name: §õ¨Î¿P", 0Dh, 0Ah,
								"Press enter to quit the game", 0
.code

main PROC
	mov eax, first
	mov sec, eax
	add sec, 16
	call showFrame
Q:	call ReadChar
	cmp al, 'b'
	je P1
	cmp al, 'r'
	je P2
	cmp al, 'f'
	je P3
	cmp al, 'd'
	je P4
	cmp al, 'g'
	je P5
	cmp al, ' '
	je P6
	cmp al, 'c'
	je P7
	cmp eax, 283
	je P8
	jmp D
P1: call delete
	mov change, 1
	jmp D

P2: call delete
	cmp Y1, 1
	ja M1
	jmp D
M1:	call decY
	jmp D

P3: call delete
	cmp Y1, 16
	jb R1
	jmp D
R1:	call incY
	jmp D

P4: call delete
	cmp X1, 1
	ja W1
	jmp D
W1:	call decX
	jmp D

P5:	call delete
	cmp X1, 55
	jb U1
	jmp D
U1:	call incX
	jmp D
P6: call delete
	call changeBit
	jmp D
P7: call delete
	call changeColor
	jmp D
P8: mov eax, white + black*16
	call SetTextColor
	mov dl, 0
	mov dh, 0
	call GotoXY
	mov edx, OFFSET msg
	call WriteString
H:	call ReadChar
	cmp eax, 7181
	je L3
	jmp H
	;;;;;;;;;;;;;;;;;;;;;
D:	mov none, 0
	cmp change, 1
	je L1
	cmp change, 2
	je L2
Q1:	call delayAnimation
	jmp Q
L1: call showFirst
	jmp Q1
L2: call showSecond
	jmp Q1
L3:	exit
main ENDP
delayAnimation PROC
	mov eax, delayTime
	call Delay
	ret
delayAnimation ENDP
delete PROC
	cmp none, 1
	je L4
	mov eax, white + black*16
	call SetTextColor
	mov line, 4
	jmp L2
L1: call setPosition
	mov al, ' '
	call WriteChar
	call decX
	inc line
	inc cal
	cmp cal, 20
	je L3
	cmp line, 5
	je L2	
	jmp L1
L2: dec line
	call incX
	cmp line, 0
	ja L2
	call decY
	jmp L1
L3:	mov line, 0
	mov cal, 0
	call incX
L4:	ret
delete ENDP
;;;;;;;;;;;;;;;;;;;; show ship ;;;;;;;;;;;;;;;;;;;;;;
showFirst PROC
	mov eax, first
	call SetTextColor
L1: call setPosition
	mov al, ' '
	call WriteChar
	call incX
	inc line
	inc cal
	cmp cal, 1
	je Q1
	cmp cal, 4
	je Q2
	cmp cal, 7
	je Q1
	cmp cal, 8
	je Q2
	cmp line, 5
	je Q3
L3:	cmp cal, 10
	je Q1
	cmp cal, 12
	je Q2
	cmp cal, 13
	je Q1
	cmp cal, 15
	je Q2
	cmp cal, 17
	je Q1
	cmp cal, 18
	je Q2
	cmp cal, 20
	jb L1
	jmp L2
Q1:	mov eax, white + black*16
	call SetTextColor
	jmp L1
Q2:	mov eax, first
	call SetTextColor
	jmp L1
Q3: dec line
	call decX
	cmp line, 0
	ja Q3
	call incY
	jmp L3
L2:	mov cal, 0
	mov line, 0
	mov eax, black + black*16
	call SetTextColor
	ret
showFirst ENDP
showSecond PROC
	mov eax, sec
	call SetTextColor
L1: call setPosition
	mov al, ' '
	call WriteChar
	call incX
	inc line
	inc cal
	cmp cal, 6
	je Q2
	cmp cal, 7
	je Q1
	cmp cal, 8
	je Q2
	cmp line, 5
	je Q3
L3:	cmp cal, 5
	je Q1
	cmp cal, 9
	je Q1
	cmp cal, 10
	je Q2
	cmp cal, 15
	je Q1
	cmp cal, 16
	je Q2
	cmp cal, 17
	je Q1
	cmp cal, 18
	je Q2
	cmp cal, 19
	je Q1
	cmp cal, 20
	jb L1
	jmp L2
Q1:	mov eax, white + black*16
	call SetTextColor
	jmp L1
Q2:	mov eax, sec
	call SetTextColor
	jmp L1
Q3: dec line
	call decX
	cmp line, 0
	ja Q3
	call incY
	jmp L3
L2:	mov cal, 0
	mov line, 0
	mov eax, black + black*16
	call SetTextColor
	ret
showSecond ENDP
changeBit PROC
	cmp change, 1
	je L1
	cmp change, 2
	je L2
L1: mov change, 2
	jmp L3
L2: mov change, 1
L3:	ret
changeBit ENDP
changeColor PROC
	cmp change, 1
	je L1
	cmp change, 2
	je L2
	jmp L3
L1:	cmp one, 1
	je P1
	cmp one, 2
	je P2
	cmp one, 3
	je P3
P1:	mov one, 2
	add first, 16
	jmp L3
P2:	mov one, 3
	add first, 32
	jmp L3
P3:	mov one, 1
	sub first, 48
	jmp L3
L2: cmp two, 1
	je Q1
	cmp two, 2
	je Q2
	cmp two, 3
	je Q3
Q1:	mov two, 2
	add sec, 16
	jmp L3
Q2:	mov two, 3
	add sec, 32
	jmp L3
Q3:	mov two, 1
	sub sec, 48
L3:	ret
changeColor ENDP
;;;;;;;;;;;;;;;;;;;; show frame ;;;;;;;;;;;;;;;;;;;;;
setPosition PROC
	cmp change, 0
	je L0
	cmp change, 1
	je L1
	cmp change, 2
	je L1
L0:	mov dl, X
	mov dh, Y
	call GotoXY
	jmp L2
L1: mov dl, X1
	mov dh, Y1
	call GotoXY	
L2:	ret
setPosition ENDP
showFrame PROC
	mov dl, X
	mov dh, Y
	call GotoXY
	mov eax, blue + blue*16
	call SetTextColor
T:	mov al, ' '
	call WriteChar
	call incX
	cmp X, 60
	jb T
R:	mov al, ' '
	call WriteChar
	call incY
	cmp Y, 20
	jb R
D:	mov al, ' '
	call WriteChar
	call decX
	cmp X, 0
	ja D
L:	mov al, ' '
	call WriteChar
	call decY
	cmp Y, 0
	ja L
	mov eax, white + black*16
	call SetTextColor
	ret
showFrame ENDP
;;;;;;;;;;;;;;;;;;;;;;change XY;;;;;;;;;;;;;;;;;
incX PROC
	cmp change, 0
	je L0
	cmp change, 1
	je L1
	cmp change, 2
	je L1
L0:	mov dl, X
	mov dh, Y
	inc dl
	mov X, dl
	call GotoXY
	jmp L2
L1:	mov dl, X1
	mov dh, Y1
	inc dl
	mov X1, dl
	call GotoXY
L2:	ret
incX ENDP
decX PROC
	cmp change, 0
	je L0
	cmp change, 1
	je L1
	cmp change, 2
	je L1
L0:	mov dl, X
	mov dh, Y
	dec dl
	mov X, dl
	call GotoXY
	jmp L2
L1:	mov dl, X1
	mov dh, Y1
	dec dl
	mov X1, dl
	call GotoXY
L2:	ret
decX ENDP
incY PROC
	cmp change, 0
	je L0
	cmp change, 1
	je L1
	cmp change, 2
	je L1
L0:	mov dl, X
	mov dh, Y
	inc dh
	mov Y, dh
	call GotoXY
	jmp L2
L1:	mov dl, X1
	mov dh, Y1
	inc dh
	mov Y1, dh
	call GotoXY
L2:	ret
incY ENDP
decY PROC
	cmp change, 0
	je L0
	cmp change, 1
	je L1
	cmp change, 2
	je L1
L0:	mov dl, X
	mov dh, Y
	dec dh
	mov Y, dh
	call GotoXY
	jmp L2
L1:	mov dl, X1
	mov dh, Y1
	dec dh
	mov Y1, dh
	call GotoXY
L2:	ret
decY ENDP

END main
