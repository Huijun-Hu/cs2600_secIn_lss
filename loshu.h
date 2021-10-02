#include <stdio.h>
#include <stddef.h>

typedef struct{
    int const squareArr[3][3];

    int col1sum;
    int col2sum;
    int col3sum;

    int row1sum;
    int row2sum;
    int row3sum;

    int dia1sum;
    int dia2sum;

} LoshuSquare, *PtrToLoshuSquare;

typedef const LoshuSquare *PtrToConstLoshuSquare;
