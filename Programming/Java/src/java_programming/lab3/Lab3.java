package java_programming.lab3;

/**
 * Created by Daria on 25.09.2014.
 */

/**
 * Lab No. 3
 * Matrices multiplication
 */

public class Lab3 {

	public static void main(String[] args) {
		int [][] one = {{1,0,0},
				            {0,3,0},
				            {0,0,1},
				            {2,4,6}};
		int [][] two = {{2,2,2,1},
				            {2,2,2,0},
				            {2,2,2,1}};
		int columnsNumber1 = 3;
		int rowsNumber1 = 4;

		int columnsNumber2 = 4;
		int rowsNumber2 = 3;

		if(rowsNumber2 != columnsNumber1){
			System.out.println("Matrices multiplication impossible");
		}
		int [][] three = new int [rowsNumber1][columnsNumber2];
		System.out.println("First matrix");
		for(int [] a: one) {
			for(int b: a) {
				System.out.print(b + " ");
			}
			System.out.println(" ");
		}

		System.out.println("Second matrix");
		for(int [] a: two) {
			for(int b: a) {
				System.out.print(b + " ");
			}
			System.out.println(" ");
		}

		for(int i = 0; i < rowsNumber1; i++) {
			for(int j = 0; j < columnsNumber2; j++) {
				for(int k = 0, f = 0; k < columnsNumber1 && f < rowsNumber2;f++, k++){
					three[i][j] += one[i][k] * two[f][j];
				}
			}
		}

		System.out.println("Matrices multiplication");

		for(int [] a: three) {
			for(int b: a) {
				System.out.print(b+" ");
			}
			System.out.println(" ");
		}
	}

}
