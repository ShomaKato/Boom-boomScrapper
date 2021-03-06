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
#include "Scenes\PlayScene.h"
//#include <time.h>


// 名前空間
USING_NS_CC;

// 定数
//const int debugPosX = 490;
//const int debugPosY = 320;


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

	// カウントのリセット
	m_timeCnt = 0;
	m_clearCnt = 0;


	//==========スクラッパの設置・表示==========//
	//　スクラッパノードの作成
	scrappers = Node::create();

	// 上側
	scrapperA = Sprite::create("scrapper.png");
	scrapperA->setPosition(480, mp_initSpotA);
	this->addChild(scrapperA);
	scrappers->addChild(scrapperA);

	// 下側
	scrapperB = Sprite::create("scrapper.png");
	scrapperB->setPosition(480, mp_initSpotB);
	scrapperB->setRotation(180.0f);
	this->addChild(scrapperB);
	scrappers->addChild(scrapperB);




	//==========標的の設置・表示==========//
	for (int i = 0; i < 40; i++)
	{
		// 標的（スクラップ）の設置
		scrapA[i] = Sprite::create("scrapA.png");
		this->addChild(scrapA[i]);
		scrapA[i]->setPosition(rand() % -500 - 500,rand() % 350 + 135);
		//scrapA[i]->setPosition(debugPosX, debugPosY);
	}

	// 標的の破壊数を初期化
	m_scrapCnt = 0;

	// 初期化が正常に終了
	return true;
}

void PlayScene::update(float delta)
{
	//==========毎フレーム必ず行う更新処理==========//
	m_timeCnt++;


	// 6秒でゲームオーバー
	if (m_timeCnt >= 360)
	{
		// 次のシーンを作成する
		Scene* nextScene = OverScene::create();
		// 次のシーンに移行
		_director->replaceScene(nextScene);
	}

	// 標的Aの出現関数
	this->AppearScrapA();

	// 全部スクラップしたら2.5秒後にクリア画面
	if (m_scrapCnt >= 40)
	{
		m_clearCnt++;

		if (m_clearCnt >= 90)
		{
			Scene* nextScene = ClearScene::create();
			_director->replaceScene(nextScene);
		}
	}

	//==========プレイヤ関係の更新処理==========//






}


////----------------------------------------------------------------------
////! @関数名：AppearScrapA
////!
////! @役割：標的Aの出現・移動計算処理を行う関数
////!
////! @引数：なし
////!
////! @戻り値：なし
////----------------------------------------------------------------------
void PlayScene::AppearScrapA()
{
	for (int i = 0; i < 40; i++)
	{
		if (scrapA[i] != nullptr)
		{
			// //標的を左から右へ移動させる
			Vec2 scrapA_pos = scrapA[i]->getPosition();
			scrapA_pos += Vec2(rand() % 3 + 4, 0);
			scrapA[i]->setPosition(scrapA_pos);

			// 矩形を取得する	// プレイヤの矩形を取得
			Rect r_scrapperA = scrapperA->getBoundingBox();
			Rect r_scrapperB = scrapperB->getBoundingBox();
			Rect r_scrapA = scrapA[i]->getBoundingBox();

			// プレイヤと標的が接触したか否か
			bool isScrapedByA = r_scrapperA.intersectsRect(r_scrapA);
			bool isScrapedByB = r_scrapperB.intersectsRect(r_scrapA);

			// スクラップできたら標的が爆発四散する
			if (isScrapedByA || isScrapedByB)
			{
				Vec2 scrappedSpot(scrapA[i]->getPosition());
				boom = Sprite::create("boom.png");
				this->addChild(boom);
				boom->setPosition(Vec2(scrappedSpot));
				// 爆発のアクション
				FadeOut* action1 = FadeOut::create(0.5f);
				RemoveSelf* action2 = RemoveSelf::create(true);
				Sequence* action3 = Sequence::create(action1, action2, nullptr);
				// 爆発したら消滅＆カウント数に+1
				scrapA[i]->removeFromParent();
				scrapA[i] = nullptr;
				boom->runAction(action3);
				m_scrapCnt++;
			}

		}
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
	mp_isActing = scrapperA->numberOfRunningActions();

	if (!mp_isActing)
	{
		// タッチ座標の取得
		Vec2 touch_pos = touch->getLocation();
		// タッチした場所にスクラッパー
		scrapperA->setPosition(touch_pos.x, mp_initSpotA);
		scrapperB->setPosition(touch_pos.x, mp_initSpotB);

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
	mp_isActing = scrapperA->numberOfRunningActions();

	if (!mp_isActing)
	{
		// タッチ座標の取得を継続
		Vec2 touch_pos = touch->getLocation();
		// スライド場所にもスクラッパー
		scrapperA->setPosition(touch_pos.x, mp_initSpotA);
		scrapperB->setPosition(touch_pos.x, mp_initSpotB);
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
	//* アクション中の移動値を以下省略
	mp_isActing = scrapperA->numberOfRunningActions();

	if (!mp_isActing)
	{
		// タッチ座標の取得を継続
		Vec2 touch_pos = touch->getLocation();
		// スクラップ動作のアクション
		MoveTo* actionA1 = MoveTo::create(0.05f, Vec2(touch_pos.x, mp_workSpotB));
		MoveTo* actionA2 = MoveTo::create(0.3f, Vec2(touch_pos.x, mp_initSpotA));
		MoveTo* actionB1 = MoveTo::create(0.05f, Vec2(touch_pos.x, mp_workSpotB));
		MoveTo* actionB2 = MoveTo::create(0.3f, Vec2(touch_pos.x, mp_initSpotB));
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

