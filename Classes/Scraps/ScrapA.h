///-------------------------------------------------------------------
//*
//*	@名前		ScrapA.h
//*
//*	@作成日		2017/05/08
//*
//*	@著者		加藤 彰馬
//*
///-------------------------------------------------------------------


// 多重インクルードの防止
#pragma once

// ヘッダーファイルのインクルード
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"


//////////////////////////////
///　プレイヤクラスの宣言　///
//////////////////////////////
class ScrapA : public cocos2d::Layer
{
private:

public:
	// create関数の宣言と定義
	static ScrapA* create();

	// 初期化
	bool init();

	// 更新
	void update(float delta);

	// どこに出現させるか
	void SetScrap_pos(float x, float y);


	// スクラップ（標的）
	cocos2d::Sprite* scrapA;
};

