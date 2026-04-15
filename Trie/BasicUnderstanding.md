## Need kyu padri hai iski ?

- lets get a problem statement, by which we will understand - Trie
1. I want to implement a dictionary - where there can be major three operation
- Insert Word
- Search Word
- Delete Word

2. Which datastrcure will be best suitable for this
- First thing will come to my mind is Hash Map
- which will perform all 3 operation in O(1) time.
- but ye constant T.C average case mein ayegi
- For worst case it will be - O(length of word)

- Now lets explore Trie, how does it solve this problem
- Difference kya hai HashMap and Trie, because complexity are same of all three operation in both
- If there are words like 
- ARE, ARM, ARENA, ARMDILO, ARMDENO
- In hash map, all words the storage will allocated separately, 
- But in Trie, storage is optimized, by reusing the common character prefix strings
- Just typing few words - we can suggest present word in our dictionary starting from prefix string you typed, But in hash map we will be required to traverse whole hash map, and do string comparison

- A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.