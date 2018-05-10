
;========================================================
; Student Name: §õ¨Î¿P
; Student ID: 0416039
; Email: girlannie123@gmail.com
;========================================================
; Instructor: Sai-Keung WONG
; Email: cswingo@cs.nctu.edu.tw
; Room: EC706
; Assembly Language 
;========================================================
; Description:
;
; IMPORTANT: always save EBX, EDI and ESI as their
; values are preserved by the callers in C calling convention.
;

INCLUDE Irvine32.inc
INCLUDE Macros.inc

invisibleObjX  TEXTEQU %(-100000)
invisibleObjY  TEXTEQU %(-100000)

MOVE_LEFT		= 0
MOVE_LEFT_KEY	= 'a'
MOVE_UP         = 1
MOVE_UP_KEY     = 'w'
MOVE_RIGHT      = 2
MOVE_RIGHT_KEY  = 'd'
MOVE_DOWN       = 3
MOVE_DOWN_KEY   = 's'

RAINBOW_KEY     = 'p'

RANDOM_KEY      = 'r'

CLEAR_KEY       = 'c'
SAVE_KEY        = 'l'

LOAD_KEY        = 'v'

SPACE_BAR_KEY   = 32
ESC_KEY			= 283

; PROTO C is to make agreement on calling convention for INVOKE

c_updatePositionsOfAllObjects PROTO C

.data 

MY_INFO_AT_TOP_BAR	BYTE "My Student Name: §õ¨Î¿P StudentID: 0416039",0 

MyMsg BYTE "Project Title: Assembly Programming...",0dh, 0ah, 0
infor BYTE "My Student Name: §õ¨Î¿P StudentID: 0416039",0dh, 0ah,0

CaptionString BYTE "Student Name: §õ¨Î¿P",0
MessageString BYTE "Welcome to Wonderful World", 0dh, 0ah, 0dh, 0ah
				BYTE "My Student ID is 0416039", 0dh, 0ah, 0dh, 0ah
				BYTE "My Email is: girlannie123@gmail.com.", 0dh, 0ah, 0dh, 0ah, 0

CaptionString_EndingMessage BYTE "Student Name: §õ¨Î¿P",0
MessageString_EndingMessage BYTE "My Student ID is 0416039", 0dh, 0ah, 0dh, 0ah
							BYTE "My Email is: girlannie123@gmail.com.", 0dh, 0ah, 0dh, 0ah, 0

usagecap	BYTE	"key usage", 0							
usage	BYTE	"Programmer Name: §õ¨Î¿P", 0dh, 0ah
		BYTE	"Programmer ID: 0416039", 0dh, 0ah
		BYTE	"Programmer Email Address: girlannie123@gmail.com", 0dh, 0ah, 0dh, 0ah
		BYTE	"¡¥a¡¦: left; ¡¥d¡¦: right, ¡¥w¡¦: up; ¡¥s¡¦: down", 0dh, 0ah
		BYTE	"¡¥p¡¦ : rainbow color", 0dh, 0ah
		BYTE	"¡¥r¡¦: random color", 0dh, 0ah
		BYTE	"¡¥c¡¦: clear", 0dh, 0ah
		BYTE	"¡¥v¡¦ : save", 0dh, 0ah
		BYTE	"¡¥l¡¦ : load", 0dh, 0ah
		BYTE	"left mouse button: set target", 0dh, 0ah
		BYTE	"spacebar : toggle grow / not grow", 0dh, 0ah
		BYTE	"ESC : quit the program", 0

speed	DWORD	100
cycle	DWORD	25
rainbow	DWORD	0
random	DWORD	1
space	DWORD	1
X_p		SDWORD	0
Y_p		SDWORD	0
X_s		SDWORD	0
Y_s		SDWORD	0
timer	DWORD	0
obj		DWORD	0
clear	DWORD	0
rainbow_color DWORD 255,0,0, 255,110,0, 238,255,0 , 8,255,0 , 0,187,255 , 30,0,255 , 221,0,255

