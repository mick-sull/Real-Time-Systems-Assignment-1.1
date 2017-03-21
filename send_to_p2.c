#include <stdio.h>
#include <errno.h>
#include <modes.h>
#include <types.h>
#include <string.h>
#include "CommData.h"

main()
	{
	error_code err;
	path_id pipe_P2;
	u_int32 count;
	u_int32 pipe_size1;
	struct CommData MyData;

	if ((err = _os_create ("/pipe/p2", S_IREAD | S_ISIZE, &pipe_P2, FAP_READ | FAP_GREAD | FAP_WRITE | FAP_GWRITE, 501)) !=0)
	{

		printf("The pipe for the process P2 has a message ready? \n");

		count = MESSAGE_SIZE;
		if (( err= _os_open("/pipe/p2", S_IWRITE, &pipe_P2)) !=0)
		{
			printf("Error -- Cannot open a pipe to send to????\n");
			exit(0);
		}
	}

strcpy(MyData.From,"P0");
MyData.MessageNumber = 2001;
strcpy(MyData.Message, "Water sensor");
MyData.Temp = 34;
MyData.Pressure = 51;
strcpy(MyData.ValveOpen,"Y");
MyData.WaterLevel = 20;
count = MESSAGE_SIZE;

if ((err = _os_write(pipe_P2, &MyData, &count)) != 0)
	printf("Error: write...");

-_os_close(pipe_P2);
}