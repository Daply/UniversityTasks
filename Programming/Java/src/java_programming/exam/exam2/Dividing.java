package java_programming.exam.exam2;

import java.io.IOException;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by OK USER on 20.01.2015.
 */
public class Dividing {
    private String[] words;
    private String filename;
    ArrayList<String> numbers;
    ArrayList<String> signs;

    public Dividing(String filename) {
        this.filename = filename;
        numbers = new ArrayList<String>();
        signs = new ArrayList<String>();
    }

    public void readStringFromFile() throws IOException {
        FileReading rf = new FileReading(filename);
        int n = rf.readingStringFromFile();
        words = rf.readingFile(n);
    }

    public void method() throws IOException {
        readStringFromFile();
        for (int i = 0; i < words.length; i++) {
            putNumbers(words[i]);
            putSigns(words[i]);
            System.out.println("answer of exspression:");
            System.out.println(String.format("%s",counting()));
            System.out.println("type B of the exspression:");
            System.out.println(String.format("%s",expression()));
            System.out.println("the list of numbers is sorted by number of digits:");
            System.out.println(String.format("%s",sorting()));
            signs.clear();
            numbers.clear();
        }
    }


    public ArrayList sorting(){
        ArrayList<String> ar = new ArrayList<String>(numbers);
        ar.sort(new CompareNumbers());
        return ar;
    }

    public void putSigns(String s) {
        String num;
        num = s;
        StringTokenizer st = new StringTokenizer(num, " \t\n\r0123456789 ");
        while (st.hasMoreTokens()) {
            signs.add(st.nextToken());

        }
    }

    public void putNumbers(String s) {
        String num;
        num = s;

        StringTokenizer st = new StringTokenizer(num, " \t\n\r+-*/ ");
        while (st.hasMoreTokens()) {
            numbers.add(st.nextToken());

        }
    }


    public ArrayList counting() {
        ArrayList<String> s = new ArrayList<String>(signs);
        ArrayList<String> n = new ArrayList<String>(numbers);
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            String str = s.get(i);
            if (str.equals("*")) {
                num = Integer.parseInt(n.get(i)) * Integer.parseInt(n.get(i + 1));
                n.set(i + 1, Integer.toString(num));
                n.remove(i);
                s.remove(i);
                i--;
            }
            if (str.equals("/")) {
                num = Integer.parseInt(n.get(i)) / Integer.parseInt(n.get(i + 1));
                n.set(i + 1, Integer.toString(num));
                n.remove(i);
                s.remove(i);
                i--;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            String str = s.get(i);
            if (str.equals("+")) {
                num = Integer.parseInt(n.get(i)) + Integer.parseInt(n.get(i + 1));
                n.set(i + 1, Integer.toString(num));
                n.remove(i);
                s.remove(i);
                i--;
            }
            if (str.equals("-")) {
                num = Integer.parseInt(n.get(i)) - Integer.parseInt(n.get(i + 1));
                n.set(i + 1, Integer.toString(num));
                n.remove(i);
                s.remove(i);
                i--;
            }
        }
        return n;
    }


    public ArrayList expression() {
        ArrayList<String> s = new ArrayList<String>(signs);
        ArrayList<String> n = new ArrayList<String>(numbers);
        String num;
        for (int i = 0; i < s.size(); i++) {
            String str = s.get(i);
            if (str.equals("*")) {
                num = "mul" + "(" + n.get(i) + "," + n.get(i + 1) + ")";
                n.set(i + 1, num);
                n.remove(i);
                s.remove(i);
                i--;
            }
            if (str.equals("/")) {
                num = "dev" + "(" + n.get(i) + "," + n.get(i + 1) + ")";
                n.set(i + 1, num);
                n.remove(i);
                s.remove(i);
                i--;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            String str = s.get(i);
            if (str.equals("+")) {
                num = "add" + "(" + n.get(i) + "," + n.get(i + 1) + ")";
                n.set(i + 1, num);
                n.remove(i);
                s.remove(i);
                i--;
            }
            if (str.equals("-")) {
                num = "sub" + "(" + n.get(i) + "," + n.get(i + 1) + ")";
                n.set(i + 1, num);
                n.remove(i);
                s.remove(i);
                i--;
            }
        }
        return n;
    }

}

