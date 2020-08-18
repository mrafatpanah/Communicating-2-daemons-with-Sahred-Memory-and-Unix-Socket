# Two daemons that communicate with Unix Socket

-- (Coded with: C programming language)

this project contains Client and server application and 2 header files:

-- test in Ubuntu OS (Linux)

# Client
    -- run and execute:
        - Step-1: install gcc
            $ sudo apt update
            $ sudo apt install build-essential
            $ sudo apt-get install manpages-dev

        - Step-2: compile with gcc
            $ gcc client.c -o client

        - Step-3: execute client application
            $ ./client

        - Step-4: check the result
            open ClientLog.txt and wait for reading messages from Server

# Server
    -- run and execute:
        - Step-1: compile with gcc
            $ gcc server.c -o server

        - Step-2: execute consumer application
            $ ./server

        - Step-3: check the result
            open ServerLog.txt and wait for showing messages

# Daemon
    -- check process ID to kill if needed:
        ps -ax | grep <process ID>
        kill -9 <process ID>