objPosX_s		SDWORD	2048 DUP(0)
objPosY_s		SDWORD	2048 DUP(0)
num				DWORD	1
rainbow_s		DWORD	0
random_s		DWORD	0
moveDirection_s	DWORD	2
space_s			DWORD	1
clear_s			DWORD	0
mouse			DWORD	0
y_m				SDWORD	0
x_m				SDWORD	0
f_x				DWORD	0

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
particleSize DWORD  2
numParticles DWORD 20000
particleMaxSpeed DWORD 3

moveDirection	DWORD	2

flgQuit		DWORD	0
maxNumObjects	DWORD 2048
numObjects	DWORD	1
objPosX		SDWORD	2048 DUP(0)
objPosY		SDWORD	2048 DUP(0)
objTypes	BYTE	2048 DUP(1)
objSpeedX	SDWORD	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
			SDWORD	2048 DUP(?)
objSpeedY	SDWORD	2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
			SDWORD	2048 DUP(?)			
objColor	DWORD	0, 254, 254,
					254, 254, 254,
					0, 127, 0,
					2048*3 DUP(128)

DIGIT_MO_0		BYTE 0, 0, 1, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0dh
				BYTE 0, 0, 0, 0ffh
DIGIT_MO_SIZE = ($-DIGIT_MO_0)				

offsetImage DWORD 0

openingMsg	BYTE	"This program shows the student ID using bitmap and manipulates images....", 0dh
			BYTE	"Great programming.", 0
movementDIR	BYTE 0
state		BYTE	0

imagePercentage DWORD	0

mImageStatus DWORD 0
mImagePtr0 BYTE 200000 DUP(?)
mImagePtr1 BYTE 200000 DUP(?)
mImagePtr2 BYTE 200000 DUP(?)
mTmpBuffer	BYTE	200000 DUP(?)
mImageWidth DWORD 0
mImageHeight DWORD 0
mBytesPerPixel DWORD 0
mImagePixelPointSize DWORD 6

.code

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
	mov dx, 0
	call GotoXY
	xor eax, eax
	mov ah, 0h
	mov al, 0e1h
	call SetTextColor
	mov edx, offset MyMsg
	call WriteString
	mov edx, offset infor
	call WriteString
	ret
asm_ShowTitle ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_InitializeApp()
;
;This function is called
;at the beginning of the program.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_InitializeApp PROC C USES ebx edi esi edx
	call AskForInput_Initialization
	call initGame
	ret
asm_InitializeApp ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_EndingMessage()
;
;This function is called
;when the program exits.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_EndingMessage PROC C USES ebx edx
	mov ebx, OFFSET CaptionString_EndingMessage
	mov edx, OFFSET MessageString_EndingMessage
	call MsgBox
	ret
asm_EndingMessage ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_updateSimulationNow()
;
;Update the simulation.
;For examples,
;we can update the positions of the objects.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_updateSimulationNow PROC C USES edi esi ebx
	;
	call updateGame
	;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;DO NOT REMOVE THIS FOLLOWING LINE
	call c_updatePositionsOfAllObjects 
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	ret
asm_updateSimulationNow ENDP

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
asm_GetNumParticles PROC C
	mov eax, 10000
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
	;modify this procedure
	mov eax, 1
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
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	
	ret
asm_handleMousePassiveEvent ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_handleMouseEvent(int button, int status, int x, int y)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_handleMouseEvent PROC C USES ebx,
	button : DWORD, status : DWORD, x : DWORD, y : DWORD
	
	mov eax, 1
	mov mouse, eax
	mov f_x, eax
	mWriteln "asm_handleMouseEvent"
	mov eax, button
	mWrite "button:"
	call WriteDec
	mWriteln " "
	mov eax, status
	mWrite "status:"
	call WriteDec
	mov eax, x
	mov ebx, 125
	mul ebx
	sub eax, 50000
	mov x_m, eax
	mWriteln " "
	mWrite "x:"
	call WriteDec
	mWriteln " "
	mov eax, y
	mov ebx, 125
	mul ebx
	sub eax, 50000
	neg eax
	mov y_m, eax
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
	;call ReadInt
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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
	call WriteInt
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	cmp eax, MOVE_LEFT_KEY
	jne L1
	mov eax, 0
	mov mouse, eax
	call moveLeft
	jmp exit0
