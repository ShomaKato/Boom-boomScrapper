#include "TransitionOriginal.h"

USING_NS_CC;

TransitionOriginal* TransitionOriginal::create(float t, Scene* scene)
{
	// トランジションシーンの作成
	TransitionOriginal* newScene = new (std::nothrow) TransitionOriginal();
	// トランジションシーンの初期化
	if (newScene && newScene->initWithDuration(t, scene))
	{
		// 自動解放マネージャに登録
		newScene->autorelease();
		return newScene;
	}
	// 初期化に失敗した場合、解放してNULLポインタを返す
	CC_SAFE_DELETE(newScene);
	return nullptr;
}

void TransitionOriginal::onEnter()
{
	// 基底クラスの処理（タッチ無効化など）
	TransitionScene::onEnter();

	Size s = Director::getInstance()->getWinSize();

	// 次シーンの初期状態を設定
	_inScene->setScale(0.0f);
	//* 追記：↓は、入ってくるシーンを画面右にs分だけずらす、というもの
	//_inScene->setPosition(s.width, 0);
	_inScene->setAnchorPoint(Vec2(0.5f, 0.5f));
	_outScene->setAnchorPoint(Vec2(0.5f, 0.5f));
	// 各種アクションを生成
	ActionInterval *rotate = RotateBy::create(_duration / 4, 1080.0f);
	ActionInterval *rotateEaseIn = EaseIn::create(rotate,5.0f);
	ActionInterval *rotateEaseOut = EaseOut::create(rotate,5.0f);
	ActionInterval *scaleIn = ScaleTo::create(_duration / 4, 1.0f);
	ActionInterval *scaleOut = ScaleTo::create(_duration / 4, 0.00001f);
	// 前シーンが回転しながら縮小していくアクション
	ActionInterval *rotateZoomOut = (ActionInterval*)(Spawn::create(scaleOut, rotateEaseIn, nullptr));
	// 次シーンが回転しながら拡大してくるアクション
	ActionInterval *rotateZoomIn = (ActionInterval*)(Spawn::create(rotateEaseOut, scaleIn, nullptr));

	ActionInterval *delay = DelayTime::create(_duration / 2);
	// 前シーンへのアクションを実行
	_outScene->runAction(rotateZoomOut);

	// 次シーンへのアクションを実行
	_inScene->runAction
		(
			Sequence::create
			(
				// 待機
				delay,
				// 回転して入ってくる
				rotateZoomIn,
				// シーン遷移の終了処理
				CallFunc::create(CC_CALLBACK_0(TransitionScene::finish, this)),
				nullptr
				)
			);
}