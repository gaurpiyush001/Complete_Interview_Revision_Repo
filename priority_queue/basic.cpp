/*
How to Implement Priority Queue? 
Priority queue can be implemented using the following data structures: 

Arrays - enqueu(O(n)) | dequeue(O(n)) | peek(O(1))
Linked list - enqueu(O(n)) | dequeue(O(1)) | peekO(1)
Heap data structure - enqueu(O(logn)) | dequeue(O(logn)) | peek(O(1))
Binary search tree - enqueu(O(logn)) | dequeue(O(logn)) | peek(O(1))
*/

/*
3) Implement Priority Queue Using Heaps: 
Binary Heap is generally preferred for priority queue implementation because heaps provide better performance compared to arrays or LinkedList. Considering the properties of a heap, The entry with the largest key is on the top and can be removed immediately. It will, however, take time O(log n) to restore the heap property for the remaining keys. However if another entry is to be inserted immediately, then some of this time may be combined with the O(log n) time needed to insert the new entry. Thus the representation of a priority queue as a heap proves advantageous for large n, since it is represented efficiently in contiguous storage and is guaranteed to require only logarithmic time for both insertions and deletions.
*/