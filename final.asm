include number.asm
include macros2.asm

.MODEL LARGE
.386
.STACK 200h

.DATA
_1                                 	dd	1
_2                                 	dd	2
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

MOV EAX, 4C00H
INT 21h
END START