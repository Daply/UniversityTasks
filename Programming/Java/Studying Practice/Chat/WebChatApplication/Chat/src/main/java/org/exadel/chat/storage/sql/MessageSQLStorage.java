package org.exadel.chat.storage.sql;

import org.exadel.chat.model.Message;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public final class MessageSQLStorage {

	private static final String DRIVER = "com.mysql.cj.jdbc.Driver";
	private static final String URL = "jdbc:mysql://localhost/chat";
	private static final String USER = "root";
	private static final String PASSWORD = "root";

	private static final String SELECT_ALL_MESSAGES = "select * from message";
	private static final String INSERT_MESSAGE = "insert message(id, author, content) values ";
	private static final String UPDATE_MESSAGE = "update message set ";
	private static final String WHERE_ID = "where id=";
	private static final String MESSAGE_AUTHOR = "author";
	private static final String MESSAGE_CONTENT = "content";
	private static final String DELETE_MESSAGE_BY_ID = "delete from message where id=";
	private static final String SELECT_MESSAGES_SIZE = "select count(*) as size from message";
	private static final String SELECT_MESSAGE_BY_ID = "select * from message where id=";

	private MessageSQLStorage() {
	}

	public static List<Message> getStorage() {
		List<Message> messages = new ArrayList<>();
		Connection connection = getConnection();
		PreparedStatement statement = null;
		ResultSet resultSet = null;
		if (connection != null) {
			try {
				statement = connection.prepareStatement(SELECT_ALL_MESSAGES);
				resultSet = statement.executeQuery();
				while (resultSet != null && resultSet.next()) {
					Message message = new Message(String.valueOf(resultSet.getLong(1)),
							resultSet.getString(2), resultSet.getString(3));
					messages.add(message);
				}
			} catch (SQLException throwables) {
				throwables.printStackTrace();
			} finally {
				try {
					connection.close();
					if (statement != null) {
						statement.close();
					}
					if (resultSet != null) {
						resultSet.close();
					}
				} catch (SQLException throwables) {
					throwables.printStackTrace();
				}
			}
		}
		return messages;
	}

	public static void addMessage(Message message) {
		String query = INSERT_MESSAGE + "(" + message.getId() + ", '" + message.getAuthor()  + "', '" +
				message.getContent() + "')";
		executeUpdateQuery(query);
	}

	public static void updateMessage(Message message) {
		String query = UPDATE_MESSAGE +
				MESSAGE_AUTHOR + "='" + message.getAuthor()  + "', " +
				MESSAGE_CONTENT + "='" + message.getContent() + "' " +
				WHERE_ID + message.getId();
		executeUpdateQuery(query);
	}

	public static void deleteMessage(Message message) {
		String query = DELETE_MESSAGE_BY_ID + message.getId();
		executeUpdateQuery(query);
	}

	public static void deleteMessageById(String id) {
		String query = DELETE_MESSAGE_BY_ID + id;
		Connection connection = getConnection();
		PreparedStatement statement = null;
		ResultSet resultSet = null;
		if (connection != null) {
			try {
				statement = connection.prepareStatement(query);
				resultSet = statement.executeQuery();
			} catch (SQLException throwables) {
				throwables.printStackTrace();
			} finally {
				try {
					connection.close();
					if (statement != null) {
						statement.close();
					}
					if (resultSet != null) {
						resultSet.close();
					}
				} catch (SQLException throwables) {
					throwables.printStackTrace();
				}
			}
		}
	}

	public static void executeUpdateQuery(String query) {
		Connection connection = getConnection();
		PreparedStatement statement = null;
		ResultSet resultSet = null;
		if (connection != null) {
			try {
				statement = connection.prepareStatement(query);
				int result = statement.executeUpdate();
			} catch (SQLException throwables) {
				throwables.printStackTrace();
			} finally {
				try {
					connection.close();
					if (statement != null) {
						statement.close();
					}
					if (resultSet != null) {
						resultSet.close();
					}
				} catch (SQLException throwables) {
					throwables.printStackTrace();
				}
			}
		}
	}
	
	public static void addAll(Message[] messages) {
		for (Message message: messages) {
			addMessage(message);
		}
	}
	
	public static void addAll(List<Message> messages) {
		for (Message message: messages) {
			addMessage(message);
		}
	}

	public static int getSize() {
		int size = 0;
		Connection connection = getConnection();
		PreparedStatement statement = null;
		ResultSet resultSet = null;
		if (connection != null) {
			try {
				statement = connection.prepareStatement(SELECT_MESSAGES_SIZE);
				resultSet = statement.executeQuery();
				if(resultSet.next()){
					size = resultSet.getInt("size");
				}
			} catch (SQLException throwables) {
				throwables.printStackTrace();
			} finally {
				try {
					connection.close();
					if (statement != null) {
						statement.close();
					}
					if (resultSet != null) {
						resultSet.close();
					}
				} catch (SQLException throwables) {
					throwables.printStackTrace();
				}
			}
		}
		return size;
	}

	public static Message getMessageById(String id) {
		String query = SELECT_MESSAGE_BY_ID + id;
		Message message = null;
		Connection connection = getConnection();
		PreparedStatement statement = null;
		ResultSet resultSet = null;
		if (connection != null) {
			try {
				statement = connection.prepareStatement(query);
				resultSet = statement.executeQuery();
				while (resultSet != null && resultSet.next()) {
					message = new Message(String.valueOf(resultSet.getLong(1)),
							resultSet.getString(2), resultSet.getString(3));
				}
			} catch (SQLException throwables) {
				throwables.printStackTrace();
			} finally {
				try {
					connection.close();
					if (statement != null) {
						statement.close();
					}
					if (resultSet != null) {
						resultSet.close();
					}
				} catch (SQLException throwables) {
					throwables.printStackTrace();
				}
			}
		}
		return message;
	}

	private static Connection getConnection() {
		Connection connection = null;
		try {
			Class.forName(DRIVER);
			connection = DriverManager.getConnection(URL, USER, PASSWORD);
		} catch (Exception e) {
			e.printStackTrace();
		}
		return connection;
	}

}
