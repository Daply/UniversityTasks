package cryptography.task1;

public class Vigenere {

	public static String encrypt(String message, String key) {
		message = message.toUpperCase();
		StringBuilder result = new StringBuilder();
		for (int i = 0, j = 0; i < message.length(); i++) {
			char character = message.charAt(i);
			if (character < 'A' || character > 'Z')
				continue;
			char newCharacter = (char) ((character + key.charAt(j) - 2 * 'A') % 26 + 'A');
			result.append(newCharacter);
			j = ++j % key.length();
		}
		return result.toString();
	}

	public static String decrypt(String message, String key) {
		message = message.toUpperCase();
		StringBuilder result = new StringBuilder();
		for (int i = 0, j = 0; i < message.length(); i++)
		{
			char c = message.charAt(i);
			if (c < 'A' || c > 'Z')
				continue;
			char newCharacter = (char) ((c - key.charAt(j) + 26) % 26 + 'A');
			result.append(newCharacter);
			j = ++j % key.length();
		}
		return result.toString();
	}

	public static void main(String[] args) {
		String message = "Hello beautiful world, here we are!";
		String key = "KEY";
		String encryptedMessage = encrypt(message, key);
		System.out.println("original message: " + message);
		System.out.println("encrypted message: " + encryptedMessage);
		System.out.println("decrypted message: " + decrypt(encryptedMessage, key));
	}

}
