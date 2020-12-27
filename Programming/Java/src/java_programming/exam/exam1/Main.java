package java_programming.exam.exam1;

import java.io.IOException;

/**
 * Created by Daria on 22.01.2015.
 */
public class Main {
    public static void main(String[] args) throws IOException {
        Dividing dev = new Dividing("input1.txt", "input2.txt");
        dev.mainMethod();
        FileReading fr = new FileReading("output.txt");
        fr.putInFile(dev.toString());
    }
}
