/*
01/10/21
TP2, ex 2.8

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that show pointer of differents data types
*/

#include <stdio.h>


int main(){
	unsigned char a = 99;
	unsigned char *unsigned_char_ptr = &a;
	signed char b = 0;
	signed char *signed_char_ptr = &b;
	unsigned short c = 9999;
	unsigned short *unsigned_short_ptr = &c;
	signed short d = -9999;
	signed short *signed_short_ptr = &d;
 	unsigned int e = 999999;
	unsigned int *unsigned_int_ptr = &e;
	signed int f = -9999999;
	signed int *signed_int_ptdr = &f;
	unsigned long int g = 99999;
	unsigned long int *unsigned_long_int_ptr = &g;
	signed long int h = -999999999;
	signed long int *signed_long_int_ptr = &h;
	unsigned long long int i = 9999999999999;
	unsigned long long int *unsigned_long_long_int_ptr = &i;
	signed long long int j = -99999999999999;
	signed long long int *signed_long_long_int_ptr = &j;
	float k = 999.998;
	float *float_ptr = &k;
	double l = 99999999.27878;
	double *double_ptr = &l;
	long double m = 9999999.2782782;
	long double *long_double_ptr = &m;

	printf("unsigned char %p \n",unsigned_char_ptr);
	printf("signed char %p \n",signed_char_ptr);
	printf("unsigned short %p \n",unsigned_short_ptr);
	printf("signed short %p \n",signed_short_ptr);
	printf("unsigned int %p \n",unsigned_int_ptr);
	printf("signed int %p\n",signed_int_ptdr);
	printf("unsigned long int %p \n",unsigned_long_int_ptr);
	printf("signed long int %p \n",signed_long_int_ptr);
	printf("unsigned long long int %p \n",unsigned_long_long_int_ptr);
	printf("signed long long int %p \n",signed_long_long_int_ptr);
	printf("float %p \n",float_ptr);
	printf("double %p \n",double_ptr);
	printf("long double %p \n",long_double_ptr);
}
