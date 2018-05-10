TITLE Floating Point Unit

;Generate a set of number from 1 to n and store them in an array
;2*1, 2*2, 2*3, ..., 2*n

Include Irvine32.inc
Include Macros.inc

num = 10    ;named constant
maxNum = 1000

.data

n	DWORD	num
v	DWORD	maxNum DUP(?)

.code

main PROC
	call generateNumbers
	call showNumbers
	exit
main ENDP

generateNumbers PROC
	mov ecx, n
	mov eax, 2
	mov ebx, 0
	mov esi, offset v
	L1:
		mov edx, eax
		shl edx, 1     ; if 2=>16(1*16, 2*16, ...), then shl edx, 4
		mov [esi+TYPE v*ebx], edx    ; = [esi+ebx] = v[ebx] ;shift
		add ebx, 1
		add eax, 1      ; or + eax by 2 every times
		loop L1
	ret
generateNumbers ENDP

showNumbers PROC
	mov ecx, n
	mov eax, 1
	mov ebx, 0
	mov esi, offset v
	L1:
		mov eax, [esi+TYPE v*ebx]
		add ebx, 1
		call WriteDec
		call crlf
		loop L1
	call ReadInt
	ret
showNumbers ENDP

END main 