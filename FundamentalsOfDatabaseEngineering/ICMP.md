# ICMP - Internet Control Message Protocol
- lives in layer 3 (means there is only destination and source IP, there is no concept of port at that layer) 
- Designed for informational messages
    - Host unreachable, port unreachable(if we try to reach a port on the server that doesn't eexist it will send a ICMP message back), fragmentation needed
    - Packet expired (infinte loop in routers)
- Uses IP directly
- Ping and Traceroute use it
- Doesn't require listeners or ports to be opnened
- some firewall block ICMP leading to TCP blackhole 
