#include "TransitionOriginal.h"

USING_NS_CC;

TransitionOriginal* TransitionOriginal::create(float t, Scene* scene)
{
	// �g�����W�V�����V�[���̍쐬
	TransitionOriginal* newScene = new (std::nothrow) TransitionOriginal();
	// �g�����W�V�����V�[���̏�����
	if (newScene && newScene->initWithDuration(t, scene))
	{
		// ��������}�l�[�W���ɓo�^
		newScene->autorelease();
		return newScene;
	}
	// �������Ɏ��s�����ꍇ�A�������NULL�|�C���^��Ԃ�
	CC_SAFE_DELETE(newScene);
	return nullptr;
}

void TransitionOriginal::onEnter()
{
	// ���N���X�̏����i�^�b�`�������Ȃǁj
	TransitionScene::onEnter();

	Size s = Director::getInstance()->getWinSize();

	// ���V�[���̏�����Ԃ�ݒ�
	_inScene->setScale(0.0f);
	//* �ǋL�F���́A�����Ă���V�[������ʉE��s���������炷�A�Ƃ�������
	//_inScene->setPosition(s.width, 0);
	_inScene->setAnchorPoint(Vec2(0.5f, 0.5f));
	_outScene->setAnchorPoint(Vec2(0.5f, 0.5f));
	// �e��A�N�V�����𐶐�
	ActionInterval *rotate = RotateBy::create(_duration / 4, 1080.0f);
	ActionInterval *rotateEaseIn = EaseIn::create(rotate,5.0f);
	ActionInterval *rotateEaseOut = EaseOut::create(rotate,5.0f);
	ActionInterval *scaleIn = ScaleTo::create(_duration / 4, 1.0f);
	ActionInterval *scaleOut = ScaleTo::create(_duration / 4, 0.00001f);
	// �O�V�[������]���Ȃ���k�����Ă����A�N�V����
	ActionInterval *rotateZoomOut = (ActionInterval*)(Spawn::create(scaleOut, rotateEaseIn, nullptr));
	// ���V�[������]���Ȃ���g�債�Ă���A�N�V����
	ActionInterval *rotateZoomIn = (ActionInterval*)(Spawn::create(rotateEaseOut, scaleIn, nullptr));

	ActionInterval *delay = DelayTime::create(_duration / 2);
	// �O�V�[���ւ̃A�N�V���������s
	_outScene->runAction(rotateZoomOut);

	// ���V�[���ւ̃A�N�V���������s
	_inScene->runAction
		(
			Sequence::create
			(
				// �ҋ@
				delay,
				// ��]���ē����Ă���
				rotateZoomIn,
				// �V�[���J�ڂ̏I������
				CallFunc::create(CC_CALLBACK_0(TransitionScene::finish, this)),
				nullptr
				)
			);
}