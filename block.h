//=====================================================
//
// ブロックの処理のヘッダ[block.h]
// Author:石原颯馬
//
//=====================================================
#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "object2D.h"

//*****************************************************
// 前方宣言
//*****************************************************
class CCollisionSphere;

//ブロッククラス
class CBlock : public CObject2D
{
public:
	//ブロック種類列挙
	enum TYPE
	{
		TYPE_BLOCK = 0,
		TYPE_BONUS,
		TYPE_NEEDLE,
		TYPE_BEDROCK,
		TYPE_MAX
	};

	//コンストラクタ・デストラクタ
	CBlock();
	~CBlock();

	//基本処理
	HRESULT Init(void);	// 初期化処理
	void Uninit(void);	// 終了処理
	void Update(void);	// 更新処理
	void Draw(void);	// 描画処理
	static CBlock *Create(int nPriority = PRIORITY_DEFAULT);		// 生成処理

	//取得
	TYPE GetType(void) { return m_type; }							//ブロック種類（ブロック・とげ等）取得

	//設定
	void SetType(const TYPE type) { m_type = type; }				//ブロック種類（ブロック・とげ等）設定

private:
	bool CheckOutOfRange(void);	//範囲外チェック
	void ManageCollision(void);	// 当たり判定管理

	TYPE m_type;			//ブロック種類
	CCollisionSphere *m_pCollisionSphere;	// 球の当たり判定
};
#endif // !_BLOCK_H_