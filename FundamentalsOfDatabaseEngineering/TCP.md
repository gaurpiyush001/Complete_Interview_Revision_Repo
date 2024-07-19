# TCP - Transmission Control Protocol(reliable protocol) - Focuses on Reliability , CONGESTION CONTROL, with Congestion Control, with FloW Control, With ReTransmission, With ORDER - GUARANTEE
- Note - if you want to send data, you want to make sure the data arrives, you dont want to deal with the headache of retransmission and flow control and congestion 
- Layer 4 protocol
- Ability to address processes in a host using ports
- "Controls" the tranmission unlike UDP which is a firehose
- Concept of "CONNECTION", - means a session - there is a knowledge between client and the server, this knowledge is a state that is stored on both the server and the client
- Requires HANDSHAKE
- 20 bytes headers Segment
- Stateful


## TCP Use Cases
- Reliable Communication
- Remote Shell
- Database Connections
- Web Communications
- Any Birectional communication - TCP is not a requst/response system, its a birectional communication journey

## TCP Connection - Concept of a connectionmeans we have state/ we have knowledge, we handshake - Once i know you I am gonna save a state/session at layer 5 that idetifies you
- You better be in this list of layer 5, if you send me something in TCP and you claim to be a TCP Segemnt and you dont have a connection with me I am gonna drop you !! So there is no Spoofing
- Connection is a layer 5 (session)
- Connection is an agreement between client and server
- Must create a connection to send data (this is most IMPORTANT security concern of this protocol, and a reason of inducing latency, as now i want to do a whole handshake to send data)
- Connection is identified by 4 properties
    - Source IP-SourcePort
    - DestinationIP-DestinationPort
- All these 4 pairs from layer 4 & 3 are taken, the OS hash it and preserve one hash, and that hash is looked up in a lookup in Operating system, and that matches something called a filedescriptor in the operating system ands the file description contains session effectively the state, **`So thats how you get to know, if there is a connection or not. (We hash it and we lookup)`**

## TCP Connection
- Cannot send data ouside of a connection (we already talked about that how it checks it 2 devices have a connection otherwise throw ICMP message)
- Sometimes called Socket or File Descriptor (it is a layer 5 thing)
- Requires a 3-way TCP Handshake
- Segments are sequenced and ordered (sometime they can be out of order as all segments are shoved into one IP Packets which does not gaurantee ordering)
- Segments are acknowledged
- Lost segments are retransmitted - **` THIS WHAT MAKES TCP RELIABLE`**
-  We can aknowledge multiple segment with one ACK

- 3 way handshake 
    - ->SYN-> (to syncronize sequence members(of both side), in order to establish a connectiyon in bidirectional communication)
    - <-SYN&ACK<- ()
    - ->ACK->
    -  we end up in creating file descriptors in both side
    - when a particular connection is destroyed we eneed to remove that hash , and that particular hash table changes size, this IS A EXPENSIVE OPERATION
    - CPU and memory is the limit when there are o many TCP Connections, CPU CYcles are required to hash 4 pairs
    - memory is used to store that hash in memory

- App1 can send new segement before ack of old segment arrives
- Flow control(how the routers controls to send our data through the route as fast as possibel) and congestion control(how fast our server responds)
- Flow control is a fundamental concept in computer networking that ensures the reliable and efficient transfer of data between a sender and a receiver. Its primary goal is to prevent the sender from overwhelming the receiver with too much data at once, which could lead to buffer overflow, data loss, or degraded performance. Flow control mechanisms manage the rate of data transmission to match the receiver's processing capacity and buffer availability.

## Closing Connection
- App1 wants to close the connection
- App1 sends FIN(I am gonna check there is a session for you first), App2 sends ACK
- App2 sends FIN, App1 sends back ACK(when client sends that ACk to server, that is when the connectino is completely closed, And now the server destroys the FILE DESCRIPTOR)
- NOTE-->> File descriptor for the client which sends FIN, is not destroyed immediate it stays in time weight state to wait for any OLD SEGMENT that have been lost and retransmitted to arrive. 
- **`FOUR WAY HANDSHAKE`**
