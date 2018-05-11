
;========================================================
; Student Name: §õ¨Î¿P
; Student ID: 0416039
; Email: girlannie123@gmail.com
;========================================================
; Instructor: Sai-Keung WONG
; Email: cswingo@cs.nctu.edu.tw
; Room: 706
; Assembly Language 
;========================================================
; Description:
;
; IMPORTANT: always save EBX, EDX, EDI and ESI as their
; values are preserved by the callers in C calling convention.
;

INCLUDE Irvine32.inc
INCLUDE Macros.inc

invisibleDigitX  TEXTEQU %(-100000)
invisibleDigitY  TEXTEQU %(-100000)

; PROTO C is to make agreement on calling convention for INVOKE

c_updatePositionsOfAllObjects PROTO C

.data 
colors BYTE 01ch
colorOriginal BYTE 01ch

MYINFO	BYTE "My Student Name: §õ¨Î¿P StudentID: 0416039",0 

OpenMsgDelay	DWORD	25
EnterStageDelay	DWORD	50

MyMsg BYTE "Final Project for Assembly Language...",0dh, 0ah
BYTE "My Student Name: §õ¨Î¿P",0dh, 0ah 
BYTE "My student ID: 0416039.", 0dh, 0ah, 0dh, 0ah
BYTE "My Email is: girlannie123@gmail.com.", 0dh, 0ah, 0dh, 0ah
BYTE "Make sure the screen dimension is (120, 30).", 0dh, 0ah, 0dh, 0ah
BYTE "Key usages:", 0dh, 0ah
BYTE "x (flip), y (flip)", 0dh, 0ah
BYTE "w (gray), g (grid)", 0dh, 0ah
BYTE "a (reset), b (blue)", 0dh, 0ah
BYTE "1-5: point size", 0dh, 0ah
BYTE "8:2x4, 9:4x8, 0:8x8", 0dh, 0ah
BYTE "< (blending), > (blending)", 0

EnterSpeed	BYTE	0dh, 0ah, "Enter the maximum speed of a digit (integer): ", 0
EnterSpaceX	BYTE	"Enter the spacing for the blocks along the X-axis (integer): ", 0
EnterSpaceY	BYTE	"Enter the spacing for the blocks along the Y-axis (integer): ", 0

EndingMsg BYTE "Thanks for playing.", 0
side1	DWORD	0
side2	DWORD	0
side3	DWORD	0
side4	DWORD	0
side11	DWORD	0
side22	DWORD	0
side33	DWORD	0
side44	DWORD	0
start	DWORD	0
partX	DWORD	0
partY	DWORD	0
EnterX1	DWORD	0
EnterY1	DWORD	0
EnterX2	DWORD	0
EnterY2	DWORD	0
timer	DWORD	0
grid	DWORD	0
game	DWORD	0
count	DWORD	1
direct	DWORD	0
speed	DWORD	70
spaceX	DWORD	2000
spaceY	DWORD	2000
X1		DWORD	0
Y1		DWORD	0
set		DWORD	0
Index	DWORD	?
windowWidth		DWORD 8000
windowHeight	DWORD 8000

scaleFactor	DWORD	128
canvasMinX	DWORD -4000
canvasMaxX	DWORD 4000
canvasMinY	DWORD -4000
canvasMaxY	DWORD 4000
;
particleRangeMinX REAL8 0.0
particleRangeMaxX REAL8 0.0
particleRangeMinY REAL8 0.0
particleRangeMaxY REAL8 0.0
;
tmpParticleY DWORD ?
;
particleSize DWORD  2
numParticles DWORD 20000
particleMaxSpeed DWORD 3

showID		DWORD	0
flgQuit		DWORD	0
numObjects	DWORD	1024
objPosX		SDWORD	512 DUP(0)
objPosY		SDWORD	512 DUP(0)
objTypes	BYTE	512 DUP(1)
objSpeedX	SDWORD	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
			SDWORD	512 DUP(?)
objSpeedY	SDWORD	2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
			SDWORD	512 DUP(?)			
objColor	DWORD	0, 254, 254,
					254, 254, 254,
					0, 127, 0,
					1024 DUP(255)
studentObjColor	DWORD	1024 DUP(?)
goMsg		BYTE "Final Project for Assembly Language. Let's start...", 0
bell		BYTE 0,0, 0
					
testDBL	REAL4	3.141592654
zero REAL8 0.0

studentIDDigit DWORD 0
;studentID	DWORD 0, 1, 2, 3, 4, 5, 6

particleState BYTE 0
negOne REAL8 -1.0

DIGIT_ALL		BYTE 1, 1, 1, 1
				BYTE 1, 1, 1, 1
				BYTE 1, 1, 1, 0dh
				BYTE 1, 1, 1, 1
				BYTE 1, 1, 1, 1

DIGIT_MO_0		BYTE 0, 0, 1, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0ffh
DIGIT_MO_SIZE = ($-DIGIT_MO_0)				
DIGIT_MO_1		BYTE 0, 1, 1, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0ffh
				
DIGIT_MO_2		BYTE 1, 1, 1, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0ffh
				
