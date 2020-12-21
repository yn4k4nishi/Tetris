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
	}
}

/*
 * ミノを落とす
 */
Tetris::dropMino(){
	for(int i=0; i < NUM_ROW; i++){
		uint8_t t = 0B00000000;
		for(int j=0; j < NUM_CELL; j++){
			t = 0B00000001 & mino[i][j];  
			
			mino[i][j] >>= 1;
			
			if( j>0 && t>0 ){
				mino[i][j] |= 0B10000000;
			}
		}
	}
}

/*
 * ミノが着地しているか
 */
Tetris::hasLandedMino(){
	uint8_t mino_after[NUM_ROW][NUM_CELL];

	for(int i=0; i < NUM_ROW; i++){
		uint8_t t = 0B00000000;
		for(int j=0; j < NUM_CELL; j++){
			t = 0B00000001 & mino[i][j];  
			
			mino_after[i][j] = mino[i][j] >> 1;
			
			if( j>0 && t>0 ){
				mino_after[i][j] |= 0B10000000;
			}
		}
	}

	for(int i=0; i < NUM_ROW; i++){
		for(int j=0; j < NUM_CELL; j++){
			if(mino[i][j] & mino_after[i][j] > 0) return true;
		}
	}
	return false;
}

/*
 * 横一列を消す
 */
Tetris::deleteLine(){
	uint8_t masks[NUM_CELL] = { 0B11111111, 0B11111111, 0B11111111, 0B11111111};
	for (int j = 0; j < NUM_CELL; j++){
		uint8_t m = 0B10000000;
		while (m > 0){
			for (int i = 0; i < NUM_ROW; i++){
				if( m & background[i][j] < 1){
					m >>= 1;
					masks[j] >>= 1;
					break;
				}

				if (i == NUM_ROW - 1){ // 横一列を削除
					unit8_t tmp [NUM_ROW][NUM_CELL]; 
					// 削除される行より下を保存
					for (int i = 0; i < NUM_ROW; i++){
						for (int j = 0; j < NUM_CELL; j++){
							tmp[i][j] = background[i][j] & masks[j];
						}
					}
					// 全体を1段下げる
					dropMino();

					// masksの0と1の反転したマスク
					uint8_t reverse[NUM_CELL];
					for (int i = 0; i < NUM_CELL; i++){
						reverse[i] = ~masks[i];
					}
					
					// 1段下げた行と保存した行を合わせる
					for (int i = 0; i < NUM_ROW; i++){
						for (int j = 0; j < NUM_CELL; j++){
							background[i][j] &= reverse[i][j];
							background[i][j] |= tmp[i][j];
						}
					}
					
					m >>= 1;
					masks[j] >>= 1;
				}
				
			}
			
		}
	}
}

/*
 * minoとbackgroundをled_patternに合わせる
 */
Tetris::setPattern(){
	for (int i = 0; i < NUM_ROW; i++){
		for (int j = 0; j < NUM_CELL; j++){
			led_pattern[i][j] = mino[i][j] | background[i][j];
		}
	}
}

