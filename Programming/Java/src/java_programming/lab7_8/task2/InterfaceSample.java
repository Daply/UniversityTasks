package java_programming.lab7_8.task2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * Lab No. 7-8
 * Abstract classes and interfaces
 */

public class InterfaceSample {

	public static void print(ControllArea a) {
		for (int i = 0; i < a.getFieldMap().length; i++) {
			System.out.println(Arrays.toString(a.getFieldMap()[i]));
		}
	}

	public static int[] array(String str) {
		String[] tokens = new String[str.length()];
		int[] a = new int[str.length()];
		for (int i = 0; i < str.length(); i++) {
			tokens[i] = "";
		}
		char sym = ' ';
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) > '0' && str.charAt(i) < '9')
				sym = str.charAt(i);
			tokens[i] += sym;
			a[i] = Integer.parseInt(tokens[i]);
		}
		return a;
	}

	public static void main(String[] args) {
		try {
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			ControllArea area1 = new ControllArea(5, 5);
			ControllArea area2 = new ControllArea(5, 6);
			ControllArea area3 = new ControllArea(4, 4);
			ControllArea area4 = new ControllArea(6, 7);
			FirstGrRobotInterface robot1 = new FirstRobot(area1);
			FirstGrRobotInterface robot2 = new SecondRobot(area2);
			SecondGrRobotInterface robot3 = new ThirdRobot(area3);
			SecondGrRobotInterface robot4 = new FourthRobot(area4);
			System.out.println("Write commands to your robot to do:" +
					" 1 - look right side" +
					" 2 - look left side" +
					" 3 - look in front" +
					" 4 - look back");

			AreaControllingFirstGrRobots robot1Control = new AreaControllingFirstGrRobots(robot1, 1, 2);
			AreaControllingFirstGrRobots robot2Control = new AreaControllingFirstGrRobots(robot2, 1, 3);
			AreaControllingSecondGrRobots robot3Control = new AreaControllingSecondGrRobots(robot3, 2, 2);
			AreaControllingSecondGrRobots robot4Control = new AreaControllingSecondGrRobots(robot4, 1, 2);
			String str = reader.readLine();
			for (int i = 0; i < array(str).length; i++) {
				robot1Control.executeCommand(array(str)[i]);
			}
			print(area1);
			System.out.println("-----------------------");
			for (int i = 0; i < array(str).length; i++) {
				robot2Control.executeCommand(array(str)[i]);
			}
			print(area2);
			robot3Control.executeCommand(3, 3);
			System.out.println("-----------------------");
			print(area3);
			robot4Control.executeCommand(5, 4);
			System.out.println("-----------------------");
			print(area4);

		} catch (IOException e) {}

	}
}
