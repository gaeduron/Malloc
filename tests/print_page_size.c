#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("Pages are currently: %d Bytes\n\n", getpagesize());
	return (0);
}
