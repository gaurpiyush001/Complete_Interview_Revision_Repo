# GRPC -> Google Remote Procedureal Calls, Built on top of HTTP2.0 and takes complete advantage of HTTP2 to give various features like 
- Bi-directional streaming
- Uni-directional streamin
- Request/response

## this protocol was very attractive because one protocol can give you anything you need
## supports many languages

### Client server communication have so many protocols 
- SOAP, REST, GraphQL
- SSE, WebSockets
- Raw TCP

## SO why do we need another protocol ?
- The PROBLEM WITH CLIENT LIBRARIES
    - Every time you build a protocol, the client and the server has to agree on their protocol language(the rules that we talked about to the properties of the protocol)
    - Any communication the protocol needs a client library for the language of choice like SOAP library, HTTP Client Library
    - Hard to maintain and patch client libraries

## Why gRPC was invented ?
    - Client Library:  One library for popular languages
    -In gRPC, building specific stubs refers to generating client-side code from a .proto file that allows your application to call remote procedures on a server. The process involves: Define Service: Write your service and message definitions in a .proto file.
    - In gRPC we built a protocol buffer(definition file and then that, then you build stubs in your own language)
    - So the library here is always built for you own language.
    - Protocol - HTTP/2 (Hidden implementation)
    - Message Format : Protocol buffers as format

## gRPC Modes
- Unary RPC (simple request/repsonse)
- Server streaming RPC (if i am downloading a large file, you send a requst and the server will stream content for you)
- Client streaming RPC
- Bidirectional streaming RPC


- syntax = "proto3" (lastes protocol buffer version)
- if we are building something with gRPC or Protocol buffers then we need to build a proto file A SCHEMA


