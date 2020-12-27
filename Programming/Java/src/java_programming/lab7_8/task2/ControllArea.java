package java_programming.lab7_8.task2;

public class ControllArea {
	protected final int rows;
	protected final int cols;
	private final int[][] fieldMap;

	public ControllArea(int rows, int cols) {
		this.rows = rows;
		this.cols = cols;
		fieldMap = new int[rows][cols];
	}

	public int getFlag(int r, int c) {
		checkIsExist(r, c);
		return fieldMap[r][c];
	}

	public void setFlag(int r, int c, int flag) {
		checkIsExist(r, c);
		fieldMap[r][c] = flag;
	}

	void checkIsExist(int r, int c) {  //return condition
		if (r >= rows || c >= cols
				|| rows < 0 || cols < 0) {
			throw new IllegalArgumentException("Such cell does not exist");
		}
	}

	public int[][] getFieldMap() {
		return fieldMap;
	}
}
