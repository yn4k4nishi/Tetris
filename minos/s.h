#include "Tetris.h"

void setMino_S0(uint8_t pattern[][Tetris::NUM_CELL]){
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

void setMino_S1(uint8_t pattern[][Tetris::NUM_CELL]){
	uint8_t mino_[Tetris::NUM_ROW][Tetris::NUM_CELL] = {
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 0
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 1
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 2
                { 0B01100000, 0B00000000, 0B00000000, 0B00000000 }, // Line 3
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

void setMino_S2(uint8_t pattern[][Tetris::NUM_CELL]){
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

void setMino_S3(uint8_t pattern[][Tetris::NUM_CELL]){
	uint8_t mino_[Tetris::NUM_ROW][Tetris::NUM_CELL] = {
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 0
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 1
                { 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 2
                { 0B01100000, 0B00000000, 0B00000000, 0B00000000 }, // Line 3
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