L1: cmp eax, MOVE_RIGHT_KEY
	jne L2
	mov eax, 0
	mov mouse, eax
	call moveRight
	jmp exit0
L2: cmp eax, MOVE_UP_KEY
	jne L3
	mov eax, 0
	mov mouse, eax
	call moveUp
	jmp exit0
L3: cmp eax, MOVE_DOWN_KEY
	jne L4
	mov eax, 0
	mov mouse, eax
	call moveDown
	jmp exit0
L4: cmp eax, RAINBOW_KEY
	jne L5
	mov rainbow, 1
	mov random, 0
L5: cmp eax, RANDOM_KEY
	jne L6
	mov random, 1
	mov rainbow, 0
L6: cmp eax, CLEAR_KEY
	jne L7
	mov clear, 1
L7: cmp eax, LOAD_KEY
	jne L8
	call save
L8: cmp eax, SAVE_KEY
	jne L9
	call load
L9: 
L10: cmp eax, SPACE_BAR_KEY
	 jne L11
	 mov ebx, space
	 cmp ebx, 0
	 je Q1
	 mov ebx, 0
	 mov space, ebx
	 jmp L11
Q1:  mov ebx, 1
	 mov space, ebx
L11: cmp eax, ESC_KEY
	 jne exit0
	 mov flgQuit, 1
exit0:
	mov eax, 0
	ret
asm_HandleKey ENDP

save PROC
	mov eax, 0
P:	mov esi, offset objPosX
	mov ecx, [esi + eax*4]
	mov esi, offset objPosX_s
	mov [esi + eax*4], ecx
	mov esi, offset objPosY
	mov ecx, [esi + eax*4]
	mov esi, offset objPosY_s
	mov [esi + eax*4], ecx
	inc eax
	cmp eax, numObjects
	jb P
	mov eax, random
	mov random_s, eax
	mov eax, rainbow
	mov rainbow_s, eax
	mov eax, numObjects
	mov num, eax
	mov eax, moveDirection
	mov moveDirection_s, eax
	mov eax, space
	mov space_s, eax
	mov eax, clear
	mov clear_s, eax
	mov eax, X_p
	mov X_s, eax
	mov eax, Y_p
	mov Y_s, eax
	ret
save ENDP
load PROC
	mov eax, 0
P:	mov esi, offset objPosX_s
	mov ecx, [esi + eax*4]
	mov esi, offset objPosX
	mov [esi + eax*4], ecx
	mov esi, offset objPosY_s
	mov ecx, [esi + eax*4]
	mov esi, offset objPosY
	mov [esi + eax*4], ecx
	inc eax
	cmp eax, num
	jb P
W:	mov ecx, 0
	mov esi, offset objPosX
	mov [esi + eax*4], ecx
	mov ecx, 0
	mov esi, offset objPosY
	mov [esi + eax*4], ecx
	inc eax
	cmp eax, numObjects
	jb W
	mov eax, random_s
	mov random, eax
	mov eax, rainbow_s
	mov rainbow, eax
	mov eax, num
	mov numObjects, eax
	mov eax, moveDirection_s
	mov moveDirection, eax
	mov eax, space_s
	mov space, eax
	mov eax, clear_s
	mov clear, eax
	mov eax, X_s
	mov X_p, eax
	mov eax, Y_s
	mov Y_p, eax
	ret
load ENDP
moveLeft PROC
	mov moveDirection, MOVE_LEFT
	ret
