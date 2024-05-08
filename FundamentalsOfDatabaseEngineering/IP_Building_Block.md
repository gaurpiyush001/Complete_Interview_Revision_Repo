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
- Most networks consists of host and a default Gateway, bcz if any host need to send smoething out of the subnet they need to talk to thier gateway
- When host A want to talk to B directly if both are in same subnet, they can do
- Otherqise A sends it to someone who might know, where B is places -->THE GATEWAY DOES THAT
- The GATEWAY has an IP Addreess and each host should know its GATEWAY