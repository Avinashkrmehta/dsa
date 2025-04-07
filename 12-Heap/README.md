## Binary Heap

## Introduction of Heap
<img src="./images/imagea.png" width="500" />
<img src="./images/imageb.png" width="500" />
<img src="./images/imagec.png" width="500" />

---

## Inserting in a Heap
<img src="./images/imaged.png" width="500" />
<img src="./images/imagee.png" width="500" />

---

## Program to insert in a Heap
<img src="./images/imagef.png" width="500" />

---

## Creating a Heap
<img src="./images/imageg.png" width="500" />
<img src="./images/imageh.png" width="500" />
<img src="./images/imagei.png" width="500" />
<img src="./images/imagej.png" width="500" />

---

## Deletion from a Heap
<img src="./images/imagek.png" width="500" />
<img src="./images/imagel.png" width="500" />
<img src="./images/imagem.png" width="500" />
<img src="./images/imagen.png" width="500" />
















# 📚 Binary Heap - Notes

## 🔍 Overview

In this topic, we will cover the following:

- What is a Heap?
- Insertion in a Heap
- Deletion from a Heap
- Understanding `Heapify`
- Priority Queues and their relation to Heaps

---

## 📘 What is a Heap?

A **Heap** is a special **complete binary tree** that satisfies one of the following properties:

### 🔸 1. Complete Binary Tree

A binary tree is *complete* if:
- All levels are fully filled **except possibly the last**.
- The last level has all keys as far left as possible.
- In array representation, **no blank spots** are allowed in between.

**Array Index Rule:**
```
Parent at index i:
Left Child  => 2i
Right Child => 2i + 1
```

### 🧠 Conceptual Diagram: Complete Binary Tree

```text
Index:    1   2   3   4   5   6   7
Values:  20  15  18  10  12  14  16
```

- Complete: No gaps between indices.
- If we remove a node (e.g., value at index 4), it becomes **incomplete**.

---

## 🏗️ Heap Types

### 🔹 Max Heap
- Every parent node has a value **greater than or equal to** its children.
- **Example:**  
  ```
       20
      /  \
    15    18
   / \    / \
  10 12  14 16
  ```

### 🔹 Min Heap
- Every parent node has a value **smaller than or equal to** its children.
- **Example:**
  ```
       5
      / \
     10 15
    / \
   20 25
  ```

---

## 🔁 Key Properties

