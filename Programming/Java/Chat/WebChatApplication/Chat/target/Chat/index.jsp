<!DOCTYPE html>
	<html>
	<head lang="en">
	    <meta charset="UTF-8">
	    <title>My chat</title>
	    <link rel="stylesheet" href="css/lib/bootstrap.css"/>
	    <link rel="stylesheet" href="css/styles.css"/>
	    <script src="js/chat.js"></script>
	    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.5.1/jquery.min.js" type="text/javascript"></script>    
	</head>
	<body background = "images/background.jpg" width="100" align="all" onload="run();">
		<div class="container-fluid app-container main">
			<div style="float:left; width:50%;">

				 <h3 class="editable" id="edits" contenteditable = "true" onclick = "storeName()">Enter your name</h3>

				 <div class="ava">
					 <img src="images/ava.jpg" >
				 </div>

				 <section class="messages">
					 <div class="server_style">server:<span class="server">available</span></div>

							<div class="input form-inline">
								<input id="messageText" type="text" class="form-control message-input" placeholder="Input message">
								<button id="addButton" type="button" class="btn btn-primary btn-add">Add</button>
								<button id="removeButton" type="button" onclick = "deleteMail()" class="btn btn-primary">Delete selected</button>
								<button id="editButton" type="button" onclick = "storeChanges()" class="btn btn-primary">Save changes</button>
							</div>
							<hr>
								<div class="items"></div>
							<hr>
					  <div class="nav">All: <span class="counter-holder">0</span> messages</div>
				 </section>
			</div>
			<pre id="output" style="float:right; width:50%;"></pre>
		</div>
	</body>
</html>