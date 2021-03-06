///-------------------------------------------------------------------
//*
//*	@作成日		2017/01/18
//*
//*	@名前		TitleScene.h
//*
//*	@著者		加藤 彰馬
//*
///-------------------------------------------------------------------

// 多重インクルードの防止
#pragma once

// ヘッダーファイルのインクルード
#include "cocos2d.h"
#include "ui/CocosGUI.h"


// タイトルシーン
class TitleScene : public cocos2d::Scene
{
private:

public:
	//* create関数の宣言と定義
	//CREATE_FUNC(PlayScene);	/* 今まで使ってたcreate関数 */
	static TitleScene* create();

	bool init();

	void update(float delta) override;


	//* onButtonClickのイベントリスナー	
	// スタートボタン
	bool TitleScene::scrapButton(Ref *ref);
	// 終了ボタン
	bool TitleScene::exitButton(Ref *ref);

	// タイトル画面
	cocos2d::Sprite* m_title;
};