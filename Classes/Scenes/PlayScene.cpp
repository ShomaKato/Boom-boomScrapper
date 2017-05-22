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

// 


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

	// ランダム化
	srand(static_cast<unsigned int>(time(NULL)));

	// イベントリスナーを作成する
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	// イベントリスナーに各コールバック関数をセットする
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(PlayScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(PlayScene::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(PlayScene::onTouchCancelled, this);
	// イベントリスナーを登録する
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// 毎フレーム更新を有効化
	scheduleUpdate();


	// ステージの表示
	stage = Sprite::create("stage.png");
	stage->setPosition(480, 320);
	this->addChild(stage);


	//==========スクラッパの設置・表示==========//
	//　スクラッパノードの作成
	scrappers = Node::create();

	// 上側
	scrapperA = Sprite::create("scrapper.png");
	scrapperA->setPosition(480, p_initSpotA);
	this->addChild(scrapperA);
	scrappers->addChild(scrapperA);

	// 下側
	scrapperB = Sprite::create("scrapper.png");
	scrapperB->setPosition(480, p_initSpotB);
	scrapperB->setRotation(180.0f);
	this->addChild(scrapperB);
	scrappers->addChild(scrapperB);





	// 標的（スクラップ）の設置
	scrap = Sprite::create("scrapA.png");
	this->addChild(scrap);
	scrap->setPosition(300, 400);


	// 初期化が正常に終了
	return true;
}

void PlayScene::update(float delta)
{
	// プレイヤと敵の矩形を取得
	Rect r_scrapperA = scrapperA->getBoundingBox();
	Rect r_scrapperB = scrapperB->getBoundingBox();
	Rect r_scrap = scrap->getBoundingBox();


	// プレイヤと標的が接触したか否か
	bool isScrapedByA = r_scrapperA.intersectsRect(r_scrap);
	bool isScrapedByB = r_scrapperB.intersectsRect(r_scrap);

	// スクラップできたら標的がアボンする
	if (isScrapedByA || isScrapedByB)
	{
		scrap->setVisible(false);
	}
}


////----------------------------------------------------------------------
////! @関数名：onTouchBegan
////!
////! @役割：タッチ・クリックした場所へプレイヤを移動させる
////!
////! @引数：タッチ判定(Touch)、イベントタイプ(Event)
////!
////! @戻り値：成功or失敗(bool)
////----------------------------------------------------------------------
bool PlayScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	//* アクション中の移動値を取ってくれる関数をif文に利用する
	p_isActed = scrapperA->numberOfRunningActions();

	if (!p_isActed)
	{
		// タッチ座標の取得
		Vec2 touch_pos = touch->getLocation();
		// タッチした場所にスクラッパー
		scrapperA->setPosition(touch_pos.x, p_initSpotA);
		scrapperB->setPosition(touch_pos.x, p_initSpotB);

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
void PlayScene::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	//* アクション中の移動値を取ってくれる関数を以下省略
	p_isActed = scrapperA->numberOfRunningActions();

	if (!p_isActed)
	{
		// タッチ座標の取得を継続
		Vec2 touch_pos = touch->getLocation();
		// スライド場所にもスクラッパー
		scrapperA->setPosition(touch_pos.x, p_initSpotA);
		scrapperB->setPosition(touch_pos.x, p_initSpotB);
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
void PlayScene::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	//* アクション中の移動値を取ってくれる関数を以下省略
	p_isActed = scrapperA->numberOfRunningActions();

	if (!p_isActed)
	{
		// タッチ座標の取得を継続
		Vec2 touch_pos = touch->getLocation();
		//　スクラップ動作のアクション
		MoveTo* actionA1 = MoveTo::create(0.05f, Vec2(touch_pos.x, p_workSpotB));
		MoveTo* actionA2 = MoveTo::create(0.3f, Vec2(touch_pos.x, p_initSpotA));
		MoveTo* actionB1 = MoveTo::create(0.05f, Vec2(touch_pos.x, p_workSpotB));
		MoveTo* actionB2 = MoveTo::create(0.3f, Vec2(touch_pos.x, p_initSpotB));
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
void PlayScene::onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
}