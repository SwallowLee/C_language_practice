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
	msgMenu	BYTE	"Menu", 0dh, 0ah,
					"1) Floating point calculation", 0dh, 0ah,
					"2) Simple control", 0dh, 0ah,
					"Please press a key to continue ¡K", 0
	msgA	BYTE	"Enter a: ", 0
	msgB	BYTE	"Enter b: ", 0
	msgC	BYTE	"Enter c: ", 0
	ans		BYTE	"(a*a+b*b)/c = ", 0
	oneFin	BYTE	"Press any key to turn back to menu.", 0
	fin		BYTE	"Student ID: 0416039", 0dh, 0ah,
					"Name: §õ¨Î¿P", 0dh, 0ah,
					"email address: girlannie123@gmail.com.", 0dh, 0ah,
					"Press any key to exit the program.", 0
	Onea	REAL8	?
	Oneb	REAL8	?
	Onec	REAL8	?
	X		BYTE	0
	Y		BYTE	0
	hide	DWORD	0
	array	DWORD	1200 DUP(0)
	temp	DWORD	60 DUP(0)
	cal		DWORD	0
	cal1	DWORD	0
	index1	DWORD	1
	index2	DWORD	1
.code

main PROC
L:	call ClrScr
	mov edx, OFFSET msgMenu
	call WriteString
L0: call ReadKey
	cmp al, '1'
	je L1
	cmp al, '2'
	je L2
	jmp L0
L1: call CalOne
	jmp L
L2: call CalTwo
	mov eax, white + black*16
	call SetTextColor
	call ClrScr
	mov edx, OFFSET fin
	call WriteString
	call ReadChar
	exit
main ENDP

CalOne PROC
	call ClrScr
	finit
	mov edx, OFFSET msgA
	call WriteString
	call ReadFloat
	fstp Onea
	mov edx, OFFSET msgB
	call WriteString
	call ReadFloat
	fstp Oneb
	mov edx, OFFSET msgC
	call WriteString
	call ReadFloat
	fstp Onec
;;;;;;;;;;;;;;;;;;; calculate ;;;;;;;;;;;;;;;;;;;;;;;
	finit
	fld Onea
	fld Onea
	fmul ST(0), ST(1)
	fstp Onea
	fld Oneb
	fld Oneb
	fmul ST(0), ST(1)
	fstp Oneb
	fld Onea
	fld Oneb
	fadd ST(0), ST(1)
	fstp Onea
	fld Onec
	fld Onea
	fdiv ST(0), ST(1)				
	mov edx, OFFSET ans
	call WriteString
	call WriteFloat
	call Crlf
	mov edx, OFFSET oneFin
	call WriteString
	call ReadChar
	ret
CalOne ENDP

CalTwo PROC
	mov eax, blue + blue*16
	call SetTextColor
	call ClrScr
	mov eax, gray + gray*16
	call SetTextColor
	call DrawFrame
	call Draw
;	mov ecx, 60
;	mov edx, 60
;L:  mov ebx, offset array
;	mov eax, [ebx + edx*4]
;	call WriteInt
;	inc edx
;	Loop L
;	call ReadInt
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
M0:	call RollW
	jmp L0
M1:	call RollA
	jmp L0
M2:	call RollS
	jmp L0
M3:	call RollD
	jmp L0
M4:	call draw
	jmp L0
M5:	cmp hide, 0
	je P1
	mov hide, 0
	mov eax, gray + gray*16
	call SetTextColor
	call DrawFrame
	jmp L0
P1: mov hide, 1
	mov eax, blue + blue*16
	call SetTextColor
	call DrawFrame
	jmp L0
M6:	ret
CalTwo ENDP

RollD PROC
	mov edx, 0
	mov ecx, 58
L0: mov eax, offset array
	mov esi, offset temp
	mov ebx, [eax + ecx*4]
	mov [esi + edx*4], ebx
	add ecx, 59
	inc edx
	cmp edx, 20
	jne L0
	mov index1, 57
	mov index2, 58
	mov cal, 0
L1: mov ecx, index1
	mov edx, index2
M:	mov eax, offset array
	mov ebx, [eax + ecx*4]
	mov [eax + edx*4], ebx
	add ecx, 59
	add edx, 59
	inc cal
	cmp cal, 20
	jne M
	mov cal, 0
	dec index1
	dec index2
	cmp index1, -1
	jne L1
	mov edx, 0
	mov ecx, 0
L2: mov eax, offset array
	mov esi, offset temp
	mov ebx, [esi + ecx*4]
	mov [eax + edx*4], ebx
	add edx, 59
	inc ecx
	cmp ecx, 20
	jne L2
	mov X, 1
	mov Y, 1
	mov dl, X
	mov dh, Y
	call GotoXY
	mov ecx, 0
L3: mov ebx, offset array
	mov eax, [ebx + ecx*4]
	call SetTextColor
	inc ecx
	mov al, ' '
	call WriteChar
	call incX
	cmp X, 60
	jne L3
	inc Y
	mov X, 1
	mov dl, X
	mov dh, Y
	call GotoXY
	cmp Y, 20
	jne L3
	ret
