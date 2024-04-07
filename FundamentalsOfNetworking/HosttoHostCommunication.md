# Host to Host Communication

- I need to send message from Host A to Host B
- Usually a request to do something on Host B(RPC), specifying the MAC Address(GLOBALLY UNIQUE ADDRESSES)
- Everyone in the network will 'GET' the message but ONLY B will accept it(this is like a broadcast message, we need to go UP TILL layer 2 to identify the MAC Address, and compare) - [THIS IS VERY BAD HABIT OF BROADCASTING IT TO EVERYONE]
- Each host network card has a unique Media Access Control Address(MAC)
- eg-: 00:00:5e:00:53:af

## We need a way to eliminate the need to send it to everyone
- the address need to get better(MAC are not so accurate, they dont have information to tell me where to send it and where to not send)
- WE NEED ROUTABILITY ## NOTE ## - so we absolutely need IP ADDRESSES      
    1. THIS HELPS US TO REDUCE THE NUMBER OF MACHINE THAT WE NEED TO SCAN OVER THE NETWORK, to identify our suitable machine which we need to send that message

## IMPORTANT THINGS TO KNOW ABOUT IP ADRESSESS
- The IP Address is built in TWO PARTS
- FIRST part identifies the NETWORK, and the second part is HOST
- we use the NETWORK PORTION to ELIMINATE many networks ( SO I ONLY SEND THIS IP PACKET to the network that is destined, then scanning every machine in that network with MAC ADDRESS(host) )
- The HOST PART IS USED TO IDENTIFY THE host
- STILL NEEDS MAC ADDRESS!!!(to identify HOST)
- IN ADDITION TO THIS, WE ALSO NEED PORT, AS ONCE WE GET FRAME/PACKET in our destined machine, there are many application running on our destined machine, so we need to identify our application with PORT,  https - port 80, DNS - port 53, SSH - 22 port 