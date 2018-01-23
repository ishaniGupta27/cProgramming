//Without a makefile, the typical approach to the test/modify/debug cycle is to use the up arrow in a terminal to go back to your last compile command so you don't have to type it each time, especially once you've added a few more .c files to the mix.

//Unfortunately, this approach to compilation has two downfalls. First, if you lose the compile command or switch computers you have to retype it from scratch, which is inefficient at best. Second, if you are only making changes to one .c file, recompiling all of them every time is also time-consuming and inefficient. So, it's time to see what we can do with a makefile--automatic complie dependencies !!
//I am keeping the name of makefile similar to that of my maine function.
int addInt(int a,int b);


//gcc -0 exec_name addingLib.c int_add.c -I

//here -I ensures that it to look in the same folder location for same named make file 