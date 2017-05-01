///-------------------------------------------------------------------
//*
//*	@�쐬��		2017/01/18
//*
//*	@���O		PlayScene.cpp
//*
//*	@����		���� ���n
//*
///-------------------------------------------------------------------

// �w�b�_�[�t�@�C���̃C���N���[�h
#include "Scenes\OverScene.h"
#include "Scenes\PlayScene.h"


// ���O���
USING_NS_CC;

//* create�֐�
PlayScene* PlayScene::create()
{
	//* �������̊m��
	PlayScene *pRet = new(std::nothrow) PlayScene();
	//* ���������m�ۂł��A����ɏ������ł����Ȃ�
	if (pRet && pRet->init())
	{
		//* �����J���}�l�[�W���ɓo�^
		pRet->autorelease();
		//* �����������I�u�W�F�N�g��Ԃ�
		return pRet;
	}
	else
	{
		//* �������ŃG���[���N�����̂ŁA���������J�����Ĉُ�I��
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool PlayScene::init()
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}


	// ���t���[���X�V��L����
	scheduleUpdate();


	// �v���C���̐ݒu
	m_player = new Player();
	this->addChild(m_player);
	m_player->init();


	// ������������ɏI��
	return true;
}

void PlayScene::update(float delta)
{

}

//
//
//bool PlayScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event)
//{
//	// �^�b�`���W�̎擾
//	Vec2 touch_pos = touch->getLocation();
//	// �^�b�`�����ꏊ�ɃX�N���b�p�[
//	scrapperA->setPosition(touch_pos.x, posA);
//	scrapperB->setPosition(touch_pos.x, posB);
//
//	return true;
//}
//
//void PlayScene::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unused_event)
//{
//	// �^�b�`���W�̎擾���p��
//	Vec2 touch_pos = touch->getLocation();
//	// �X���C�h�ꏊ�ɂ��X�N���b�p�[
//	scrapperA->setPosition(touch_pos.x, posA);
//	scrapperB->setPosition(touch_pos.x, posB);
//}
//
//void PlayScene::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event)
//{
//	// �^�b�`���W�̎擾���p��
//	Vec2 touch_pos = touch->getLocation();
//	//�@�X�N���b�v����̃A�N�V����
//	MoveTo* actionA1 = MoveTo::create(0.1f, Vec2(touch_pos.x, 340.0f));
//	MoveTo* actionA2 = MoveTo::create(1.0f, Vec2(touch_pos.x, posA));
//	MoveTo* actionB1 = MoveTo::create(0.1f, Vec2(touch_pos.x, 320.0f));
//	MoveTo* actionB2 = MoveTo::create(1.0f, Vec2(touch_pos.x, posB));
//	DelayTime* actionAB = DelayTime::create(0.15f);
//	Sequence* actionA = Sequence::create(actionA1, actionAB, actionA2, nullptr);
//	Sequence* actionB = Sequence::create(actionB1, actionAB, actionB2, nullptr);
//	// �X�N���b�v����̎��s
//	scrapperA->runAction(actionA);
//	scrapperB->runAction(actionB);
//}
//
//void PlayScene::onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event)
//{
//}