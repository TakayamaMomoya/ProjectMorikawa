//*****************************************************
//
// 背景の処理[bg.cpp]
// Author:髙山桃也
//
//*****************************************************

#ifndef _BG_H_
#define _BG_H_

#include "object2D.h"

//*****************************************************
// クラスの定義
//*****************************************************
class CMultiBg : public CObject2D
{
public:

	struct MultiBg
	{// プレイヤー情報
		CObject2D *pFront;	// 体の見た目
		CObject2D *pMiddle;	// トロッコの見た目
		CObject2D *pBack;	// トロッコの見た目
		D3DXVECTOR3 pos;	// 位置
		D3DXVECTOR3 move;	// 移動量
		D3DXVECTOR2 m_texLeftUp;	// テクスチャ右上座標
		D3DXVECTOR2 m_texRightDown;	// テクスチャ左下座標
	};

	CMultiBg(int nPriority = 1);	// コンストラクタ
	~CMultiBg();	// デストラクタ

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CMultiBg *Create(void);	// 生成処理
	static HRESULT Load(void);	    // 読込
	static void Unload(void);
	void SetScroll(float fSpeedV, float fSpeedU);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;	// テクスチャへのポインタ
	MultiBg m_Multibg;
	D3DXVECTOR2 m_texFrontLeftUp;	  // テクスチャ右上座標
	D3DXVECTOR2 m_texFrontRightDown;	// テクスチャ左下座標
	D3DXVECTOR2 m_texMiddleLeftUp;	   // テクスチャ右上座標
	D3DXVECTOR2 m_texMiddleRightDown;	// テクスチャ左下座標
	D3DXVECTOR2 m_texBackLeftUp;	  // テクスチャ右上座標
	D3DXVECTOR2 m_texBackRightDown;	  // テクスチャ左下座標
	float m_fSpeedU;	// 横スクロール速度
	float m_fSpeedV;	// 縦スクロール速度
};

#endif