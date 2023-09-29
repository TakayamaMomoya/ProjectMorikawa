//=====================================================
//
// ブロックマネージャの処理[blockmanager.cpp]
// Author:石原颯馬
//
//=====================================================
#include "blockmanager.h"
#include "manager.h"
#include "texture.h"

//いったんファイルパス
const char* g_apFilePath[CBlock::TYPE_MAX] =
{
	"data\\TEXTURE\\Block_R_01.png",
	"data\\TEXTURE\\Block_R_04.png",
	"data\\TEXTURE\\Block_R_02.png",
	"data\\TEXTURE\\Block_R_03.png"
};

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
	m_nNeedleHeight = 0;
	m_nChangeNeedleHeight = 0;
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
	m_nChangeNeedleHeight = 5;	//仮

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

			//ブロック種類設定
			int nIdx;
			
			if (cnt > m_nNeedleHeight)
			{//とげの高さより下（破壊可能ブロック）
				m_apBlock[cnt]->SetType(CBlock::TYPE_BLOCK);
				nIdx = CManager::GetTexture()->Regist(g_apFilePath[CBlock::TYPE_BLOCK]);
			}
			else if (cnt == m_nNeedleHeight)
			{//とげの高さ（とげ）
				m_apBlock[cnt]->SetType(CBlock::TYPE_NEEDLE);
				nIdx = CManager::GetTexture()->Regist(g_apFilePath[CBlock::TYPE_NEEDLE]);
			}
			if (cnt < m_nNeedleHeight)
			{//とげの高さより上（岩盤）
				m_apBlock[cnt]->SetType(CBlock::TYPE_BEDROCK);
				nIdx = CManager::GetTexture()->Regist(g_apFilePath[CBlock::TYPE_BEDROCK]);
			}
			m_apBlock[cnt]->SetIdxTexture(nIdx);
			m_apBlock[cnt]->SetVtx();
		}
		m_nChangeNeedleHeight--;	//変更なし回数減らす
	}

	//高さ変更チェック
	if (m_nChangeNeedleHeight <= 0)
	{//変更する
		int nRand = rand() % 2;
		m_nNeedleHeight += (nRand == 0) ? -1 : 1;	//高さ変更

		//最低を下回らないようにする
		if (m_nNeedleHeight < MIN_NEEDLE)
		{
			m_nNeedleHeight = MIN_NEEDLE;
		}
		//最高を上回らないようにする
		else if (m_nNeedleHeight > MAX_NEEDLE)
		{
			m_nNeedleHeight = MAX_NEEDLE;
		}

		m_nChangeNeedleHeight = rand() % MIN_CHANGE_NUM + CHANGE_NUM_DEGREE;	//変更なし回数再設定
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