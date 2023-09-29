//*****************************************************
//
// �w�i�̏���[bg.cpp]
// Author:���R����
//
//*****************************************************

#ifndef _BG_H_
#define _BG_H_

#include "object2D.h"

//*****************************************************
// �N���X�̒�`
//*****************************************************
class CMultiBg : public CObject2D
{
public:

	struct MultiBg
	{// �v���C���[���
		CObject2D *pFront;	// �̂̌�����
		CObject2D *pMiddle;	// �g���b�R�̌�����
		CObject2D *pBack;	// �g���b�R�̌�����
		D3DXVECTOR3 pos;	// �ʒu
		D3DXVECTOR3 move;	// �ړ���
		D3DXVECTOR2 m_texLeftUp;	// �e�N�X�`���E����W
		D3DXVECTOR2 m_texRightDown;	// �e�N�X�`���������W
	};

	CMultiBg(int nPriority = 1);	// �R���X�g���N�^
	~CMultiBg();	// �f�X�g���N�^

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CMultiBg *Create(void);	// ��������
	static HRESULT Load(void);	    // �Ǎ�
	static void Unload(void);
	void SetScroll(float fSpeedV, float fSpeedU);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;	// �e�N�X�`���ւ̃|�C���^
	MultiBg m_Multibg;
	D3DXVECTOR2 m_texFrontLeftUp;	  // �e�N�X�`���E����W
	D3DXVECTOR2 m_texFrontRightDown;	// �e�N�X�`���������W
	D3DXVECTOR2 m_texMiddleLeftUp;	   // �e�N�X�`���E����W
	D3DXVECTOR2 m_texMiddleRightDown;	// �e�N�X�`���������W
	D3DXVECTOR2 m_texBackLeftUp;	  // �e�N�X�`���E����W
	D3DXVECTOR2 m_texBackRightDown;	  // �e�N�X�`���������W
	float m_fSpeedU;	// ���X�N���[�����x
	float m_fSpeedV;	// �c�X�N���[�����x
};

#endif