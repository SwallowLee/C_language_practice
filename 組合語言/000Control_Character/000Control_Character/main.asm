TITLE Animation

include Irvine32.inc
include Macros.inc

delayTime = 100
dft_avatarColor = white	+ white*16; named constant

backgroundColor = black + black*16
.data

avatarColor DWORD	dft_avatarColor
avatarChar	BYTE	'B'
avatarX		BYTE	1
avatarY		BYTE	1
$sound		BYTe	7, 0
.code

main PROC
	mov eax, black + black*16
	call SetTextColor
	call Clrscr
L1:
	call deleteOldAvatar
	call handleKeyEvents
	call SetAvatarPosition
	call showAvatar
	call delayAnimation
	;call changeAvatarColor
	jmp L1

	call ReadInt
	exit
main ENDP
;
handleKeyEvents PROC
	call ReadKey
	jnz L0
	jmp quit0
L0:
	cmp al, 'a'
	jne L1
	call moveLeft
	jmp quit0
L1:
	cmp al, 'd'
	jne L2
	call moveRight
	mov edx, offset $sound
	call WriteString
	jmp quit0
L2:
quit0:
	ret
handleKeyEvents ENDP

moveLeft PROC
	mov dl, avatarX
	mov dh, avatarY
	dec dl
	mov avatarX, dl
	ret
moveLeft ENDP

moveRight PROC
	mov dl, avatarX
	mov dh, avatarY
	inc dl
	mov avatarX, dl
	ret
moveRight ENDP

;
deleteOldAvatar PROC
	call SetAvatarPosition
	mov eax, black + black*16
	call SetTextColor
	mov al, ' '
	call WriteChar
	ret
deleteOldAvatar ENDP
;
SetAvatarPosition PROC
	mov dl, avatarX
	mov dh, avatarY
	call GotoXY
	ret
SetAvatarPosition ENDP
;
updateAvatarPosition PROC
	mov dl, avatarX
	inc dl
	cmp dl, 60
	jb L1
	mov dl, 0
	inc dh
	mov avatarY, dh
L1:
	mov avatarX, dl
	ret
updateAvatarPosition ENDP
;
delayAnimation PROC
	mov eax, delayTime
	call Delay
	ret
delayAnimation ENDP

showAvatar PROC
	call SetAvatarColor
	mov al, avatarChar
	call WriteChar
	ret
showAvatar ENDP
;
SetAvatarColor PROC
	xor ebx, ebx
	xor edx, edx
	mov eax, avatarColor
	;mov eax, blue + blue*16
	call SetTextColor
	ret
SetAvatarColor ENDP
;
changeAvatarColor PROC
	;mov eax, avatarColor
	;inc eax
	;mov avatarColor, eax
	inc  avatarColor
	ret
changeAvatarColor ENDP
;
END main


























TITLE ThSs Is mY sEcOnD dAy

include Irvine32.inc
include Macros.inc

.data
$MyMessage BYTE	"ABCD"
$MyMessage BYTE	"ABCD"
$MyMessage BYTE	"ABCD"
$MyMessage BYTE	"ABCD"
.code

main PROC
	mov eAx, 12345
	mov EbX, 1FAB1234h
	mov eCX, 123456h
	call DumpRegs
	mov eax, 1
	add eax, 2
	call DumpRegs
	mov eax, 1
	add eax, 0FFFFFFFFh
	call DumpRegs
	call ReadInt	; this is a comment. block the program
	exit
main ENDP
END main























TITLE Show a message: Hello World!

include Irvine32.inc
include Macros.inc

.data
MyMessage	BYTE "Hello World!"
			BYTE "ABCDEF0GHIJK!"
			BYTE "ABCDEFGHIJK!"
			BYTE "ABCDEFGHIJK!"
			BYTE "ABCDEFGHIJK!"
; null-terminated string


.code
;e: extended
;dx: register name
;edx is a 32-bit register
main PROC
	mov eax, 0
	mov eax, yellow + blue*16
	call SetTextColor
	mov edx, offset MyMessage ; address
	call WriteString
	;
	mov eax, 0
	mov eax, yellow*16 + blue
	call SetTextColor
	mov edx, offset MyMessage ; address
	call WriteString
	;
	call ReadInt   ; read an integer
	; it is blocked
	exit
main ENDP

END main























tITle My fiRsT pRoGraM

  
  include Irvine32.inc
  include Macros.inc

  
  .data

  MyMessage BYTE "Hello World!", 0

  .code

  main PROC
	mov eax, 0
	mov eax, yellow*16 + blue
	call SetTextColor
	mov edx, offset MyMessage
	call WriteString ; edx
	;
		mov eax, 0
	mov eax, yellow + blue*16
	call SetTextColor
	mov edx, offset MyMessage
	call WriteString ; edx
	call ReadInt
	exit
  main ENDP

  END main

 













  aslkdjlaskjdaskljasd
  as
  dsa
  d
  asd
  as
  dsa
  das
  d
  as
  das
  d
  af
  sdgklfglfd;jgdlkfs;lkf;klsd

  


























Title my program

include Irvine32.inc
include Macros.inc

.data
MyMsg BYTE "Hello World!", 0

.code

main PROC
	mov edx, offset MyMsg
	call WriteString
	call ReadInt
Lexit0:
	exit
main ENDP

END main
