// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
// bool is_bitonic(const std::vector<int> &numbers){
//     bool going_up = true;

//     for (int i = 1; i < numbers.size(); i ++) {
//         if ((numbers[i] >= numbers[i-1]) && going_up) {
//             continue;
//         } else if ((numbers[i] <= numbers[i-1]) && going_up) {
//             going_up = false;
//             continue;
//         } else if ((numbers[i] <= numbers[i-1]) && !going_up) {
//             continue;
//         } else {
//             return false;
//         }
//     }

//     return true;
// }

bool is_bitonic(const std::vector<int> &numbers){
    bool going_up;
    int continue_index;

    for (int i = 1; i < numbers.size(); i ++) {
        if (numbers[i] == numbers[i-1]) {
            continue;
        } else if (numbers[i] > numbers[i-1]) {
            going_up = true;
        } else if (numbers[i] < numbers[i-1]) {
            going_up = false;
        }
        continue_index = i + 1;
        break;
    }

    for (int i = continue_index; i < numbers.size(); i++) {
        if (going_up) {
            if (numbers[i] >= numbers[i-1]) {
                continue;
            } else {
                going_up = false;
                continue_index = i + 1;
                break;
            }
        } else {
            if (numbers[i] <= numbers[i-1]) {
                continue;
            } else {
                going_up = true;
                continue_index = i + 1;
                break;
            }
        }
    }

    for (int i = continue_index; i < numbers.size(); i++) {
        if (going_up) {
            if (numbers[i] >= numbers[i-1]) {
                continue;
            } else {
                return false;
            }
        } else {
            if (numbers[i] <= numbers[i-1]) {
                continue;
            } else {
                return false;
            }
        }
    }

    return true;
}

// Main function
int main(){
    // Uncomment one of these lines and make sure you get the result at the right. 
    
    // std::vector<int> myvec = {1, 2, 5, 4, 3};  // Yes
    // std::vector<int> myvec = {1, 1, 1, 1, 1};  // Yes
    // std::vector<int> myvec = {3, 4, 5, 2, 2};  // Yes
    // std::vector<int> myvec = {3, 4, 5, 2, 4};  // No
    // std::vector<int> myvec = {1, 2, 3, 4, 5};  // Yes
    // std::vector<int> myvec = {1, 2, 3, 1, 2};  // No
    // std::vector<int> myvec = {5, 4, 6, 2, 6};  // No
    // std::vector<int> myvec = {5, 4, 3, 2, 1};  // Yes
    // std::vector<int> myvec = {5, 4, 3, 2, 6};  // Yes
    // std::vector<int> myvec = {5, 4, 6, 5, 4};  // No
    std::vector<int> myvec = {5, 4, 6, 5, 5};  // Yes

    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
