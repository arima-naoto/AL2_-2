#include "Bullet.h"
#include "stdlib.h"
#include "Novice.h"
//ヘッダーファイル読み込み

Bullet::Bullet() {//Bulletクラスのコンストラクタを使用し、初期化を行う
	position_.x = 0;
	position_.y = -10;
	radius_ = rand() % 4 + 3.0f;
	speed_.x = rand() % 5 - 2.25f;
	speed_.y = rand() % 5 - 2.25f;
	isShot_ = 0;
	isShot2_ = 0;
	color_ = 0xFFFFFF80;

	VelocityY = 0.0f;
	accelerationY = -0.8f;
}

//============================================================<Bulletクラスの更新処理>==============================================
void Bullet::Scene1Update()//SCENE1の更新処理 
{
	
	if (isShot_ == 1)//弾が打たれてるフラグが立っていたら
	{
		radius_+= 0.3f;//Radiusを0.3ずつ上げていく

		position_.x += speed_.x;//弾のX座標を-2.25fから2.25fの範囲で弾を進める
		position_.y += speed_.y;//弾のY座標を-2.25fから2.25fの範囲で弾を進める
		color_ -= 0x00000001;//色の透明度を1ずつ下げていく

		if (color_ <= 0xFFFFFF00)//色の透明度が0になったら
		{
			radius_ = rand() % 4 + 3.0f;//Radiusを最初の状態に戻す
			color_ = 0xFFFFFF80;//色の透明度を80に戻し
			isShot_ = 0;//弾のフラグを折る
		}
	}
	
}

void Bullet::Scene2Update()//SCENE2の更新処理 
{

	if (isShot_ == 1)//弾2が打たれているフラグが立っているならば 
	{
		VelocityY += 0.4f;//弾2の加速度を0.4fずつ加算していく

		radius_ = 7;//弾2の半径を7に設定し
		color_ = GREEN;//弾2の色をGREENに設定する

		position_.x += speed_.x;//弾2のX座標を1から15の範囲で進ませ

		VelocityY += accelerationY;//弾2の加速度に弾2の重力加速度を加算していく

		position_.y -= VelocityY;//弾2のY座標を下方向に進ませる
	}

	if (isShot2_ == 1) {//弾3が打たれているフラグ2が立っているならば 

		VelocityY += 0.4f;//弾3の加速度を0.4fずつ加算していく

		radius_ = 7;//弾3の半径を7に設定し
		color_ = GREEN;//弾3の色をGREENに設定する

		position_.x -= speed_.x;////弾3のX座標を1から15の範囲で進ませ

		VelocityY += accelerationY;//弾3の加速度に弾3の重力加速度を加算していく

		position_.y -= VelocityY;//弾3のY座標を下方向に進ませる
	}
}

void Bullet::Scene3Update()//SCENE3の更新処理  
{
	if (isShot_ == 1)//弾4が打たれているフラグが立っているならば
	{

		position_.x += speed_.x;
		position_.y -= speed_.y;
		//弾4のX座標を-1.01fから1.01fの範囲で進め、Y座標を2.5fから7.5fの範囲で進める

		if (position_.y <= 65)//弾のY座標が65以下なら 
		{
			//弾のY座標を下に進ませる
			speed_.x = 0;
			VelocityY += 0.4f;
			VelocityY += accelerationY;
			speed_.y += VelocityY;
			position_.y -= speed_.y;
		}
	}


}

//============================================================<Bulletクラスの描画処理>==============================================
void Bullet::Scene1Draw()//SCENE1の描画処理 
{
	if (isShot_ == 1)//弾が打たれているフラグが立っていたら
	{
		Novice::DrawEllipse((int)position_.x, (int)position_.y, (int)radius_, (int)radius_, 0.0f, color_, kFillModeSolid);
		//DrawEllipse関数を使用し、弾を描画する		
	}
}

void Bullet::Scene2Draw()//SCENE2の描画処理 
{
	if (isShot_ == 1)//弾2が打たれているフラグが立っていたら
	{
		Novice::DrawEllipse((int)position_.x, (int)position_.y, (int)radius_, (int)radius_, 0.0f, color_, kFillModeSolid);
		//DrawEllipse関数を使用し、弾2を描画する		
	}

	if (isShot2_ == 1)//弾3が打たれているフラグ2が立っていたら
	{
		Novice::DrawEllipse((int)position_.x, (int)position_.y, (int)radius_, (int)radius_, 0.0f, color_, kFillModeSolid);
		//DrawEllipse関数を使用し、弾3を描画する		
	}
}

void Bullet::Scene3Draw()//SCENE3の描画処理
{

	//int型変数ParticleHandleを宣言し、LoadTexture関数でパーティクル画像を読み込む
	int ParticleHandle = Novice::LoadTexture("./Resources/particle.png");

	if (isShot_ == 1)//弾4が打たれているフラグが立っていたら
	{
		Novice::SetBlendMode(BlendMode::kBlendModeAdd);//ブレンドモードを加算に設定する
		Novice::DrawSprite((int)position_.x - 40, (int)position_.y - 40, ParticleHandle, 1.0f, 1.0f, 0.0f, color_);
		//DrawEllipse関数を使用し、弾4を描画する		
	}
}