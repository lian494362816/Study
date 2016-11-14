#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fdr, fdw;
	char buf[128];
	int ret = 1;

	umask(0);
	fdr = open(argv[1], O_RDONLY);

	fdw = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 00644);

	while(ret > 0)
	{
		ret = read(fdr, buf, sizeof(buf));
		write(fdw, buf, ret);
	}

	close(fdr);
	close(fdw);

	return 0;
}