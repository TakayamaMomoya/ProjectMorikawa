//=====================================================
//
// ブロックマネージャの処理[blockmanager.cpp]
// Author:石原颯馬
//
//=====================================================
#include "blockmanager.h"
#include "manager.h"
#include "texture.h"

//=====================================
//コンストラクタ
//=====================================
CBlockManager::CBlockManager()
{
	for (int cnt = 0; cnt < BLOCK_CREATE_NUM; cnt++)
	{//ブロックオブジェぬるぽ入れる
		m_apBlock[cnt] = nullptr;
	}
	m_fSpeed = 0.0f;	//速度もいったん0
}

//=====================================
//デストラクタ
//=====================================
CBlockManager::~CBlockManager()
{
}

//=====================================
//初期化
//=====================================
HRESULT CBlockManager::Init(void)
{
	return S_OK;
}

//=====================================
//終了
//=====================================
void CBlockManager::Uninit(void)
{
	Release();		//自分破棄
}

//=====================================
//更新
//=====================================
void CBlockManager::Update(void)
{
	bool bNotDisp = false;

	for (int cnt = 0; cnt < BLOCK_CREATE_NUM; cnt++)
	{//最近配置したブロックを見る
		if (m_apBlock[cnt] != nullptr)
		{//そもそもぬるぽじゃない
			//当たり判定に必要なもの取得
			D3DXVECTOR3 pos = m_apBlock[cnt]->GetPosition();
			float fWidth = m_apBlock[cnt]->GetWidth();

			if (pos.x + fWidth > SCREEN_WIDTH)
			{
				bNotDisp = true;
				break;
			}
		}
	}

	//ブロックがすべて表示された
	if (bNotDisp == false)
	{//生成
		for (int cnt = 0; cnt < BLOCK_CREATE_NUM; cnt++)
		{//最大数分生成
			m_apBlock[cnt] = CBlock::Create();
			m_apBlock[cnt]->SetSize(32.0f, 32.0f);
			m_apBlock[cnt]->SetPosition(D3DXVECTOR3(SCREEN_WIDTH + 32.0f, BLOCK_START_HEIGHT + (cnt * 32.0f * 2.0f), 0.0f));

			int nIdx = CManager::GetTexture()->Regist("data\\TEXTURE\\Block_R_01.png");
			m_apBlock[cnt]->SetIdxTexture(nIdx);
			m_apBlock[cnt]->SetVtx();
		}
	}
}

//=====================================
//描画
//=====================================
void CBlockManager::Draw(void)
{
	
}

//=====================================
//生成
//=====================================
CBlockManager* CBlockManager::Create(int nPriority)
{
	CBlockManager* pBlockManager = nullptr;

	//一応チェック
	if (pBlockManager == nullptr)
	{//生成
		pBlockManager = new CBlockManager;	//生成
		pBlockManager->Init();			//初期化

		return pBlockManager;
	}
	return nullptr;	//たぶん起きないと思うけど
}