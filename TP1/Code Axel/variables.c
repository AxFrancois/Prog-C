#include <stdio.h>


int main(){
	unsigned char a = 99;
	signed char b = 0;
	unsigned short c = 9999;
	signed short d = -9999;
	unsigned int e = 999999;
	signed int f = -9999999;
	unsigned long int g = 99999;
	signed long int h = -999999999;
	unsigned long long int i = 9999999999999;
	signed long long int j = -99999999999999;
	float k = 999.998;
	double l = 99999999.27878;
	long double m = 9999999.2782782;

	printf("%c \n",a);
	printf("%c \n",b);
	printf("%u \n",c);
	printf("%i \n",d);
	printf("%u \n",e);
	printf("%d \n",f);
	printf("%lu \n",g);
	printf("%ld \n",h);
	printf("%llu \n",i);
	printf("%lli \n",j);
	printf("%f \n",k);
	printf("%f \n",l);
	printf("%Lf \n",m);
}
