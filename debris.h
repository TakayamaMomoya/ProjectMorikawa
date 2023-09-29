//*****************************************************
//
// 破片の処理[debris.cpp]
// Author:髙山桃也
//
//*****************************************************

#ifndef _DEBRIS_H_
#define _DEBRIS_H_

//*****************************************************
// インクルード
//*****************************************************
#include "Object2D.h"

//*****************************************************
// クラスの定義
//*****************************************************
class CDebris : public CObject2D
{
public:
	CDebris(int nPriority = 3);	// コンストラクタ
	~CDebris();	// デストラクタ

	static CDebris *Create(D3DXVECTOR3 pos,int nLife);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	int m_nLife;	// 寿命
	float m_fSpeedRotation;	// 回る速度
	static int m_nNumAll;	// 総数
};

#endif
