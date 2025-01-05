#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
/* Custom graphics library; credit goes to bisqwit*/
static void SetGFX() { _asm { mov ax,0x13; int 0x10 } }
static void SetText() { _asm { mov ax,0x3; int 0x10 } }
static unsigned char _far* VRAM = (unsigned char _far*) 0xA0000000UL;
static void PutPixel (unsigned x, unsigned y, int c) {VRAM[y*320+x] = c;}
static int KeyPressed(){
       int temp =0;
       _asm{
	 mov ax, 0x0;
	 int 0x16
	 mov temp, ax
       }
       return temp;
}
/* end library */

static const unsigned Width=320, Height=200;
int random(unsigned x)
{
  return rand() % x;
}
int main()
{
   int i=1; unsigned x,y=0;
   char ch=0;
   SetGFX();
   do{
     for (y=1; y<Height; ++y)
	 for(x=1; x<Width; ++x){
		PutPixel(x,y,0);
		if ((x ^ y) %i) {
		PutPixel(x,y,15);
	       }
	  }
      ch = KeyPressed();
      if (ch == 27) break;
      ++i;
   } while (i < 100);
   SetText();
   return 0;
}