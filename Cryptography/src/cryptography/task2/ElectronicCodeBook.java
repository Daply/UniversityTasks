package cryptography.task2;

/**
 * Created by Daria on 29.03.2016.
 */

import java.io.UnsupportedEncodingException;
import java.util.UUID;

public class ElectronicCodeBook implements BlockCipherMode {

    private Belt belt;

    public ElectronicCodeBook(Belt belt) {
        this.belt = belt;
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

    public String encrypt(String text) throws UnsupportedEncodingException {
        text = belt.stringToBinaryString(text);
        System.out.println("parent: "+text);
        String[] blocks = getBlocks(text, 64);
        StringBuilder builder = new StringBuilder();
        for(String block : blocks) {
            builder.append(belt.encrypt(block));
        }
        String code = new String(builder);
        System.out.println("encrypted: " + code);
        return code;
    }

    public String decrypt(String code) throws UnsupportedEncodingException {
        String[] blocks = getBlocks(code, 64);
        StringBuilder builder = new StringBuilder();
        for(String block : blocks) {
            builder.append(belt.decrypt(block));
        }
        String text = new String(builder);
        System.out.println("decrypted: " + text);
        text = belt.binaryStringToOriginalString(text);
        System.out.println("decrypted as text: " + text);
        return text;
    }

}
