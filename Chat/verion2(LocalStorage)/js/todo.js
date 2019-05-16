var uniqueId = function() {
		var date = Date.now();
		var random = Math.random() * Math.random();
	
		return Math.floor(date * random).toString();
	};
	
	var theTask = function(text, done) {
		return {
			description:text,
			done: !!done,
			id: uniqueId()
		};
	};
	
	var taskList = [];
	var ind = 0;
	function run(){
		var appContainer = document.getElementsByClassName('todos')[0];
	
		appContainer.addEventListener('click', delegateEvent);
		appContainer.addEventListener('change', delegateEvent);
		appContainer.addEventListener('dblclick', delegateEvent);
		
		restoreName();
		var allTasks = restore() || [ theTask('Привет', true),
				theTask('Как дела? ', true)
			];
		
	    
		createAllTasks(allTasks);
		updateCounter();
	}
	
	function createAllTasks(allTasks) {
		for(var i = 0; i < allTasks.length; i++){
			addTodo(allTasks[i]);
	}
	}
	
	
	
	function delegateEvent(evtObj) {
		if(evtObj.type === 'dblclick'
			&& evtObj.target.classList.contains('item'))
			onDblClickItem(evtObj.target);
		if(evtObj.type === 'click'
			&& evtObj.target.classList.contains('btn-add'))
			onAddButtonClick();
		if(evtObj.type === 'change' 
			&& evtObj.target.nodeName == 'INPUT'
			&& evtObj.target.type == 'checkbox')
			onToggleItem(evtObj.target.parentElement);
	}
	
	function onDblClickItem(divItem) {
		var id = divItem.attributes['data-task-id'].value;
	
		for(var i = 0; i < taskList.length; i++) {
			if(taskList[i].id != id)
				continue;
	
			changeDescription(taskList[i]);
			updateItem(divItem, taskList[i]);
			store(taskList);

			return;
		}
	}
	
	function changeDescription(task){
		task.description += '!';
	}
	
	function onAddButtonClick(){
		var todoText = document.getElementById('todoText');
    	var newTask = theTask(todoText.value);
	
		if(todoText.value == '')
			return;
	
		addTodo(newTask);
		todoText.value = '';
		updateCounter();
		store(taskList);
	} 
	
	function onToggleItem(divItem) {
		var id = divItem.attributes['data-task-id'].value;
	
		for(var i = 0; i < taskList.length; i++) {
			if(taskList[i].id != id)
				continue;
	
			toggle(taskList[i]);
			updateItem(divItem, taskList[i]);
			store(taskList);
	
			return;
		}
	}
	
	function toggle(task) {
		task.done = !task.done;
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
	
	/////////////////////////////////////////////////////
	
	function storeChanges(){
		for(var i = 0;i < ind;i++) {
		//get the editable element​
		var editElem = document.getElementById("mail_" + i.toString());

		//get the edited element content
		var userVersion = editElem.innerHTML;
		alert(userVersion);
		//save the content to local storage
		taskList[i].description = userVersion;
			
	}
		store(taskList);
		
	}
	
	
	function reCreateItem(task){
		
		var temp = document.createElement('div');
		var htmlAsText = '<div class="first_person" data-task-id="идентификатор" id = "check_'+ind.toString()+'">'+
		'<img src = "images/ava.jpg" class = "avf">'+
		'<input id = "check_input_'+ind.toString()+
		'" type="checkbox"><small contenteditable = "true" id = "mail_'+ind.toString()+
		'">сообщение</small></div>';
		temp.innerHTML = htmlAsText;
		updateItem(temp.firstChild, task);
	
		return temp.firstChild;
	}
	
	/////////////////////////////////////////////////////
	function storeName(){
		//get the editable element
		var editElem = document.getElementById("edits");

		//get the edited element content
		var userVersion = editElem.innerHTML;

		//save the content to local storage
		localStorage.userEdits = userVersion;

		//write a confirmation to the user
		//document.getElementById("update").innerHTML="Edits saved!";
		
	}
	
	function restoreName(){
		if(localStorage.userEdits!=null)
			document.getElementById("edits").innerHTML = localStorage.userEdits;
	}
	
	////////////////////////////////////////////////////
	
	function addTodo(task) {
		var item = createItem(task);
		var items = document.getElementsByClassName('items')[0];
	
		
		taskList.push(task);
		items.appendChild(item);
  }

	function createItem(task){
		
		var temp = document.createElement('div');
		var htmlAsText = '<div class="first_person" data-task-id="идентификатор" id = "check_'+ind.toString()+'">'+
		'<img src = "images/ava.jpg" class = "avf">'+
		'<input id = "check_input_'+ind.toString()+
		'" type="checkbox"><small contenteditable = "true" id = "mail_'+ind.toString()+
		'">сообщение</small></div>';
	    ind++;
		temp.innerHTML = htmlAsText;
		updateItem(temp.firstChild, task);
	
		return temp.firstChild;
	}
	
	function updateCounter(){
		var items = document.getElementsByClassName('items')[0];
		var counter = document.getElementsByClassName('counter-holder')[0];
	
		counter.innerText = items.children.length.toString();
	}
	
	function deleteMail() { 
		  var checkbox = document.getElementsByClassName('items');
			for(var i = 0;i <= ind;i++) {
				if(document.getElementById("check_input_" + i.toString()) != null){
		  	    	if(document.getElementById("check_input_" + i.toString()).checked) {
		  	    		taskList.splice(i,1);
		  				store(taskList);
		  				updateCounter();
		  	        return (element = document.getElementById("check_" + i.toString())).parentNode.removeChild(element);
		  	    	}
			    }
			}
     }
	
	function store(listToSave) {
	
		if(typeof(Storage) == "undefined") {
			alert('localStorage is not accessible');
			return;
		}
	
		localStorage.setItem("taskList", JSON.stringify(listToSave));
	}
	
	function restore() {
		if(typeof(Storage) == "undefined") {
			alert('localStorage is not accessible');
			return;
		}
		
		var item = localStorage.getItem("taskList");
	
		return item && JSON.parse(item);
	}
	
	function output(value){
	}
	
	function serverChecking(){
		var onl = document.getElementsByClassName('server')[0];
		var img = document.body.appendChild(document.createElement("img"));
		  img.onload = function()
  	    {
          onl.innerText = "available";
  	    };
  	    img.onerror = function()
  	    {
  	      onl.innerText = "not available";
  	    };
	}
	
	