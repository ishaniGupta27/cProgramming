#include <unistd.h> //defines miscellaneous symbolic constants and types, and declares miscellaneous functions.
#include <stdlib.h> // standard library definitions
#include <stdio.h> //input output

/*
 * program to find the average value of a set of random numbers
 *
 * usage: avg-nothread count
 *
 * where count is the number of random values to generate
 */

char *Usage = "usage: avg-nothread count";

#define RAND() (drand48()) /* basic Linux random number generator */
//argc is count of total command line arguments
//**argv or *argv[] is array of character string of each command line argument passed to executable on execution.
int main(int argc, char *argv[])
{
	//we can see total arguments count is internally maintained by “argc” parameter 
	//argv is array of strings 
	int i;
	int n;
	double *data;
	double sum;
	int count;

	//argv[0] is always the executable name whereas from arg[i] where i>0 ..they are actual parameters.
	count = atoi(argv[1]);	/* count is first argument */  //argv(1) will be string and atoi converts it to int

	/*
	 * make an array large enough to hold #count# doubles
	 */
	data = (double *)malloc(count * sizeof(double));

	/*
	 * pick a bunch of random numbers
	 */
	for(i=0; i < count; i++) {
		data[i] = RAND();
	}

	sum = 0;
	for(i=0; i < count; i++) {
		sum += data[i];
	}

	printf("the average over %d random numbers on (0,1) is %f\n",
			count, sum/(double)count);

	return(0);
}
