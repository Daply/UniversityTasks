package java_programming.lab7_8.task1;

/**
 * Created by Daria on 26.10.2014.
 */

public class AreaControllingSecondRobot extends FirstRobot {
	protected ControllArea area;
	AbstractRobot robot;
	int place1;
	int place2;
	String name;

	protected AreaControllingSecondRobot(ControllArea area, AbstractRobot robot, int place1, int place2) {
		robot = new FirstRobot();
		this.name = robot.getName();
		this.area = area;
		this.place1 = place1;
		this.place2 = place2;
	}

	@Override
	public boolean executeCommand(int command) {
		if (area == null) {
			throw new RuntimeException("Could not execute command because field is not set");
		}
		switch (command) {
			case 1:
				area.lookRight(place1, place2, 2);
				break;
			case 2:
				area.lookLeft(place1, place2, 2);
				break;
			case 3:
				area.lookFront(place1, place2, 3);
				break;
			case 4:
				area.lookBack(place1, place2, 1);
				break;
			default:
				return false;
		}
		return true;
	}


	public ControllArea getArea() {
		return area;
	}

	public void setArea(ControllArea area) {
		this.area = area;
	}
}