# Sorting Algorithms

This repository contains C programs that implement various sorting algorithms. Each sorting algorithm is implemented as a separate C file. The repository includes the following sorting algorithms:

1. **Bubble Sort**
   - File: [101-bubble_sort.c](101-bubble_sort.c)
   - Description: Implementation of the Bubble Sort algorithm.

2. **Insertion Sort**
   - File: [102-insertion_sort_list.c](102-insertion_sort_list.c)
   - Description: Implementation of the Insertion Sort algorithm for doubly linked lists.

3. **Selection Sort**
   - File: [2-selection_sort.c](2-selection_sort.c)
   - Description: Implementation of the Selection Sort algorithm.

4. **Quick Sort - Lomuto Partition scheme**
   - File: [3-quick_sort.c](3-quick_sort.c)
   - Description: Implementation of the Quick Sort algorithm using the Lomuto Partition scheme.

5. **Quick Sort - Hoare Partition scheme**
   - File: [107-quick_sort_hoare.c](107-quick_sort_hoare.c)
   - Description: Implementation of the Quick Sort algorithm using the Hoare Partition scheme.

6. **Counting Sort**
   - File: [102-counting_sort.c](102-counting_sort.c)
   - Description: Implementation of the Counting Sort algorithm.

7. **Merge Sort**
   - File: [103-merge_sort.c](103-merge_sort.c)
   - Description: Implementation of the Merge Sort algorithm.

8. **Heap Sort**
   - File: [104-heap_sort.c](104-heap_sort.c)
   - Description: Implementation of the Heap Sort algorithm using the sift-down approach.

9. **Radix Sort**
   - File: [105-radix_sort.c](105-radix_sort.c)
   - Description: Implementation of the Radix Sort algorithm using the LSD approach.

10. **Bitonic Sort**
   - File: [106-bitonic_sort.c](106-bitonic_sort.c)
   - Description: Implementation of the Bitonic Sort algorithm for arrays of size 2^k.

11. **Dealer (Sorting a Deck of Cards)**
    - Files: [deck.h](deck.h), [1000-sort_deck.c](1000-sort_deck.c), [1000-main.c](1000-main.c)
    - Description: Sorting a deck of cards using various sorting techniques.

## Usage

To compile and run the programs, use the following commands:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -o output_file input_file.c
./output_file

