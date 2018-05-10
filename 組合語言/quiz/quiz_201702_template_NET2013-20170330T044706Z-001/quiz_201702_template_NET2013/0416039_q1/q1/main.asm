;7181 283
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
; $Student Email: girlannie123@gmail.com
;
; Instructor Name: Sai-Keung Wong 
;
TITLE 

include Irvine32.inc
include Macros.inc

.data
	msg1	BYTE	0Dh, 0Ah, 0Dh, 0Ah, "  My student ID is: 0416039", 0Dh, 0Ah,
					"  Please select one of the option", 0Dh, 0Ah,
					"  1. Compute (1^2+2^2+3^2+¡K+n^2)/m", 0Ah, 0Ah,
					"  2. Compute", 0Dh, 0Ah,
					"  	(1^2-2^2+3^2+¡K+(-1)^(n+1) n^2)*m", 0Dh, 0Ah,
					"  3. Compute S(n).", 0Dh, 0Ah,
					"	Define S(n) = 1 + S(n-1) + S(n-2), n>=2. S(0) = 1, S(1) = 1.5.", 0Dh, 0Ah,
					"  4. Quit program", 0Dh, 0Ah,
					"  Please enter an option¡K¡K", 0Dh, 0Ah, 0
	msg2	BYTE	"1. Compute (1^2+2^2+3^2+¡K+n^2)/m", 0Ah, 0Ah,
					"Input n [0, 100]: ", 0
	warn	BYTE	"out of range.", 0Dh, 0Ah, 0
	msg3	BYTE	"Input m (non-zero, signed integer):", 0
	msg4	BYTE	"2. Compute (1^2-2^2+3^2+...+(-1)^(n+1) n^2)*m", 0Dh, 0Ah,
					"Please input n [0, 50]: ", 0
	msg5	BYTE	"3.Compute S(n).", 0Ah, 0Dh,
					"Define S(n) = 1.0 +S(n-1) + S(n-2), 	n>=2. S(0) = 1.0, S(1) = 1.5", 0Dh, 0Ah,
					"Please input n:", 0
	msg6	BYTE	"Thanks for playing this system.", 0Ah, 0Dh,
					"This program is written by ", 0Ah, 0Dh,
					"	Name: §õ¨Î¿P", 0Ah, 0Dh,
					"	ID: 0416039", 0Ah, 0Dh,
					"I am learning assembly programming.", 0Dh, 0Ah,
					"Please contact me at girlannie123@gmail.com.", 0Dh, 0Ah,
					"Press ENTER to quit.", 0
	X		BYTE	0
	Y		BYTE	0
	m		DWORD	?
	n		DWORD	?
	ans		DWORD	?
	sign	DWORD	-1
	first	REAL8	1.5
	second	REAL8	1.0
	third	REAL8	?
	one		REAL8	1.0
	trash	REAL8	?
	initial1	REAL8	1.5
	initial2	REAL8	1.0
	quotient		BYTE	"Quotient: ", 0
	remainder		BYTE	"Remainder: ", 0
.code

main PROC
L0:	call ClrScr
	mov X, 0
	mov Y, 0
	call SetPosition
	mov eax, white + blue*16
	call SetTextColor
	mov edx, OFFSET msg1
	call WriteString
	call showFrame
	mov X, 0
	mov Y, 15
	call SetPosition
Q:  call ReadKey
	cmp al, '1'
	je L1
	cmp al, '2'
	je L2
	cmp al, '3'
	je L3
	cmp al, '4'
	je L4
	jmp Q
L1:	call Division
	jmp L0
L2: call Multiply
	jmp L0
L3: call plus
	jmp L0
L4:	mov edx, OFFSET msg6
	call WriteString
Q1: call ReadChar
	cmp eax, 7181
	je L5
	jmp Q1
L5:	exit
main ENDP
;;;;;;;;;;;;;;;;;; three ;;;;;;;;;;;;;;;;;;
plus PROC
	call ClrScr
