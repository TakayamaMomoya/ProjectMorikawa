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
#include "tutorial.h"
#include "object.h"
#include "universal.h"
#include "particle.h"
#include "inputkeyboard.h"
#include "inputjoypad.h"
#include "fade.h"
#include "camera.h"
#include "objectmanager.h"
#include "game.h"
#include "texture.h"

//*****************************************************
// �}�N����`
//*****************************************************
#define TEXTURE_PATH	"data\\TEXTURE\\BG\\tutorial.jpg"	// �e�N�X�`���̃p�X

//=====================================================
// �R���X�g���N�^
//=====================================================
CTutorial::CTutorial()
{

}

//=====================================================
// �f�X�g���N�^
//=====================================================
CTutorial::~CTutorial()
{

}

//=====================================================
// ����������
//=====================================================
HRESULT CTutorial::Init(void)
{
	// �ꖇ�G�̐���
	CObject2D *m_pObj = CObject2D::Create(7);

	if (m_pObj != nullptr)
	{
		m_pObj->SetSize(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
		m_pObj->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));

		int nIdx = CManager::GetTexture()->Regist(TEXTURE_PATH);
		m_pObj->SetIdxTexture(nIdx);
		m_pObj->SetVtx();
	}

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CTutorial::Uninit(void)
{
	// �I�u�W�F�N�g�S�j��
	CObject::ReleaseAll();
}

//=====================================================
// �X�V����
//=====================================================
void CTutorial::Update(void)
{
	// ���擾
	CInputKeyboard *pKeyboard = CManager::GetKeyboard();

	CFade *pFade = CManager::GetFade();

	if (pKeyboard != nullptr)
	{
		if (pKeyboard->GetTrigger(DIK_RETURN))
		{// �t�F�[�h
			if (pFade != nullptr)
			{
				if (pFade->GetState() == CFade::FADE_NONE)
				{
					pFade->SetFade(CScene::MODE_GAME);
				}
			}
		}
	}
}

//=====================================================
// �`�揈��
//=====================================================
void CTutorial::Draw(void)
{

}