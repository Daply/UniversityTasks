package java_programming.lab1;

import java.io.*;
import java.text.NumberFormat;

/**
 * Created by Daria on 13.09.2014.
 */

/**
 * Lab No. 1
 * Taylor series expansion of sine function
 */

public class Lab1 {
	public static void main(String[] args) {

		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		double x, k, eps, sin, slag, i = 1;
		try {

			System.out.println("Input x ");
			String line = br.readLine();
			x = Double.parseDouble(line);
			sin = x;
			slag = x;

			System.out.println("Input k ");
			line = br.readLine();
			k = Double.parseDouble(line);
			eps = Math.pow(10.0, -k);

			System.out.println("Standard sinus ");
			NumberFormat formatter = NumberFormat.getNumberInstance();
			formatter.setMaximumFractionDigits(5);
			System.out.println(formatter.format(Math.sin(x)));

			System.out.println("Taylor sine ");

			while (Math.abs(slag) > eps){
				slag = ((-1) * slag * x * x) / ((i + 1) * (i + 2));
				sin += slag;
				i = i + 2;
			}
			System.out.println(formatter.format(sin));
		}
		catch (NumberFormatException e)
		{ System.out.println("format error");}
		catch (IOException e)
		{ System.out.println("input error");}
	}
}
