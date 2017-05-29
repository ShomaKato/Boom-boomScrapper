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
#include "Scenes\OverScene.h"

// 名前空間
USING_NS_CC;

//* create関数
OverScene* OverScene::create()
{
	//* メモリの確保
	OverScene *pRet = new(std::nothrow) OverScene();
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

bool OverScene::init()
{
	// 基底クラスの初期化
	if (!Scene::init())
	{
		// 基底クラスの初期化が失敗なら、異常終了
		return false;
	}

	// イベントリスナーを作成する
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	// イベントリスナーを登録する
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// 毎フレーム更新を有効化
	scheduleUpdate();

	// ゲームオーバー画面
	m_over = Sprite::create("over.png");
	m_over->setPosition(490.0f, 320.0f);
	this->addChild(m_over);

	//* onButtonClick
	//* ボタンの設置
	ui::Button* againButton = ui::Button::create("Again-button.png");
	againButton->setPosition(Vec2(300.0f, 250.0f));
	this->addChild(againButton);
	againButton->addClickEventListener(CC_CALLBACK_1(OverScene::againButton, this));


	ui::Button* exitButton = ui::Button::create("Exit-button.png");
	exitButton->setPosition(Vec2(660.0f, 250.0f));
	this->addChild(exitButton);
	exitButton->addClickEventListener(CC_CALLBACK_1(OverScene::exitButton, this));


	// 初期化が正常に終了
	return true;
}

void OverScene::update(float delta)
{
}



// ボタンクリック時コールバック
bool OverScene::againButton(Ref * ref)
{
	// 次のシーンを作成する
	Scene* nextScene = PlayScene::create();
	// 次のシーンに移行
	_director->replaceScene(nextScene);

	return true;
}

bool OverScene::exitButton(Ref * ref)
{
	// ボタンが押されたらアプリを終了する
	Director::getInstance()->end();

	return true;
}