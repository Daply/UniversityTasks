package cryptography.task2;

public class BeltRealization {

    static String [][] TABLE = {{"","0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"},
            {"0","B1","94","BA","C8","0A","08","F5","3B","36","6D","00","8E","58","4A","5D","E4"},
            {"1","85","04","FA","9D","1B","B6","C7","AC","25","2E","72","C2","02","FD","CE","0D"},
            {"2","5B","E3","D6","12","17","B9","61","81","FE","67","86","AD","71","6B","89","0B"},
            {"3","5C","B0","C0","FF","33","C3","56","B8","35","C4","05","AE","D8","E0","7F","99"},
            {"4","E1","2B","DC","1A","E2","82","57","EC","70","3F","CC","F0","95","EE","8D","F1"},
            {"5","C1","AB","76","38","9F","E6","78","CA","F7","C6","F8","60","D5","BB","9C","4F"},
            {"6","F3","3C","65","7B","63","7C","30","6A","DD","4E","A7","79","9E","B2","3D","31"},
            {"7","3E","98","B5","6E","27","D3","BC","CF","59","1E","18","1F","4C","5A","B7","93"},
            {"8","E9","DE","E7","2C","8F","0C","0F","A6","2D","DB","49","F4","6F","73","96","47"},
            {"9","06","07","53","16","ED","24","7A","37","39","CB","A3","83","03","A9","8B","F6"},
            {"A","92","BD","9B","1C","E5","D1","41","01","54","45","FB","C9","5E","4D","0E","F2"},
            {"B","68","20","80","AA","22","7D","64","2F","26","87","F9","34","90","40","55","11"},
            {"C","BE","32","97","13","43","FC","9A","48","A0","2A","88","5F","19","4B","09","A1"},
            {"D","7E","CD","A4","D0","15","44","AF","8C","A5","84","50","BF","66","D2","E8","8A"},
            {"E","A2","D7","46","52","42","A8","DF","B3","69","74","C5","51","EB","23","29","21"},
            {"F","D4","EF","D9","B4","3A","62","28","75","91","14","10","EA","77","6C","DA","1D"}};

    static String[] K = new String[56]; //раундовые ключи
    static String[] WORDs = new String[4];

    public BeltRealization(){}

///////////////////////////////////Main functions//////////////////////////////////////////////

    public String encrypt(String text, String key){
        start(text, key);
        return algorithmCiphering();
    }

    public String decrypt(String text, String key){
        start(text, key);
        return algorithmDeciphering();
    }

////////////////////////////////////ALGORITHM/////////////////////////////////////////////////

    public static String algorithmCiphering(){
        String a = WORDs[0];
        String b = WORDs[1];
        String c = WORDs[2];
        String d = WORDs[3];
        String e = "";
        int i;
        String[] key = K;

        for (i = 0; i < 8; ++i) {
            b = summMod2(b,G(summ(a,key[(7*(i+1)-6)-1]),5));
            c = summMod2(c,G(summ(b,key[(7*(i+1)-5)-1]),21));
            a = sub(a, G(summ(b, key[(7*(i+1)-4)-1]), 13));
            e = summMod2(G(summ(b, key[(7*(i+1)-3)-1]), 21), int10ToSystem2(i + 1));
            b = summ(b, c);
            c = sub(c, e);
            d = summ(d, G(summ(c, key[(7*(i+1)-2)-1]), 13));
            b = summMod2(b, G(summ(a, key[(7*(i+1)-1)-1]), 21));
            c = summMod2(d, G(summ(a, key[(7*(i+1))-1]), 5));
            e = a;
            a = b;
            b = e;
            e = c;
            c = d;
            d = e;
            e = b;
            b = c;
            c = e;
        }

        return b + d + a + c;
    }

    public static String algorithmDeciphering(){
        String a = WORDs[0];
        String b = WORDs[1];
        String c = WORDs[2];
        String d = WORDs[3];
        String e;
        int i;
        String[] key = K;

        for (i = 7; i < 0; --i) {
            b = summMod2(b,G(summ(a,key[(7*(i)-1)]),5));
            c = summMod2(c,G(summ(b,key[(7*(i)-2)]),21));
            a = sub(a, G(summ(b, key[(7*(i)-3)]), 13));
            e = summMod2(G(summ(b, key[(7*(i)-4)]), 21), int10ToSystem2(i + 1));
            b = summ(b, c);
            c = sub(c, e);
            d = summ(d, G(summ(c, key[(7*(i)-5)]), 13));
            b = summMod2(b, G(summ(a, key[(7*(i)-6)]), 21));
            c = summMod2(d, G(summ(a, key[(7*(i)-7)]), 5));
            e = a;
            a = b;
            b = e;
            e = c;
            c = d;
            d = e;
            e = a;
            a = d;
            d = e;
        }

        return c + a + d + b;
    }

/////////////////////////DEVIDING TO BLOCKS WARNING!!!!!!!!  WORDS AND KEY ARE BINARY////////

