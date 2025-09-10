#include <stdio.h>
#include <math.h>

int drawPoint(int x, int y) {
    printf(
        
        "\x1B[%d;%dH**********"
        "\x1B[%d;%dH*        *"
        "\x1B[%d;%dH*        *"
        "\x1B[%d;%dH*        *"
        "\x1B[%d;%dH*        *"       
        "\x1B[%d;%dH**********",
        y, x,           
        y + 1, x,        
        y + 2, x,         
        y + 3, x,         
        y + 4, x,         
        y + 5, x          
    );
    return 0;
}

int main(void) {
    int posx = 3;
    int posy = 3;

    drawPoint(posx, posy);

    return 0;
}
