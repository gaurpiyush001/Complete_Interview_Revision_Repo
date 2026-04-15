# USER DATAGRAM PROTOCOL
- reason its called - user datagram is because there is a message that the user set and that message is responsible to fit exactly into that segment(UDP Segment)
- TCP is great for reliability, but UDP is required for people who dont like necessarily the reliability of TCP
- UDP sits right on top the internet protocol
- layer 4 protocol
- Ability to address processes in a host using ports(as a particular host has many applications running, and we can data to same IP address, multiple request, for multiple apps running in same host, and uniquely identify using HOST)
- simple protocol to send and recieve data 
- stateless protocol prior communication not required 
- 8 byte header Datagram

## UDP use cases - used in cases if we wanna send a lot of huge data that you dont really care about consistency
- Video streaming
- DNS
- VPN
- WebRTC

- In UDP, sender multiplxes all its app into UDP(source IP and each port for sender application)
- Receiver demultiplex UDP datagrams to each app(destination IP , with target Host port to idetify application runnning on that Host IP)

## UDP Datagram Analogy
- UDP Header is 8 bytes only (IPv4)
- Datagram slides into an IP Packet as "data"
- Port are 16 bit (0 to 65535)2^16 


## UDP Pros
- Simple protocol
- Header size is small so datagrams are small
- Uses less bandwith 
- Stateless
- Consumes less memory ( no state stored in the server/client )
- Low latency - no handshake, order, retransmission or guaranteed delivery


## UDP Cons
- No Acknowledgement
- No guarantee delivery
- Connection-less : anyone can send data without prior knowledge
- No flow control
- No congestion control
- No ordered packets
- Security - can be easily spoofedb     


