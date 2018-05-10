TITLE Floating Point Unit

;Generate a set of number from 1 to n and store them in an array
;1, 2, 3, 4, ..., n

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
	mov eax, 1
	mov ebx, 0
	mov esi, offset v
	L1:
		mov [esi+TYPE v*ebx], eax    ; = [esi+ebx] = v[ebx]
		add ebx, 1
		add eax, 1      ; inc eax
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