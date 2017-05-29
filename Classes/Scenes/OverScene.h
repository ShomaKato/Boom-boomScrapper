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
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Scenes\PlayScene.h"


class OverScene : public cocos2d::Scene
{

public:
	// create関数の宣言と定義
	static OverScene* create();


	// 初期化
	bool init();
	// 更新
	void update(float delta) override;


	//* onButtonClickのイベントリスナー	
	// タイトルボタン
	bool OverScene::againButton(Ref *ref);
	// 終了ボタン
	bool OverScene::exitButton(Ref *ref);

	// タイトル画面
	cocos2d::Sprite* m_over;
};