moveLeft ENDP
moveRight PROC
	mov moveDirection, MOVE_RIGHT
	ret
moveRight ENDP
moveUp PROC
	mov moveDirection, MOVE_UP
	ret
moveUp ENDP
moveDown PROC
	mov moveDirection, MOVE_DOWN
	ret
moveDown ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_SetWindowDimension(int w, int h, int scaledWidth, int scaledHeight)
;
;w: window resolution (i.e. number of pixels) along the x-axis.
;h: window resolution (i.e. number of pixels) along the y-axis. 
;scaledWidth : scaled up width
;scaledHeight : scaled up height

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
	call asm_RefreshWindowSize
	ret
asm_SetWindowDimension ENDP	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;int asm_GetNumOfObjects()
;
;Return the number of objects
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_GetNumOfObjects PROC C
	mov eax, maxNumObjects
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

;;;;;;;;;;;;;;;;;;;;;;;;asm_ComputeObjPositionX;;;;;;;;;;;;;;;;
;void asm_GetObjectColor (int &r, int &g, int &b, int objID)
;Input: objID, the ID of the object
;
;Return the color three color components
;red, green and blue.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_GetObjectColor  PROC C USES ebx edi esi,
	r: PTR DWORD, g: PTR DWORD, b: PTR DWORD, objID: DWORD
	mov eax, rainbow
	cmp eax, 1
	je L0
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

L0:	xor edx ,edx
	mov ebx , 7
	mov eax , objID
	div ebx
	mov eax , edx
	add eax , edx
	add eax , edx
	mov ebx , 4
	mul ebx
	
	mov esi ,offset rainbow_color
	add esi , eax
	mov ebx, DWORD PTR [esi]
	mov edi, r
	mov DWORD PTR [edi], ebx
	;
	add esi, 4
	mov ebx, DWORD PTR [esi]
	mov edi, g
	mov DWORD PTR [edi], ebx
	;
	add esi, 4
	mov ebx, DWORD PTR [esi]
	mov edi, b
	mov DWORD PTR [edi], ebx
	ret
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
;int asm_ComputeObjPositionX(int x, int objID)
;
;Return the x-coordinate in eax.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_ComputeObjPositionX PROC C USES edi esi ebx edx,
	x: DWORD, objID: DWORD
	;modify this procedure
	mov ebx, objID
	mov esi, offset objPosX
	mov eax, [esi+ebx*4]
	ret
asm_ComputeObjPositionX ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;int asm_ComputeObjPositionY(int y, int objID)
;
;Return the y-coordinate in eax.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_ComputeObjPositionY PROC C USES ebx esi edx,
	y: DWORD, objID: DWORD
	;modify this procedure
	mov ebx, objID
	mov esi, offset objPosY
	mov eax, [esi+ebx*4]
	ret
asm_ComputeObjPositionY ENDP


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; The input image's information:
; imageIndex : the index of an image, starting from 0
; imagePtr : the starting address of the image, i.e., the address of the first byte of the image
; (w, h) defines the dimension of the image.
; w: width
; h: height
; Thus, the image has w times h pixels.
; bytesPerPixel : the number of bytes used to represent one pixel
;
; Purpose of this procedure:
; Copy the image to our own database
;
asm_SetImageInfo PROC C USES esi edi ebx eax ecx,
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

;
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

	
	;mov esi, r
	;mov DWORD PTR [esi], 0
	;mov esi, g
	;mov DWORD PTR [esi], 125
	;mov esi, b
	;mov DWORD PTR [esi], 0
	ret
asm_GetImageColour ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;const char *asm_getStudentInfoString()
;
;return pointer in edx
asm_getStudentInfoString PROC C
	mov eax, offset MY_INFO_AT_TOP_BAR
	ret
asm_getStudentInfoString ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Return the particle system state in eax
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
asm_GetParticleSystemState PROC C
	mov eax, 1
	ret
