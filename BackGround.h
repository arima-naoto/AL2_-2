#pragma once
#include "GameObject.h"
//ヘッダーファイル読み込み

//BackGroundクラスを作成
class BackGround : public GameObject
{
public://メンバ関数の宣言

	/// <summary>
	/// コンストラクタの作成
	/// </summary>
	BackGround();

	/// <summary>
	/// 更新処理用のメンバ関数Updateを作成
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理用のメンバ関数Drawを作成
	/// </summary>
	void Draw();

public://メンバ変数の作成

	int BlockSize;//MapChip用のメンバ変数

};
