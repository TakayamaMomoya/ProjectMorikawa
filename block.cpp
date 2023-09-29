//=====================================================
//
// ブロックの処理[block.cpp]
// Author:石原颯馬
//
//=====================================================
#include "game.h"
#include "block.h"
#include "blockmanager.h"

//=====================================
//コンストラクタ
//=====================================
CBlock::CBlock()
{
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
	return CObject2D::Init();	//親処理
}

//=====================================
//終了
//=====================================
void CBlock::Uninit(void)
{
	CObject2D::Uninit();		//親処理
}

//=====================================
//更新
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
