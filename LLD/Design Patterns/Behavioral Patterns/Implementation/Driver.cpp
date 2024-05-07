// ===================== NOTE ===========
// The client may either assemble chains on its own or receive pre-built chains from other objects. In the latter case, you must implement some factory classes to build chains according to the configuration or environment settings.
 
//  The client may trigger any handler in the chain, not just the first one. The request will be passed along the chain until some handler refuses to pass it further or until it reaches the end of the chain.
 
//  Due to the dynamic nature of the chain, the client should be ready to handle the following scenarios:
 
//  The chain may consist of a single link.
//  Some requests may not reach the end of the chain.
//  Others may reach the end of the chain unhandled.