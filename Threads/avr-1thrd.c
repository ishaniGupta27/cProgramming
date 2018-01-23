#include <stdio.h>
#include <pthreads.h>

#define Rand() (drand48())
/*
The standard as implemented for Linux specifies that
the entry point funtion take one argument that is of type (void *)
the entry point function return a single argument that if of type (void *)
This typing specification can cause some confusion if you are not entirely comfortable with C 
pointers so it is important to try and understand why it is defined this way. 
In C, a (void *) pointer is that can legally point to any data type.
 The key is that your program can make the decision about what it points to at run time. 
That is, a a (void *) tells the compiler that your program will determine the type at run time
 under program control

*/
//I could have taken global variable but instead, it is better to make threads work on local variables.
struct arguments_struct{
	int size;
	double *dataArr;//point towards the data array
}

struct results_sum{
	double result;
}
void *MinionThreadForSum(void *arg){//mandatory by pthreads to get void* argument and return void* results
	struct arguments_struct  *minionThreadArg;
	minionThreadArg=(struct arguments_struct *)arg;//manual type casting//unmarshalling
	
	int minionThreadSize=(*minionThreadArg).size;
	double *minionThreadData=(*minionThreadArg).dataArr;
	
	free(minionThreadArg);//prevent mempry leak;
	
	double minionThreadSum=0.0;
	for(i=0; i < minionThreadSize; i++) {
			minionThreadSum += minionThreadData[i];
		}
		
		//I idea of marshalling the result to give it back in the form of void*
		struct results_sum *minionThreadRes;
		minionThreadRes=(struct result_struct *)malloc(sizeof(struct result_struct));
		minionThreadRes.result=minionThreadSum;
		
		return ((void *)minionThreadRes);
		
}
//this is the "main thread"
int main(int argc,char *argv[]){
	//we will keep an array of random numbers with size count
	double *arrRandNum;//here arrRandNum is a pointer 
	int count=atoi(argv[1]);
	pthread_t thread_id;
	struct arguments_struct *args;
	struct results_sum *result;
	arrRandNum=(double *)malloc(count*sizeof(double));//This is where dynamic memory allocation is done
	
	for(int i =0;i<count;i++){
		arrRandNum[i]=Rand();
	}
	
	//I have to marshall the arguments here.
	args=(struct arguments_struct *)malloc(sizeof(struct arguments_struct));//allocated memory to thread arguments
	(*args).size=count;
	(*args).dataArr=arrRandNum;
	pthread_t thread_id;
	//I am going to run an individual thread which do the sum of the numbers in arr.
	err= pthread_create(&thread_id,NULL, MinionThreadForSum, (void *) args);// am marshalling the thread arguments and spawning the thread.
	//first arg: pointer to a varible of type pthread_t;
	//second arg: point to structure indicating scheduling
	//third arg: entry point of thread
	//fourth arg: a single pointer to the arguments as a (void *)
  //return is the error code ---0 :success
	
	err=pthread_join(thread_id,(void **)&result);//what is happenign here??
	//pthread_join blocks the ongoing thread till the called thread (one with thread id) is terminated.Return 0 if successful.
	
	pritnf((*result).result);//the arguent sent to join give the locationof the result from the thread terminated by the join.
	
	free(result);
	free(arrRandNum);
	
	return(0);
}