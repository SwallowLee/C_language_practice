TITLE Animation

include Irvine32.inc
include Macros.inc

delayTime = 10
avatarColor = blue+white*16		;named constant
backgroundColore = black + black*16
.data
	avatarColor		DWORD	dft_avatarColor
	avatarChar		BYTE	'B'
	avararX			BYTE	1
	acatarY			BYTE	5
	$sound			BYTE	7, 0
.code

main PROC
	mov ecx, 0
L1:
	call DeleteOldAvatar
	call updateAvatarPosition
	call SetAvatarPosition
	call showAvatar
	call delayAnimation
	call changeAvatarColor
	loop L1
	call ReadInt
	exit
main ENDP

DeleteOldAvatar PROC
	call SetAvatarPosition
	mov eax, backgroundColor
	call SetTextColore
	mov al, ' '
	call WriteChar
	ret
DeleteOldAvatar ENDP

SetAvatarPosition PROC
	mov dl, avatarX
	mov dh, avatarY
	call GotoXY					;origin is at left top
	ret
SetAvatarPosition ENDP

updateAvatarPosition PROC
	mov dl, avatarX
	inc dl
	mov avatarX, dl
	ret
updateAvatarPosition ENDP
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

SetAvatarColor PROC
	mov eax, avatarColor
	ret				;return 
SetAvatarColor ENDP

changeAvatarColor PROC
	mov eax, avatarColor
	inc eax
	mov avatarColor, eax

	inc avatarColor
changeAvatarColor ENDP
END main