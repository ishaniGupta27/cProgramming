#include <unistd.h> //this is the library
#include <stdlib.h>
#include <stdio.h> 

#include <makefile.h>

int main(int argc, char *argv[]){
	int a=100;
	int b=200;
	//I am calling the function of some other file i.e. int_add here
	printf("the sum of %d and %d is %d \n",a,b,addInt(a,b));
	
}