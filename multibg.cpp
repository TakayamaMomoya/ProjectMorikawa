//*****************************************************
//
// �w�i�̏���[bg.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "main.h"
#include "multibg.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"
#include "game.h"

//*****************************************************
// �}�N����`
//*****************************************************
#define BG_FRONT	"data\\TEXTURE\\BG\\bg000.png"	        // ��ԑO�̔w�i
#define BG_MIDDLE	"data\\TEXTURE\\BG\\bg001.png"	        // �^�񒆂̔w�i
#define BG_BACK	    "data\\TEXTURE\\BG\\bg002.png"	        // ��Ԍ��̔w�i
#define BG_MIDSPEED  (0.0012f)                               // �^�񒆂̔w�i�̑��x
#define BG_FROSPEED  (0.0013f)                               // ��ԑO�̔w�i�̑��x

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
LPDIRECT3DTEXTURE9 CMultiBg::m_pTexture = nullptr;	// �e�N�X�`���̃|�C���^

//=====================================================
// �R���X�g���N�^
//=====================================================
CMultiBg::CMultiBg(int nPriority) : CObject2D(nPriority)
{
	ZeroMemory(&m_Multibg, sizeof(MultiBg));
	m_fSpeedU = 0.0f;
	m_fSpeedV = 0.0f;
	m_texFrontLeftUp = { 0.0f,0.0f };
	m_texFrontRightDown = { 0.0f,0.0f };
	m_texMiddleLeftUp = { 0.0f,0.0f };
	m_texMiddleRightDown = { 0.0f,0.0f };
	m_texBackLeftUp = { 0.0f,0.0f };
	m_texBackRightDown = { 0.0f,0.0f };
}

//=====================================================
// �f�X�g���N�^
//=====================================================
CMultiBg::~CMultiBg()
{

}

