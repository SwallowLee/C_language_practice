TITLE stack

include 

;forward
foo PROTO,
: DWORD, : PTR DWORD		; to use invoke

.data
c	DWORD	11111
d	DWORD	33333, 1356, 548532, 23486
.code

main PROC
	invoke foo, x, offset y
	;push offset d
	;push c
	call foo			; foo(c, &d)
	mov eax, [d]
	call ShowInt
	call crlf
	mov eax, [d+4]
	call ShowInt
	call ReadInt
	exit
main ENDP

foo PROC USES ESI
	a: DWORD, b: PTR DWORD	; push ebp in the stack and do mov ebp, [esp]
	
	mov eax, a			; eax = a
	mov esi, b			; *b = a
	mov [esi+4], eax		; *b = a
	call ReadInt
	ret	
foo ENDP

ShowInt PROC
	call WriteInt
	call crlf 
	ret
ShowInt ENDP
END main
