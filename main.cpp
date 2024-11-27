#include "Board.hpp"

#define MAX_COL 8
#define MAX_ROW 8
// Creating the base game utilizing a 2D array

int main(void){

    // start: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR
    
    Board board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR ");
    //std::bitset<5> currPiece = *(board.getPieceAt(3, 1))->getPiece();
    
    board.printBoard();

    return 0;
}