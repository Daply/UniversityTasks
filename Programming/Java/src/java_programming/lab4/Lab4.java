package java_programming.lab4;

import java.util.Arrays;
import java.util.Comparator;

/**
 * Created by Daria on 04.10.2014.
 */

/**
 * Lab No. 4
 *
 */

public class Lab4 {

	public static boolean findEngSymbols(String a) {
		int countAbc = 0;
		for (int k = 0; k < a.length(); k++) {
			if ((a.charAt(k) >= 'a' && a.charAt(k) <= 'z') ||
					(a.charAt(k) >= 'A' && a.charAt(k) <= 'Z'))
				countAbc++;
		}
		if (countAbc == 2)
			return true;
		else
			return false;
	}

	public static void main(String[] args) {
		String str = "Ребята ходили рjkо уghом в лighс по гioбы ";
		StringBuilder s = new StringBuilder(str);

		int countPr = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == ' ')
				countPr++;
		}
		String[] words = new String[countPr + 2];

		for (int i = 0; i < countPr + 2; i++) {
			words[i] = "";
		}

		// Create an array of strings and put words there
		int countWords = 0;
		int l = 0;
		int i = 0;
		int g = 0;

		for (int j = 0; j < s.length(); j++) {   // For string characters
			char sym = s.charAt(j);
			words[i] += sym;                       // Add to the array of strings
			if (sym == ' ')
				i++;
		}
		for (i = 0; i < countPr + 2; i++) {
			if (findEngSymbols(words[i])) {
				countWords++;
				if (countWords == 1) {               // Remember the first word in the group
					g = i;
				}
				if (i == g + 1)
					l = i;
				if (i == l + 1)
					l = i;
			} else {
				if (countWords >= 3) {
					for (int d = g; d <= l; d++) {
						if (d != g + 1)
							words[d] = "";
					}
				}
				countWords = 0;
			}
		}
		for (String a : words) {
			System.out.print(a);
		}
		System.out.println(" ");

		// Sort the remaining words alphabetically
		Arrays.sort(words, new CompareWords());

		for (String a : words) {
			System.out.print(a);
		}
		System.out.println(" ");

	}
}

class CompareWords implements Comparator <String> {
	@Override
	public int compare(String a, String b)   {
		return a.compareToIgnoreCase(b);
	}
}



