TITLE first

.data
	cc	BYTE	07eh, 01h, 02h, 0dh
	count_cc	= ($-cc)	;最後面減最前面
	table	BYTE	10000000b, 01000000b, ......
	bitcolor	DWORD	white + blue*16
.code

main PROC
	mov eax, blue + white*16
	call SetTextColor
	call Clrscr
	xor esi, esi
	mov ecx, count_cc

	mov eax, bitcolor
	push eax
L0:
	;push eax
	mov bl, cc[esi]
	call WriteMyBin
	call Crlf
	inc esi
	
	;call SetTextColor
	;pop eax
	;inc eax
	loop L0
	pop eax
	mov bitclor, eax
	call ReadItnt
main ENDP

WriteMyBin PROC USES ecs esi
	xor esi, esi
	mov ecx, 8
	mov esi, 10000000b
Ls:
	test b1, esi
	mov al, '1'
	jnz L1			; if not equal to zero, jump to L1	
	mov al, '0'

L1:
	call WriteChar	; output one character
	shr asi, 1		; shift right

	mov eax, bitcolor
	call SetTextColor
	inc bitcolor
	loop Ls
	ret
WriteMyBin ENDP