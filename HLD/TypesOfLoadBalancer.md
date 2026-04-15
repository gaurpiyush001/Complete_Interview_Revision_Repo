Great question! Load balancers are essential in scalable system design, and knowing the **types of load balancers** — along with examples like **Nginx, HAProxy, AWS ELB** — is a solid thing to have in your interview toolkit.

---

## 🚦 **Types of Load Balancers (With Examples)**

### 1. **Layer 4 Load Balancer (Transport Layer)**
- Operates at the **TCP/UDP** level (OSI Layer 4).
- Routes traffic based on IP address and port number.
- Faster, but less intelligent than L7.

🔧 **Examples**:
- **HAProxy (Layer 4 mode)**
- **AWS Network Load Balancer (NLB)**
- **NGINX (with stream module)**

🔹**Use Case**: Load balancing database connections, or WebSockets.

---

### 2. **Layer 7 Load Balancer (Application Layer)**
- Operates at **HTTP/HTTPS layer** (OSI Layer 7).
- Can inspect headers, cookies, URL paths — smart routing.
- Slower than L4 but more flexible.

🔧 **Examples**:
- **NGINX**
- **HAProxy (HTTP mode)**
- **AWS Application Load Balancer (ALB)**
- **Traefik, Envoy**

🔹**Use Case**: Routing traffic based on `/api/` vs `/admin/`, A/B testing, authentication, etc.

---

### 3. **Hardware Load Balancer**
- Physical device used in data centers (less common now).
- Expensive, very fast.

🔧 **Examples**:
- **F5 BIG-IP**
- **Cisco ACE**

🔹**Use Case**: High-performance enterprise setups, legacy systems.

---

### 4. **DNS Load Balancing**
- Distributes traffic by rotating IPs at the DNS level.
- No real-time health checks or failover.

🔧 **Examples**:
- **Route53 DNS Round Robin**
- **Cloudflare DNS Load Balancer**

🔹**Use Case**: Geo-distributed systems, CDN fallback.

---

### 5. **Global Load Balancer / Anycast**
- Routes users to the **nearest server** globally based on latency/location.
- Uses **Anycast IPs** (same IP advertised from multiple locations).

🔧 **Examples**:
- **Cloudflare**
- **Google Cloud Load Balancing**
- **Akamai / Fastly (Edge)**

🔹**Use Case**: CDN, global apps, high availability across continents.

---

## ✅ Common Interview Bonus: What to say

> "In projects I’ve worked on, I’ve mostly used **Layer 7 load balancing via Nginx** for routing traffic between microservices. I understand that **L4 is better for performance**-sensitive workloads like DB or WebSockets, while **L7 gives more control** over HTTP request routing. I'm also familiar with using **AWS ALB and NLB** for scalable cloud-native deployments, and how DNS-level routing can support geo-redundancy."

---

Let me know if you want to see **load balancing algorithms** next — like round-robin, least connections, consistent hashing, etc.