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

bool is_bitonic(const std::vector<int> &numbers){
    bool going_up;
    int continue_index;
    int first_number = numbers[0];
    int wrap_around_number;
    bool check_wrap_around = false;

    for (int i = 1; i < numbers.size(); i ++) {
        if (numbers[i] == numbers[i-1]) {
            continue;
        } else if (numbers[i] > numbers[i-1]) {
            going_up = true;
        } else {
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
                if (first_number == numbers[i]) {
                    continue_index = i + 1; 
                    wrap_around_number = numbers[i];
                    check_wrap_around = true;
                    break;  
                }
                return false;
            }
        } else {
            if (numbers[i] <= numbers[i-1]) {
                continue;
            } else {
                if (first_number == numbers[i]) {
                    continue_index = i + 1;
                    wrap_around_number = numbers[i];
                    check_wrap_around = true;
                    break;  
                }
                return false;
            }
        }
    }

    if (check_wrap_around) {
        for (int i = continue_index; i < numbers.size(); i++) {
            if (numbers[i] == wrap_around_number) {
                continue;
            }
            return false;
        }
    }

    return true;
}

// Main function
int main(){
    // Uncomment one of these lines and make sure you get the result at the right. 
    
    std::vector<int> myvec = {1, 2, 5, 4, 3};  // Yes
    // std::vector<int> myvec = {1, 1, 1, 1, 1};  // Yes
    // std::vector<int> myvec = {3, 4, 5, 2, 2};  // Yes
    // std::vector<int> myvec = {3, 4, 5, 2, 4};  // No
    // std::vector<int> myvec = {1, 2, 3, 4, 5};  // Yes
    // std::vector<int> myvec = {1, 2, 3, 1, 2};  // No
    // std::vector<int> myvec = {5, 4, 6, 2, 6};  // No
    // std::vector<int> myvec = {5, 4, 3, 2, 1};  // Yes
    // std::vector<int> myvec = {5, 4, 3, 2, 6};  // Yes
    // std::vector<int> myvec = {5, 4, 6, 5, 4};  // No
    // std::vector<int> myvec = {5, 4, 6, 5};  // Yes
    // std::vector<int> myvec = {5, 4, 6, 5, 5};  // Yes

    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic." : "No, it is not bitonic.");
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
