<div align="right">
    <p>FlorentWasTaken<br>
    April 2024</p>
</div>
<p align="center">todo-cpp's HTTP Protocol</p>




	Table of Contents

	1.      Introduction
	2.      Architecture
	3.      Protocol
	3a.     Server
	3b.     Client

<br>
1.  Introduction

	The objective of the todo-cpp project is to develop a todo-list server
	and client like Trello

<br>
2.  Architecture

	The project is organized into a client-server architecture, with separate
	directories for the client and server components.

	Client Directory:

        - source:   This is the heart of the client-side code and is further
                    organized into various subdirectories, each dedicated to
                    a specific aspect of the client.


	Server Directory:

        - deps:     This directory appears to contain files related to
                    package management,such as "conanfile.txt" and platform
                    specific installer scripts.

        - source:   Similar to the client's src

<br>
3. HTTP Protocol

	All client-server communications are conducted using this Todo-CPP protocol.
	A message is generated when a user requests, edits, adds, or deletes data.
	Names enclosed in square brackets '[]' represent JSON fields. Data is
	transmitted as JSON. Here are some examples :

	Login example :

        {
            "code": 10,
            "email": "your@email.com",
            "password": "12345"
        }
<br>
	3a. Server

		To run the server, you must compile it first by running setup.bat on Windows.
		On Windows, simply run it using Visual Studio

		Below are the responses sent to the client after it makes a request.
		If a status code other than 200 is received, none of the JSON fields will be sent.

		Command: Authentication
			POST 10 (Login) :
				[code]  : - 200 success
						  - 400 wrong password or email
						  - 401 already connected
				[token] : client's token as string

			POST 11 (Register) :
				[code]  : - 200 success
						  - 400 wrong password or email
						  - 401 already connected
						  - 402 user already exists
				[token] : client's token as string

			POST 12 (Logout) :
				[code]  : - 200 success
						  - 400 not connected

		Command: Lists
			GET 20 (Get all lists) :
				[code]		: - 200 success
							  - 400 not connected
							  - 401 failure
				[index] 	: list's index (1, 2, 3, ...) as int. Is a table in JSON for each list
					[uuid]  : list's unique id as string
					[title] : list's name

			POST 20 (Create a list) :
				[code]		: - 200 success
							  - 400 not connected
							  - 401 failure
				[uuid]		: list's unique id as string
				[index]		: list's index as int

			GET 21 (Get list's content) :
				[code]		: - 200 success
							  - 400 not connected
							  - 401 failure
				[cards]		: JSON table containing each cards from this list
					[index] 	: card's index (1, 2, 3, ...) as int.
						[uuid]  : card's unique id as string
						[title] : card's title

		Command: Cards
			GET 30 (Get a card's detail) :
				[code]		: - 200 success
							  - 400 not connected
							  - 401 failure
				[desc]		: card's description
				[sdate]		: card's start date (0 if none) as int timestamp
				[ddate]		: card's due date (0 if none) as int timestamp
				[labels]	: JSON table containing each label from this card
					[index] 	: label's index (1, 2, 3, ...) as int.
						[uuid]  : label's unique id as string
						[title] : label's title
						[color]	: JSON table containing RGB value
							[r]	: red color as int
							[g]	: green color as int
							[b]	: blue color as int

			POST 30 (Create a card)	:
				[code]		: - 200 success
							  - 400 not connected
							  - 401 failure
				[index] 	: card's index (1, 2, 3, ...) as int.
				[uuid]  	: card's unique id as string

<br>
    3b. Client

        To run the client, you must compile it first by running npm install.
        Next, use npm run to start the client. Below are the request sent to
        the server.

        Command: Authentication
            POST 10 (Login) :
                [email]    : client's email
                [password] : client's password

            POST 11 (Register) :
                [email]    : client's email
                [password] : client's password

            POST 12 (Logout) :
                [token]    : client's token as string


        Command: Lists
            GET 20 (Get all lists) :
                [token]    : client's token

            POST 20 (Create a list) :
                [token]    : client's token
                [title]    : list's title

            GET 21 (Get list's content) :
                [token]    : client's token
                [uuid]	   : list's unique id

		Command: Cards
			GET 30 (Get a card's detail) :
				[token]		: client's token
				[parent]	: parent (list)'s unique id
				[uuid]		: card's unique id

			POST 30 (Create a card)	:
				[token]		: client's token
				[parent]	: parent (list)'s unique id
				[title]		: card's title
				[desc]		: card's description (not necessary)
				[sdate]		: card's start date (not necessary)
				[ddate]		: card's due date (not necessary)
