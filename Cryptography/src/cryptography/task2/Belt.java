package cryptography.task2;

import java.io.UnsupportedEncodingException;

public class Belt {

    private byte[] txtBlock;
    private byte[] key;
    private String[] keys;

    private final int[] getZeroKeyTranspositionArray = new int[]{
            57,49,41,33,25,17,9,1,58,50,42,34,26,18,
            10,2,59,51,43,35,27,19,11,3,60,52,44,36,
            63,55,47,39,31,23,15,7,62,54,46,38,30,22,
            14,6,61,53,45,37,29,21,13,5,28,20,12,4
    };

    private final int[] keysTranspositionArray = new int[]{
            14,17,11,24,1,5,3,28,15,6,21,10,
            23,19,12,4,26,8,16,7,27,20,13,2,
            41,52,31,37,47,55,30,40,51,45,33,48,
            44,49,39,56,34,53,46,42,50,36,29,32
    };

    private final int[] initialTranspositionArray = new int[]{
            58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,
            62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,
            57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,
            61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7
    };

    private final int[] expansionTranspositionArray = new int[]{
            32,1,2,3,4,5,4,5,6,7,8,9,
            8,9,10,11,12,13,12,13,14,15,16,17,
            16,17,18,19,20,21,20,21,22,23,24,25,
            24,25,26,27,28,29,28,29,30,31,32,1
    };

    private final int[] f_TranspositionArray = new int[]{
            16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,
            2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25
    };

    int[][][] s = new int[][][] {
            new int[][]{{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                        {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},
            new int[][]{{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
                        {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},
            new int[][]{{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
                        {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},
            new int[][]{{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
                        {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},
            new int[][]{{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
                        {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},
            new int[][]{{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
                        {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},
            new int[][]{{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
                        {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},
            new int[][]{{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
                        {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}
    };

    private final int[] finalTranspositionArray = new int[]{
            40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,
            38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,
            36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,
            34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25
    };

    public Belt(String key) throws UnsupportedEncodingException {
        generateKeys(stringToBinaryString(key));
    }

    private void generateKeys(String originalKey) {
        keys = new String[16];
        originalKey = new String(transposition(originalKey.toCharArray(), getZeroKeyTranspositionArray));
        keys[0] = getK(originalKey,0);
        for (int i = 1; i < keys.length; i++) {
            keys[i] = getK(keys[i - 1],i);
        }
        for (int i = 0; i < keys.length; i++) {
            keys[i] = new String(transposition(keys[i].toCharArray(), keysTranspositionArray));
        }
    }

    public String encrypt(String txt) {
        char[] charBlock = txt.toCharArray();
        char[] newCharBlock = transposition(charBlock, initialTranspositionArray);
        String almostResult = cycleFeistel(String.valueOf(newCharBlock), keys);
        return new String(transposition(almostResult.toCharArray(), finalTranspositionArray));
    }

    public static String stringToBinaryString(String txt) throws UnsupportedEncodingException {
        byte[] bytes = txt.getBytes("UTF-8");
        StringBuilder builder = new StringBuilder();
        for (byte b : bytes) {
            builder.append(String.format("%8s", Integer.toBinaryString(b)).replace(" ", "0"));
        }
        return new String(builder);
    }

    public static String binaryStringToOriginalString(String binaryText) throws UnsupportedEncodingException {
        byte[] bytes = new byte[binaryText.length() / 8];
        for (int i = 0; i < bytes.length; i++) {
            int a = Integer.parseInt(binaryText.substring(i * 8, (i + 1) * 8), 2);
            bytes[i] = (byte)(a);
        }
        return new String(bytes, "UTF-8");
    }

    private char[] transposition(char[] charBlock, int[] arr) {
        char[] newCharBlock = new char[arr.length];
        for (int i = 0; i < arr.length; i++) {
            newCharBlock[i] = charBlock[arr[i] - 1];
        }
        return newCharBlock;
    }

    private String cycleFeistel(String block, String[] keys) {
        String[] left = new String[17];
        String[] right = new String[17];
        left[0] = block.substring(0, 32);
        right[0] = block.substring(32);
        for (int i = 1; i < left.length; i++) {
            left[i] = right[i - 1];
            right[i] = xorStrings(left[i - 1],f(right[i - 1], keys[i - 1]));
        }
        return right[16] + left[16];
    }

    private String f(String r, String k) {
        String er = new String(transposition(r.toCharArray(), expansionTranspositionArray));
        String xor = xorStrings(er, k);
        String[] b = new String[8];
        for (int i = 0; i < b.length; i++) {
            b[i] = xor.substring(i*6, (i+1)*6);
        }
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < b.length; i++) {
            builder.append(getS(b[i], s[i]));
        }
        String resultAfterS = new String(builder);
        return new String(transposition(resultAfterS.toCharArray(), f_TranspositionArray));
    }

    private String getS(String block, int[][] arr) {
        String a = String.valueOf(new char[]{block.charAt(0), block.charAt(5)});
        String b = block.substring(1, 5);
        int resultNum = arr[Integer.parseInt(a,2)][Integer.parseInt(b,2)];
        return String.format("%4s", Integer.toBinaryString(resultNum)).replace(" ", "0");
    }

    private String getK(String prevKey, int i) {
        int[] circularShiftNum = new int[]{1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
        String c = prevKey.substring(0,28);
        String d = prevKey.substring(28);
        String cNew = rotateLeft(c, circularShiftNum[i]);
        String dNew = rotateLeft(d,circularShiftNum[i]);
        return cNew + dNew;
    }

    private String rotateLeft(String binaryStr, int num) {
        return binaryStr.substring(num) + binaryStr.substring(0,num);
    }

    private String xorStrings(String a, String b) {
        StringBuilder builder = new StringBuilder();
        for(int i = 0; i < a.length(); i++) {
            builder.append(a.charAt(i) == b.charAt(i) ? '0' : '1');
        }
        return new String(builder);
    }

    public String decrypt(String code) {
        char[] charBlock = code.toCharArray();
        char[] newCharBlock = transposition(charBlock, initialTranspositionArray);
        String almostResult = cycleFeistel(String.valueOf(newCharBlock), reverseArray(keys));
        return new String(transposition(almostResult.toCharArray(), finalTranspositionArray));
    }

    private String[] reverseArray(String[] array){
        String[] reversedArray = new String[array.length];
        for(int i = 0; i < array.length; i++){
            reversedArray[i] = array[array.length - i - 1];
        }
        return reversedArray;
    }

}
