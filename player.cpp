//*****************************************************
//
// �v���C���[�̏���[player.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "main.h"
#include "player.h"
#include "object2D.h"
#include "manager.h"
#include "texture.h"
#include "inputkeyboard.h"
#include "inputjoypad.h"
#include "debugproc.h"

//*****************************************************
// �}�N����`
//*****************************************************
#define BODY_PATH	"data\\TEXTURE\\CHARACTER\\player.png"	// �����ڂ̃p�X
#define TRAM_PATH	"data\\TEXTURE\\CHARACTER\\tram.png"	// �g���b�R�̃p�X
#define FLOOR_LIMIT	(SCREEN_HEIGHT * 0.9f)	// ���̐���
#define BODY_WIDTH	(50.0f)	// �̂̕�
#define BODY_HEIGHT	(100.0f)	// �̂̍���
#define TRAM_WIDTH	(100.0f)	// �g���b�R�̕�
#define TRAM_HEIGHT	(50.0f)	// �g���b�R�̍���
#define TRAM_POSY	(FLOOR_LIMIT - TRAM_HEIGHT)	// �g���b�R��Y���W
#define MAX_JUMP (30.0f)	// �W�����v��
#define GRAVITY	(0.98f)	// �d��
#define CHARGE_POWER	(0.01f)	// 1�t���[��������ɗ��܂�W�����v��
#define MAX_CHARGE	(1.0f)	// �`���[�W�̍ő�l

//=====================================================
// �D�揇�ʂ����߂�R���X�g���N�^
//=====================================================
CPlayer::CPlayer(int nPriority)
{
	ZeroMemory(&m_player,sizeof(Player));
}

//=====================================================
// �f�X�g���N�^
//=====================================================
CPlayer::~CPlayer()
{

}

//=====================================================
// ����������
//=====================================================
HRESULT CPlayer::Init(void)
{
	// �����ڂ̐���
	m_player.pBody = CObject2D::Create(7);

	if (m_player.pBody != nullptr)
	{
		m_player.pBody->SetSize(BODY_WIDTH, BODY_HEIGHT);
		m_player.pBody->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
		m_player.pos = D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f);  
		int nIdx = CManager::GetTexture()->Regist(BODY_PATH);
		m_player.pBody->SetIdxTexture(nIdx);
		m_player.pBody->SetVtx();
	}

	// �g���b�R�̐���
	m_player.pTram = CObject2D::Create(7);

	if (m_player.pTram != nullptr)
	{
		m_player.pTram->SetSize(TRAM_WIDTH, TRAM_HEIGHT);
		m_player.pTram->SetPosition(D3DXVECTOR3(m_player.pos.x, TRAM_POSY, 0.0f));
		int nIdx = CManager::GetTexture()->Regist(TRAM_PATH);
		m_player.pTram->SetIdxTexture(nIdx);
		m_player.pTram->SetVtx();
	}

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CPlayer::Uninit(void)
{
	if (m_player.pBody != nullptr)
	{// �{�f�B�̔j��
		m_player.pBody->Uninit();
		m_player.pBody = nullptr;
	}

	if (m_player.pTram != nullptr)
	{// �g���b�R�̔j��
		m_player.pTram->Uninit();
		m_player.pTram = nullptr;
	}

	// ���g�̔j��
	Release();
}

//=====================================================
// �X�V����
//=====================================================
void CPlayer::Update(void)
{
	// �O��̈ʒu��ۑ�
	m_player.posOld = m_player.pos;

	// ���쏈��
	Input();

	// �ړ��̊Ǘ�
	ManageMove();

	// �ʒu�̐���
	LimitPos();

	// �̂̒Ǐ]
	FollowBody();

	// �g���b�R�̒Ǐ]
	FollowTram();
}

//=====================================================
// ���쏈��
//=====================================================
void CPlayer::Input(void)
{
	CInputKeyboard *pKeyboard = CManager::GetKeyboard();
	CInputJoypad *pJoypad = CManager::GetJoypad();

	if (pKeyboard == nullptr || pJoypad == nullptr)
	{
		return;
	}

	if (pKeyboard->GetPress(DIK_SPACE))
	{// �W�����v����
		m_player.fPowJump += CHARGE_POWER;

		if (m_player.fPowJump >= MAX_CHARGE)
		{// �W�����v�͐���
			m_player.fPowJump = MAX_CHARGE;
		}
	}

	if (pKeyboard->GetRelease(DIK_SPACE))
	{// �W�����v����
		m_player.move.y -= MAX_JUMP * m_player.fPowJump;

		m_player.fPowJump = 0.0f;
	}
}

//=====================================================
// �ړ��̊Ǘ�
//=====================================================
void CPlayer::ManageMove(void)
{
	// �d��
	m_player.move.y += GRAVITY;

	// �ʒu�Ɉړ��ʂ𔽉f
	m_player.pos += m_player.move;
}

//=====================================================
// �̂�Ǐ]�����鏈��
//=====================================================
void CPlayer::FollowBody(void)
{
	CObject2D *pBody = m_player.pBody;

	if (pBody == nullptr)
	{
		return;
	}

	// �ʒu�����킹��
	pBody->SetPosition(m_player.pos);

	pBody->SetVtx();
}

//=====================================================
// �̂�Ǐ]�����鏈��
//=====================================================
void CPlayer::FollowTram(void)
{
	CObject2D *pTram = m_player.pTram;

	if (pTram == nullptr)
	{
		return;
	}

	// �ʒu�����킹��
	pTram->SetPosition(D3DXVECTOR3(m_player.pos.x, TRAM_POSY, 0.0f));

	pTram->SetVtx();
}

//=====================================================
// �ʒu��������
//=====================================================
void CPlayer::LimitPos(void)
{
	if (m_player.pos.y >= FLOOR_LIMIT - BODY_WIDTH)
	{// ���Ƃ̐���
		m_player.pos.y = FLOOR_LIMIT - BODY_WIDTH;

		m_player.move.y = 0.0f;
	}
}

//=====================================================
// �`�揈��
//=====================================================
void CPlayer::Draw(void)
{
#ifdef _DEBUG
	// �f�o�b�O�\��
	Debug();
#endif
}

//=====================================================
// �f�o�b�O�\��
//=====================================================
void CPlayer::Debug(void)
{
	CDebugProc *pDebugProc = CManager::GetDebugProc();

	if (pDebugProc == nullptr)
	{
		return;
	}

	pDebugProc->Print("\n�W�����v��[%f]",m_player.fPowJump);
}

//=====================================================
// ��������
//=====================================================
CPlayer *CPlayer::Create(void)
{
	CPlayer *pPlayer = nullptr;

	if (pPlayer == nullptr)
	{// �C���X�^���X����
		pPlayer = new CPlayer;

		// ����������
		pPlayer->Init();
	}

	return pPlayer;
}