RollD ENDP

RollA PROC
	mov edx, 0
	mov ecx, 0
L0: mov eax, offset array
	mov esi, offset temp
	mov ebx, [eax + edx*4]
	mov [esi + ecx*4], ebx
	add edx, 59
	inc ecx
	cmp ecx, 20
	jne L0
	mov index1, 1
	mov index2, 0
	mov cal, 0
L1: mov ecx, index1
	mov edx, index2
M:	mov eax, offset array
	mov ebx, [eax + ecx*4]
	mov [eax + edx*4], ebx
	add ecx, 59
	add edx, 59
	inc cal
	cmp cal, 20
	jne M
	mov cal, 0
	inc index1
	inc index2
	cmp index1, 59
	jne L1
	mov edx, 58
	mov ecx, 0
L2: mov eax, offset array
	mov esi, offset temp
	mov ebx, [esi + ecx*4]
	mov [eax + edx*4], ebx
	add edx, 59
	inc ecx
	cmp ecx, 20
	jne L2
	mov X, 1
	mov Y, 1
	mov dl, X
	mov dh, Y
	call GotoXY
	mov ecx, 0
L3: mov ebx, offset array
	mov eax, [ebx + ecx*4]
	call SetTextColor
	inc ecx
	mov al, ' '
	call WriteChar
	call incX
	cmp X, 60
	jne L3
	inc Y
	mov X, 1
	mov dl, X
	mov dh, Y
	call GotoXY
	cmp Y, 20
	jne L3
	ret
RollA ENDP

RollS PROC
	mov edx, 0
	mov ecx, 1062
L0: mov esi, offset array
	mov eax, offset temp
	mov ebx, [esi + ecx*4]
	mov [eax + edx*4], ebx
	inc ecx
	inc edx
	cmp ecx, 1121
	jne L0
	mov ecx, 1120
	mov edx, 1061
L1: mov ebx, offset array
	mov eax, [ebx + edx*4]
	mov [ebx + ecx*4], eax
	dec ecx
	dec edx
	cmp edx, -1
	jne L1
	mov ecx, 0
L2: mov esi, offset array
	mov eax, offset temp
	mov ebx, [eax + ecx*4]
	mov [esi + ecx*4], ebx
	inc ecx
	cmp ecx, 59
	jne L2
	mov X, 1
	mov Y, 1
	mov dl, X
	mov dh, Y
	call GotoXY
	mov ecx, 0
L3: mov ebx, offset array
	mov eax, [ebx + ecx*4]
	call SetTextColor
	inc ecx
	mov al, ' '
	call WriteChar
	call incX
	cmp X, 60
	jne L3
	inc Y
	mov X, 1
	mov dl, X
	mov dh, Y
	call GotoXY
	cmp Y, 20
	jne L3
	ret
RollS ENDP

RollW PROC							
	mov ecx, 0
L0: mov ebx, offset array
	mov eax, offset temp
	mov edx, [ebx + ecx*4]
	mov [eax + ecx*4], edx
	inc ecx
	cmp ecx, 59
	jne L0
	mov ecx, 0
	mov edx, 59
L1: mov ebx, offset array
	mov eax, [ebx + edx*4]
	mov [ebx + ecx*4], eax
	inc ecx
	inc edx
	cmp edx, 1121
	jne L1
	mov ecx, 0
	mov edx, 1062
L2: mov esi, offset array
	mov eax, offset temp
	mov ebx, [eax + ecx*4]
	mov [esi + edx*4], ebx
	inc ecx
	inc edx
	cmp ecx, 59
	jne L2
	mov X, 1
	mov Y, 1
	mov dl, X
	mov dh, Y
	call GotoXY
	mov ecx, 0
L3: mov ebx, offset array
	mov eax, [ebx + ecx*4]
	call SetTextColor
	inc ecx
	mov al, ' '
	call WriteChar
	call incX
	cmp X, 60
	jne L3
	inc Y
	mov X, 1
	mov dl, X
	mov dh, Y
	call GotoXY
	cmp Y, 20
	jne L3
	ret
RollW ENDP

Draw PROC
	mov X, 1
	mov Y, 1
	mov dl, X
	mov dh, Y
	mov ecx, 0
	call GotoXY	
	call Randomize
L0:	call Random32
	and eax, 0ffh
	cmp ah, blue
	je L0
	mov ebx, offset array
	mov [ebx + ecx*4], eax
	call SetTextColor
	inc ecx
	mov al, ' '
	call WriteChar
	call incX
	cmp X, 60
	jne L0
	inc Y
	mov X, 1
	mov dl, X
	mov dh, Y
	call GotoXY
	cmp Y, 20
	jne L0
	ret
Draw ENDP

DrawFrame PROC
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
L1:	mov al, ' '
	call WriteChar
	call incY
	cmp Y, 20
	jne L1
L2:	mov al, ' '
	call WriteChar
	call decX
	cmp X, 0
	jne L2
L3:	mov al, ' '
	call WriteChar
	call decY
	cmp Y, 0
	jne L3
	ret
DrawFrame ENDP

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