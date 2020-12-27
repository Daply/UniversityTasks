package cryptography.task2;

/**
 * Created by Daria on 29.03.2016.
 */

import java.io.UnsupportedEncodingException;

public interface BlockCipherMode {

    String encrypt(String openText) throws UnsupportedEncodingException;

    String decrypt(String code) throws UnsupportedEncodingException;

}
