# POLLING 
## REQUEST IS TAKING A WHILE, I WILL CHECK WITH YOU LATER!!

## This strategy is used, when request/response isn't ideal
- A request takes long time to process
    - ex -: Upload a youtube video
- The backend want to sends notification
    - A user just logged in
- Polling is a good communication style 


## What is Short Polling ?
- Client sends a request
- Server responds immediately with a handle(unique identifier that correspondse to that request)
- NOTE++ HERE THE BACKEND is free to do, whatever it can do here i can queue/persist this unique handler, and then later execute that request(Backend takes a decision how long we can save this job that has been finished in the backend)
- So request is not executed immediately!!But we can check later for progress
- Server continues to process the request
- Client uses that handle to check for status ---- IMP --- SERVER CONTINUES TO POLL FOR THE STATUS, IS THSI THING READY ? IS THIS THING READY ?, So thats how short polling works, the reason we call short is bcz we immediately going to get the result.
- So idea of making a POLL is a request / response.
- But the whole system is based on the Async Execution with Short Polling.
- MULTIPLE "SHORT" request response as POLLS.

## Short Polling Pros & Cons
## PROS
    - Simple to implement both client wise / server wise
    - Good for long running time taking requests(make it as a polling system, instead of ordinary request repsonse model, make the backend async execution with a response as a handler and let the client short poll for this handle)
    - Client can disconnect
## CONS
    - too chatty, (imagine you scale this up, thousands of people are using your application, one client is making polls thats not bad, but now imagine thousands of people each app is making 10, 20, to 30 polls, frequently -- IT ADDS UP, if you gonna be making lot of request the network be gonna congested)
    - network bandwidth
    - Wasted backend resources
    