L1:	mov edx, OFFSET msg5
	call WriteString
	call ReadInt
	cmp eax, 0
	je L2
	call computeThree
	jmp L1
L2:	ret
plus ENDP
computeThree PROC
	finit
	fld initial1
	fld initial2
	fstp second
	fstp first
	mov ecx, eax
	sub ecx, 1
L1: fld first
	fstp third
	fld first
	fld one
	fadd ST(0), ST(1)
	fstp first
	fstp trash
	fld first
	fld second
	fadd ST(0), ST(1)
	fstp first
	fstp second
	fld third
	fstp second
	Loop L1	
	fld first
	call WriteFloat
	call Crlf
	ret
computeThree ENDP
;;;;;;;;;;;;;;;;;;; two ;;;;;;;;;;;;;;;;;;;
Multiply PROC
	call ClrScr
L1:	mov edx, OFFSET msg4
	call WriteString
	call ReadInt
	cmp eax, 50
	ja L2
	cmp eax, 0
	jl L2
	mov ebx, eax
	cmp ebx, 0
	je L4
	mov edx, OFFSET msg3
	call WriteString
	call ReadInt
	call computeTwo
	jmp L1
L2: mov edx, OFFSET warn
	call WriteString
	jmp L1
L4:	ret
Multiply ENDP
computeTwo PROC
	mov sign, -1
	mov ecx, ebx
	mov m, eax
	mov ebx, 1
	mov ans, 0
L1:	mov eax, ebx
	imul eax
	neg sign
	imul sign
	add ans, eax
	inc ebx
	Loop L1
L3:	mov eax, m
	imul ans
	call WriteInt
	call Crlf
	ret
computeTwo	ENDP
;;;;;;;;;;;;;;;;;;; one ;;;;;;;;;;;;;;;;;;
Division PROC
    call ClrScr
L1:	mov edx, OFFSET msg2
	call WriteString
	call ReadInt
	cmp eax, 100
	ja L2
	cmp eax, 0
	jl L2
	cmp eax, 0
	je L4
	mov ebx, eax
	mov edx, OFFSET msg3
	call WriteString
	call ReadInt
	call computeOne
	jmp L1
L2: mov edx, OFFSET warn
	call WriteString
	jmp L1
L4:	ret
Division ENDP
computeOne PROC
	mov m, eax
	mov ecx, ebx
	mov ebx, 1
	mov n, 0
L1:	mov eax, ebx
	mul eax
	add n, eax
	inc ebx
	Loop L1
	mov eax, n
	mov edx, 0
	div m
	mov ebx, edx
	mov edx, OFFSET quotient
	call WriteString
	call WriteInt
	call Crlf
	mov edx, OFFSET remainder
	call WriteString
	mov eax, ebx
	call WriteInt
	call Crlf
	ret
computeOne ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SetPosition PROC
	mov dl, X
	mov dh, Y
	call GotoXY
	ret
SetPosition ENDP
showFrame PROC
	mov dl, 0
	mov dh, 0
	call GotoXY
	mov eax, green + green*16
	call SetTextColor
T:	mov al, ' '
	call WriteChar
	call incX
	cmp X, 78
	jb T
R:	mov al, ' '
	call WriteChar
	call incY
	cmp Y, 14
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
	mov eax, White + blue*16
	call SetTextColor
	ret
showFrame ENDP
;;;;;;;;;;;;;;;;;;;;;;change XY;;;;;;;;;;;;;;;;;
incX PROC
	mov dl, X
	mov dh, Y
	inc dl
	mov X, dl
	call GotoXY
	ret
incX ENDP
decX PROC
	mov dl, X
	mov dh, Y
	dec dl
	mov X, dl
	call GotoXY
	ret
decX ENDP
incY PROC
	mov dl, X
	mov dh, Y
	inc dh
	mov Y, dh
	call GotoXY
	ret
incY ENDP
decY PROC
	mov dl, X
	mov dh, Y
	dec dh
	mov Y, dh
	call GotoXY
	ret
decY ENDP

END main
