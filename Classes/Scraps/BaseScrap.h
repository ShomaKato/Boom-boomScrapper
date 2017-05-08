///-------------------------------------------------------------------
//*
//*	@名前		BaseScrap.h
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
class BaseScrap : public cocos2d::Layer
{
private:
	// スクラップ動作時の、上部分の停止場所
	float m_workSpotA = 340.0f;

	// スクラップ動作時の、下部分の停止場所
	float m_workSpotB = 320.0f;

	// 初期位置へ戻る時の、上部分の停止場所
	float m_initSpotA = 630.0f;;

	// 初期位置へ戻る時の、下部分の停止場所
	float m_initSpotB = 10.0f;;

	// スクラップ動作時の速度
	float m_workSpeed;

	// 初期位置へ戻る時の速度
	float m_initSpeed;

	// プレイヤの現在位置
	cocos2d::Vec2 m_playerPos;

	// アクション中か否か（アクション中なら、どれくらい動いているかの数値が入る）
	int isActed;


public:
	// create関数の宣言と定義
	static BaseScrap* create();

	// 初期化
	bool init();

	// 更新
	void update(float delta);

	//////////////////////////////
	/// コールバック関数の宣言 ///
	//////////////////////////////
	// タッチイベントリスナー
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event);


	//////////////////////////////
	/// スプライト・ノード登録 ///
	//////////////////////////////
	// プレイヤ（上側）
	cocos2d::Sprite* scrapperA;
	// プレイヤ（下側）
	cocos2d::Sprite* scrapperB;
	
	// プレイヤ（統合ノード）
	cocos2d::Node* scrappers;

};

