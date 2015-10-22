
/*
 * File:    isumit.c 
 * Purpose: to sum the integers from stdin
 * Author:  pc2@ecs.csus.edu or http://www.ecs.csus.edu/pc2
 *
 * Thu Oct  2 20:27:08 PDT 2003
 *
 * $Id: isumit.c 1962 2009-11-25 03:42:12Z boudreat $ 
 *
 */

#include <stdio.h>

#define INFILENAME "sumit.dat"

main ()
{
	int sum = 0;
	int i;

	while (1==fscanf(stdin, "%d", &i))
	{
		sum += i > 0 ? i : 0;
	}
	printf("The sum of the positive integers is %d \n",sum);

}

/* eof isumit.c $Id: isumit.c 1962 2009-11-25 03:42:12Z boudreat $ */
