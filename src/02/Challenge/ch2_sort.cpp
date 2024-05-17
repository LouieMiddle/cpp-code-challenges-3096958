// C++ Code Challenges, LinkedIn Learning

// Challenge #2: Sorting an Array
// Sort the elements in an array in ascending order.
// Implement the algorithm of your choice.
// Don't use STL vectors.
// Don't use a sorting function from a library.

#include <iostream>

int partition(int *arr, int lo, int hi) {
    int pivot_value = arr[hi];
    int pivot_index = lo;

    for (int j = lo; j < hi; j++) {
        if (arr[j] <= pivot_value) {
            std::swap(arr[pivot_index], arr[j]);
            pivot_index += 1;
        }
    }

    std::swap(arr[pivot_index], arr[hi]);
    return pivot_index;
}

void quick_sort(int *arr, int lo, int hi) {
    if ((lo > hi) || (lo < 0)) {
        return;
    }

    int p = partition(arr, lo, hi);

    quick_sort(arr, lo, p-1);
    quick_sort(arr, p+1, hi);
}

// sort_array()
// Summary: This function receives an array of integers and sorts it in ascending order.
// Arguments:
//           arr: A pointer acting as the array to sort.
//           n: The size of the array.
// Returns: A boolean value: True on success, false otherwise.
bool sort_array(int *arr, int n){
    quick_sort(arr, 0, n-1);
    return false;
}

// Main function
int main(){
    // The following array will be treated as an array of length len. 
    const int len = 7; // Don't exceed the length of the array below!
    int array[] = {2, 9, 4, 3, 5, 1, 6, 8, 0, 7};

    // Print the original array
    std::cout << "Original Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    sort_array(array, len); // Sort the array

    // Print the sorted array
    std::cout << "  Sorted Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    return 0;
}
