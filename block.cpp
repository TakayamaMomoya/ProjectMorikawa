//=====================================================
//
// ブロックの処理[block.cpp]
// Author:石原颯馬
//
//=====================================================
#include "game.h"
#include "block.h"
#include "blockmanager.h"
#include "collision.h"
#include "debrisspawner.h"
#include "score.h"

//*****************************************************
// マクロ定義
//*****************************************************
#define SIZE_DEFAULT	(32.0f)	// デフォルトのサイズ
#define NORMAL_SCORE	(500)	// 通常スコア
#define BONUS_SCORE	(5000)	// ボーナススコア

//=====================================
//コンストラクタ
//=====================================
CBlock::CBlock()
{
	m_pCollisionSphere = nullptr;
}

//=====================================
//デストラクタ
//=====================================
CBlock::~CBlock()
{
}

//=====================================
//初期化
//=====================================
HRESULT CBlock::Init(void)
{
	if (m_pCollisionSphere == nullptr)
	{// 球の当たり判定生成
		m_pCollisionSphere = CCollisionSphere::Create(CCollision::TAG_BLOCK, CCollision::TYPE_SPHERE, this);

		float fRadius;

		if (m_pCollisionSphere != nullptr)
		{// 情報の設定
			fRadius = SIZE_DEFAULT;

			m_pCollisionSphere->SetPosition(GetPosition());
			m_pCollisionSphere->SetRadius(fRadius);
		}
	}

	return CObject2D::Init();	//親処理
}

//=====================================
//終了
//=====================================
void CBlock::Uninit(void)
{
	if (m_pCollisionSphere != nullptr)
	{// 当たり判定の消去
		m_pCollisionSphere->Uninit();

		m_pCollisionSphere = nullptr;
	}

	CObject2D::Uninit();		//親処理
}

//=====================================
// 更新
//=====================================
void CBlock::Update(void)
{
	CBlockManager* pBlockManager = CGame::GetBlockManager();
	CObject2D::SetMove(D3DXVECTOR3(-pBlockManager->GetSpeed(), 0.0f, 0.0f));	//移動量設定

	if (CheckOutOfRange() == true)
	{//範囲外に出た
		Uninit();
		return;
	}

	CObject2D::Update();									//親処理
	CObject2D::SetVtx();									//頂点移動

	// 当たり判定の管理
	ManageCollision();
}

//=====================================
// 当たり判定管理
//=====================================
void CBlock::ManageCollision(void)
{
	if (m_pCollisionSphere != nullptr)
	{// 球の当たり判定の管理
		m_pCollisionSphere->SetPositionOld(m_pCollisionSphere->GetPosition());

		m_pCollisionSphere->SetPosition(GetPosition());

		if (m_pCollisionSphere->IsTriggerEnter(CCollision::TAG_PLAYER))
		{// 対象との当たり判定
			ManageHit(m_pCollisionSphere->GetOther());

		}
	}
}

//=====================================
// 当たった時の管理
//=====================================
void CBlock::ManageHit(CObject *pObj)
{
	// スコア取得
	CScore *pScore = CGame::GetScore();

	switch (m_type)
	{
	case CBlock::TYPE_BLOCK:

		CDebrisSpawner::Create(GetPosition(), 10.0f, 2, 3);

		if (pScore != nullptr)
		{
			pScore->AddScore(NORMAL_SCORE);
		}

		Uninit();

		break;
	case CBlock::TYPE_BONUS:

		CDebrisSpawner::Create(GetPosition(), 20.0f, 2, 30,CDebrisSpawner::TYPE_BONUS);

		if (pScore != nullptr)
		{
			pScore->AddScore(BONUS_SCORE);
		}

		Uninit();

		break;
	case CBlock::TYPE_NEEDLE:

		if (pObj != nullptr)
		{
			pObj->Hit(0.0f);
		}

		break;
	case CBlock::TYPE_BEDROCK:
	default:
		break;
	}

}

//=====================================
//描画
//=====================================
void CBlock::Draw(void)
{
	CObject2D::Draw();			//親処理
}

//=====================================
//生成
//=====================================
CBlock* CBlock::Create(int nPriority)
{
	CBlock* pBlock = nullptr;

	//一応チェック
	if (pBlock == nullptr)
	{//生成
		pBlock = new CBlock;	//生成
		pBlock->Init();			//初期化

		return pBlock;
	}
	return nullptr;	//たぶん起きないと思うけど
}

//=====================================
//範囲外チェック
//=====================================
bool CBlock::CheckOutOfRange(void)
{
	//当たり判定に使う変数取得
	D3DXVECTOR3 pos = CObject2D::GetPosition();	//位置取得
	float fWidthHalf = CObject2D::GetWidth();	//幅取得
	
	//範囲外出た？
	if (pos.x + fWidthHalf < 0.0f)
	{//出た
		return true;
	}
	else
	{//出てない
		return false;
	}
}
