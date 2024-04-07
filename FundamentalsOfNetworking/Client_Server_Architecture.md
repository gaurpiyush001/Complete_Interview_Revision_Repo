# This was a revolution in networking

## This resolves the question - How can I put my client and my server at different location, where different code pieces can live somewhere else and I need to call certain peice to execute somewhere else.

## Client server architecture
### Machines are expensive and applications are complex
### Seperate the application into 2 components
### Expensive worklod can be done on the server,(which takes a lot of RAM, CPU)
### Clients(caller) call servers to perform tasks
### Remote Procedure call(RPC) was born, -> lets make a call, but a remote call(Remote Procedure Call (RPC) is a way for one computer program to ask another program running on a remote computer to perform a task.)


## Client-Server Arch. Benefits -

### servers have beefy hardware
### clients have commodity hardware
### clients can still perform lightwieght task, now clients does not have that complex application logic that they used to have
### clients no longer require dependicies
### However, we need a communication model, (how should i send data from one machine to another , there should be some rules/principldes)
