///-------------------------------------------------------------------
//*
//*	@�쐬��		2017/01/18
//*
//*	@���O		PlayScene.h
//*
//*	@����		���� ���n
//*
///-------------------------------------------------------------------

// ���d�C���N���[�h�̖h�~
#pragma once

// �w�b�_�[�t�@�C���̃C���N���[�h
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
//#include "Player\Player.h"
//#include "Scraps\ScrapA.h"


class PlayScene : public cocos2d::Scene
{
private:

	////////////////////////
	/// �v���C���p�̕ϐ� ///
	////////////////////////
	// �X�N���b�v���쎞�́A�㕔���̒�~�ꏊ
	float mp_workSpotA = 340.0f;

	// �X�N���b�v���쎞�́A�������̒�~�ꏊ
	float mp_workSpotB = 320.0f;

	// �����ʒu�֖߂鎞�́A�㕔���̒�~�ꏊ
	float mp_initSpotA = 510.0f;;

	// �����ʒu�֖߂鎞�́A�������̒�~�ꏊ
	float mp_initSpotB = 130.0f;;

	// �X�N���b�v���쎞�̑��x
	float mp_workSpeed;

	// �����ʒu�֖߂鎞�̑��x
	float mp_initSpeed;

	// �v���C���̌��݈ʒu
	cocos2d::Vec2 mp_playerPos;

	// �A�N�V���������ۂ��i�A�N�V�������Ȃ�A�ǂꂭ�炢�����Ă��邩�̐��l������j
	int mp_isAction;
	

	////////////////////
	/// �W�I�p�̕ϐ� ///
	////////////////////

	// �G�̏����ʒu�iinit�Ń����_�����j
	int mt_initPos;

	int mt_targetPos;



public:
	// create�֐��̐錾�ƒ�`
	static PlayScene* create();

	// �^�b�`�C�x���g���X�i�[
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * unused_event);
	void onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * unused_event);

	// ������
	bool init();
	// �X�V
	void update(float delta) override;



	//////////////////////////////
	/// �X�v���C�g�E�m�[�h�o�^ ///
	//////////////////////////////

	// �v���C���i�X�N���b�p�㑤�j
	cocos2d::Sprite* scrapperA;
	// �v���C���i�X�N���b�p�����j
	cocos2d::Sprite* scrapperB;
	// �v���C���i�����m�[�h�j
	cocos2d::Node* scrappers;



	// �G�i�X�N���b�vA�j
	cocos2d::Sprite* scrapA;
	// �G�i�X�N���b�vB�j
	cocos2d::Sprite* scrapB;
	// �G�i�X�N���b�vC�j
	cocos2d::Sprite* scrapC;
	// �G�j��G�t�F�N�g
	cocos2d::Sprite* boom;



	// �X�e�[�W
	cocos2d::Sprite* stage;

};

