#include <stdio.h>

int main(){
	int a=5,b=10,c[10];
	int *pt; //will store addresses only hence defined as pointer
	pt= &a;  //allocating the address of the value
	printf("%p\n",pt); //"%p" is he way to print pointer
	
	b=*pt; //dereferencing pointer pt
	
	printf("%d\n",b); //now b is a.
	
	*pt=22; //here pt is keeping the address of a and when *pt ..we derefence to a and we changes a to 22.
	
	printf("%d\n",a); //this is 22
	
	pt=&c[0];
	
	printf("%p\n",pt);//new addres
	
	
}