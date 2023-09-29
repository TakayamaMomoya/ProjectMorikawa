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

//*****************************************************
// �}�N����`
//*****************************************************
#define SIZE_DEFAULT	(32.0f)	// �f�t�H���g�̃T�C�Y

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
	CObject2D::SetMove(D3DXVECTOR3(-pBlockManager->GetSpeed(), 0.0f, 0.0f));	//�ړ��ʐݒ�

	if (CheckOutOfRange() == true)
	{//�͈͊O�ɏo��
		Uninit();
		return;
	}

	CObject2D::Update();									//�e����
	CObject2D::SetVtx();									//���_�ړ�

	if (m_pCollisionSphere != nullptr)
	{// ���̓����蔻��̊Ǘ�
		m_pCollisionSphere->SetPositionOld(m_pCollisionSphere->GetPosition());

		m_pCollisionSphere->SetPosition(GetPosition());

		if (m_pCollisionSphere->IsTriggerEnter(CCollision::TAG_PLAYER))
		{// �ΏۂƂ̓����蔻��
			Uninit();
		}
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
