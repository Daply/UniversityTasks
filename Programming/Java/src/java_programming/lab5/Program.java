package java_programming.lab5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * Created by Daria on 10.10.2014.
 */

/**
 * Lab No. 5
 * Create classes according to task
 */

public class Program {

	public static void main(String[] args) {
		Computer [] a = new Computer[5];
		a[0] = new Computer("Samsung", Processor.DUAL_CORE,128,2014,9);
		a[1] = new Computer("Lenovo", Processor.QUAD_CORE,240,2014,8);
		a[2] = new Computer("Asus", Processor.QUAD_CORE,64,2014,8);
		a[3] = new Computer("Lenovo", Processor.QUAD_CORE,1024,2014,8);
		a[4] = new Computer("Samsung", Processor.THREE_CORE,500,2012,8);

		// List of all computers
		System.out.println("All computers: ");
		for(Computer b : a)
			System.out.println(b);
		System.out.println("______________________________________________________");

		try {
			System.out.println("Input processor type: ");
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			String Str = reader.readLine();

			// List of computers with given processor type
			System.out.println("Computers with processor type " + Str);
			Processor p = Processor.SINGLE_CORE;
			switch(Str){
				case("single core"): p = Processor.SINGLE_CORE;
					break;
				case("dual core"): p = Processor.DUAL_CORE;
					break;
				case("three core"): p = Processor.THREE_CORE;
					break;
				case("quad core"): p = Processor.QUAD_CORE;
					break;
				default:
					break;
			}
			for (int i = 0; i < a.length; ++i) {
				if (a[i].getProcessor().equals(p))
					System.out.println(a[i]);
			}
			System.out.println("______________________________________________________");

			// List of computers with given hard drive volume interval
			BufferedReader reader1 = new BufferedReader(new InputStreamReader(System.in));
			BufferedReader reader2 = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Input hard drive volume interval: ");
			String in1 = reader1.readLine();
			String in2 = reader2.readLine();
			double vol1 = Double.parseDouble(in1);
			double vol2 = Double.parseDouble(in2);
			for (int i=0; i<a.length; ++i) {
				if ((a[i].getHardDriveVolume() >= vol1) && (a[i].getHardDriveVolume() <= vol2))
					System.out.println(a[i]);
			}
			System.out.println("______________________________________________________");

			// List of computers with given manufacturer name
			BufferedReader reader3 = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Input manufacturer name: ");
			String manufacturer = reader3.readLine();
			for (int i = 0; i < a.length; ++i) {
				if (a[i].getManufacturer().equalsIgnoreCase(manufacturer))
					System.out.println(a[i]);
			}
			System.out.println("______________________________________________________");

			///////////Список компьютеров в порядке убывания объёма ОП///////////////////

			// List of computers in descending order of volume of RAM
			System.out.println("List of computers in descending order of volume of RAM");
			Arrays.sort(a, new CompareRAM());
			for (int i = 0; i < a.length; ++i)
				System.out.println(a[i]);
			System.out.println("______________________________________________________");

			// List of computers alphabetically by manufacturer
			System.out.println("List of computers alphabetically by manufacturer");
			Arrays.sort(a, new CompareManufacturers());
			for(int i = 0; i < a.length; ++i)
				System.out.println(a[i]);
			System.out.println("______________________________________________________");

		} catch (IOException e) {}

	}

}

