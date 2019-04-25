#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>

void *ft_malloc(size_t len)
{
	return mmap(0, len, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
}

int main(int ac, char **av)
{
	int i;
	int nb;
	char c;
	char *str;

	nb = atoi(av[2]);
	c = av[1][0];

	str = (char *)ft_malloc(nb + 1);

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
