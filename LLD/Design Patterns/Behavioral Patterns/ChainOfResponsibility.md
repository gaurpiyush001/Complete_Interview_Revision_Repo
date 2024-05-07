# CHAIN OF RESPONSIBILITY ****
- It is a behavioral design pattern that lets you pass requests along a chain of handlers. Upon receiving a request, each handler decides either to process the request or to pass it to the next handler in the chainin the chain


## PROBLEM
- Online ordering system, you want to restrict access to the system so only authenticated users can create orders. Also users who have administrative permisiions must have full access to all orders

- After a bit planning, you realized that these checks must be performed sequentially. The application can attempt to authenticate a user to the systemwhenever it recieves a request that contains the user creds. However if those creds are not correct and authentication fails, there is no reason to procees with other checks



During the next few months, you implmeneted several more of those sequential checks - \
- Its unsafe to pass raw data straight top the ordering system, so you added extra validation setup to sanitize the data in a request.
- Later, noticed system is vulnerable to bruteforce password cracking, To negate this, you promptly added a check that filters repeated failed request coming from same IP address
- speed up the system by returning cached results on repeated requests containing same data.Hence, you added check which lets the request pass through to the system only if there's no suitable cached response.
- The code of the checks, which had already looked like a mess, became MORE MESSY and MORE BLOATED as you added each new feature. CHANGING ONE CHECK SOMETIMES AFFECTED THE OTHERS.
- WORST OF ALL, when you tried reuse the checks to PROTECT other components of the system, you had to duplicate some of the code since those components required some of the checks, but not all of them.
- SO THE SYSTEM BECOME HARD TO MAINTAIN, unil one day you decide to refactor the whole thing.


## --==================SOLUTION===================---

- COR relies on transforming particular behaviors into stand-alone objects called HANDLERS, 
- IN our case each check should be extracted to its own class with a single method that performs the check, the request along with its data is passed to this method as an argument
- The pattern suggests that you link these handlers into a chain. Each linked handler has a field for storing a reference to the next handler in the chain, handlers pass the request further along the chainREQUEST TRAVELS ALONG THE CHAIN UNTIL ALL HANDLERS HAVE HAD A CHANCE TO PROCESS IT.

- BEST THING IN THIS IS - A HANDLER CAN DECIDE NOT TO PASS THE REQUEST FURTHER DOWN THEW CHAIN AND EFFECTIVELY STOP ANY FURTHER PROCESSING

- A Handler processes the recieved request and then decide to whether to pass the request further down the chain.
- It is crucial that all handlers classes implement same interface, Each concrete handler should only care about the following one having execute method, THIS WATY WE CAN COMPOSE CHAINS AT RUNTIME, USING VARIOPUS HANDLERS WITHOUT COUPLING YOUR CODE TO THIER CONCRETE CLASS 


## APPLICABILITY ======================

- Use the COR pattern when your program is expected to process different kinds of request in various ways, but the exact types of requests and their sequences are unknown beforehand
- The pattern lets you link several handlers into one chain and upon recieving a request, "ASK EACH HANDLER WHETHER IT CAN PROCESS IT"
- use this pattern to chai handlers in any order you want
- USE COR pattern when the set of handlers and their order are supposed to cahnge at runtime
- When sender only has sent the requiest, and we dont know which recewiver will fullfil its request


## ======NOTE====== 
- The client may either assemble chains on its own or receive pre-built chains from other objects. In the latter case, you must implement some factory classes to build chains according to the configuration or environment settings.
- The client may trigger any handler in the chain, not just the first one. The request will be passed along the chain until some handler refuses to pass it further or until it reaches the end of the chain.
 
- Due to the dynamic nature of the chain, the client should be ready to handle the following scenarios: 
    - The chain may consist of a single link.
    - Some requests may not reach the end of the chain.
    - Others may reach the end of the chain unhandled.

## CONS - Some Requests may end up unhandled


- cases where COR pattern should be used 
    - ATM / Vending Machine
    - Design Logger
    - 