package java_programming.lab7_8.task2;

public class FourthRobot implements SecondGrRobotInterface {
	protected int[] commands;
	protected ControllArea area;

	public FourthRobot(ControllArea area) {
		this.area = area;
	}

	@Override
	public boolean executeCommand(int place1, int place2, int placeOn1, int placeOn2) {
		int x = place1;
		int y = place2;
		int x1 = placeOn1;
		int y1 = placeOn2;
		int x0 = x;
		int y0 = y;
		int X = 0;
		int Y = 0;
		int flag = 0;
		while (x0 < area.rows && y0 < area.cols) {

			for (int i = 0; i < area.rows; i++) {
				if ((x1 + i == x0 && y1 + i == y0) || (x1 - i == x0 && y1 - i == y0) ||
						(x1 - i == x0 && y1 + i == y0) || (x1 + i == x0 && y1 - i == y0)) {
					X = x0;
					Y = y0;
					flag = 1;
				}
			}
			y0++;
			x0++;
		}
		if (flag == 0) {
			return false;
		}
		while (x <= X && y <= Y) {
			area.setFlag(x, y, 2);
			y++;
			x++;
		}
		area.setFlag(placeOn1, placeOn2, 2);
		return true;
	}

}
