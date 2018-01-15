#include <stdio.h>
void swap(int * x,int * y); //declaration of function
int main(){
	//The classic example of understanding importance of pointers
	//everytime we call a function we are creating new variables and hence it is impossible to swap values of original variables
	int a=5;
	int b=10;
	
	printf("Before swap a was %d\n",a);
	printf("Before swap b was %d\n",b);
	
	swap(&a,&b);
	
	printf("After swap a was %d\n",a);
	printf("After swap b was %d\n",b);
	
	
	
}

void swap(int * x,int * y){
	
	int temp=*x;
	*x=*y;
	*y=temp;
	
}