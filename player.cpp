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
#include "inputkeyboard.h"
#include "inputjoypad.h"
#include "debugproc.h"

//*****************************************************
// マクロ定義
//*****************************************************
#define BODY_PATH	"data\\TEXTURE\\CHARACTER\\player.png"	// 見た目のパス
#define BODY_WIDTH	(50.0f)	// 体の幅
#define BODY_HEIGHT	(100.0f)	// 体の高さ
#define MAX_JUMP (30.0f)	// ジャンプ力
#define FLOOR_LIMIT	(SCREEN_HEIGHT * 0.9f)	// 床の制限
#define GRAVITY	(0.98f)	// 重力
#define CHARGE_POWER	(0.01f)	// 1フレームあたりに溜まるジャンプ力
#define MAX_CHARGE	(1.0f)	// チャージの最大値

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
	m_player.pBody = CObject2D::Create(7);

	if (m_player.pBody != nullptr)
	{
		m_player.pBody->SetSize(BODY_WIDTH, BODY_HEIGHT);
		m_player.pBody->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
		m_player.pos = D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f);  
		int nIdx = CManager::GetTexture()->Regist(BODY_PATH);
		m_player.pBody->SetIdxTexture(nIdx);
		m_player.pBody->SetVtx();
	}

	return S_OK;
}

//=====================================================
// 終了処理
//=====================================================
void CPlayer::Uninit(void)
{
	if (m_player.pBody != nullptr)
	{// ボディの破棄
		m_player.pBody->Uninit();
		m_player.pBody = nullptr;
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
	m_player.posOld = m_player.pos;

	// 操作処理
	Input();

	// 移動の管理
	ManageMove();

	// 位置の制限
	LimitPos();

	// 体の見た目を追従させる
	FollowBody();
}

//=====================================================
// 操作処理
//=====================================================
void CPlayer::Input(void)
{
	CInputKeyboard *pKeyboard = CManager::GetKeyboard();
	CInputJoypad *pJoypad = CManager::GetJoypad();

	if (pKeyboard == nullptr || pJoypad == nullptr)
	{
		return;
	}

	if (pKeyboard->GetPress(DIK_SPACE))
	{// ジャンプ溜め
		m_player.fPowJump += CHARGE_POWER;

		if (m_player.fPowJump >= MAX_CHARGE)
		{// ジャンプ力制限
			m_player.fPowJump = MAX_CHARGE;
		}
	}

	if (pKeyboard->GetRelease(DIK_SPACE))
	{// ジャンプ操作
		m_player.move.y -= MAX_JUMP * m_player.fPowJump;

		m_player.fPowJump = 0.0f;
	}
}

//=====================================================
// 移動の管理
//=====================================================
void CPlayer::ManageMove(void)
{
	// 重力
	m_player.move.y += GRAVITY;

	// 位置に移動量を反映
	m_player.pos += m_player.move;
}

//=====================================================
// 体の見た目を追従させる処理
//=====================================================
void CPlayer::FollowBody(void)
{
	CObject2D *pBody = m_player.pBody;

	if (pBody == nullptr)
	{
		return;
	}

	// 位置を合わせる
	pBody->SetPosition(m_player.pos);

	pBody->SetVtx();
}

//=====================================================
// 位置制限処理
//=====================================================
void CPlayer::LimitPos(void)
{
	if (m_player.pos.y >= FLOOR_LIMIT - BODY_WIDTH)
	{// 床との制限
		m_player.pos.y = FLOOR_LIMIT - BODY_WIDTH;

		m_player.move.y = 0.0f;
	}
}

//=====================================================
// 描画処理
//=====================================================
void CPlayer::Draw(void)
{
#ifdef _DEBUG
	// デバッグ表示
	Debug();
#endif
}

//=====================================================
// デバッグ表示
//=====================================================
void CPlayer::Debug(void)
{
	CDebugProc *pDebugProc = CManager::GetDebugProc();

	if (pDebugProc == nullptr)
	{
		return;
	}

	pDebugProc->Print("\nジャンプ力[%f]",m_player.fPowJump);
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