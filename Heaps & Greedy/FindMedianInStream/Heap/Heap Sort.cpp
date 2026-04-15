//Heap sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to the selection sort where we first find the minimum element and place the minimum element at the beginning. Repeat the same process for the remaining elements.

//First convert the array into heap data structure using heapify, then one by one delete the root node of the Max-heap and replace it with the last node in the heap and then heapify the root of the heap. Repeat this process until size of heap is greater than 1.

/*
Build a heap from the given input array.
Repeat the following steps until the heap contains only one element:
Swap the root element of the heap (which is the largest element) with the last element of the heap.
Remove the last element of the heap (which is now in the correct position).
Heapify the remaining elements of the heap.
The sorted array is obtained by reversing the order of the elements in the input array.
*/

/*
Complexity Analysis of Heap Sort
Time Complexity: O(N log N)
Auxiliary Space: O(log n), due to the recursive call stack. However, auxiliary space can be O(1) for iterative implementation.

Important points about Heap Sort:
Heap sort is an in-place algorithm. 
Its typical implementation is not stable but can be made stable (See this)
Typically 2-3 times slower than well-implemented QuickSort.  The reason for slowness is a lack of locality of reference.
*/

//Some Sorting Algorithms are stable by nature, such as Bubble Sort, Insertion Sort, Merge Sort, Count Sort, etc.

//Which sorting algorithms are unstable? 
//Quick Sort, Heap Sort etc., can be made stable by also taking the position of the elements into consideration. This change may be done in a way that does not compromise a lot on the performance and takes some extra space, possibly \theta(n)      .