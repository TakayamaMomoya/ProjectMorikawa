//*****************************************************
//
// 矢印の処理[arrow.cpp]
// Author:髙山桃也
//
//*****************************************************

#ifndef _ARROW_H_
#define _ARROW_H_

//*****************************************************
// インクルード
//*****************************************************
#include "Object2D.h"

//*****************************************************
// クラスの定義
//*****************************************************
class CArrow : public CObject2D
{
public:
	CArrow(int nPriority = 3);	// コンストラクタ
	~CArrow();	// デストラクタ

	static CArrow *Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	void DispCharge(void);	// タメ具合の表示
};

#endif
