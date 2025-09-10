#include <stdio.h>

int main(void) {

    printf(
        "\x1B[3;3H**********"
        "\x1B[4;3H*        *"
        "\x1B[5;3H*        *"
        "\x1B[6;3H*        *"
        "\x1B[7;3H*        *"
        "\x1B[8;3H**********"
    );

    return 0;
}
