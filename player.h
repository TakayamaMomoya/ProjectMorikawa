//*****************************************************
//
// �v���C���[�̏���[player.cpp]
// Author:���R����
//
//*****************************************************

#ifndef _PLAYER_H_
#define _PLAYER_H_

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "motion.h"

//*****************************************************
// �O���錾
//*****************************************************
class CObject2D;

//*****************************************************
// �N���X�̒�`
//*****************************************************
class CPlayer : public CObject
{
public:
	struct Player
	{// �v���C���[���
		CObject2D *pBody;	// �̂̌�����
		D3DXVECTOR3 pos;	// �ʒu
		D3DXVECTOR3 posOld;	// �O��̈ʒu
		D3DXVECTOR3 move;	// �ړ���
		float fPowJump;	// �W�����v�J�E���^�[
	};

	CPlayer(int nPriority = 4);	// �R���X�g���N�^
	~CPlayer();	// �f�X�g���N�^

	static CPlayer *Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	Player *GetInfo(void) { return &m_player; }

private:
	void Input(void);	// ���쏈��
	void ManageMove(void);	// �ړ��̊Ǘ�
	void FollowBody(void);	// �̂�Ǐ]�����鏈��
	void LimitPos(void);	// �ʒu��������
	void Debug(void);	// �f�o�b�O�\��

	Player m_player;	// �v���C���[���
};

#endif