DIGIT_MO_3		BYTE 1, 1, 1, 0dh
				BYTE 1, 0, 0, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0ffh
				
DIGIT_MO_4		BYTE 1, 1, 1, 0dh
				BYTE 1, 0, 0, 0dh
				BYTE 1, 0, 0, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0ffh
				
DIGIT_MO_5		BYTE 1, 1, 1, 0dh
				BYTE 1, 0, 0, 0dh
				BYTE 1, 1, 0, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0ffh
				
DIGIT_MO_6		BYTE 1, 1, 1, 0dh
				BYTE 1, 0, 0, 0dh
				BYTE 1, 1, 1, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0ffh

DIGIT_MO_7		BYTE 1, 1, 1, 0dh
				BYTE 1, 0, 0, 0dh
				BYTE 1, 1, 1, 0dh
				BYTE 0, 0, 1, 0dh
				BYTE 0, 0, 0, 0ffh

DIGIT_MO_8		BYTE 1, 1, 1, 0dh
				BYTE 1, 0, 0, 0dh
				BYTE 1, 1, 1, 0dh
				BYTE 0, 0, 1, 0dh
				BYTE 0, 0, 1, 0ffh

				
DIGIT_MO_9		BYTE 1, 1, 1, 0dh
				BYTE 1, 0, 0, 0dh
				BYTE 1, 1, 1, 0dh
				BYTE 0, 0, 1, 0dh
				BYTE 0, 1, 1, 0ffh

DIGIT_MO_10		BYTE 1, 1, 1, 0dh
				BYTE 1, 0, 0, 0dh
				BYTE 1, 1, 1, 0dh
				BYTE 0, 0, 1, 0dh
				BYTE 1, 1, 1, 0ffh
				
DIGIT_MO_11		BYTE 1, 1, 1, 0dh
				BYTE 1, 0, 1, 0dh
				BYTE 1, 1, 1, 0dh
				BYTE 1, 0, 1, 0dh
				BYTE 1, 1, 1, 0ffh
				
DIGIT_MO_12		BYTE 1, 1, 1, 0dh
				BYTE 1, 1, 1, 0dh
				BYTE 1, 1, 1, 0dh
				BYTE 1, 0, 1, 0dh
				BYTE 1, 1, 1, 0ffh
				
DIGIT_MO_13		BYTE 1, 1, 1, 0dh
				BYTE 1, 1, 1, 0dh
				BYTE 1, 1, 1, 0dh
				BYTE 1, 1, 1, 0dh
				BYTE 1, 1, 1, 0ffh
												
DIGIT_INDEX		DWORD	0
TOTALDIGITS		DWORD	13


DIGIT_0			BYTE 1, 1, 1, 0dh
				BYTE 1, 0, 1, 0dh
				BYTE 1, 0, 1, 0dh
				BYTE 1, 0, 1, 0dh
				BYTE 1, 1, 1, 0ffh
DIGIT_SIZE = ($-DIGIT_0)				
DIGIT_1			BYTE 0, 1, 0, 0dh
				BYTE 0, 1, 0, 0dh
				BYTE 0, 1, 0, 0dh
				BYTE 0, 1, 0, 0dh
				BYTE 0, 1, 0, 0ffh
				
DIGIT_2			BYTE 1, 1, 1, 0dh
				BYTE 0, 0, 1, 0dh
				BYTE 1, 1, 1, 0dh
				BYTE 1, 0, 0, 0dh
				BYTE 1, 1, 1, 0ffh
				
StudentID		BYTE 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0
				BYTE 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0
				BYTE 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0
				BYTE 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0
				BYTE 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0
stage				DWORD 0
currentDigit			DWORD 0
objPosForOneDigitX	SDWORD 1000 DUP(0)
objPosForOneDigitY	SDWORD 1000 DUP(0)
digitX SDWORD -8000
digitY SDWORD 25000
digitTimer DWORD 0
colorTimer DWORD 0
colorIndex DWORD 0

offsetImage DWORD 0

digitOffsetX DWORD 0
digitSpacingDFTWidth DWORD	2000
digitSpacingDFTHeight DWORD 2000

digitSpacingWidth DWORD	2000
digitSpacingHeight DWORD 2000

digitMaxSpeed DWORD 10
digitMaxDFTSpeed DWORD 10

digitWidth DWORD 0

totalColors	DWORD	0
colorRed	BYTE	10000 DUP(0)
colorGreen	BYTE	10000 DUP(0)
colorBlue	BYTE	10000 DUP(0)

openingMsg	BYTE	"This program shows the student ID using bitmap and manipulates images....", 0dh
			BYTE	"Great programming.", 0
movementDIR	BYTE 0
state		BYTE	0

imagePercentage DWORD	0

exist	DWORD	0
mImageStatus DWORD 0
temp BYTE 200000 DUP(?)
initial	DWORD	0
mImagePtr0 BYTE 200000 DUP(?)
mImagePtr1 BYTE 200000 DUP(?)
mImagePtr2 BYTE 200000 DUP(?)
mTmpBuffer	BYTE	200000 DUP(?)
mImageWidth DWORD 0
mImageHeight DWORD 0
mBytesPerPixel DWORD 0
mImagePixelPointSize DWORD 3

