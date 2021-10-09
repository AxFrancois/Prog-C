/*
24/09/21
TP1, ex 1.3

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program to display size of every data type
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	printf("unsigned char : size %ld, min %d, max %d \n", sizeof (unsigned char), 0, UCHAR_MAX);
	printf("signed char %ld, min %d, max %d \n", sizeof (signed char), SCHAR_MIN, SCHAR_MAX);
	printf("unsigned short %ld, min %d, max %d \n", sizeof (unsigned short), 0, USHRT_MAX);
	printf("unsigned short %ld, min %d, max %d \n", sizeof (signed short), SHRT_MIN, SHRT_MAX);
	printf("unsigned int %ld, min %d, max %d \n", sizeof (unsigned int), 0, UINT_MAX);
	printf("signed int %ld, min %d, max %d \n", sizeof (signed int), INT_MIN, INT_MAX);
	printf("unsigned long int %ld, min %d, max %ld \n", sizeof (unsigned long int), 0, ULONG_MAX);
	printf("signed long int %ld, min %ld, max %ld \n", sizeof (signed long int), LONG_MIN, LONG_MAX);
	printf("unsigned long long int %ld, min %d, max %lld \n", sizeof (unsigned long long int), 0, ULLONG_MAX);
	printf("signed long long int %ld, min %lld, max %lld \n", sizeof (signed long long int), LLONG_MIN, LLONG_MAX);
	printf("float %ld, min %f, max %f \n", sizeof (float), FLT_MIN, FLT_MAX);
	printf("double %ld, min %f, max %f \n", sizeof (double), DBL_MIN, DBL_MAX);
	printf("long double %ld, min %Lf, max %Lf \n", sizeof (long double), LDBL_MIN, LDBL_MAX);
}
