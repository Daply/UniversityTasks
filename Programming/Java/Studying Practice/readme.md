
## Studying practice

[<b>Web Chat Application</b>](https://github.com/Daply/university-assignments/blob/master/Programming/Java/Studying%20Practice/Chat/WebChatApplication/readme.md)

A task.<br>
To create a simple web chat application (using java, javascript, html, css), where it is possible to:<br>
- send messages
- edit messages
- delete messages

If user changes name, the new message from this user will be from the edited name of this user.<br>
There should be used MySql database and ajax in javascript.


General instructions / recommendations:<br>
1. It is recommended to use Tomcat 7 as a server
2. All web applications, by their nature, must support the simultaneous operation of several users, therefore<br>
a. Don't use static, synchronized unless necessary.<br>
b. Multithreading is already implemented by the server (Tomcat, etc.). Do not create new threads unless you need to.<br>
c. If the application uses shared resources such as files and others, then care must be taken to ensure that collaboration does not damage those resources.<br>
3. All messages to the user and interface elements must be localizable, for example, using property files (optional).
