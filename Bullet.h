#pragma once
#include "MyStruct.h"
#include "GameObject.h"
//ヘッダーファイル読み込み

/// <summary>
/// 固定int型変数の宣言
/// </summary>
const int MAX = 130;
const int MAX2 = 15;
const int MAX3 = 15;
const int MAX4 = 300;

class Bullet:public GameObject//Bulletクラスの作成
{
public:
	/// <summary>
	/// コンストラクタの作成
	/// </summary>
	Bullet();

	/// <summary>
	/// シーンごとの更新処理用メンバ関数を作成
	/// </summary>
	void Scene1Update();//(SCENE1用)
	void Scene2Update();//(SCENE2用)
	void Scene3Update();//(SCENE3用)

	/// <summary>
	/// シーンごとの描画処理用メンバ関数を作成
	/// </summary>
	void Scene1Draw();//(SCENE1用)
	void Scene2Draw();//(SCENE2用)
	void Scene3Draw();//(SCENE3用)

public://メンバ変数の宣言

	//弾が動く速度の宣言
	Vector2 speed_;

	//DEMO2とDEMO3で使う加速度と重力加速度を宣言
	float VelocityY;
	float accelerationY;

	//弾が打たれているかのフラグを宣言する
	int isShot_;
	int isShot2_;
};

