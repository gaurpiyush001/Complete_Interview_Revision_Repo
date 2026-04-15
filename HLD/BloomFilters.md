A Bloom filter is a space-efficient probabilistic data structure used to test whether an element exists in a set. It uses a bit array and multiple hash functions. On insertion, it sets bits at positions given by hashes. On lookup, if any bit is 0, the element definitely does not exist; if all bits are 1, it might exist. It has no false negatives but allows false positives.

It is commonly used to prevent cache penetration by filtering out invalid keys before hitting the database.



---------------------------------------------------------------------------------

Think of it like a smart membership test

You ask:

“Does userId = 123 exist?”

Bloom filter answers:

❌ Definitely NOT present → 100% correct
✅ Might be present → need to check DB/cache

👉 It NEVER says “present” with certainty

⚙️ How it works internally
Step 1: Bit array

Imagine:

[0 0 0 0 0 0 0 0 0 0]   (size = N bits)

Initially all zeros.

Step 2: Multiple hash functions

Say we use 3 hash functions:

h1(x), h2(x), h3(x)

Each maps input → index in array

➕ Insertion (adding a key)

Insert userId = 42

h1(42) → index 2
h2(42) → index 5
h3(42) → index 8

Update:

[0 0 1 0 0 1 0 0 1 0]

👉 We set those positions to 1

🔍 Lookup (checking a key)

Check userId = 42

h1(42) → 2 → bit = 1
h2(42) → 5 → bit = 1
h3(42) → 8 → bit = 1

👉 All 1 → Might exist ✅

------------------------------------------------------------------------------

We apply mutex locking at the cache key level. For example, for a key like product:123, we create a corresponding lock key like lock:product:123. When a cache miss happens, only one request acquires the lock (using Redis SET NX) and rebuilds the cache by fetching from the database. Other concurrent requests either wait, retry, or return stale data. This ensures only one DB hit for a hot key and prevents cache breakdown.

Cache Breakdown (Hot Key Problem)
💥 What actually happens

Imagine:

GET /celebrity/elon

This key is VERY popular.

Timeline:
1M users hitting cache → all good ✅
Suddenly key expires ⏰

Now:

1M requests → Cache MISS → DB

👉 DB gets 1M simultaneous queries 💣

🔍 Why this is dangerous

Because:

All traffic is concentrated on one key

This is called Hot Key