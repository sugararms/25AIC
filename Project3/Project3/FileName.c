#include <stdio.h>

int main(void) {
    int width = 10;   
    int height = 6;   
    int row, col;

    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            
            if (row == 0 || row == height - 1 || col == 0 || col == width - 1) {
              
                printf("\x1B[%d;%dH#", row + 3, col + 3);
             
            }
        }
    }

    return 0;
}
