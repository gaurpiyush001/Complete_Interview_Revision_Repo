# PUSH - I want as soon as possible - We call it PUSH because the result PUSHED immediately as the moment the event is generated

## Request/Response isn't always ideal
- Client wants real time notification from backend
    - A user just logged in
    - A message is just received
- Push model is good for certain cases (ther server knows something is going to push it to the client - this is sometimes good or sometimes bad as lot of clients cannot handle that load)


# WHAT IS PUSH ?
- Client connects to a server
- Server sends data to the client
- Client doesn't have to request anything (There is only thing which is necessary is there should be a connection establishment, almost its like undirectional stream from server side)
- Protocol must be bidirectional(will be much better in this scenario)
- Used by RabbitMQ

## PUSH PROS
- ITS ACT LIKE REAL TIME MESSAGING(the moment things happen we got to push it to all connected clients whos connectinos are established, we dont wait)
## PUSH CONS
- Clients must be online(client should be connected to the server)
- Clients might not be able to handle(what if server is pushing tons of notification to the client)
- Requires a bidirectional protocol
- Polling is preferred for light clients(as client itself made the request when they are capable to handle the load)
