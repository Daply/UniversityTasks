package java_programming.lab7_8.task2;

public class AreaControllingSecondGrRobots {
	SecondGrRobotInterface rob;
	int place1;
	int place2;

	protected AreaControllingSecondGrRobots(SecondGrRobotInterface rob, int place1, int place2) {
		this.place1 = place1;
		this.place2 = place2;
		this.rob = rob;
	}

	public boolean executeCommand(int placeOn1, int placeOn2) {
		if (rob.executeCommand(place1, place2, placeOn1, placeOn2))
			return true;
		else
			throw new ExceptionInInitializerError("Robot cant go there");
	}

}
