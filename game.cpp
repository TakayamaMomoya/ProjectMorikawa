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
#include "multibg.h"

//*****************************************************
// マクロ定義
//*****************************************************
#define BLOCK_SPEED	(3.0f)	// ブロックの流れる速度
#define ADD_SPEED (0.03f)	// 一秒当たりに上がるゲームスピード

//*****************************************************
// 静的メンバ変数宣言
//*****************************************************
CScore *CGame::m_pScore = nullptr;	// スコアのポインタ
CTimer *CGame::m_pTimer = nullptr;	// タイマーのポインタ
CPlayer *CGame::m_pPlayer = nullptr;	// プレイヤーのポインタ
CBlockManager *CGame::m_pBlockManager = nullptr;	//ブロックマネージャのポインタ
CMultiBg *CGame::m_pMultiBg = nullptr;
CObject2D* CGame::m_pResult = nullptr;		//リザルト文字のポインタ
CNumber* CGame::m_pResultScore = nullptr;	//リザルトスコアのポインタ
CGame::STATE CGame::m_state = STATE_NONE;	// ゲーム状態
float CGame::m_fGameSpeed = 0.0f;	// ゲームスピード

//=====================================================
// コンストラクタ
//=====================================================
CGame::CGame()
{
	m_nCntSecond = 0;
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
	m_fGameSpeed = 1.0f;

	CObjectManager *pObjManager = CManager::GetObjectManager();

	if (m_pMultiBg == nullptr)
	{// 多重背景生成
		m_pMultiBg = CMultiBg::Create();
	}

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

	if (m_pPlayer == nullptr)
	{
		// プレイヤー生成
		m_pPlayer = CPlayer::Create();
	}

	return S_OK;
}

//=====================================================
// 終了処理
//=====================================================
void CGame::Uninit(void)
{
	if (m_pMultiBg != nullptr)
	{// 多重背景の終了・破棄
		m_pMultiBg->Uninit();

		m_pMultiBg = nullptr;
	}

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

	if (m_pPlayer != nullptr)
	{// プレイヤーの終了・破棄
		m_pPlayer->Uninit();

		m_pPlayer = nullptr;
	}

	if (m_pBlockManager != nullptr)
	{// ブロック管理の破棄
		m_pBlockManager->Uninit();

		m_pBlockManager = nullptr;
	}

	if (m_pResult != nullptr)
	{// リザルト文字の破棄
		m_pResult->Uninit();

		m_pResult = nullptr;
	}

	if (m_pResultScore != nullptr)
	{// リザルトスコアの破棄
		m_pResultScore->Uninit();

		m_pResultScore = nullptr;
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

	if (m_pTimer->GetSecond() <= 0)
	{
		if (m_pScore != nullptr)
		{// スコア保存
			CManager::SetScore(m_pScore->GetScore());
		}

		CPlayer::Player* pPlayerInfo = m_pPlayer->GetInfo();

		if (pPlayerInfo->bJump == false && m_state != STATE_RESULT)
		{//ゲーム終了後着地したらスクロール止める
			pPlayerInfo->move = D3DXVECTOR3(m_pBlockManager->GetSpeed() * 3.0f, 0.0f, 0.0f);

			m_fGameSpeed = 0.0f;

			m_pBlockManager->SetSpeed(0.0f);

			SetState(STATE_RESULT);
		}

		if (pPlayerInfo->pos.x - pPlayerInfo->pTram->GetWidth() >= SCREEN_WIDTH && pFade->GetState() == CFade::FADE_NONE)
		{//画面外に出た
			if (m_pResult == nullptr && m_pResultScore == nullptr)
			{//リザルト表示
				//リザルト文字
				m_pResult = CObject2D::Create(CObject::PRIORITY_UI);
				m_pResult->SetSize(444.0f, 78.0f);
				m_pResult->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, 300.0f, 0.0f));
				m_pResult->SetIdxTexture(CManager::GetTexture()->Regist("data\\TEXTURE\\UI\\yourscore.png"));
				m_pResult->SetVtx();

				//リザルトスコア
				m_pResultScore = CNumber::Create(6, m_pScore->GetScore());
				m_pResultScore->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, 420.0f, 0.0f));
				m_pResultScore->SetSizeAll(40.0f, 40.0f);

			}

			if (pKeyboard != nullptr && pKeyboard->GetTrigger(DIK_RETURN) && pFade != nullptr)
			{//ランキング遷移
				pFade->SetFade(CScene::MODE_RANKING);
			}
		}
	}

	// スピードの管理
	ManageSpeed();
}

//=====================================================
// スピードの管理
//=====================================================
void CGame::ManageSpeed(void)
{
	m_nCntSecond++;

	if (m_nCntSecond >= 60)
	{
		m_nCntSecond = 0;

		m_fGameSpeed += ADD_SPEED;
	}
}

//=====================================================
// 描画処理
//=====================================================
void CGame::Draw(void)
{

}