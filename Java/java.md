Great! Let’s go over each of these **Core Java & OOP questions** in a **concise and interview-style** manner — clear, to-the-point, but with enough depth to show you understand what you're talking about. 🧠💬

---

### ✅ **1. Difference between HashMap, ConcurrentHashMap, and Hashtable**

| Feature              | HashMap        | Hashtable        | ConcurrentHashMap |
|----------------------|----------------|------------------|-------------------|
| Thread-safe?         | ❌ No           | ✅ Yes (synchronized) | ✅ Yes (segmented locking) |
| Performance          | Fast (no sync) | Slower (locks entire map) | Better under concurrency |
| Null keys/values     | 1 null key, many null values | ❌ No null keys/values | ❌ No null keys |
| Use Case             | Single-threaded | Legacy thread-safe code | Multi-threaded, modern use |

**In interview:**  
> HashMap is not thread-safe and is good for single-threaded use. Hashtable is thread-safe but outdated. ConcurrentHashMap is the preferred choice in concurrent environments due to its segment-based locking for better performance.

---

### ✅ **2. How does Java handle memory management? Explain GC in detail.**

> Java uses an automatic **Garbage Collector (GC)** to manage memory. The memory is split into **Heap (where objects live)** and **Stack (method frames, local variables)**.

**Heap Memory Breakdown:**
- **Young Generation**: New objects (includes Eden and Survivor spaces)
- **Old Generation (Tenured)**: Long-lived objects
- **Metaspace**: Class metadata

**Garbage Collection Process:**
- **Minor GC**: Cleans up young generation
- **Major/Full GC**: Cleans old gen (slower, more expensive)
- Modern collectors: G1, ZGC, Shenandoah, etc.

**In interview:**  
> Java uses automatic garbage collection to free memory by removing unreachable objects. G1GC is commonly used today for balancing throughput and latency.

---

### ✅ **3. Explain `synchronized` keyword. When would you use ReentrantLock?**

- `synchronized` blocks or methods ensure **mutual exclusion** – only one thread can access the critical section at a time.
- It's **easy to use**, but:
  - Can't interrupt a thread waiting for a lock
  - No try-lock support
  - No fairness policy

**ReentrantLock** (from `java.util.concurrent.locks`) is more flexible:
- Allows **tryLock()**, **lockInterruptibly()**
- Supports **fair locking**
- Can unlock in different places

**In interview:**  
> I’d use `synchronized` for simple locking. But in complex scenarios like timed locks, interruptible waiting, or needing lock fairness, I’d go for `ReentrantLock`.

---

### ✅ **4. Java 8: How do Stream, map, flatMap, and collect work?**

- **Stream**: Functional-style operations on collections
- **map()**: Transforms each element  
  > `list.stream().map(x -> x * 2)`
- **flatMap()**: Flattens nested streams  
  > `listOfLists.stream().flatMap(List::stream)`
- **collect()**: Terminal operation to collect result  
  > `list.stream().collect(Collectors.toList())`

**In interview:**  
> Streams enable functional programming in Java 8. `map()` transforms elements, `flatMap()` flattens nested structures, and `collect()` gathers the result into a List, Set, or Map.

---

### ✅ **5. Difference between `final`, `finally`, and `finalize()`**

| Term       | Purpose                              |
|------------|--------------------------------------|
| `final`    | Prevent modification (variable, method, class) |
| `finally`  | Always executes after try-catch      |
| `finalize()` | Called by GC before object is removed (deprecated in recent versions) |

**In interview:**  
> `final` is for immutability or restriction, `finally` ensures clean-up code always runs, and `finalize()` was used for cleanup before GC but is now discouraged in favor of `AutoCloseable`.

---

### ✅ **6. How do you design an immutable class in Java?**

Steps:
1. Make the class `final`
2. Declare fields `private final`
3. No setters
4. Initialize fields via constructor only
5. For mutable fields (e.g., List), return **defensive copies**

**Example:**
```java
public final class Employee {
    private final String name;
    private final int id;

    public Employee(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public String getName() { return name; }
    public int getId() { return id; }
}
```

**In interview:**  
> I’d make the class and its fields final, use constructor injection, avoid setters, and return copies for mutable fields to ensure immutability.



- A thread pool in Java is a group of pre-created threads that execute tasks. It avoids the overhead of creating a new thread for every task and allows better resource management. I’d use Executors.newFixedThreadPool() or ExecutorService from the java.util.concurrent package to manage task execution in a scalable and efficient way.


---

Would you like a one-pager cheat sheet PDF on this topic for quick review before your interview?