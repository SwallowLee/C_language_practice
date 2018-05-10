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
	timer	DWORD	0
	speed	DWORD	1
	X	BYTE	0
	Y	BYTE	0
	XU	BYTE	0
	YU	BYTE	0
	XP	BYTE	0
	YP	BYTE	0
	msg		BYTE	"Student ID: 0416039", 0dh, 0ah,
					"Name: §õ¨Î¿P", 0dh, 0ah,
					"Email Address: girlannie123@gmail.com", 0dh, 0ah,
					"Press any key to exit the program.", 0
	maps	DWORD	1200 DUP(0)
	Pwin	BYTE	"Program win!", 0
	Uwin	BYTE	"User win!", 0
	Program	DWORD	0
	User	DWORD	0
	space	DWORD	0
	hole	DWORD	0
	up		DWORD	0
	down	DWORD	0
.code

main PROC
L:	mov timer, 0
	mov Program, 0
	mov User, 0
	mov space, 0
	mov hole, 0
	mov up, 1
	mov down, 0
	mov XU, 1
	mov YU, 1
	mov XP, 1
	mov YP, 19
	mov eax, gray + black*16
	call SetTextColor
	call ClrScr
	mov eax, gray + gray*16
	call SetTextColor
	call DrawFrame
	mov X, 1
	mov Y, 1
	mov dl, X
	mov dh, Y
	call GotoXY
	mov eax, yellow + yellow*16
	call SetTextColor
	mov al, ' '
	call WriteChar
	mov X, 1
	mov Y, 19
	mov dl, X
	mov dh, Y
	call GotoXY
	mov eax, black + red*16
	call SetTextColor
	mov al, ' '
	call WriteChar
	call drawMap

L0: mov al, XU
	mov X, al
	mov al, YU
	mov Y, al
	mov dl, X
	mov dh, Y
	call GotoXY
	mov eax, Yellow + Yellow*16
	call SetTextColor
	mov al, ' '
	call WriteChar
	mov al, XP
	mov X, al
	mov al, YP
	mov Y, al
	mov dl, X
	mov dh, Y
	call GotoXY
	mov eax, red + red*16
	call SetTextColor
	mov al, ' '
	call WriteChar
	call ReadKey
	cmp al, 't'
	je L1
	cmp al, 'f'
	je L2
	cmp al, 'g'
	je L3
	cmp al, 'h'
	je L4
	cmp al, 32
	je L5
	cmp al, 'z'
	je L
	cmp al, 27
	je Q
P:	call ProgramMove
	mov eax, 100
	call Delay
	jmp L0

L1: call MoveUp
	jmp L0
L2: call MoveLeft
	jmp L0
L3: call MoveDown
	jmp L0
L4: call MoveRight
	jmp L0
L5: cmp space, 0
	je M0
	mov space, 0
	jmp L0
M0: mov space, 1
	jmp L0
Q:	mov eax, white + black*16
	call SetTextColor
	call ClrScr
	mov edx, OFFSET msg
	call WriteString
	call ReadChar
	exit
main ENDP

ProgramMove PROC
	cmp space, 1
	je L4
	cmp XP, 59
	je L2
	mov eax, speed
	cmp timer, eax
	jne Q
	mov timer, 0
	movzx eax, YP
	dec eax
	mov ebx, 59
	mul ebx
	movzx ebx, XP
	dec ebx
	add eax, ebx
	inc eax
	mov esi, offset maps
	mov ebx, 1
	cmp [esi+eax*4], ebx
	je L1
	mov al, XP
	mov X, al
	mov al, YP
	mov Y, al
	mov dl, X
	mov dh, Y
	call GotoXY
	call DeleteAnimation
	mov eax, red + red*16
	call SetTextColor
	call incX
	inc XP
	mov al, ' '
	call WriteChar
	ret
L1:	cmp down, 0
	je L3
	cmp YP, 19
	je M0
	movzx eax, YP
	dec eax
	mov ebx, 59
	mul ebx
	movzx ebx, XP
	dec ebx
	add eax, ebx
	add eax, 59
	mov esi, offset maps
	mov ebx, 1
	cmp [esi+eax*4], ebx
	je L4
	mov al, XP
	mov X, al
	mov al, YP
	mov Y, al
	mov dl, X
	mov dh, Y
	call GotoXY
	call DeleteAnimation
	mov eax, red + red*16
	call SetTextColor
	call incY
	inc YP
	mov al, ' '
	call WriteChar
	ret
M0: mov down, 0
	mov up, 1
	ret
L3:	cmp up, 0
	je L4
	cmp YP, 1
	je M1
	movzx eax, YP
	dec eax
	mov ebx, 59
	mul ebx
	movzx ebx, XP
	dec ebx
	add eax, ebx
	sub eax, 59
	mov esi, offset maps
	mov ebx, 1
	cmp [esi+eax*4], ebx
	je L4
	mov al, XP
	mov X, al
	mov al, YP
	mov Y, al
	mov dl, X
	mov dh, Y
	call GotoXY
	call DeleteAnimation
	mov eax, red + red*16
	call SetTextColor
	call decY
	dec YP
	mov al, ' '
	call WriteChar
L4:	ret
M1: mov down, 1
	mov up, 0
	ret
Q:	inc timer
	ret
L2: call ProgramWin
	ret
ProgramMove ENDP

