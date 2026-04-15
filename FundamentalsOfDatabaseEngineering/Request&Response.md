# REQUEST RESPONSE MODEL

- Client sends a request(client really need to define, what a request is ?) 
- backend needs to uderstand what a request is.
- server parses the request(where does a particular request begins and where is it end ?)
- server processes the request
- NOTE -> parsing and understanding the request, and then actually executing the request -> they are all different things
- for example -> if you recieve a GET request, KNOWING THAT THIS IS A GET REQUEST IS ONE THING || EXECUTING THE GET REQUEST TO FETCH AN API IS ANOTHER THING(these are the processing aspect of the request)
- Server sends a response back to the client
- CLIENT PARSES the RESPONSE AND CONSUME

## WHERE DOES SERIALIZATION / DE-SERIALIZATION COMES INTO PLAY (if i have JSON as a payload or XML as a Payload)?
- this comes into picture in processign the request(when server processes the request), to deserialize means to convert whatever this content is coming to something what can i understand from my server side progaramming language
- COST TO DE-SERIALIZATION - >> (why people moved from SOAP XML to JSON REST), expense of parsing XML is way higher than JSON

## ANATOMY OF A REQUEST / RESPONSE
- A request structure is defined by both client and server(and they have to agree on the protocol being used).
- exmaple of request -:
- GET /path HTTP/1.1
- Headers
- <CLRF>
- BODY

- request has a boundary
- Defined by the protocol(where it starts and where it end) and message format

## Building an Upload Image Service with Request Response
- Simplest way - (Send LARGE REQUEST WITH THE IMAGE)- here there is also limitation to size of request
- Chunk Image with unique ID and send a request per chunk (resumable), then server wil reassemble those chunks


## REQUEST REPONSE MODEL - PROBLEMS
## areas where does'nt work everywhere
- Notification Service (here client top make a request, but in this case the backend has the knowledge but the client does'nt)
- Chatting Applicatin (Pollng can cause congest our network by spamming of empty request)
-  Very Long running requests


client finished writing this request 
writing the request also takes time


server eventually recieves ths request and understood it
then request is processed 
after that server sends the reponse