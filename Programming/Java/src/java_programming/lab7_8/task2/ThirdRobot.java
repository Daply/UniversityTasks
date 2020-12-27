package java_programming.lab7_8.task2;

public class ThirdRobot implements SecondGrRobotInterface {
	protected int[] commands;
	protected ControllArea area;

	public ThirdRobot(ControllArea area) {
		this.area = area;
	}

	@Override
	public boolean executeCommand(int place1, int place2, int placeOn1, int placeOn2) {
		int x = place1;
		int y = place2;
		while (y != placeOn2) {

			area.setFlag(x, y, 2);
			y++;
		}
		while (x != placeOn1) {

			area.setFlag(x, y, 2);
			x++;
		}
		if (x == placeOn1)
			area.setFlag(x, y, 2);
		return true;
	}

}