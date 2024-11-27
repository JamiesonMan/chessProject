#include <iostream>
#include <string>
#include <stdexcept>
#include "Pieces.hpp"

class Board {
public:
    Board() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                board[i][j] = new Piece(0, 0, 0, 0);
            }
        }
    }

    Board(std::string FEN) {
        int row = 0, col = 0;
        for (size_t i = 0; i < FEN.find(" "); ++i) {


            if (FEN[i] == 'r') {
                board[row][col++] = new Piece(4, 16, row, col); // Black Rook
            } else if (FEN[i] == 'n') {
                board[row][col++] = new Piece(2, 16, row, col); // Black Knight
            } else if (FEN[i] == 'b') {
                board[row][col++] = new Piece(3, 16, row, col); // Black Bishop
            } else if (FEN[i] == 'q') {
                board[row][col++] = new Piece(5, 16, row, col); // Black Queen
            } else if (FEN[i] == 'k') {
                board[row][col++] = new Piece(6, 16, row, col); // Black King
            } else if (FEN[i] == 'p') {
                board[row][col++] = new Piece(1, 16, row, col); // Black Pawn
            } else if (FEN[i] == 'R') {
                board[row][col++] = new Piece(4, 8, row, col); // White Rook
            } else if (FEN[i] == 'N') {
                board[row][col++] = new Piece(2, 8, row, col); // White Knight
            } else if (FEN[i] == 'B') {
                board[row][col++] = new Piece(3, 8, row, col); // White Bishop
            } else if (FEN[i] == 'Q') {
                board[row][col++] = new Piece(5, 8, row, col); // White Queen
            } else if (FEN[i] == 'K') {
                board[row][col++] = new Piece(6, 8, row, col); // White King
            } else if (FEN[i] == 'P') {
                board[row][col++] = new Piece(1, 8, row, col); // White Pawn
            } else if (FEN[i] == '/') {
                ++row;
                col = 0;
            } else if (std::isdigit(FEN[i])) {
                int num = FEN[i] - '0';
                while(num != 0){
                    board[row][col++] = new Piece();
                    num--; 
                }
            } else {
                throw std::invalid_argument("Invalid FEN character");
            }

            if (row >= 8 || col > 8) {
                throw std::out_of_range("FEN string out of bounds");
            }
        }
    }

    Piece* getPieceAt(int row, int col){
        if (row >= 8 || col >= 8) throw std::out_of_range("Index out of bounds");
        return board[row][col];
    }

    void printBoard(){
        bool squareColor = true;
    
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                char type = (board[i][j])->getPieceType();
                char color = (board[i][j])->getPieceColor();
                int currCoordY = 8 - i;
                if(color == 'W'){
                    type = std::toupper(type);
                }

                if(j == 0){
                    if(type == 'x' && squareColor == false){
                        std::cout << currCoordY << " |  " << " " << "  ";
                    } else {
                        std::cout << currCoordY << " |  " << type << "  ";
                    }
                    
                } else {
                    if(type == 'x' && squareColor == false){
                        std::cout << " " << "  ";
                    } else {
                        std::cout << type << "  ";
                    }
                    
                }

                if(squareColor){
                    squareColor = false;
                } else {
                    squareColor = true;
                }
            }
        if(squareColor){
            squareColor = false;
        } else {
            squareColor = true;
        }
        std::cout << std::endl;
        }
        std::cout << "    ________________________" << std::endl;
        std::cout << "     a  b  c  d  e  f  g  h" << std::endl;
        
    }
    
private:
    Piece* board[8][8];
};
