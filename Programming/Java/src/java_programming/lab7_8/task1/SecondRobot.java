package java_programming.lab7_8.task1;

/**
 * Created by Daria on 30.10.2014.
 */

public class SecondRobot extends AbstractRobot {
	protected int[] commands;

	public SecondRobot() {
		super("Robot2");
	}

	@Override
	public boolean executeCommand(int command) {
		for (int i = 0; i < commands.length; i++) {
			if (command != commands[i])
				return false;
		}

		return true;
	}

	@Override
	public int[] getSupportedCommands() {
		return commands;
	}
}
