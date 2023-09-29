//*****************************************************
//
// ���̏���[arrow.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "bonus.h"
#include "game.h"
#include "universal.h"
#include "manager.h"
#include "objectmanager.h"
#include "texture.h"
#include "number.h"

//*****************************************************
// �}�N����`
//*****************************************************
#define NUM_PLACE	(4)	// ����
#define DEFAULT_WIDTH	(5.0f)	// �W���̕�
#define DEFAULT_HEIGHT	(15.0f)	// �W���̍���
#define BONUS_WIDTH	(DEFAULT_WIDTH * 2)	// �W���̕�
#define BONUS_HEIGHT	(DEFAULT_HEIGHT * 2)	// �W���̍���
#define INITIAL_LIFE	(60)	// ��������
#define BONUS_LINE	(1000)	// �g��\���ɂȂ郉�C��

//=====================================================
// �R���X�g���N�^
//=====================================================
CBonus::CBonus(int nPriority)
{
	m_pos = { 0.0f,0.0f,0.0f };
	m_move = { 0.0f,0.0f,0.0f };
	m_pNumber = nullptr;
	m_nLife = 0;
}

//=====================================================
// �f�X�g���N�^
//=====================================================
CBonus::~CBonus()
{

}

//=====================================================
// ����������
//=====================================================
HRESULT CBonus::Init(void)
{
	m_nLife = INITIAL_LIFE;

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CBonus::Uninit(void)
{
	if (m_pNumber != nullptr)
	{
		m_pNumber->Uninit();
		m_pNumber = nullptr;
	}
	
	Release();
}

//=====================================================
// �X�V����
//=====================================================
void CBonus::Update(void)
{
	m_nLife--;

	// �ړ��ʂ��ʒu�ɔ��f
	m_pos += m_move;

	if (m_pNumber != nullptr)
	{// �������ʒu�ɍ��킹��
		m_pNumber->SetPosition(m_pos);
	}

	if (m_nLife <= 0)
	{
		Uninit();
	}
}

//=====================================================
// �`�揈��
//=====================================================
void CBonus::Draw(void)
{

}

//=====================================================
// ��������
//=====================================================
CBonus *CBonus::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nValue)
{
	CBonus *pBonus = nullptr;

	if (pBonus == nullptr)
	{// �C���X�^���X����
		pBonus = new CBonus;

		if (pBonus == nullptr)
		{
			return nullptr;
		}

		// ����������
		pBonus->Init();

		pBonus->m_pos = pos;
		pBonus->m_move = move;

		if (pBonus->m_pNumber == nullptr)
		{// �����̐���

			pBonus->m_pNumber = CNumber::Create(NUM_PLACE,nValue);

			if (pBonus->m_pNumber != nullptr)
			{
				pBonus->m_pNumber->SetPosition(pos);

				if (nValue < BONUS_LINE)
				{
					pBonus->m_pNumber->SetSizeAll(DEFAULT_WIDTH, DEFAULT_HEIGHT);
				}
				else
				{
					pBonus->m_pNumber->SetSizeAll(BONUS_WIDTH, BONUS_HEIGHT);
				}

				if (nValue < 0)
				{
					nValue *= -1;

					pBonus->m_pNumber->SetValue(nValue, NUM_PLACE);

					pBonus->m_pNumber->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
				}
			}
		}
	}

	return pBonus;
}