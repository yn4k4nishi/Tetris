#include "Tetris.h"
#include "MaxMatrix2.h"

//-----------------------------------------------------------------------------
// Aruduino pin numbers
//-----------------------------------------------------------------------------
const int DATA_PIN = 8 ;
const int LOAD_PIN = 9 ;
const int CLOCK_PIN = 10 ;

//-----------------------------------------------------------------------------
// Tetris setup
//-----------------------------------------------------------------------------
Tetris tetris = Tetris();

//-----------------------------------------------------------------------------
// MaxMatrix2 setup
//-----------------------------------------------------------------------------
byte* Address[ MaxMatrix2::NROW ] = {
  &tetris.led_pattern[0][0], &tetris.led_pattern[1][0], &tetris.led_pattern[2][0], &tetris.led_pattern[3][0],
  &tetris.led_pattern[4][0], &tetris.led_pattern[5][0], &tetris.led_pattern[6][0], &tetris.led_pattern[7][0],
};

const int NCELL = 4 ;
MaxMatrix2 Ledmx( DATA_PIN, LOAD_PIN, CLOCK_PIN, NCELL, Address ) ;

//-----------------------------------------------------------------------------
// Sketch main
//-----------------------------------------------------------------------------
void setup(){
  pinMode(A4, INPUT_PULLUP); // SU-1203のスイッチ用

  // LED
  Ledmx.clear();
  Ledmx.show();

  randomSeed(analogRead(0)); // ランダム

  Serial.begin(115200); //デバック用
}

//-----------------------------------------------------------------------------
void loop(){
  
  while (!tetris.isGameOver()){
    
    // ランダムにミノを選択
    tetris.selectMino((TET_MINO)random(1,7));
  
    while (!tetris.hasLandedMino()){ // ミノが着地するまで落下

      // スイッチで90度回転
      if(digitalRead(A4)==0){
        tetris.rotateMino();
      }

      // ボリュームで左右に移動
      int volume = analogRead(A0)/102.3 - 5; //10段階に正規化
      tetris.transMino(volume);

      // 1段落とす
      tetris.dropMino();

      // LEDに表示
      tetris.setPattern();
      Ledmx.show();
      
      delay(tetris.interval_ms);
    }
    
    tetris.putMino(); //ミノを固定する

    while(tetris.deleteLine()); //横一列を消す
  }

  while (1){ // 終了した後
    tetris.selectMino((TET_MINO)random(1,7));
    tetris.setPattern();
    Ledmx.show();
    delay(1000);

    if (digitalRead(A4) == 0){
      tetris.reset();
      break;
    }
  }
}

//-----------------------------------------------------------------------------
// Sketch end
//-----------------------------------------------------------------------------
