
/*
Switch Source Code File
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>


void datatransfer(int state, int event)
{
	printf("Enter datatransfer function %d %d\n", state, event);
}


void defaulthandler(int state, int event)
{
	printf("Enter defaulthandler function %d %d\n", state, event);
}

void callrelease(int state, int event)
{
	printf("Enter callrelease function %d %d\n", state, event);
}

void callsetup(int state, int event)
{
	printf("Enter callsetup function %d %d\n", state, event);
}

void callanswer(int state, int event)
{
	printf("Enter call answer function %d %d\n", state, event);
}


void handle(int state, int event)
{
	switch (state)
	{
		case 0 :
			switch (event)
			{
				case 0:
					defaulthandler(state, event);
					break;
				case 1:
					datatransfer(state, event);
					break;
				case 2:
					callrelease(state, event);
					break;
				case 3:
					callsetup(state, event);
					break;
				case 4:
					callanswer(state, event);
					break;
			}
			break;
		case 1 :
			switch (event)
			{
				case 0:
					defaulthandler(state, event);
					break;
				case 1:
					datatransfer(state, event);
					break;
				case 2:
					callrelease(state, event);
					break;
				case 3:
					callsetup(state, event);
					break;
				case 4:
					callanswer(state, event);
					break;
			}

			break;
	}
}

int main(int argc, char *argv[])
{
	int state;
	int event;

	for(;;)
	{
		printf("enter state and event \n");
		scanf("%d", &state);
		scanf("%d", &event);
		handle(state, event);
	}
	return 1;
}
