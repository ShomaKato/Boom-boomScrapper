///-------------------------------------------------------------------
//*
//*	@作成日		2017/01/25
//*
//*	@名前		OverScene.cpp
//*
//*	@著者		加藤 彰馬
//*
///-------------------------------------------------------------------

// ヘッダーファイルのインクルード
#include "Scenes\TitleScene.h"
#include "Scenes\OverScene.h"

// 名前空間
USING_NS_CC;


bool OverScene::init()
{
	// 基底クラスの初期化
	if (!Scene::init())
	{
		// 基底クラスの初期化が失敗なら、異常終了
		return false;
	}

	// ランダム化
	srand(static_cast<unsigned int>(time(NULL)));

	//// 背景画像
	//Sprite* background = Sprite::create("back.png");
	//background->setPosition(480, 320);
	//this->addChild(background);

	// 毎フレーム更新を有効化
	scheduleUpdate();

	//* イベントリスナーを作成する
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	//* イベントリスナーに各コールバック関数をセットする
	listener->onTouchBegan = CC_CALLBACK_2(OverScene::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(OverScene::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(OverScene::onTouchCancelled, this);
	//* イベントリスナーを登録する
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//* ハエ１の表示
	fly = Sprite::create("fly2.png");
	fly->setPosition(480, 320);

	this->addChild(fly);

	//* とりあえず往復運動
	MoveBy* action1 = MoveBy::create(1.0f, Vec2(0.0f, 200.0f));
	MoveBy* action2 = MoveBy::create(1.0f, Vec2(0.0f, -200.0f));
	Sequence* turn = Sequence::create(action1, action2, nullptr);
	RepeatForever* turning = RepeatForever::create(turn);

	fly->runAction(turning);

	//* onButtonClick
	//* ボタンの設置
	ui::Button* button = ui::Button::create("Play-button.png");
	button->setPosition(Vec2(480.0f, 200.0f));
	this->addChild(button);
	button->addClickEventListener(CC_CALLBACK_1(OverScene::onButtonClick, this));


	// 初期化が正常に終了
	return true;
}

void OverScene::update(float delta)
{
}


bool OverScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	return false;
}

void OverScene::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
}

void OverScene::onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
}


// ボタンクリック時コールバック
bool OverScene::onButtonClick(Ref * ref)
{
	// 次のシーンを作成する
	Scene* nextScene = TitleScene::create();
	//* [13.6]１・シーントランジション
	//nextScene = TransitionOriginal::create(1.5f, nextScene);	/* [13.7]に伴ってコメントアウト */
	// 次のシーンに移行
	_director->replaceScene(nextScene);

	return true;
}