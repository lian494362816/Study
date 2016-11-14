#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <shadow.h>
#include <crypt.h>
#include <time.h>
#include <dirent.h>
#include <glob.h>
#include <signal.h>
#include <sys/wait.h>

#define INFORMATION   do{					\
		printf("file: %s\n", __FILE__);		\
		printf("func: %s\n", __func__);		\
		printf("line: %d\n", __LINE__);		\
}while(0)

#define ERRP(condition, string, ret) do{	\
		if(condition)						\
		{									\
			printf(#string" failed\n");		\
			INFORMATION;					\
			ret;							\
		}									\
}while(0)

void p1(void)
{
	printf("p1\n");
}

void p2(void)
{
	printf("p2\n");
}

void p3(void)
{
	printf("p3\n");
}


int main(int argc, char **argv)
{
	p1();
	p2();
	p3();

	atexit(p1);
	atexit(p2);
	atexit(p3);
	return 0;
}