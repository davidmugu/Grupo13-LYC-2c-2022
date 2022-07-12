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
_ET_15:
FLD a
FLD _6
FXCH
FCOM
FSTSW AX
SAHF
FFREE
FLD BGE
FLD a
FLD _1
FADD
FSTP a
DisplayFloat Hola, 2
newline 1
FLD _0
FSTP c
_ET_29:
FLD c
FLD _3
FXCH
FCOM
FSTSW AX
SAHF
FFREE
FLD BGE
DisplayFloat c, 2
newline 1
FLD c
FLD _1
FADD
FSTP c
JMP _ET_15
_ET_41:
JMP _ET_15
_ET_44:

MOV EAX, 4C00H
INT 21h
END START