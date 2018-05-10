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
	msg1	BYTE	"1) Floating point calculation", 0dh, 0ah,
					"2) Simple control", 0
	msg11	BYTE	"Enter a: ", 0
	msg12	BYTE	"Enter b: ", 0
	msg13	BYTE	"Enter c: ", 0
	msg1ans	BYTE	"a+b*c = ", 0
	msg1end	BYTE	"Press any key to turn back to menu.", 0
	msg		BYTE	"Thanks.", 0dh, 0ah,
					"Press any key to quit.", 0
	inputa		REAL8	?
	inputb		REAL8	?
	inputc		REAL8	?
	X			BYTE	0
	Y			BYTE	0
	hide		DWORD	0
.code

main PROC
L:  call ClrScr
	mov edx, OFFSET msg1
	call WriteString
L0: call ReadKey
	cmp al, '1'
	je L1
	cmp al, '2'
	je L2
	jmp L0
L1: call ClrScr
	mov edx, OFFSET msg11
	call WriteString
	call ReadFloat
	fstp inputa
	mov edx, OFFSET msg12
	call WriteString
	call ReadFloat
	fstp inputb
	mov edx, OFFSET msg13
	call WriteString
	call ReadFloat
	fstp inputc
	finit
	fld inputb
	fld inputc
	fmul ST(0), ST(1)
	fld	inputa
	fadd ST(0), ST(1)
	fstp inputa
	mov edx, OFFSET msg1ans
	call WriteString
	fld inputa
	call Writefloat
	call Crlf
	mov edx, OFFSET msg1end
	call WriteString
	call ReadChar
	jmp L
L2: call control
	call Crlf
	mov edx, OFFSET msg
	call WriteString
	call ReadChar
	exit
main ENDP

control PROC
	mov eax, gray + gray*16
	call SetTextColor
	call ClrScr
	mov eax, blue + blue*16
	call SetTextColor
	call drawframe
	call draw
L0: call ReadKey
	cmp al, 'w'
	je M0
	cmp al, 'a'
	je M1
	cmp al, 's'
	je M2
	cmp al, 'd'
	je M3
	cmp al, 'm'
	je M4
	cmp al, 'h'
	je M5
	cmp al, 'q'
	je M6
	jmp L0
M0:
M1:
M2:
M3:
M4: call draw
	jmp L0
M5: cmp hide, 0
	je P0
	mov hide, 0
	mov eax, blue + blue*16
	call SetTextColor
	call drawFrame
	jmp L0
P0: mov hide, 1
	mov eax, gray + gray*16
	call SetTextColor
	call drawFrame
	jmp L0
M6: ret
control ENDP

draw PROC
	mov X, 1
	mov Y, 1
	mov dl, X
	mov dh, Y
	call GotoXY
	call Randomize
M0:	call Random32
	call SetTextColor
	mov al, ' '
	call WriteChar
	call incX
	cmp X, 59
	jne M0
	inc Y
	mov X, 0
	mov dl, X
	mov dh, Y
	cmp Y, 20
	jne M0
	ret
draw ENDP

drawframe PROC
	mov X, 0
	mov Y, 0
	mov dl, X
	mov dh, Y
	call GotoXY
L0:	mov al, ' '
	call WriteChar
	call incX
	cmp X, 60
	jne L0
L1: mov al, ' '
	call WriteChar
	call incY
	cmp Y, 20
	jne L1
L2: mov al, ' '
	call WriteChar
	call decX
	cmp X, 0
	jne L2
L3: mov al, ' '
	call WriteChar
	call decY
	cmp Y, 0
	jne L3
	ret
drawframe ENDP

incX PROC
	inc X
	mov dl, X
	call GotoXY
	ret
incX ENDP

incY PROC
	inc Y
	mov dh, Y
	call GotoXY
	ret
incY ENDP

decX PROC
	dec X
	mov dl, X
	call GotoXY
	ret
decX ENDP

decY PROC
	dec Y
	mov dh, Y
	call GotoXY
	ret
decY ENDP

END main
