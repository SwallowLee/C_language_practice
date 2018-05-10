TITLE	Compute pi

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

include Irvine32.inc
include macros.inc

.data

MAX = 100000
ONE		REAL8	1.0
TWO		REAL8	2.0
FOUR	REAL8	4.0
sign	REAL8	1.0
ZERO	REAL8	0.0
minus	REAL8	-1.0
pi		REAL8	0.0
current	REAL8	0.0
previous	REAL8	-1.0

.code
main PROC
	mWrite "My Student Name: §õ¨Î¿P"
	call Crlf
	mWrite "My Student ID: 0416039"
	call Crlf
	;;;;;;;;;;;;;; input integer ;;;;;;;;;;;;;
L0::
	finit											;initial the value
	fld ZERO										;initial the value
	fst pi											;initial the value
	fst current										;initial the value
	fld minus										;initial the value
	fst previous									;initial the value
	fld ONE											;initial the value
	fst sign										;initial the value
	mWrite "Please enter the number of terms:"
	call ReadInt									; read an integer
	cmp eax, MAX									; compare eax to MAX
	ja L3											; if above, go to L3
	cmp eax, 0
	je L4											; if equal 0, go to L4

L1:
	mov ecx, eax									; move value of eax to ecx
	;;;;;;;;;;;;;;; compute pi ;;;;;;;;;;;;;;;;;
L2::
	finit
	fld TWO
	fld previous
	fadd ST(0), ST(1)								; + 2
	fst current
	fst previous
	;;;;;;;;;;;;;;;;;;;;;;;;;
	finit
	fld current
	fld sign
	fdiv ST(0), ST(1)
	fld pi
	fadd ST(0), ST(1)
	fst pi
	fld sign
	fchs											; change sign of sign (ST(0))
	fst sign
	Loop L2
	finit
	fld FOUR
	fld pi
	fmul ST(0), ST(1)								; * 4
	call WriteFloat
	call Crlf
	jmp L0
	
	
L3:
	mov ecx, 100000									; move max value(100000) to ecx
	jmp L2

L4:
	INVOKE ExitProcess, 0
main ENDP
END main