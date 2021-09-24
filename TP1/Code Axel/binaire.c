#include <stdio.h>

int main(){
	int nombre = 255;
	
	int binarray[20], i;
	for (i = 0; nombre > 0; i++) {
		binarray[i] = nombre%2;
		nombre /= 2;
	}
	for (i -= 1; i >= 0; i--){
		printf("%d", binarray[i]);
	}
}
