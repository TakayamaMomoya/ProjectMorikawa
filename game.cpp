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
// マクロ定義
//*****************************************************
#define BLOCK_SPEED	(3.0f)	// ブロックの流れる速度

//*****************************************************
// 静的メンバ変数宣言
//*****************************************************
CScore *CGame::m_pScore = nullptr;	// スコアのポインタ
CTimer *CGame::m_pTimer = nullptr;	// タイマーのポインタ
CBlockManager *CGame::m_pBlockManager = nullptr;	//ブロックマネージャのポインタ
CGame::STATE CGame::m_state = STATE_NONE;

//=====================================================
// コンストラクタ
//=====================================================
CGame::CGame()
{

}

//=====================================================
// デストラクタ
//=====================================================
CGame::~CGame()
{

}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CGame::Init(void)
{
	CObjectManager *pObjManager = CManager::GetObjectManager();

	if (m_pScore == nullptr)
	{// スコア生成
		m_pScore = CScore::Create();
	}

	if (m_pScore != nullptr)
	{// スコア初期化
		m_pScore->Init();
	}

	if (m_pTimer == nullptr)
	{// タイマー生成
		m_pTimer = CTimer::Create();
		SetState(STATE_NORMAL);
	}

	if (m_pBlockManager == nullptr)
	{//ブロックマネージャ生成
		m_pBlockManager = CBlockManager::Create();
		m_pBlockManager->SetSpeed(BLOCK_SPEED);
	}

	// プレイヤー生成
	CPlayer::Create();

	return S_OK;
}

//=====================================================
// 終了処理
//=====================================================
void CGame::Uninit(void)
{
	if (m_pScore != nullptr)
	{// スコアの終了・破棄
		m_pScore->Uninit();

		m_pScore = nullptr;
	}

	if (m_pTimer != nullptr)
	{// タイマーの終了・破棄
		m_pTimer->Uninit();

		m_pTimer = nullptr;
	}

	if (m_pBlockManager != nullptr)
	{// ブロック管理の破棄
		m_pBlockManager->Uninit();

		m_pBlockManager = nullptr;
	}

	// オブジェクト全棄
	CObject::ReleaseAll();
}

//=====================================================
// スコア終了処理
//=====================================================
void CGame::ReleaseScore(void)
{
	if (m_pScore != nullptr)
	{// スコアの終了・破棄
		m_pScore = nullptr;
	}
}

//=====================================================
// タイマー終了処理
//=====================================================
void CGame::ReleaseTimer(void)
{
	if (m_pTimer != nullptr)
	{// タイマーの終了・破棄
		m_pTimer = nullptr;
	}
}

//=====================================================
// 更新処理
//=====================================================
void CGame::Update(void)
{
	// 入力取得
	CInputKeyboard *pKeyboard = CManager::GetKeyboard();
	CInputJoypad *pJoypad = CManager::GetJoypad();

	CFade *pFade = CManager::GetFade();

	CCamera *pCamera = CManager::GetCamera();

	// シーンの更新
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
	if (m_pTimer->GetSecond() <= 0)
	{
		if (m_pScore != nullptr)
		{// スコア保存
			CManager::SetScore(m_pScore->GetScore());
		}

		pFade->SetFade(CScene::MODE_RANKING);
	}
}

//=====================================================
// 描画処理
//=====================================================
void CGame::Draw(void)
{

}