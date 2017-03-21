#include <stdio.h>
#include <signal.h>
#include <types.h> 

main (int argc, char * argv[])
	{
	_os_send(atoi(argv[1]), atoi(argv[2]));

	}