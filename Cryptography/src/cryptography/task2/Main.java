package cryptography.task2;

/**
 * Created by Daria on 29.03.2016.
 */

import java.io.UnsupportedEncodingException;

public class Main {

    public static void main(String[] args) throws UnsupportedEncodingException {
        String text = "hello world here"; // number of symbols should be divisible by 16
        String key = "keykeykey";
        Belt belt = new Belt(key);

        BlockCipherMode blockCipherMode;

        System.out.println("====================================Electronic Code Book=================================");
        blockCipherMode = new ElectronicCodeBook(belt);
        String code = blockCipherMode.encrypt(text);
        blockCipherMode.decrypt(code);

        System.out.println("====================================Cipher Block Chaining================================");
        blockCipherMode = new CipherBlockChaining(belt);
        code = blockCipherMode.encrypt(text);
        blockCipherMode.decrypt(code);

        System.out.println("===============================Propagating CipherBlock Chaining==========================");
        blockCipherMode = new PropagatingCipherBlockChaining(belt);
        code = blockCipherMode.encrypt(text);
        blockCipherMode.decrypt(code);

        System.out.println("=======================================Cipher Feedback===================================");
        blockCipherMode = new CipherFeedback(belt);
        code = blockCipherMode.encrypt(text);
        blockCipherMode.decrypt(code);

        System.out.println("=======================================Output Feedback===================================");
        blockCipherMode = new OutputFeedback(belt);
        code = blockCipherMode.encrypt(text);
        blockCipherMode.decrypt(code);

        System.out.println("=======================================Counter Mode======================================");
        blockCipherMode = new CounterMode(belt);
        code = blockCipherMode.encrypt(text);
        blockCipherMode.decrypt(code);
    }

}
