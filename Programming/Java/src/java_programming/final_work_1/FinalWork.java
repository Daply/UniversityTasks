package java_programming.final_work_1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class FinalWork {

	public static void sortingY(double[][]a, int n){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n-1; j++) {
				if (a[1][j] <= a[1][j+1]) {
					for (int k = 0; k < 2; k++) {
						double temp = a[k][j];
						a[k][j] = a[k][j+1];
						a[k][j+1] = temp;
					}
				}
			}
		}
	}

	/**
	 * (-x - 5)^3 - (-x + 5)^2 - 5;
	 * @param a
	 * @param b
	 */
	public static void func(double[] a, double[][] b) {
		for (int i = 0; i < a.length; i++) {
			b[0][i] = i;
			b[1][i] = Math.pow((-a[i]-5), 3) - Math.pow((-a[i]+5), 2) - 5;
		}
	}

	public static double[][] matrix(double[] a, double[] b, int n) {
		double [][]mat = new double[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i] == b[j])
					mat[j][i] = 1;
			}
		}
		return mat;
	}

	public static String cipher(String s, double[][] mat, int n) {
		String s1 = "";
		char sym = ' ';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == 1) {
					sym = s.charAt(j);
					s1 += sym;
				}
			}
		}
		return s1;
	}


	public static void main(String[] args) {
		try {
			// Reading string
			System.out.println("Input first string: ");
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			String line = reader.readLine();

			// Putting all numbers from a string to double array
			String[] str = new String[line.length()];
			int j = 0; int l = 0; int count = 0;

			for (int i = 0; i < line.length(); i++) {
				str[i] = "";
			}

			for (int i = 0; i < line.length(); i++) {
				char sym = line.charAt(i);
				if(sym >= '0' && sym <= '9' || sym == '.') {
					count++;
					if (count == 1) {
						l = i;
						str[j] += sym;
					}
					if (count != 1) {
						if (i == l+1) {
							l = i;
							str[j] += sym;
						}
						else {
							count = 0;
							j++;
							str[j] += sym;
						}
					}
				}
			}

			double[] x = new double[j+1];

			for (int i = 0; i < j+1; i++) {
				x[i] = Double.parseDouble(str[i]);
			}

			for(double a: x) {
				System.out.print(a + " ");
			}
			System.out.println(" ");

			double[][] y = new double[2][j+1];
			func(x,y);
			for (double [] a: y) {
				for (double b: a) {
					System.out.print(b + " ");
				}
				System.out.println(" ");
			}
			System.out.println("Сортируем массив y: ");

      // Sorting source array
			sortingY(y,j+1);

			for (double [] a: y) {
				for (double b: a) {
					System.out.print(b + " ");
				}
				System.out.println(" ");
			}
			System.out.println("   ");

			double[] x1 = new double[j+1];

			for (int i = 0; i < j+1; i++) {
				x1[i] = x[i];
			}

			for (int i = 0; i < j+1; i++) {
				for (int k = 0; k < j+1; k++) {
					if (y[0][i] == k) {
						x[i] =  x1[k];
					}
				}
			}

			for(double a: x) {
				System.out.print(a + " ");
			}
			System.out.println(" ");

			// Permutation matrix
			for (double [] a: matrix(x1,x,j+1)) {
				for (double b: a) {
					System.out.print(b + " ");
				}
				System.out.println(" ");
			}
			System.out.println("   ");

			System.out.println("Input second string: ");
			String line1 = reader.readLine();
			System.out.println(cipher(line1, matrix(x1,x,j+1),j+1));
		}
		catch (NumberFormatException | IOException eX) {}

	}
}
