package java_programming.lab7_8.task2;

public class AreaControllingFirstGrRobots {
	FirstGrRobotInterface rob;
	int place1;
	int place2;

	protected AreaControllingFirstGrRobots(FirstGrRobotInterface rob, int place1, int place2) {
		this.place1 = place1;
		this.place2 = place2;
		this.rob = rob;
	}

	public boolean executeCommand(int command1) {
		rob.executeCommand(command1, place1, place2);
		return true;
	}

}
