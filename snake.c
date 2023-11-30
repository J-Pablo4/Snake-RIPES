#include "ripes_system.h"

void paint_snake(int*, int, int);
void clean_matrix(int*);

int main(void)
{
    int *leds = LED_MATRIX_0_BASE;
    int *d_pad = D_PAD_0_BASE;
    int offset_v = 12;
    int offset_h = 17;
    int values[4] = {};
    clean_matrix(leds);
    paint_snake(leds, offset_v, offset_h);  
    
   do
   {
       values[0] = *d_pad;
       values[1] = *(d_pad+1)+1;
       values[2] = *(d_pad+2)+2;
       values[3] = *(d_pad+3);
           
       while(values[3])
       {
           values[0] = *d_pad;
           values[1] = *(d_pad+1)+1;
           values[2] = *(d_pad+2)+2;
               
           clean_matrix(leds);
           offset_h +=1;
           offset_h %= LED_MATRIX_0_WIDTH -1;
           paint_snake(leds, offset_v, offset_h);
               
           if(values[0]==1 || values[1]==2 || values[2]==3)
           {
               values[3] = 0;
               break;
           }
        }   
   }while(1);
   return 0;
}

void clean_matrix(int *leds)
{
    for(int x = 0; x < LED_MATRIX_0_HEIGHT; x++)
    {
        for(int y = 0; y < LED_MATRIX_0_WIDTH; y++)
        {
            *(leds +(LED_MATRIX_0_WIDTH*x+y)) = 0;
        }
    }
}

void paint_snake(int *leds, int offset_v, int offset_h)
{
    int x = 0+offset_v;
    int y = 0+offset_h;
    
    *(leds +(LED_MATRIX_0_WIDTH*x+y)) = 0x00ff0000;
    *(leds +(LED_MATRIX_0_WIDTH*(x+1)+y)) = 0x00ff0000;
    *(leds +(LED_MATRIX_0_WIDTH*x+(y+1))) = 0x00ff0000;
    *(leds +(LED_MATRIX_0_WIDTH*(x+1)+(y+1))) = 0x00ff0000;
}
