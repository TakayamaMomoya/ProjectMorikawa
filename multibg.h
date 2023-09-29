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

	/*typedef MultiBg
	{
		CObject2D *m_apObject2D[3];
	}*/
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
	CObject2D *m_apObject2D[3];
	D3DXVECTOR2 m_texLeftUp;	// �e�N�X�`���E����W
	D3DXVECTOR2 m_texRightDown;	// �e�N�X�`���������W
	float m_fSpeedU;	// ���X�N���[�����x
	float m_fSpeedV;	// �c�X�N���[�����x
};

#endif