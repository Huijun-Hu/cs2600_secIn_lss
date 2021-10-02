#include <stdio.h>
#include <stdlib.h>
#include "loshu.h"

void assignSquareElement(PtrToLoshuSquare ptr, int temp[3][3]){

    //ptr->squareArr = temp;
    
    ptr->col1sum = temp[0][0] + temp[1][0] + temp[2][0];
    ptr->col2sum = temp[0][1] + temp[1][1] + temp[2][1];
    ptr->col3sum = temp[0][2] + temp[1][2] + temp[2][2];

    ptr->row1sum = temp[0][0] + temp[0][1] + temp[0][2];
    ptr->row2sum = temp[1][0] + temp[1][1] + temp[1][2];
    ptr->row3sum = temp[2][0] + temp[2][1] + temp[2][2];

    ptr->dia1sum = temp[0][0] + temp[1][1] + temp[2][2];
    ptr->dia2sum = temp[0][2] + temp[1][1] + temp[2][0];
} 

static int checkColumn(PtrToConstLoshuSquare square, int commonSum){
    if (square->col1sum == commonSum && square->col2sum == commonSum && square->col3sum == commonSum)
        return 0;
    else
        return 1;
}
static int checkRow(PtrToConstLoshuSquare square, int commonSum){
    if (square->row1sum == commonSum && square->row2sum == commonSum && square->row3sum == commonSum)
        return 0;
    else
        return 1;
}
static int checkDiagnal(PtrToConstLoshuSquare square, int commonSum){
    if (square->dia1sum == commonSum && square->dia2sum == commonSum)
        return 0;
    else
        return 1;
}

int main(){

    int arr1[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int arr2[3][3] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };

    LoshuSquare s1;
    PtrToLoshuSquare p1;
    p1 = &s1;

    LoshuSquare s2;
    PtrToLoshuSquare p2;
    p2 = &s2;

    printf("...Testing with assigned 2-D arrays...\n\n");

    // is not case
    assignSquareElement(p1, arr1);
    int oneSideSum1 = p1->col1sum;

    for ( int i = 0; i < 3; i++ ){
        printf("[ ");
        for ( int j = 0; j < 3; j++){
            printf("%d ", arr1[i][j]); 
        }
        printf("]\n");
    }
    if (checkColumn(p1, oneSideSum1) == 0 && checkRow(p1, oneSideSum1) == 0 && checkDiagnal(p1, oneSideSum1) == 0)
        printf("It is a Lo Shu Square.\n\n");
    else
        printf("It is Not a Lo Shu Square.\n\n");


    // is case
    assignSquareElement(p2, arr2);
    int oneSideSum2 = p2->col1sum;

    for ( int i = 0; i < 3; i++ ){
        printf("[ ");
        for ( int j = 0; j < 3; j++){
            printf("%d ", arr2[i][j]); 
        }
        printf("]\n");
    }
    if (checkColumn(p2, oneSideSum2) == 0 && checkRow(p2, oneSideSum2) == 0 && checkDiagnal(p2, oneSideSum2) == 0)
        printf("It is a Lo Shu Square.\n\n");
    else
        printf("It is Not a Lo Shu Square.\n\n");

    return(0);
}