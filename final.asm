include number.asm
include macros2.asm

.MODEL LARGE
.386
.STACK 200h

.DATA
_0                                 	dd	0.00
_1                                 	dd	1.00
_2                                 	dd	2.00
_3                                 	dd	3.00
_52                                	dd	52.00
_6                                 	dd	6.00
_Hola                              	db	Hola                               , '$', 4 dup (?)
_condicion                         	db	condicion                          , '$', 9 dup (?)
a                                  	dd	?
b                                  	dd	?
c                                  	dd	?
d                                  	dd	?
e                                  	dd	?
f                                  	dd	?
g                                  	dd	?
h                                  	dd	?
i                                  	dd	?

.CODE
START:
MOV EAX, @DATA
MOV DS, EAX
MOV ES, EAX

FLD _1
FSTP a
FLD _2
FSTP b
FLD _1
FLD _2
FADD
FSTP c
DisplayFloat c, 2
newline 1
GetFloat g
_ET_10:
FLD a
FLD _6
FXCH
FCOM
FSTSW AX
SAHF
FFREE
JNB _ET_33
FLD a
FLD _1
FADD
FSTP a
DisplayString _Hola
newline 1
FLD _0
FSTP c
_ET_22:
FLD c
FLD _3
FXCH
FCOM
FSTSW AX
SAHF
FFREE
JNB _ET_33
DisplayFloat c, 2
newline 1
FLD c
FLD _1
FADD
FSTP c
JMP _ET_10
_ET_33:
JMP _ET_10
_ET_35:
FLD a
FLD _52
FXCH
FCOM
FSTSW AX
SAHF
FFREE
JNB _ET_41
DisplayString _condicion
newline 1
_ET_41:

MOV EAX, 4C00H
INT 21h
END START