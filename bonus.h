//*****************************************************
//
// �{�[�i�X�\���̏���[bonus.cpp]
// Author:���R����
//
//*****************************************************

#ifndef _BONUS_H_
#define _BONUS_H_

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "Object.h"

//*****************************************************
// �O���錾
//*****************************************************
class CNumber;

//*****************************************************
// �N���X�̒�`
//*****************************************************
class CBonus : public CObject
{
public:
	CBonus(int nPriority = 3);	// �R���X�g���N�^
	~CBonus();	// �f�X�g���N�^

	static CBonus *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move,int nValue);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	D3DXVECTOR3 m_pos;	// �ʒu
	D3DXVECTOR3 m_move;	// �ړ���
	CNumber *m_pNumber;	// �����̃|�C���^
	int m_nLife;	// ����
};

#endif
