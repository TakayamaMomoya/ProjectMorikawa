//*****************************************************
//
// ゲーム処理[game.cpp]
// Author:髙山桃也
//
//*****************************************************

//*****************************************************
// インクルード
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
// マクロ定義
//*****************************************************
#define TEXTURE_PATH	"data\\TEXTURE\\BG\\tutorial.jpg"	// テクスチャのパス

//=====================================================
// コンストラクタ
//=====================================================
CTutorial::CTutorial()
{

}

//=====================================================
// デストラクタ
//=====================================================
CTutorial::~CTutorial()
{

}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CTutorial::Init(void)
{
	// 一枚絵の生成
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
// 終了処理
//=====================================================
void CTutorial::Uninit(void)
{
	// オブジェクト全破棄
	CObject::ReleaseAll();
}

//=====================================================
// 更新処理
//=====================================================
void CTutorial::Update(void)
{
	// 情報取得
	CInputKeyboard *pKeyboard = CManager::GetKeyboard();

	CFade *pFade = CManager::GetFade();

	if (pKeyboard != nullptr)
	{
		if (pKeyboard->GetTrigger(DIK_RETURN))
		{// フェード
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
// 描画処理
//=====================================================
void CTutorial::Draw(void)
{

}