asm_GetParticleSystemState ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;void asm_GetImageDimension(int &iw, int &ih)
asm_GetImageDimension PROC C USES ebx eax edi,
iw : PTR DWORD, ih : PTR DWORD
	mov eax, mimagewidth
	mov ebx, iw
	mov DWORD PTR [ebx], eax
	mov eax, mimageheight
	mov ebx, ih
	mov DWORD PTR [ebx], eax
	ret
asm_GetImageDimension ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;
; Compute a position to place an image.
; This position defines the lower left corner
; of the image.
;
asm_GetImagePos PROC C USES ebx,
	x : PTR DWORD,
	y : PTR DWORD
	mov eax, canvasMinX
	mov ebx, scaleFactor
	cdq
	idiv ebx
	mov ebx, x
	mov [ebx], eax
;
	mov eax, canvasMinY
	mov ebx, scaleFactor
	cdq
	idiv ebx
	mov ebx, y
	mov [ebx], eax
	ret
asm_GetImagePos ENDP

AskForInput_Initialization PROC USES ebx edi esi
	mov edx, offset MyMsg
	call WriteString
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	mov ebx, OFFSET CaptionString
	mov edx, OFFSET MessageString
	call MsgBox
	mov ebx, OFFSET usagecap
	mov edx, OFFSET usage
	call MsgBox
	mWrite "Please input grow cycle:"
	call ReadInt
	cmp eax, 0
	je L0
	jmp L1
L0: mov eax, 25
L1:	mov cycle, eax
	mWriteln " "
	mWrite "Please input the speed:"
	call ReadInt
	cmp eax, 0
	je L2
	jmp L3
L2: mov eax, 100
L3: mov speed, eax
	ret
AskForInput_Initialization ENDP

asm_RefreshWindowSize PROC
	ret
asm_RefreshWindowSize ENDP

initGame PROC
	
	ret
initGame ENDP

updateGame PROC USES esi 
	mov eax, 1
	cmp mouse, eax
	je Z
	mov eax, moveDirection
L:	cmp eax, MOVE_LEFT
	jne L0
	mov esi, offset objPosX
	mov eax, [esi]
	cmp eax, -50000
	jl	Q0
	sub eax, speed
	mov [esi], eax
	jmp L3
Q0: mov eax, moveDirection
	call moveRight
L0: cmp eax, MOVE_RIGHT
	jne L1
	mov esi, offset objPosX
	mov eax, [esi]
	cmp eax, 50000
	jg Q1
	add eax, speed
	mov [esi], eax
	jmp L3
Q1: mov eax, moveDirection
	call moveLeft
	jmp L
L1: cmp eax, MOVE_UP
	jne L2
	mov esi, offset objPosY
	mov eax, [esi]
	cmp eax, 50000
	jg Q2
	add eax, speed
	mov [esi], eax
	jmp L3
Q2: mov eax, moveDirection
	call moveDown
L2:	cmp eax, MOVE_DOWN
	jne L3
	mov esi, offset objPosY
	mov eax, [esi]
	cmp eax, -50000
	jl Q3
	sub eax, speed
	mov [esi], eax
	jmp L3
Q3: mov eax, moveDirection
	call moveUp
	jmp L1	
L3:	cmp clear, 1
	je L5
	mov eax, timer
	cmp eax, cycle
	jne L4
	mov timer, 0
	mov eax, numObjects
	cmp eax, MaxNumObjects
	je L4
	mov ebx, space
	cmp ebx, 1
	jne W
	mov edx, 1
	cmp numObjects, edx
	ja W0
	mov edi, offset ObjColor
	mov edx, 255
	mov [edi], edx
	add edi, 4
	mov edx, 0
	mov [edi], edx
	add edi, 4
	mov [edi], edx
	inc numObjects
	jmp W
