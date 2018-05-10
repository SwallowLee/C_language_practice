TITLE Chapter 4

include Irvine32.inc
include Macros.inc

.data
	msg		BYTE	"This is Chapter 4", 0	
	var1	RWORD	12345678h, 0ABCDEF12h, 3, 4, 5, 6, 7, 8, 0ffh, ofeh
.code

main PROC
	;INVOKE ExitProcess,0	;use INVOKE to call processure
	mov eax, 0
	mov eax, [var1+1]				; eax = 12123456 ¡ö foru bytes
	mov ax, WORD PTR [var1]			; read only two bytes			
	mov ebx, [var1+TYPE var1*1]		; the second one
	mov ecx, [var1+TYPE var1*2]		; the third one
	call DumpRegs
	exit
main ENDP
END main