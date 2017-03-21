#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <modes.h>
#include <types.h>
#include <cglob.h>

sig_handler(signal_code sig)
	{
	
	switch (sig)
		{
		case 400 : printf("P3:	Case 400\n");
	 	break;
		
		case 500 : printf("P3:	Case 500\n");
		break;

		case 600 : printf("P3:	Case 600\n");
	 	break;
		
		case 700 : printf("P3:	Case 700\n");
		break;
	   }

	_os_rte();
	}
main()
	{
	 error_code err;
	 u_int32 num_ticks;
	 signal_code dummy_sig;

	if ((err = _os_intercept(sig_handler, _glob_data)) != 0)
		exit(err);
		num_ticks = 40000;
		_os_sleep(&num_ticks, &dummy_sig);
		

}



