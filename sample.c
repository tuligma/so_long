#include <stdio.h>
#include <stdlib.h>

void	reduced(int *x, int *y)
{
	if (*x % 2 == 0 && *y % 2 == 0)
	{
		*x = *x / 2;
		*y = *y / 2;
		printf("Step:	%d / %d --> 2\n", *x, *y);
		reduced(x, y);
	}
	else
	{
		if (*x % 3 == 0 && *y % 3 == 0)
		{
			*x = *x / 3;
			*y = *y / 3;
			printf("Step:	%d / %d --> 3\n", *x, *y);
			reduced(x, y);
		}
		else if (*x % 5 == 0 && *y % 5 == 0)
		{
			*x = *x / 5;
			*y = *y / 5;
			printf("Step:	%d / %d --> 5\n ", *x, *y);
			reduced(x, y);
		}
		else if (*x % 7 == 0 && *y % 7 == 0)
		{
			*x = *x / 7;
			*y = *y / 7;
			printf("Step:	%d / %d --> 7\n", *x, *y);
			reduced(x, y);
		}
		else if (*x % 9 == 0 && *y % 9 == 0)
		{
			*x = *x / 9;
			*y = *y / 9;
			printf("Step:	%d / %d --> 9\n", *x, *y);
			reduced(x, y);
		}
		else
			return ;
	}
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	x = atoi(argv[1]);
	y = atoi(argv[2]);
	printf("Problem:	%d / %d\n", x, y);
	reduced(&x, &y);
	printf("Answer:		%d / %d\n", x , y);
	return (0);
}