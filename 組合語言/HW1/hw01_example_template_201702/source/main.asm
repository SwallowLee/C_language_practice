TITLE MASM Template						(main.asm)

; 
;========================================================
; Student Name:	§õ¨Î¿P
; Student ID:	0416039
; Email:		girlannie123@gmail.com
;========================================================
; Instructor: Sai-Keung WONG
; Email: cswingo@cs.nctu.edu.tw
; Assembly Language 
; Date: 2017/02/21
;========================================================
; Description:
;
; 
; Compute the sum of 1, 2, 3, 4, ...
; Maximum number of terms is 10.
;
; There is no error checking! 
; Revision date:

INCLUDE Irvine32.inc
INCLUDE macros.inc

.data

MAX = 10 ;maximum number of terms
NUM		DWORD	?
ONE		REAL8	1.0
VALUES	REAL8	MAX DUP(?) ; array for storing values
TERM	REAL8	0.0
SUM		REAL8	0.0
.code
main PROC

	mWrite "My Student Name: Sai-Keung Wong"
	mWrite "My Student ID: 0123456789"
	mWrite "My Student Email: cswingo@cs.nctu.edu.tw"
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;Input an integer
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
L0:
	mWrite "Please enter the number of terms (1-10):"
	call ReadInt	; read an integer
	cmp EAX, MAX	; compare eax to MAX
	ja L0			; above
	cmp EAX, 0		; compare eax to 0
	jbe L0			; below or equal
	;
	mWrite "Computing SUM......"
	;
	mov NUM, eax		; store number of terms to NUM
	mov ecx, eax		; move value of eax to ecx. ECX is the loop counter
	mov eax, 0			; set eax as ZERO
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;Compute the value for the n-th term 
	;and store it to the array VALUE
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
L1:
	finit				;reset FPU
	fld TERM			;load current TERM value FPU; ST(0) = term
	fld ONE				;load ONE to FPU; ST(0) = one, ST(1) = term
	fadd 				;add ST(1) to ST(0)
	fstp	VALUES[eax]	;store ST(0) to VALUES[eax], and pop ST(0).
	;
	finit				;reset FPU
	fld		VALUES[eax]	;load VALUES[eax] to FPU; ST(0) = VALUES[eax]
	fstp TERM			;store ST(0) to TERM, and pop ST(0)
	add eax, 8			;add 8 to eax. eax points to the next REAL8 element
	loop L1				;go to L1 until ecx = 0
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;Compute sum = VALUES[0] + VALUES[8] + ...
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	mov eax, 0
	mov ecx, NUM		; set loop counter
L2:
	finit				;reset FPU
	fld VALUES[eax]		;load VALUES[eax] to FPU; ST(0) = VALUES[eax]
	fld SUM				;load SUM to FPU; ST(0) = SUM, ST(1) = VALUES[eax]
	fadd				;add ST(1) to ST(0). i.e. ST(0) += ST(1)
	fstp SUM			;store ST(0), i.e., the current sum, to SUM; pop ST(0)
	add eax, 8			;point to next term of VALUES
	loop L2				;loop until ecx = 0
	
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;print the sum
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	finit				;reset FPU
	fld SUM				;load TERM to FPU; ST(0) = TERM
	call WriteFloat		;show ST(0)
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;exit program
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	call ReadInt		;block the program
	INVOKE ExitProcess, 0
main ENDP

END main