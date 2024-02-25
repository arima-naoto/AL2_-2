#pragma once
#include "MyStruct.h"
//ヘッダーファイル読み込み

//GameObjectクラスの作成
class GameObject 
{

public://メンバ変数の作成
	Vector2 position_;
	Vector2 Rand;
	float radius_;
	unsigned int color_;

	int isShake;
	int ShakeTimer;
};