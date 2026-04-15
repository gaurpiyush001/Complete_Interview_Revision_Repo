//https://www.geeksforgeeks.org/building-heap-from-array/

//Given an array of N elements. The task is to build a Binary Heap from the given array. The heap can be either Max Heap or Min Heap.

// Root is at index 0 in array.
// Left child of i-th node is at (2*i + 1)th index.
// Right child of i-th node is at (2*i + 2)th index.
// Parent of i-th node is at (i-1)/2 index.


// So, the idea is to heapify the complete binary tree formed from the array in reverse level order following a top-down approach. That is first heapify, the last node in level order traversal of the tree, then heapify the second last node and so on. 


//Time Complexity Analysis: Heapify a single node takes O(log N) time complexity where N is the total number of Nodes. Therefore, building the entire Heap will take N heapify operations and the total time complexity will be O(N*logN).
// Note: In reality, building a heap takes O(n) 

/*
The reason it's not considered O(nlogn) is because building a heap doesn't involve sorting the elements, which is what typically contributes to a time complexity of O(nlogn). Instead, building a heap involves a process called heapification, where elements are rearranged in the array to satisfy the heap property (i.e., parent nodes are greater than or equal to their child nodes in a max heap, or less than or equal to their child nodes in a min heap).
*/

/*
Heapification can be performed efficiently in O(n) time complexity, making the overall time complexity of building a heap O(n). This is because the number of operations required to heapify each level of the heap decreases exponentially as you move up the tree. Therefore, the total number of operations is bounded by a constant multiple of the number of elements in the array, leading to a linear time complexity.
*/

/*
The above approach can be optimized by observing the fact that the leaf nodes need not to be heapified as they already follow the heap property. Also, the array representation of the complete binary tree contains the level order traversal of the tree. So the idea is to find the position of the last non-leaf node and perform the heapify operation of each non-leaf node in reverse level order.
*/

//Last non-leaf node = Node at index ((n-1) – 1)/2 = (n/2) – 1.

