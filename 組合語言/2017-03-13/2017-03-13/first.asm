TITLE	determined

.data
	a	DWORD	101
	b	DWORD	100
	msg	BYTE	"Above or equal", 0
.code

main PROC
	mov eax, a
	cmp eax, b
	jb L0		; unsigned: ja/jb/jbe/jna	; signed: jg/jl/jle (SDWORD)
	call showMsg
L0:
	
qs:
	call ReadInt

	exit
main ENDP

showMsg PROC
	mov edx, offset msg
	call WriteString
	ret
showMsg ENDP
END main