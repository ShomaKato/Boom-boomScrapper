#pragma once

#include "cocos2d.h"

// 独自のトランジションクラス
class TransitionOriginal : public cocos2d::TransitionScene
{
public:
	// 独自トランジションの生成　　　　秒数　　　　　次シーン
	static TransitionOriginal* create(float t, cocos2d::Scene* scene);

	virtual void onEnter() override;
};