///-------------------------------------------------------------------
//*
//*	@作成日		2017/01/18
//*
//*	@名前		PlayScene.cpp
//*
//*	@著者		加藤 彰馬
//*
///-------------------------------------------------------------------

// ヘッダーファイルのインクルード
#include "Scenes\OverScene.h"
#include "Scenes\PlayScene.h"


// 名前空間
USING_NS_CC;

//* create関数
PlayScene* PlayScene::create()
{
	//* メモリの確保
	PlayScene *pRet = new(std::nothrow) PlayScene();
	//* メモリが確保でき、正常に初期化できたなら
	if (pRet && pRet->init())
	{
		//* 自動開放マネージャに登録
		pRet->autorelease();
		//* 初期化したオブジェクトを返す
		return pRet;
	}
	else
	{
		//* 初期化でエラーが起きたので、メモリを開放して異常終了
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool PlayScene::init()
{
	// 基底クラスの初期化
	if (!Scene::init())
	{
		// 基底クラスの初期化が失敗なら、異常終了
		return false;
	}


	// 毎フレーム更新を有効化
	scheduleUpdate();


	// プレイヤの設置
	m_player = new Player();
	this->addChild(m_player);
	m_player->init();


	// 初期化が正常に終了
	return true;
}

void PlayScene::update(float delta)
{

}

//
//
//bool PlayScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event)
//{
//	// タッチ座標の取得
//	Vec2 touch_pos = touch->getLocation();
//	// タッチした場所にスクラッパー
//	scrapperA->setPosition(touch_pos.x, posA);
//	scrapperB->setPosition(touch_pos.x, posB);
//
//	return true;
//}
//
//void PlayScene::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unused_event)
//{
//	// タッチ座標の取得を継続
//	Vec2 touch_pos = touch->getLocation();
//	// スライド場所にもスクラッパー
//	scrapperA->setPosition(touch_pos.x, posA);
//	scrapperB->setPosition(touch_pos.x, posB);
//}
//
//void PlayScene::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event)
//{
//	// タッチ座標の取得を継続
//	Vec2 touch_pos = touch->getLocation();
//	//　スクラップ動作のアクション
//	MoveTo* actionA1 = MoveTo::create(0.1f, Vec2(touch_pos.x, 340.0f));
//	MoveTo* actionA2 = MoveTo::create(1.0f, Vec2(touch_pos.x, posA));
//	MoveTo* actionB1 = MoveTo::create(0.1f, Vec2(touch_pos.x, 320.0f));
//	MoveTo* actionB2 = MoveTo::create(1.0f, Vec2(touch_pos.x, posB));
//	DelayTime* actionAB = DelayTime::create(0.15f);
//	Sequence* actionA = Sequence::create(actionA1, actionAB, actionA2, nullptr);
//	Sequence* actionB = Sequence::create(actionB1, actionAB, actionB2, nullptr);
//	// スクラップ動作の実行
//	scrapperA->runAction(actionA);
//	scrapperB->runAction(actionB);
//}
//
//void PlayScene::onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event)
//{
//}