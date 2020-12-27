package cryptography.task2;

/**
 * Created by Daria on 29.03.2016.
 */

import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.util.UUID;

public class CounterMode implements BlockCipherMode {

    private Belt belt;
    private String[] ctr;

    public CounterMode(Belt belt) {
        this.belt = belt;
    }

    private void setCtr(int m) throws UnsupportedEncodingException {
        String uuid = UUID.randomUUID().toString().replaceAll("-", "");
        ctr = new String[m];
        ctr[0] = belt.stringToBinaryString(uuid.substring(0, 8));
        for (int i = 1; i < m; i++) {
            BigInteger bigInteger = new BigInteger(ctr[i - 1],2);
            bigInteger = bigInteger.add(new BigInteger("1",2));
            ctr[i] = String.format("%64s", bigInteger.toString(2)).replace(" ", "0");
        }
    }

    public String encrypt(String openText) throws UnsupportedEncodingException {
        openText = belt.stringToBinaryString(openText);
        System.out.println("parent: " + openText);
        String[] blocks = getBlocks(openText, 64);
        setCtr(blocks.length);
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < blocks.length; i++) {
            builder.append(xor(belt.encrypt(ctr[i]), blocks[i]));
        }
        String code = new String(builder);
        System.out.println("encrypted: " + code);
        return code;
    }

    public String decrypt(String code) throws UnsupportedEncodingException {
        String[] blocks = getBlocks(code, 64);
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < blocks.length; i++) {
            builder.append( xor(belt.encrypt(ctr[i]), blocks[i]));
        }
        String text = new String(builder);
        System.out.println("decrypted: " + text);
        text = belt.binaryStringToOriginalString(text);
        System.out.println("decrypted as text: " + text);
        return text;
    }

    private String[] getBlocks(String text, int size) throws UnsupportedEncodingException {
        int n = text.length() / size;
        if(text.length() % size != 0) {
            String uuid = UUID.randomUUID().toString().replaceAll("-","");
            uuid = belt.stringToBinaryString(uuid);
            text = text.concat(uuid.substring(0, size - text.length() % size));
            n++;
        }
        String[] blocks = new String[n];
        for (int i = 0; i < n; i++) {
            blocks[i] = text.substring(i * size, (i + 1) * size);
        }
        return blocks;
    }

    private String xor(String a, String b) {
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < a.length(); i++) {
            stringBuilder.append(a.charAt(i) == b.charAt(i) ? "0" : "1");
        }
        return new String(stringBuilder);
    }

}
