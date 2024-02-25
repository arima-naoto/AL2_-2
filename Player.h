#pragma once
#include "MyStruct.h"
#include "Bullet.h"
#include "Easing.h"
#include "GameObject.h"
//ヘッダーファイル読み込み

class Player:public GameObject//Playerクラスの作成
{
public:
	/// <summary>
	///コンストラクタの作成
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="speed"></param>
	/// <param name="radius"></param>
	Player(Vector2 pos,float speed,float radius);

	/// <summary>
	///デストラクタの作成 
	/// </summary>
	~Player();

	/// <summary>
	/// Player用のメンバ関数
	/// </summary>
	/// <param name="keys"></param>
	void Update(char *keys);

	/// <summary>
	/// シーンごとの更新処理用のメンバ関数を作成
	/// </summary>
	void Scene1Update();//SCENE1用
	void Scene2Update();//SCENE2用
	void Scene3Update();//SCENE3用

	/// <summary>
	/// シーンごとの描画処理用のメンバ関数を作成
	/// </summary>
	void Scene1Draw();//SCENE1用
	void Scene2Draw();//SCENE2用
	void Scene3Draw();//SCENE3用

public://メンバ変数の作成 

	//Bulletクラスの包含
	Bullet* bullet[MAX] , * bullet2[MAX2], * bullet3[MAX3],*bullet4[MAX4];

	//Easeクラスの包含
	Ease* ease;

	float speed_;

	int MouseCarsolX;
	int MouseCarsolY;
	float t;
	int isMove;

	int R;
	int G;
	int B;
	int Alpha;
};

