#include <stdio.h>

typedef struct //typedef to define structure as a new ds 
{
   int id;
   char * name;

	
} user;

int main(){
 user u1;

 u1.id=1;
 u1.name="John";

 printf("%s\n",u1.name );


}