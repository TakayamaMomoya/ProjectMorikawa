//*****************************************************
//
// 破片スポナー処理[debrisspawner.h]
// Author:��山桃也
//
//*****************************************************

#ifndef _DEBRISSPAWNER_H_
#define _DEBRISSPAWNER_H_

//*****************************************************
// インクルード
//*****************************************************
#include "object.h"

//*****************************************************
// クラス定義
//*****************************************************
class CDebrisSpawner : public CObject
{
public:
	enum TYPE
	{
		TYPE_NORMAL = 0,	// 通常
		TYPE_BONUS,	// ボーナス
		TYPE_DAMAGE,	// ダメージ
		TYPE_MAX
	};

	CDebrisSpawner(void);	// コンストラクタ
	~CDebrisSpawner();	// デストラクタ

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void) {};
	static CDebrisSpawner *Create(D3DXVECTOR3 pos, float fSpeed, int nLife,int nNumDebris,TYPE type = TYPE_NORMAL);
	void SetPosition(D3DXVECTOR3 pos);
	D3DXVECTOR3 GetPosition(void) { return m_pos; }
	D3DXVECTOR3 GetPositionOld(void) { return D3DXVECTOR3(); }	// 取得処理

private:
	TYPE m_type;
	D3DXVECTOR3 m_pos;	// 位置
	int m_nLife;	// 寿命
	float m_fSpeed;	// スピード
	int m_nNumDebris;	// デブリの数
};

#endif