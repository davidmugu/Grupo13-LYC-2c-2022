include number.asm
include macros2.asm

.MODEL LARGE
.386
.STACK 200h

.DATA
_1                                 	dd	1
_6                                 	dd	6
a                                  	dd	?

.CODE
START:
MOV EAX, @DATA
MOV DS, EAX
MOV ES, EAX

FLD _1
FSTP a
_ET_2:
FLD a
FLD _6
FXCH
FCOM
FSTSW AX
SAHF
FFREE
JNB _ET_9
DisplayFloat Hola, 2
newline 1
JMP _ET_6
_ET_9:

MOV EAX, 4C00H
INT 21h
END START