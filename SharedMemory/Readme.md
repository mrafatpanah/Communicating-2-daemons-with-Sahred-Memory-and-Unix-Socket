# Two daemons that communicate with Shared Memory

-- (Coded with: C programming language)

this project contains Consumer and publisher application and 2 header files:

-- test in Ubuntu OS (Linux)

# Consumer
    -- run and execute:
        - Step-1: install gcc
            $ sudo apt update
            $ sudo apt install build-essential
            $ sudo apt-get install manpages-dev

        - Step-2: compile with gcc
            $ gcc consumer.c -o consumer

        - Step-3: execute consumer application
            $ ./consumer

        - Step-4: check the result
            open consumer.txt and wait for reading messages from publisher

# Consumer
    -- run and execute:
        - Step-1: compile with gcc
            $ gcc publisher.c -o publisher

        - Step-2: execute consumer application
            $ ./publisher

        - Step-3: check the result
            open publisher.txt and wait for showing messages

# Daemon
    -- check process ID to kill if needed:
        ps -ax | grep <process ID>
        kill -9 <process ID>