mFlipX DWORD 0
mFlipY DWORD 1
mEnableBrighter DWORD 0
mAmountOfBrightness DWORD 1
mBrightnessDirection DWORD 0

				;x, y, width, height	
mSubImage		DWORD	0, 0, 30, 30
mShowAtLocation	DWORD	30, 30
;
;

;width and height
GridDimensionW	DWORD	8
GridDimensionH	DWORD	8
GridCellW			DWORD	1
GridCellH			DWORD	1
CurGridX		DWORD	0
CurGridY		DWORD	0
flgPickedGrid	DWORD	0
PickedGridX		DWORD	-1
PickedGridY		DWORD	-1

OldPickedGridX		DWORD	-1
OldPickedGridY		DWORD	-1

GridColorRed		BYTE	0
GridColorGreen		BYTE	0
GridColorBlue		BYTE	0


FlgSaveImage		BYTE	0
FlgRestoreImage		BYTE	0
FlgShowGrid			BYTE	0	;2
FlgYellowFlower		BYTE	0	;3
FlgBrigtenImage		BYTE	0	;4
FlgDarkenImage		BYTE	0	;5
FlgGrayLevelImage	BYTE	0	;6
gray1				DWORD	0

programState		BYTE	0

.code

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_InitializeApp()
;
;This function is called
;at the beginning of the program.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_InitializeApp PROC C USES ebx edi esi edx
	mov al, blue + white*16
	or al, 88h
	mov ah, 080h
	call SetTextColor
	mov dl, 0
	mov dh, 16
	mov edi, offset openingMsg
	call gotoxy
P0: mov al, [edi]
	call writechar
	;mov eax, 25
	mov eax, 1
	call delay
	mov al, [edi]
	inc edi
	cmp al, 0
	je P1
	cmp al, 0dh
	jne P0
	inc dh
	call gotoxy
	jmp P0
P1: mov eax, green + black*16
	call SetTextColor
	mov edx, offset EnterSpeed
	call WriteString
	call ReadInt
	cmp eax, 0
	je L0
	mov speed, eax
L0:	mov eax, blue + white*16
	call SetTextColor
	mov edx, offset EnterSpaceX
	call WriteString
	call ReadInt
	cmp eax, 0
	je L1
	mov spaceX, eax
L1:	mov edx, offset EnterSpaceY
	call WriteString
	call ReadInt
	cmp eax, 0
	je L2
	mov spaceY, eax
L2:	ret
asm_InitializeApp ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void setCursor(int x, int y)
;
;Set the position of the cursor 
;in the console (text) window.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
setCursor PROC C USES edx,
	x:DWORD, y:DWORD
	mov edx, y
	shl edx, 8
	xor edx, x
	call Gotoxy
	ret
setCursor ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_ClearScreen()
;
;Clear the screen.
;We can set text color if you want.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_ClearScreen PROC C
	mov al, 0
	mov ah, 0
	call SetTextColor
	call clrscr
	ret
asm_ClearScreen ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_ShowTitle()
;
;Show the title of the program
;at the beginning.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_ShowTitle PROC C USES edx
	INVOKE setCursor, 0, 0
	xor eax, eax
	mov ah, 0h
	mov al, 0e1h
	call SetTextColor
	mov edx, offset MyMsg
	call WriteString
	ret
asm_ShowTitle ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_InitObjects()
;
;Initialize the objects,
;including the speed, colors, etc.
;That're up to you (programmers).
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_InitObjects PROC C
	mov ecx, 512
	mov ebx, 0
L:	mov esi, offset objPosX
	mov eax, -2000
	mov [esi + ebx], eax
	mov esi, offset objPosY
	mov eax, 25000
	mov [esi + ebx], eax
	add ebx, 4
	Loop L
	ret
asm_InitObjects ENDP	

asm_computeCircularPosX PROC C
	fld testDBL
	ret
asm_computeCircularPosX ENDP

asm_GetNumParticles PROC C
mov eax, numParticles
ret
asm_GetNumParticles ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_GetParticleMaxSpeed PROC C
mov eax, particleMaxSpeed
ret
asm_GetParticleMaxSpeed ENDP

;int asm_GetParticleSize()
;
;Return the particle size.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_GetParticleSize PROC C
	mov eax, 2
	ret
asm_GetParticleSize ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_handleMousePassiveEvent( int x, int y )
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_handleMousePassiveEvent PROC C USES eax ebx edx,
	x : DWORD, y : DWORD
	mov eax, x
	mWrite "x:"
	call WriteDec
	mWriteln " "
	mov eax, y
	mWrite "y:"
	call WriteDec
	mWriteln " "

	cmp grid, 0
	jne L0
	mov eax, x
	xor edx, edx
	mov ebx, 200
	div ebx
	mov partX, eax
	mov eax, y
	mov ebx, 800
	sub ebx, eax
	mov eax, ebx
	mov ebx, 400
	xor edx, edx
	div ebx
	mov partY, eax
	jmp L2
