## Transport layer security (TLS) basic fundamental to encrypt any communication between 2 parties,
- We have to build a standard for encryption because we can't send just IP packets with data that is plain text
- we can build TLS on top any protocol, anything that comes from layer 7 down to below layers
- It is a layer 4(transport layer)protocol
 
 
- So here we open a connection and we do a handshake first and the goal of a handshake is to share a symmetric key,(means share a encryption key) (same key should exist on the client and the server) 
- once we get these keys we will use them to encrypt our GET request on the server.
- HOW CAN WE GET THE SAME KEY at both ends?  AS IN THE SYMMETRIC ENCRYPTION ALGORITHM, the same key encrypts and the same key decrypts
- server will get the encrypted data and will decrypt with the symmetric key, ``**NO BODY IN THE MIDDLE SHOULD HAVE THIS KEY**`` !!
- SYMMETRIC ALGOs(they are much faster than assymetrric algo's)
 
 
## HOW DO WE ACTUALLY EXCHANGE THAT KEY ?
- we encrypt with symmetric key algo's(uses the same key to descrypt and encypt the data)
- Symmetric key algo are way faster than assymetric algo's as Symmetric key algos uses XOR and the later uses exponential stuff
- PROBLEM WITH SYMMETRIC KEY is - you need to share the key across client and server and we cannot just send the key through open network bcz anyone can grab it
- Key exchange uses Asymmetric Key (PKI)
- GOAL OF TLS - Authenticate the server, in order to authenticate server send back a certificate, and certificate relies on PKI(public key infrastructure which are like Asymmetric key algo's)
- there are two algorithms one is to exchange the key and other is for actual encryption which is suppose to be symmetric (bcz its faster)
- server's RSA Public Key and RSA Private key are used for sharing of symmetric key across client and server `*NOTE IMPORTANT*` 

## `**===IMPORTANT=====**`
- TLS - a general purpose protocol that can secure any application-layer protocol, not just HTTP. For example, it can secure email (SMTP), file transfers (FTPS), and more
- HTTPS - Specifically designed to secure HTTP, which is the protocol used for transfering web pages on the internet.