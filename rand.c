#include <stdio.h>
#include <stdlib.h>

	void runSimulation(int goal, int live);

	int main() {
		runSimulation(57324985, -43255);
		return 0;
	}

	void runSimulation(int goal, int live) {
		long count = 0;

		while(live != goal) {
			count++;
			int oper = rand() % 4;
			double range = rand() % 100;

			switch(oper) {
				case 0:
					live = live + range;
					break;
				case 1:
					live = live - range; 
					break;
				case 2:
					live = live * range;
					break;
				case 3:
					live = live / range;
					break;
			}
		}

		printf("It took %ld iterations to reach the goal of %d\n",
			count, goal);
	}