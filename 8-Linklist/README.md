## Linklist
## Why we need Dynamic data structure
<img src="./images/imagea.png" width="500" />
<img src="./images/imageb.png" width="500" />

## About Linklist
<img src="./images/imagec.png" width="500" />
<img src="./images/imaged.png" width="500" />

## More about Linklist
<img src="./images/imagee.png" width="500" />
<img src="./images/imagef.png" width="500" />
<img src="./images/imageg.png" width="500" />

## Display Linklist
<img src="./images/imageg.png" width="500" />
<img src="./images/imageh.png" width="500" />

## Recursive Display of link list
<img src="./images/imagei.png" width="500" />
<img src="./images/imagej.png" width="500" />

## Counting Nodes in link list
<img src="./images/imagek.png" width="500" />
<img src="./images/imagel.png" width="500" />
<img src="./images/imagem.png" width="500" />
<img src="./images/imagen.png" width="500" />

## Sum of all element in linklist
<img src="./images/imageo.png" width="500" />

## Maximum element in linklist
<img src="./images/imagep.png" width="500" />

## Searching in a linklist
<img src="./images/imageq.png" width="500" />
<img src="./images/imager.png" width="500" />
<img src="./images/images.png" width="500" />
<img src="./images/imaget.png" width="500" />
<img src="./images/imageu.png" width="500" />

## Inserting in linklist
<img src="./images/imagev.png" width="500" />
<img src="./images/imagew.png" width="500" />
<img src="./images/imagex.png" width="500" />

## Creating Linklist using insert
<img src="./images/imagey.png" width="500" />
<img src="./images/imagez.png" width="500" />

## Inserting in a sorted Linked List
<img src="./images/imageza.png" width="500" />
  
## Deleting from LinkList
<img src="./images/imagezb.png" width="500" />
<img src="./images/imagezc.png" width="500" />

## Check if link list is sorted
<img src="./images/imagezd.png" width="500" />

## Removing duplicated from sorted element
<img src="./images/imageze.png" width="500" />

## Reversing a linklist
<img src="./images/imagezf.png" width="500" />
<img src="./images/imagezg.png" width="500" />

### sliding pointer
<img src="./images/imagezh.png" width="500" />

### Recursive for reversing linklist
<img src="./images/imagezi.png" width="500" />

## Concatenationing 2 linnklists
<img src="./images/imagezj.png" width="500" />

## Merging two link list
<img src="./images/imagezk.png" width="500" />
<img src="./images/imagezl.png" width="500" />

## Checking loop in linklist
<img src="./images/imagezm.png" width="500" />
<img src="./images/imagezn.png" width="500" />

## Circular Link List
<img src="./images/imagezo.png" width="500" />
<img src="./images/imagezp.png" width="500" />

## Display Circular Link List
<img src="./images/imagezo.png" width="500" />
<img src="./images/imagezp.png" width="500" />
<img src="./images/imagezq.png" width="500" />
<img src="./images/imagezr.png" width="500" />

## Delete Circular Link List
<img src="./images/imagezs.png" width="500" />
<img src="./images/imagezt.png" width="500" />
<img src="./images/imagezu.png" width="500" />
<img src="./images/imagezv.png" width="500" />

## Doubly Link List
<img src="./images/imagezw.png" width="500" />

## Inserting in doubly link list
<img src="./images/imagezx.png" width="500" />
<img src="./images/imagezy.png" width="500" />

## Deleting from doubly linklist
<img src="./images/imagezz.png" width="500" />
<img src="./images/imagezza.png" width="500" />

## Reversing doubly link list
<img src="./images/imagezzb.png" width="500" />
<img src="./images/imagezzc.png" width="500" />

## Circilar doubly link list
<img src="./images/imagezzb.png" width="500" />
<img src="./images/imagezze.png" width="500" />

## Comparision of LinkedList
<img src="./images/imagezzf.png" width="500" />

# Comparison of Various Types of Linked Lists

## Introduction
This document compares different types of linked lists based on various criteria such as space complexity, insertion, deletion, and traversal operations.

## Types of Linked Lists
1. **Singly Linked List (Linear)**
   - Each node has a single pointer to the next node.
   
2. **Circular Singly Linked List**
   - The last node points back to the first node, forming a circular structure.
   
3. **Doubly Linked List (Linear)**
   - Each node has two pointers: one pointing to the next node and another pointing to the previous node.
   
4. **Circular Doubly Linked List**
   - A doubly linked list where the last node points to the first, forming a circular structure.

## Comparison Criteria

### 1. Space Complexity
- Singly Linked List: **O(n)** (One pointer per node)
- Circular Singly Linked List: **O(n)** (Same as singly linked list)
- Doubly Linked List: **O(2n)** (Two pointers per node)
- Circular Doubly Linked List: **O(2n)** (Same as doubly linked list)

### 2. Traversal
- **Singly Linked List**: Forward traversal only.
- **Circular Singly Linked List**: Forward traversal; circular access possible.
- **Doubly Linked List**: Forward and backward traversal.
- **Circular Doubly Linked List**: Forward and backward traversal; circular access possible.

