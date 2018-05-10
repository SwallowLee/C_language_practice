TITLE Chapter 4

include Irvine32.inc
include Macros.inc

.data
	msg		BYTE	"This is zero", 0	
	var2	DWORD	12345678h, 0ABCDEF12h, 3, 4, 5, 6, 7, 8,
					0ffh, ofeh, 0AAAABBBBh, 0, 121321h		; still can work
	var1	DWORD	12345678h, 0ABCDEF12h, 3, 4, 5, 6, 7, 8
			DWORD	0ffh, ofeh, 0AAAABBBBh, 0, 121321h
	count = ($-var1)/TYPE var1		; put two DWORD¡@together

.code

main PROC
; flags
; carry
; zero					ZF
; signed flag			SF = 1: sign change
	mov eax, 0ffffffffh
	inc eax
	call DumpRegs
	call ReadInt			; change ZF not SF
	
	;mov eax, 1
	;mov ebx, 07fffffffh
	;add eax, ebx
	;jnz L1

	;mov edz, offset msg
	;call WriteStrin
	;L1:
	;	call DumpRegs		; change SF not ZF
	exit
main ENDP
END main