#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	void runSimulation(long goal, long startPoint, long visible, int mod);

	int main(int argc, char *argv[]) {
		srand(time(NULL));
		runSimulation(atoi(argv[2]), atoi(argv[1]), 1, 1);
		
		return 0;
	}

	void runSimulation(long goal, long startPoint, long visible, int mod) {
		long count = 0;

		while(startPoint != goal) {
			count++;
			long oper = rand() % (4 + mod);
			long range = (rand() % 100) + 1;
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
