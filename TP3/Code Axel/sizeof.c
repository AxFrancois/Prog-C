/*
08/10/21
TP3, ex 3.1

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that print different pointers
*/
#include <stdio.h>

int main(){
    printf("int : %ld \n", sizeof (int));
    printf("int * : %ld \n", sizeof (int *));
    printf("int ** : %ld \n", sizeof (int **));
    printf("char * : %ld \n", sizeof (char *));
    printf("char ** : %ld \n", sizeof (char **));
    printf("char *** : %ld \n", sizeof (char ***));
    printf("float * : %ld \n", sizeof (float *));
    printf("float ** : %ld \n", sizeof (float **));
    printf("float *** : %ld \n", sizeof (float ***));
}
