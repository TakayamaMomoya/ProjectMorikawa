//*****************************************************
//
// 矢印の処理[arrow.cpp]
// Author:髙山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "arrow.h"
#include "game.h"
#include "particle.h"
#include "universal.h"
#include "manager.h"
#include "objectmanager.h"
#include "texture.h"
#include "player.h"

//*****************************************************
// マクロ定義
//*****************************************************
#define WIDTH	(50.0f)	// 幅
#define HEIGHT	(100.0f)	// 高さ
#define CHARGE_HEIGHT	(70.0f)	// 減る高さ
#define TEXTURE_PATH	"data\\TEXTURE\\UI\\arrow.png"	// テクスチャのパス

//=====================================================
// コンストラクタ
//=====================================================
CArrow::CArrow(int nPriority)
{

}

//=====================================================
// デストラクタ
//=====================================================
CArrow::~CArrow()
{

}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CArrow::Init(void)
{
	// 継承クラスの初期化
	CObject2D::Init();

	SetSize(WIDTH, HEIGHT);
	int nIdx = CManager::GetTexture()->Regist(TEXTURE_PATH);
	SetIdxTexture(nIdx);
	SetVtx();

	return S_OK;
}

//=====================================================
// 終了処理
//=====================================================
void CArrow::Uninit(void)
{
	// 継承クラスの終了
	CObject2D::Uninit();
}

//=====================================================
// 更新処理
//=====================================================
void CArrow::Update(void)
{
	// 継承クラスの更新
	CObject2D::Update();

	// 溜め表示
	DispCharge();

	SetVtx();
}

//=====================================================
// 溜めの表示
//=====================================================
void CArrow::DispCharge(void)
{
	// プレイヤーの取得
	CPlayer::Player *pPlayerInfo = nullptr;

	if (CGame::GetPlayer() != nullptr)
	{
		pPlayerInfo = CGame::GetPlayer()->GetInfo();
	}
	else
	{
		return;
	}

	// 計算用変数
	float fSize;
	D3DXVECTOR3 pos = pPlayerInfo->pos;
	D3DXCOLOR col = { 1.0f,1.0f,1.0f,1.0f };

	// タメ具合によるサイズ設定
	fSize = HEIGHT - CHARGE_HEIGHT * pPlayerInfo->fPowJump;

	col.g = 1.0f - pPlayerInfo->fPowJump;
	col.b = 1.0f - pPlayerInfo->fPowJump;

	// サイズ設定
	SetSize(GetWidth(),fSize);

	// 位置をずらす
	pos.x += 80.0f;
	pos.y -= fSize - 70.0f;

	// 位置設定
	SetPosition(pos);

	// 色設定
	SetCol(col);
}

//=====================================================
// 描画処理
//=====================================================
void CArrow::Draw(void)
{
	// 継承クラスの描画
	CObject2D::Draw();
}

//=====================================================
// 生成処理
//=====================================================
CArrow *CArrow::Create(void)
{
	CArrow *pDebris = nullptr;

	if (pDebris == nullptr)
	{// インスタンス生成
		pDebris = new CArrow;

		// 初期化処理
		pDebris->Init();
	}

	return pDebris;
}