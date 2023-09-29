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
#include "game.h"
#include "player.h"
#include "object2D.h"
#include "manager.h"
#include "texture.h"
#include "inputkeyboard.h"
#include "inputjoypad.h"
#include "debugproc.h"
#include "universal.h"
#include "collision.h"
#include "arrow.h"
#include "timer.h"

//*****************************************************
// �}�N����`
//*****************************************************
#define BODY_PATH	"data\\TEXTURE\\CHARACTER\\player.png"	// �����ڂ̃p�X
#define TRAM_PATH	"data\\TEXTURE\\CHARACTER\\tram.png"	// �g���b�R�̃p�X
#define FLOOR_LIMIT	(SCREEN_HEIGHT * 0.9f)	// ���̐���
#define BODY_WIDTH	(60.0f)	// �̂̕�
#define BODY_HEIGHT	(60.0f)	// �̂̍���
#define TRAM_WIDTH	(60.0f)	// �g���b�R�̕�
#define TRAM_HEIGHT	(30.0f)	// �g���b�R�̍���
#define TRAM_POSY	(SCREEN_HEIGHT * 0.89f)	// �g���b�R��Y���W
#define MAX_JUMP (30.0f)	// �W�����v��
#define GRAVITY	(0.98f)	// �d��
#define CHARGE_POWER	(0.010f)	// 1�t���[��������ɗ��܂�W�����v��
#define CHARGE_INTIIAL	(0.5f)	// �����̃W�����v��
#define MAX_CHARGE	(0.5f)	// �`���[�W�̍ő�l
#define JUMP_BUTTON	(DIK_SPACE)	// �W�����v�L�[
#define ROLL_SPEED	(0.6f)	// ��]���x

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
		m_player.pBody->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.2f, SCREEN_HEIGHT * 0.5f, 0.0f));
		m_player.pos = D3DXVECTOR3(SCREEN_WIDTH * 0.2f, SCREEN_HEIGHT * 0.5f, 0.0f);  
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

	if (m_pCollisionSphere == nullptr)
	{// ���̓����蔻�萶��
		m_pCollisionSphere = CCollisionSphere::Create(CCollision::TAG_PLAYER, CCollision::TYPE_SPHERE, this);

		float fRadius;

		if (m_pCollisionSphere != nullptr)
		{// ���̐ݒ�
			fRadius = BODY_HEIGHT;

			m_pCollisionSphere->SetPosition(GetPosition());
			m_pCollisionSphere->SetRadius(fRadius);
		}
	}

	// ���ݒ�
	CArrow::Create();

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

	if (m_pCollisionSphere != nullptr)
	{// �����蔻��̔j��
		m_pCollisionSphere->Uninit();
		m_pCollisionSphere = nullptr;
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

	if (CGame::GetTimer()->GetSecond() > 0)
	{//���Ԃ�������蓮������悤�ɂ���
		// ���쏈��
		Input();
	}
	else if(m_player.bJump == false)
	{
		m_player.move = D3DXVECTOR3(5.0f, 0.0f, 0.0f);
	}

	// �ړ��̊Ǘ�
	ManageMove();

	// �����蔻��Ǘ�
	ManageCollision();

	// �ʒu�̐���
	LimitPos();

	// ��]�̊Ǘ�
	ManageRoll();

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
	if (m_player.bJump == false)
	{
		// �W�����v����
		InputJump();
	}
}

//=====================================================
// �W�����v����
//=====================================================
void CPlayer::InputJump(void)
{
	CInputKeyboard *pKeyboard = CManager::GetKeyboard();
	CInputJoypad *pJoypad = CManager::GetJoypad();

	if (pKeyboard == nullptr || pJoypad == nullptr)
	{// ���͂ɕs���������ʂ�Ȃ�
		return;
	}

	if (pKeyboard->GetPress(JUMP_BUTTON))
	{// �W�����v����
		m_player.fPowJump += CHARGE_POWER;

		if (m_player.fPowJump >= MAX_CHARGE)
		{// �W�����v�͐���
			m_player.fPowJump = MAX_CHARGE;
		}
	}

	if (pKeyboard->GetRelease(JUMP_BUTTON))
	{// �W�����v����
		m_player.move.y -= MAX_JUMP * (m_player.fPowJump + CHARGE_INTIIAL);

		m_player.fPowJump = 0.0f;

		m_player.bJump = true;
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
// �����蔻��Ǘ�
//=====================================================
void CPlayer::ManageCollision(void)
{
	if (m_pCollisionSphere != nullptr)
	{// ���̓����蔻��̊Ǘ�
		m_pCollisionSphere->SetPositionOld(m_pCollisionSphere->GetPosition());

		m_pCollisionSphere->SetPosition(m_player.pos);
	}
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

		if (m_player.bJump)
		{// ���n����
			Land();
		}
	}
}

//=====================================================
// ���n����
//=====================================================
void CPlayer::Land(void)
{
	if (m_player.bJump == false)
	{// ���ɒ��n���Ă�����ʂ�Ȃ�
		return;
	}

	// ���n��Ԃɂ���
	m_player.bJump = false;

	// �̂̌����̃��Z�b�g
	CObject2D *pBody = m_player.pBody;

	if (pBody != nullptr)
	{
		pBody->SetRot(0.0f);

		pBody->SetVtx();
	}
}

//=====================================================
// ��]�̊Ǘ�
//=====================================================
void CPlayer::ManageRoll(void)
{
	// �ėp�����̎擾
	CUniversal *pUniversal = CManager::GetUniversal();

	if (m_player.bJump)
	{// ��]������
		CObject2D *pBody = m_player.pBody;
		float fRot = 0.0f;

		if (pBody == nullptr)
		{
			return;
		}

		// �����擾
		fRot = pBody->GetRot();

		// ��]������
		fRot -= ROLL_SPEED;

		pUniversal->LimitRot(&fRot);	// �p�x����

		pBody->SetRot(fRot);
	}
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
// �q�b�g����
//=====================================================
void CPlayer::Hit(float fDamage)
{
	m_player.move.y += GRAVITY;
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