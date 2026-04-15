# Packet belongs to Layer 3, it is a bunch of data with a destination IP address and a Source IP Address

## IP Address
- Layer 3 property
- Can be set automatically or statically
- Network & Host portion
- 4 bytes in IPv4 - 32 bits


## Network vs Host
- a.b.c.d/x (a.b.c.d are integers) x is the network bits and remains are Host
- ex - 192.168.254.0/24
- The first 24 bits (3 bytes) are network the rest 8 are for host
- this means we can have 2^24 networks and each network has 2^8 hosts
- Also called Subnet, is a logical subdivision of an IP network. It allows larger network to be divided into smaller and manageable segments.
- Subnetting is primarily based on dividing the IP Address space into 2 parts - the Network Portion, the Host Portion
- Also called a subnet - a.b.c.d/x


## Subnet Mask
- ex-: 192.168.254.0/24 is also called a subnet
- Subnet must have a Subnet Mask - 255.255.255.0
- Subnet mask is used to determine whether an IP is in same subnet or not
- If its in my subnet, you can use the MAC Address to send/communicate 
- while if its not in same address - we need to talk to someone who knows how to route this (and this is usually called the router or GATEWAY), Thats why you have a gateway IP Adress in every network 

## Default Gateway
- A gateway in networking typically refers to device(like a router) that serves as an entry point to another network. This device is resonsible for routing data ppackets from one network to another.
- Most networks consists of host and a default Gateway, bcz if any host need to send smoething out of the subnet they need to talk to thier gateway
- When host A want to talk to B directly if both are in same subnet, they can do
- Otherqise A sends it to someone who might know, where B is places -->THE GATEWAY DOES THAT
- The GATEWAY has an IP Addreess(or multiple IP Addresses) and each host should know its GATEWAY

- when we send packet between 2 different networks
    - If devices from two different subnet needs to talk , then we send our packet to our Gateway, and after that the connection between gateway and device in another network works as HOST TO HOST communication
    - we send packet destined to another network of the device, But the MAC Address is the router - and here is where EVERY ATTACK IS POSSIBLE HAPPENS(R POISOINING), If someone here pretend to be the router then all the pacekts will go through that router|||
    - The router actually lives in two worlds if its connected to 2 different subnets, it has 2 IP Addresses
    - You need to make sure, your backend applcation and client application to be in same subnety, otherwise it will give delayes in response, as the router will be so congested

## IP Packet 
- The IP Packet has headers and data sections
- IP Packet header is 20 bytes(can go up to 60 bytes if options are enabled)
- Data Section can go up to 65536
- Maximum Tranmission Unit is the frame size, by default an IP pacekt should git into a frame
    - If an IP Packet is not able to fit in a frame , then there are 2 options - :
        - fail message is sent back, as mtu is too small 
        - put the IP packet in one frame with mtu limit, and another remaining part in another frame - and then the HOST Has to understand that this frame is fragemennted and Host needs to assemble that(assembling a fragment is most dangerous thing securit wise)
        - MTU generally reprents the maximum size of an IP packet that can be transmitted over a network segment without fragmentation
        - So it is responsibility of the client to send IP packets, that they know which should fit in all the MTUs that the network will pass through.
- Time to live (How many Hops can this pacekt survive ?)if i go across different internet then only ttl will decrement 
    - why do we have time to live ?  
        - Because the Idea of routing, the packet can go into different routes and they can end up in the situation wheere they into an infinte loop, and you have no idea to chec if you have visited a route previously or not.
        - So to prevent packets from roaming around in internet forever ==> We have TTL
        - Time to Live block value suggest that for example that this packet will live for a hundred route - so assign 100. And everyone of the router/Host that recieves this packet will decrement the TTL value 
        Every IP packet has 8 bit, a single byte that represent a counter  

- Explicit Congestion Notification
    - previously when there was congestion on router to process the packets coming to it, routers generally drops those packets, even does'nt sending any message, So the client need to guess when it doesnt recieve the acknowledgment of packet, when time out happens
    - Above problem of notifying client prior to congestion is resolved by Explecit Congestion Notification - the router when there buffere fills up , I am about to drop it but actually not drop it, ECN set the bit to 1,  Notification sent to client that router experienced congestion 


 
