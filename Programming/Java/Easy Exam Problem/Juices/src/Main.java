import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by Daria Pleshchankova on 27.11.2014.
 */
public class Main extends Thread{

    static public List<String> readFromFile(String name) throws FileNotFoundException {
        List<String>  s = new ArrayList<String>();
        Scanner in = new Scanner(new File(name));
        while (in.hasNext()) {
            s.add(in.nextLine());
        }
        in.close();
        return s;
    }

    static public void putInFile(String name, String text) throws IOException {
        File file = new File(name);
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

    public static void main(String[] args) throws IOException {
        final Juice j = new Juice();
        j.putFruits(readFromFile("juice.in"));
        String text1 = "List of fruits:\n " + j.diffFruits();
        String text3 = "Minimal times of washing:\n "+ j.countingTimesOfWashing();
        putInFile("juice1.out",text1);
        putInFile("juice3.out",text3);
        Thread myThready = new Thread(new Runnable()
        {
            public void run()
            {
                String text2 = "List of fruits in alphabetical order:\n " + j.fruitsInAlphabeticalOrder();
                try {
                    putInFile("juice2.out",text2);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        myThready.start();
;
    }
}






