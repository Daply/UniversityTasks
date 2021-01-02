'use strict';
var ind = 1;
var storedName;

var uniqueId = function() {
	var date = Date.now();
	var random = Math.random() * Math.random();

	return Math.floor(date * random).toString();
};

var theMessage = function(author, content) {
	return {
		author: author,
		content: content,
		id: uniqueId()
	};
};

var appState = {
	mainUrl : 'messages',
	messageList: [],
	token : 'TE11EN'
};

function run() {
	var appContainer = document.getElementsByClassName('messages')[0];

	appContainer.addEventListener('click', delegateEvent);
	appContainer.addEventListener('change', delegateEvent);
	appContainer.addEventListener('dblclick', delegateEvent);

	restore();
};

function createAllMessages(allMessages) {
	for (var i = 0; i < allMessages.length; i++) {
		addMessageInternal(allMessages[i]);
	}
};

function delegateEvent(evtObj) {
	if (evtObj.type === 'click'
		&& evtObj.target.classList.contains('btn-add')) {
		onAddButtonClick();
	}

	if (evtObj.type === 'change'
		&& evtObj.target.nodeName == 'INPUT'
		&& evtObj.target.type == 'checkbox') {
		onToggleItem(evtObj.target.parentElement);
	}
};

function onAddButtonClick(){
	var messageText = document.getElementById('messageText');
	var nameEdit = document.getElementById('nameEdit');

	var textName = nameEdit.lastChild.textContent;

	if (storedName != null) {
		textName = storedName;
	}
	
	var newMessage = theMessage(messageText.value, textName);

	if (messageText.value == '') {
		return;
	}

	messageText.value = '';
	addMessage(newMessage, function() {
		updateCounter();
		output(appState);
	});
};

function onToggleItem(divItem) {
	var id = divItem.attributes['data-message-id'].value;
	var messageList = appState.messageList;

	for(var i = 0; i < messageList.length; i++) {
		if(messageList[i].id != id)
			continue;

		toggle(messageList[i], function() {
			updateItem(divItem, messageList[i]);
			output(messageList);
		});

		return;
	}
};

function toggle(message, continueWith) {
	put(appState.mainUrl + '?id=' + message.id, JSON.stringify(message), function() {
		continueWith();
	});
};

function updateItem(divItem, message){
	if(message.done) {
		divItem.classList.add('strikeout');
		divItem.firstChild.checked = true;
	} else {
		divItem.classList.remove('strikeout');
		divItem.firstChild.checked = false;
	}

	divItem.setAttribute('data-message-id', message.id);
	divItem.lastChild.textContent = message.description;
};

function updateName(divItem, message){
	divItem.lastChild.textContent = message.user;
};

function addMessage(message, continueWith) {
	post(appState.mainUrl, JSON.stringify(message), function(){
		restore();
	});
};

function addMessageInternal(message) {
	var item = createItem(message);
	var items = document.getElementsByClassName('items')[0];
	var messageList = appState.messageList;

	messageList.push(message);
	items.appendChild(item);
};

function createItem(message) {
	var temp = document.createElement('div');
	var htmlAsText = '<div class="first_person" data-message-id="identificator" id = "check_'+ind.toString()+'">'+
	'<img src = "images/ava.jpg" class = "avf">'+
	'<input id = "check_input_'+ind.toString()+
	'" type="checkbox"><small contenteditable = "true" class = "message">message</small></div>';
    ind++;

	temp.innerHTML = htmlAsText;
	updateItem(temp.firstChild, message);
	
    //createName(message);

	return temp.firstChild;
};

function createName(message) {
	var name = document.createElement('div');
	var htmlName = '<h3 class="editable" id="edits" contenteditable = "true" onclick = "storeName()">name</h3>';

	name.innerHTML = htmlName;
	updateName(name.firstChild, message);

	return name.firstChild;
};

function updateStoredName(){
	var name = document.createElement('div');
	var htmlName = '<h3 class="editable" id="edits" contenteditable = "true" onclick = "storeName()">name</h3>';

	name.innerHTML = htmlName;
	var divItem = name.firstChild;
	divItem.lastChild.textContent = storedName;
	return name.firstChild;
};

