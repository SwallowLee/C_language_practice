TITLE stack

include 

.data

.code

main PROC
	mov eax, 123432
	push eax
	mov eax, 3534
	push eax
	call foo
	mov eax, [esp]
	call WriteInt
	call crlf	
	call Readint
	exit
main ENDP

foo PROC
	mov ebp, esp
	mov eax, 8721
	push eax
	mov eax, [ebp+4]		; return address
	call WriteInt
	call crlf
	mov eax, [ebp+8]		; 12432
	call WriteInt
	call crlf
	mov eax, [ebp-4]		; 8721
	call WriteInt
	call crlf

	mov eax, [ebp]
	call WriteHex
	call ReadInt
	pop ebp
	ret	8				; clear the space
foo ENDP
END main
