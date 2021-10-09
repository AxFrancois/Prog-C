/*
24/09/21
TP1, ex 1.2

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Area and Perimeter of circle calculation
*/

#include <stdio.h>
#include <math.h>

int main() {
	float rayon = 1;

	float Perimeter = 2*M_PI*rayon;
	float Area = M_PI*rayon*rayon;
	
	printf("Perimeter : %f \n",Perimeter);
	printf("Area : %f \n",Area);
}
