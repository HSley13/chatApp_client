# Chat App (Client)

+ **Server app source code [click me](https://github.com/HSley13/chatApp_server)**

---

## Prerequisites
+ C++ 17 or later
+ MYSQL server & mysql-connector-c++ [click me](https://dev.mysql.com/downloads/)
+ QWebAssembly [Installation tutorial](https://doc.qt.io/qt-6/wasm.html)
  + Qt@6.7 or later [Installation tutorial](https://doc.qt.io/qt-6/build-sources.html) 
  + emscripten 3.1.50 [Installation tutorial](https://emscripten.org/docs/getting_started/downloads.html)
+ argon2 (use your package manager)

---

## Introduction
> This project is a comprehensive demonstration of my understanding of Chat Applications. It is built using C++ for Backend Logic and intensive work along with QML for the graphical user interface (GUI) implementation, ensuring cross-platform compatibility.

>The application supports Desktop, Mobile and Web environments through WebAssembly. Both the server and client are built using WebAssembly, allowing them to run with all dependencies included using Wasmer or Wasmtime, ensuring seamless execution without additional setup.

---

## Functionalities
+ **Utilizes Qt for GUI, enabling the app to be cross platform**.
    1. Network Communication through QWebSocket and QWebSocketServer.
    2. Employs QtCore for core functionalities.
    3. Data Serialization (files, voice notes, and text messages) through QJsonDocument, QJsonArray and QJsonObject.
    4. Handles Audio Recording and Playback through QtMultimedia.
+ **Real-time File and Voice Note Transmission** : Send files and voice notes in real-time without degradation.
+ **Real-time is Typing... Message** : Notifies When Someone is typing a message.
+ **Password Recovery** : Uses Self-asked Secret Question and Answer that were entered when signing up.
+ **Swipe Back (from left to right) Navigation** : Swipe on the edge of the window to go back to previous ones. This Implementation was possible By overriding both QT's mousePressEvent and mouseMoveEvent core function.
+ **Dynamic Client Names** : Allows clients to change their names dynamically, reflecting changes Friend list/Group list (Whole Interface).
+ **Online/Offline Status** : Indicates user status with green (online) and red (offline) dots.
+ **Permanent Data Storage**: (Audio) Uses emscripten's IDBFS for local data storage, ensuring consistency with IndexedDB along with AWS for Files.
+ **Add New Friend**: uses People's phone number to add them in Your Friend List.
+ **Group Chats**.
    1. Admin-only controls for adding/removing group members.
    2. Upon clicked on Group Settings, it Displays group members and enables direct messaging.
    3. Notifies group members they were added to groups and by whom.
+ **Read/Unread Message Notification** : Utilizes timestamps and database integration to notify users of read/unread messages.
+ **Message Deletion** : Right Clicked or Press and Hold on one's message to delete it.

---

## ScreenShots (Previews)
Login window (Default) ![](preview_images/1.png)
Password Forgotten default ![](preview_images/2.png)
Password Forgotten (secret question --> *Who am I* in this case) ![](preview_images/3.png)
Password Forgotten (New Password) ![](preview_images/4.png)
Sign Up Widget ![](preview_images/5.png)
Conversation Window (Red Buttons == offline)![](preview_images/6.png)
Conversation Window (Green Buttons == online)![](preview_images/7.png)
Is Typing... outside of the chat ![](preview_images/8.png)
Menu Panel Options  ![](preview_images/9.png)
Menu Panel (New Conversation Clicked) ![](preview_images/10.png)
Menu Panel (New Group Clicked) ![](preview_images/11.png)
Menu Panel (Add Friend Clicked) ![](preview_images/12.png)
Search Contact (Tony in this case) ![](preview_images/13.png)
Chat Window (Red Offline status) ![](preview_images/14.png)
Chat Window (is typing...) ![](preview_images/15.png)
ChatWindow (Upon right clicked on a message) ![](preview_images/23.png)
Group Chat Window  ![](preview_images/16.png)
Group Chat Conversation (Sender Name of top of each Message) ![](preview_images/17.png)
Group Chat Window (Bruce is typing...)  ![](preview_images/18.png)
Group Setting Panel ![](preview_images/19.png)
Group Settings (Upon clicked on +Members)  ![](preview_images/20.png)
Account Settings  ![](preview_images/21.png)
Account Settings (Upon clicked on Delete Account) ![](preview_images/21.png)
Server App Default Window![](preview_images/server.png)

---

## MYSQL Database Preparation (Server app)

### Tables (OLD SERVER'S DATABASE SETUP WITH MYSQL)
### The New Server is Using MongoDB for scalability

-------accounts
```mysql
 CREATE TABLE accounts
            (
                phone_number INT PRIMARY KEY,
                first_name TEXT,
                last_name TEXT,
                alias VARCHAR(50)
            );
 ```

-------password_security
```mysql
CREATE TABLE password_security
            (
                phone_number INT PRIMARY KEY,
                hashed_password VARBINARY(500),
                secret_question TEXT,
                secret_answer TEXT
            );
 ```

-------conversations
```mysql
 CREATE TABLE conversations 
            (
                chat_ID INT PRIMARY KEY,
                participant1 TEXT,
                participant1_ID INT,
                last_message_read1 TEXT,
                participant2 TEXT,
                participant2_ID INT,
                last_message_read2 TEXT,
                start_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP
            );
 ```

-------messages
```mysql
 CREATE TABLE messages 
            (
                id INT PRIMARY KEY AUTO_INCREMENT,
                date_time VARCHAR(100) NOT NULL UNIQUE,
                chat_ID INT,
                sender_ID INT,
                receiver_ID INT,
                content TEXT,
                message_type VARCHAR(25) DEFAULT 'text'
            )AUTO_INCREMENT = 1;
 ```

-------binary_data
```mysql
CREATE TABLE binary_data 
            (
                id INT PRIMARY KEY AUTO_INCREMENT,
                date_time VARCHAR(100) NOT NULL UNIQUE,
                chat_ID INT,
                sender_ID INT,
                receiver_ID INT,
                file_name TEXT,
                file_data MEDIUMBLOB,
                data_type TEXT
            )AUTO_INCREMENT = 1;
 ```

-------group_memberships
```mysql
CREATE TABLE group_memberships 
            (
                group_ID INT,
                group_name TEXT,
                participant_ID INT,
                user_role TEXT,
                last_message_read VARCHAR(100),
                PRIMARY KEY (group_ID, participant_ID)
            );
 ```

-------group_messages
```mysql
CREATE TABLE group_messages 
            (
                id INT PRIMARY KEY AUTO_INCREMENT,
                date_time VARCHAR(100) NOT NULL UNIQUE,
                group_ID INT,
                sender TEXT,
                content TEXT,
                message_type VARCHAR(25) DEFAULT 'text'
            )AUTO_INCREMENT = 1;
```

 -------group_binary_data
```mysql
CREATE TABLE group_binary_data 
            (
                id INT PRIMARY KEY AUTO_INCREMENT,
                date_time VARCHAR(100) NOT NULL UNIQUE,
                group_ID INT,
                sender TEXT,
                file_name TEXT,
                file_data MEDIUMBLOB,
                data_type TEXT
            )AUTO_INCREMENT = 1;
 ```

 ### Triggers

-------default_alias
```mysql
CREATE TRIGGER default_alias BEFORE INSERT ON accounts
            FOR EACH ROW
                BEGIN
                    IF NEW.alias IS NULL THEN 
                        SET NEW.alias = NEW.first_name;
                    END IF;
                END;
 ```

-------add_file_message
```mysql
CREATE TRIGGER add_file_message AFTER INSERT ON binary_data 
            FOR EACH ROW 
                BEGIN
                    INSERT INTO messages (date_time, chat_ID, sender_ID, receiver_ID, content, message_type)
                    VALUES (NEW.date_time, NEW.chat_ID, NEW.sender_ID, NEW.receiver_ID, NEW.file_name, NEW.data_type);
                END;

 ```

-------update_message_deletion
```mysql
CREATE TRIGGER update_message_deletion AFTER DELETE ON messages 
            FOR EACH ROW 
                BEGIN
                    DELETE FROM binary_data WHERE date_time = OLD.date_time AND chat_ID = OLD.chat_ID;
                END;
 ```

-------update_group_message_deletion
```mysql
CREATE TRIGGER update_group_message_deletion AFTER DELETE ON group_messages 
            FOR EACH ROW 
                BEGIN
                    DELETE FROM group_binary_data WHERE date_time = OLD.date_time AND group_ID = OLD.group_ID;
                END;
 ```

-------add_group_file_message   
```mysql
CREATE TRIGGER add_group_file_message AFTER INSERT ON group_binary_data 
            FOR EACH ROW 
                BEGIN
                    INSERT INTO group_messages (date_time, group_ID, sender, content, message_type)
                    VALUES (NEW.date_time, NEW.group_ID, NEW.sender, NEW.file_name, NEW.data_type);
                END;

 ```

-------update_delete_account   
```mysql
CREATE TRIGGER update_delete_account AFTER DELETE ON accounts
            FOR EACH ROW 
            BEGIN
                DELETE FROM password_security WHERE phone_number = OLD.phone_number;
            END;
 ```

---