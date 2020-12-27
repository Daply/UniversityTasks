package java_programming.lab5;

import java.util.Comparator;

public class CompareManufacturers implements Comparator<Computer> {
	@Override
	public int compare(Computer a, Computer b)   {
		return a.getManufacturer().compareTo(b.getManufacturer());
	}
}
