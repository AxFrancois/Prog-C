/*
01/10/21
TP2, ex 2.2

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that verify if 4th and 20th left bits are 1
*/
#include <stdio.h>

int main(){
	int d = 524296; //548872
	int mask1 = 524288;
	int mask2 = 8;
	printf("%d \n", ((d & mask1) && (d & mask2)) ? 1:0);
}	
