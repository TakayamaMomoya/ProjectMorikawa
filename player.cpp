//*****************************************************
//
// プレイヤーの処理[player.cpp]
// Author:��山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "main.h"
#include "game.h"
#include "player.h"
#include "object2D.h"
#include "manager.h"
#include "texture.h"
#include "inputkeyboard.h"
#include "inputjoypad.h"
#include "debugproc.h"
#include "universal.h"
#include "collision.h"
#include "arrow.h"
#include "timer.h"
#include "score.h"
#include "bonus.h"
#include "debrisspawner.h"
#include "blockmanager.h"
#include "sound.h"

//*****************************************************
// マクロ定義
//*****************************************************
#define BODY_PATH	"data\\TEXTURE\\CHARACTER\\player.png"	// 見た目のパス
#define TRAM_PATH	"data\\TEXTURE\\CHARACTER\\tram.png"	// トロッコのパス
#define FLOOR_LIMIT	(SCREEN_HEIGHT * 0.9f)	// 床の制限
#define BODY_WIDTH	(60.0f)	// 体の幅
#define BODY_HEIGHT	(60.0f)	// 体の高さ
#define TRAM_WIDTH	(60.0f)	// トロッコの幅
#define TRAM_HEIGHT	(30.0f)	// トロッコの高さ
#define TRAM_POSY	(SCREEN_HEIGHT * 0.89f)	// トロッコのY座標
#define MAX_JUMP (30.0f)	// ジャンプ力
#define GRAVITY	(0.98f)	// 重力
#define CHARGE_POWER	(0.010f)	// 1フレームあたりに溜まるジャンプ力
#define CHARGE_INTIIAL	(0.5f)	// 初動のジャンプ力
#define MAX_CHARGE	(0.5f)	// チャージの最大値
#define JUMP_BUTTON	(DIK_RETURN)	// ジャンプキー
#define ROLL_SPEED	(0.6f)	// 回転速度
#define DAMAGE_SCORE	(-5000)	// 減点量

//=====================================================
// 優先順位を決めるコンストラクタ
//=====================================================
CPlayer::CPlayer(int nPriority)
{
	ZeroMemory(&m_player,sizeof(Player));

	m_state = STATE_NONE;
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
	m_state = STATE_NORMAL;

	// 見た目の生成
	m_player.pBody = CObject2D::Create(7);

	if (m_player.pBody != nullptr)
	{
		m_player.pBody->SetSize(BODY_WIDTH, BODY_HEIGHT);
		m_player.pBody->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.2f, SCREEN_HEIGHT * 0.5f, 0.0f));
		m_player.pos = D3DXVECTOR3(SCREEN_WIDTH * 0.2f, SCREEN_HEIGHT * 0.5f, 0.0f);  
		int nIdx = CManager::GetTexture()->Regist(BODY_PATH);
		m_player.pBody->SetIdxTexture(nIdx);
		m_player.pBody->SetVtx();
	}

	// トロッコの生成
	m_player.pTram = CObject2D::Create(7);

	if (m_player.pTram != nullptr)
	{
		m_player.pTram->SetSize(TRAM_WIDTH, TRAM_HEIGHT);
		m_player.pTram->SetPosition(D3DXVECTOR3(m_player.pos.x, TRAM_POSY, 0.0f));
		int nIdx = CManager::GetTexture()->Regist(TRAM_PATH);
		m_player.pTram->SetIdxTexture(nIdx);
		m_player.pTram->SetVtx();
	}

	if (m_pCollisionSphere == nullptr)
	{// 球の当たり判定生成
		m_pCollisionSphere = CCollisionSphere::Create(CCollision::TAG_PLAYER, CCollision::TYPE_SPHERE, this);

		float fRadius;

		if (m_pCollisionSphere != nullptr)
		{// 情報の設定
			fRadius = BODY_HEIGHT;

			m_pCollisionSphere->SetPosition(GetPosition());
			m_pCollisionSphere->SetRadius(fRadius);
		}
	}

	// 矢印設定
	CArrow::Create();

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

	if (m_player.pTram != nullptr)
	{// トロッコの破棄
		m_player.pTram->Uninit();
		m_player.pTram = nullptr;
	}

	if (m_pCollisionSphere != nullptr)
	{// 当たり判定の破棄
		m_pCollisionSphere->Uninit();
		m_pCollisionSphere = nullptr;
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

	if (CGame::GetTimer()->GetSecond() > 0)
	{//時間がある限り動かせるようにする
		// 操作処理
		Input();
	}

	// 移動の管理
	ManageMove();

	// 当たり判定管理
	ManageCollision();

	// 位置の制限
	LimitPos();

	// 回転の管理
	ManageRoll();

	// 体の追従
	FollowBody();

	// トロッコの追従
	FollowTram();
}

