///-------------------------------------------------------------------
//*
//*	@名前		BaseScrap.cpp
//*
//*	@作成日		2017/05/08
//*
//*	@著者		加藤 彰馬
//*
///-------------------------------------------------------------------

// ヘッダーファイルのインクルード
#include "Scraps\BaseScrap.h"

// cocos2d-xの名前空間
USING_NS_CC;


////////////////////////////
/// プレイヤクラスの定義 ///
////////////////////////////

////----------------------------------------------------------------------
////! @関数名：init
////!
////! @役割：プレイヤクラスの初期化処理
////!
////! @引数：なし
////!
////! @戻り値：初期化に成功したか否か(bool)
////----------------------------------------------------------------------
bool BaseScrap::init()
{
	// 毎フレーム更新を有効化
	scheduleUpdate();

	// イベントリスナーを作成する
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	// イベントリスナーに各コールバック関数をセットする
	listener->onTouchBegan = CC_CALLBACK_2(BaseScrap::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(BaseScrap::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(BaseScrap::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(BaseScrap::onTouchCancelled, this);
	// イベントリスナーを登録する
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);



	//==========スクラッパーの設置・表示==========//
	//　スクラッパーノードの作成
	scrappers = Node::create();

	// 上側
	scrapperA = Sprite::create("scrapper.png");
	scrapperA->setPosition(480, m_initSpotA);
	this->addChild(scrapperA);
	scrappers->addChild(scrapperA);

	// 下側
	scrapperB = Sprite::create("scrapper.png");
	scrapperB->setPosition(480, m_initSpotB);
	this->addChild(scrapperB);
	scrappers->addChild(scrapperB);

	// 初期化が正常に終了
	return true;
}


////----------------------------------------------------------------------
////! @関数名：update
////!
////! @役割：プレイやクラスの毎フレーム処理
////!
////! @引数：フレーム数(float)
////!
////! @戻り値：なし
////----------------------------------------------------------------------
void BaseScrap::update(float delta)
{

}



//////////////////////////////
/// コールバック関数の宣言 ///
//////////////////////////////

////----------------------------------------------------------------------
////! @関数名：onTouchBegan
////!
////! @役割：タッチ・クリックした場所へプレイヤを移動させる
////!
////! @引数：タッチ判定(Touch)、イベントタイプ(Event)
////!
////! @戻り値：成功or失敗(bool)
////----------------------------------------------------------------------
bool BaseScrap::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	//* アクション中の移動値を取ってくれる関数をif文に利用する
	isActed = scrapperA->numberOfRunningActions();

	if (!isActed)
	{
		// タッチ座標の取得
		Vec2 touch_pos = touch->getLocation();
		// タッチした場所にスクラッパー
		scrapperA->setPosition(touch_pos.x, m_initSpotA);
		scrapperB->setPosition(touch_pos.x, m_initSpotB);

		return true;
	}

	return false;
}


////----------------------------------------------------------------------
////! @関数名：onTouchMoved
////!
////! @役割：タッチ・クリックの場所を移動させたら、その場所へプレイヤを追従させる
////!
////! @引数：タッチ判定(Touch)、イベントタイプ(Event)
////!
////! @戻り値：なし
////----------------------------------------------------------------------
void BaseScrap::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	//* アクション中の移動値を取ってくれる関数を以下省略
	isActed = scrapperA->numberOfRunningActions();
	
	if (!isActed)
	{
		// タッチ座標の取得を継続
		Vec2 touch_pos = touch->getLocation();
		// スライド場所にもスクラッパー
		scrapperA->setPosition(touch_pos.x, m_initSpotA);
		scrapperB->setPosition(touch_pos.x, m_initSpotB);
	}
}


////----------------------------------------------------------------------
////! @関数名：onTouchEnded
////!
////! @役割：タッチ・クリックの判定が消えたら、その場所でプレイヤを作動させる
////!
////! @引数：タッチ判定(Touch)、イベントタイプ(Event)
////!
////! @戻り値：なし
////----------------------------------------------------------------------
void BaseScrap::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	//* アクション中の移動値を取ってくれる関数を以下省略
	isActed = scrapperA->numberOfRunningActions();

	if (!isActed)
	{
		// タッチ座標の取得を継続
		Vec2 touch_pos = touch->getLocation();
		//　スクラップ動作のアクション
		MoveTo* actionA1 = MoveTo::create(0.1f, Vec2(touch_pos.x, m_workSpotB));
		MoveTo* actionA2 = MoveTo::create(1.0f, Vec2(touch_pos.x, m_initSpotA));
		MoveTo* actionB1 = MoveTo::create(0.1f, Vec2(touch_pos.x, m_workSpotB));
		MoveTo* actionB2 = MoveTo::create(1.0f, Vec2(touch_pos.x, m_initSpotB));
		DelayTime* actionAB = DelayTime::create(0.15f);
		Sequence* actionA = Sequence::create(actionA1, actionAB, actionA2, nullptr);
		Sequence* actionB = Sequence::create(actionB1, actionAB, actionB2, nullptr);
		// スクラップ動作の実行
		scrapperA->runAction(actionA);
		scrapperB->runAction(actionB);
	}
}


////----------------------------------------------------------------------
////! @関数名：onTouchCancelled
////!
////! @役割：タッチ・クリックの判定が想定外に消えたら、それに見合った動作を行う
////!
////! @引数：タッチ判定(Touch)、イベントタイプ(Event)
////!
////! @戻り値：なし
////----------------------------------------------------------------------
void BaseScrap::onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{

}