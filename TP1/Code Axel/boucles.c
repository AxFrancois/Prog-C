/*
24/09/21
TP1, ex 1.6

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that uses while and for loops to print a triangle
*/

#include <stdio.h>


int main(){
	int compter = 10, cas = 1;
	int a=0;
	if (compter < 4) {
		printf("compter trop petit (doit être supérieur ou égal à 4)\n");
	}
	else{
		switch(cas){
			case 1: //With for loops
				for(a=0; a<compter; a++){
					if (a == 0){
						printf("*\n");
					}
					else if	(a == compter-1){ 
						for(int b=0; b<compter-1; b++){
							printf("*");
						}
						printf("*\n");
					}
					else {
						printf("*");
						for(int b=0; b<a-1; b++){
							printf("#");
						}
						printf("*\n");
					}
				}
			break;
			case 2:	//with while loops
				while (a<compter){
					if (a == 0){
						printf("*\n");
					}
					else if	(a == compter-1){ 
						int b=0;
						while (b<compter-1){
							printf("*");
							b++;
						}
						printf("*\n");
					}
					else {
						printf("*");
						int b=0; 
						while (b<a-1){
							printf("#");
							b++;
						}
						printf("*\n");
					}				
					a++;			
				}
		}
	}	
}
