/*
 * Tetris.h
 */

#ifndef TETRIS
#define TETRIS

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
}

#endif
