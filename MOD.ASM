   .MODEL TINY
   .CODE

ORG 100h
START:
   mov al, 13h          ; graphic mode
biosint:
   int 10h		; bios interrupt
   and cl,ch            ; bitwise operation magic
   in al,60h            ; read byte from keyboard
   daa                  ; decrease counter
   mov ah,0ch           ; putpixel
   loopnz biosint   	; draw pixel
   mov  ah,4ch          ;DOS terminate program function
   int  21h             ;terminate the program
END START
