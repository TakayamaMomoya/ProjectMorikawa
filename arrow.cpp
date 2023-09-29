//*****************************************************
//
// ���̏���[arrow.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "arrow.h"
#include "game.h"
#include "particle.h"
#include "universal.h"
#include "manager.h"
#include "objectmanager.h"
#include "texture.h"
#include "player.h"

//*****************************************************
// �}�N����`
//*****************************************************
#define WIDTH	(50.0f)	// ��
#define HEIGHT	(100.0f)	// ����
#define CHARGE_HEIGHT	(70.0f)	// ���鍂��
#define TEXTURE_PATH	"data\\TEXTURE\\UI\\arrow.png"	// �e�N�X�`���̃p�X

//=====================================================
// �R���X�g���N�^
//=====================================================
CArrow::CArrow(int nPriority)
{

}

//=====================================================
// �f�X�g���N�^
//=====================================================
CArrow::~CArrow()
{

}

//=====================================================
// ����������
//=====================================================
HRESULT CArrow::Init(void)
{
	// �p���N���X�̏�����
	CObject2D::Init();

	SetSize(WIDTH, HEIGHT);
	int nIdx = CManager::GetTexture()->Regist(TEXTURE_PATH);
	SetIdxTexture(nIdx);
	SetVtx();

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CArrow::Uninit(void)
{
	// �p���N���X�̏I��
	CObject2D::Uninit();
}

//=====================================================
// �X�V����
//=====================================================
void CArrow::Update(void)
{
	// �p���N���X�̍X�V
	CObject2D::Update();

	// ���ߕ\��
	DispCharge();

	SetVtx();
}

//=====================================================
// ���߂̕\��
//=====================================================
void CArrow::DispCharge(void)
{
	// �v���C���[�̎擾
	CPlayer::Player *pPlayerInfo = nullptr;

	if (CGame::GetPlayer() != nullptr)
	{
		pPlayerInfo = CGame::GetPlayer()->GetInfo();
	}
	else
	{
		return;
	}

	// �v�Z�p�ϐ�
	float fSize;
	D3DXVECTOR3 pos = pPlayerInfo->pos;
	D3DXCOLOR col = { 1.0f,1.0f,1.0f,1.0f };

	// �^����ɂ��T�C�Y�ݒ�
	fSize = HEIGHT - CHARGE_HEIGHT * pPlayerInfo->fPowJump;

	col.g = 1.0f - pPlayerInfo->fPowJump;
	col.b = 1.0f - pPlayerInfo->fPowJump;

	// �T�C�Y�ݒ�
	SetSize(GetWidth(),fSize);

	// �ʒu�����炷
	pos.x += 80.0f;
	pos.y -= fSize - 70.0f;

	// �ʒu�ݒ�
	SetPosition(pos);

	// �F�ݒ�
	SetCol(col);
}

//=====================================================
// �`�揈��
//=====================================================
void CArrow::Draw(void)
{
	// �p���N���X�̕`��
	CObject2D::Draw();
}

//=====================================================
// ��������
//=====================================================
CArrow *CArrow::Create(void)
{
	CArrow *pDebris = nullptr;

	if (pDebris == nullptr)
	{// �C���X�^���X����
		pDebris = new CArrow;

		// ����������
		pDebris->Init();
	}

	return pDebris;
}