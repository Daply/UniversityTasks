package java_programming.lab7_8.task2;

public class FirstRobot implements FirstGrRobotInterface {
	protected int[] commands;
	protected ControllArea area;

	public FirstRobot(ControllArea area) {
		this.area = area;
	}

	@Override
	public boolean executeCommand(int command, int place1, int place2) {
		switch (command) {
			case 1:
				lookRight(place1, place2);
				break;
			case 2:
				lookLeft(place1, place2);
				break;
			case 3:
				lookFront(place1, place2);
				break;
			case 4:
				lookBack(place1, place2);
				break;
			default:
				return true;
		}
		return true;
	}

	public void lookLeft(int r, int c) {
		area.checkIsExist(r, c);
		if (c + 1 < area.cols)
			area.setFlag(r, c + 1, 1);

	}

	public void lookRight(int r, int c) {
		area.checkIsExist(r, c);
		if (1 <= c)
			area.setFlag(r, c - 1, 1);

	}

	public void lookFront(int r, int c) {
		area.checkIsExist(r, c);
		if (r + 1 < area.rows)
			area.setFlag(r + 1, c, 1);
	}

	public void lookBack(int r, int c) {
		area.checkIsExist(r, c);
		if (1 <= r)
			area.setFlag(r - 1, c, 1);
	}

}

