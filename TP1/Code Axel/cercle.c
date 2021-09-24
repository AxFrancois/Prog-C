#include <stdio.h>
#include <math.h>

int main() {
	float rayon = 1;

	float Perimeter = 2*M_PI*rayon;
	float Area = M_PI*rayon*rayon;
	
	printf("Perimeter : %f \n",Perimeter);
	printf("Area : %f \n",Area);
}
