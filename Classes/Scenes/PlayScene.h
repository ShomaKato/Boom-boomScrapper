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
//#include "Player\Player.h"
//#include "Scraps\ScrapA.h"


class PlayScene : public cocos2d::Scene
{
private:

	////////////////////////
	/// プレイヤ用の変数 ///
	////////////////////////
	// スクラップ動作時の、上部分の停止場所
	float mp_workSpotA = 340.0f;

	// スクラップ動作時の、下部分の停止場所
	float mp_workSpotB = 320.0f;

	// 初期位置へ戻る時の、上部分の停止場所
	float mp_initSpotA = 510.0f;;

	// 初期位置へ戻る時の、下部分の停止場所
	float mp_initSpotB = 130.0f;;

	// スクラップ動作時の速度
	float mp_workSpeed;

	// 初期位置へ戻る時の速度
	float mp_initSpeed;

	// プレイヤの現在位置
	cocos2d::Vec2 mp_playerPos;

	// アクション中か否か（アクション中なら、どれくらい動いているかの数値が入る）
	int mp_isAction;
	

	////////////////////
	/// 標的用の変数 ///
	////////////////////

	// 敵の初期位置（initでランダム化）
	int mt_initPos;

	int mt_targetPos;



public:
	// create関数の宣言と定義
	static PlayScene* create();

	// タッチイベントリスナー
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event);

	// 初期化
	bool init();
	// 更新
	void update(float delta) override;



	//////////////////////////////
	/// スプライト・ノード登録 ///
	//////////////////////////////

	// プレイヤ（スクラッパ上側）
	cocos2d::Sprite* scrapperA;
	// プレイヤ（スクラッパ下側）
	cocos2d::Sprite* scrapperB;
	// プレイヤ（統合ノード）
	cocos2d::Node* scrappers;



	// 敵（スクラップA）
	cocos2d::Sprite* scrapA;
	// 敵（スクラップB）
	cocos2d::Sprite* scrapB;
	// 敵（スクラップC）
	cocos2d::Sprite* scrapC;
	// 敵破壊エフェクト
	cocos2d::Sprite* boom;



	// ステージ
	cocos2d::Sprite* stage;

};

