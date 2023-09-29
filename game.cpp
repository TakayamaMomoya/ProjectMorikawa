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

//*****************************************************
// �}�N����`
//*****************************************************

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
CScore *CGame::m_pScore = nullptr;	// �X�R�A�̃|�C���^
CTimer *CGame::m_pTimer = nullptr;	// �^�C�}�[�̃|�C���^
CBlockManager *CGame::m_pBlockManager = nullptr;	//�u���b�N�}�l�[�W���̃|�C���^
CGame::STATE CGame::m_state = STATE_NONE;

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
	CObjectManager *pObjManager = CManager::GetObjectManager();

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
	}

	if (m_pBlockManager == nullptr)
	{//�u���b�N�}�l�[�W������
		m_pBlockManager = CBlockManager::Create();
		m_pBlockManager->SetSpeed(1.0f);
	}

	// �v���C���[����
	CPlayer::Create();

	//�u���b�N���u��
	CBlock* pBlock = CBlock::Create();
	pBlock->SetSize(32.0f, 32.0f);
	pBlock->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));

	int nIdx = CManager::GetTexture()->Regist("data\\TEXTURE\\Block_R_01.png");
	pBlock->SetIdxTexture(nIdx);
	pBlock->SetVtx();

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CGame::Uninit(void)
{
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
	{// �X�R�A�̏I���E�j��
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

	if (pKeyboard != nullptr)
	{
		if (pKeyboard->GetTrigger(DIK_RETURN))
		{
			if (pFade != nullptr)
			{
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