'use strict';
var ind = 1;
var storedName;
var uniqueId = function() {
	var date = Date.now();
	var random = Math.random() * Math.random();

	return Math.floor(date * random).toString();
};

var theTask = function(text, name, done) {
	return {
		description:text,
		name: name,
		done: !!done,
		id: uniqueId()
	};
};

var appState = {
	mainUrl : 'mails',
	taskList:[],
	token : 'TE11EN'
};

function run() {
	var appContainer = document.getElementsByClassName('mails')[0];

	appContainer.addEventListener('click', delegateEvent);
	appContainer.addEventListener('change', delegateEvent);
	appContainer.addEventListener('dblclick', delegateEvent);

	restore();
}

function createAllTasks(allTasks) {
	for(var i = 0; i < allTasks.length; i++)
		addTodoInternal(allTasks[i]);
}

function delegateEvent(evtObj) {
	if(evtObj.type === 'click'
		&& evtObj.target.classList.contains('btn-add'))
		onAddButtonClick();
	if(evtObj.type === 'change' 
		&& evtObj.target.nodeName == 'INPUT'
		&& evtObj.target.type == 'checkbox')
		onToggleItem(evtObj.target.parentElement);
}

function onAddButtonClick(){
	var todoText = document.getElementById('mailText');
	var Name = document.getElementById('edits');

	var textName = Name.lastChild.textContent;

	if(storedName != null)
	textName = storedName;
	
	var newTask = theTask(todoText.value, textName);

	if(todoText.value == '')
		return;

	todoText.value = '';
	addTodo(newTask, function() {
		updateCounter();
		output(appState);
	});
} 

function onToggleItem(divItem) {
	var id = divItem.attributes['data-task-id'].value;
	var taskList = appState.taskList;

	for(var i = 0; i < taskList.length; i++) {
		if(taskList[i].id != id)
			continue;

		toggle(taskList[i], function() {
			updateItem(divItem, taskList[i]);
			output(taskList);
		});

		return;
	}
}

function toggle(task, continueWith) {
	task.done = !task.done;
	put(appState.mainUrl + '?id=' + task.id, JSON.stringify(task), function() {
		continueWith();
	});
}

function updateItem(divItem, task){
	if(task.done) {
		divItem.classList.add('strikeout');
		divItem.firstChild.checked = true;
	} else {
		divItem.classList.remove('strikeout');
		divItem.firstChild.checked = false;
	}

	divItem.setAttribute('data-task-id', task.id);
	divItem.lastChild.textContent = task.description;
}

function updateName(divItem, task){
	divItem.lastChild.textContent = task.user;
}

function addTodo(task, continueWith) {
	post(appState.mainUrl, JSON.stringify(task), function(){
		restore();
	});
}

function addTodoInternal(task) {
	var item = createItem(task);
	var items = document.getElementsByClassName('items')[0];
	var taskList = appState.taskList;

	taskList.push(task);
	items.appendChild(item);
}

function createItem(task) {
	var temp = document.createElement('div');
	var htmlAsText = '<div class="first_person" data-task-id="идентификатор" id = "check_'+ind.toString()+'">'+
	'<img src = "images/ava.jpg" class = "avf">'+
	'<input id = "check_input_'+ind.toString()+
	'" type="checkbox"><small contenteditable = "true" class = "mail">сообщение</small></div>';
    ind++;

	temp.innerHTML = htmlAsText;
	updateItem(temp.firstChild, task);
	
    //createName(task);

	return temp.firstChild;
}


function createName(task) {
	var name = document.createElement('div');
	var htmlName = '<h3 class="editable" id="edits" contenteditable = "true" onclick = "storeName()">name</h3>';

name.innerHTML = htmlName;
updateName(name.firstChild, task);

return name.firstChild;
}


function updateStoredName(){
	var name = document.createElement('div');
	var htmlName = '<h3 class="editable" id="edits" contenteditable = "true" onclick = "storeName()">name</h3>';

name.innerHTML = htmlName;
var divItem = name.firstChild;
divItem.lastChild.textContent = storedName;
return name.firstChild;
}


function updateCounter(){
	var items = document.getElementsByClassName('items')[0];
	var counter = document.getElementsByClassName('counter-holder')[0];

	counter.innerText = items.children.length.toString();
}

function isServerAvailable(){
	var counter = document.getElementsByClassName('server_style')[0];

	counter.innerText = "not av";
}


function restore(continueWith) {
	var url = appState.mainUrl + '?token=' + appState.token;

	get(url, function(responseText) {
		console.assert(responseText != null);

		var response = JSON.parse(responseText);

		appState.token = response.token;
		createAllTasks(response.tasks);
		output(appState);
		updateCounter();

		continueWith && continueWith();
	});
}

function output(value){
	var output = document.getElementById('output');

	output.innerText = JSON.stringify(value, null, 2);
}

function defaultErrorHandler(message) {
	console.error(message);
	output(message);
}

function get(url, continueWith, continueWithError) {
	ajax('GET', url, null, continueWith, continueWithError);
	//jQuery.get(url, null, continueWith, continueWithError);
}

function post(url, data, continueWith, continueWithError) {
	ajax('POST', url, data, continueWith, continueWithError);	
}

function put(url, data, continueWith, continueWithError) {
	ajax('PUT', url, data, continueWith, continueWithError);	
}

function doDelete(url, data, continueWith, continueWithError) {
	ajax('DELETE', url, data, continueWith, continueWithError);	
}

function isError(text) {
	if(text == "")
		return false;
	
	try {
		var obj = JSON.parse(text);
	} catch(ex) {
		return true;
	}

	return !!obj.error;
}

function ajax(method, url, data, continueWith, continueWithError) {
	var xhr = new XMLHttpRequest();

	continueWithError = continueWithError || defaultErrorHandler;
	xhr.open(method || jQuery.get(url, null, continueWith, continueWithError), url, true);

	//jQuery.get(url, null, continueWith, continueWithError);
	
	xhr.onload = function () {
		if (xhr.readyState !== 4)
			return;

		if(xhr.status == 400) {
			document.location.href = "http://localhost:8080/Chat/400BadRequest.jsp";
			return;
		}
		
		if(xhr.status == 404) {
			document.location.href = "http://localhost:8080/Chat/404NotFound.jsp";
			return;
		}
		
		if(xhr.status == 500) {
			document.location.href = "http://localhost:8080/Chat/500InternalServerError.jsp";
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
    	ontinueWithError('Server timed out !');
    }

    xhr.onerror = function (e) {
    	var errMsg = 'Server connection error !\n'+
    	'\n' +
    	'Check if \n'+
    	'- server is active\n'+
    	'- server sends header "Access-Control-Allow-Origin:*"';

        continueWithError(errMsg);
    };

    xhr.send(data);
}

window.onerror = function(err) {
	output(err.toString());
}

function storeChanges(){
	var editElem = document.getElementsByClassName("first_person");
	for(var i = 0;i < ind;i++) {
	var userVersion = editElem[i].innerText;
    var task = appState.taskList[i];
	task.description = userVersion;
	task.name = task.name;
	put(appState.mainUrl, JSON.stringify(task), function(){
	restore();
   });		
  }
}

function storeName(){
var editElem = document.getElementById("edits");
var userName = editElem.innerText;
storedName = userName;
updateStoredName();
}

function deleteMail(){
  for(var i = 0;i < ind;i++) {
  var task = appState.taskList[i];
  if(task.done)
	doDelete(appState.mainUrl, JSON.stringify(task), function(){	
	location.reload();
    //run(); //пишу для ошибки 500
});
}
}