L0:	cmp grid, 1
	jne L1
	mov eax, x
	xor edx, edx
	mov ebx, 100
	div ebx
	xor edx, edx
	mov partX, eax
	mov eax, y
	mov ebx, 800
	sub ebx, eax
	mov eax, ebx
	mov ebx, 200
	div ebx
	mov partY, eax
	jmp L2

L1:	cmp grid, 2
	jne L2
	xor edx, edx
	mov eax, x
	mov ebx, 100
	div ebx
	xor edx, edx
	mov partX, eax
	mov eax, y
	mov ebx, 800
	sub ebx, eax
	mov eax, ebx
	mov ebx, 100
	div ebx
	mov partY, eax

L2:	mov eax, partX
	call WriteInt
	mov eax, partY
	call WriteInt
	mWrite"!!!!"
	ret
asm_handleMousePassiveEvent ENDP



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_handleMouseEvent(int button, int status, int x, int y)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_handleMouseEvent PROC C USES ebx,
	button : DWORD, status : DWORD, x : DWORD, y : DWORD
	
	mWriteln "asm_handleMouseEvent"
	mov eax, button
	mWrite "button:"
	call WriteDec
	mWriteln " "
	mov eax, status
	mWrite "status:"
	call WriteDec
	mov eax, x
	mWriteln " "
	mWrite "x:"
	call WriteDec
	mWriteln " "
	mov eax, y
	mWrite "y:"
	call WriteDec
	mWriteln " "
	mov eax, windowWidth
	mWrite "windowWidth:"
	call WriteDec
	mWriteln " "
	mov eax, windowHeight
	mWrite "windowHeight:"
	call WriteDec
	mWriteln " "
	jmp exit0	

	cmp timer, 0
	jne L0
	mov timer, 1
	mov EnterX2, 0
	mov EnterY2, 0
	xor edx, edx
	mov eax, x
	mov ebx, 100
	div ebx
	xor edx, edx
	mov EnterX1, eax
	mov eax, y
	mov ebx, 800
	sub ebx, eax
	mov eax, ebx
	mov ebx, 100
	div ebx
	mov EnterY1, eax
	mov start, 1
	jmp exit0
L0:	cmp timer, 1
	jne exit0
	mov timer, 0
	xor edx, edx
	mov eax, x
	mov ebx, 100
	div ebx
	xor edx, edx
	mov EnterX2, eax
	mov eax, y
	mov ebx, 800
	sub ebx, eax
	mov eax, ebx
	mov ebx, 100
	div ebx
	mov EnterY2, eax
	
exit0:
	ret
asm_handleMouseEvent ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;int asm_HandleKey(int key)
;
;Handle key events.
;Return 1 if the key has been handled.
;Return 0, otherwise.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_HandleKey PROC C, 
	key : DWORD
	mov eax, key
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	cmp al, '1'
	jne L2
	mov mImagePixelPointSize, 1
	mov state, 0
	ret
L2:	cmp al, '2'
	jne L3
	mov mImagePixelPointSize, 2
	mov state, 0
	ret
L3:	cmp al, '3'
	jne L4
	mov mImagePixelPointSize, 3
	mov state, 0
	ret
L4:	cmp al, '4'
	jne L5
	mov mImagePixelPointSize, 4
	mov state, 0
	ret
L5:	cmp al, '5'
	jne L6
	mov mImagePixelPointSize, 5
	mov state, 0
	ret
L6:	cmp al, 'y'
	jne L7
	call UpsideDown
	mov state, 0
	ret
L7: cmp al, 'x'
	jne L8
	call horizon
	mov state, 0
	ret
L8: cmp al, 'a'
	jne L9
	mov gray1, 0
	mov count, 1
	mov state, 0
	ret
L9: cmp al, 'i'
	jne L10
	mov showID, 1
	mov state, 0
	ret
L10:cmp al, 'l'
	jne L11
	mov showID, 1
	mov state, 0
	ret
L11:cmp al, 's'
	jne L12
	cmp gray1, 0
	je M
	mov gray1, 0
	mov count, 0
	mov state, 0
	ret
M:  mov gray1, 1
	mov state, 0
	ret
L12:cmp al, 'g'
	jne L13
	cmp game, 0
	je M1
	mov game, 0
	mov count, 1
	mov state, 0
	ret
M1: mov game, 1
	mov count, 1
	mov state, 0
	ret
L13:cmp al, '8'
	jne L14
	mov grid, 0
	mov state, 0
	ret
L14:cmp al, '9'
	jne L15
	mov grid, 1
	mov state, 0
	ret
L15:cmp al, '0'
	jne L16
	mov grid, 2
	mov state, 0
	ret
L16:cmp al, 27 ; ESC
	jne L1
	mov al, white + blue*16
	mov ah, 01h
	call SetTextColor
	mWriteLn "Thanks for playing..."
	mWriteLn "My student name is §õ¨Î¿P"
	mWriteLn "My student ID is: 0416039."
	
	mWriteLn "Press ENTER to quit."
	call ReadInt
	exit
	mov state, 0
