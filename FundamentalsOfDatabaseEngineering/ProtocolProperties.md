# What to take into account when designing a protocol ? 

## What is a protocol ?
- A set of rules that allows two parties to communicate, if both parties follow the same rules , then they can communicate.
- A protocol is designed with a set of properties
- TCP, UDP, HTTP, gRPC, FTP

## Protocol Properties
1. Data Format
    - Text Based(plain text, JSON, XML)
    - Binary (protobuf(political buffers), RESP(redis serialization protocol), http2, http3) 
2. Transfer Mode
    - Message Based ( UDP, HTTP ), where a message can have a start and an end. like HTTP where request has a start and end/ response has a start ans an end
    - stream , stream of bytes : there is no start or end ( TCP , WebRTC)
3. Addressing System (where are you going)
    - DNS name(layer 7), IP(layer 3), MAC(this addressing system is used by ARP - Address resolution protocol)
4. Directionality
    - Bidirectional (TCP)
    - Unidirectional (HTTP)
    - Full/Half Duplex
5. State
    - Stateful (TCP, gRPC, apache thrift)
    - Stateless (UDP, HTTP)
6. Routing (how does your protocol works with different gateways and proxies)
    - Proxies, Gateways
7. Flow & Congestion Control
    - TCP (Flow & Congestion)
    - UDP (No Control)
8. Error Management
    - Error Code
    - Retries and timeouts
    