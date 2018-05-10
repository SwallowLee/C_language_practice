TITLE Add and Substract

; This program adds and substracts 32-bit integers

INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data

.code

main PROC
	mov eax, 10000h ; eax = 10000h
	add eax, 40000h ; eax = 50000h
	sub eax, 20000h ; eax = 30000h
	call DumpRegs   ; display registers
	call ReadInt    ; block the program
	exit
main ENDP
END main