//*****************************************************
//
// �Q�[������[game.h]
// Author:���R����
//
//*****************************************************
#ifndef _GAME_H_
#define _GAME_H_

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "main.h"
#include "scene.h"

//*****************************************************
// �O���錾
//*****************************************************
class CScore;
class CTimer;
class CPlayer;
class CGame;
class CBlockManager;
class CMultiBg;
class CNumber;
class CObject2D;

//*****************************************************
// �N���X�̒�`
//*****************************************************
class CGame : public CScene
{
public:
	enum STATE
	{// ���
		STATE_NONE,	// �������Ă��Ȃ����
		STATE_NORMAL,	// �ʏ���
		STATE_RESULT,	// ���U���g���
		STATE_END,	// �I�����
		STATE_MAX
	};

	CGame();	// �R���X�g���N�^
	~CGame();	// �f�X�g���N�^

	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update();
	virtual void Draw();
	static CScore *GetScore(void) { return m_pScore; }
	static CTimer *GetTimer(void) { return m_pTimer; }
	static CPlayer *GetPlayer(void) { return m_pPlayer; }
	static CBlockManager *GetBlockManager(void) { return m_pBlockManager; }
	static void ReleaseScore(void);
	static void ReleaseTimer(void);
	static void SetState(STATE state) { m_state = state; }
	static STATE GetState(void) { return m_state; }
	static float GetGameSpeed(void) { return m_fGameSpeed; }

private:
	void ManageSpeed(void);

	static CScore *m_pScore;	// �X�R�A�̃|�C���^
	static CTimer *m_pTimer;	// �^�C�}�[�̃|�C���^
	static CPlayer *m_pPlayer;	// �v���C���[�̃|�C���^
	static CBlockManager *m_pBlockManager;	//�u���b�N�}�l�[�W��
	static CMultiBg *m_pMultiBg;
	static CObject2D* m_pResult;	//���U���g����
	static CNumber* m_pResultScore;	//���U���g�̃X�R�A
	static STATE m_state;	// ���
	static float m_fGameSpeed;	// �Q�[���̃X�s�[�h
	int m_nCntSecond;	// ��b�J�E���^�[
};

#endif