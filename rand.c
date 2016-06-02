#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	void runSimulation(long goal, long startPolong, long visible);

	int main(int argc, char *argv[]) {
		srand(time(NULL));
		runSimulation(atoi(argv[2]), atoi(argv[1]), 1);
		
		return 0;
	}

	void runSimulation(long goal, long startPolong, long visible) {
		long count = 0;

		while(startPolong != goal) {
			count++;
			long oper = rand() % 4;
			long range = (rand() % 100) + 1;
			char voper = 'E';

			switch(oper) {
				case 0:
					startPolong = startPolong + range;
					voper = '+';
					break;
				case 1:
					startPolong = startPolong - range; 
					voper = '-';
					break;
				case 2:
					startPolong = startPolong * range;
					voper = '*';
					break;
				case 3:
					startPolong = startPolong / range;
					voper = '/';
					break;
			}
			
			if(visible) {
				printf("%c %ld = %ld\n", voper, range, startPolong);
			}
		}

		printf("It took %ld iterations to reach the goal of %ld\n",
			count, goal);
	}
