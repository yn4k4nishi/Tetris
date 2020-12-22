/*
 * Tetris.h
 */

#ifndef TETRIS
#define TETRIS

enum TET_MINO{
	I = 1,
	O = 2,
	S = 3,
	Z = 4,
	J = 5,
	L = 6,
	T = 7
};

class Tetris{
public:
	Tetris();
	
	void selectMino(TET_MINO); // ランダムにミノを1つ選択する
	bool isGameOver();         // ゲーム終了か判定する
	void rotateMino();         // ミノを回転させる
	void transMino(int);       // ミノを横に移動させる
	void dropMino();           // ミノを落とす
	bool hasLandedMino();      // ミノが着地しているか
	void deleteLine();         // 横一列を消す
	void setPattern();         // minoとbackgroundをled_patternに合わせる

	static const int NUM_ROW  = 8;
	static const int NUM_COL  = 8;
	static const int NUM_CELL = 4;

	uint8_t led_pattern[NUM_ROW][NUM_CELL];

private:
	uint8_t mino[NUM_ROW][NUM_CELL] = {
		{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 0
	 	{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 1
 	 	{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 2
 	 	{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 3
  		{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 4
  		{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 5
  		{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 6
  		{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }  // Line 7
	};

	uint8_t background[NUM_ROW][NUM_CELL] = {
		{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 0
		{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 1
		{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 2
 	 	{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 3
  		{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 4
  		{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 5
  		{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }, // Line 6
  		{ 0B00000000, 0B00000000, 0B00000000, 0B00000000 }  // Line 7
	};
};

#endif