MoveLeft PROC
	cmp XU, 1
	je L1
	mov eax, white + black*16
	call SetTextColor
	movzx eax, YU
	dec eax
	mov ebx, 59
	mul ebx
	movzx ebx, XU
	dec ebx
	add eax, ebx
	dec eax
	mov esi, offset maps
	mov ebx, 1
	cmp [esi+eax*4], ebx
	je L1
	mov al, XU
	mov X, al
	mov al, YU
	mov Y, al
	mov dl, X
	mov dh, Y
	call GotoXY
	call DeleteAnimation
	mov eax, Yellow + Yellow*16
	call SetTextColor
	call decX
	dec XU
	mov al, ' '
	call WriteChar
L1:	ret
MoveLeft ENDP

MoveRight PROC
	cmp space, 1
	je L1
	cmp XU, 59
	je L2
	movzx eax, YU
	dec eax
	mov ebx, 59
	mul ebx
	movzx ebx, XU
	dec ebx
	add eax, ebx
	inc eax
	mov esi, offset maps
	mov ebx, 1
	cmp [esi+eax*4], ebx
	je L1
	mov al, XU
	mov X, al
	mov al, YU
	mov Y, al
	mov dl, X
	mov dh, Y
	call GotoXY
	call DeleteAnimation
	mov eax, Yellow + Yellow*16
	call SetTextColor
	call incX
	inc XU
	mov al, ' '
	call WriteChar
	cmp XU, 59
	je L2
L1:	ret
L2: call UserWin
	ret
MoveRight ENDP

MoveUp PROC
	cmp space, 1
	je L1
	cmp YU, 1
	je L1
	movzx eax, YU
	dec eax
	mov ebx, 59
	mul ebx
	movzx ebx, XU
	dec ebx
	add eax, ebx
	sub eax, 59
	mov esi, offset maps
	mov ebx, 1
	cmp [esi+eax*4], ebx
	je L1
	mov al, XU
	mov X, al
	mov al, YU
	mov Y, al
	mov dl, X
	mov dh, Y
	call GotoXY
	call DeleteAnimation
	mov eax, Yellow + Yellow*16
	call SetTextColor
	call decY
	dec YU
	mov al, ' '
	call WriteChar
L1:	ret
MoveUp ENDP

MoveDown PROC
	cmp space, 1
	je L1
	cmp YU, 19
	je L1
	movzx eax, YU
	dec eax
	mov ebx, 59
	mul ebx
	movzx ebx, XU
	dec ebx
	add eax, ebx
	add eax, 59
	mov esi, offset maps
	mov ebx, 1
	cmp [esi+eax*4], ebx
	je L1
	mov al, XU
	mov X, al
	mov al, YU
	mov Y, al
	mov dl, X
	mov dh, Y
	call GotoXY
	call DeleteAnimation
	mov eax, Yellow + Yellow*16
	call SetTextColor
	call incY
	inc YU
	mov al, ' '
	call WriteChar
L1:	ret
MoveDown ENDP

DeleteAnimation PROC
	mov eax, black + black*16
	call SetTextColor
	mov al, ' '
	call WriteChar
	ret
DeleteAnimation ENDP

ProgramWin PROC
	cmp User, 1
	je L1
	mov Program, 1
	mov X, 25
	mov Y, 0
	mov dl, X
	mov dh, Y
	call GotoXY
	mov eax, blue + yellow*16
	call SetTextColor
	mov edx, OFFSET Pwin
	call WriteString
L1:	ret
ProgramWin ENDP

UserWin PROC
	cmp Program, 1
	je L1
	mov User, 1
	mov X, 25
	mov Y, 0
	mov dl, X
	mov dh, Y
	call GotoXY
	mov eax, blue + yellow*16
	call SetTextColor
	mov edx, OFFSET Uwin
	call WriteString
L1:	ret
UserWin ENDP

drawMap PROC					
	call Randomize
	mov ecx, 3
	mov esi, offset maps
L0:	mov edi, ecx
M:	mov ebx, 1
	mov [esi + edi*4], ebx
	add edi, 59
	cmp edi, 1121
	jb M
M0:	mov eax, 19
	call RandomRange
	mov ebx, 59
	mul ebx
	add eax, ecx
	mov ebx, 0
	cmp [esi + eax*4], ebx
	je M0

	mov [esi + eax*4], ebx
	inc hole
	cmp hole, 2
	jne M0
	mov hole, 0
	add ecx, 2
	cmp ecx, 59
	jne L0
	
	mov eax, black + gray*16
	call SetTextColor
	mov X, 1
	mov Y, 1
	mov dl, X
	mov dh, Y
	call GotoXY
	mov esi, offset maps
	mov ecx, 0
L1: mov bl, 0
	cmp [esi + ecx*4], bl
	je P0
	mov al, ' '
	call WriteChar
	call incX
	inc ecx
	cmp X, 60
	je W
	jmp L1
P0:	inc ecx
	call incX
	cmp X, 60
	je W
	jmp L1
W:	mov X, 1
	inc Y
	mov dl, X
	mov dh, Y
	call GotoXY
	cmp Y, 20
	jne L1
	ret
drawMap ENDP

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
	mov dh, Y
	call GotoXY
	ret
incX ENDP

incY PROC
	inc Y
	mov dl, X
	mov dh, Y
	call GotoXY
	ret
incY ENDP

decX PROC
	dec X
	mov dl, X
	mov dh, Y
	call GotoXY
	ret
decX ENDP

decY PROC
	dec Y
	mov dl, X
	mov dh, Y
	call GotoXY
	ret
decY ENDP

END main

