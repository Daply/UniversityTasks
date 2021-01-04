package org.exadel.chat.controller;

import static org.exadel.chat.util.MessageUtil.MESSAGES;
import static org.exadel.chat.util.MessageUtil.TOKEN;
import static org.exadel.chat.util.MessageUtil.getToken;
import static org.exadel.chat.util.MessageUtil.jsonToMessage;
import static org.exadel.chat.util.MessageUtil.stringToJson;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.xpath.XPathExpressionException;

import org.apache.log4j.Logger;
import org.exadel.chat.model.Message;
import org.exadel.chat.storage.sql.MessageSQLStorage;
import org.exadel.chat.storage.xml.MessageXMLStorage;
import org.exadel.chat.util.XMLHistoryUtil;
import org.exadel.chat.util.ServletUtil;
import org.json.simple.JSONObject;
import org.json.simple.parser.ParseException;
import org.xml.sax.SAXException;

@WebServlet("/messages")
public class MessageServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;
	private static final Logger logger = Logger.getLogger(MessageServlet.class.getName());

	/**
	 * XML or SQL
	 */
	private final String STORAGE = "XML";

	@Override
	public void init() {
		try {
			loadHistory();
		} catch (SAXException | IOException | ParserConfigurationException | TransformerException e) {
			logger.error(e);
		}
	}

	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
		logger.info("doGet");
		String token = request.getParameter(TOKEN);
		logger.info("Token " + token);

		if (token != null && !"".equals(token)) {
			String messages = formResponse();
			response.setContentType(ServletUtil.APPLICATION_JSON);
			PrintWriter out = response.getWriter();
			out.print(messages);
			out.flush();
		} else {
			response.sendError(HttpServletResponse.SC_BAD_REQUEST, "'token' parameter needed");
		}
	}

	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
		logger.info("doPost");
		String data = ServletUtil.getMessageBody(request);
		logger.info(data);
		try {
			JSONObject json = stringToJson(data);
			Message message = jsonToMessage(json);
			if (STORAGE.equals("XML")) {
				MessageXMLStorage.addMessage(message);
				XMLHistoryUtil.addData(message);
			}
			else if (STORAGE.equals("SQL")) {
				MessageSQLStorage.addMessage(message);
			}
			response.setStatus(HttpServletResponse.SC_OK);
		} catch (ParseException | ParserConfigurationException | SAXException | TransformerException e) {
			logger.error(e);
			response.sendError(HttpServletResponse.SC_BAD_REQUEST);
		}
	}
	
	@Override
	protected void doDelete(HttpServletRequest request, HttpServletResponse response) throws IOException {
		logger.info("doDelete");
		String data = ServletUtil.getMessageBody(request);
		logger.info(data);
		try {
			JSONObject json = stringToJson(data);
			Message message = jsonToMessage(json);
			if (message != null) {
				String id = message.getId();
				if (STORAGE.equals("XML")) {
					Message messageToDelete = MessageXMLStorage.getMessageById(id);
					if (messageToDelete != null) {
						MessageXMLStorage.deleteMessage(messageToDelete);
						XMLHistoryUtil.deleteData(messageToDelete);
						response.setStatus(HttpServletResponse.SC_OK);
					}
				}
				else if (STORAGE.equals("SQL")) {
					Message messageToDelete = MessageSQLStorage.getMessageById(id);
					if (messageToDelete != null) {
						MessageSQLStorage.deleteMessage(messageToDelete);
						response.setStatus(HttpServletResponse.SC_OK);
					}
				}
			}
		} catch (ParseException | ParserConfigurationException | SAXException | TransformerException e) {
			logger.error(e);
			response.sendError(HttpServletResponse.SC_BAD_REQUEST);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	@Override
	protected void doPut(HttpServletRequest request, HttpServletResponse response) throws IOException {
		logger.info("doPut");
		String data = ServletUtil.getMessageBody(request);
		logger.info(data);
		try {
			JSONObject json = stringToJson(data);
			Message message = jsonToMessage(json);
			String id = message.getId();

			if (STORAGE.equals("XML")) {
				Message messageToUpdate = MessageXMLStorage.getMessageById(id);
				if (messageToUpdate != null) {
					messageToUpdate.setAuthor(message.getAuthor());
					messageToUpdate.setContent(message.getContent());
					XMLHistoryUtil.updateData(messageToUpdate);
					response.setStatus(HttpServletResponse.SC_OK);
				} else {
					response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Message does not exist");
				}
			}
			else if (STORAGE.equals("SQL")) {
				Message messageToUpdate = MessageSQLStorage.getMessageById(id);
				if (messageToUpdate != null) {
					messageToUpdate.setAuthor(message.getAuthor());
					messageToUpdate.setContent(message.getContent());
					MessageSQLStorage.updateMessage(messageToUpdate);
					response.setStatus(HttpServletResponse.SC_OK);
				} else {
					response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Message does not exist");
				}
			}
		} catch (ParseException | ParserConfigurationException | SAXException | TransformerException | XPathExpressionException e) {
			logger.error(e);
			response.sendError(HttpServletResponse.SC_BAD_REQUEST);
		}
	}

	@SuppressWarnings("unchecked")
	private String formResponse() {
		JSONObject jsonObject = new JSONObject();
		if (STORAGE.equals("XML")) {
			jsonObject.put(MESSAGES, MessageXMLStorage.getStorage());
		}
		else if (STORAGE.equals("SQL")) {
			jsonObject.put(MESSAGES, MessageSQLStorage.getStorage());
		}
		jsonObject.put(TOKEN, getToken(MessageXMLStorage.getSize()));
		return jsonObject.toJSONString();
	}

	private void loadHistory() throws SAXException, IOException, ParserConfigurationException, TransformerException  {
		if (STORAGE.equals("XML")) {
			if (XMLHistoryUtil.doesStorageExist()) {
				MessageXMLStorage.addAll(XMLHistoryUtil.getMessages());
			} else {
				XMLHistoryUtil.createStorage();
				addStubData();
			}
		}
		else if (STORAGE.equals("SQL")) {
			if (MessageSQLStorage.getSize() == 0) {
				addStubData();
			}
		}
	}
	
	private void addStubData() {
		Message[] stubMessages = {
				new Message("1", "Sarah", "Hello!!!"),
				new Message("2", "Ann", "How are you?") };
		if (STORAGE.equals("XML")) {
			MessageXMLStorage.addAll(stubMessages);
			for (Message message : stubMessages) {
				try {
					XMLHistoryUtil.addData(message);
				} catch (ParserConfigurationException | SAXException | IOException | TransformerException e) {
					logger.error(e);
				}
			}
		}
		else if (STORAGE.equals("SQL")) {
			MessageSQLStorage.addAll(stubMessages);
		}
	}

}
