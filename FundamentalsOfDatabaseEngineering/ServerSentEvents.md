# SERVER SENT EVENTS, 
## Its a pure HTTP thing, does not work on other protocols
## One Request, a very very long Response - means you send an HTTP request but you keet getting data, it just never ends


# What is server Sent Events ??
- A response has start and end
- Client sends a request
- Server sends logical events as part of response
- Server never writes the end of the response, but server sends mini events from the stream that is used by the server send events object in browser that understand these returned small events from server
- for ex- just someone logged in, you can respond with an event in the long response just partt of it and the client just parses this segment, oh somone just actually logged in
- It is still a request but an unending response
-  Client parses the streams data looking for these events 