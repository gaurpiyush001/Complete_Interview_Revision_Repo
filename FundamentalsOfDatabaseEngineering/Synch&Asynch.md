# Synchronous I/O
- Caller sends a request and blocks
- Ca;;er cannot execute any code meanwhile
- Receiver responds, Caller unblocks and the operating system can put your process back to execute the rest of your code
- Caller and Recever are in "sync"

## Example of an OS synch I/O
- Program asks OS to read from disk
- Program main thread is taken off of the CPU
- Read completes, program can resume execution


# Asynchronous I/O
- Caller sends a request
- Caller can work until it gets a response
- Caller either
    - checks if the response is ready
    - receiver calls back when its done
    - spins up a ew thread that blocks
- caller and receiver are not necessary in sync


## Asynchronous backend processing means - backend may not process that request immediately, rather it puts it in a execution queue as it might be precessing some other request
## Asynchronous commits in Database systems (postgres) - we return success, before even commiting to our main memory (DISK)
## Asynchronous Replication -> replication is the idea of having primary writer in the database, and set of secondary worker databases (which are used for read) || synch replication mtlb pehle secondary workers pr saarey updation fir last mein primary pr hoga then response will be sent. --- But we can do async commit at the cost of consistency as first doing commit in primary and returning the reponse to client and then subsequently write to other secondary databases  
