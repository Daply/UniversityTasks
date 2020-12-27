package java_programming.exam.exam3;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by Daria on 20.01.2015.
 */

public class Dividing {
    private String[] words1;
    private String[] words2;
    private String input1;
    private String input2;

    private String system;
    private String[] var;
    private String[] val;


    ArrayList<String> expressions;
    ArrayList<String> finalexpressions;

    ArrayList<String> signs;
    ArrayList<String> varities;


    public Dividing(String input1, String input2) {
        this.input1 = input1;
        this.input2 = input2;
        signs = new ArrayList<String>();
        varities = new ArrayList<String>();
        expressions = new ArrayList<String>();
        finalexpressions = new ArrayList<String>();
    }

    public void readStringFromFile() throws IOException {
        ReadingFile rf = new ReadingFile(input1);
        int n = rf.readingStringFromFile();
        words1 = rf.readingFile(n);
        ReadingFile rf1 = new ReadingFile(input2);
        int n1 = rf1.readingStringFromFile();
        words2 = rf1.readingFile(n1);
    }

    public void mainMethod() throws IOException {
        readStringFromFile();
        WritingFile wf = new WritingFile("output.txt");

        for(int i = 0; i < words1.length; i++){
            devideExpressions(words1[i]);
            devideValues(words2[i]);
            String s = words1[i].replaceAll("\n","");
            s = s.replaceAll(";","");
            System.out.println(s +"="+ turnInSystemOfCounting((deleting(counting().get(0).toString())),"10"));
            makingExpressions();
            System.out.println(sortingExpressions());

            signs.clear();
            varities.clear();
            finalexpressions.clear();
        }
        wf.putInFile(toString());
    }

    public String deleting(String n){
        StringBuffer sb = new StringBuffer(n);
        sb.deleteCharAt(sb.length()-1);
        String d = new String(sb);
        return d;
    }

    ///////////////////////////////////////////////////////
    public void devideValues(String s){
        String[] a = s.split("(;| ;| ; |; )");
        system = a[0];
        int flag = 1;
        String str;
        String str1;
        var = new String[a.length-1];
        val = new String[a.length-1];
        for(int i = 1; i < a.length; i++){
            str = "";
            str1 ="";
            flag = 1;
            for(int j = 0; j < a[i].length(); j++){
                char c = a[i].charAt(j);
                if(c != '=' && flag == 1)
                    str += c;
                if(c == '=')
                    flag = 0;
                if(flag == 0)
                    str1 += c;

            }
            if (str != "" || str1 != ""){
                var[i-1] = str;
                val[i-1] = str1;}
        }

        for(int i = 0; i < var.length-1; i++){
            var[i] = var[i].replaceAll(" ","");
        }
        for(int i = 0; i < val.length-1; i++){
            val[i] = val[i].replaceAll("=","");
            val[i] = val[i].replaceAll(" ","");
        }
    }

    public void devideExpressions(String s){
        putVarities(s);
        putSigns(s);
        System.out.println(signs);
    }

    public void putSigns(String s) {
        String num;
        num = s;
        String regex = "[a-zA-Z]+[0-9]*";
        num = num.replaceAll(regex,"");
        num = num.replaceAll(";","");
        num = num.replaceAll("\n","");
        signs.add(num);
    }

    public void putVarities(String s) {
        String num;
        num = s;
        StringTokenizer st = new StringTokenizer(num, " \t\n\r+-*/; ");
        while (st.hasMoreTokens()) {
            varities.add(st.nextToken());
        }
    }
///////////////////////////////////////////////////////

    @Override
    public String toString() {
        return "Deviding{" +
            "words1=" + Arrays.toString(words1) +
            "words2=" + Arrays.toString(words2) +
            '}';
    }

    ///////////////////////////////////////////////////////
    public ArrayList<String> devideSigns(){
        ArrayList<String> sign = new ArrayList<String>();
        String str;
        for(int i = 0; i < signs.size(); i++){

            for(int j = 0; j < signs.get(i).length(); j++) {
                char c = signs.get(i).charAt(j);
                str = "";
                if(c == '+' || c == '-'|| c == '/'|| c == '*'){
                    str += c;
                }
                sign.add(str);
            }
        }
        return sign;
    }

