#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	char *str;
	int fd = open("file.txt", O_RDONLY);

	str = get_next_line(fd);
	printf("%s", str);
	free(str);
}
