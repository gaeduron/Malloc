#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i;
	char addr[1];

	i = 0;
	while (i < 1024)
	{
		addr[0] = 42;
		i++;
	}

	printf("The end");
	return (0);
}