L1:
exit0:
	mov eax, 0
	ret
asm_HandleKey ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_EndingMessage()
;
;This function is called
;when the program exits.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_EndingMessage PROC C
	mov ah, 0h
	mov al, 0e1h
	call SetTextColor
	mov edx, offset EndingMsg
	call WriteString
	ret
asm_EndingMessage ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_SetWindowDimension(int w, int h, int scaledWidth, int scaledHeight)
;
;w: window resolution (i.e. number of pixels) along the x-axis.
;h: window resolution (i.e. number of pixels) along the y-axis. 
;scaledWidth : scaled up width
;scaledHeight : scaled up height
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_SetWindowDimension PROC C USES ebx,
	w: DWORD, h: DWORD, scaledWidth : DWORD, scaledHeight : DWORD
	mov ebx, offset windowWidth
	mov eax, w
	mov [ebx], eax
	mov eax, scaledWidth
	shr eax, 1	; divide by 2, i.e. eax = eax/2
	mov ebx, offset canvasMaxX
	mov [ebx], eax
	neg eax
	mov ebx, offset canvasMinX
	mov [ebx], eax
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	mov ebx, offset windowHeight
	mov eax, h
	mov [ebx], eax
	mov eax, scaledHeight
	shr eax, 1	; divide by 2, i.e. eax = eax/2
	mov ebx, offset canvasMaxY
	mov [ebx], eax
	neg eax
	mov ebx, offset canvasMinY
	mov [ebx], eax
	;
	finit
	fild canvasMinX
	fstp particleRangeMinX
	;
	finit
	fild canvasMaxX
	fstp particleRangeMaxX
	;
	finit
	fild canvasMinY
	fstp particleRangeMinY
	;
	finit
	fild canvasMaxY
	fstp particleRangeMaxY	
	;
	ret
asm_SetWindowDimension ENDP	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;int asm_GetNumOfObjects()
;
;Return the number of objects
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_GetNumOfObjects PROC C
	mov eax, numObjects
	ret
asm_GetNumOfObjects ENDP	

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;int asm_GetObjectType(int objID)
;
;Return the object type
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_GetObjectType		PROC C USES ebx edx,
	objID: DWORD
	push ebx
	push edx
	xor eax, eax
	mov edx, offset objTypes
	mov ebx, objID
	mov al, [edx + ebx]
	pop edx
	pop ebx
	ret
asm_GetObjectType		ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_GetObjPosX		PROC C
mov eax,objPosX
ret
asm_GetObjPosX		ENDP

asm_GetObjPosY		PROC C
mov eax,objPosY
ret
asm_GetObjPosY		ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_GetObjectColor (int &r, int &g, int &b, int objID)
;Input: objID, the ID of the object
;
;Return the color three color components
;red, green and blue.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_GetObjectColor  PROC C USES ebx edi esi,
	r: PTR DWORD, g: PTR DWORD, b: PTR DWORD, objID: DWORD
;	
	mov esi, offset ObjColor
	mov eax, objID
	mov ebx, 12
	mul ebx
	add esi, eax
	mov eax, [esi]
	mov edi, r
	mov DWORD PTR [edi], eax
	;
	add esi, 4
	mov eax, [esi]
	mov edi, g
	mov DWORD PTR [edi], eax
	;
	add esi, 4
	mov eax, [esi]
	mov edi, b
	mov DWORD PTR [edi], eax
	ret
;
asm_GetObjectColor ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;int asm_ComputeRotationAngle(a, b)
;return an angle*10.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_ComputeRotationAngle PROC C USES ebx,
	a: DWORD, b: DWORD
	mov ebx, b
	shl ebx, 1
	mov eax, a
	add eax, 10
	ret
asm_ComputeRotationAngle ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;int asm_ComputePositionX(int x, int objID)
;
;Return the x-coordinate.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_ComputePositionX PROC C USES edi esi,
	x: DWORD, objID: DWORD
	mov ebx, objID
	mov esi, offset objPosX
	mov eax, [esi+ebx*4]
	ret
asm_ComputePositionX ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;int asm_ComputePositionY(int y, int objID)
;
;Return the y-coordinate.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_ComputePositionY PROC C USES ebx esi edx,
	y: DWORD, objID: DWORD
	mov ebx, objID
	mov esi, offset objPosY
	mov eax, [esi+ebx*4]
	ret
asm_ComputePositionY ENDP

ASM_setText PROC C
	;mov al, 0e1h
	mov al, 01eh
	call SetTextColor
	ret
ASM_setText ENDP

asm_ComputeParticlePosX PROC C,
xPtr : PTR REAL8
ret
asm_ComputeParticlePosX ENDP

;
asm_ComputeParticlePosY PROC C,
x : DWORD, yPtr : PTR REAL8, yVelocityPtr : PTR REAL8
ret
asm_ComputeParticlePosY ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_updateSimulationNow()
;
;Update the simulation.
;For examples,
;we can update the positions of the objects.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_updateSimulationNow PROC C USES edi esi ebx
call updateGame
update0:
	INVOKE c_updatePositionsOfAllObjects
	ret
