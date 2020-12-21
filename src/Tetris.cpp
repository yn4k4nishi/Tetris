/*
 * Tetris.cpp
 */

#include <Arduino.h>
#include "Tetris.h"
#include "minos.h"

Tetris::Tetris(){}

/*
 * ランダムにミノを1つ選択する
 */
Tetris::selectMino(TET_MINO mino){
	switch(mino){
		case TET_MINO::I:
			setMino_I(&mino);
			break;

		case TET_MINO::O:
			setMino_O(&mino);
			break;

		case TET_MINO::S:
			setMino_S(&mino);
			break;

		case TET_MINO::Z:
			setMino_Z(&mino);
			break;

		case TET_MINO::J:
			setMino_J(&mino);
			break;

		case TET_MINO::L:
			setMino_L(&mino);
			break;

		case TET_MINO::T:
			setMino_T(&mino);
			break;
	}
}

/*
 * ゲームが終了か判定する
 */
Tetris::isGameOver(){
	uint8_t deadline[NUM_ROW][NUM_CELL] = {
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 0
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 1
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 2
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 3
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 4
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 5
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 6
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }  // Line 7
        };

	for(int i=0; i < NUM_ROW; i++){
		for(int j=0; j < NUM_CELL; j++){
			if(background[i][j] & deadline[i][j] > 0){
				return true;
			}
		}
	}

	return false;
}

/*
 * ミノを回転させる
 */
Tetris::rotateMino(){
	return; // TODO:実装
}

/*
 * ミノを横に移動させる
 * 	引数が正 : 右に1つ移動
 * 	引数が負 : 左に1つ移動
 */
Tetris::transMino(int direction){
	if(direction > 0){ //右に移動
		for(int i=0; i < NUM_CELL; i++)
			if(mino[0][i] > 0) return; //右端にある場合は移動できない
	
		for(int i=0; i < NUM_ROW-1; i++){
			for(int j=0; j < NUM_CELL; j++){
				mino[i][j] = mino[i+1][j];
			}
		}
		for(int j=0; j < NUM_CELL; j++){
			mino[NUM_ROW-1][j] = 0B00000000;
		}
	} else 
	if(direction < 0){ //左に移動
		for(int i=0; i < NUM_CELL; i++)
			if(mino[NUM_ROW-1][i] > 0) return; //左端にある場合は移動できない
	
		for(int i = NUM_ROW-1; i > 0; i--){
			for(int j=0; j < NUM_CELL; j++){
				mino[i][j] = mino[i-1][j];
			}
		}
		for(int j=0; j < NUM_CELL; j++){
			mino[0][j] = 0B00000000;
		}
	} else 
	
}
