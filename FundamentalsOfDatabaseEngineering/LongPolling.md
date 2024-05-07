# LONG POLLING - nice trick to avoid the chattiness of long polling !!

## IDEA -
- Request is taking long time, I will check with you later, But talk to only when its ready!
- So you will make a trick, as you will make a poll request. But the server just "DOES NOT RESPOND". Doesn't write anything to the socket
- Instead of saying by the server immediately, hey its not ready. It just waits there.
- Client is asynchronously doing it task, but the server knows that job is not ready the response is not ready, Server will just say i will come back later. 
- First request get the JobID, then the next request to do long polling will be blocked, server will not respond


## CASES WHERE REQUEST/RESPONSE & short POLLING ISN'T IDEAL
- When a request takes a long time to process
- The backend want to sends notification
- Short polling is good, but its chatty 
- MEET LONG POLLING (kafka uses it, for clients to consume a topic in kafka, consumer will do a long polling request and it will then just the kafka will not resopnd immediately until there is an entry in the topic, then it wil respond back)


## what is LONG POLLING
- Client sends a request
- Server responds immediately with a handle 
- server conmtinues to process the request
- client uses that handle to ckeck for status,(In kafka consumer subscribes to a topic and subscription happen through long polling, IF THERE ARE NOT any messages in topics, then kafka blocks. so we did not waste bandwidth by sending multiple pull requests, moment we have messages, kafka writes back to the client)
- SERVER DOES NOT REPLY UNTIL it has the response 
- so we got a handle we can disconnect and we are less chatty

## LONG POLLING PROS AND CONS
## PROS
    - Less chatty and backend freindly
    - client can disconnect thats a beauty
## CONS
    - Not real time