package java_programming.lab9;

import java.util.Comparator;

public class CompareRAM implements Comparator<GameClub.Computer> {
	@Override
	public int compare(GameClub.Computer a, GameClub.Computer b)  {
		if (a.getHardDriveVolume() == b.getHardDriveVolume())
			return 0;
		else if(a.getHardDriveVolume() < b.getHardDriveVolume())
			return 1;
		else
			return -1;
	}

}
