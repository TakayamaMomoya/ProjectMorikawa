//*****************************************************
//
// チュートリアル処理[tutorial.h]
// Author:��山桃也
//
//*****************************************************
#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

//*****************************************************
// インクルード
//*****************************************************
#include "main.h"
#include "scene.h"

//*****************************************************
// クラスの定義
//*****************************************************
class CTutorial : public CScene
{
public:
	CTutorial();	// コンストラクタ
	~CTutorial();	// デストラクタ

	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update();
	virtual void Draw();

private:

};

#endif