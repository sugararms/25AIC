#include <stdio.h>
#include <Windows.h>


void moveCursor(int x, int y) {
    printf("\x1b[%d;%dH", y, x);
}


void printBomb(int isExploded) {
    if (isExploded) {
        printf("\x1b[A^^^^^^^");
        printf("\x1b[B\x1b[7D!!BAM!!");
        printf("\x1b[B\x1b[7D^^^^^^^");
    }
    else {
        printf("( b )");
    }
}

int main() {
    int x = 14, y = 9;

    
    moveCursor(x, y);
    printf("*");
    Sleep(200);  
    moveCursor(x, y);
    printf(" ");  

   
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };

    
    int step = 2;  
    int dir = 0;   
    for (int loop = 0; loop < 6; loop++) {
        for (int rep = 0; rep < 2; rep++) { 
            for (int i = 0; i < step; i++) {
                x += dx[dir];
                y += dy[dir];
                moveCursor(x, y);
                printf("#");
            }
            dir = (dir + 1) % 4; 
        }
        step += 2; 
    }

   
    moveCursor(x, y);
    printBomb(0);

   
    x = 14; y = 9;
    step = 2; dir = 0;
    for (int loop = 0; loop < 6; loop++) {
        for (int rep = 0; rep < 2; rep++) {
            for (int i = 0; i < step; i++) {
                x += dx[dir];
                y += dy[dir];
                moveCursor(x, y);
                printf("*");  
                Sleep(200);
                moveCursor(x, y);
                printf(" ");  
            }
            dir = (dir + 1) % 4;
        }
        step += 2;
    }

    
    moveCursor(x, y);
    printBomb(1);

    moveCursor(0, 25);
    return 0;
}
