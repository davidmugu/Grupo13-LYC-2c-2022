include number.asm
include macros2.asm

.MODEL LARGE
.386
.STACK 200h

.DATA
_1                                 	dd	1
_5                                 	dd	5
_6                                 	dd	6
_90                                	dd	90

.CODE
START:
MOV EAX, @DATA
MOV DS, EAX
MOV ES, EAX

_ET_0:
FLD a
FLD 6
FLD 5
FSTP a
_ET_5:
FLD c
FLD 90
FLD c
FLD 1
FADD
FSTP c
JMP _ET_0
_ET_13:
JMP _ET_0
_ET_16:

MOV EAX, 4C00H
INT 21h
END START