#include <stdio.h>

int main(){
	printf("Hello,World\n");
	//Printing fahr and celsius from 0 to 300 with 10 steps
	int fahr,celsius;
	int lowerLimit,upperLimit,step;
	
	lowerLimit=0;
	upperLimit=300;
	step=10;
	
	fahr=lowerLimit;
	
	while(fahr<=upperLimit){
		celsius=5*(fahr-32)/9;
		printf("%d\t%d\n",fahr,celsius);
		fahr=fahr+step;
	}
	
}