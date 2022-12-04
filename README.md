
# Data Structures and Algorithms in C++


## Sorting Algorithms

### Bubble Sort
👉 [`SortingAlgorithms::bubbleSort`](https://github.com/shubham0204/DSA/blob/DSA/sorting_algorithms.cpp#L56)

![](https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif)
> Source: [Bubble Sort - Wikipedia](https://en.wikipedia.org/wiki/Bubble_sort)

Implement the bubble sort algorithm
The algorithm performs swaps of adjacent elements until the largest element is "bubbled" or "shifted"
to the rightmost position in each pass.

Properties:
- comparison-based
- in-place
- stable
- for internal sorting only.

Time and Space Complexity:
- Worst and average-case time complexity: `O( N^2 )` comparisons, `O( N^2 )` swaps
- Best case time complexity: `O( N )` comparisons, `O( 1 )` swaps
- Space Complexity: `O( 1 )` always



### Selection Sort
👉 [`SortingAlgorithms::selectionSort`](https://github.com/shubham0204/DSA/blob/DSA/sorting_algorithms.cpp#L90)

![](https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif)
> Source: [Insertion Sort - Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)

Implement the selection sort algorithm
In each kth pass, we determine the k-smallest element and place it at the (k - 1)th index

Properties:
- comparison-based
- in-place
- stable
- for internal sorting only.

Time and Space Complexity:
- Worst and average-case time complexity: `O( N^2 )` comparisons, `O( N )` swaps
- Best case time complexity: `O( N^2 )` comparisons, `O( 1 )` swaps
- Space Complexity: `O( 1 )` always

### Insertion Sort
👉 [`SortingAlgorithms::insertionSort`](https://github.com/shubham0204/DSA/blob/DSA/sorting_algorithms.cpp#L125)

![](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)
> Source: [Insertion Sort - Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort)

Implement the insertion sort algorithm
We iterate through element ( say the kth element ) and place it in its correct position in the array,
that is already swept ( i.e. the subarray from `[0 , k - 1] ). It is most efficient than selection sort
and bubble sort for arrays that are nearly sorted.

Properties:
- comparison-based
- in-place
- stable
- online: It can sort array elements as it receives newer elements.

Time and Space Complexity:
- Worst and average-case time complexity: `O( N^2 )` comparisons and swaps
- Best case time complexity: `O( N )` comparisons, `O( 1 )` swaps
- Space Complexity: `O( 1 )` always