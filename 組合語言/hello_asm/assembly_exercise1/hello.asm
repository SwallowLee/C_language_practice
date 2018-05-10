TITLE hello

INCLUDE Irvine32.inc
INCLUDE Macros.inc

.data
	buffer BYTE "Hello ASM!", 0

.code

main PROC
	mov edx, offset buffer
	call Writestring
	call Crlf
	call ReadInt
	exit
main ENDP
END main