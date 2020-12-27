package java_programming.lab5;

import java.util.Comparator;

public class CompareRAM implements Comparator<Computer> {
	@Override
	public int compare(Computer a, Computer b)  {
		if (a.getRamVolume() == b.getRamVolume())
			return 0;
		else if(a.getRamVolume() < b.getRamVolume())
			return 1;
		else
			return -1;
	}

}
