#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void) {
	char	*filepath = "./sample.txt";
	int	fd = open(filepath, O_RDONLY);
	char	*s = "";
	for (size_t i = 0; s; i++)
	{
		s = get_next_line(fd);
		printf("line%zu: %s\n", i, s);
		free(s);
	}
	close(fd);
	system("leaks -q a.out");
	return (0);
}
