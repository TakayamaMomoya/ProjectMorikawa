//*****************************************************
//
// プレイヤーの処理[player.cpp]
// Author:髙山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "main.h"
#include "player.h"
#include "object2D.h"
#include "manager.h"
#include "texture.h"

//*****************************************************
// マクロ定義
//*****************************************************
#define BODY_PATH	"data\\TEXTURE\\CHARACTER\\player.png"	// 見た目のパス
#define BODY_WIDTH	(50.0f)	// 体の幅
#define BODY_HEIGHT	(100.0f)	// 体の高さ

//=====================================================
// 優先順位を決めるコンストラクタ
//=====================================================
CPlayer::CPlayer(int nPriority)
{
	ZeroMemory(&m_player,sizeof(Player));
}

//=====================================================
// デストラクタ
//=====================================================
CPlayer::~CPlayer()
{

}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CPlayer::Init(void)
{
	// 見た目の生成
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
// 終了処理
//=====================================================
void CPlayer::Uninit(void)
{
	if (m_player.m_pBody != nullptr)
	{// ボディの破棄
		m_player.m_pBody->Uninit();
		m_player.m_pBody = nullptr;
	}

	// 自身の破棄
	Release();
}

//=====================================================
// 更新処理
//=====================================================
void CPlayer::Update(void)
{
	// 前回の位置を保存
	m_player.m_posOld = m_player.m_pos;

	// 操作処理
	Input();

	// 体の見た目を追従させる
	FollowBody();
}

//=====================================================
// 操作処理
//=====================================================
void CPlayer::Input(void)
{

}

//=====================================================
// 体の見た目を追従させる処理
//=====================================================
void CPlayer::FollowBody(void)
{

}

//=====================================================
// 描画処理
//=====================================================
void CPlayer::Draw(void)
{

}

//=====================================================
// 生成処理
//=====================================================
CPlayer *CPlayer::Create(void)
{
	CPlayer *pPlayer = nullptr;

	if (pPlayer == nullptr)
	{// インスタンス生成
		pPlayer = new CPlayer;

		// 初期化処理
		pPlayer->Init();
	}

	return pPlayer;
}