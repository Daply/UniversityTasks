package java_programming.lab6;

class Computer {
	protected int id;
	protected final String manufacturer;
	protected final Processor processor;
	protected final double hardDriveVolume;
	protected final int year;
	protected double ramVolume;

	private static int count = 0;

	public Computer(String manufacturer, Processor processor, double hardDriveVolume, int year, double ramVolume) {
		count++;
		id = count;
		this.manufacturer = manufacturer;
		this.processor = processor;
		this.hardDriveVolume = hardDriveVolume;
		this.year = year;
		this.ramVolume = ramVolume;
	}

	public Computer(Computer comp) {
		this.manufacturer = comp.manufacturer;
		this.processor = comp.processor;
		this.hardDriveVolume = comp.hardDriveVolume;
		this.year = comp.year;
		this.ramVolume = comp.ramVolume;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getManufacturer() {
		return manufacturer;
	}

	public Processor getProcessor() {
		return processor;
	}

	public double getHardDriveVolume() {
		return hardDriveVolume;
	}

	public int getYear() {
		return year;
	}

	public double getRamVolume() {
		return ramVolume;
	}

	public void setRamVolume(double ramVolume) {
		this.ramVolume = ramVolume;
	}

	public static int getCount() {
		return count;
	}

	public static void setCount(int count) {
		Computer.count = count;
	}

	@Override
	public String toString() {
		return "Computer{" +
				"id=" + id +
				", manufacturer='" + manufacturer + '\'' +
				", processor=" + processor +
				", hardDriveVolume=" + hardDriveVolume +
				", year=" + year +
				", ramVolume=" + ramVolume +
				'}';
	}
}
