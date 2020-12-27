package cryptography.task1;

public class Substitution {

	public static String encrypt(String message, String key) {
		StringBuilder sb = new StringBuilder(message.length());

		for (char c : message.toCharArray())
			sb.append(key.charAt((int) c - 32));

		return sb.toString();
	}

	public static String decrypt(String message, String key) {
		StringBuilder sb = new StringBuilder(message.length());

		for (char c : message.toCharArray())
			sb.append((char) (key.indexOf(c) + 32));

		return sb.toString();
	}

	public static void main(String[] args) {
		String message = "hello beautiful world, here we are!";
		String key = "]kYV}(!7P$n5_0i R:?jOWtF/=-pe'AD&@r6%ZXs\"v*N"
				+ "[#wSl9zq2^+g;LoB`aGh{3.HIu4fbK)mU8|dMET><,Qc\\C1yxJ";
		String encryptedMessage = encrypt(message, key);
		System.out.println("original message: " + message);
		System.out.println("encrypted message: " + encryptedMessage);
		System.out.println("decrypted message: " + decrypt(encryptedMessage, key));
	}

}