//=====================================================
// 操作処理
//=====================================================
void CPlayer::Input(void)
{
	if (m_player.bJump == false)
	{
		// ジャンプ操作
		InputJump();
	}
}

//=====================================================
// ジャンプ操作
//=====================================================
void CPlayer::InputJump(void)
{
	CInputKeyboard *pKeyboard = CManager::GetKeyboard();
	CInputJoypad *pJoypad = CManager::GetJoypad();
	CSound *pSound = CManager::GetSound();

	if (pKeyboard == nullptr || pJoypad == nullptr)
	{// 入力に不具合あったら通らない
		return;
	}

	if (pKeyboard->GetPress(JUMP_BUTTON))
	{// ジャンプ溜め
		m_player.fPowJump += CHARGE_POWER;

		if (m_player.fPowJump >= MAX_CHARGE)
		{// ジャンプ力制限
			m_player.fPowJump = MAX_CHARGE;
		}
	}

	if (pKeyboard->GetRelease(JUMP_BUTTON))
	{// ジャンプ操作
		m_player.move.y -= MAX_JUMP * (m_player.fPowJump + CHARGE_INTIIAL);

		m_player.fPowJump = 0.0f;

		m_player.bJump = true;

		pSound->Play(CSound::LABELJUMP_SE);
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
// 当たり判定管理
//=====================================================
void CPlayer::ManageCollision(void)
{
	if (m_pCollisionSphere != nullptr)
	{// 球の当たり判定の管理
		m_pCollisionSphere->SetPositionOld(m_pCollisionSphere->GetPosition());

		m_pCollisionSphere->SetPosition(m_player.pos);
	}
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

		if (m_player.bJump)
		{// 着地処理
			Land();
		}
	}
}

//=====================================================
// 着地処理
//=====================================================
void CPlayer::Land(void)
{
	if (m_player.bJump == false)
	{// 既に着地していたら通らない
		return;
	}

	// 着地状態にする
	m_player.bJump = false;

	// 体の向きのリセット
	CObject2D *pBody = m_player.pBody;

	if (pBody != nullptr)
	{
		pBody->SetRot(0.0f);

		pBody->SetVtx();
	}

	m_state = STATE_NORMAL;
}

//=====================================================
// 回転の管理
//=====================================================
void CPlayer::ManageRoll(void)
{
	// 汎用処理の取得
	CUniversal *pUniversal = CManager::GetUniversal();

	if (m_player.bJump)
	{// 回転させる
		CObject2D *pBody = m_player.pBody;
		float fRot = 0.0f;

		if (pBody == nullptr)
		{
			return;
		}

		// 向き取得
		fRot = pBody->GetRot();

		// 回転させる
		fRot -= ROLL_SPEED;

		pUniversal->LimitRot(&fRot);	// 角度制限

		pBody->SetRot(fRot);
	}
}

//=====================================================
// 体を追従させる処理
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
// 体を追従させる処理
//=====================================================
void CPlayer::FollowTram(void)
{
	CObject2D *pTram = m_player.pTram;

	if (pTram == nullptr)
	{
		return;
	}

	// 位置を合わせる
	pTram->SetPosition(D3DXVECTOR3(m_player.pos.x, TRAM_POSY, 0.0f));

	pTram->SetVtx();
}

//=====================================================
// ヒット処理
//=====================================================
void CPlayer::Hit(float fDamage)
{
	CSound *pSound = CManager::GetSound();

	if (m_state == STATE_DAMAGE)
	{
		return;
	}

	pSound->Play(CSound::LABELNEEDLE_SE);

	// スコア取得
	CScore *pScore = CGame::GetScore();

	m_player.move.y = GRAVITY;

	if (pScore != nullptr)
	{
		pScore->AddScore(DAMAGE_SCORE);
	}

	CBonus::Create(m_player.pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), DAMAGE_SCORE);

	m_state = STATE_DAMAGE;

	CDebrisSpawner::Create(m_player.pos, 20.0f, 1, 15, CDebrisSpawner::TYPE_DAMAGE);
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