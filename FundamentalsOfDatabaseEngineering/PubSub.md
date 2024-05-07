# PUBLIC SUBSCRIBE
## client can publish something to the server and then moves on, and then client can comsume from the server
## This was designed to solve a problem where, lot of services need to talk to each other and createing this MESH Architecture 
## One publisher many readers / we can also have many Publishers as well  


## In Simple request response - 
- 1. we sent a request, 
- 2. we wait
- 3. We get back content

## BUT DOES THAT SCALE, when you have many many SERVERS --
- example for you tube we upload a video, technically to upload a video,\
1. Upload Service
2. Compress Service
3. Format Service
4. Notification Service

- So all this thing is happening in order, then if anything breaks , it will break the entire workflow
- now if we want to integrate new reiever its get messy
5. Copyright Service

## Naive Req/Res PROS and CONS
- PROS
1. Elegant & Simple

- CONS
1. Bad for multiple recievers
2. High Coupling 

## PUB / SUB Model
- let the client upload and once the upload is finished , the client job is done it gets its jobID and that's it
- Once you upload you are done, you dont have to wait for any other services, they will happen in the background
- So in backend architecture, the upload server will upload the raw MP4 videos into a TOPIC(message queue/broker, all the topics live here - TOPICS ARE GROUP OF THINGS THAT SUBSCRIBERS CAN SUBSCRIBE TO)
- So we eleminated high coupling of services, by making an intermediate topics(queues)

## PUB/SUB MODEL 
## PROS
- Scales with multiple receivers
- Great for microservices
- Loose Coupling
- Works while clients not running, once your publish has done you move on

## CONS
- Message delivery issues(Two generals problem - that the consumer or the subscriber actualy got the message, what if a message is recieved twice [THis is a very difficult problem to solve])