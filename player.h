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
class CCollisionSphere;

//*****************************************************
// �N���X�̒�`
//*****************************************************
class CPlayer : public CObject
{
public:
	struct Player
	{// �v���C���[���
		CObject2D *pBody;	// �̂̌�����
		CObject2D *pTram;	// �g���b�R�̌�����
		D3DXVECTOR3 pos;	// �ʒu
		D3DXVECTOR3 posOld;	// �O��̈ʒu
		D3DXVECTOR3 move;	// �ړ���
		float fPowJump;	// �W�����v�J�E���^�[
		bool bJump;	// �W�����v�t���O
	};

	CPlayer(int nPriority = 4);	// �R���X�g���N�^
	~CPlayer();	// �f�X�g���N�^

	static CPlayer *Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	Player *GetInfo(void) { return &m_player; }
	void Hit(float fDamage);

private:
	void Input(void);	// ���쏈��
	void InputJump(void);	// �W�����v����
	void ManageMove(void);	// �ړ��̊Ǘ�
	void ManageCollision(void);	// �����蔻��Ǘ�
	void FollowBody(void);	// �̂�Ǐ]�����鏈��
	void FollowTram(void);	// �g���b�R��Ǐ]�����鏈��
	void LimitPos(void);	// �ʒu��������
	void Land(void);	// ���n����
	void ManageRoll(void);	// ��]�̊Ǘ�
	void Debug(void);	// �f�o�b�O�\��

	Player m_player;	// �v���C���[���
	CCollisionSphere *m_pCollisionSphere;	// ���̓����蔻��
};

#endif
