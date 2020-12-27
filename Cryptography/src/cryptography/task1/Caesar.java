package cryptography.task1;

public class Caesar {

	public static String encrypt(String message, int offset) {
		StringBuilder result = new StringBuilder();
		for (char character : message.toCharArray()) {
			if (character != ' ') {
				int originalAlphabetPosition = character - 'a';
				int newAlphabetPosition = (originalAlphabetPosition + offset) % 26;
				char newCharacter = (char) ('a' + newAlphabetPosition);
				if (newCharacter < 'a' && newCharacter > 'Z') {
					newCharacter = (char) (newCharacter - 'a' + 'z' + 1);
				}
				if (newCharacter < 'A') {
					newCharacter = (char) (newCharacter - 'A' + 'Z' + 1);
				}
				result.append(newCharacter);
			} else {
				result.append(character);
			}
		}
		return result.toString();
	}

	public static String decrypt(String message, int offset) {
		return encrypt(message, -offset);
	}

	public static void main(String[] args) {
		String message = "Hello world";
		int offset = 7;
		String encryptedMessage = encrypt(message, offset);
		System.out.println("original message: " + message);
		System.out.println("encrypted message: " + encryptedMessage);
		System.out.println("decrypted message: " + decrypt(encryptedMessage, offset));
	}

}
