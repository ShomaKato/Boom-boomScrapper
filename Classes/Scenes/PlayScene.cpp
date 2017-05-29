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
#include "Scenes\PlayScene.h"
//#include <time.h>


// ���O���
USING_NS_CC;

// �萔
//const int debugPosX = 490;
//const int debugPosY = 320;


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

	// �J�E���g�̃��Z�b�g
	m_timeCnt = 0;
	m_clearCnt = 0;


	//==========�X�N���b�p�̐ݒu�E�\��==========//
	//�@�X�N���b�p�m�[�h�̍쐬
	scrappers = Node::create();

	// �㑤
	scrapperA = Sprite::create("scrapper.png");
	scrapperA->setPosition(480, mp_initSpotA);
	this->addChild(scrapperA);
	scrappers->addChild(scrapperA);

	// ����
	scrapperB = Sprite::create("scrapper.png");
	scrapperB->setPosition(480, mp_initSpotB);
	scrapperB->setRotation(180.0f);
	this->addChild(scrapperB);
	scrappers->addChild(scrapperB);




	//==========�W�I�̐ݒu�E�\��==========//
	for (int i = 0; i < 40; i++)
	{
		// �W�I�i�X�N���b�v�j�̐ݒu
		scrapA[i] = Sprite::create("scrapA.png");
		this->addChild(scrapA[i]);
		scrapA[i]->setPosition(rand() % -500 - 500,rand() % 350 + 135);
		//scrapA[i]->setPosition(debugPosX, debugPosY);
	}

	// �W�I�̔j�󐔂�������
	m_scrapCnt = 0;

	// ������������ɏI��
	return true;
}

void PlayScene::update(float delta)
{
	//==========���t���[���K���s���X�V����==========//
	m_timeCnt++;


	// 6�b�ŃQ�[���I�[�o�[
	if (m_timeCnt >= 360)
	{
		// ���̃V�[�����쐬����
		Scene* nextScene = OverScene::create();
		// ���̃V�[���Ɉڍs
		_director->replaceScene(nextScene);
	}

	// �W�IA�̏o���֐�
	this->AppearScrapA();

	// �S���X�N���b�v������2.5�b��ɃN���A���
	if (m_scrapCnt >= 40)
	{
		m_clearCnt++;

		if (m_clearCnt >= 90)
		{
			Scene* nextScene = ClearScene::create();
			_director->replaceScene(nextScene);
		}
	}

	//==========�v���C���֌W�̍X�V����==========//






}


////----------------------------------------------------------------------
////! @�֐����FAppearScrapA
////!
////! @�����F�W�IA�̏o���E�ړ��v�Z�������s���֐�
////!
////! @�����F�Ȃ�
////!
////! @�߂�l�F�Ȃ�
////----------------------------------------------------------------------
void PlayScene::AppearScrapA()
{
	for (int i = 0; i < 40; i++)
	{
		if (scrapA[i] != nullptr)
		{
			// //�W�I��������E�ֈړ�������
			Vec2 scrapA_pos = scrapA[i]->getPosition();
			scrapA_pos += Vec2(rand() % 3 + 4, 0);
			scrapA[i]->setPosition(scrapA_pos);

			// ��`���擾����	// �v���C���̋�`���擾
			Rect r_scrapperA = scrapperA->getBoundingBox();
			Rect r_scrapperB = scrapperB->getBoundingBox();
			Rect r_scrapA = scrapA[i]->getBoundingBox();

			// �v���C���ƕW�I���ڐG�������ۂ�
			bool isScrapedByA = r_scrapperA.intersectsRect(r_scrapA);
			bool isScrapedByB = r_scrapperB.intersectsRect(r_scrapA);

			// �X�N���b�v�ł�����W�I�������l�U����
			if (isScrapedByA || isScrapedByB)
			{
				Vec2 scrappedSpot(scrapA[i]->getPosition());
				boom = Sprite::create("boom.png");
				this->addChild(boom);
				boom->setPosition(Vec2(scrappedSpot));
				// �����̃A�N�V����
				FadeOut* action1 = FadeOut::create(0.5f);
				RemoveSelf* action2 = RemoveSelf::create(true);
				Sequence* action3 = Sequence::create(action1, action2, nullptr);
				// ������������Ł��J�E���g����+1
				scrapA[i]->removeFromParent();
				scrapA[i] = nullptr;
				boom->runAction(action3);
				m_scrapCnt++;
			}

		}
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
	mp_isActing = scrapperA->numberOfRunningActions();

	if (!mp_isActing)
	{
		// �^�b�`���W�̎擾
		Vec2 touch_pos = touch->getLocation();
		// �^�b�`�����ꏊ�ɃX�N���b�p�[
		scrapperA->setPosition(touch_pos.x, mp_initSpotA);
		scrapperB->setPosition(touch_pos.x, mp_initSpotB);

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
	mp_isActing = scrapperA->numberOfRunningActions();

	if (!mp_isActing)
	{
		// �^�b�`���W�̎擾���p��
		Vec2 touch_pos = touch->getLocation();
		// �X���C�h�ꏊ�ɂ��X�N���b�p�[
		scrapperA->setPosition(touch_pos.x, mp_initSpotA);
		scrapperB->setPosition(touch_pos.x, mp_initSpotB);
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
	//* �A�N�V�������̈ړ��l���ȉ��ȗ�
	mp_isActing = scrapperA->numberOfRunningActions();

	if (!mp_isActing)
	{
		// �^�b�`���W�̎擾���p��
		Vec2 touch_pos = touch->getLocation();
		// �X�N���b�v����̃A�N�V����
		MoveTo* actionA1 = MoveTo::create(0.05f, Vec2(touch_pos.x, mp_workSpotB));
		MoveTo* actionA2 = MoveTo::create(0.3f, Vec2(touch_pos.x, mp_initSpotA));
		MoveTo* actionB1 = MoveTo::create(0.05f, Vec2(touch_pos.x, mp_workSpotB));
		MoveTo* actionB2 = MoveTo::create(0.3f, Vec2(touch_pos.x, mp_initSpotB));
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

