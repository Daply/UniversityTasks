import java.util.Comparator;

/**
 * Created by Daria Pleshchankova on 10.02.2015.
 */

public class FruitComparator implements Comparator<String> {
    @Override
    public int compare(String o1, String o2) {
        return o1.compareTo(o2);
    }
}