asm_updateSimulationNow ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_SetImageInfo PROC C USES esi edi ebx esi edx,
imageIndex : DWORD,
imagePtr : PTR BYTE, w : DWORD, h : DWORD, bytesPerPixel : DWORD
mov edi, offset mimageWidth
	mov eax, w
	mov [edi], eax
	mov edi, offset mimageHeight
	mov eax, h
	mov [edi], eax
	mov edi, offset mbytesperpixel
	mov eax, bytesperpixel
	mov [edi], eax
	mov ebx, imageIndex
	mov index, ebx
	mov ebx, 0
	cmp imageIndex, ebx
	je M0
	mov esi, imageptr
	mov edi, offset mimageptr1
	jmp M1
M0:	mov esi, imageptr
	mov edi, offset mimageptr0
M1:	mov eax, w
	mov ebx, h
	add ebx, h
	add ebx, h
	mul ebx
	mov ecx, eax
	;call writedec
L1:
	mov eax, [esi]
	mov [edi], eax
	inc esi
	inc edi
	dec ecx
	cmp ecx, 0
	jg L1
	
	ret
asm_SetImageInfo ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

asm_GetImagePixelSize PROC C
mov eax, mImagePixelPointSize
ret
asm_GetImagePixelSize ENDP

asm_GetImageStatus PROC C
mov eax, 1
ret
asm_GetImageStatus ENDP

asm_getImagePercentage PROC C
mov eax, imagePercentage
ret
asm_getImagePercentage ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;asm_GetImageColour(int imageIndex, int ix, int iy, int &r, int &g, int &b)
;
asm_GetImageColour PROC C USES ebx esi eax edi, 
imageIndex : DWORD,
ix: DWORD, iy : DWORD,
r: PTR DWORD, g: PTR DWORD, b: PTR DWORD
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	mov eax, mimagewidth
	mov ebx, mimageheight
	sub ebx, iy
	mul ebx
	add eax, ix
	mov ebx, eax
	add eax, ebx
	add eax, ebx
	mov ebx, 0
	cmp imageIndex, ebx
	je M0
	mov esi, offset mimageptr1
	jmp M1
M0:	mov esi, offset mimageptr0
M1:	add esi, eax
	mov edi, r
	mov al, [esi]
	mov [edi], al
	inc esi
	mov edi, g
	mov al, [esi]
	mov [edi], al
	inc esi
	mov edi, b
	mov al, [esi]
	mov [edi], al
	cmp gray1, 1
	je L
P:	mov edi, r
	mov eax, [edi]
	mov eax, 60
	cmp [edi], eax
	jb Q1
	cmp count, 256
	ja P1
	mov edi, r
	mov eax, [edi]
	mov edi, b
	mov ebx, [edi]
	add ebx, count
	cmp ebx, eax
	ja W0
	mov eax, count
	add [edi], eax
	jmp W1
W0: mov [edi], eax
W1:	mov eax, 0
	cmp ix, eax
	jne Q1
	cmp iy, eax
	jne Q1
	inc count
	jmp Q1
P1: mov edi, b
	mov esi, r
	mov eax, [esi]
	mov [edi], eax
	jmp Q1
Q1:	cmp game, 1
	je D
	jmp Q

L:	mov edx, 0
	mov eax, 0
	mov edi, r
	mov eax, [edi]
	mov ebx, 299
	mul ebx
	mov ecx, eax
	mov edx, 0
	mov eax, 0
	mov edi, g
	mov eax, [edi]
	mov ebx, 587
	mul ebx
	add ecx, eax
	mov edx, 0
	mov eax, 0
	mov edi, b
	mov eax, [edi]
	mov ebx, 114
	mul ebx
	add ecx, eax
	add ecx, 500
	mov eax, ecx
	mov ecx, 1000
	div ecx

	mov edi, r
	mov [edi], eax
	mov edi, g
	mov [edi], eax
	mov edi, b
	mov [edi], eax
	cmp game, 1
	jne Q

D:	mov ebx, ix
	mov eax, iy
	cmp eax, 0
	jne F1
	jmp F0
F1:	cmp ebx, 255
	jne F2
	jmp F0
F2:	cmp ebx, 0
	jne F3
	jmp F0
F3:	cmp eax, 255
	jne F
	jmp F0
F:	cmp grid, 0
	jne D0
	mov eax, partX
	cmp eax, 3
	je Y3
	mov ebx, 63
	mul ebx
	mov side1, eax
	add eax, 63
	mov side2, eax
Y9:	mov eax, partY
	cmp eax, 1
	je Y2
	mov ebx, 127
	mul ebx
	mov side3, eax
	add eax, 127
	mov side4, eax
	jmp Y4
Y2:	mov side3, 127
	mov side4, 255
	jmp Y4
Y3: mov side1, 189
	mov side2, 255
	jmp Y9
Y4:	mov ebx, ix
	mov eax, iy
	cmp eax, 127
	je F0
	cmp ebx, 63
	je F0
	cmp ebx, 126
	je F0
	cmp ebx, 189
	je F0
	jmp Q
