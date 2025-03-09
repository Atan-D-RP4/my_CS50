# 8085 Assembly Language Program for adding two 8-bit numbers
MVI C, 00
LDA 9000
MOV B, A
LDA 9001
ADD B
JNC NEXT
INR C
NEXT: STA 9002
MOV A, C
STA 9003
HLT

#8000 0E
#8001 00
#8002 3A
#8003 00
#8004 90
#8005 47
#8006 3A
#8007 01
#8008 90
#8009 80
#800A D2
#800B 0E
#800C 80
#800D 0C
#800E 32
#800F 02
#8010 90
#8011 79
#8012 32
#8013 03
#8014 90
#8015 76
