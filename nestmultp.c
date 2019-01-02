#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
	nest multiply, to calculate value of a polynomial
	polynomial express: y = c[0] + c[1]*x^1 + c[2]*x^2 + ... + c[n-1]*x^(n-1)
	it can be rewrite as: y = c[0] + x * ( c[1] + x * ( c[2] + x * ( c[3] + x * ( c[4] + ... + x * ( c[n-2] + x * c[n-1])...))))
	generally, add array {r,n}, it can be writed as:
	y = c[0] + (x - r[1]) * ( c[1] + (x - r[2]) * ( c[2] + (x - r[3]) * ( c[3] + (x - r[4]) * ( c[4] + ... + (x - r[n-2]) * ( c[n-2] + (x - r[n-1]) * c[n-1])...))))
*/

long nestmultip(int degree, int *carray, int *rarray, int x);

int main(int argc, char *argv[])
{
	if(argc < 2 || strcmp(argv[1],"--help") == 0 || strcmp(argv[1],"-h") == 0){
		printf("Usage: %s -d degree of polynomial -c carray [-r rarray] -x xvalue\n",argv[0]);
		return 0;
	}
	if(strcmp(argv[1],"-d") != 0){
		printf("the degree must be input\n");
		return 0;
	}
	int degree = atoi(argv[2]);
	int x;
	int carray[degree + 1], rarray[degree];
	memset(carray, 0, sizeof(carray));
	memset(rarray, 0, sizeof(rarray));
	for(int i = 3; i < argc; i++){
		if(strcmp(argv[i], "-c") == 0){
			for(int j = 0; j < degree + 1; j++){
				carray[j] = atoi(argv[i+j+1]);
			}
			i += (degree + 1);
		}else if(strcmp(argv[i], "-r") == 0){
			for(int j=0; j < degree; j++){
				rarray[j] = atoi(argv[i+j+1]);
			}
			i += degree;
		}else if(strcmp(argv[i], "-x") == 0){
			x = atoi(argv[i+1]);
			i++;
		}else{
			printf("parameter error\n");
			return 0;
		}
	}
	long res;
	res = nestmultip(degree, carray, rarray, x);
	printf("result=%d\n",res);
	return 0;
}

long nestmultip(int degree, int carray[], int rarray[], int x)
{
	long y;
	int len = degree + 1;
	y = carray[len-1];
	if(rarray == NULL){
		for(int i = len-1; i > 0; --i){
			y = carray[i-1] + y * x;
		}
	} else{
		for(int i = len-1; i > 0; --i){
			y = carray[i-1] + y * (x - rarray[i-1]);
		}
	}
	return y;
}
