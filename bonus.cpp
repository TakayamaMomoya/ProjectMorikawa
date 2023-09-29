//*****************************************************
//
// 矢印の処理[arrow.cpp]
// Author:髙山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "bonus.h"
#include "game.h"
#include "universal.h"
#include "manager.h"
#include "objectmanager.h"
#include "texture.h"
#include "number.h"

//*****************************************************
// マクロ定義
//*****************************************************
#define NUM_PLACE	(4)	// 桁数
#define DEFAULT_WIDTH	(5.0f)	// 標準の幅
#define DEFAULT_HEIGHT	(15.0f)	// 標準の高さ
#define BONUS_WIDTH	(DEFAULT_WIDTH * 2)	// 標準の幅
#define BONUS_HEIGHT	(DEFAULT_HEIGHT * 2)	// 標準の高さ
#define INITIAL_LIFE	(60)	// 初期寿命
#define BONUS_LINE	(1000)	// 拡大表示になるライン

//=====================================================
// コンストラクタ
//=====================================================
CBonus::CBonus(int nPriority)
{
	m_pos = { 0.0f,0.0f,0.0f };
	m_move = { 0.0f,0.0f,0.0f };
	m_pNumber = nullptr;
	m_nLife = 0;
}

//=====================================================
// デストラクタ
//=====================================================
CBonus::~CBonus()
{

}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CBonus::Init(void)
{
	m_nLife = INITIAL_LIFE;

	return S_OK;
}

//=====================================================
// 終了処理
//=====================================================
void CBonus::Uninit(void)
{
	if (m_pNumber != nullptr)
	{
		m_pNumber->Uninit();
		m_pNumber = nullptr;
	}
	
	Release();
}

//=====================================================
// 更新処理
//=====================================================
void CBonus::Update(void)
{
	m_nLife--;

	// 移動量を位置に反映
	m_pos += m_move;

	if (m_pNumber != nullptr)
	{// 数字を位置に合わせる
		m_pNumber->SetPosition(m_pos);
	}

	if (m_nLife <= 0)
	{
		Uninit();
	}
}

//=====================================================
// 描画処理
//=====================================================
void CBonus::Draw(void)
{

}

//=====================================================
// 生成処理
//=====================================================
CBonus *CBonus::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nValue)
{
	CBonus *pBonus = nullptr;

	if (pBonus == nullptr)
	{// インスタンス生成
		pBonus = new CBonus;

		if (pBonus == nullptr)
		{
			return nullptr;
		}

		// 初期化処理
		pBonus->Init();

		pBonus->m_pos = pos;
		pBonus->m_move = move;

		if (pBonus->m_pNumber == nullptr)
		{// 数字の生成

			pBonus->m_pNumber = CNumber::Create(NUM_PLACE,nValue);

			if (pBonus->m_pNumber != nullptr)
			{
				pBonus->m_pNumber->SetPosition(pos);

				if (nValue < BONUS_LINE)
				{
					pBonus->m_pNumber->SetSizeAll(DEFAULT_WIDTH, DEFAULT_HEIGHT);
				}
				else
				{
					pBonus->m_pNumber->SetSizeAll(BONUS_WIDTH, BONUS_HEIGHT);
				}

				if (nValue < 0)
				{
					nValue *= -1;

					pBonus->m_pNumber->SetValue(nValue, NUM_PLACE);

					pBonus->m_pNumber->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
				}
			}
		}
	}

	return pBonus;
}