- **Binary Heap is usually implemented using an array.**
- **Duplicates are allowed.**
- **Height of Heap = log(n)** (Because it's complete, height grows minimally).
- **Not used for search operations** (unlike Binary Search Trees).

---

## 🧮 Why Array Implementation?

Array is preferred because:
- Easy calculation of parent and child using indices.
- Space-efficient and cache-friendly.
- Avoids pointer overhead from linked representation.

---

## ⚙️ Operations (To Be Covered Later)

- **Insertion** into Heap
- **Deletion** from Heap
- **Heapify** procedure
- Using Heap for **Priority Queues**

---

## 📌 Summary

| Property         | Details                                      |
|------------------|----------------------------------------------|
| Type             | Complete Binary Tree                         |
| Usage            | Priority Queues, Heap Sort                   |
| Heap Types       | Max Heap, Min Heap                           |
| Representation   | Array (most common), Linked (rare)           |
| Efficiency       | Insert/Delete: O(log n), Search: Not Optimal |

Here’s a clean and clear summary of the transcript you provided. It's focused on **heap insertion in a max heap**, and formatted for easy understanding:

---

## 🛠️ Inserting an Element into a Max Heap

### 🎯 Goal:
Learn how to insert an element into a **Max Heap** while maintaining heap properties.

### 📌 Key Concepts:
- A **Max Heap** is a **complete binary tree** where every parent node is **greater than its children**.
- It is usually implemented as an **array**, with indexing starting at **1** for easier formula calculations.

---

### 🔢 Step-by-Step Insertion Procedure

#### 🧮 Example:
Inserting element `40` into the heap:

#### 1. **Insert at the Next Free Position**:
- Always insert the new element at the **next available index** to maintain **completeness** of the binary tree.
- For `40`, suppose it's inserted at index `8`.

#### 2. **Compare with Parent (Bubble Up)**:
- Compare the inserted element with its parent using index: `i // 2`.
- If the new element is **greater**, **swap** it with the parent.
- Continue this **bubble-up** process until the **heap property** is satisfied.

#### 3. **Repeat Until Root or Heap Property Maintained**:
- Keep moving the element up the tree until it is either at the root or **no longer greater** than its parent.

---

### 🔁 Inserting Another Element (`35`)

#### Steps:
- Insert `35` at index `9`.
- Compare it with its parent at `index 4`, then move up as needed (compare with `index 2`, and so on).
- Stop when the heap property is satisfied.

---

### 🧠 Notes:
- Always insert elements in **level order** (left to right).
- Use **temporary variables** to hold values during swaps.
- Maintain **complete binary tree structure** at all times.
- **Heapify-up** continues until no parent is smaller than the inserted element.

---

### ✅ Result:
After each insertion, elements are **rearranged** to restore the **max heap** property without violating the **complete binary tree** structure.

---

Here’s a clean, concise summary of the transcript you provided — it's been rephrased into a clear explanation of the **heap insert operation** along with its **time complexity analysis**:

---

### 📌 Heap Insertion Procedure (Min/Max Heap)

To insert an element into a heap, follow these steps:

1. **Add the element at the end of the heap array**:
   - For example, insert `50` at index `n` (next available position).

2. **Initialize helper variables**:
   - Let `i = n` (current index of the new element).
   - Store the inserted element in a temporary variable: `temp = heap[i]`.

3. **Percolate up (heapify-up)**:
   - Repeat the following until either `i == 1` (reached the root) or `temp <= heap[i / 2]` (parent is greater for max heap or smaller for min heap):
     - Move the parent element `heap[i / 2]` down to `heap[i]`.
     - Set `i = i / 2`.

4. **Insert the `temp` at its correct position**:
   - Once the loop stops, assign `heap[i] = temp`.

---

### ⏱️ Time Complexity Analysis

- Each insertion involves moving up the tree (percolating).
- In a **complete binary heap**, the height is **log₂(n)**.
- Thus, the **time complexity for insertion** is:

  [O(log n)]

This log(n) complexity is both theoretically and practically confirmed from the loop behavior in the code — where `i` is repeatedly divided by 2.

---


# Max Heap Creation - In-Place Algorithm

This project demonstrates how to create a **max heap** using a simple, in-place algorithm. It builds upon the idea of inserting one element at a time into the heap while maintaining the heap properties.

---

## 📌 What is a Heap?

A **heap** is a special tree-based data structure that satisfies the heap property:

- In a **max heap**, for every node `i`, the value of `i` is **greater than or equal to** the values of its children.
- A heap is also a **complete binary tree**, meaning all levels are fully filled except possibly for the last, which is filled from left to right.

---

## 🧠 Concept

- Initially, only the **first element** of the array is considered to be in the heap.
- Remaining elements are inserted **one-by-one** into the heap using the insert operation.
- Each insertion maintains the **heap property** by comparing the newly added node with its parent and swapping them if needed.
- This process continues until all elements are added to the heap.

> **This is known as in-place heap creation** – it doesn't require extra memory or space, as the heap is built directly within the array.

---

## 📈 Example

Consider inserting the elements in the following order:

```
[30, 20, 10, 40, 15, 12, 25]
```

### Step-by-step Heap Building:

1. Begin with first element: `[30]` → Heap of size 1
2. Insert 20 → `[30, 20]`
3. Insert 10 → `[30, 20, 10]`
4. Insert 40 → Swaps with 10 → Then swaps with 30 → `[40, 30, 10, 20]`
5. Insert 15 → Compared but no swap needed → `[40, 30, 10, 20, 15]`
6. Insert 12 → Compared but no swap needed → `[40, 30, 12, 20, 15, 10]`
7. Insert 25 → Swaps with 12 → `[40, 30, 25, 20, 15, 10, 12]`

---

## 💡 In-Place Heap Creation Algorithm

No additional array or data structure is used. Only a single array is manipulated.

```cpp
void createHeap(int arr[], int n) {
    for (int i = 2; i <= n; i++) {
        insert(arr, i);
    }
}
```

Each element (starting from index 2) is inserted using the `insert` function, which ensures the max-heap property is maintained.

---

## ⚙️ Time Complexity

- **Insert Operation**: O(log n)
- **Creating Heap** (for `n` elements):  
  **O(n log n)** in worst-case  
  But can be optimized to **O(n)** using heapify (not covered here)

---

## 🧪 Demo Structure

- Elements are inserted one by one
- Every insertion step is followed by swapping (if needed) up the tree
- After all insertions, the array represents a valid max heap

---

## ✅ Final Heap Example

After inserting all elements:  
```
Input: [30, 20, 10, 40, 15, 12, 25]
Heap:  [40, 30, 25, 20, 15, 10, 12]
```

---

## 📚 References

- Heap Data Structure
- In-place algorithms
- Binary Tree properties

---

Here’s a clean, structured `README.md` file draft based on the transcript you provided, covering the key concepts of heap deletion and heap sort:

---

# 🧮 Heap Deletion & Heap Sort – Explained

This README summarizes the procedure of **deletion in a Max Heap** and introduces the concept of **Heap Sort** using deletion operations.

---

## 📌 Key Concepts

### 🔺 Max Heap Recap
- A **Max Heap** is a complete binary tree where the **largest element is always at the root**.
- You can **only delete the root element**, not any arbitrary node.

---

## 🗑️ Deleting the Root from a Max Heap

### ✅ Steps:

1. **Delete the root (largest element).**
2. **Move the last element in the heap to the root's position.**
3. **Restore the Max Heap property** by *percolating down* the new root:
   - Compare with its children.
   - Swap with the **larger child** if it's smaller.
   - Repeat until the Max Heap property is restored.

### 🔁 Algorithm Summary:
```pseudo
delete(heap, size):
  x = heap[0]          // Save root element
  heap[0] = heap[size] // Move last to root
  size -= 1            // Reduce heap size

  i = 0
  while i has a child:
    j = index of larger child
    if heap[i] < heap[j]:
      swap(heap[i], heap[j])
      i = j
    else:
      break

  heap[size + 1] = x   // Store deleted value at end
```

---

## 📚 Example

Initial Max Heap:
```
         40
       /    \
     35      30
    /  \    /  \
  15   10  25   5
```

After deleting 40:
- Move 5 to root
- Reheapify: 5 → 35 → 15

New Heap:
```
         35
       /    \
     15      30
    /  \    / 
  5   10  25  
```

Deleted Elements: [40]

---

## 📦 Heap Sort

**Heap Sort** works by:
1. **Building a Max Heap** from an unsorted array.
2. **Deleting the root repeatedly**, storing each deleted element at the end.
3. The result is a sorted array in **ascending order**.

### 🎯 Steps:
1. Construct the heap.
2. Repeat:
   - Delete root (max)
   - Store it at the end
   - Reheapify
3. Done when all elements are removed from heap section.

### 🔁 Time Complexity
- **Build Heap:** O(n)
- **Delete (per element):** O(log n)
- **Total Heap Sort:** O(n log n)

---

## ✅ Key Takeaways

- You can only delete the **highest-priority (root)** element in a heap.
- After deleting, **restore the heap** using the last element and percolate down.
- Repeating this gives you **Heap Sort**, a powerful O(n log n) sorting algorithm.

---

## 🧠 Pro Tip

Use an array to represent the heap. After every deletion, store the deleted element in the last free index. Eventually, the array will become sorted in ascending order.

---



