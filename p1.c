#include <stdio.h>
#include <errno.h>
#include <process.h>
#include <types.h>

main(int argc , char * argv[])
	{
	u_int32 numTicks;
	signal_code dummySignal;
	int a;
	
   /* for loop execution */
   for( a =1 ; a < 6; a = a + 1 ){
	  numTicks = 4200; 
	  _os_sleep(&numTicks, &dummySignal); 
      printf("P1:	%s\n",argv[a]);
      
      }

	}