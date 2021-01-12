/*
 * Tetris.cpp
 */

#include <Arduino.h>
#include "Tetris.h"
#include "minos.h"

/*
 * コンストラクタ
 */
Tetris::Tetris(){}

/*
 * ランダムにミノを1つ選択する
 */
void Tetris::selectMino(TET_MINO mino_type_){
	this->mino_type = mino_type_;
	mino_pos_x = 0;

	switch(mino_type){
		case TET_MINO::I:
			setMino_I(mino,rotation_num);
			break;

		case TET_MINO::O:
			setMino_O(mino,rotation_num);
			break;

		case TET_MINO::S:
			setMino_S(mino,rotation_num);
			break;

		case TET_MINO::Z:
			setMino_Z(mino,rotation_num);
			break;

		case TET_MINO::J:
			setMino_J(mino,rotation_num);
			break;

		case TET_MINO::L:
			setMino_L(mino,rotation_num);
			break;

		case TET_MINO::T:
			setMino_T(mino,rotation_num);
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
	rotation_num += 1;
	rotation_num %= 4;

	mino_pos_x = 0;
	switch (mino_type){
			case TET_MINO::I:
			setMino_I(mino, rotation_num);
			break;

		case TET_MINO::O: // Oミノは回転しない。
			return;

		case TET_MINO::S:
			setMino_S(mino, rotation_num);
			break;

		case TET_MINO::Z:
			setMino_Z(mino, rotation_num);
			break;

		case TET_MINO::J:
			setMino_J(mino, rotation_num);
			break;

		case TET_MINO::L:
			setMino_L(mino, rotation_num);
			break;

		case TET_MINO::T:
			setMino_T(mino, rotation_num);
			break;
	}

	for (size_t i = 0; i < drop_num; i++){
		dropMino(false);
		if (hasLandedMino()){
			break;
		}
	}

	return; // TODO:実装
}

/*
 * ミノを横に移動させる
 * 	引数が正 : 右に1つ移動
 * 	引数が負 : 左に1つ移動
 */
void Tetris::transMino(int pos){
	int direction = pos - mino_pos_x;
	while (direction != 0){ // 指定した位置に移動するまでループ
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
			mino_pos_x += 1;
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
			mino_pos_x -= 1;
		}
		direction = pos - mino_pos_x;
	}
}

/*
 * ミノを落とす
 */
void Tetris::dropMino(bool is_count){
	for(int i=0; i < Tetris::NUM_ROW; i++){
		for(int j=NUM_CELL-1; j > 0; j--){
			mino[i][j] >>= 1;
			mino[i][j] |= (mino[i][j-1] & 0B00000001) << NUM_COL-1; 
		}
		mino[i][0] >>= 1;
	}

	if (is_count){
		drop_num += 1;
	}

}

/*
 * backgroudを一つ下げる
 */
void Tetris::dropBG(){
	for(int i=0; i < Tetris::NUM_ROW; i++){
		for(int j=NUM_CELL-1; j > 0; j--){
			background[i][j] >>= 1;
			background[i][j] |= (background[i][j-1] & 0B00000001) << NUM_COL-1; 
		}
		background[i][0] >>= 1;
	}
}

/*
 * ミノが着地しているか
 */
bool Tetris::hasLandedMino(){
	//既に底にミノがある場合
	for (int i = 0; i < NUM_ROW; i++){
		if((mino[i][NUM_CELL-1] & 0B00000001) > 0) {
			drop_num = 0;
			rotation_num = 0;
			return true;
		}
	}
	

	uint8_t mino_next[NUM_ROW][NUM_CELL];//1段落ちた場合のミノ

	for(int i=0; i < NUM_ROW; i++){
		for (int j = 0; j < NUM_CELL; j++){
			mino_next[i][j] = mino[i][j] >> 1;
			if(j != 0){
				mino_next[i][j] |= (mino[i][j-1] & 0B00000001) << NUM_COL-1;
			}
		}
	}

	//mino_nextとbackgroundが干渉した場合はtrueを返す。
	for(int i=0; i < NUM_ROW; i++){
		for(int j=0; j < NUM_CELL; j++){
			if((background[i][j] & mino_next[i][j]) != 0B00000000){
				drop_num = 0;
				rotation_num = 0;
				return true;
			} 
		}
	}
	return false;
}

/*
 * minoをbackgroundに移す
 */
void Tetris::putMino(){
	for (int i = 0; i < Tetris::NUM_ROW; i++){
		for (int j = 0; j < Tetris::NUM_CELL; j++){
			background[i][j] |= mino[i][j];
			mino[i][j] = 0B00000000;	
		}
	}
	
}

/*
 * 横一列を消す
 */
bool Tetris::deleteLine(){
	for (int j = 0; j < NUM_CELL; j++){	
		uint8_t mask = 0B1000000;
		while (mask > 0){
			for (int i = 0; i < NUM_ROW; i++){
				if((mask & background[i][j]) == 0B00000000){
					break;
				}

				// 一列削除する
				// background[][j]のmaskの位置を消す。
				if(i == NUM_ROW-1){
					//動かさないところを保存しておく
					uint8_t save[NUM_ROW][NUM_CELL];
					for (int t = 0; t < NUM_CELL; t++){
						for (int y = 0; y < NUM_ROW; y++){
							if(j > t){ // 消す列より上の部分
								save[y][t] = 0B00000000;
							}else if(j < t){ //消す列より下の部分
								save[y][t] = background[y][t];
								background[y][t] = 0B00000000;
							}else{ //マスクを使う部分
								save[y][t] = background[y][t] & (mask - 1);
								background[y][t] &= ~((mask - 1) << 1);
							}
						}
					}

					//一段下げる
					dropBG();

					// saveとbackgroundを合わせる
					for (int t = 0; t < NUM_CELL; t++){
						for (int y = 0; y < NUM_ROW; y++){
							background[y][t] |= save[y][t];
						}
					}
					
					return true;
				}
			}
			mask >>= 1;
		}
		
	}
	

	return false;
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

/*
 * minoを初期化
 */
void Tetris::reset(){
	for (int i = 0; i < Tetris::NUM_ROW; i++){
		for (int j = 0; j < Tetris::NUM_CELL; j++){
			mino[i][j] = 0B00000000;
			background[i][j] = 0B00000000;
			led_pattern[i][j] = 0B00000000;
		}
	}
}
