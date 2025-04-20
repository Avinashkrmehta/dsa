#selection sort

def selection_sort(arr)
  n = arr.length
  for i in 0...(n - 1)
    min_index = i
    for j in (i + 1)...n
      if arr[j] < arr[min_index]
        min_index = j
      end
    end
    arr[i], arr[min_index] = arr[min_index], arr[i] if min_index != i
  end
end

# Example usage
arr = [64, 25, 12, 22, 11]
puts "Original array: #{arr}"
selection_sort(arr)
puts "Sorted array: #{arr}"
# Output:
# Original array: [64, 25, 12, 22, 11]
# Sorted array: [11, 12, 22, 25, 64]
# Time Complexity: O(n^2) in all cases (best, average, worst)
# Space Complexity: O(1) as it requires a constant amount of space for the variables used in the algorithm.

# The selection sort algorithm is not a stable sort, as it may change the relative order of equal elements.
# It is an in-place sorting algorithm, meaning it does not require additional storage space proportional to the input size.
# Selection sort is not suitable for large datasets as its average and worst-case time complexity is quite high compared to more efficient algorithms like quicksort or mergesort.
# However, it can be useful for small datasets or when memory usage is a concern.
# Selection sort is also easy to implement and understand, making it a good choice for educational purposes.
# It is often used in situations where memory writes are more expensive than reads, as it minimizes the number of writes to the array.
# Selection sort is also a good choice when the input data is already partially sorted, as it can quickly find the minimum element and place it in the correct position.
# However, it is not a good choice for large datasets or when the input data is randomly ordered, as its time complexity is O(n^2) in all cases.
# In summary, selection sort is a simple and easy-to-understand sorting algorithm that is not suitable for large datasets but can be useful in certain situations where memory usage is a concern or when the input data is already partially sorted.
# It is also a good choice for educational purposes, as it is easy to implement and understand.
# Overall, selection sort is a simple and straightforward sorting algorithm that can be useful in certain situations, but it is not the most efficient choice for large datasets or randomly ordered input data.
# It is important to consider the specific requirements of the problem at hand when choosing a sorting algorithm, as different algorithms have different strengths and weaknesses.
# In general, it is best to use more efficient algorithms like quicksort or mergesort for large datasets, while selection sort can be used for small datasets or when memory usage is a concern.
# It is also important to consider the specific requirements of the problem at hand when choosing a sorting algorithm, as different algorithms have different strengths and weaknesses.