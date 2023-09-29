//=====================================================
//
// ブロックマネージャの処理のヘッダ[blockmanager.h]
// Author:石原颯馬
//
//=====================================================
#ifndef _BLOCK_MANAGER_H_
#define _BLOCK_MANAGER_H_

#include "object.h"
#include "block.h"

//いったんマクロ
#define BLOCK_CREATE_NUM	(6)		//一度に配置するブロック数
#define BLOCK_START_HEIGHT	(96.0f)	//1つ目のブロック配置高さ
#define MIN_NEEDLE			(-1)	//とげ最低高さ
#define MAX_NEEDLE			(3)		//とげ最高高さ
#define MIN_CHANGE_NUM		(2)		//最低限変えない配置回数
#define CHANGE_NUM_DEGREE	(2)		//配置回数の振れ幅
#define BONUS_SPAWN_MIN		(4)		//ボーナスブロックの最低出現頻度
#define BONUS_SPAWN_DEGREE	(3)		//ボーナスブロックの振れ幅

//ブロッククラス
class CBlockManager : public CObject
{
public:
	//コンストラクタ・デストラクタ
	CBlockManager();
	~CBlockManager();

	//基本処理
	HRESULT Init(void);	// 初期化処理
	void Uninit(void);	// 終了処理
	void Update(void);	// 更新処理
	void Draw(void);	// 描画処理
	static CBlockManager *Create(int nPriority = PRIORITY_DEFAULT);	// 生成処理

	//取得
	float GetSpeed(void) { return m_fSpeed; }						//スクロール速度取得

	//設定
	void SetSpeed(const float fSpeed) { m_fSpeed = fSpeed; }		//スクロール速度設定

private:
	CBlock* m_apBlock[BLOCK_CREATE_NUM];	//最近配置したブロックオブジェ
	float m_fSpeed;							//ブロックスクロール速度
	int m_nNeedleHeight;					//とげを置く高さ
	int m_nChangeNeedleHeight;				//とげの高さを変える配置回数
	int m_nSpawnBonus;						//ボーナスブロックが次出てくるまで
};
#endif // !_BLOCK_MANAGER_H_