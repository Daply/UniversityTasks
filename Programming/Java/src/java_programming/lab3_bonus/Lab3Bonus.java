package java_programming.lab3_bonus;

/**
 * Created by Daria on 26.09.2014.
 */

/**
 * Lab No. 3 Bonus task
 *
 */

public class Lab3Bonus {

	/**
	 * Two rows replacing
	 *
	 * @param a
	 * @param size
	 * @param str1
	 * @param str2
	 */
	public static void changeRows(int [][] a, int size, int str1, int str2){
		int [] temp = new int [size];
		temp = a[str1];
		a[str1] = a[str2];
		a[str2] = temp;
	}

	/**
	 * Replacing two columns (when a column with two ones, exchange it with the first one)
	 *
	 * @param a
	 * @param size
	 * @param str1
	 * @param str2
	 * @param i1
	 */
	public static void changeColumns(int [][] a, int size, int str1, int str2, int i1){
		int tmp = 0;
		for (int r = i1; r < size; r++) {
			tmp = a[r][str1];
			a[r][str1] = a[r][str2];
			a[r][str2] = tmp;}
	}

	/**
	 * Replacing columns with collected ones to column with all zeroes and to the first column
	 *
	 * @param a
	 * @param size
	 * @param stb1
	 * @param stb2
	 * @param i1
	 */
	public static void changeRowsWithOnes(int [][] a, int size, int stb1, int stb2, int i1){
		int tmp = 0;
		int tmp1 = 0;
		for (int r = i1; r < size; r++) {
			tmp = a[r][stb1];
			a[r][stb1] = a[r][0];
			a[r][0] = tmp;
			tmp1 = a[r][stb2];
			a[r][stb2] = a[r][1];
			a[r][1] = tmp1;
		}
	}

	/**
	 * Replacing rows with collected ones to row with all zeroes and to first row
	 *
	 * @param a
	 * @param size
	 * @param str1
	 * @param str2
	 */
	public static void changeRowsWithOnes(int [][] a, int size, int str1, int str2){
		int [] temp = new int [size];
		int [] temp1 = new int [size];
		temp = a[str1];
		a[str1] = a[0];
		a[0] = temp;
		temp1 = a[str2];
		a[str2] = a[1];
		a[1] = temp1;
	}

	/**
	 * Replacing columns with collected ones to fourth and fifth columns
	 *
	 * @param a
	 * @param size
	 * @param stb1
	 * @param stb2
	 * @param i1
	 */
	public static void changeRowsWithOnes2(int [][] a, int size, int stb1, int stb2, int i1){
		int tmp = 0;
		int tmp1 = 0;
		for (int r = i1; r < size; r++) {
			tmp = a[r][stb1];
			a[r][stb1] = a[r][5];
			a[r][5] = tmp;
			tmp1 = a[r][stb2];
			a[r][stb2] = a[r][4];
			a[r][4] = tmp1;
		}
	}

	/**
	 * Replacing rows with collected ones to fourth and fifth rows
	 *
	 * @param a
	 * @param size
	 * @param str1
	 * @param str2
	 */
	public static void changeRowsWithOnes2(int [][] a, int size, int str1, int str2){
		int [] temp = new int [size];
		int [] temp1 = new int [size];
		temp = a[str1];
		a[str1] = a[5];
		a[5] = temp;
		temp1 = a[str2];
		a[str2] = a[4];
		a[4] = temp1;
	}

	public static void main(String[] args) {
		int [][] onesZ = {{0,0,0,1,1,0},
				              {0,1,1,0,0,1},
				              {0,1,0,0,0,0},
				              {1,0,0,0,0,1},
				              {0,0,0,1,1,0},
				              {1,1,0,1,0,0}};

		for (int [] a: onesZ) {
			for (int b: a) {
				System.out.print(b + " ");
			}
			System.out.println(" ");
		}

		/*
		 * SQUARES IN THE UPPER LEFT CORNER
		 */
		/*
		 * We are looking for rows with ones on the same columns and move them to the beginning
		 */
		int str1 = 0, str2 = 0;
		int stb1 = 0, stb2 = 0;

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				for (int l = i + 1; l < 6; l++) {
					for (int k = j + 1; k < 6; k++) {
						if (onesZ[i][j] == 1 && onesZ[l][j] == 1) {
							if (onesZ[i][k] == 1 && onesZ[l][k] == 1) {
								stb1 = j;
								stb2 = k;
								if (i != 0)
									changeRows(onesZ, 6,i - 1, l);
							}
						}
					}
				}
			}
		}
		changeRowsWithOnes(onesZ, 6, stb1, stb2, 0);

		/*
		 * We are looking for columns with ones in the same places, and move them to the beginning
		 */
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				for (int l = i+1; l < 6;l++) {
					for (int k = j+1; k < 6; k++) {
						if (onesZ[i][j] == 1 && onesZ[i][k] == 1) {
							if (onesZ[l][j] == 1 && onesZ[l][k] == 1) {
								str1 = i;
								str2 = l;
								if (j != 0)
									changeColumns(onesZ, 6, j , k, 0);
							}
						}
					}
				}
			}
		}

		changeRowsWithOnes(onesZ, 6, str1, str2);

		/*
		 * SQUARES IN THE LOWER RIGHT CORNER
		 */
		/*
		 * We are looking for ones in rows from the second row and column,
		 * that stand in the same places and moving them to the end
		 */
		for (int i = 2; i < 6; i++) {
			for (int j = 2; j < 6; j++) {
				for (int l = i+1; l < 6;l++) {
					for (int k = j+1; k < 6; k++) {
						if (onesZ[i][j] == 1 && onesZ[l][j] == 1) {
							if (onesZ[i][k] == 1 && onesZ[l][k] == 1) {
								stb1 = j;
								stb2 = k;
								if (i != 2)
									changeRows(onesZ, 6,i - 1,l);
							}
						}
					}
				}
			}
		}
		changeRowsWithOnes2(onesZ, 6, stb1, stb2, 2);

		for (int i = 2; i < 6; i++) {
			for (int j = 2; j < 6; j++) {
				for (int l = i+1; l < 6; l++) {
					for (int k = j+1; k < 6; k++) {
						if (onesZ[i][j] == 1 && onesZ[i][k] == 1) {
							if (onesZ[l][j] == 1 && onesZ[l][k] == 1) {
								str1 = i;
								str2 = l;
								if (j != 0)
									changeColumns(onesZ, 6, j , k, 0);
							}
						}
					}
				}
			}
		}

		changeRowsWithOnes2(onesZ, 6, str1, str2);

		if (onesZ[0][0] != 1) {
			System.out.println("The matrix cannot be reduced to this form.");
		}
		else {
			System.out.println("New matrix ");
			for(int [] a: onesZ) {
				for(int b: a) {
					System.out.print(b + " ");
				}
				System.out.println(" ");
			}
		}

	}
}