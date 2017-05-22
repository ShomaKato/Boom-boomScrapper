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

// 


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

	// �����_����
	srand(static_cast<unsigned int>(time(NULL)));

	// �C�x���g���X�i�[���쐬����
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	// �C�x���g���X�i�[�Ɋe�R�[���o�b�N�֐����Z�b�g����
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(PlayScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(PlayScene::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(PlayScene::onTouchCancelled, this);
	// �C�x���g���X�i�[��o�^����
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// ���t���[���X�V��L����
	scheduleUpdate();


	// �X�e�[�W�̕\��
	stage = Sprite::create("stage.png");
	stage->setPosition(480, 320);
	this->addChild(stage);


	//==========�X�N���b�p�̐ݒu�E�\��==========//
	//�@�X�N���b�p�m�[�h�̍쐬
	scrappers = Node::create();

	// �㑤
	scrapperA = Sprite::create("scrapper.png");
	scrapperA->setPosition(480, p_initSpotA);
	this->addChild(scrapperA);
	scrappers->addChild(scrapperA);

	// ����
	scrapperB = Sprite::create("scrapper.png");
	scrapperB->setPosition(480, p_initSpotB);
	scrapperB->setRotation(180.0f);
	this->addChild(scrapperB);
	scrappers->addChild(scrapperB);





	// �W�I�i�X�N���b�v�j�̐ݒu
	scrap = Sprite::create("scrapA.png");
	this->addChild(scrap);
	scrap->setPosition(300, 400);


	// ������������ɏI��
	return true;
}

void PlayScene::update(float delta)
{
	// �v���C���ƓG�̋�`���擾
	Rect r_scrapperA = scrapperA->getBoundingBox();
	Rect r_scrapperB = scrapperB->getBoundingBox();
	Rect r_scrap = scrap->getBoundingBox();


	// �v���C���ƕW�I���ڐG�������ۂ�
	bool isScrapedByA = r_scrapperA.intersectsRect(r_scrap);
	bool isScrapedByB = r_scrapperB.intersectsRect(r_scrap);

	// �X�N���b�v�ł�����W�I���A�{������
	if (isScrapedByA || isScrapedByB)
	{
		scrap->setVisible(false);
	}
}


////----------------------------------------------------------------------
////! @�֐����FonTouchBegan
////!
////! @�����F�^�b�`�E�N���b�N�����ꏊ�փv���C�����ړ�������
////!
////! @�����F�^�b�`����(Touch)�A�C�x���g�^�C�v(Event)
////!
////! @�߂�l�F����or���s(bool)
////----------------------------------------------------------------------
bool PlayScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	//* �A�N�V�������̈ړ��l������Ă����֐���if���ɗ��p����
	p_isActed = scrapperA->numberOfRunningActions();

	if (!p_isActed)
	{
		// �^�b�`���W�̎擾
		Vec2 touch_pos = touch->getLocation();
		// �^�b�`�����ꏊ�ɃX�N���b�p�[
		scrapperA->setPosition(touch_pos.x, p_initSpotA);
		scrapperB->setPosition(touch_pos.x, p_initSpotB);

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
void PlayScene::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	//* �A�N�V�������̈ړ��l������Ă����֐����ȉ��ȗ�
	p_isActed = scrapperA->numberOfRunningActions();

	if (!p_isActed)
	{
		// �^�b�`���W�̎擾���p��
		Vec2 touch_pos = touch->getLocation();
		// �X���C�h�ꏊ�ɂ��X�N���b�p�[
		scrapperA->setPosition(touch_pos.x, p_initSpotA);
		scrapperB->setPosition(touch_pos.x, p_initSpotB);
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
void PlayScene::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
	//* �A�N�V�������̈ړ��l������Ă����֐����ȉ��ȗ�
	p_isActed = scrapperA->numberOfRunningActions();

	if (!p_isActed)
	{
		// �^�b�`���W�̎擾���p��
		Vec2 touch_pos = touch->getLocation();
		//�@�X�N���b�v����̃A�N�V����
		MoveTo* actionA1 = MoveTo::create(0.05f, Vec2(touch_pos.x, p_workSpotB));
		MoveTo* actionA2 = MoveTo::create(0.3f, Vec2(touch_pos.x, p_initSpotA));
		MoveTo* actionB1 = MoveTo::create(0.05f, Vec2(touch_pos.x, p_workSpotB));
		MoveTo* actionB2 = MoveTo::create(0.3f, Vec2(touch_pos.x, p_initSpotB));
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
void PlayScene::onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event)
{
}