//=====================================================
// ����������
//=====================================================
HRESULT CMultiBg::Init(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_Multibg.pBack = CObject2D::Create(PRIORITY_BG);

	// ��Ԍ��̔w�i
	if (m_Multibg.pBack != nullptr)
	{
		m_Multibg.pBack->Init();
		m_Multibg.pBack->SetSize(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
		m_Multibg.pBack->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
		int nIdx = CManager::GetTexture()->Regist(BG_BACK);
		m_Multibg.pBack->SetIdxTexture(nIdx);
		m_Multibg.pBack->SetVtx();
	}

	m_Multibg.pMiddle = CObject2D::Create(PRIORITY_BG);

	// �^�񒆂̔w�i
	if (m_Multibg.pBack != nullptr)
	{
		m_Multibg.pMiddle->Init();
		m_Multibg.pMiddle->SetSize(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
		m_Multibg.pMiddle->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
		int nIdx = CManager::GetTexture()->Regist(BG_MIDDLE);
		m_Multibg.pMiddle->SetIdxTexture(nIdx);
		m_Multibg.pMiddle->SetVtx();
	}

	m_Multibg.pFront = CObject2D::Create(PRIORITY_BG);

	// ��ԑO�̔w�i
	if (m_Multibg.pFront != nullptr)
	{
		m_Multibg.pFront->Init();
		m_Multibg.pFront->SetSize(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
		m_Multibg.pFront->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
		int nIdx = CManager::GetTexture()->Regist(BG_FRONT);
		m_Multibg.pFront->SetIdxTexture(nIdx);
		m_Multibg.pFront->SetVtx();
	}

	//m_texLeftUp = { 0.0f,0.0f };
	//m_texRightDown = { 1.0f,1.0f };
	m_texBackRightDown = { 1.0f,1.0f };
	m_texMiddleRightDown = { 1.0f,1.0f };
	m_texFrontRightDown = { 1.0f,1.0f };

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CMultiBg::Uninit(void)
{
	if (m_Multibg.pBack != nullptr)
	{// �{�f�B�̔j��
		m_Multibg.pBack->Uninit();
		m_Multibg.pBack = nullptr;
	}

	if (m_Multibg.pMiddle != nullptr)
	{// �g���b�R�̔j��
		m_Multibg.pMiddle->Uninit();
		m_Multibg.pMiddle = nullptr;
	}

	if (m_Multibg.pFront != nullptr)
	{// �g���b�R�̔j��
		m_Multibg.pFront->Uninit();
		m_Multibg.pFront = nullptr;
	}

	// �p���N���X�̏I��
	CObject2D::Uninit();
}

//=====================================================
// �X�V����
//=====================================================
void CMultiBg::Update(void)
{
	m_fSpeedU = 0.001f;
	float fSpeed = CGame::GetGameSpeed();

	// ��Ԍ��̔w�i
	m_texBackLeftUp.x += m_fSpeedU * fSpeed;
	m_texBackLeftUp.y += m_fSpeedV;
	m_texBackRightDown.x += m_fSpeedU * fSpeed;
	m_texBackRightDown.y += m_fSpeedV;

	// �^�񒆂̔w�i
	m_texMiddleLeftUp.x += (m_fSpeedU + BG_MIDSPEED) * fSpeed;
	m_texMiddleLeftUp.y += m_fSpeedV;
	m_texMiddleRightDown.x += (m_fSpeedU + BG_MIDSPEED) * fSpeed;
	m_texMiddleRightDown.y += m_fSpeedV;

	// ��ԑO�̔w�i
	m_texFrontLeftUp.x += (m_fSpeedU + BG_FROSPEED) * fSpeed;
	m_texFrontLeftUp.y += m_fSpeedV;
	m_texFrontRightDown.x += (m_fSpeedU + BG_FROSPEED) * fSpeed;
	m_texFrontRightDown.y += m_fSpeedV;

	if (m_texBackLeftUp.x > 1.0f)
	{
		m_texBackLeftUp.x -= 1.0f;
		m_texBackRightDown.x -= 1.0f;
	}

	if (m_texBackLeftUp.y > 1.0f)
	{
		m_texBackLeftUp.y -= 1.0f;
		m_texBackRightDown.y -= 1.0f;
	}

	if (m_texMiddleLeftUp.x > 1.0f)
	{
		m_texMiddleLeftUp.x -= 1.0f;
		m_texMiddleRightDown.x -= 1.0f;
	}

	if (m_texMiddleLeftUp.y > 1.0f)
	{
		m_texMiddleLeftUp.y -= 1.0f;
		m_texMiddleRightDown.y -= 1.0f;
	}

	if (m_texFrontLeftUp.x > 1.0f)
	{
		m_texFrontLeftUp.x -= 1.0f;
		m_texFrontRightDown.x -= 1.0f;
	}

	if (m_texFrontLeftUp.y > 1.0f)
	{
		m_texFrontLeftUp.y -= 1.0f;
		m_texFrontRightDown.y -= 1.0f;
	}

	// ��Ԍ��̔w�i
	if (m_Multibg.pBack != nullptr)
	{
		m_Multibg.pBack->Update();
		m_Multibg.pBack->SetVtx();
		m_Multibg.pBack->SetTex(m_texBackLeftUp, m_texBackRightDown);
	}

	// �^�񒆂̔w�i
	if (m_Multibg.pMiddle != nullptr)
	{
		m_Multibg.pMiddle->Update();
		m_Multibg.pMiddle->SetVtx();
		m_Multibg.pMiddle->SetTex(m_texMiddleLeftUp, m_texMiddleRightDown);
	}

	// ��ԑO�̔w�i
	if (m_Multibg.pFront != nullptr)
	{
		m_Multibg.pFront->Update();
		m_Multibg.pFront->SetVtx();
		m_Multibg.pFront->SetTex(m_texFrontLeftUp, m_texFrontRightDown);
	}
}

//=====================================================
// �`�揈��
//=====================================================
void CMultiBg::Draw(void)
{
	// �p���N���X�̕`��
	//CObject2D::Draw();
}

//=====================================================
// �Ǎ�����
//=====================================================
HRESULT CMultiBg::Load(void)
{
	if (m_pTexture == nullptr)
	{
		// �f�o�C�X�̎擾
		LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

		D3DXCreateTextureFromFile
		(
			pDevice,
			"data\\TEXTURE\\BG\\bg101.jpg",
			&m_pTexture
		);
	}

	return S_OK;
}

//=====================================================
// �j������
//=====================================================
void CMultiBg::Unload(void)
{
	if (m_pTexture != nullptr)
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
	}
}

//=====================================================
// �X�N���[�����x�ݒ菈��
//=====================================================
void CMultiBg::SetScroll(float fSpeedV, float fSpeedU)
{
	m_fSpeedV = fSpeedV;
	m_fSpeedU = fSpeedU;
}

//=====================================================
// ��������
//=====================================================
CMultiBg *CMultiBg::Create(void)
{
	CMultiBg *pBg = nullptr;

	if (pBg == nullptr)
	{// �C���X�^���X����
		pBg = new CMultiBg;

		// ����������
		pBg->Init();
		//pBg->SetSize(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
		//pBg->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
	}

	return pBg;
}