D0: cmp grid, 1
	jne D1
	mov eax, partX
	cmp eax, 7
	je Y0
	xor edx, edx
	mov ebx, 31
	mul ebx
	mov side1, eax
	add eax, 31
	mov side2, eax
Y10:mov eax, partY
	cmp eax, 3
	je Y
	mov ebx, 63
	xor edx, edx
	mul ebx
	mov side3, eax
	add eax, 63
	mov side4, eax
	jmp Y8
Y:	mov side3, 189
	mov side4, 255
	jmp Y8
Y0: mov side1, 217
	mov side2, 255
	jmp Y10
Y8:	mov ebx, ix
	mov eax, iy
	cmp ebx, 31
	je F0
	cmp ebx, 62
	je F0
	cmp ebx, 93
	je F0
	cmp ebx, 124
	je F0
	cmp ebx, 155
	je F0
	cmp ebx, 186
	je F0
	cmp ebx, 217
	je F0
	cmp eax, 63
	je F0
	cmp eax, 126
	je F0
	cmp eax, 189
	je F0
	jmp Q
D1: cmp grid, 2
	jne Q
	mov eax, partX
	cmp eax, 7
	je Y6
	mov ebx, 31
	xor edx, edx
	mul ebx
	mov side1, eax
	add eax, 31
	mov side2, eax
Y11:mov eax, partY
	cmp eax, 7
	je Y5
	mov ebx, 31
	xor edx, edx
	mul ebx
	mov side3, eax
	add eax, 31
	mov side4, eax
	jmp Y7
Y5:	mov side3, 217
	mov side4, 255
	jmp Y7
Y6: mov side1, 217
	mov side2, 255
	jmp Y11
Y7:	mov ebx, ix
	mov eax, iy
	cmp ebx, 31
	je F0
	cmp ebx, 62
	je F0
	cmp ebx, 93
	je F0
	cmp ebx, 124
	je F0
	cmp ebx, 155
	je F0
	cmp ebx, 186
	je F0
	cmp ebx, 217
	je F0
	cmp eax, 31
	je F0
	cmp eax, 62
	je F0
	cmp eax, 93
	je F0
	cmp eax, 124
	je F0
	cmp eax, 155
	je F0
	cmp eax, 186
	je F0
	cmp eax, 217
	je F0
	jmp Q

F0:	mov edi, r
	mov eax, 255
	mov [edi], eax
	mov edi, g
	mov [edi], eax
	mov edi, b
	mov [edi], eax

	mov eax, ix
	mov ebx, iy
	cmp side1, eax
	je E
	cmp side2, eax
	je E1
	cmp side3, ebx
	je E2
	cmp side4, ebx
	je E3
	jmp Q
E:	cmp ebx, side3
	jae U
	jmp Q
U:	cmp ebx, side4
	jbe U1
	jmp Q
U1: mov eax, 256
	call RandomRange
	mov edi, r
	mov [edi], eax
	mov eax, 256
	call RandomRange
	mov edi, g
	mov [edi], eax
	mov eax, 256
	call RandomRange
	mov edi, b
	mov [edi], eax
	jmp Q
E1:	cmp ebx, side3
	jae U2
	jmp Q
U2:	cmp ebx, side4
	jbe U3
	jmp Q
U3: mov eax, 256
	call RandomRange
	mov edi, r
	mov [edi], eax
	mov eax, 256
	call RandomRange
	mov edi, g
	mov [edi], eax
	mov eax, 256
	call RandomRange
	mov edi, b
	mov [edi], eax
	jmp Q
E2: cmp eax, side1
	jae U4
	jmp Q
U4:	cmp eax, side2
	jbe U5
	jmp Q
U5: mov eax, 256
	call RandomRange
	mov edi, r
	mov [edi], eax
	mov eax, 256
	call RandomRange
	mov edi, g
	mov [edi], eax
	mov eax, 256
	call RandomRange
	mov edi, b
	mov [edi], eax
	jmp Q
E3: cmp eax, side1
	jae U6
	jmp Q
U6:	cmp eax, side2
	jbe U7
	jmp Q
U7: mov eax, 256
	call RandomRange
	mov edi, r
	mov [edi], eax
	mov eax, 256
	call RandomRange
	mov edi, g
	mov [edi], eax
	mov eax, 256
	call RandomRange
	mov edi, b
	mov [edi], eax
Q:	ret
asm_GetImageColour ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;const char *asm_getStudentInfoString()
;
;return pointer in edx
asm_getStudentInfoString PROC C
	mov eax, offset MYINFO
	ret
asm_getStudentInfoString ENDP

;void asm_GetImageDimension(int &iw, int &ih)
asm_GetImageDimension PROC C USES ebx,
iw : PTR DWORD, ih : PTR DWORD
	mov eax, mimagewidth
	mov ebx, iw
	mov DWORD PTR [ebx], eax
	mov eax, mimageheight
	mov ebx, ih
	mov DWORD PTR [ebx], eax
	ret
