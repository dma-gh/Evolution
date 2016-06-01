
public class rand {
	public static void main(String[] args) {
		runSimulation(57324985, -43255);
	}

	public static void runSimulation(int goal, int live) { 
		int count = 0;

		while(live != goal) {
			count++;
			int oper = (int)(Math.random() * 4);
			double range = (Math.random() * 100);

			switch(oper) {
				case 0:
				live *= range;
				break;
				case 1:
				live += range;
				break;
				case 2:
				live -= range;
				break;
				case 3:
				live /= range;
				break;
			}
		}
		System.out.println("It took " + count + " iterations to hit the goal of " + goal);
	}
}