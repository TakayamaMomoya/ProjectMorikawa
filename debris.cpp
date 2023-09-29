//*****************************************************
//
// 破片の処理[debris.cpp]
// Author:髙山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "debris.h"
#include "game.h"
#include "particle.h"
#include "universal.h"
#include "manager.h"
#include "objectmanager.h"
#include "texture.h"

//*****************************************************
// マクロ定義
//*****************************************************
#define MODE_FACT	(0.9f)	// 移動量の減衰係数
#define GRAVITY	(0.3f)	// 重力
#define SIZE_DEFAULT	(10.0f)	// デフォルトのサイズ
#define TEXTURE_PATH	"data\\TEXTURE\\EFFECT\\debris.png"	// テクスチャのパス

//*****************************************************
// 静的メンバ変数宣言
//*****************************************************
int CDebris::m_nNumAll = 0;	// 総数

//=====================================================
// コンストラクタ
//=====================================================
CDebris::CDebris(int nPriority)
{
	m_nLife = 0;
	m_fSpeedRotation = 0.0f;

	m_nNumAll++;
}

//=====================================================
// デストラクタ
//=====================================================
CDebris::~CDebris()
{
	m_nNumAll--;
}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CDebris::Init(void)
{
	// 継承クラスの初期化
	CObject2D::Init();

	SetSize(SIZE_DEFAULT, SIZE_DEFAULT);
	int nIdx = CManager::GetTexture()->Regist(TEXTURE_PATH);
	SetIdxTexture(nIdx);
	SetVtx();

	// 回るスピードの設定
	m_fSpeedRotation = rand() % 100 * 0.001f;

	return S_OK;
}

//=====================================================
// 終了処理
//=====================================================
void CDebris::Uninit(void)
{
	// 継承クラスの終了
	CObject2D::Uninit();
}

//=====================================================
// 更新処理
//=====================================================
void CDebris::Update(void)
{
	// 汎用処理の取得
	CUniversal *pUniversal = CManager::GetUniversal();

	D3DXVECTOR3 move = GetMove();
	D3DXVECTOR3 pos = GetPosition();
	float fRot = GetRot();

	// 継承クラスの更新
	CObject2D::Update();

	// 移動量を位置に加算
	SetPosition(pos + move);

	// 移動量減衰
	move.y += GRAVITY;

	SetMove(move);

	fRot += m_fSpeedRotation;

	// 向きの修正
	pUniversal->LimitRot(&fRot);

	SetRot(fRot);

	m_nLife--;

	SetVtx();

	if (m_nLife <= 0)
	{// 寿命による破棄
		Uninit();
	}
}

//=====================================================
// 描画処理
//=====================================================
void CDebris::Draw(void)
{
	// 継承クラスの描画
	CObject2D::Draw();
}

//=====================================================
// 生成処理
//=====================================================
CDebris *CDebris::Create(D3DXVECTOR3 pos, int nLife)
{
	CDebris *pDebris = nullptr;

	if (pDebris == nullptr)
	{// インスタンス生成
		pDebris = new CDebris;

		pDebris->m_nLife = nLife;

		pDebris->SetPosition(pos);

		// 初期化処理
		pDebris->Init();
	}

	return pDebris;
}