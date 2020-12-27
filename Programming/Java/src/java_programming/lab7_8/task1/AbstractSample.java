package java_programming.lab7_8.task1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by OK USER on 26.10.2014.
 */

/**
 * Lab No. 7-8
 * Abstract classes and interfaces
 */

public class AbstractSample {

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
			AbstractRobot robot1 = new FirstRobot();

			System.out.println("Write commands to your robot to do:" +
					" 1 - look right side" +
					" 2 - look left side" +
					" 3 - look in front" +
					" 4 - look back");

			AbstractRobot robot2 = new FirstRobot();

			ControllArea area1 = new ControllArea(5, 5);
			ControllArea area2 = new ControllArea(5, 6);
			AreaControllingFirstRobot robot1Control = new AreaControllingFirstRobot(area1, robot1, 1, 2);
			AreaControllingSecondRobot robot2Control = new AreaControllingSecondRobot(area2, robot2, 1, 3);
			String str = reader.readLine();
			for (int i = 0; i < array(str).length; i++) {
				robot1Control.executeCommand(array(str)[i]);
			}
			area1.getFieldMap();
			System.out.println("--------------");
			for (int i = 0; i < array(str).length; i++) {
				robot2Control.executeCommand(array(str)[i]);
			}

			area2.getFieldMap();

		} catch (IOException e) {}

	}
}
