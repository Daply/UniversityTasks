package org.exadel.todos.util;

import org.exadel.todos.model.Message;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

public final class TaskUtil {
	public static final String TOKEN = "token";
	public static final String MESSAGES = "messages";
	private static final String TN = "TN";
	private static final String EN = "EN";
	private static final String ID = "id";
	private static final String AUTHOR = "author";
	private static final String CONTENT = "content";

	private TaskUtil() {
	}

	public static String getToken(int index) {
		int number = index * 8 + 11;
		return TN + number + EN;
	}

	public static int getIndex(String token) {
		return (Integer.parseInt(token.substring(2, token.length() - 2)) - 11) / 8;
	}

	public static JSONObject stringToJson(String data) throws ParseException {
		JSONParser parser = new JSONParser();
		return (JSONObject) parser.parse(data.trim());
	}

	public static Message jsonToMessage(JSONObject json) {
		Object id = json.get(ID);
		Object author = json.get(AUTHOR);
		Object content = json.get(CONTENT);

		if (id != null && author != null && content != null) {
			return new Message((String) id, (String) author, (String) content);
		}
		return null;
	}
}
