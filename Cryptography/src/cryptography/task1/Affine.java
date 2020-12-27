package cryptography.task1;

import java.math.BigInteger;

public class Affine {

	private static int MOD = 26;

	/**
	 * Formula to encrypt : ax + b % 26
	 * a = first key
	 * b = second key
	 * x = is the each letter
	 *
	 * @param message
	 * @param a
	 * @param b
	 * @return
	 */
	public static String encrypt(String message, int a, int b) {
		message = message.toLowerCase();
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < message.length(); i++) {
			char character = message.charAt(i);
			if (Character.isLetter(character)) {
				character = (char) ((a * (character - 'a') + b) % MOD + 'a');
			}
			result.append(character);
		}
		return result.toString();
	}

	/**
	 * Formual to decrypt : IN * (x - b) mod 26
	 * a = first key
	 * b = second key
	 * x = 0 - infinity
	 *
	 * @param message
	 * @param a
	 * @param b
	 * @return
	 */
	public static String decrypt(String message, int a, int b) {
		message = message.toLowerCase();
		StringBuilder builder = new StringBuilder();
		BigInteger inverse = BigInteger.valueOf(a).modInverse(BigInteger.valueOf(MOD));
		for (int i = 0; i < message.length(); i++) {
			char character = message.charAt(i);
			if (Character.isLetter(character)) {
				int decoded = inverse.intValue() * (character - 'a' - b + MOD);
				character = (char) (decoded % MOD + 'a');
			}
			builder.append(character);
		}
		return builder.toString();
	}

	public static void main(String[] args) {
		String message = "hello beautiful world, here we are!";
		int a = 3;
		int b = 6;
		String encryptedMessage = encrypt(message, a, b);
		System.out.println("original message: " + message);
		System.out.println("encrypted message: " + encryptedMessage);
		System.out.println("decrypted message: " + decrypt(encryptedMessage, a, b));
	}

}
