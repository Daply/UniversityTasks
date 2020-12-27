package java_programming.lab7_8.task1;

/**
 * Created by Daria on 30.10.2014.
 */

public abstract class AbstractRobot {
	protected final String name;

	protected AbstractRobot(String name) {
		this.name = name;
	}

	public abstract boolean executeCommand(int command);

	public abstract int[] getSupportedCommands();

	public String getName() {
		return name;
	}

}
