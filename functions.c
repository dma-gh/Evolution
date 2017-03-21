#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
	int deviation(int x,int goal)
	{
		return abs(x - goal) ;
	}

	double fitness(int x ,int goal)
	{
		return (1 / ((deviation(x,goal) + 1.0)) ) ;
	}

	char operate(long *a,long range)
	{
		char operator ;
		char oper = rand() % (OP_NUM + 1) ;
		switch(oper) {
			case 0:
				*a = *a + range;
				operator = '+';
				break;
			case 1:
				*a = *a - range;
				operator = '-';
				break;
			case 2:
				*a = *a * range;
				operator = '*';
				break;
			case 3:
				*a = *a / range;
				operator = '/';
				break;
			case 4:
				*a = *a % range;
				operator = '%';
				break;
		}
		return operator ;
	}
