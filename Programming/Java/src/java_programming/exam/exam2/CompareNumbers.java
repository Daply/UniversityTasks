package java_programming.exam.exam2;

import java.util.Comparator;

/**
 * Created by OK USER on 21.01.2015.
 */
public class CompareNumbers implements Comparator<String> {

    @Override
    public int compare(String o1, String o2) {
        if(o1.length()>o2.length())
        return -1;
        if(o1.length()<o2.length())
            return 1;
        else
            return 0;
    }
}
