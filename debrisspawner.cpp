//*****************************************************
//
// �j�ЃX�|�i�[����[debrisspawner.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "debrisspawner.h"
#include "debris.h"

//=====================================================
// �D�揇�ʂ����߂�R���X�g���N�^
//=====================================================
CDebrisSpawner::CDebrisSpawner()
{
	m_pos = { 0.0f,0.0f,0.0f };
	m_fSpeed = 0.0f;
	m_nLife = 0;
	m_nNumDebris = 0;
	m_type = TYPE_NORMAL;
}

//=====================================================
// �f�X�g���N�^
//=====================================================
CDebrisSpawner::~CDebrisSpawner()
{

}

//=====================================================
// ����������
//=====================================================
HRESULT CDebrisSpawner::Init(void)
{
	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CDebrisSpawner::Uninit(void)
{
	Release();
}

//=====================================================
// �X�V����
//=====================================================
void CDebrisSpawner::Update(void)
{
	D3DXVECTOR3 move;
	float fRot,fSpeed;
	int nLife;
	CDebris *pDebris;

	for (int nCnt = 0; nCnt < m_nNumDebris; nCnt++)
	{
		nLife = rand() % 50 + 10;
		fRot = rand() % 628 - 314 / 100.0f;
		fSpeed = (float)(rand() % (int)(m_fSpeed * 50)) * 0.01f + m_fSpeed * 0.5f;

		move.x = sinf(fRot) * fSpeed;
		move.y = cosf(fRot) * fSpeed;
		move.z = 0.0f;

		pDebris = CDebris::Create(m_pos, nLife);

		pDebris->SetMove(move);
	}

	m_nLife--;

	if (m_nLife < 0)
	{
		// ���g�̔j��
		Uninit();
	}
}

//=====================================================
// �ʒu�ݒ菈��
//=====================================================
void CDebrisSpawner::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//=====================================================
// ��������
//=====================================================
CDebrisSpawner *CDebrisSpawner::Create(D3DXVECTOR3 pos,float fSpeed,int nLife, int nNumDebris, TYPE type)
{
	CDebrisSpawner *pSpawner = nullptr;

	if (pSpawner == nullptr)
	{// �C���X�^���X����
		pSpawner = new CDebrisSpawner;

		pSpawner->m_pos = pos;

		pSpawner->m_nLife = nLife;

		pSpawner->m_fSpeed = fSpeed;

		pSpawner->m_nNumDebris = nNumDebris;

		pSpawner->m_type = type;
	}

	return pSpawner;
}