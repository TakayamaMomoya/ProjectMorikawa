//=====================================================
//
// �u���b�N�̏���[block.cpp]
// Author:�Ό��D�n
//
//=====================================================
#include "game.h"
#include "block.h"
#include "blockmanager.h"
#include "collision.h"
#include "debrisspawner.h"
#include "score.h"
#include "bonus.h"
#include "sound.h"
#include "manager.h"

//*****************************************************
// �}�N����`
//*****************************************************
#define SIZE_DEFAULT	(32.0f)	// �f�t�H���g�̃T�C�Y
#define NORMAL_SCORE	(200)	// �ʏ�X�R�A
#define BONUS_SCORE	(1500)	// �{�[�i�X�X�R�A

//=====================================
//�R���X�g���N�^
//=====================================
CBlock::CBlock()
{
	m_pCollisionSphere = nullptr;
}

//=====================================
//�f�X�g���N�^
//=====================================
CBlock::~CBlock()
{
}

//=====================================
//������
//=====================================
HRESULT CBlock::Init(void)
{
	if (m_pCollisionSphere == nullptr)
	{// ���̓����蔻�萶��
		m_pCollisionSphere = CCollisionSphere::Create(CCollision::TAG_BLOCK, CCollision::TYPE_SPHERE, this);

		float fRadius;

		if (m_pCollisionSphere != nullptr)
		{// ���̐ݒ�
			fRadius = SIZE_DEFAULT;

			m_pCollisionSphere->SetPosition(GetPosition());
			m_pCollisionSphere->SetRadius(fRadius);
		}
	}

	return CObject2D::Init();	//�e����
}

//=====================================
//�I��
//=====================================
void CBlock::Uninit(void)
{
	if (m_pCollisionSphere != nullptr)
	{// �����蔻��̏���
		m_pCollisionSphere->Uninit();

		m_pCollisionSphere = nullptr;
	}

	CObject2D::Uninit();		//�e����
}

//=====================================
// �X�V
//=====================================
void CBlock::Update(void)
{
	CBlockManager* pBlockManager = CGame::GetBlockManager();
	CObject2D::SetMove(D3DXVECTOR3(-pBlockManager->GetSpeed() * CGame::GetGameSpeed(), 0.0f, 0.0f));	//�ړ��ʐݒ�

	if (CheckOutOfRange() == true)
	{//�͈͊O�ɏo��
		Uninit();
		return;
	}

	CObject2D::Update();									//�e����
	CObject2D::SetVtx();									//���_�ړ�

	// �����蔻��̊Ǘ�
	ManageCollision();
}

//=====================================
// �����蔻��Ǘ�
//=====================================
void CBlock::ManageCollision(void)
{
	if (m_pCollisionSphere != nullptr)
	{// ���̓����蔻��̊Ǘ�
		m_pCollisionSphere->SetPositionOld(m_pCollisionSphere->GetPosition());

		m_pCollisionSphere->SetPosition(GetPosition());

		if (m_pCollisionSphere->IsTriggerEnter(CCollision::TAG_PLAYER))
		{// �ΏۂƂ̓����蔻��
			ManageHit(m_pCollisionSphere->GetOther());

		}
	}
}

//=====================================
// �����������̊Ǘ�
//=====================================
void CBlock::ManageHit(CObject *pObj)
{
	CSound *pSound = CManager::GetSound();

	// �X�R�A�擾
	CScore *pScore = CGame::GetScore();

	switch (m_type)
	{
	case CBlock::TYPE_BLOCK:

		CDebrisSpawner::Create(GetPosition(), 10.0f, 2, 3);

		if (pScore != nullptr)
		{
			pScore->AddScore(NORMAL_SCORE);
		}

		CBonus::Create(GetPosition(), GetMove(), NORMAL_SCORE);

		pSound->Play(CSound::LABELBREAK_SE);

		Uninit();

		break;
	case CBlock::TYPE_BONUS:

		CDebrisSpawner::Create(GetPosition(), 20.0f, 2, 30,CDebrisSpawner::TYPE_BONUS);

		if (pScore != nullptr)
		{
			pScore->AddScore(BONUS_SCORE);
		}

		CBonus::Create(GetPosition(), GetMove(), BONUS_SCORE);

		pSound->Play(CSound::LABELBONUS_SE);

		Uninit();

		break;
	case CBlock::TYPE_NEEDLE:

		if (pObj != nullptr)
		{
			pObj->Hit(0.0f);
		}

		break;
	case CBlock::TYPE_BEDROCK:
	default:
		break;
	}

}

//=====================================
//�`��
//=====================================
void CBlock::Draw(void)
{
	CObject2D::Draw();			//�e����
}

//=====================================
//����
//=====================================
CBlock* CBlock::Create(int nPriority)
{
	CBlock* pBlock = nullptr;

	//�ꉞ�`�F�b�N
	if (pBlock == nullptr)
	{//����
		pBlock = new CBlock;	//����
		pBlock->Init();			//������

		return pBlock;
	}
	return nullptr;	//���Ԃ�N���Ȃ��Ǝv������
}

//=====================================
//�͈͊O�`�F�b�N
//=====================================
bool CBlock::CheckOutOfRange(void)
{
	//�����蔻��Ɏg���ϐ��擾
	D3DXVECTOR3 pos = CObject2D::GetPosition();	//�ʒu�擾
	float fWidthHalf = CObject2D::GetWidth();	//���擾
	
	//�͈͊O�o���H
	if (pos.x + fWidthHalf < 0.0f)
	{//�o��
		return true;
	}
	else
	{//�o�ĂȂ�
		return false;
	}
}
