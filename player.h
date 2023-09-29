//*****************************************************
//
// プレイヤーの処理[player.cpp]
// Author:髙山桃也
//
//*****************************************************

#ifndef _PLAYER_H_
#define _PLAYER_H_

//*****************************************************
// インクルード
//*****************************************************
#include "motion.h"

//*****************************************************
// 前方宣言
//*****************************************************
class CObject2D;

//*****************************************************
// クラスの定義
//*****************************************************
class CPlayer : public CObject
{
public:
	struct Player
	{// プレイヤー情報
		CObject2D *m_pBody;	// 体の見た目
		D3DXVECTOR3 m_pos;	// 位置
		D3DXVECTOR3 m_posOld;	// 前回の位置
	};

	CPlayer(int nPriority = 4);	// コンストラクタ
	~CPlayer();	// デストラクタ

	static CPlayer *Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	Player *GetInfo(void) { return &m_player; }

private:
	void Input(void);	// 操作処理
	void FollowBody(void);	// 体を追従させる処理

	Player m_player;	// プレイヤー情報
};

#endif