function updateCounter(){
	var items = document.getElementsByClassName('items')[0];
	var counter = document.getElementsByClassName('counter-holder')[0];

	counter.innerText = items.children.length.toString();
};

function isServerAvailable(){
	var counter = document.getElementsByClassName('server_style')[0];

	counter.innerText = "not av";
};

function restore(continueWith) {
	var url = appState.mainUrl + '?token=' + appState.token;

	get(url, function(responseText) {
		console.assert(responseText != null);

		var response = JSON.parse(responseText);

		appState.token = response.token;
		createAllMessages(response.messages);
		output(appState);
		updateCounter();

		continueWith && continueWith();
	});
};

function output(value){
	var output = document.getElementById('output');

	output.innerText = JSON.stringify(value, null, 2);
};

function defaultErrorHandler(message) {
	console.error(message);
	output(message);
};

function get(url, continueWith, continueWithError) {
	ajax('GET', url, null, continueWith, continueWithError);
	//jQuery.get(url, null, continueWith, continueWithError);
};

function post(url, data, continueWith, continueWithError) {
	ajax('POST', url, data, continueWith, continueWithError);	
};

function put(url, data, continueWith, continueWithError) {
	ajax('PUT', url, data, continueWith, continueWithError);	
};

function doDelete(url, data, continueWith, continueWithError) {
	ajax('DELETE', url, data, continueWith, continueWithError);	
};

function isError(text) {
	if(text == "")
		return false;
	
	try {
		var obj = JSON.parse(text);
	} catch(ex) {
		return true;
	}

	return !!obj.error;
};

function ajax(method, url, data, continueWith, continueWithError) {
	var xhr = new XMLHttpRequest();

	continueWithError = continueWithError || defaultErrorHandler;
	xhr.open(method || jQuery.get(url, null, continueWith, continueWithError), url, true);

	//jQuery.get(url, null, continueWith, continueWithError);
	
	xhr.onload = function () {
		if (xhr.readyState !== 4)
			return;

		if(xhr.status == 400) {
			document.location.href = "http://localhost:8080/chat/400BadRequest.jsp";
			return;
		}
		
		if(xhr.status == 404) {
			document.location.href = "http://localhost:8080/chat/404NotFound.jsp";
			return;
		}
		
		if(xhr.status == 500) {
			document.location.href = "http://localhost:8080/chat/500InternalServerError.jsp";
			return;
		}
		
		if(xhr.status != 200) {
			continueWithError('Error on the server side, response ' + xhr.status);
			return;
		}

		if(isError(xhr.responseText)) {
			continueWithError('Error on the server side, response ' + xhr.responseText);
			return;
		}

		continueWith(xhr.responseText);
	};    

    xhr.ontimeout = function () {
    	continueWithError('Server timed out!');
    }

    xhr.onerror = function (e) {
    	var errMsg = 'Server connection error!\n'+
    	'\n' +
    	'Check if \n'+
    	'- server is active\n'+
    	'- server sends header "Access-Control-Allow-Origin:*"';

        continueWithError(errMsg);
    };

    xhr.send(data);
};

window.onerror = function(err) {
	output(err.toString());
};

function storeChanges(){
	var editElem = document.getElementsByClassName("first_person");
	for(var i = 0;i < ind;i++) {
	var userVersion = editElem[i].innerText;
    var message = appState.messageList[i];
	message.content = userVersion;
	//message.name = message.name;
	put(appState.mainUrl, JSON.stringify(message), function(){
	restore();
   });		
  }
};

function storeName(){
	var editElem = document.getElementById("edits");
	var userName = editElem.innerText;
	storedName = userName;
	updateStoredName();
};

function deleteMessage() {
  for (var i = 0;i < ind;i++) {
	  var message = appState.messageList[i];
	  if (message.done) {
		  doDelete(appState.mainUrl, JSON.stringify(message), function () {
			  location.reload();
			  //run();
		  });
	  }
  }
};