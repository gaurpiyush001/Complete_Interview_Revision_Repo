# HTTP Request

METHOD | PATH(url have a limit generally on each server) | PROTOCOL
      HEADERS
       BODY

# HEADERS MEIN HOST KYU zaruri hota hai ?
- beacuse at 1 IP Address, there can be more than One website hosted
- So if you actually have ten domains, that all point to the same IP Address, then by sending HOST in headers identifies that this domain is in which folder, containing in the same machine

## HTTP Response

PROTOCOL | CODE | CODE TEXT
      HEADERS
        BODY

- `*MAJOR DIFFERENCE BETWEEN HTTP1.1 AND HTTP2 IS THAT in HTTP1.1 there is status code as well its description*`
- HTTP is built on top of TCP, so in HTTP you gonna open a TCP Connection 
- So do the three way handshake
- After that you gonna send a GET/ request and get back as response


## In HTTPS, 
-  to secure HTTP connection, we gonna do a TLS handshake first, just after the TCP
- After then both client & server, agrees on a Assymetric Key
- so after this we send ecryptes GET/ request and Encrypted POST/ request

## HTTP1.0 - NEW TCP CONNECTION WITH EACH REQUEST, which SLOWS down, NO MULTI-HOMED WEBSITES(as HOST Headers are optional - so one IP address cannot be mapped by multiple domain names)
- First time you want to send a request, you open a connection (brand new connection)
- send your GET request, then server process
- and the moment you get the reponse you close that connection
- beCAUSE http was stateless, I dont care about the connection dont leave it open, in early 90's where actually keping a TCP connection live actually consumes a lot of CPU (memory effectively in the file descariptor and we have limited RAM, so cant afford keepig alive a TCP connection)
- MAJOR PROBLEM is here we are CLOSING THE CONNECTION EVERYTIME, just to save memory


## HTTP1.1
 - PERSISTED TCP CONNECTION between multiple request(KEEP CONNECTION ALIVE)
 - Low latency & Low CPU Storage
 - Streaming with chunked transfer
 - Pipelining (Disabled by default), this technique is taken from CPU, as we can execute other processes , meanwhile while we are doing another task (Simple meaning of pipelining means that client can send all the three request together, and server can process all the request at the same time) - in pipelining we need to maintain the order of returning the reponse in which the request were coming to server - so we need to block the response if our first request is yet yo be processed
 - this http1.1 pipelining was discountuned bcz of blocking of response
 - multi-homes website
