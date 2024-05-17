// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

struct chess_position {
    char row;
    int column;
};

bool valid_position(chess_position position) {
    bool good_row = position.row > 64 && position.row < 73 ? true : false;
    bool good_column = position.column > 0 && position.column < 9 ? true : false;
    return good_row && good_column;
}

void add_position(std::vector<chess_position> &moves, chess_position knight, int i, int j) {
    chess_position position = {knight.row + i, knight.column + j};
    if (valid_position(position)) {
        moves.push_back(position);
    } 
}

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<chess_position> knight_moves(chess_position knight){
    std::vector<chess_position> moves;

    for (int i = -2; i < 3; i++) {
        if (i == 0) {
            continue;
        }

        if (i == -2 || i == 2) {
            for (int j = -1; j < 2; j++) {
                if (j == 0) {
                    continue;
                }
                add_position(moves, knight, i, j);
            }
        } else {
            for (int j = -2; j < 3; j += 2) {
                if (j == 0) {
                    continue;
                }
                add_position(moves, knight, i, j);
            } 
        }
    }

    return moves;
}

// Main function
int main(){
    chess_position knight;
    
    std::cout << "Enter the row of the knight: " << std::flush;
    std::cin >> knight.row;

    std::cout << "Enter the column of the knight: " << std::flush;
    std::cin >> knight.column;

    std::vector<chess_position> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight.row << knight.column << ": ";

    for (auto element : the_moves)
        std::cout << element.row << element.column << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}