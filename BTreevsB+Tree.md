Great question — this goes to the **core of database indexing design**. Systems like **MySQL**, **PostgreSQL**, and storage engines like **InnoDB** use **B+ tree** instead of **B-tree** for indexes for very specific reasons.

You are correct about the structural difference — but the **performance implications on disk** are what matter most.

---

# 1️⃣ Structural difference

### B-tree

Data can be stored **in internal nodes and leaf nodes**.

Example:

```
        [10 | 20]
       /    |    \
   [5,7]  [12]  [25,30]
```

Internal nodes may contain **actual records**.

---

### B+ tree

Internal nodes contain **only keys**, not full data.

All **actual data is stored in leaf nodes**, and leaves are **linked like a linked list**.

```
          [10 | 20]
         /    |    \
      L1     L2     L3

L1: [1,5,7]
L2: [10,12,18]
L3: [20,25,30]

Leaf nodes linked:
L1 → L2 → L3
```

---

# 2️⃣ Why B+ tree is better for indexing

The reason is mainly **disk I/O efficiency**.

Disk access is **extremely expensive** compared to memory.

---

# 3️⃣ B+ trees have higher fanout (shallower trees)

Since internal nodes store **only keys**, they can store **many more keys per node**.

Example:

| Node Type | Keys per node |
| --------- | ------------- |
| B-tree    | 100           |
| B+ tree   | 300           |

This means the tree height becomes **smaller**.

Example for **1 billion rows**:

| Structure | Height |
| --------- | ------ |
| B-tree    | ~5     |
| B+ tree   | ~3     |

Each level requires **one disk read**.

So:

```
B-tree → 5 disk reads
B+ tree → 3 disk reads
```

Huge difference at scale.

---

# 4️⃣ Range queries become extremely fast

Range queries are very common in databases.

Example:

```
SELECT * FROM users WHERE id BETWEEN 100 AND 200
```

In **B+ tree**, leaves are linked:

```
100 → 101 → 102 → ... → 200
```

So after reaching `100`, the database simply **walks sequentially** through leaf nodes.

In **B-tree**, keys are scattered across internal nodes → requires more tree traversal.

---

# 5️⃣ Sequential disk reads become possible

Databases love **sequential reads**.

In B+ tree:

```
Leaf1 → Leaf2 → Leaf3 → Leaf4
```

This matches how disks load **pages sequentially**.

So scanning indexes is extremely efficient.

---

# 6️⃣ Internal nodes become pure routing tables

Internal nodes in B+ tree act like **search directories**:

```
find which page contains the data
```

They stay **small and cache-friendly**.

This means the upper levels of the tree can stay **fully in RAM**.

---

# 7️⃣ Predictable lookup time

In B-tree:

```
data may appear in internal node
```

Lookup depth varies.

In B+ tree:

```
data always in leaf
```

So search path length is **consistent**.

Databases prefer predictable latency.

---

# 8️⃣ Real database behavior

Most relational databases use **B+ tree indexes.

Examples:

* MySQL (InnoDB)
* PostgreSQL
* Oracle Database
* SQL Server

---

# 9️⃣ Quick comparison

| Feature         | B-tree          | B+ tree   |
| --------------- | --------------- | --------- |
| Data location   | internal + leaf | leaf only |
| Tree height     | larger          | smaller   |
| Range query     | slower          | very fast |
| Sequential scan | poor            | excellent |
| Disk I/O        | more            | less      |

---

# 🔟 One-line interview answer

> B+ trees are preferred for database indexing because internal nodes store only keys, allowing higher fanout, shallower trees, fewer disk I/O operations, and very efficient range queries due to linked leaf nodes.

---

✅ If you want, I can also show something **very important interviewers love asking**:

**Why databases prefer B+ trees over hash indexes for most queries** (this is a classic system design question).