### 3. Insertion Operations

#### Inserting at the Beginning
- **Singly Linked List**: O(1) (Modify one pointer)
- **Circular Singly Linked List**: O(n) (Modify last node pointer)
- **Doubly Linked List**: O(1) (Modify two pointers)
- **Circular Doubly Linked List**: O(1) (Modify four pointers)

#### Inserting at Any Other Position
- **All types**: O(n) in worst case (traversing to the correct position)

### 4. Deletion Operations

#### Deleting the Head Node
- **Singly Linked List**: O(1) (Move head pointer)
- **Circular Singly Linked List**: O(n) (Modify last node pointer)
- **Doubly Linked List**: O(1) (Modify two pointers)
- **Circular Doubly Linked List**: O(1) (Modify four pointers)

#### Deleting Any Other Node
- **All types**: O(n) in worst case (traversing to the node before deletion)

### 5. Special Considerations
- If a **pointer to a node** is already given, deleting that node in a singly linked list requires O(n) time to update the previous node’s pointer.
- In a **doubly linked list**, deleting a node when given its pointer takes **O(1)** time since the previous node can be accessed directly.

### 6. Use Cases
- **Singly Linked List**: Used in queues, stacks, and where traversal is unidirectional.
- **Circular Singly Linked List**: Suitable for buffering applications, round-robin scheduling.
- **Doubly Linked List**: Used when bidirectional access is required, such as in a browser history or navigation system.
- **Circular Doubly Linked List**: Used in applications requiring constant circular movement, like a music playlist.


## Comparision of Array and linked list

# Comparison of Arrays and Linked Lists

## Introduction
This document provides a detailed comparison of Arrays and Linked Lists, covering their structures, memory allocation, operations, and efficiency.

## Physical Structures
- There are two fundamental physical data structures:
  1. **Array**
  2. **Linked List**
- Other logical structures are built using these fundamental structures.

## Memory Allocation
- **Arrays**: Can be created in both **stack** and **heap** memory.
- **Linked Lists**: Always created in **heap** memory.

## Size and Growth
- **Arrays**: Fixed size. Once created, the size cannot be changed. To increase size, a new array must be created.
- **Linked Lists**: Dynamic size. They can grow as long as heap memory is available.

## Space Utilization
- **Arrays**: Occupies space equal to the size of stored data.
- **Linked Lists**: Requires extra space for storing pointers to the next node, leading to additional memory consumption.

## Accessibility
- **Arrays**: Can be accessed randomly using an index.
- **Linked Lists**: Can only be accessed sequentially, requiring traversal from the first node to reach a specific element.

## Speed of Access
- **Arrays**: Faster access as they allow **random access**.
- **Linked Lists**: Slower access due to **sequential traversal**.

## Insertion and Deletion
- **Arrays**:
  - Insertion at the end is efficient (O(1)).
  - Insertion in the middle requires shifting elements (O(n)).
  - Deletion at the end is efficient (O(1)).
  - Deletion in the middle requires shifting elements (O(n)).
- **Linked Lists**:
  - Insertion at the beginning is efficient (O(1)).
  - Insertion in the middle requires traversal (O(n)).
  - Deletion at the beginning is efficient (O(1)).
  - Deletion in the middle requires traversal (O(n)).
  - No shifting of elements is required, only pointer manipulation.

## Data Movement
- **Arrays**: Moving elements involves shifting data, which is costly if the data size is large.
- **Linked Lists**: Only pointers are modified, making data movement more efficient.

## Searching
- **Arrays**:
  - Supports both **linear search** (O(n)) and **binary search** (O(log n)).
- **Linked Lists**:
  - Only supports **linear search** (O(n)).
  - Binary search is inefficient due to sequential access, making it O(n log n) instead of O(log n).

## Sorting
- Sorting algorithms perform better on arrays due to direct indexing.
- Linked lists may require additional steps for efficient sorting.

## Summary
| Feature            | Array                      | Linked List               |
|--------------------|---------------------------|---------------------------|
| Memory Location   | Stack / Heap               | Heap                      |
| Size              | Fixed                      | Dynamic                    |
| Extra Space       | No extra memory required  | Requires extra pointers    |
| Access Speed      | Fast (random access)       | Slow (sequential access)  |
| Insertion         | O(1) at end, O(n) in middle | O(1) at beginning, O(n) in middle |
| Deletion         | O(1) at end, O(n) in middle | O(1) at beginning, O(n) in middle |
| Searching         | O(n) (linear), O(log n) (binary) | O(n) (linear only) |
| Sorting          | Efficient (direct indexing) | Less efficient |

Arrays are preferred when random access and fixed-size storage are required. Linked lists are better for dynamic storage with frequent insertions and deletions.

## Finding middle element of the link list
<img src="./images/imagezzg.png" width="500" />

## Find Intersection of 2 linked list
<img src="./images/imagezzh.png" width="500" />
<img src="./images/imagezzi.png" width="500" />
<img src="./images/imagezzj.png" width="500" />

