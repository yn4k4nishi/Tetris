/*
 * Tetris.h
 */

#ifndef TETRIS
#define TETRIS

enum class TET_MINO{
	I,O,S,Z,J,L,T
}

class Tetris{
public:
	Tetris();
	
	void selectMino();    // ランダムにミノを1つ選択する
	bool isGameOver();    // ゲーム終了か判定する
	void rotateMino();    // ミノを回転させる
	void transMino();     // ミノを横に移動させる
	void dropMino();      // ミノを落とす
	bool hasLandedMino(); // ミノが着地しているか
	void deleteLine();    // 横一列を消す

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

}

#endif
