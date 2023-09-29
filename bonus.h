//*****************************************************
//
// ボーナス表示の処理[bonus.cpp]
// Author:髙山桃也
//
//*****************************************************

#ifndef _BONUS_H_
#define _BONUS_H_

//*****************************************************
// インクルード
//*****************************************************
#include "Object.h"

//*****************************************************
// 前方宣言
//*****************************************************
class CNumber;

//*****************************************************
// クラスの定義
//*****************************************************
class CBonus : public CObject
{
public:
	CBonus(int nPriority = 3);	// コンストラクタ
	~CBonus();	// デストラクタ

	static CBonus *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move,int nValue);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	D3DXVECTOR3 m_pos;	// 位置
	D3DXVECTOR3 m_move;	// 移動量
	CNumber *m_pNumber;	// 数字のポインタ
	int m_nLife;	// 寿命
};

#endif
