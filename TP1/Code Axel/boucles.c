#include <stdio.h>


int main(){
	int compter = 10, cas = 1;
	int a=0;
	if (compter < 4) {
		printf("compter trop petit \n");
	}
	else{
		switch(cas){
			case 1:
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
			case 2:
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
