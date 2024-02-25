#include "Easing.h"
#define _USE_MATH_DEFINES
#include <math.h>
//ヘッダーファイル読み込み

float Ease::InQuint(float t)//Easeクラスのメンバ関数InQuintを使用し、戻り値を以下の値で設定する 
{
	return t * t * t * t * t;
}