W0:	
M0: call Random32
	mov ecx, eax
	and ecx, 0ffh
	call Random32
	mov ebx, eax
	and ebx, 0ffh
	call Random32
	mov eax, eax
	and eax, 0ffh
	mov edi, offset ObjColor
	mov eax, numObjects
	mov ebx, 12
	mul ebx
	add edi, eax
	mov DWORD PTR [edi], eax
	;
	add edi, 4
	mov DWORD PTR [edi], ebx
	;
	add edi, 4
	mov DWORD PTR [edi], ecx
	inc numObjects
W:	mov eax, numObjects
	mov obj, eax
P:	mov eax, obj
	cmp eax, 2
	ja P1
	jb L4
	mov esi, offset objPosX
	mov ecx, X_p
	mov [esi + 4], ecx
	mov esi, offset objPosY
	mov ecx, Y_p
	mov [esi + 4], ecx 
	mov esi, offset objPosX
	mov eax, [esi]
	mov X_p, eax
	mov esi, offset objPosY
	mov eax, [esi]
	mov Y_p, eax
	jmp L4

P1: mov ebx, obj
	sub ebx, 2
	mov esi, offset objPosX
	mov ecx, [esi + ebx*4]
	dec eax
	mov [esi + eax*4], ecx
	mov eax, obj
	mov ebx, obj
	sub ebx, 2
	mov esi,  offset objPosY
	mov ecx, [esi + ebx*4]
	dec eax
	mov [esi + eax*4], ecx
	dec obj
	jmp P

L4:	cmp space, 0
	je Q
E:	inc timer
	ret
Q:  cmp numObjects, 1
	je L6
	jmp E
L5: mov ecx, numObjects
	mov eax, 1
R:	mov esi, offset objPosX
	mov ebx, 0
	mov [esi + eax*4], ebx
	mov esi, offset objPosY
	mov ebx, 0
	mov [esi + eax*4], ebx
	inc eax
	Loop R	
	mov space, 0
	mov clear, 0
	mov timer, 0
	mov numObjects, 1
	ret
L6: mov esi, offset objPosX
	mov eax, [esi]
	mov X_p, eax
	mov esi, offset objPosY
	mov eax, [esi]
	mov Y_p, eax
	jmp X
Z:  ;mWrite"x_m"
	;mov eax, x_m
	;call WriteInt
	;call Crlf
	mov esi, offset objPosX
	mov eax, [esi]
	;call WriteInt
	;call Crlf
	;call ReadInt
	cmp eax, x_m
	jl Z1
	cmp eax, x_m
	jg Z2
	mov eax, 0
	mov f_x, eax
	jmp Z3
Z1: call moveRight
	mov ebx, x_m
	sub ebx, eax
	cmp ebx, speed
	jl X1
	add eax, speed
	jmp X2
X1:	mov eax, x_m
X2:	mov [esi], eax
	jmp Z3
Z2: call moveLeft
	mov ebx, x_m
	mov ecx, eax
	sub ecx, ebx
	cmp ecx, speed
	jl X3
	sub eax, speed
	jmp X4
X3:	mov eax, x_m
X4:	mov [esi], eax

Z3: mov esi, offset objPosY
	mov eax, [esi]
	cmp eax, y_m
	jl Z4
	cmp eax, y_m
	jg Z5
	mov ebx, 0
	cmp f_x, ebx
	je U1
	jmp L3
U1:	jmp X
Z4:  call moveUp
	mov ebx, y_m
	mov ecx, eax
	sub ebx, ecx
	cmp ebx, speed
	jl X5
	add eax, speed
	jmp X6
X5:	mov eax, y_m
X6:	mov [esi], eax
	jmp L3
Z5: call moveDown
	mov ebx, y_m
	mov ecx, eax
	sub ecx, ebx
	cmp ecx, speed
	jl X7
	sub eax, speed
	jmp X8
X7:	mov eax, y_m
X8:	mov [esi], eax
	jmp L3
X:	ret
updateGame ENDP

END

