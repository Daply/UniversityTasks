package cryptography.task2;

/**
 * Created by Daria on 29.03.2016.
 */

import java.io.UnsupportedEncodingException;
import java.util.UUID;

public class CipherFeedback implements BlockCipherMode {

    private Belt belt;
    private String initializationVector;

    public CipherFeedback(Belt belt) throws UnsupportedEncodingException {
        this.belt = belt;
        setInitializationVector();
    }

    private void setInitializationVector() throws UnsupportedEncodingException {
        String uuid = UUID.randomUUID().toString().replaceAll("-", "");
        initializationVector = belt.stringToBinaryString(uuid.substring(0, 8));
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

    public String encrypt(String openText) throws UnsupportedEncodingException {
        openText = belt.stringToBinaryString(openText);
        System.out.println("parent: " + openText);
        String[] blocks = getBlocks(openText, 64);
        StringBuilder builder = new StringBuilder();
        String prevEncodedBlock = xor(belt.encrypt(initializationVector), blocks[0]);
        builder.append(prevEncodedBlock);
        for (int i = 1; i < blocks.length; i++) {
            prevEncodedBlock = xor(belt.encrypt(prevEncodedBlock), blocks[i]);
            builder.append(prevEncodedBlock);
        }
        String code = new String(builder);
        System.out.println("encrypted: " + code);
        return code;
    }

    public String decrypt(String code) throws UnsupportedEncodingException {
        String[] blocks = getBlocks(code, 64);
        StringBuilder builder = new StringBuilder();
        builder.append(xor(belt.encrypt(initializationVector), blocks[0]));
        for (int i = 1; i < blocks.length; i++) {
            builder.append(xor(belt.encrypt(blocks[i - 1]), blocks[i]));
        }
        String text = new String(builder);
        System.out.println("decrypted: " + text);
        text = belt.binaryStringToOriginalString(text);
        System.out.println("decrypted as text: " + text);
        return text;
    }

}
