package java_programming.lab9;

import java.io.*;

/**
 * Created by Daria on 17.11.2014.
 */

/**
 * Lab No. 9
 * Serialization
 */

public class Main {
	public static void main(String[] args) {
		GameClub gameClub = new GameClub("HGames", "Berter str. 1450");
		gameClub.add("Samsung", Processor.QUAD_CORE, 128, 2014, 9);
		gameClub.add("Lenovo", Processor.DUAL_CORE, 240, 2014, 8);
		gameClub.add("Asus", Processor.QUAD_CORE, 64, 2014, 8, "bat2", 28, 14, 1.5);
		gameClub.add("Lenovo", Processor.QUAD_CORE, 1024, 2014, 8);
		gameClub.add("Samsung", Processor.THREE_CORE, 500, 2012, 8);
		gameClub.add("Siemens", Processor.SINGLE_CORE, 512, 2013, 9, "bat1", 34, 23, 3);

		while (true) {
			System.out.println("Choose operation: ");

			System.out.println("Print all computers in game club - 1");
			System.out.println("Print computers with chosen processor - 2");
			System.out.println("Computers with chosen interval volume of the hard drive - 3");
			System.out.println("Computers with chosen manufacturer - 4");
			System.out.println("Sorting computers by volume of operation memory - 5");
			System.out.println("Sorting computers in alphabetical order manufacturers - 6");
			System.out.println("Write to file(serialization) - 7");
			System.out.println("Read from file(deserialization) - 8");
			System.out.println("Exit - 0");

			try {
				int operation_number;
				BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
				operation_number = Integer.parseInt(reader.readLine());

				switch (operation_number) {

					case 1:
						System.out.println("All computers: ");
						gameClub.print();
						System.out.println("______________________________________________________");

						break;

					case 2:
						try {
							System.out.println("Input the type of processor: ");
							BufferedReader reader1 = new BufferedReader(new InputStreamReader(System.in));
							String Str = reader1.readLine();
							gameClub.computersWithProcessor(Str);
							System.out.println("______________________________________________________");

						} catch (IOException eX) {
						}
						break;
					case 3:
						try {
							BufferedReader reader1 = new BufferedReader(new InputStreamReader(System.in));
							BufferedReader reader2 = new BufferedReader(new InputStreamReader(System.in));
							System.out.println("Input the hard drive volume interval: ");
							String f = reader1.readLine();
							String g = reader2.readLine();
							double vol1 = Double.parseDouble(f);
							double vol2 = Double.parseDouble(g);
							gameClub.computersHardDriveVolume(vol1, vol2);
							System.out.println("______________________________________________________");
						} catch (IOException eX) {
						}
						break;
					case 4:
						try {
							BufferedReader reader1 = new BufferedReader(new InputStreamReader(System.in));
							System.out.println("Input the name of manufacturer: ");
							String manufacturer = reader1.readLine();
							gameClub.computersByManufacturer(manufacturer);
							System.out.println("______________________________________________________");
						} catch (IOException eX) {
						}
						break;
					case 5:
						System.out.println("Computers in descending order of RAM volume: ");
						gameClub.computersSortByRAM();
						System.out.println("______________________________________________________");

						break;
					case 6:
						System.out.println("Computers alphabetically by manufacturer: ");
						gameClub.computersSortByManufacturer();
						System.out.println("______________________________________________________");

						break;
					case 7:
						gameClub.serialization();
						break;
					case 8:
						gameClub.deSerialization();
						break;
					case 0:
						System.exit(0);
					default:
						System.out.println("Wrong operation");
				}


			} catch (IOException e) {
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
			}
		}
	}
}
