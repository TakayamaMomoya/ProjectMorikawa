//*****************************************************
//
// プレイヤーの処理[player.cpp]
// Author:��山桃也
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
		CObject2D *pBody;	// 体の見た目
		CObject2D *pTram;	// トロッコの見た目
		D3DXVECTOR3 pos;	// 位置
		D3DXVECTOR3 posOld;	// 前回の位置
		D3DXVECTOR3 move;	// 移動量
		float fPowJump;	// ジャンプカウンター
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
	void ManageMove(void);	// 移動の管理
	void FollowBody(void);	// 体を追従させる処理
	void FollowTram(void);	// トロッコを追従させる処理
	void LimitPos(void);	// 位置制限処理
	void Debug(void);	// デバッグ表示

	Player m_player;	// プレイヤー情報
};

#endif
