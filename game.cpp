//*****************************************************
//
// �Q�[������[game.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "manager.h"
#include "renderer.h"
#include "texture.h"
#include "game.h"
#include "score.h"
#include "timer.h"
#include "object.h"
#include "universal.h"
#include "particle.h"
#include "inputkeyboard.h"
#include "inputjoypad.h"
#include "fade.h"
#include "camera.h"
#include "effect3D.h"
#include "objectmanager.h"
#include "sound.h"
#include "scene.h"
#include "player.h"
#include "block.h"
#include "blockmanager.h"
#include "multibg.h"

//*****************************************************
// �}�N����`
//*****************************************************
#define BLOCK_SPEED	(3.0f)	// �u���b�N�̗���鑬�x

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
CScore *CGame::m_pScore = nullptr;	// �X�R�A�̃|�C���^
CTimer *CGame::m_pTimer = nullptr;	// �^�C�}�[�̃|�C���^
CPlayer *CGame::m_pPlayer = nullptr;	// �v���C���[�̃|�C���^
CBlockManager *CGame::m_pBlockManager = nullptr;	//�u���b�N�}�l�[�W���̃|�C���^
CMultiBg *CGame::m_pMultiBg = nullptr;
CObject2D* CGame::m_pResult = nullptr;		//���U���g�����̃|�C���^
CNumber* CGame::m_pResultScore = nullptr;	//���U���g�X�R�A�̃|�C���^
CGame::STATE CGame::m_state = STATE_NONE;	// �Q�[�����
float CGame::m_fGameSpeed = 0.0f;	// �Q�[���X�s�[�h

//=====================================================
// �R���X�g���N�^
//=====================================================
CGame::CGame()
{

}

//=====================================================
// �f�X�g���N�^
//=====================================================
CGame::~CGame()
{

}

//=====================================================
// ����������
//=====================================================
HRESULT CGame::Init(void)
{
	m_fGameSpeed = 1.0f;

	CObjectManager *pObjManager = CManager::GetObjectManager();

	if (m_pMultiBg == nullptr)
	{// ���d�w�i����
		m_pMultiBg = CMultiBg::Create();
	}

	if (m_pScore == nullptr)
	{// �X�R�A����
		m_pScore = CScore::Create();
	}

	if (m_pScore != nullptr)
	{// �X�R�A������
		m_pScore->Init();
	}

	if (m_pTimer == nullptr)
	{// �^�C�}�[����
		m_pTimer = CTimer::Create();
		SetState(STATE_NORMAL);
	}

	if (m_pBlockManager == nullptr)
	{//�u���b�N�}�l�[�W������
		m_pBlockManager = CBlockManager::Create();
		m_pBlockManager->SetSpeed(BLOCK_SPEED);
	}

	if (m_pPlayer == nullptr)
	{
		// �v���C���[����
		m_pPlayer = CPlayer::Create();
	}

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CGame::Uninit(void)
{
	if (m_pMultiBg != nullptr)
	{// ���d�w�i�̏I���E�j��
		m_pMultiBg->Uninit();

		m_pMultiBg = nullptr;
	}

	if (m_pScore != nullptr)
	{// �X�R�A�̏I���E�j��
		m_pScore->Uninit();

		m_pScore = nullptr;
	}

	if (m_pTimer != nullptr)
	{// �^�C�}�[�̏I���E�j��
		m_pTimer->Uninit();

		m_pTimer = nullptr;
	}

	if (m_pPlayer != nullptr)
	{// �v���C���[�̏I���E�j��
		m_pPlayer->Uninit();

		m_pPlayer = nullptr;
	}

	if (m_pBlockManager != nullptr)
	{// �u���b�N�Ǘ��̔j��
		m_pBlockManager->Uninit();

		m_pBlockManager = nullptr;
	}

	if (m_pResult != nullptr)
	{// ���U���g�����̔j��
		m_pResult->Uninit();

		m_pResult = nullptr;
	}

	if (m_pResultScore != nullptr)
	{// ���U���g�X�R�A�̔j��
		m_pResultScore->Uninit();

		m_pResultScore = nullptr;
	}

	// �I�u�W�F�N�g�S��
	CObject::ReleaseAll();
}

//=====================================================
// �X�R�A�I������
//=====================================================
void CGame::ReleaseScore(void)
{
	if (m_pScore != nullptr)
	{// �X�R�A�̏I���E�j��
		m_pScore = nullptr;
	}
}

//=====================================================
// �^�C�}�[�I������
//=====================================================
void CGame::ReleaseTimer(void)
{
	if (m_pTimer != nullptr)
	{// �^�C�}�[�̏I���E�j��
		m_pTimer = nullptr;
	}
}

//=====================================================
// �X�V����
//=====================================================
void CGame::Update(void)
{
	// ���͎擾
	CInputKeyboard *pKeyboard = CManager::GetKeyboard();
	CInputJoypad *pJoypad = CManager::GetJoypad();

	CFade *pFade = CManager::GetFade();

	CCamera *pCamera = CManager::GetCamera();

	// �V�[���̍X�V
	CScene::Update();

	if (m_pTimer->GetSecond() <= 0)
	{
		if (m_pScore != nullptr)
		{// �X�R�A�ۑ�
			CManager::SetScore(m_pScore->GetScore());
		}
		m_fGameSpeed = 0.0f;

		m_pBlockManager->SetSpeed(0.0f);

		CPlayer::Player* pPlayerInfo = m_pPlayer->GetInfo();
		if (pPlayerInfo->pos.x - pPlayerInfo->pTram->GetWidth() >= SCREEN_WIDTH && pFade->GetState() == CFade::FADE_NONE)
		{//��ʊO�ɏo��
			if (m_pResult == nullptr && m_pResultScore == nullptr)
			{//���U���g�\��
				//���U���g����
				m_pResult = CObject2D::Create(CObject::PRIORITY_UI);
				m_pResult->SetSize(444.0f, 78.0f);
				m_pResult->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, 300.0f, 0.0f));
				m_pResult->SetIdxTexture(CManager::GetTexture()->Regist("data\\TEXTURE\\UI\\yourscore.png"));
				m_pResult->SetVtx();

				//���U���g�X�R�A
				m_pResultScore = CNumber::Create(6, m_pScore->GetScore());
				m_pResultScore->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, 420.0f, 0.0f));
				m_pResultScore->SetSizeAll(40.0f, 40.0f);

			}

			if (pKeyboard != nullptr && pKeyboard->GetTrigger(DIK_RETURN) && pFade != nullptr)
			{//�����L���O�J��
				pFade->SetFade(CScene::MODE_RANKING);
			}
		}
	}
}

//=====================================================
// �`�揈��
//=====================================================
void CGame::Draw(void)
{

}