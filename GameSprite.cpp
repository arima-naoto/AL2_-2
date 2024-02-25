#include "GameSprite.h"
#include "Novice.h"
//ヘッダーファイル読み込み

void GameSpriteDraw() //自作関数GameSpriteDrawを使用し、以下の処理を行う
{
	//int型配列KeyBoradHandleを要素数4で宣言し、LoadTexture関数でキーボード画像を四つ読み込む
	int KeyBoradHandle[4];
	KeyBoradHandle[0] = Novice::LoadTexture("./Resources/UPKey.png");
	KeyBoradHandle[1] = Novice::LoadTexture("./Resources/LeftKey.png");
	KeyBoradHandle[2] = Novice::LoadTexture("./Resources/DownKey.png");
	KeyBoradHandle[3] = Novice::LoadTexture("./Resources/RightKey.png");

	//int型変数GameLetterHandleを宣言し、LoadTexture関数でで文字画像を読み込む
	int GameLetterHandle = Novice::LoadTexture("./Resources/GameLetter.png");

	//DrawSprite関数で、キーボード画像を以下の座標で描画する
	Novice::DrawSprite(1184, 576, KeyBoradHandle[0], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(1136, 624, KeyBoradHandle[1], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(1184, 624, KeyBoradHandle[2], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(1232, 624, KeyBoradHandle[3], 1, 1, 0.0f, WHITE);

	//DrawSprite関数で、文字画像を以下の座標で描画する
	Novice::DrawSprite(1072, 672, GameLetterHandle, 1, 1, 0.0f, WHITE);

}