asm_GetImageDimension ENDP

asm_GetImagePos PROC C USES ebx,
x : PTR DWORD,
y : PTR DWORD
mov eax, canvasMinX
mov ebx, scaleFactor
cdq
idiv ebx
mov ebx, x
mov [ebx], eax

mov eax, canvasMinY
mov ebx, scaleFactor
cdq
idiv ebx
mov ebx, y
mov [ebx], eax
ret
asm_GetImagePos ENDP

UpsideDown PROC USES eax ebx ecx edi esi edx
	mov ebx, 0
	cmp index, ebx
	jne M
	mov edi, OFFSET mimageptr1
	jmp M1
M:	mov edi, OFFSET mimageptr0
M1:	mov esi, OFFSET temp
	mov ecx, mimagewidth

	mov eax, mimagewidth
	mov ebx, mimageheight
	dec ebx
	mul ebx
	mov ebx, 3
	mul ebx
	
	mov ebx, 0
L:  mov edx, [edi + eax] 
	mov [esi + ebx], edx
	inc ebx
	inc eax
	mov edx, [edi + eax] 
	mov [esi + ebx], edx
	inc ebx
	inc eax
	mov edx, [edi + eax] 
	mov [esi + ebx], edx
	inc ebx
	inc eax
	Loop L
	sub eax, 1536
	mov ecx, mimagewidth
	cmp eax, -800
	jg L
	mov eax, mimagewidth
	mov ecx, mimageheight
	mul ecx
	mov ecx, eax
	mov eax, 0
L1: mov edx, [esi + eax] 
	mov [edi + eax], edx
	inc eax
	mov edx, [esi + eax] 
	mov [edi + eax], edx
	inc eax
	mov edx, [esi + eax] 
	mov [edi + eax], edx
	inc eax
	Loop L1
	ret
UpsideDown ENDP

horizon PROC USES edi esi ebx eax ecx edx
	mov ebx, 0
	cmp index, ebx
	jne M
	mov edi, OFFSET mimageptr1
	jmp M1
M:	mov edi, OFFSET mimageptr0
M1:	mov esi, OFFSET temp
	mov ebx, 0
	mov eax, mimagewidth
	dec eax
	mov ecx, 3
	mul ecx

	mov ecx, mimagewidth
	sub eax, 3
L:	mov edx, [edi + eax]
	mov [esi + ebx], edx
	inc eax
	inc ebx
	mov edx, [edi + eax]
	mov [esi + ebx], edx
	inc eax
	inc ebx
	mov edx, [edi + eax]
	mov [esi + ebx], edx
	inc eax
	inc ebx
	sub eax, 6
	Loop L
	add eax, 1536
	mov ecx, mimagewidth
	cmp eax, 196609
	jb L

	mov eax, mimagewidth
	mov ecx, mimageheight
	mul ecx
	mov ecx, eax
	mov eax, 0
L1: mov edx, [esi + eax] 
	mov [edi + eax], edx
	inc eax
	mov edx, [esi + eax] 
	mov [edi + eax], edx
	inc eax
	mov edx, [esi + eax] 
	mov [edi + eax], edx
	inc eax
	Loop L1

	ret
horizon ENDP

updateGame PROC USES esi
	cmp showID, 1
	jne Q
	cmp set, 1
	je L0
	call SetStudentID
	mov set, 1
L0:	mov esi, offset objPosX
	mov ecx, 512
	mov ebx, -50000
	cmp [esi], ebx
	jl M1
	mov ebx, 50000
	cmp [esi + 112], ebx
	ja M2
	jmp L2
M1: mov direct, 1
	jmp L2
M2: mov direct, 0
L2:	cmp direct, 1
	je P1
	mov ebx, speed
	sub SDWORD PTR [esi], ebx
	jmp P2
P1: mov ebx, speed
	add SDWORD PTR [esi], ebx 
P2:	add esi, 4
	Loop L2
Q:	ret
updateGame ENDP

SetStudentID PROC
	mov edi, offset objPosX
	mov esi, offset objPosY
	mov edx, offset ObjColor
	mov X1, 0
	mov Y1, 0
	mov ebx, 0
	mov ecx, 28
L:  cmp studentID[ebx], 1
	jne L1
	mov eax, Y1
	mul spaceY
	sub [esi], eax
	mov eax, X1
	mul spaceX
	add [edi], eax
	add esi, 4
	add edi, 4
L1: inc X1
	inc ebx
	Loop L
	inc Y1
	cmp Y1, 6
	je L0
	mov X1, 0
	mov ecx, 28
	jmp L
L0:	mov edi, offset ObjColor
	mov ecx, 12288
	call Randomize
L2:	mov eax, 255
	call RandomRange
	mov ecx, eax
	call Random32
	mov ebx, eax
	call Random32
	mov DWORD PTR [edi], eax
	;
	add edi, 4
	mov DWORD PTR [edi], ebx
	;
	add edi, 4
	mov DWORD PTR [edi], ecx
	add edi, 4
	Loop L2
Q:	ret
SetStudentID ENDP

END