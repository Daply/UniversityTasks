package java_programming.lab9;

import java.util.Comparator;

public class CompareManufacturers implements Comparator<GameClub.Computer> {
	@Override
	public int compare(GameClub.Computer a, GameClub.Computer b)   {
		return a.getManufacturer().compareTo(b.getManufacturer());
	}
}
