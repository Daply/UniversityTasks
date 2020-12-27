package java_programming.lab7_8.task1;

/**
 * Created by Daria on 26.10.2014.
 */

public class ControllArea {
	private final int rows;
	private final int cols;
	private final int[][] fieldMap;

	public ControllArea(int rows, int cols) {
		this.rows = rows;
		this.cols = cols;
		fieldMap = new int[rows][cols];
	}

	public void lookLeft(int r, int c, int dc) {
		checkIfExist(r, c);
		if (dc + c < cols)
			fieldMap[r][c + dc] = 1;
		// throw new IllegalArgumentException("Robot cant look there");

	}

	public void lookRight(int r, int c, int dc) {
		checkIfExist(r, c);
		if (dc <= c)
			fieldMap[r][c - dc] = 1;

	}

	public void lookFront(int r, int c, int dr) {
		checkIfExist(r, c);
		if (dr + r < rows)
			fieldMap[r + dr][c] = 1;
	}

	public void lookBack(int r, int c, int dr) {
		checkIfExist(r, c);
		if (dr <= r)
			fieldMap[r - dr][c] = 1;
	}

	public int getFlag(int r, int c) {
		checkIfExist(r, c);
		return fieldMap[r][c];
	}

	private void checkIfExist(int r, int c) {  // return condition
		if (r >= rows || c >= cols
				|| rows < 0 || cols < 0) {
			throw new IllegalArgumentException("Such cell does not exist");
		}
	}

	public int getFieldMap() {
		for (int i = 0; i < this.rows; i++) {
			for (int j = 0; j < this.cols; j++) {
				System.out.print(fieldMap[i][j]);
			}
			System.out.println(" ");
		}
		return 0;
	}

}
