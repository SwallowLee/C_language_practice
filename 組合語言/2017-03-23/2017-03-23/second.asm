TITLE stack

include 

.data

.code

main PROC
	mov eax, 11111
	push eax
	mov eax, 123432
	push eax
	mov eax, 3534
	push eax
	call foo
	mov eax, [esp]
	call ShowInt
	call Readint
	exit
main ENDP

foo PROC,
	a: DWORD, b: DWORD	; push ebp in the stack and do mov ebp, [esp]
	mov eax, a			; a = [abp-12]
	call ShowInt
	mov eax, b			; b = [ebp-8]
	call ShowInt
	call ReadInt
	ret	
foo ENDP

ShowInt PROC
	call WriteInt
	call crlf 
	ret
ShowInt ENDP
END main
