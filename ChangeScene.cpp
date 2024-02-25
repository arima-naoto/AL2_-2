#include "ChangeScene.h"
#include "Novice.h"
#include "GameSprite.h"
//ヘッダーファイル読み込み

ChangeScene::ChangeScene()//ChangeSceneクラスのコンストラクタを使用し、初期化処理を行う 
{
	Scene = SCENE1;//シーンをSCENE1で初期化する

	player = new Player({ 640.0f,350.0f }, 5, 16);//Playerクラスのインスタンスを作成

	background = new BackGround();//BackGroundクラスのインスタンスを作成
}

ChangeScene::~ChangeScene()//ChangeSceneクラスのデストラクタを使用し、delete処理を行う 
{
	delete player;
	delete background;
}

void ChangeScene::Update(char *keys,char *preKeys) {

	if (keys[DIK_1] && preKeys[DIK_1] == false)//1キーが押された瞬間 
	{
		Scene = SCENE1;//SceneをSCENE1に切り替える

		//SCENE2の初期化
		for (int i = 0; i < MAX2; i++) {
			player->bullet2[i]->isShot_ = false;
			player->bullet2[i]->VelocityY = 0.4f;
		}

		for (int i = 0; i < MAX3; i++) {
			player->bullet3[i]->isShot2_ = false;
			player->bullet3[i]->VelocityY = 0.4f;
		}

		player->isShake = 0;
		player->Rand.x = 0;
		player->Rand.y = 0;
		player->ShakeTimer = 0;

		background->isShake = 0;
		background->Rand.x = 0;
		background->Rand.y = 0;
		background->ShakeTimer = 0;

		//SCENE3の初期化
		for (int i = 0; i < MAX4; i++) {
			player->bullet4[i]->isShot_ = false;
			player->bullet4[i]->VelocityY = 0.4f;
		}
	}

	if (keys[DIK_2] && preKeys[DIK_2] == false)//2キーが押された瞬間 
	{
		Scene = SCENE2;//SceneをSCENE2に切り替える

		//SCENE1の初期化
		for (int i = 0; i < MAX; i++) {
			player->bullet[i]->isShot_ = false;
			player->bullet[i]->color_ = 0x00FF0080;
		}

		if (player->isMove == 1) {
			player->isMove = 0;
			player->t = 0;
		}

		//SCENE3の初期化
		for (int i = 0; i < MAX4; i++) {
			player->bullet4[i]->isShot_ = false;
			player->bullet4[i]->VelocityY = 0.4f;
		}
	}

	if (keys[DIK_3] && preKeys[DIK_3] == false)//3キーが押された瞬間
	{
		Scene = SCENE3;//SceneをSCENE3に切り替える

		//SCENE1の初期化
		for (int i = 0; i < MAX; i++) {
			player->bullet[i]->isShot_ = false;
			player->bullet[i]->color_ = 0x00FF0080;
		}

		if (player->isMove == 1) {
			player->isMove = 0;
			player->t = 0;
		}

		//SCENE2の初期化
		for (int i = 0; i < MAX2; i++) {
			player->bullet2[i]->isShot_ = false;
			player->bullet2[i]->VelocityY = 0.4f;
		}

		for (int i = 0; i < MAX3; i++) {
			player->bullet3[i]->isShot2_ = false;
			player->bullet3[i]->VelocityY = 0.4f;
		}

		player->isShake = 0;
		player->Rand.x = 0;
		player->Rand.y = 0;
		player->ShakeTimer = 0;

		background->isShake = 0;
		background->Rand.x = 0;
		background->Rand.y = 0;
		background->ShakeTimer = 0;
	}

	if (keys[DIK_R] && preKeys[DIK_R] == false)//Rキーが押された瞬間 
	{
		Scene = SCENE1;//SceneをSCENE1に切り替える

		//プレイヤーの座標の初期化
		player->position_.x = 640.0f;
		player->position_.y = 350.0f;

		//SCENE1の初期化
		for (int i = 0; i < MAX; i++) {
			player->bullet[i]->isShot_ = false;
			player->bullet[i]->color_ = 0x00FF0080;
		}

		if (player->isMove == 1) {
			player->isMove = 0;
			player->t = 0;
		}

		//SCENE2の初期化
		for (int i = 0; i < MAX2; i++) {
			player->bullet2[i]->isShot_ = false;
			player->bullet2[i]->VelocityY = 0.4f;
		}

		for (int i = 0; i < MAX3; i++) {
			player->bullet3[i]->isShot2_ = false;
			player->bullet3[i]->VelocityY = 0.4f;
		}

		player->isShake = 0;
		player->Rand.x = 0;
		player->Rand.y = 0;
		player->ShakeTimer = 0;

		background->isShake = 0;
		background->Rand.x = 0;
		background->Rand.y = 0;
		background->ShakeTimer = 0;

		//SCENE3の初期化
		for (int i = 0; i < MAX4; i++) {
			player->bullet4[i]->isShot_ = false;
			player->bullet4[i]->VelocityY = 0.4f;
		}

	}

	player->Update(keys);//Playerクラスの移動処理用メンバ関数Updateを呼び出す

	switch (Scene) 
	{
	case GameScene::SCENE1://caseがSCENE1の時

		player->Scene1Update();//PlayerクラスのSCENE1の更新処理用メンバ関数Scene1Updateを呼び出す
		
		break;//breakを抜ける

	case GameScene::SCENE2://caseがSCENE2の時

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == false)//SPACEキーが押された瞬間
		{
			player->isShake = 1;//プレイヤーのシェイクフラグを立てる
			background->isShake = 1;//背景のシェイクフラグを立てる
		}

		player->Scene2Update();//PlayerクラスのSCENE2の更新処理用メンバ関数Scene2Updateを呼び出す

		background->Update();//BackGroundクラスのメンバ関数Updateを呼び出す

		break;//breakで抜ける

	case GameScene::SCENE3://caseがSCENE3の時

		player->Scene3Update();//PlayerクラスのSCENE3の更新処理用メンバ関数Scene3Updateを呼び出す

		break;//breakで抜ける
	}
}

