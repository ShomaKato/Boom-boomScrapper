#pragma once

#include "cocos2d.h"

// �Ǝ��̃g�����W�V�����N���X
class TransitionOriginal : public cocos2d::TransitionScene
{
public:
	// �Ǝ��g�����W�V�����̐����@�@�@�@�b���@�@�@�@�@���V�[��
	static TransitionOriginal* create(float t, cocos2d::Scene* scene);

	virtual void onEnter() override;
};