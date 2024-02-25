#pragma once
#include "Player.h"
#include "BackGround.h"
//ヘッダーファイル読み込み

//ChangeSceneクラスを作成
class ChangeScene
{
public:

	/// <summary>
	/// コンストラクタの作成
	/// </summary>
	ChangeScene();

	/// <summary>
	/// デストラクタの作成
	/// </summary>
	~ChangeScene();

	/// <summary>
	/// void型メンバ関数Updateを作成
	/// </summary>
	/// <param name="keys"></param>
	/// <param name="preKeys"></param>
	void Update(char *keys,char *preKeys);

	/// <summary>
	/// void型メンバ関数Drawを作成
	/// </summary>
	void Draw();

	//enum型列挙体GameSceneを宣言し、列挙子を定義する
	enum GameScene {
		SCENE1,
		SCENE2,
		SCENE3,
	};

public:

	//Playerクラスの包含
	Player* player;

	//BackGroundクラスの包含
	BackGround* background;

	//GameScene型変数Sceneを宣言する
	GameScene Scene;

};

