//*****************************************************
//
// ���̏���[arrow.cpp]
// Author:���R����
//
//*****************************************************

#ifndef _ARROW_H_
#define _ARROW_H_

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "Object2D.h"

//*****************************************************
// �N���X�̒�`
//*****************************************************
class CArrow : public CObject2D
{
public:
	CArrow(int nPriority = 3);	// �R���X�g���N�^
	~CArrow();	// �f�X�g���N�^

	static CArrow *Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	void DispCharge(void);	// �^����̕\��
};

#endif