    public String systemOfCounting(String s, String k){
        int n = 0;
        int count = s.length();
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(c == ' ')
                i++;
            if(c == 'A' || c =='a')
                n += Math.pow(Double.parseDouble(k),count)*10;
            if(c == 'B' || c =='b')
                n += Math.pow(Double.parseDouble(k),count)*11;
            if(c == 'C' || c =='c')
                n += Math.pow(Double.parseDouble(k),count)*12;
            if(c == 'D' || c =='d')
                n += Math.pow(Double.parseDouble(k),count)*13;
            if(c == 'E' || c =='e')
                n += Math.pow(Double.parseDouble(k),count)*14;
            if(c == 'F' || c =='f')
                n += Math.pow(Double.parseDouble(k),count)*15;
            if(c == 'G' || c =='g')
                n += Math.pow(Double.parseDouble(k),count)*16;
            if(c == '0')
                n += 0;
            if(c == '1')
                n += Math.pow(Double.parseDouble(k),count)*1;
            if(c == '2')
                n += Math.pow(Double.parseDouble(k),count)*2;
            if(c == '3')
                n += Math.pow(Double.parseDouble(k),count)*3;
            if(c == '4')
                n += Math.pow(Double.parseDouble(k),count)*4;
            if(c == '5')
                n += Math.pow(Double.parseDouble(k),count)*5;
            if(c == '6')
                n += Math.pow(Double.parseDouble(k),count)*6;
            if(c == '7')
                n += Math.pow(Double.parseDouble(k),count)*7;
            if(c == '8')
                n += Math.pow(Double.parseDouble(k),count)*8;
            if(c == '9')
                n += Math.pow(Double.parseDouble(k),count)*9;

            count--;
        }
        return Integer.toString(n);
    }


    public String turnInSystemOfCounting(String s, String k){
        int n = 0;
        String v = "";
        s = s.replaceAll("\\-","");
        s = s.replaceAll(" ","");
        int count = s.length();
        for(int i = 0; i < s.length(); i++){
            n = Integer.parseInt(s)%Integer.parseInt(k);
            if(n == 1)
                v += "1";
            if(n == 2)
                v += "2";
            if(n == 3)
                v += "3";
            if(n == 4)
                v += "4";
            if(n == 5)
                v += "5";
            if(n == 6)
                v += "6";
            if(n == 7)
                v += "7";
            if(n == 8)
                v += "8";
            if(n == 9)
                v += "9";
            if(n == 10)
                v += "A";
            if(n == 11)
                v += "B";
            if(n == 12)
                v += "C";
            if(n == 13)
                v += "D";
            if(n == 14)
                v += "E";
            if(n == 15)
                v += "F";
            if(n == 16)
                v += "G";
            n = Integer.parseInt(s)/Integer.parseInt(k);
            count--;
        }
        return v;
    }


    public void countsSystem(){
        for(int i = 0; i < val.length; i++){
            val[i] = systemOfCounting(val[i],system);
        }
        for(String d: val){
            System.out.println(d+" ");
        }
    }

    public ArrayList counting() {
        countsSystem();
        ArrayList<String> s = new ArrayList<String>(devideSigns());
        for(int i = 0; i < s.size(); i++){
            if(s.get(i) == "")
                s.remove(i);
        }
        ArrayList<String> n = new ArrayList<String>();
        for(int i = 0; i < val.length; i++){
            if(val[i] != "0")
                n.add(val[i]);
        }
        int num = 0;
        String string;
        for (int i = 0; i < s.size(); i++) {
            String str = s.get(i);
            if (str.equals("*")) {
                num = Integer.parseInt(n.get(i)) * Integer.parseInt(n.get(i + 1));
                finalexpressions.add(Integer.toString(num));
                n.set(i + 1, Integer.toString(num));
                n.remove(i);
                s.remove(i);
                i--;
            }
            if (str.equals("/")) {
                num = Integer.parseInt(n.get(i)) / Integer.parseInt(n.get(i + 1));
                finalexpressions.add(Integer.toString(num));
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
                string = n.get(i) +" + "+ n.get(i + 1);
                finalexpressions.add(string);
                n.set(i + 1, Integer.toString(num));
                n.remove(i);
                s.remove(i);
                i--;
            }
            if (str.equals("-")) {
                num = Integer.parseInt(n.get(i)) - Integer.parseInt(n.get(i + 1));
                string = n.get(i) +" - "+ n.get(i + 1);
                finalexpressions.add(string);
                n.set(i + 1, Integer.toString(num));
                n.remove(i);
                s.remove(i);
                i--;
            }
        }
        for(int i = 0; i < n.size(); i++){
            if(n.get(i).equals("0"))
                n.remove(i);
        }
        return n;
    }
///////////////////////////////////////////////////////

    public void makingExpressions(){
        int j = 0;
        ArrayList<String> ar = new ArrayList<String>(finalexpressions);
        for(int i = finalexpressions.size()-1; i >= 0; i--){
            String a = ar.get(i);
            finalexpressions.set(j, a);
            j++;
        }
        System.out.println(finalexpressions);
    }

    public ArrayList<String> sortingExpressions(){
        ArrayList<String> ar = new ArrayList<String>(finalexpressions);
        ar.sort(new CompareThings());
        return ar;
    }
}

