#include <stdio.h>
#include <errno.h>
#include <modes.h>
#include <signal.h>
#include <types.h>
#include "CommData.h"

main()
	{
	u_int32 numTicks;
	signal_code dummySignal;
	error_code err;
	path_id pipe_P2;
	u_int32 count;
	struct CommData MyData;


	numTicks = 20000;

	_os_sleep(&numTicks, &dummySignal);
		
	if ((err = _os_open("/pipe/P2", S_IREAD, &pipe_P2)) != 0)
		{
		printf("P2:	No Message availible. \n");
		exit(0);
		}
	count = MESSAGE_SIZE;
	if ((err = _os_read(pipe_P2, &MyData, &count)) !=0)
		{
		printf("Error : Message reading error invalid message?");
		exit(0);
		}
	else
		{
		printf("Message Received\n");
		printf("P2:		Sensor: %s\n", MyData.From);
		printf("P2:		MessageNumber: %d\n", MyData.MessageNumber);
		printf("P2:		Water Info = %s'\n", MyData.Message);
		printf("P2:		Temperature = %d c\n", MyData.Temp);
		printf("P2:		Pressure = %d\n", MyData.Pressure);
		printf("P2:		Valve open:  = %s\n", MyData.ValveOpen);
		printf("P2:		Water Level:  = %d\n", MyData.WaterLevel);

		
		}
	_os_close(pipe_P2);
}