TITLE Chapter 4

include Irvine32.inc
include Macros.inc

.data
	msg		BYTE	"This is Chapter 4", 0	
	var2	DWORD	12345678h, 0ABCDEF12h, 3, 4, 5, 6, 7, 8,
					0ffh, ofeh, 0AAAABBBBh, 0, 121321h		; still can work
	var1	DWORD	12345678h, 0ABCDEF12h, 3, 4, 5, 6, 7, 8
			DWORD	0ffh, ofeh, 0AAAABBBBh, 0, 121321h
	count = ($-var1)/TYPE var1		; put two DWORD¡@together

.code

main PROC
	;mov eax, sizeof var1	; the total length of var1
	;mov ebx, type var1		; the type length of var1
	mov ecx, Lengthof var1	; the number of var1 ; loop counter
	xor ebx, ebx			;mov ebx, 0
	mov esi, offset var1
	L1:
		mov eax, [esi+ebx*TYPE var1]	;mov eax, [var1+ebx*TYPE var1]
		cmp eax, 0
		jne	L2							; j: jump ne: not equal zero ; oppsite: je (=jz)
		jmp L3
	L2:
		call WriteHex
		call crlf
		inc ebx
		loop L2
	L3:
		call DumpRegs
		exit
main ENDP
END main