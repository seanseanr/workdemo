Goal: use C posix library to create UDP gram client sever project.

Detail:

    1. Server.c: listen to the specific IP and PORT and Echo and reply.
    
    2. Client.c: send message to and receive response from server and echo.
    
    3. Build Client
        gcc Client.c -I/usr/lib/gcc/x86_64-linux-gnu/8/include -lm -o Client
        
    4. Build Server
        gcc Server.c -I/usr/lib/gcc/x86_64-linux-gnu/8/include -o Server
        
    5. Video demo the execution of Server& and Client
