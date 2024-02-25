#include "Player.h"
#include "Novice.h"
#define _USE_MATH_DEFINES
#include <math.h>
//ヘッダーファイル読み込み

Player::Player(Vector2 pos, float speed, float radius)//Playerクラスのコンストラクトを使用し、初期化を行う 
{	
	position_.x = pos.x;
	position_.y = pos.y;
	speed_ = speed;
	radius_ = radius;
	color_ = RED;

	Rand.x = 0;
	Rand.y = 0;

	MouseCarsolX = 0;
	MouseCarsolY = 0;
	t = 0;
	isMove = 0;
	isShake = 0;
	ShakeTimer = 0;

	R = 0x00000000;
	G = 0x00000000;
	B = 0x00000000;
	Alpha = 0x0000000FF;

	//bulletクラスのインスタンスを4つ生成する
	for (int i = 0; i < MAX; i++) {
		bullet[i] = new Bullet();
	}

	for (int i = 0; i < MAX2; i++) {
		bullet2[i] = new Bullet();
	}

	for (int i = 0; i < MAX3; i++) {
		bullet3[i] = new Bullet();
	}

	for (int i = 0; i < MAX4; i++) {
		bullet4[i] = new Bullet();
	}

	//Easeクラスのインスタンスを生成する
	ease = new Ease();
}

Player::~Player()//Playerクラスのデストラクタを使用し、delete処理を行う 
{
	//Bulletクラスのdelete
	for (int i = 0; i < MAX; i++) {
		delete bullet[i];
	}

	for (int i = 0; i < MAX2; i++) {
		delete bullet2[i];
	}

	for (int i = 0; i < MAX3; i++) {
		delete bullet3[i];
	}

	for (int i = 0; i < MAX4; i++) {
		delete bullet4[i];
	}

	//Easeクラスのdelete
	delete ease;
};

//====================================================<Playerクラスの更新処理>======================================================

void Player::Update(char* keys)//Playerクラスのメンバ関数を使用しUpdateを使用し、 プレイヤーの移動処理を行う
{
	if (keys[DIK_D] || keys[DIK_RIGHT])//RIGHTキーが押されている間 
	{
		position_.x += speed_;//プレイヤーを右方向に動かす

		if (position_.x >= 1264)//プレイヤーのX座標が1264以上である場合、 
		{
			speed_ = 0;//プレイヤーの速度を0にする
		}
		else//そうでなければ 
		{
			speed_ = 5;//プレイヤーの速度を5に戻す
		}
	}

	if (keys[DIK_A] || keys[DIK_LEFT])//LEFTキーが押されている間 
	{
		position_.x -= speed_;//プレイヤーを左方向に動かす

		if (position_.x <= 16)//プレイヤーのX座標が16以下である場合 
		{
			speed_ = 0;//プレイヤーの速度を0にする
		}
		else //そうでなければ
		{
			speed_ = 5;//プレイヤーの速度を5に戻す
		}
	}

	if (keys[DIK_W] || keys[DIK_UP])//UPキーが押されている間 
	{
		position_.y -= speed_;//プレイヤーを上方向に動かす

		if (position_.y <= 16)//プレイヤーのY座標が16以下である場合 
		{
			speed_ = 0;//プレイヤーの速度を0にする
		}
		else //そうでなければ
		{
			speed_ = 5;//プレイヤーの速度を5に戻す
		}
	}

	if (keys[DIK_S] || keys[DIK_DOWN])//DOWNキーが押されている間 
	{
		position_.y += speed_;//プレイヤーを下方向に動かす

		if (position_.y >= 704)//プレイヤーのY座標が704以上である場合 
		{
			speed_ = 0;//プレイヤーの速度を0にする
		}
		else //そうでなければ
		{
			speed_ = 5;//プレイヤーの速度を5に戻す
		}
	}
}

