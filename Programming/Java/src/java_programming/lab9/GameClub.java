package java_programming.lab9;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by Daria on 17.11.2014.
 */

public class GameClub implements Serializable {

	static int Id = 0;
	private List<Computer> computers = new ArrayList();
	String name;
	String address;

	public class Computer implements Serializable {
		protected int id;
		protected final String manufacturer;
		protected final Processor processor;
		protected final double hardDriveVolume;
		protected final int year;
		protected double ramVolume;

		public Computer(String manufacturer, Processor processor, double hardDriveVolume, int year, double ramVolume) {
			id = Id;
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

		public String getManufacturer() {
			return manufacturer;
		}

		public Processor getProcessor() {
			return processor;
		}

		public int getId() {
			return Id++;
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

		@Override
		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;

			Computer computer = (Computer) o;

			if (Double.compare(computer.ramVolume, ramVolume) != 0) return false;
			if (Double.compare(computer.hardDriveVolume, hardDriveVolume) != 0) return false;
			if (year != computer.year) return false;
			if (manufacturer != null ? !manufacturer.equals(computer.manufacturer) : computer.manufacturer != null) return false;
			if (processor != computer.processor) return false;

			return true;
		}

		@Override
		public int hashCode() {
			int result;
			long temp;
			result = manufacturer != null ? manufacturer.hashCode() : 0;
			result = 31 * result + (processor != null ? processor.hashCode() : 0);
			temp = Double.doubleToLongBits(hardDriveVolume);
			result = 31 * result + (int) (temp ^ (temp >>> 32));
			result = 31 * result + year;
			temp = Double.doubleToLongBits(ramVolume);
			result = 31 * result + (int) (temp ^ (temp >>> 32));
			return result;
		}

		public String toString() {
			return getId() + " Manufacturer: " + this.manufacturer + " Type of processor: " +
					this.processor + " Volume of hard drive: " + this.hardDriveVolume + " Year of creation: " +
					this.year + " Volume of RAM: " + this.ramVolume + "\n";
		}

	}

	public class Laptop extends Computer implements Serializable {
		private int id;
		private final String battery;
		private final double timeOfWork;
		private final double size;
		private final double weight;

		public Laptop(String manufacturer, Processor processor, double hardDriveVolume, int year,
		              double ramVolume, String battery, double timeOfWork, double size, double weight) {
			super(manufacturer, processor, hardDriveVolume, year, ramVolume);
			id = Id;
			this.battery = battery;
			this.timeOfWork = timeOfWork;
			this.size = size;
			this.weight = weight;

		}

		public int getId() {
			return Id++;
		}

		public double getWeight() {
			return weight;
		}

		public String getBattery() {
			return battery;
		}

		public double getTimeOfWork() {

			return timeOfWork;
		}

		@Override
		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;
			if (!super.equals(o)) return false;

			Laptop laptop = (Laptop) o;

			if (Double.compare(laptop.size, size) != 0) return false;
			if (Double.compare(laptop.timeOfWork, timeOfWork) != 0) return false;
			if (Double.compare(laptop.weight, weight) != 0) return false;
			if (battery != null ? !battery.equals(laptop.battery) : laptop.battery != null) return false;

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

		public double getSize() {
			return size;
		}

		@Override
		public String toString() {
			return getId() +" Firm-manufacturer: " + super.getManufacturer() + " Type of processor: " +
					super.getProcessor() + " Volume of hard drive: " + super.getHardDriveVolume() + " Year of creation: " +
					super.getYear() + " Volume of operation memory: " + super.getRamVolume() +
					" Battery: " + battery +
					" Time of work: " + timeOfWork +
					" Size: " + size + " Weight: " + weight + "\n";
		}

	}

	public GameClub(String name, String address) {
		this.name = name;
		this.address = address;
	}

	public void print() {
		System.out.println(this);
	}

	public void computersWithProcessor(String Str) {

		System.out.println("Computers with processor type " + Str);
		Processor P = Processor.valueOf(Str);
		ArrayList<Computer> comps;

		for (int i = 0; i < computers.size(); ++i) {
			if (computers.get(i).getProcessor() == P)
				System.out.println(computers.get(i));
		}
	}

	public void computersHardDriveVolume(double vol1, double vol2) {
		for (int i = 0; i < computers.size(); ++i) {
			if ((computers.get(i).getHardDriveVolume() >= vol1) && (computers.get(i).getHardDriveVolume() <= vol2))
				System.out.println(computers.get(i));
		}
	}

	public void computersByManufacturer(String manufacturer) {
		for (int i = 0; i < computers.size(); ++i) {
			if (computers.get(i).getManufacturer().equalsIgnoreCase(manufacturer))
				System.out.println(computers.get(i));
		}
	}

	public void computersSortByRAM() {
		computers.sort(new CompareRAM());
		for (int i = 0; i < computers.size(); ++i)
			System.out.println(computers.get(i));

	}

	public void computersSortByManufacturer() {
		computers.sort(new CompareManufacturers());
		for (int i = 0; i < computers.size(); ++i)
			System.out.println(computers.get(i));
	}

	@Override
	public String toString() {
		return "GameClub: " + '\n' +
				"computers:" + computers +
				", name ='" + name + '\'' +
				", address ='" + address + '\'' ;
	}

	public void serialization() throws FileNotFoundException, IOException {
		ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("temp.txt"));
		oos.writeObject(computers);
	}

	public void deSerialization() throws FileNotFoundException, IOException, ClassNotFoundException {
		ObjectInputStream ois = new ObjectInputStream(new FileInputStream("temp.txt"));
		computers = (ArrayList) ois.readObject();
		System.out.println(computers);

	}

	public void add(String manufacturer, Processor processor, double hardDriveVolume, int year,
	                double ramVolume) {
		computers.add(new Computer(manufacturer, processor, hardDriveVolume, year, ramVolume));
	}

	public void add(String manufacturer, Processor processor, double hardDriveVolume, int year,
	                double ramVolume, String battery, double timeOfWork, double size, double weight) {
		computers.add(new Laptop(manufacturer, processor, hardDriveVolume, year, ramVolume, battery, timeOfWork, size, weight));
	}

}
