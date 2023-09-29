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
		CObject2D *m_pBody;	// �̂̌�����
		D3DXVECTOR3 m_pos;	// �ʒu
		D3DXVECTOR3 m_posOld;	// �O��̈ʒu
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
	void FollowBody(void);	// �̂�Ǐ]�����鏈��

	Player m_player;	// �v���C���[���
};

#endif