void Player::Scene1Update()//SCENE1の更新処理 
{
	//GetMousePosition関数を使用して、マウスカーソルの位置を取得
	Novice::GetMousePosition(&MouseCarsolX, &MouseCarsolY);

	//左クリックしたら
	if (Novice::IsTriggerMouse(0)) 
	{
		isMove = 1;//isMoveのフラグを立て
		t = 0;//tを0に設定する
	}

	if (isMove == 1)//isMoveのフラグが立っている場合 
	{
		t += 0.009f;//tを0.009fずつ加算していく

		//float型EaseTを宣言し、EaseクラスのInQuintを呼び出す
		float EaseT = ease->InQuint(t);

		//線形補間を使って、プレイヤーをマウスカーソルの位置まで移動させる
		position_.x = (1.0f - EaseT) * position_.x + EaseT * float(MouseCarsolX);
		position_.y = (1.0f - EaseT) * position_.y + EaseT * float(MouseCarsolY);
	}

	if (t >= 0.81f)//tが0.81以上である場合 
	{
		isMove = 0;//isMoveのフラグを折る
	}

	for (int i = 0; i < MAX; i++)
	{
		if (bullet[i]->isShot_ == 0)//弾が打たれているフラグが折られている場合
		{
			bullet[i]->isShot_ = 1;//弾が打たれているフラグを立て
			bullet[i]->position_.x = position_.x;
			bullet[i]->position_.y = position_.y;
			//弾のX座標とY座標に、プレイヤーのX座標とY座標を代入する
			break;
			//breakで抜ける
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		bullet[i]->Scene1Update();//BulletクラスのSCENE1の更新処理用メンバ関数Scene1Updateを呼び出す(弾)
	}
}

void Player::Scene2Update()//SCENE2の更新処理 
{

	if (isShake == 1)//isShakeが1である場合 
	{
		ShakeTimer++;//ShakeTimerをインクリメントする

		speed_ = 0;//プレイヤーの速度を0にする

	
		for (int i = 0; i < MAX2; i++)
		{
			if (bullet2[i]->isShot_ == 0)//弾2が打たれているフラグが折られている場合
			{
				bullet2[i]->isShot_ = 1;//弾2が打たれているフラグを立て

				bullet2[i]->speed_.x = rand() % 15 + 1.0f;//弾2の速度Xを1から15の範囲に設定する

				//更に、弾2のX座標を-20に設定し、弾2のY座標を以下の値で設定する
				bullet2[i]->position_.x = -20.0f;
				bullet2[i]->position_.y = -30.0f + 20.0f * i;

				break;//breakで抜ける
			}
		}

		for (int i = 0; i < MAX3; i++) 
		{
			if (bullet3[i]->isShot2_ == 0)//弾3が打たれているフラグ2が折られている場合
			{
				bullet3[i]->isShot2_ = 1;//弾3が打たれているフラグ2を立て

				bullet3[i]->speed_.x = rand() % 15 + 1.0f;//弾3の速度Xを1から15の範囲に設定する

				//更に、弾3のX座標を1300に設定し、弾3のY座標を以下の値で設定する
				bullet3[i]->position_.x = 1300.0f;
				bullet3[i]->position_.y = -30.0f + 20.0f * i;

				break;//breakで抜ける
			}
		}

	}

	if (ShakeTimer > 1 && ShakeTimer < 80)//ShakeTimerが1より大きく80より小さい場合 
	{
		Rand.x = rand() % 33 - 16.0f;
		Rand.y = rand() % 33 - 16.0f;
		//RandのXとYを-16から16の範囲に設定する
	}

	if (ShakeTimer >= 10)//ShakeTimerが10以上である場合 
	{
		Rand.x = rand() % 29 - 14.0f;
		Rand.y = rand() % 29 - 14.0f;
		//RandのXとYを-14から14の範囲に設定する
	}

	if (ShakeTimer >= 20)//ShakeTimerが20以上である場合  
	{
		Rand.x = rand() % 25 - 12.0f;
		Rand.y = rand() % 25 - 12.0f;
		//RandのXとYを-12から12の範囲に設定する
	}

	if (ShakeTimer >= 30)//ShakeTimerが30以上である場合  
	{
		Rand.x = rand() % 21 - 10.0f;
		Rand.y = rand() % 21 - 10.0f;
		//RandのXとYを-10から10の範囲に設定する
	}

	if (ShakeTimer >= 40)//ShakeTimerが40以上である場合   
	{
		Rand.x = rand() % 17 - 8.0f;
		Rand.y = rand() % 17 - 8.0f;
		//RandのXとYを-8から8の範囲に設定する
	}

	if (ShakeTimer >= 50)//ShakeTimerが50以上である場合  
	{
		Rand.x = rand() % 13 - 6.0f;
		Rand.y = rand() % 13 - 6.0f;
		//RandのXとYを-6から6の範囲に設定する
	}

	if (ShakeTimer >= 60)//ShakeTimerが60以上である場合 
	{
		Rand.x = rand() % 9 - 4.0f;
		Rand.y = rand() % 9 - 4.0f;
		//RandのXとYを-4から4の範囲に設定する
	}

	if (ShakeTimer >= 70)//ShakeTimerが70以上である場合  
	{
		Rand.x = rand() % 5 - 2.0f;
		Rand.y = rand() % 5 - 2.0f;
		//RandのXとYを-2から2の範囲に設定する
	}

	if (ShakeTimer >= 80)//ShakeTimerが80以上である場合  
	{
		isShake = 0;//シェイクのフラグを折り
		Rand.x = 0;
		Rand.y = 0;
		//RandのXとYを0に戻し

		ShakeTimer = 0;
		//ShakeTimerを0に戻す

		speed_ = 5;//プレイヤーの速度を5に戻す

		for (int i = 0; i < MAX2; i++) {
			bullet2[i]->isShot_ = 0;//弾2が打たれているフラグを折り

			bullet2[i]->VelocityY = 0.4f;//弾2の加速度を0.4fに戻す
		}

		for (int i = 0; i < MAX3; i++) {
			bullet3[i]->isShot2_ = 0;//弾3が打たれているフラグ2を折り

			bullet3[i]->VelocityY = 0.4f;//弾3の加速度を0.4fに戻す
		}
	}

	for (int i = 0; i < MAX2; i++) {
		bullet2[i]->Scene2Update();//BulletクラスのSCENE2の更新処理用のメンバ関数Scene2Updateを呼び出す(弾2)
	}

	for (int i = 0; i < MAX3; i++) {
		bullet3[i]->Scene2Update();//BulletクラスのSCENE2の更新処理用のメンバ関数Scene2Updateを呼び出す(弾3)
	}
}

void Player::Scene3Update()//DEMO3の更新処理
{
	R += 0x24000000;//Rを0x24000000ずつ加算していく

	G += 0x00160000;//Gを0x00160000ずつ加算していく

	B += 0x00000800;//Bを0x00000800ずつ加算していく
	
	for (int i = 0; i < MAX4; i++) 
	{
		if (bullet4[i]->isShot_ == 0)//弾4のフラグがおられている場合
		{
			bullet4[i]->isShot_ = 1;//弾4のフラグを立てる

			bullet4[i]->position_.x = position_.x;
			bullet4[i]->position_.y = position_.y;
			//弾4のX座標とY座標にプレイヤーのX座標とY座標を代入する

			bullet4[i]->color_ = R + G + B + Alpha;
			//弾4の色に赤と緑と青と透明度を足した値を代入する

			bullet4[i]->speed_.x = rand() % 3 - 1.01f;
			bullet4[i]->speed_.y = rand() % 5 + 2.5f;
			//弾4の速度Xを-1.01fから1.01fの範囲に設定し、速度Yを2.5fから7.5fの範囲に設定する

			break;//breakで抜ける
		}
	}

	for (int i = 0; i < MAX4; i++) {
		bullet4[i]->Scene3Update();//BulletクラスのSCENE3の更新処理用メンバ関数Scene3Updateを呼び出す(弾3)
	}

	for (int i = 0; i < MAX4; i++) 
	{
		if (bullet4[i]->position_.y >= 740)//弾4のY座標が740である場合 
		{
			bullet4[i]->VelocityY = 0.4f;//弾4の加速度を0.4fに戻し

			bullet4[i]->isShot_ = 0;//弾4が打たれているフラグを折る
		}
	}
}

//====================================================<Playerクラスの描画処理>======================================================

void Player::Scene1Draw()//SCENE1の描画処理 
{
	for (int i = 0; i < MAX; i++) {
		bullet[i]->Scene1Draw();//BulletクラスのSCENE1の描画処理用メンバ関数Scene1Drawを呼び出す(弾)
	}

	//DrawEllipse関数を使用し,半径16の赤い円のプレイヤーを描画する
	Novice::DrawEllipse((int)position_.x, (int)position_.y, (int)radius_, (int)radius_, 0.0f, color_, kFillModeSolid);

}

void Player::Scene2Draw()//SCENE2の描画処理  
{

	for (int i = 0; i < MAX2; i++) {
		bullet2[i]->Scene2Draw();//BulletクラスのSCENE2の描画処理用のメンバ関数Scene2Drawを呼び出す(弾2)
	}

	for (int i = 0; i < MAX3; i++) {
		bullet3[i]->Scene2Draw();//BulletクラスのSCENE2の描画処理用のメンバ関数Scene2Drawを呼び出す(弾3)
	}

	//Player::Scene1Drawと同じ
	Novice::DrawEllipse((int)position_.x + (int)Rand.x, (int)position_.y + (int)Rand.y, 
		(int)radius_, (int)radius_, 0.0f, color_, kFillModeSolid);
}

void Player::Scene3Draw()//SCENE3の描画処理 
{

	for (int i = 0; i < MAX4; i++) {
		bullet4[i]->Scene3Draw();//BulletクラスのSCENE3の描画処理用メンバ関数Scene3Drawを呼び出す(弾3)
	}
	
	Novice::SetBlendMode(BlendMode::kBlendModeNormal);//ブレンドモードをNormalに設定する
	//Player::Scene1Drawと同じ
	Novice::DrawEllipse((int)position_.x, (int)position_.y, (int)radius_, (int)radius_, 0.0f, color_, kFillModeSolid);
}