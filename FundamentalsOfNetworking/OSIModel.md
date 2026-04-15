# OSI MODEL

## Why do we need a communication model ?
1. Goal is to build an agnostic application(Agnostic applications are often favored for their flexibility and portability. They can adapt to different environments without requiring extensive changes or redevelopment)
    -  without a standard model, every application need to have the knowledge of underlying network medium , in which it needs to communicate
    -   without a standard, and we want to build a networking application, then WE CANNOT DO THIS, because my SERVER HAS NO IDEA HOW TO TALK/TRANSMIT data to your client(how a machine is supposed to transform those bits into a usefull message), SO THERE MUST BE A PROTOCOL, which understand how to make use of these transfered bits to have sense
    -   Imagine if you have to author different version of your apps so that it works indifferent mediums like wifi, ethernet, fibre(THIS WILL BE A DISASTER🤯)
2. without a standard model, upgrading network equipments becomes difficult
3. Docoupled Innovation, this means each layer we conduct specific innovatino without affecting the rest of models


# WHAT IS OSI MODEL ???
### layer 7 and layer 4 are most important for a backend engineer
- 7 layers each describe a specific networking component
- layer 7 - Application - HTTP/FTP/gRPC(HTTP does have a sessino layer as its stateles protocol,. While TCP is a statefull protocol)
- layer 6 - Presentation - Encoding, Encrypting, Serializing(Ever send a json through AXIO/FETCH, the json need to be serialized odwn to a string, happens in layer 6)
- layer 5 - Session - Connection establishment by opening session channels for communication,(at this layer state effectively sets place at client and server) TLS( Transport Layer Security, successor of old SSL(Secure Sockets Layer) protocol - ensures the privacy and integrity of data exchanged between two communicating applications)
- layer 4 - Transport - UCP/TCP(here we have visibility to ports)- here we end SEGEMENTS in TCP, or In UDP we sent Datagram
- layer 3 - Network - IP - its a packet that destined to an IP(here we dont know what ports are, only we know is IP Adressess) -Here we Send PACKETS
- layer 2 - Data Link Layer - We send FRAMES in layer 2 
- layer 1 - Physical - medium/communication of transportation - electric signals, fiber or radio waves


# THE OSI LAYERS - AN EXAMPLE ( SENDER )
- Exaple sending a POST request t an HTTPS webpage
- layer 7 - Application
    1. POST request with JSON data to HTTPS Server
- Layer 6 - Presentation
    1. This layer takes your JSON object and Serialize JSON to flat byte strings(bcz objec is meaning full in your language only)
- Layer 5 - Session
    1. Request to establish TCP connection/TLS(session layer se pehle request jaati hai to establish a connection with reciever/or the other party, and to that other poarty our request traverse up till its session layer and gets back to notify to sender, yes connection established)
    2. The acknowledgment of successful establishment of this connection is exchanged at the Transport Layer through the SYN, SYN-ACK, and ACK segments.
- Layer 4 - Transpot 
    1. Sends SYN request target port 443(a step in the process of establishing a TCP connection(secure connection to a server) using the TCP three-way handshake, specifically targeting port 443, which is the standard port for HTTPS connections (HTTP over TLS/SSL).)
    2. what is SYN request - SYN (short for "synchronize") is one of the flags used in the TCP (Transmission Control Protocol) header. When initiating a connection, the client sends a TCP segment with the SYN flag set.
