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

//*****************************************************
// �}�N����`
//*****************************************************
#define BODY_PATH	"data\\TEXTURE\\CHARACTER\\player.png"	// �����ڂ̃p�X
#define BODY_WIDTH	(50.0f)	// �̂̕�
#define BODY_HEIGHT	(100.0f)	// �̂̍���

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
	m_player.m_pBody = CObject2D::Create(7);

	if (m_player.m_pBody != nullptr)
	{
		m_player.m_pBody->SetSize(BODY_WIDTH, BODY_HEIGHT);
		m_player.m_pBody->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));

		int nIdx = CManager::GetTexture()->Regist(BODY_PATH);
		m_player.m_pBody->SetIdxTexture(nIdx);
		m_player.m_pBody->SetVtx();
	}

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CPlayer::Uninit(void)
{
	if (m_player.m_pBody != nullptr)
	{// �{�f�B�̔j��
		m_player.m_pBody->Uninit();
		m_player.m_pBody = nullptr;
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
	m_player.m_posOld = m_player.m_pos;

	// ���쏈��
	Input();

	// �̂̌����ڂ�Ǐ]������
	FollowBody();
}

//=====================================================
// ���쏈��
//=====================================================
void CPlayer::Input(void)
{

}

//=====================================================
// �̂̌����ڂ�Ǐ]�����鏈��
//=====================================================
void CPlayer::FollowBody(void)
{

}

//=====================================================
// �`�揈��
//=====================================================
void CPlayer::Draw(void)
{

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