    public static void start(String text, String key) {
        devidingKey(key);
        devidingText(text);
    }

    public static void devidingKey(String key) {
        String[] KEY = new String[8];
        int k = 0;
        for (int i = 0; i < 256; i += 32) {
            KEY[k] = "";
            for (int j = 0; j < 32; j++) {
                KEY[k] += key.charAt(i + j);
            }
            k++;
        }
        int n = 0;
        for (int i = 0; i < 56; i++) {
            if(n == 7)
                n = 0;
            K[i] = KEY[n];
            n++;
        }
    }

    public static void devidingText(String text) {
        int k = 0;
        for (int i = 0; i < 128; i += 32){
            WORDs[k] = "";
            for (int j = 0; j < 32; j++) {
                WORDs[k] += text.charAt(i + j);
            }
            k++;
        }
    }

    private static String[] convertToBits(String text) {
        char[] a = text.toCharArray();
        String[] bitWords = new String [a.length];
        for (int i = 0; i < a.length; i++){
            bitWords[i] = charToBits(a[i]);
        }
        return bitWords;
    }

    private static String charToBits(char c){
        String result = "";
        int n = c;
        while (n != 0) {
            int i = n % 2;
            result = i + result;
            n/=2;
        }
        int len = 8 - result.length();
        if (result.length() < 8)
            for (int j = 0; j < len; j++)
                result = '0' + result;
        return result;
    }


///////////////////////summs and subs/////////////////////////////////////////////////////////

    public static String summMod2(String u, String v) {
        String result = "";
        for (int i = 0; i < u.length(); i++) {
            if (u.charAt(i) == '0' && v.charAt(i) == '0')
                result += '0';
            if (u.charAt(i) == '0' && v.charAt(i) == '1')
                result += '1';
            if (u.charAt(i) == '1' && v.charAt(i) == '0')
                result += '1';
            if (u.charAt(i) == '1' && v.charAt(i) == '1')
                result += '0';
        }
        return result;
    }

    public static String summ(String u, String v){
        long res;
        long u1 = string2ToSystem10(u);
        long v1 = string2ToSystem10(v);
        res = u1+v1;
        return int10ToSystem2(res);
    }

    public static String sub(String u, String v){
        long res;
        long u1 = string2ToSystem10(u);
        long v1 = string2ToSystem10(v);
        res = Math.abs(u1-v1);
        return int10ToSystem2(res);
    }

    private static String int10ToSystem2(long c){
        String result = "";
        long n = c;
        while (n != 0) {
            long i = n % 2;
            result = (int) i + result;
            n/=2;
        }
        int len = 32 - result.length();
        if (result.length() < 32)
            for(int j = 0; j < len; j++)
                result = '0' + result;
        if (result.length() > 32){
            String res = result;
            result = modToString(result);
        }

        return result;
    }

    public static long string2ToSystem10(String c) {
        long res = 0;
        long pow2, value;
        for (int i = 0; i < c.length(); i++){
            pow2 = (long) Math.pow(2, c.length() - i - 1);
            value = Integer.parseInt(String.valueOf(c.charAt(i)));
            res += pow2*value;
        }
        return res;
    }

    public static long mod32(String u) {
        long u1 = string2ToSystem10(u);
        long mod = (long) Math.pow(2, 31);
        long les = u1%mod;
        return les;
    }

    public static String modToString(String u) {
        long res = mod32(u);
        return int10ToSystem2(res);
    }

/////////////////////// G ////////////////////////////////////////////////////////////////////

    public static String G(String word, int r) {
        String[] words = devidingToBlocksS(word);
        return RotHi(permutationS(words[0])+permutationS(words[1])+permutationS(words[2])+permutationS(words[3]), r);
    }

