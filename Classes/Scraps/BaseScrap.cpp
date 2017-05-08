///-------------------------------------------------------------------
//*
//*	@���O		BaseScrap.cpp
//*
//*	@�쐬��		2017/05/08
//*
//*	@����		���� ���n
//*
///-------------------------------------------------------------------

// �w�b�_�[�t�@�C���̃C���N���[�h
#include "Scraps\BaseScrap.h"

// cocos2d-x�̖��O���
USING_NS_CC;


////////////////////////////
/// �v���C���N���X�̒�` ///
////////////////////////////

////----------------------------------------------------------------------
////! @�֐����Finit
////!
////! @�����F�v���C���N���X�̏���������
////!
////! @�����F�Ȃ�
////!
////! @�߂�l�F�������ɐ����������ۂ�(bool)
////----------------------------------------------------------------------
bool BaseScrap::init()
{
	// ���t���[���X�V��L����
	scheduleUpdate();

	// �C�x���g���X�i�[���쐬����
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	// �C�x���g���X�i�[�Ɋe�R�[���o�b�N�֐����Z�b�g����
	listener->onTouchBegan = CC_CALLBACK_2(BaseScrap::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(BaseScrap::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(BaseScrap::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(BaseScrap::onTouchCancelled, this);
	// �C�x���g���X�i�[��o�^����
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);



	//==========�X�N���b�p�[�̐ݒu�E�\��==========//
	//�@�X�N���b�p�[�m�[�h�̍쐬
	scrappers = Node::create();

	// �㑤
	scrapperA = Sprite::create("scrapper.png");
	scrapperA->setPosition(480, m_initSpotA);
	this->addChild(scrapperA);
	scrappers->addChild(scrapperA);

	// ����
	scrapperB = Sprite::create("scrapper.png");
	scrapperB->setPosition(480, m_initSpotB);
	this->addChild(scrapperB);
	scrappers->addChild(scrapperB);

	// ������������ɏI��
	return true;
}


////----------------------------------------------------------------------
////! @�֐����Fupdate
////!
////! @�����F�v���C��N���X�̖��t���[������
////!
////! @�����F�t���[����(float)
////!
////! @�߂�l�F�Ȃ�
////----------------------------------------------------------------------
void BaseScrap::update(float delta)
{

}



//////////////////////////////
/// �R�[���o�b�N�֐��̐錾 ///
//////////////////////////////

////----------------------------------------------------------------------
////! @�֐����FonTouchBegan
////!
////! @�����F�^�b�`�E�N���b�N�����ꏊ�փv���C�����ړ�������
////!
////! @�����F�^�b�`����(Touch)�A�C�x���g�^�C�v(Event)
////!
////! @�߂�l�F����or���s(bool)
////----------------------------------------------------------------------
bool BaseScrap::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	//* �A�N�V�������̈ړ��l������Ă����֐���if���ɗ��p����
	isActed = scrapperA->numberOfRunningActions();

	if (!isActed)
	{
		// �^�b�`���W�̎擾
		Vec2 touch_pos = touch->getLocation();
		// �^�b�`�����ꏊ�ɃX�N���b�p�[
		scrapperA->setPosition(touch_pos.x, m_initSpotA);
		scrapperB->setPosition(touch_pos.x, m_initSpotB);

		return true;
	}

	return false;
}


////----------------------------------------------------------------------
////! @�֐����FonTouchMoved
////!
////! @�����F�^�b�`�E�N���b�N�̏ꏊ���ړ���������A���̏ꏊ�փv���C����Ǐ]������
////!
////! @�����F�^�b�`����(Touch)�A�C�x���g�^�C�v(Event)
////!
////! @�߂�l�F�Ȃ�
////----------------------------------------------------------------------
void BaseScrap::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	//* �A�N�V�������̈ړ��l������Ă����֐����ȉ��ȗ�
	isActed = scrapperA->numberOfRunningActions();
	
	if (!isActed)
	{
		// �^�b�`���W�̎擾���p��
		Vec2 touch_pos = touch->getLocation();
		// �X���C�h�ꏊ�ɂ��X�N���b�p�[
		scrapperA->setPosition(touch_pos.x, m_initSpotA);
		scrapperB->setPosition(touch_pos.x, m_initSpotB);
	}
}


////----------------------------------------------------------------------
////! @�֐����FonTouchEnded
////!
////! @�����F�^�b�`�E�N���b�N�̔��肪��������A���̏ꏊ�Ńv���C�����쓮������
////!
////! @�����F�^�b�`����(Touch)�A�C�x���g�^�C�v(Event)
////!
////! @�߂�l�F�Ȃ�
////----------------------------------------------------------------------
void BaseScrap::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	//* �A�N�V�������̈ړ��l������Ă����֐����ȉ��ȗ�
	isActed = scrapperA->numberOfRunningActions();

	if (!isActed)
	{
		// �^�b�`���W�̎擾���p��
		Vec2 touch_pos = touch->getLocation();
		//�@�X�N���b�v����̃A�N�V����
		MoveTo* actionA1 = MoveTo::create(0.1f, Vec2(touch_pos.x, m_workSpotB));
		MoveTo* actionA2 = MoveTo::create(1.0f, Vec2(touch_pos.x, m_initSpotA));
		MoveTo* actionB1 = MoveTo::create(0.1f, Vec2(touch_pos.x, m_workSpotB));
		MoveTo* actionB2 = MoveTo::create(1.0f, Vec2(touch_pos.x, m_initSpotB));
		DelayTime* actionAB = DelayTime::create(0.15f);
		Sequence* actionA = Sequence::create(actionA1, actionAB, actionA2, nullptr);
		Sequence* actionB = Sequence::create(actionB1, actionAB, actionB2, nullptr);
		// �X�N���b�v����̎��s
		scrapperA->runAction(actionA);
		scrapperB->runAction(actionB);
	}
}


////----------------------------------------------------------------------
////! @�֐����FonTouchCancelled
////!
////! @�����F�^�b�`�E�N���b�N�̔��肪�z��O�ɏ�������A����Ɍ�������������s��
////!
////! @�����F�^�b�`����(Touch)�A�C�x���g�^�C�v(Event)
////!
////! @�߂�l�F�Ȃ�
////----------------------------------------------------------------------
void BaseScrap::onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{

}