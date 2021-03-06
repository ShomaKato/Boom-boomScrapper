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

	// タイトル画面
	m_title = Sprite::create("title.png");
	m_title->setPosition(490.0f, 320.0f);
	this->addChild(m_title);


	//* onButtonClick
	// スタートボタンの設置
	ui::Button* startButton = ui::Button::create("Play-button.png");
	startButton->setPosition(Vec2(300.0f, 150.0f));
	this->addChild(startButton);
	startButton->addClickEventListener(CC_CALLBACK_1(TitleScene::scrapButton, this));

	// 終了ボタンの設置
	ui::Button* endButton = ui::Button::create("Exit-Button.png");
	endButton->setPosition(Vec2(660.0f, 150.0f));
	this->addChild(endButton);
	endButton->addClickEventListener(CC_CALLBACK_1(TitleScene::exitButton, this));



	// 初期化が正常終了
	return true;
}

// 毎フレーム更新
void TitleScene::update(float delta)
{

}


// ボタンクリック時コールバック
bool TitleScene::scrapButton(Ref * ref)
{
	// 次のシーンを作成する
	Scene* nextScene = PlayScene::create();
	// 次のシーンに移行
	_director->replaceScene(nextScene);

	return true;
}

bool TitleScene::exitButton(Ref * ref)
{
	// ボタンが押されたらアプリを終了する
	Director::getInstance()->end();

	return true;
}