    public static String[] devidingToBlocksS(String text){
        int k = 0;
        String[] words = new String[4];
        for (int i = 0; i < 32; i += 8) {
            words[k] = "";
            for (int j = 0; j < 8; j++) {
                words[k] += text.charAt(i + j);
            }
            k++;
        }
        return words;
    }

///////////////////////Lambda (cycle turn to left)////////////////////////////////////////////

    public static String RotHi(String word, int r) {
        String result = word;
        for (int i = 0; i < r; i++) {
            result += result.charAt(0);
            result = result.substring(1);
        }
        return result;
    }

///////////////////////permutation  S/////////////////////////////////////////////////////////

    public static String permutationS(String word){
        String word16 = convertTo16System(word);
        int ind1 = 0, ind2 = 0;
        for (int i = 0; i < TABLE.length; i++) {
            if (TABLE[0][i].equals(word16.substring(0,1)))
                ind1 = i;
            if (TABLE[i][0].equals(word16.substring(1)))
                ind2 = i;
        }
        String result = convertTo2SystemFrom16(TABLE[ind1][ind2]);
        return result;
    }

    private static String convertTo16System(String word){
        String firstHalf = word.substring(0,4), secondHalf = word.substring(4,word.length());
        String[][] table = {{"0", "0000"}, {"1","0001"}, {"2","0010"}, {"3","0011"},
                {"4","0100"}, {"5","0101"}, {"6","0110"}, {"7","0111"}, {"8","1000"},
                {"9","1001"}, {"A","1010"}, {"B","1011"}, {"C","1100"}, {"D","1101"},
                {"E","1110"}, {"F","1111"}};
        for (int i = 0; i < table.length; i++) {
            if (firstHalf.equals(table[i][1]))
                firstHalf = table[i][0];
            if (secondHalf.equals(table[i][1]))
                secondHalf = table[i][0];
        }
        String result = secondHalf+firstHalf;
        return result;
    }

    private static String convertTo16System2(String word){
        String firstHalf = word.substring(0,4), secondHalf = word.substring(4,word.length());
        String[][] table = {{"0", "0000"}, {"1","0001"}, {"2","0010"}, {"3","0011"},
                {"4","0100"}, {"5","0101"}, {"6","0110"}, {"7","0111"}, {"8","1000"},
                {"9","1001"}, {"A","1010"}, {"B","1011"}, {"C","1100"}, {"D","1101"},
                {"E","1110"}, {"F","1111"}};
        for (int i = 0; i < table.length; i++) {
            if (firstHalf.equals(table[i][1]))
                firstHalf = table[i][0];
            if (secondHalf.equals(table[i][1]))
                secondHalf = table[i][0];
        }
        String result = firstHalf+secondHalf;
        return result;
    }

    private static String convertTo2SystemFrom16(String word){
        String firstHalf = word.substring(0,1), secondHalf = word.substring(1,word.length());
        String[][] table = {{"0", "0000"}, {"1","0001"}, {"2","0010"}, {"3","0011"},
                {"4","0100"}, {"5","0101"}, {"6","0110"}, {"7","0111"}, {"8","1000"},
                {"9","1001"}, {"A","1010"}, {"B","1011"}, {"C","1100"}, {"D","1101"},
                {"E","1110"}, {"F","1111"}};
        for (int i = 0; i < table.length; i++) {
            if (firstHalf.equals(table[i][0]))
                firstHalf = table[i][1];
            if (secondHalf.equals(table[i][0]))
                secondHalf = table[i][1];
        }
        String result = secondHalf+firstHalf;
        return result;
    }

    private static String convertTo2SystemFrom162(String word){
        String firstHalf = word.substring(0,1), secondHalf = word.substring(1,word.length());
        String[][] table = {{"0", "0000"}, {"1","0001"}, {"2","0010"}, {"3","0011"},
                {"4","0100"}, {"5","0101"}, {"6","0110"}, {"7","0111"}, {"8","1000"},
                {"9","1001"}, {"A","1010"}, {"B","1011"}, {"C","1100"}, {"D","1101"},
                {"E","1110"}, {"F","1111"}};
        for (int i = 0; i < table.length; i++) {
            if (firstHalf.equals(table[i][0]))
                firstHalf = table[i][1];
            if (secondHalf.equals(table[i][0]))
                secondHalf = table[i][1];
        }
        String result = firstHalf+secondHalf;
        return result;
    }
}
