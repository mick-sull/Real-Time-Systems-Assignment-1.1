#include <stdio.h>
#include <errno.h>
#include <process.h>
#include <dexec.h>
#include <types.h>
#include <string.h>
#include <modes.h>
#include "CommData.h"

main(int argc , char * argv[], char **envp)
	{
	error_code err;
	error_code errP2;
	error_code errP3;
	
	process_id p1_pid;
	process_id p2_pid;
	process_id p3_pid;

	status_code child_status;
	status_code child_status2;
	status_code child_status3;


	path_id pipe_P2;
	u_int32 count;
	u_int32 pipe_size1;
	struct CommData MyData;


char * p1_argv[] = {
		"P1",
		"A real-time operating system (RTOS) is an operating system that guarantees a certain capability within a specified time constraint.",
		"For example, an operating system might be designed to ensure that a certain object was available for a robot on an assembly line.",
		"In what is usually called a hard real-time operating system, if the calculation could not be performed for making the object available at the designated time, the operating system would terminate with a failure. ",
		"In a soft real-time operating system, the assembly line would continue to function but the production output might be lower as objects failed to appear at their designated time, causing the robot to be temporarily unproductive. ",
		"Some real-time operating systems are created for a special application and others are more general purpose. " 
};




/* ---------------P1-------------------- */


/* fork p1 process */
if (err = (_os_exec(_os_fork, 0 , 3 , p1_argv[0], p1_argv, envp,0,&p1_pid, 0,0) != 0))
	printf("Error1\n");



/* ---------------P2-------------------- */
 /* fork p2 process */

 if (err = (_os_exec(_os_fork, 0 , 3 , "P2", p1_argv, envp,0,&p2_pid, 0,0) != 0))
	printf("Error1\n");



/* ---------------P3-------------------- */


/* fork p3 process */
if (err = (_os_exec(_os_fork, 0 , 3 ,"P3", p1_argv, envp,0,&p3_pid, 0,0) != 0))
	printf("Error1\n");




/* wait for child P1 */
if (err = (_os_wait(&p1_pid, &child_status) != 0))
	printf("Error1\n");



/* wait for child p2 */
if (err = (_os_wait(&p2_pid, &child_status2) != 0))
	printf("Error2\n");


/* wait for child  p3*/
if (err = (_os_wait(&p3_pid, &child_status3) != 0))
	printf("Error3\n");

								 			
}