- Layer 3 - Network (Till now our JSON body does'nt reached the other party)
    1. SYN is placed on IP packets and adds the source/dest IP Addresses(For knowing the IP addresses we need to do a DNS)
- Layer 2 - Data Link
    1. Each packet goes into a single frame and adds the source/dest MAC Addresses
- Layer 1- Physical
    1. Each frame becomes string of bits which converted into either a radio signal (wifi), electric singal(ethernet)

# THE OSI LAYERS - AN EXAMPLE ( RECIEVER )
- Receiver computer recieves the POST request the other way around
- Layer 1 - Physical
    1. Radio, electric or light is recived and the converted into digital digits(des'nt matter your server might be on fiber, but your network sending is from wifi==SEE THE BEAUTY(I send from wifi and you can recieve it through fiber🔥🔥🔥))
- Layer 2 - Data link
    1. The bits from layer 2 are assembled into frames
- Layer 3 - Network
    1. The frames from layer 2 are assembled into IP Packets
- Layer 4 - Transport 
    1. The IP packets from layer 3 are assembled into TCP segments
    2. Deals with congestion control/flow control/retransmission in case of TCP
    3. If segment is SYN(if only a connection request segment, no point to go down), we dont need to go further into more layers as we are still procesing the connection request
- Layer 5 - session - 
    1. connection session is established
- layer 6 - Presentation layer - 
    1. deserialize flat byte strings to JSON for the app to consume(this desrialization is completely different as that done on other parties end, ex- we can serialize into JS and deserialize into python, serialize into Csharp and deserialize into GO)  
- layer 7 - application layer 
    1. understands the JSON post request and a request recieve evetn is triggered(an event to process that request)

## what are subnets
### Imagine a big city as a computer network, and within that city,     there are different neighborhoods. Each neighborhood has its own unique characteristics and boundaries.
### Similarly, in a computer network, a subnet is a smaller section of the network that has its own specific range of addresses. Devices within the same subnet can communicate directly with each other without needing to go through a router, just like people in the same neighborhood can easily talk to each other without traveling far.
### Subnets help organize and manage large networks by dividing them into smaller, more manageable parts, making communication more efficient and secure.
### SWITCH(LAYER 2 DEVICE) connects a SUBNET Together, which prevents data to be sent unecessarily to different network, SWITCH understands where to send that data based on the MAC ADDRESS itself, (SO FOR SWITCH, data only traverse till layer 2 to identify MAC ADDRESS)

## ROUTER(LAYER 3 device) - bcz it needs IP addresses to route our data to other end

## PROXY(Layer 4 device) 
## FIREWALL(Layer 4 device)
### firewall blocks certian APPLICATIONS from sending data or BLOCKS certian unwanted packets to come through your network, IN ORDER TO DO THAT - IT NEEDS TO LOOK AT THE IP ADRESSES(layer 3), AS WELL AS it needs to LOOK at the PORTS(layer 4) - THOSE FIREWALL THAT ONLY LOOK UP TILL LAYER 4, they are called TRANSPARENT FIREWALL

## NOTE --## EVERYTHING UP TO LAYER 4(TRANSPORT) IS AVAILABEL TO EVERYONE, EVERYONE CAN READ YOUR PORT/IP ADRESSESS, that's why its puclic NEVER ENCRYPTED,
- If you want to go to up till layer 7 application, than you need to stop the session and first decrypt it, and to decrypt you need to serve the certificate of the server (which mostly we dont have!!)
- we can rewrite the packet at layer 4, means change the packet destinatin IP based on the PORT(so similar with load balancing)
## VPN is actually a LAYER 3(NETWORK) protocol, whcih just takes that request IP and put it in another IP


## LOAD BALANCER & CDN ( LAYER 7 ) - (means they decrypt it everything you send in request, analyze it and cache it and then they SEND the request further), 
### if you want to balance load based on path of URL, and directing request this particular server, IF YOU WANT TO DO THAT, then that SLASH URL is actually a APPLICATION LAYER CONCEPT, which is generally ENCRYPTED
### hence LOAB BALANCER OR CDN go all the way up, hence they are way slower then router or Firewall, because for further sending the request to backend we need to maintain again complete new session between session of load balancer and your next target(may be backend server)

## REVERSE PROXY AND REGULAR PROXY
### So, in summary, while a regular proxy hides your identity when accessing the internet, a reverse proxy hides the server's identity from users. 
### Think of a regular proxy as a middleman who helps you access the internet anonymously. You tell the proxy what website you want to visit, and it fetches the content for you, hiding your identity. In contrast, a reverse proxy acts on behalf of the server, receiving requests from users and fetching content from the server.