//*****************************************************
//
// ”wŒi‚Ìˆ—[bg.cpp]
// Author:ûüŽR“–ç
//
//*****************************************************

//*****************************************************
// ƒCƒ“ƒNƒ‹[ƒh
//*****************************************************
#include "main.h"
#include "multibg.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"

//*****************************************************
// ƒ}ƒNƒ’è‹`
//*****************************************************
#define BG_FRONT	"data\\TEXTURE\\BG\\bg000.png"	        // ˆê”Ô‘O‚Ì”wŒi
#define BG_MIDDLE	"data\\TEXTURE\\BG\\bg001.png"	        // ^‚ñ’†‚Ì”wŒi
#define BG_BACK	    "data\\TEXTURE\\BG\\bg002.png"	        // ˆê”ÔŒã‚ë‚Ì”wŒi
#define BG_MIDSPEED  (0.002f)                               // ^‚ñ’†‚Ì”wŒi‚Ì‘¬“x
#define BG_FROSPEED  (0.003f)                               // ˆê”Ô‘O‚Ì”wŒi‚Ì‘¬“x

//*****************************************************
// Ã“Iƒƒ“ƒo•Ï”éŒ¾
//*****************************************************
LPDIRECT3DTEXTURE9 CMultiBg::m_pTexture = nullptr;	// ƒeƒNƒXƒ`ƒƒ‚Ìƒ|ƒCƒ“ƒ^

//=====================================================
// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
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
// ƒfƒXƒgƒ‰ƒNƒ^
//=====================================================
CMultiBg::~CMultiBg()
{

}

//=====================================================
// ‰Šú‰»ˆ—
//=====================================================
HRESULT CMultiBg::Init(void)
{
	// ƒfƒoƒCƒX‚ÌŽæ“¾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_Multibg.pBack = CObject2D::Create(PRIORITY_BG);

	// ˆê”ÔŒã‚ë‚Ì”wŒi
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

	// ^‚ñ’†‚Ì”wŒi
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

	// ˆê”Ô‘O‚Ì”wŒi
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
// I—¹ˆ—
//=====================================================
void CMultiBg::Uninit(void)
{
	if (m_Multibg.pBack != nullptr)
	{// ƒ{ƒfƒB‚Ì”jŠü
		m_Multibg.pBack->Uninit();
		m_Multibg.pBack = nullptr;
	}

	if (m_Multibg.pMiddle != nullptr)
	{// ƒgƒƒbƒR‚Ì”jŠü
		m_Multibg.pMiddle->Uninit();
		m_Multibg.pMiddle = nullptr;
	}

	if (m_Multibg.pFront != nullptr)
	{// ƒgƒƒbƒR‚Ì”jŠü
		m_Multibg.pFront->Uninit();
		m_Multibg.pFront = nullptr;
	}

	// Œp³ƒNƒ‰ƒX‚ÌI—¹
	CObject2D::Uninit();
}

//=====================================================
// XVˆ—
//=====================================================
void CMultiBg::Update(void)
{
	m_fSpeedU = 0.001f;

	// ˆê”ÔŒã‚ë‚Ì”wŒi
	m_texBackLeftUp.x += m_fSpeedU;
	m_texBackLeftUp.y += m_fSpeedV;
	m_texBackRightDown.x += m_fSpeedU;
	m_texBackRightDown.y += m_fSpeedV;

	// ^‚ñ’†‚Ì”wŒi
	m_texMiddleLeftUp.x += (m_fSpeedU + BG_MIDSPEED);
	m_texMiddleLeftUp.y += m_fSpeedV;
	m_texMiddleRightDown.x += (m_fSpeedU + BG_MIDSPEED);
	m_texMiddleRightDown.y += m_fSpeedV;

	// ˆê”Ô‘O‚Ì”wŒi
	m_texFrontLeftUp.x += (m_fSpeedU + BG_FROSPEED);
	m_texFrontLeftUp.y += m_fSpeedV;
	m_texFrontRightDown.x += (m_fSpeedU + BG_FROSPEED);
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

	// ˆê”ÔŒã‚ë‚Ì”wŒi
	if (m_Multibg.pBack != nullptr)
	{
		m_Multibg.pBack->Update();
		m_Multibg.pBack->SetVtx();
		m_Multibg.pBack->SetTex(m_texBackLeftUp, m_texBackRightDown);
	}

	// ^‚ñ’†‚Ì”wŒi
	if (m_Multibg.pMiddle != nullptr)
	{
		m_Multibg.pMiddle->Update();
		m_Multibg.pMiddle->SetVtx();
		m_Multibg.pMiddle->SetTex(m_texMiddleLeftUp, m_texMiddleRightDown);
	}

	// ˆê”Ô‘O‚Ì”wŒi
	if (m_Multibg.pFront != nullptr)
	{
		m_Multibg.pFront->Update();
		m_Multibg.pFront->SetVtx();
		m_Multibg.pFront->SetTex(m_texFrontLeftUp, m_texFrontRightDown);
	}
}

//=====================================================
// •`‰æˆ—
//=====================================================
void CMultiBg::Draw(void)
{
	// Œp³ƒNƒ‰ƒX‚Ì•`‰æ
	//CObject2D::Draw();
}

//=====================================================
// “Çžˆ—
//=====================================================
HRESULT CMultiBg::Load(void)
{
	if (m_pTexture == nullptr)
	{
		// ƒfƒoƒCƒX‚ÌŽæ“¾
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
// ”jŠüˆ—
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
// ƒXƒNƒ[ƒ‹‘¬“xÝ’èˆ—
//=====================================================
void CMultiBg::SetScroll(float fSpeedV, float fSpeedU)
{
	m_fSpeedV = fSpeedV;
	m_fSpeedU = fSpeedU;
}

//=====================================================
// ¶¬ˆ—
//=====================================================
CMultiBg *CMultiBg::Create(void)
{
	CMultiBg *pBg = nullptr;

	if (pBg == nullptr)
	{// ƒCƒ“ƒXƒ^ƒ“ƒX¶¬
		pBg = new CMultiBg;

		// ‰Šú‰»ˆ—
		pBg->Init();
		//pBg->SetSize(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
		//pBg->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
	}

	return pBg;
}