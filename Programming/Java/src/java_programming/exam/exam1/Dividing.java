package java_programming.exam.exam1;

import java.io.IOException;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Daria on 20.01.2015.
 */
public class Dividing {
    private String[] logicExp;
    private String[] values;
    private String input1;
    private String input2;

    ArrayList<String> expressionPair;
    ArrayList<String> expression;
    Map<String, String> v;

    public Dividing(String input1, String input2) {
        this.input1 = input1;
        this.input2 = input2;
        expression = new ArrayList<String>();
        expressionPair = new ArrayList<String>();
        v = new HashMap<String, String>();
    }

    public void readStringFromFile() throws IOException {
        FileReading rf = new FileReading(input1);
        int n = rf.readingStringFromFile();
        logicExp = rf.readingFile(n);
        FileReading rf1 = new FileReading(input2);
        int n1 = rf1.readingStringFromFile();
        values = rf1.readingFile(n1);
    }

    public void mainMethod() throws IOException {
        addToExpressions();
        addToValues();
        expressionsWithParenthetical();
        sortingExpressionsWithParenthetical();
    }
    public void addToExpressions() throws IOException {
        readStringFromFile();
        String[] exp;
        for (int i = 0; i < logicExp.length; i++) {
            exp = logicExp[i].split(";");
            for (int j = 0; j < exp.length; j++) {
                exp[j] = exp[j].replaceAll("\n", "");
                expression.add(exp[j]);
            }
        }
    }

    public void addToValues() throws IOException {
        String[] val;
        for (int i = 0; i < values.length; i++) {
            val = values[i].split(" ");
            for (int j = 0; j < val.length; j++)
                dividingForValue(val[j]);
        }
    }

    public void expressionsWithParenthetical() throws IOException {
        ArrayList<String> ar = new ArrayList<String>(expression);
        for (int i = 0; i < ar.size(); i++) {
            dividingExpressions(ar.get(i));
        }
    }

    public ArrayList<String> sortingExpressionsWithParenthetical() throws IOException {
        ArrayList<String> ar = new ArrayList<String>(expressionPair);
        ar.sort(new CompareLength());
        return ar;
    }

    @Override
    public String toString() {
        try {
            return
                    "expressions with parenthetical=" + expressionPair +
                    "sorted expressions with parenthetical=" + sortingExpressionsWithParenthetical();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "\n";
    }

    public void dividingExpressions(String s) {
        int count = 0;
        ArrayList<String> ar = new ArrayList<String>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(')
                count++;
        }
        String regex = "\\(.*\\)";
        Pattern p = Pattern.compile(regex);
        Matcher m = p.matcher(s);
        String matchedText = "";
        for (int i = 0; i < count; i++) {
            if (m.find()) {
                matchedText = m.group();
                expressionPair.add(matchedText);
                ar.add(matchedText);
                StringBuffer sb = new StringBuffer(matchedText);
                sb.deleteCharAt(0);
                sb.deleteCharAt(sb.length() - 1);
                matchedText = new String(sb);
            }
            p = Pattern.compile(regex);
            m = p.matcher(matchedText);
        }
        for(int i = ar.size(); i >= 0 ; i--){

        }
    }

    public void counting(String s){
        ArrayList<String> count = new ArrayList<String>();
        StringBuffer sb = new StringBuffer(s);
        sb.deleteCharAt(0);
        sb.deleteCharAt(sb.length() - 1);

    }

    public void dividingForValue(String a) {
        a = a.replaceAll("=", "");
        String regex = "(?i)true|(?i)false";
        Pattern p = Pattern.compile(regex);
        Matcher m = p.matcher(a);
        if (m.find()) {
            String matchedText = m.group();
            a = a.replaceAll(matchedText, "");
            a = a.replaceAll(" ", "");
            a = a.replaceAll("\n", "");
            v.put(a, matchedText.toLowerCase());
        }
    }

}

