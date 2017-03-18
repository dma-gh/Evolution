#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	void runSimulation(long goal, long startPoint, int visible, int mod);

	int main(int argc, char *argv[]) {
		int printresults ;
		printresults = (argc > 3 ? 0 : 1) ; /*if a third option is chosen then it doesn't prints the results  */
		srand(time(NULL));
		runSimulation(atoi(argv[2]), atoi(argv[1]), printresults, 1);

		return 0;
	}

	/*This programm uses the equation to make */
	/* a' = a (operator) b */

	void runSimulation(long goal, long startPoint, int visible, int mod) {
		long count = 0;

		while(startPoint != goal) {
			count++;
			long oper = rand() % (4 + mod);			/* Gets operator randomly		*/
			long range = (rand() % 100) + 1;		/* Gets b out of random range   */
			char voper = 'E';

			switch(oper) {
				case 0:
					startPoint = startPoint + range;
					voper = '+';
					break;
				case 1:
					startPoint = startPoint - range;
					voper = '-';
					break;
				case 2:
					startPoint = startPoint * range;
					voper = '*';
					break;
				case 3:
					startPoint = startPoint / range;
					voper = '/';
					break;
				case 4:
					startPoint = startPoint % range;
					voper = '%';
					break;
			}

			if(visible) {
				printf("%c %ld = %ld\n", voper, range, startPoint);
			}
		}

		printf("It took %ld iterations to reach the goal of %ld\n",
			count, goal);
	}
