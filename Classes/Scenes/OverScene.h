///-------------------------------------------------------------------
//*
//*	@作成日		2017/01/18
//*
//*	@名前		OverScene.h
//*
//*	@著者		加藤 彰馬
//*
///-------------------------------------------------------------------

// 多重インクルードの防止
#pragma once

// ヘッダーファイルのインクルード
#include "cocos2d.h"
#include "ui/CocosGUI.h"


class OverScene : public cocos2d::Scene
{
	int m_Cnt;
public:
	// create関数の宣言と定義
	CREATE_FUNC(OverScene);


	//* タッチ操作のために必要な関数の宣言
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event);

	// 初期化
	bool init();
	// 更新
	void update(float delta) override;

	//* onButtonClickのイベントリスナー	
	bool OverScene::onButtonClick(Ref *ref);

	// スプライトの作成
	cocos2d::Sprite* fly;
};

