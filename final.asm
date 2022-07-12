include number.asm
include macros2.asm

.MODEL LARGE
.386
.STACK 200h

.DATA
_0                                 	dd	0
_1                                 	dd	1
_2                                 	dd	2
_3                                 	dd	3
_6                                 	dd	6
_Hola                              	dd	Hola
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

FLD 1
FSTP a
FLD 2
FSTP b
FLD 1
FLD 2
FADD
FSTP c
DisplayFloat c, 2
newline 1
GetFloat g
_ET_15:
FLD a
FLD 6
FXCH
FCOM
FSTSW AX
SAHF
FFREE
FLD BGE
FLD a
FLD 1
FADD
FSTP a
DisplayFloat "Hola", 2
newline 1
FLD 0
FSTP c
_ET_29:
FLD c
FLD 3
FXCH
FCOM
FSTSW AX
SAHF
FFREE
FLD BGE
DisplayFloat c, 2
newline 1
FLD c
FLD 1
FADD
FSTP c
JMP _ET_15
_ET_41:
JMP _ET_15
_ET_44:

MOV EAX, 4C00H
INT 21h
END START