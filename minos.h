/*
 * minos.h
 */

#include "Tetris.h"
#include "minos/i.h"
#include "minos/s.h"
#include "minos/z.h"
#include "minos/j.h"
#include "minos/l.h"
#include "minos/t.h"

void setMino_I(uint8_t pattern[][Tetris::NUM_CELL], int rotation_num){
        switch (rotation_num){
        case 0:
                setMino_I0(pattern);
                break;
        case 1:
                setMino_I1(pattern);
                break;
        case 2:
                setMino_I2(pattern);
                break;
        case 3:
                setMino_I3(pattern);
                break;
        }
}

void setMino_O(uint8_t pattern[][Tetris::NUM_CELL], int rotation_num){
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

void setMino_S(uint8_t pattern[][Tetris::NUM_CELL], int rotation_num){
        switch (rotation_num){
        case 0:
                setMino_S0(pattern);
                break;
        case 1:
                setMino_S1(pattern);
                break;
        case 2:
                setMino_S2(pattern);
                break;
        case 3:
                setMino_S3(pattern);
                break;
        }
}

void setMino_Z(uint8_t pattern[][Tetris::NUM_CELL], int rotation_num){
        switch (rotation_num){
        case 0:
                setMino_Z0(pattern);
                break;
        case 1:
                setMino_Z1(pattern);
                break;
        case 2:
                setMino_Z2(pattern);
                break;
        case 3:
                setMino_Z3(pattern);
                break;
        }
}
void setMino_J(uint8_t pattern[][Tetris::NUM_CELL], int rotation_num){
	switch (rotation_num){
        case 0:
                setMino_J0(pattern);
                break;
        case 1:
                setMino_J1(pattern);
                break;
        case 2:
                setMino_J2(pattern);
                break;
        case 3:
                setMino_J3(pattern);
                break;
        }
}

void setMino_L(uint8_t pattern[][Tetris::NUM_CELL], int rotation_num){
	switch (rotation_num){
        case 0:
                setMino_L0(pattern);
                break;
        case 1:
                setMino_L1(pattern);
                break;
        case 2:
                setMino_L2(pattern);
                break;
        case 3:
                setMino_L3(pattern);
                break;
        }
}

void setMino_T(uint8_t pattern[][Tetris::NUM_CELL], int rotation_num){
	switch (rotation_num){
        case 0:
                setMino_T0(pattern);
                break;
        case 1:
                setMino_T1(pattern);
                break;
        case 2:
                setMino_T2(pattern);
                break;
        case 3:
                setMino_T3(pattern);
                break;
        }
}
