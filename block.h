//=====================================================
//
// ブロックの処理のヘッダ[block.h]
// Author:石原颯馬
//
//=====================================================
#include "object2D.h"

//ブロッククラス
class CBlock : public CObject2D
{
public:
	//ブロック種類列挙
	enum TYPE
	{
		TYPE_BLOCK = 0,
		TYPE_NEEDLE,
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
	static CBlock *Create(int nPriority = PRIORITY_DEFAULT);	// 生成処理

	//取得
	TYPE GetType(void) { return m_type; }

	//設定
	void SetType(TYPE type) { m_type = type; }

private:
	TYPE m_type;
};