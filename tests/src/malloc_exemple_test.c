#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i;
	int nb;
	char c;
	char *str;

	nb = atoi(av[2]);
	c = av[1][0];

	str = (char *)malloc(nb + 1);

	i = 0;
	while (i < nb)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';

	printf("%s", str);
	return (0);
}
