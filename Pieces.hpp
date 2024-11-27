#include <iostream>
#include <string>
#include <bitset>

const int SIZE = 5;

class Piece {
    
    // We define a piece as a 5 bit number, first 2 bits are 01 for black 10 for white. Last 3 are for different types of pieces.
        
    private:
        // 00 000 Most significant 2 bits are for color. Least significant 3 bits are for piece type.
        std::bitset<SIZE> piece = 0b00000;

        const int none = 0;
        const int pawn = 1;
        const int knight = 2;
        const int bishop = 3;
        const int rook = 4;
        const int queen = 5;
        const int king = 6;

        const int white = 8;
        const int black = 16;

        int positionRow;
        int positionCol;

    public:
        Piece(){
            piece = 0b00000;
            positionRow = -1;
            positionCol = -1;
        }

        Piece(std::bitset<SIZE> type, std::bitset<SIZE> color, int x, int y){
            piece |= color;
            piece |= type;
            positionRow = x;
            positionCol = y;
        }

        std::bitset<SIZE>* getPiece(){
            return &piece;
        }

        char getPieceType(){
            std::bitset<SIZE> typePiece = piece << 2;
            typePiece = typePiece >> 2;
            
            if(typePiece.to_ullong() == pawn){
                return 'p';
            } else if (typePiece.to_ullong() == knight){
                return 'n';
            } else if (typePiece.to_ullong() == bishop){
                return 'b';
            } else if (typePiece.to_ullong() == rook){
                return 'r';
            } else if (typePiece.to_ullong() == queen){
                return 'q';
            } else if (typePiece.to_ullong() == king){
                return 'k';
            } else {
                return 'x';
            }
        }

        char getPieceColor(){
             if(piece[4]){ // look at the 4th bit
                return 'b';
            } else if (piece[3]) { // look at the 3rd bit
                return 'W';
            } else {
                return 'x';
            }
        }

};
