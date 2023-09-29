//*****************************************************
//
// 破片スポナー処理[debrisspawner.cpp]
// Author:髙山桃也
//
//*****************************************************

//*****************************************************
// インクルード
//*****************************************************
#include "debrisspawner.h"
#include "debris.h"
#include "manager.h"
#include "texture.h"

//=====================================================
// 優先順位を決めるコンストラクタ
//=====================================================
CDebrisSpawner::CDebrisSpawner()
{
	m_pos = { 0.0f,0.0f,0.0f };
	m_fSpeed = 0.0f;
	m_nLife = 0;
	m_nNumDebris = 0;
	m_type = TYPE_NORMAL;
}

//=====================================================
// デストラクタ
//=====================================================
CDebrisSpawner::~CDebrisSpawner()
{

}

//=====================================================
// 初期化処理
//=====================================================
HRESULT CDebrisSpawner::Init(void)
{
	return S_OK;
}

//=====================================================
// 終了処理
//=====================================================
void CDebrisSpawner::Uninit(void)
{
	Release();
}

//=====================================================
// 更新処理
//=====================================================
void CDebrisSpawner::Update(void)
{
	D3DXVECTOR3 move;
	float fRot,fSpeed;
	int nLife;
	CDebris *pDebris;

	char *aPath[TYPE_MAX] = 
	{
		"data\\TEXTURE\\BLOCK\\fragment00.png",
		"data\\TEXTURE\\BLOCK\\fragment01.png",
		"data\\TEXTURE\\BLOCK\\fragment02.png",
	};

	for (int nCnt = 0; nCnt < m_nNumDebris; nCnt++)
	{
		nLife = rand() % 50 + 10;
		fRot = rand() % 628 - 314 / 100.0f;
		fSpeed = (float)(rand() % (int)(m_fSpeed * 50)) * 0.01f + m_fSpeed * 0.5f;

		move.x = sinf(fRot) * fSpeed;
		move.y = cosf(fRot) * fSpeed;
		move.z = 0.0f;

		pDebris = CDebris::Create(m_pos, nLife);

		pDebris->SetMove(move);

		int nIdx = CManager::GetTexture()->Regist(aPath[m_type]);
		pDebris->SetIdxTexture(nIdx);
		pDebris->SetVtx();

		if (m_type == TYPE_DAMAGE)
		{
			pDebris->SetCol(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
		}
	}

	m_nLife--;

	if (m_nLife < 0)
	{
		// 自身の破棄
		Uninit();
	}
}

//=====================================================
// 位置設定処理
//=====================================================
void CDebrisSpawner::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//=====================================================
// 生成処理
//=====================================================
CDebrisSpawner *CDebrisSpawner::Create(D3DXVECTOR3 pos,float fSpeed,int nLife, int nNumDebris, TYPE type)
{
	CDebrisSpawner *pSpawner = nullptr;

	if (pSpawner == nullptr)
	{// インスタンス生成
		pSpawner = new CDebrisSpawner;

		pSpawner->m_pos = pos;

		pSpawner->m_nLife = nLife;

		pSpawner->m_fSpeed = fSpeed;

		pSpawner->m_nNumDebris = nNumDebris;

		pSpawner->m_type = type;
	}

	return pSpawner;
}