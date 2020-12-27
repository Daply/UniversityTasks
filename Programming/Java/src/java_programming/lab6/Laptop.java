package java_programming.lab6;

public class Laptop extends Computer {
	private final String battery;
	private final double timeOfWork;
	private final double size;
	private final double weight;

	public Laptop (String manufacturer, Processor processor,
	               double hardDriveVolume, int year, double ramVolume,
	               String battery, double timeOfWork, double size, double weight) {
		super(manufacturer, processor, hardDriveVolume, year, ramVolume);
		this.battery = battery;
		this.timeOfWork = timeOfWork;
		this.size = size;
		this.weight = weight;
	}

	public String getBattery() {
		return battery;
	}

	public double getTimeOfWork() {
		return timeOfWork;
	}

	public double getSize() {
		return size;
	}

	public double getWeight() {
		return weight;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;
		if (!super.equals(o)) return false;

		Laptop notebook = (Laptop) o;

		if (Double.compare(notebook.size, size) != 0) return false;
		if (Double.compare(notebook.timeOfWork, timeOfWork) != 0) return false;
		if (Double.compare(notebook.weight, weight) != 0) return false;
		if (battery != null ? !battery.equals(notebook.battery) : notebook.battery != null)
			return false;

		return true;
	}

	@Override
	public int hashCode() {
		int result = super.hashCode();
		long temp;
		result = 31 * result + (battery != null ? battery.hashCode() : 0);
		temp = Double.doubleToLongBits(timeOfWork);
		result = 31 * result + (int) (temp ^ (temp >>> 32));
		temp = Double.doubleToLongBits(size);
		result = 31 * result + (int) (temp ^ (temp >>> 32));
		temp = Double.doubleToLongBits(weight);
		result = 31 * result + (int) (temp ^ (temp >>> 32));
		return result;
	}

	@Override
	public String toString() {
		return "Laptop{" +
				"battery='" + battery + '\'' +
				", timeOfWork=" + timeOfWork +
				", size=" + size +
				", weight=" + weight +
				", id=" + id +
				", manufacturer='" + manufacturer + '\'' +
				", processor=" + processor +
				", hardDriveVolume=" + hardDriveVolume +
				", year=" + year +
				", ramVolume=" + ramVolume +
				'}';
	}

}
