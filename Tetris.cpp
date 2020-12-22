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
void Tetris::selectMino(TET_MINO mino_type){
	switch(mino_type){
		case TET_MINO::I:
			setMino_I(&Tetris::mino[Tetris::NUM_ROW]);
			break;

		case TET_MINO::O:
			setMino_O(&Tetris::mino[Tetris::NUM_ROW]);
			break;

		case TET_MINO::S:
			setMino_S(&Tetris::mino[Tetris::NUM_ROW]);
			break;

		case TET_MINO::Z:
			setMino_Z(&Tetris::mino[Tetris::NUM_ROW]);
			break;

		case TET_MINO::J:
			setMino_J(&Tetris::mino[Tetris::NUM_ROW]);
			break;

		case TET_MINO::L:
			setMino_L(&Tetris::mino[Tetris::NUM_ROW]);
			break;

		case TET_MINO::T:
			setMino_T(&Tetris::mino[Tetris::NUM_ROW]);
			break;
	}
}

/*
 * ゲームが終了か判定する
 */
bool Tetris::isGameOver(){
	uint8_t deadline[Tetris::NUM_ROW][Tetris::NUM_CELL] = {
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 0
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 1
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 2
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 3
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 4
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 5
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }, // Line 6
                { 0B00000001, 0B00000000, 0B00000000, 0B00000000 }  // Line 7
        };

	for(int i=0; i < Tetris::NUM_ROW; i++){
		for(int j=0; j < Tetris::NUM_CELL; j++){
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
void Tetris::rotateMino(){
	return; // TODO:実装
}

/*
 * ミノを横に移動させる
 * 	引数が正 : 右に1つ移動
 * 	引数が負 : 左に1つ移動
 */
void Tetris::transMino(int direction){
	if(direction > 0){ //右に移動
		for(int i=0; i < Tetris::NUM_CELL; i++)
			if(mino[0][i] > 0) return; //右端にある場合は移動できない
	
		for(int i=0; i < Tetris::NUM_ROW-1; i++){
			for(int j=0; j < Tetris::NUM_CELL; j++){
				mino[i][j] = mino[i+1][j];
			}
		}
		for(int j=0; j < Tetris::NUM_CELL; j++){
			mino[Tetris::NUM_ROW-1][j] = 0B00000000;
		}
	} else 
	if(direction < 0){ //左に移動
		for(int i=0; i < Tetris::NUM_CELL; i++)
			if(mino[Tetris::NUM_ROW-1][i] > 0) return; //左端にある場合は移動できない
	
		for(int i = Tetris::NUM_ROW-1; i > 0; i--){
			for(int j=0; j < Tetris::NUM_CELL; j++){
				mino[i][j] = mino[i-1][j];
			}
		}
		for(int j=0; j < Tetris::NUM_CELL; j++){
			mino[0][j] = 0B00000000;
		}
	}
}

/*
 * ミノを落とす
 */
void Tetris::dropMino(){
	for(int i=0; i < Tetris::NUM_ROW; i++){
		uint8_t t = 0B00000000;
		for(int j=0; j < Tetris::NUM_CELL; j++){
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
bool Tetris::hasLandedMino(){
	uint8_t mino_after[Tetris::NUM_ROW][Tetris::NUM_CELL];

	for(int i=0; i < Tetris::NUM_ROW; i++){
		uint8_t t = 0B00000000;
		for(int j=0; j < Tetris::NUM_CELL; j++){
			t = 0B00000001 & mino[i][j];  
			
			mino_after[i][j] = mino[i][j] >> 1;
			
			if( j>0 && t>0 ){
				mino_after[i][j] |= 0B10000000;
			}
		}
	}

	for(int i=0; i < Tetris::NUM_ROW; i++){
		for(int j=0; j < Tetris::NUM_CELL; j++){
			if(mino[i][j] & mino_after[i][j] > 0) return true;
		}
	}
	return false;
}

/*
 * 横一列を消す
 */
void Tetris::deleteLine(){
	uint8_t masks[Tetris::NUM_CELL] = { 0B11111111, 0B11111111, 0B11111111, 0B11111111};
	for (int j = 0; j < Tetris::NUM_CELL; j++){
		uint8_t m = 0B10000000;
		while (m > 0){
			for (int i = 0; i < Tetris::NUM_ROW; i++){
				if( m & background[i][j] < 1){
					m >>= 1;
					masks[j] >>= 1;
					break;
				}

				if (i == Tetris::NUM_ROW - 1){ // 横一列を削除
					uint8_t tmp [Tetris::NUM_ROW][Tetris::NUM_CELL]; 
					// 削除される行より下を保存
					for (int i = 0; i < Tetris::NUM_ROW; i++){
						for (int j = 0; j < Tetris::NUM_CELL; j++){
							tmp[i][j] = background[i][j] & masks[j];
						}
					}
					// 全体を1段下げる
					dropMino();

					// masksの0と1の反転したマスク
					uint8_t reverse[Tetris::NUM_CELL];
					for (int i = 0; i < Tetris::NUM_CELL; i++){
						reverse[i] = ~masks[i];
					}
					
					// 1段下げた行と保存した行を合わせる
					for (int i = 0; i < Tetris::NUM_ROW; i++){
						for (int j = 0; j < Tetris::NUM_CELL; j++){
							background[i][j] &= reverse[j];
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
void Tetris::setPattern(){
	for (int i = 0; i < Tetris::NUM_ROW; i++){
		for (int j = 0; j < Tetris::NUM_CELL; j++){
			led_pattern[i][j] = mino[i][j] | background[i][j];
		}
	}
}

