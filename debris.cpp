//*****************************************************
//
// �j�Ђ̏���[debris.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "debris.h"
#include "game.h"
#include "particle.h"
#include "universal.h"
#include "manager.h"
#include "objectmanager.h"
#include "texture.h"

//*****************************************************
// �}�N����`
//*****************************************************
#define MODE_FACT	(0.9f)	// �ړ��ʂ̌����W��
#define GRAVITY	(0.3f)	// �d��
#define SIZE_DEFAULT	(10.0f)	// �f�t�H���g�̃T�C�Y
#define TEXTURE_PATH	"data\\TEXTURE\\BLOCK\\fragment.png"	// �e�N�X�`���̃p�X

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
int CDebris::m_nNumAll = 0;	// ����

//=====================================================
// �R���X�g���N�^
//=====================================================
CDebris::CDebris(int nPriority)
{
	m_nLife = 0;
	m_fSpeedRotation = 0.0f;

	m_nNumAll++;
}

//=====================================================
// �f�X�g���N�^
//=====================================================
CDebris::~CDebris()
{
	m_nNumAll--;
}

//=====================================================
// ����������
//=====================================================
HRESULT CDebris::Init(void)
{
	// �p���N���X�̏�����
	CObject2D::Init();

	SetSize(SIZE_DEFAULT, SIZE_DEFAULT);
	int nIdx = CManager::GetTexture()->Regist(TEXTURE_PATH);
	SetIdxTexture(nIdx);
	SetVtx();

	// ���X�s�[�h�̐ݒ�
	m_fSpeedRotation = rand() % 100 * 0.001f;

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CDebris::Uninit(void)
{
	// �p���N���X�̏I��
	CObject2D::Uninit();
}

//=====================================================
// �X�V����
//=====================================================
void CDebris::Update(void)
{
	// �ėp�����̎擾
	CUniversal *pUniversal = CManager::GetUniversal();

	D3DXVECTOR3 move = GetMove();
	D3DXVECTOR3 pos = GetPosition();
	float fRot = GetRot();

	// �p���N���X�̍X�V
	CObject2D::Update();

	// �ړ��ʂ��ʒu�ɉ��Z
	SetPosition(pos + move);

	// �ړ��ʌ���
	move.y += GRAVITY;

	SetMove(move);

	fRot += m_fSpeedRotation;

	// �����̏C��
	pUniversal->LimitRot(&fRot);

	SetRot(fRot);

	m_nLife--;

	SetVtx();

	if (m_nLife <= 0)
	{// �����ɂ��j��
		Uninit();
	}
}

//=====================================================
// �`�揈��
//=====================================================
void CDebris::Draw(void)
{
	// �p���N���X�̕`��
	CObject2D::Draw();
}

//=====================================================
// ��������
//=====================================================
CDebris *CDebris::Create(D3DXVECTOR3 pos, int nLife)
{
	CDebris *pDebris = nullptr;

	if (pDebris == nullptr)
	{// �C���X�^���X����
		pDebris = new CDebris;

		pDebris->m_nLife = nLife;

		pDebris->SetPosition(pos);

		// ����������
		pDebris->Init();
	}

	return pDebris;
}