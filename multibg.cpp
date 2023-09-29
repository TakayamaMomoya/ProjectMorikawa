//*****************************************************
//
// 背景の処理[bg.cpp]
// Author:髙山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "main.h"
#include "multibg.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"

//*****************************************************
// マクロ定義
//*****************************************************
#define BG_FRONT	"data\\TEXTURE\\BG\\bg000.png"	        // 一番前の背景
#define BG_MIDDLE	"data\\TEXTURE\\BG\\bg001.png"	        // 真ん中の背景
#define BG_BACK	    "data\\TEXTURE\\BG\\bg002.jpg"	        // 一番後ろの背景

//*****************************************************
// 静的メンバ変数宣言
//*****************************************************
LPDIRECT3DTEXTURE9 CMultiBg::m_pTexture = nullptr;	// テクスチャのポインタ

//=====================================================
// コンストラクタ
//=====================================================
CMultiBg::CMultiBg(int nPriority) : CObject2D(nPriority)
{
	m_fSpeedU = 0.0f;
	m_fSpeedV = 0.0f;
	m_texLeftUp = { 0.0f,0.0f };
	m_texRightDown = { 0.0f,0.0f };
}

//=====================================================
// デストラクタ
//=====================================================
CMultiBg::~CMultiBg()
{

}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CMultiBg::Init(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	for(int nCount = 0; nCount < 3; nCount++)
	{
		if (m_apObject2D[nCount] == NULL)
		{//使用していなかったら

			//生成
			m_apObject2D[nCount] = CObject2D::Create(1, SCREEN_HEIGHT * 0.5f);

			if (nCount == 0)
			{
				int nIdx = CManager::GetTexture()->Regist(BG_BACK);
				m_apObject2D[0]->SetIdxTexture(nIdx);
			}

			if (nCount == 1)
			{
				int nIdx = CManager::GetTexture()->Regist(BG_MIDDLE);
				m_apObject2D[1]->SetIdxTexture(nIdx);
			}

			if (nCount == 2)
			{
				int nIdx = CManager::GetTexture()->Regist(BG_FRONT);
				m_apObject2D[2]->SetIdxTexture(nIdx);
			}

			//初期化処理
			m_apObject2D[nCount]->Init();
		}
	}

	// 継承クラスの初期化
	//CObject2D::Init();

	m_texLeftUp = { 0.0f,0.0f };
	m_texRightDown = { 1.0f,1.0f };

	return S_OK;
}

//=====================================================
// 終了処理
//=====================================================
void CMultiBg::Uninit(void)
{
	// 継承クラスの終了
	//CObject2D::Uninit();

	for (int nCount = 0; nCount < 3; nCount++)
	{
		if (m_apObject2D[nCount] != NULL)
		{
			m_apObject2D[nCount]->Uninit();

			m_apObject2D[nCount] = NULL;
		}
	}
}

//=====================================================
// 更新処理
//=====================================================
void CMultiBg::Update(void)
{
	m_texLeftUp.x += m_fSpeedU;
	m_texLeftUp.y += m_fSpeedV;
	m_texRightDown.x += m_fSpeedU;
	m_texRightDown.y += m_fSpeedV;

	if (m_texLeftUp.x > 1.0f)
	{
		m_texLeftUp.x -= 1.0f;
		m_texRightDown.x -= 1.0f;
	}

	if (m_texLeftUp.y > 1.0f)
	{
		m_texLeftUp.y -= 1.0f;
		m_texRightDown.y -= 1.0f;
	}

	// 継承クラスの更新
	//CObject2D::Update();

	for (int nCount = 0; nCount < 3; nCount++)
	{
		if (m_apObject2D[nCount] != NULL)
		{
			m_apObject2D[nCount]->Update();

			m_apObject2D[nCount]->SetVtx();

			m_apObject2D[nCount]->SetTex(m_texLeftUp, m_texRightDown);
		}
	}

	// 頂点情報設定
	//SetVtx();

	// テクスチャ座標更新
	//SetTex(m_texLeftUp, m_texRightDown);
}

//=====================================================
// 描画処理
//=====================================================
void CMultiBg::Draw(void)
{
	// 継承クラスの描画
	//CObject2D::Draw();

	for (int nCount = 0; nCount < 3; nCount++)
	{
		if (m_apObject2D[nCount] != NULL)
		{
			m_apObject2D[nCount]->Draw();
		}
	}
}

//=====================================================
// 読込処理
//=====================================================
HRESULT CMultiBg::Load(void)
{
	if (m_pTexture == nullptr)
	{
		// デバイスの取得
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
// 破棄処理
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
// スクロール速度設定処理
//=====================================================
void CMultiBg::SetScroll(float fSpeedV, float fSpeedU)
{
	m_fSpeedV = fSpeedV;
	m_fSpeedU = fSpeedU;
}

//=====================================================
// 生成処理
//=====================================================
CMultiBg *CMultiBg::Create(void)
{
	CMultiBg *pBg = nullptr;

	if (pBg == nullptr)
	{// インスタンス生成
		pBg = new CMultiBg;

		// 初期化処理
		pBg->Init();
		pBg->SetSize(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
		pBg->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
	}

	return pBg;
}