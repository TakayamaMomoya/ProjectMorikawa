//*****************************************************
//
// �j�ЃX�|�i�[����[debrisspawner.h]
// Author:���R����
//
//*****************************************************

#ifndef _DEBRISSPAWNER_H_
#define _DEBRISSPAWNER_H_

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "object.h"

//*****************************************************
// �N���X��`
//*****************************************************
class CDebrisSpawner : public CObject
{
public:
	CDebrisSpawner(void);	// �R���X�g���N�^
	~CDebrisSpawner();	// �f�X�g���N�^

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void) {};
	static CDebrisSpawner *Create(D3DXVECTOR3 pos, float fSpeed, int nLife,int nNumDebris);
	void SetPosition(D3DXVECTOR3 pos);
	D3DXVECTOR3 GetPosition(void) { return m_pos; }
	D3DXVECTOR3 GetPositionOld(void) { return D3DXVECTOR3(); }	// �擾����

private:
	D3DXVECTOR3 m_pos;	// �ʒu
	int m_nLife;	// ����
	float m_fSpeed;	// �X�s�[�h
	int m_nNumDebris;	// �f�u���̐�
};

#endif