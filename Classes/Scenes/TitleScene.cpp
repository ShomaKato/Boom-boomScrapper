///-------------------------------------------------------------------
//*
//*	@作成日		2017/3/15
//*
//*	@名前		TitleScene.cpp
//*
//*	@著者		加藤 彰馬
//*
///-------------------------------------------------------------------

// ヘッダーファイルのインクルード
#include "Scenes\TitleScene.h"
#include "Scenes\PlayScene.h"
#include "Scenes\TransitionOriginal.h"

USING_NS_CC;

//* create関数
TitleScene* TitleScene::create()
{
	//* メモリの確保
	TitleScene *pRet = new(std::nothrow) TitleScene();
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

// 初期化
bool TitleScene::init()
{
	// 基底クラスの初期化
	if (!Scene::init())
	{
		// 基底クラスの初期化が失敗なら、異常終了
		return false;
	}

	// 毎フレーム更新を有効化
	scheduleUpdate();

	//* onButtonClick
	//* ボタンの設置
	ui::Button* button = ui::Button::create("Play-button.png");
	button->setPosition(Vec2(480.0f, 200.0f));
	this->addChild(button);
	button->addClickEventListener(CC_CALLBACK_1(TitleScene::onButtonClick, this));

	// 初期化が正常終了
	return true;
}

// 毎フレーム更新
void TitleScene::update(float delta)
{

}

// タッチ開始時コールバック
bool TitleScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	//// 次のシーンを作成する
	//Scene* nextScene = PlayScene::create();
	//// 次のシーンに移行
	//_director->replaceScene(nextScene);

	return true;
}

// ボタンクリック時コールバック
bool TitleScene::onButtonClick(Ref * ref)
{
	// 次のシーンを作成する
	Scene* nextScene = PlayScene::create();
	// 次のシーンに移行
	_director->replaceScene(nextScene);

	return true;
}
