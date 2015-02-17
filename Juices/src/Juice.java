import java.io.IOException;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by OK USER on 27.11.2014.
 */

public class Juice {
    private List<String> juices = null;
    private List<String> fruits = null;

    public Juice() {
        fruits = new ArrayList<String>();
        juices = new ArrayList<String>();
    }

    public List<String> getJuices() {
        return juices;
    }

    public List<String> getFruits() {
        return fruits;
    }

    public void setJuices(List<String> juices) {
        this.juices = juices;
    }

    public void setFruits(List<String> fruits) {
        this.fruits = fruits;
    }

    public void putFruits(List<String> ar) throws IOException {
        juices = ar;
        Iterator it = juices.iterator();
        while(it.hasNext()){
            String s = (String) it.next();
            String str[] = s.split(" ");
            for(String t: str){
                t = t.replaceAll(" ","");
                fruits.add(t);
            }
        }
    }

    public List diffFruits(){
        Set<String> set = new HashSet<String>(fruits);
        fruits = new ArrayList<String>(set);
        return fruits;
    }

    public List fruitsInAlphabeticalOrder(){
        List<String> alphafruits = fruits;
        alphafruits.sort(new FruitComparator());
        return alphafruits;
    }

    public List replacingJuices(){
        List replacedJuices = juices;

        for(int i = 0; i < replacedJuices.size()-1; i++){
            String s = replacedJuices.get(i).toString();
            for(int j = i+1; j < replacedJuices.size(); j++){
                String str = replacedJuices.get(j).toString();
                if (str.contains(s)) {
                    replacedJuices.add(i+1,str);
                    replacedJuices.remove(j+1);
                }
                if (s.contains(str)){
                    replacedJuices.add(i,str);
                    replacedJuices.remove(j+1);
                }
            }
        }
        return replacedJuices;
    }

    public int countingTimesOfWashing(){
        int count = 1;
        List list = replacingJuices();
        //System.out.println(list);
        ListIterator it = list.listIterator();
        while(it.hasNext()){
            String s = (String)it.next();
            Iterator iter = it;
                if(iter.hasNext()) {
                    String str = (String) iter.next();
                    if (!str.contains(s))
                        count++;
                    s = (String) it.previous();
                }
        }
        return count;
    }

}
