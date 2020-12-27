package java_programming.lab2;

import java.io.*;
import java.util.Arrays;

/**
 * Created by Daria on 20.09.2014.
 */

/**
 * Lab No. 2
 * Subtraction of 2 large numbers
 */

public class Lab2 {

	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int j = 0;
		int f = 0;
		try {

			String red = br.readLine();
			String sub = br.readLine();
			int c = 0;

			if (red.length() > sub.length()) {
				c = red.length() - sub.length();
			}
			else {
				c = sub.length() - red.length();
				String change = sub;
				sub = red;
				red = change;
			}

			if (c == 0) {
				boolean replace = true;
				for (int i = 0; i < sub.length(); i++) {
					char digit1 = red.charAt(i);
					char digit2 = sub.charAt(i);
					if (digit1 < digit2 && replace == true) {
						break;
					}
					if (digit1 >= digit2) {
						replace = false;
					}
				}
				if (replace) {
					String change = sub;
					sub = red;
					red = change;
				}
			}

			int[] number1 = new int[red.length()];
			for (int i = red.length() - 1; i >= 0; i--) {
				char digit = red.charAt(i);
				if (digit >= '0' && digit <= '9')
					number1[j++] = Integer.parseInt(String.valueOf(digit));
			}

			int[] number2 = new int[sub.length() + c];
			for (int k = sub.length() - 1; k >= 0; k--) {
				char digit = sub.charAt(k);
				if (digit >= '0' && digit <= '9')
					number2[f++] = Integer.parseInt(String.valueOf(digit));
			}
			for (int h = 0; h < c; h++) {
				number2[f++] = 0;
			}

			number1 = Arrays.copyOf(number1, j);
			for (int p = number1.length - 1; p >= 0; p--) {
				System.out.print(number1[p]);
			}
			System.out.println(" ");
			number2 = Arrays.copyOf(number2, f);
			for (int q = number2.length - 1; q >= 0; q--){
				System.out.print(number2[q]);
			}
			System.out.println(" ");
			int[] diff = new int[red.length()];

			for (int h = 0; h <= number1.length - 1; h++) {
				if (number1[h] < number2[h]) {
					number1[h+1]--;
					diff[h] = (number1[h] + 10) - number2[h];
				}
				else {
					diff[h] = number1[h] - number2[h];
				}
			}

			diff = Arrays.copyOf(diff, diff.length);
			for (int m = diff.length - 1; m >= 0; m--) {
				System.out.print(diff[m]);
			}
		}

		catch (IOException e) {
			System.out.println("IOException occurred");
			e.printStackTrace();
		}

	}
}
