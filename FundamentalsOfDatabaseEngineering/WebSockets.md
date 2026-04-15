# WebSockets is a Bi-Directional communications designed for web, built on top of HTTP (LAYER 7 - APPLICATION LAYER)
## TCP is also a Bi-Directional protocol, why dont we just expose it to the WEB ??
- TCP does so much thing, with TCP you can connect with your SSH Server, SMTP Server and so many services so very dangerous
- Directly exposing TCP can make the system more vulnerable to various attacks such as port scanning, man-in-the-middle attacks, and other security exploits. Web protocols, on the other hand, are designed with various security measures like SSL/TLS encryption (for HTTPS) to protect against these threats.
-  the web’s protective HTTP umbrella prevents such exposure
- Only when client understand how to upgrade the HTTP connection to a web socket, we going to give access to underlying TCP connection
- HTTP 1.0 -> open a connection send a request, after recieving its response, we close it
- HTTP 1.1 -> make the coneection persistent after openingn  a connection we can send as many request as we want and thne close it.
- As we kept the connection alive, this opened up an opportunity for us to WEB SOCKETS, (We open a connection then we make a request for WEB SOCKET HANDSHAKE)
- Protocol -> `* ws:// or wss://*`
- for WebSocket handshake request,  we pass an UPGRADE HEADER (FOR UPGRADING HTTP1.1 TO WEBSOCKETS)

## WEB SOCKETS USE CASES
- chatting
- live feed
- multiplayer gaming

## web sockets pros
- full duplex(a channel can simultaneosly receive/send messages) (no polling)
- HTTP Compatible 
- Firewall friendly (as bcz http compaible, while tcp is not firewall freindly)

## CONS
- Proxying is tricky
- need to send ping pong to keep the connection alice
- statefull, difficult to horixontal scale