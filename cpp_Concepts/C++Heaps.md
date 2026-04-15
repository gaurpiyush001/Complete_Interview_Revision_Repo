### **Understanding `priority_queue<T, vector<T>, greater<T>>` Internals in C++**
In C++, the `priority_queue` is implemented as a **heap** (a binary tree stored in an array) using the **`std::make_heap`**, **`std::push_heap`**, and **`std::pop_heap`** functions.

By default, `priority_queue` is a **max-heap**, meaning the largest element has the highest priority. However, we can change this behavior by passing a **custom comparator**.

---

### **1. Default `priority_queue` (Max-Heap)**
```cpp
priority_queue<int>
```
- **Internally**, this is the same as:
  ```cpp
  priority_queue<int, vector<int>, less<int>>
  ```
- Here, `less<int>` ensures that the **largest** element is always at the top.
- **Internally, it uses a `vector<int>` as the underlying data structure** and applies the heap operations.

Example:
```cpp
priority_queue<int> pq;
pq.push(5);
pq.push(10);
pq.push(1);
pq.push(7);
```
**Internally stored as a max-heap:**
```
     10
    /  \
   7    1
  /
 5
```
✔️ Extracting `pq.top()` will always return `10`, and after popping, the heap adjusts.

---

### **2. Min-Heap Using `greater<int>`**
To create a **min-heap**, we use:
```cpp
priority_queue<int, vector<int>, greater<int>>
```
This means:
1. **`vector<int>`** is the underlying data structure.
2. **`greater<int>`** changes the default behavior, so the **smallest** element is given the highest priority.

Example:
```cpp
priority_queue<int, vector<int>, greater<int>> pq;
pq.push(5);
pq.push(10);
pq.push(1);
pq.push(7);
```
**Internally stored as a min-heap:**
```
     1
    /  \
   7    5
  /
10
```
✔️ Now, `pq.top()` will return `1` instead of `10`.

---

### **3. What is `vector<int>` Doing?**
The second parameter, `vector<int>`, specifies the **underlying container** for the heap.
- **By default, the priority queue is backed by a `vector<T>`.**
- This means all elements are stored in a **dynamic array (`std::vector`)** and modified to maintain heap properties.

Other containers like `deque` or `list` are **not** used because:
- **`vector` is cache-friendly and provides O(1) access time for top()**.
- It supports **heap operations efficiently** (`push_heap`, `pop_heap`).

---

### **4. Why Do We Pass `greater<int>`?**
The third parameter in `priority_queue<int, vector<int>, greater<int>>` is a **function object (functor)** that **defines how two elements should be compared**.

- `less<int>` → Default max-heap behavior.
- `greater<int>` → Min-heap behavior.

Since `greater<int>` defines:
```cpp
bool operator()(const int &a, const int &b) { return a > b; }
```
- It swaps the heap behavior, making the **smallest** element the top priority.

---

### **5. Custom Comparator (Instead of `greater<int>`)**
We can also use **our own custom comparator** instead of `greater<int>`.

#### **Using a Lambda Function**
```cpp
auto cmp = [](int a, int b) {
    return a > b; // Same as greater<int>, makes a min-heap
};
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
```

#### **Using a Struct**
```cpp
struct CustomCompare {
    bool operator()(int a, int b) {
        return a > b; // Min-heap
    }
};

priority_queue<int, vector<int>, CustomCompare> pq;
```

---

### **Summary**
- `priority_queue<int>` → **Max-Heap** (default, stores largest element on top).
- `priority_queue<int, vector<int>, greater<int>>` → **Min-Heap** (stores smallest element on top).
- `vector<int>` is used as the underlying storage for the heap.
- `greater<int>` reverses the default behavior from max-heap to min-heap.
- We can use **custom comparators** (lambda functions or structs) for complex priority rules.

---

### **Time Complexity of Priority Queue Operations**
| Operation  | Complexity |
|------------|------------|
| `push()`   | **O(log N)** |
| `pop()`    | **O(log N)** |
| `top()`    | **O(1)** |
| `size()`   | **O(1)** |

This is because `priority_queue` is implemented as a **binary heap**, where:
- `push()` and `pop()` maintain heap order using `O(log N)` **heapify** operations.
- `top()` always accesses the first element in `O(1)`.

---

🚀 **Now you have a clear understanding of why `greater<int>` is used and how `priority_queue` works internally!** Let me know if you need further clarification. 😊




-------------------------------------------------------------------------------------

### **Understanding `decltype` in C++ (Noob-Friendly Explanation)**
In **simple terms**, `decltype` is used to **get the type of an expression or variable** at **compile-time**.

---
### **1️⃣ What Does `decltype` Do?**
Let's say you have a variable:
```cpp
int x = 10;
```
Now, if you want another variable with the **same type as `x`**, instead of writing:
```cpp
int y = 20;
```
You can use:
```cpp
decltype(x) y = 20;  // `y` is automatically of type `int`
```
✔️ **`decltype(x)` is replaced by `int` at compile time.**  

---
### **2️⃣ Why Do We Use `decltype` with Lambda Functions?**
When using **lambda functions**, they **don’t have a standard type** like `int` or `double`. They have a unique, compiler-generated type.

Example:
```cpp
auto cmp = [](int a, int b) { return a > b; };
```
- **`cmp` is a lambda function**.
- Its **type is compiler-generated and unknown** (not `int`, `bool`, etc.).
- So we **cannot directly use** `priority_queue<int, vector<int>, cmp>` (because `cmp` is not a type).

---
### **3️⃣ Using `decltype(cmp)` to Get Lambda Type**
Instead of manually specifying an unknown lambda type, we use `decltype(cmp)`:
```cpp
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
```
✔️ **`decltype(cmp)` automatically replaces itself with the actual type of `cmp` (the lambda function).**

---
### **4️⃣ Breaking It Down**
```cpp
auto cmp = [](int a, int b) { return a > b; };
```
- This is an **anonymous function** that compares two numbers.

Now we create a **min-heap** priority queue using this comparator:
```cpp
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
```
#### **What Each Part Does:**
| Part | Meaning |
|------|---------|
| `priority_queue<int,` | Stores integers |
| `vector<int>,` | Uses a `vector<int>` internally |
| `decltype(cmp)>` | Uses the same type as `cmp` (which is a lambda function) |
| `pq(cmp);` | Initializes the priority queue with our custom comparator |

---
### **5️⃣ Why Not Just Use `greater<int>`?**
If you only need a **min-heap**, you can just use:
```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```
But if your **comparison logic is complex**, you **need a custom comparator**, and that’s when `decltype(cmp)` is useful.

---
### **Final Example**
```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Lambda function (Custom Comparator)
    auto cmp = [](int a, int b) { return a > b; }; // Min-heap

    // Create priority queue with custom comparator
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    pq.push(10);
    pq.push(5);
    pq.push(20);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}
```
### **📝 Output:**  
```
5 10 20
```
✔️ **It behaves like a min-heap because our comparator (`cmp`) ensures the smallest element has the highest priority.**

---
### **6️⃣ TL;DR (Summary)**
- `decltype(x)` → **Gets the type of `x`** at **compile-time**.
- `decltype(cmp)` → **Gets the type of the lambda function `cmp`**.
- **Lambda functions have unique types**, so we use `decltype(cmp)` to infer their type.
- This allows us to use a **custom comparator in `priority_queue`**.

---
🚀 **Now you have a clear understanding of `decltype`!** Let me know if anything needs more clarification. 😊


