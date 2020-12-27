package java_programming.exam.exam3;

import java.io.*;
import java.util.ArrayList;
import java.util.Map;
import java.util.Scanner;

/**
 * Created by Daria on 29.11.2014.
 */

public class ReadingFile {
    BufferedReader reader = null;
    String name;
    File file;

    public ReadingFile(String name) {
        this.name = name;
        file = new File(name);
    }

    public String[] readingFile(int k) throws FileNotFoundException {
        int i = 0;
        String[] s = new String[k];
        Scanner in = new Scanner(new File(name));
        while (in.hasNext()) {
            s[i] = in.nextLine() + "\n";
            i++;
        }
        in.close();
        return s;
    }

    public int readingStringFromFile() throws IOException {
        if (!file.exists()) {
            file.createNewFile();
        }
        BufferedReader fin = new BufferedReader(new FileReader(file));
        String line;
        int count = 0;
        while ((line = fin.readLine()) != null) {
            count++;
        }
        return count;
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