void ChangeScene::Draw() {
	
	background->Draw();//BackGroundクラスのメンバ関数Drawを呼び出す

	switch (Scene) {
	case GameScene::SCENE1://caseがSCENE1の時

		player->Scene1Draw();//PlayerクラスのSCENE1の描画処理用メンバ関数Scene1Drawを呼び出す

		//ScreenPrintfで文字を出力する
		Novice::ScreenPrintf(0, 0, "W A S D : Player Move");
		Novice::ScreenPrintf(0, 20, "Left Mouse Click : Ease In Quint");
		Novice::ScreenPrintf(0, 40, "2Keys : SCENE2");
		Novice::ScreenPrintf(0, 60, "3Keys : SCENE3");
		Novice::ScreenPrintf(0, 80, "R keys : Return SCENE1");

		break;//breakで抜ける

	case GameScene::SCENE2://caseがSCENE2の時

		player->Scene2Draw();//PlayerクラスのSCENE2の描画処理用メンバ関数Scene2Drawを呼び出す

		//ScreenPrintfで文字を出力する
		Novice::ScreenPrintf(0, 0, "W A S D : Player Move");
		Novice::ScreenPrintf(0, 20, "SPACE Keys : player & BackGround Shake");
		Novice::ScreenPrintf(0, 40, "1Keys : SCENE1");
		Novice::ScreenPrintf(0, 60, "3Keys : SCENE3");
		Novice::ScreenPrintf(0, 80, "R keys : Return SCENE1");

		break;//breakで抜ける

	case GameScene::SCENE3://caseがSCENE3の時

		player->Scene3Draw();//PlayerクラスのSCENE3の描画処理用メンバ関数Scene3Drawを呼び出す

		//ScreenPrintfで文字を出力する
		Novice::ScreenPrintf(0, 0, "W A S D : Player Move");
		Novice::ScreenPrintf(0, 20, "1Keys : SCENE1");
		Novice::ScreenPrintf(0, 40, "2Keys : SCENE2");
		Novice::ScreenPrintf(0, 60, "R keys : Return SCENE1");

		break;
	}

	GameSpriteDraw();//自作関数GameSpriteDrawを呼び出す

}