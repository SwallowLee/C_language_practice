TITLE Floating Point Unit

;Generate a set of number from 1 to n and store them in an array
;[0], 1!, 2!, 3!, ...

Include Irvine32.inc
Include Macros.inc

num = 10    ;named constant
maxNum = 1000

.data

ONE		REAL8	1.0
result	REAL8	maxNum DUP(?)
current_fac		REAL8	?
current_int		REAL8	?
previous_int	REAL8	0.0
previous_fac	REAL8	1.0

.code

main PROC
	call generateNumbers
	call showNumbers
	exit
main ENDP

generateNumbers PROC
	mov ecx, num
	mov ebx, 0
	L1:
		; compute the integer
		finit
		fld ONE
		fld previous_int
		fadd ST(0), ST(1)
		fst current_int
		fst previous_int
		;;;;;;;;;;;;;;;;;;;;;;;
		; n!
		finit
		fld current_int
		fld previous_fac
		fmul ST(0), ST(1)	; previous_fac*current_int
		fst previous_fac
		fld ONE
		fdiv ST(0), ST(1) 
		fst result[ebx]
		add ebx, 8
		Loop L1
		call ReadInt
	ret
generateNumbers ENDP

showNumbers PROC	
	finit
	mov ecx, num
	mov ebx, 0
	L1:
		fld result[ebx]
		call WriteFloat
		call crlf
		add ebx, 8
		Loop L1
		call ReadInt
	ret
showNumbers ENDP

END main 