#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define OP_NUM 5 /* Number of operators */
#define RANGE 100 /* Define range of b */

	void runSimulation(long goal, long startPoint, int showEquations, int showDeviation, int mod);

	int main(int argc, char *argv[]) {

		int showEquations = 1;
		int showDeviation = 0;

		if(argc > 3) {
			showEquations = atoi(argv[3]);
			showDeviation = atoi(argv[4]);
		}
		if(argc > 5){
			srand(atoi(argv[6])) ;
		}
		else
		{
			srand(time(NULL));
		}

		runSimulation(atoi(argv[2]), atoi(argv[1]), showEquations, showDeviation, 1);

		return 0;
	}
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
	/*This program uses the equation to make */
	/* a' = a (operator) range */

	void runSimulation(long goal, long startPoint, int showEquations, int showDeviation, int mod) {
		long count = 0;

		while(startPoint != goal) {
			count++;
			long range = (rand() % 100) + 1;		/* Gets b out of random range   */
			char voper = 'E';
			voper = operate(&startPoint ,range) ;

			if(showEquations) {
				printf("%c %ld = %ld\n", voper, range, startPoint);
			}

			if(showDeviation) {
				printf("Fitness : %f\n",fitness(startPoint,goal)); /* Prints fitness function */
			}
		}

		printf("It took %ld iterations to reach the goal of %ld\n", count, goal);
	}
