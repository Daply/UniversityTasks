package java_programming.exam.exam3;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Map;

/**
 * Created by Daria on 29.11.2014.
 */

public class WritingFile {
	BufferedReader reader = null;
	String name;
	File file;

	public WritingFile(String name) {
		this.name = name;
		file = new File(name);
	}

	public void putInFile(ArrayList<String> text) throws IOException {
		if (!file.exists()) {
			file.createNewFile();
		}
		PrintWriter out = new PrintWriter(file.getAbsoluteFile());
		try {
			out.print(text);
		} finally {
			out.close();
		}
	}

	public void putInFile(String text) throws IOException {
		if (!file.exists()) {
			file.createNewFile();
		}
		PrintWriter out = new PrintWriter(file.getAbsoluteFile());
		try {
			out.print(text);
		} finally {
			out.close();
		}
	}

	public void putInFile(Map text) throws IOException {
		if (!file.exists()) {
			file.createNewFile();
		}
		PrintWriter out = new PrintWriter(file.getAbsoluteFile());
		try {
			out.print(text);
		} finally {
			out.close();
		}
	}

}
