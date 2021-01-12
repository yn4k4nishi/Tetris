/*
 * minos.h
 */

#include "Tetris.h"

void setMino_I(uint8_t pattern[][Tetris::NUM_CELL]){
	uint8_t mino_[Tetris::NUM_ROW][Tetris::NUM_CELL] = {
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 0
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 1
                { 0B01000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 2
                { 0B01000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 3
                { 0B01000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 4
                { 0B01000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 5
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 6
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }  // Line 7
        };

	for(int i=0; i < Tetris::NUM_ROW; i++){
		for(int j=0; j < Tetris::NUM_CELL; j++){
			pattern[i][j] = mino_[i][j]; 
		}
	}

}

void setMino_O(uint8_t pattern[][Tetris::NUM_CELL]){
	uint8_t mino_[Tetris::NUM_ROW][Tetris::NUM_CELL] = {
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 0
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 1
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 2
                { 0B11000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 3
                { 0B11000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 4
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 5
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 6
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }  // Line 7
        };

	for(int i=0; i < Tetris::NUM_ROW; i++){
		for(int j=0; j < Tetris::NUM_CELL; j++){
			pattern[i][j] = mino_[i][j]; 
		}
	}

}

void setMino_S(uint8_t pattern[][Tetris::NUM_CELL]){
	uint8_t mino_[Tetris::NUM_ROW][Tetris::NUM_CELL] = {
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 0
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 1
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 2
                { 0B10000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 3
                { 0B11000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 4
                { 0B01000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 5
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 6
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }  // Line 7
        };

	for(int i=0; i < Tetris::NUM_ROW; i++){
		for(int j=0; j < Tetris::NUM_CELL; j++){
			pattern[i][j] = mino_[i][j]; 
		}
	}

}

void setMino_Z(uint8_t pattern[][Tetris::NUM_CELL]){
	uint8_t mino_[Tetris::NUM_ROW][Tetris::NUM_CELL] = {
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 0
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 1
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 2
                { 0B01000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 3
                { 0B11000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 4
                { 0B10000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 5
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 6
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }  // Line 7
        };

	for(int i=0; i < Tetris::NUM_ROW; i++){
		for(int j=0; j < Tetris::NUM_CELL; j++){
			pattern[i][j] = mino_[i][j]; 
		}
	}

}
void setMino_J(uint8_t pattern[][Tetris::NUM_CELL]){
	uint8_t mino_[Tetris::NUM_ROW][Tetris::NUM_CELL] = {
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 0
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 1
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 2
                { 0B01000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 3
                { 0B01000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 4
                { 0B11000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 5
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 6
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }  // Line 7
        };

	for(int i=0; i < Tetris::NUM_ROW; i++){
		for(int j=0; j < Tetris::NUM_CELL; j++){
			pattern[i][j] = mino_[i][j]; 
		}
	}

}

void setMino_L(uint8_t pattern[][Tetris::NUM_CELL]){
	uint8_t mino_[Tetris::NUM_ROW][Tetris::NUM_CELL] = {
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 0
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 1
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 2
                { 0B11000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 3
                { 0B01000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 4
                { 0B01000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 5
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 6
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }  // Line 7
        };

	for(int i=0; i < Tetris::NUM_ROW; i++){
		for(int j=0; j < Tetris::NUM_CELL; j++){
			pattern[i][j] = mino_[i][j]; 
		}
	}

}

void setMino_T(uint8_t pattern[][Tetris::NUM_CELL]){
	uint8_t mino_[Tetris::NUM_ROW][Tetris::NUM_CELL] = {
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 0
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 1
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 2
                { 0B01000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 3
                { 0B11000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 4
                { 0B01000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 5
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 6
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }  // Line 7
        };

	for(int i=0; i < Tetris::NUM_ROW; i++){
		for(int j=0; j < Tetris::NUM_CELL; j++){
			pattern[i][j] = mino_[i][j]; 
		}
	}

}
