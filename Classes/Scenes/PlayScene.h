///-------------------------------------------------------------------
//*
//*	@作成日		2017/01/18
//*
//*	@名前		PlayScene.h
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
#include "Player\Player.h"


class PlayScene : public cocos2d::Scene
{
private:
	// プレイヤ
	Player* m_player;
	
public:
	// create関数の宣言と定義
	static PlayScene* create();

	////* タッチ操作のために必要な関数の宣言
	//bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	//void onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	//void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	//void onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event);

	// 初期化
	bool init();
	// 更新
	void update(float delta) override;

};

