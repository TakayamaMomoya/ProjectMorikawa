//=====================================================
//
// �u���b�N�}�l�[�W���̏���[blockmanager.cpp]
// Author:�Ό��D�n
//
//=====================================================
#include "blockmanager.h"
#include "manager.h"
#include "texture.h"

//=====================================
//�R���X�g���N�^
//=====================================
CBlockManager::CBlockManager()
{
	for (int cnt = 0; cnt < BLOCK_CREATE_NUM; cnt++)
	{//�u���b�N�I�u�W�F�ʂ�ۓ����
		m_apBlock[cnt] = nullptr;
	}
	m_fSpeed = 0.0f;	//���x����������0
}

//=====================================
//�f�X�g���N�^
//=====================================
CBlockManager::~CBlockManager()
{
}

//=====================================
//������
//=====================================
HRESULT CBlockManager::Init(void)
{
	return S_OK;
}

//=====================================
//�I��
//=====================================
void CBlockManager::Uninit(void)
{
	Release();		//�����j��
}

//=====================================
//�X�V
//=====================================
void CBlockManager::Update(void)
{
	bool bNotDisp = false;

	for (int cnt = 0; cnt < BLOCK_CREATE_NUM; cnt++)
	{//�ŋߔz�u�����u���b�N������
		if (m_apBlock[cnt] != nullptr)
		{//���������ʂ�ۂ���Ȃ�
			//�����蔻��ɕK�v�Ȃ��̎擾
			D3DXVECTOR3 pos = m_apBlock[cnt]->GetPosition();
			float fWidth = m_apBlock[cnt]->GetWidth();

			if (pos.x + fWidth > SCREEN_WIDTH)
			{
				bNotDisp = true;
				break;
			}
		}
	}

	//�u���b�N�����ׂĕ\�����ꂽ
	if (bNotDisp == false)
	{//����
		for (int cnt = 0; cnt < BLOCK_CREATE_NUM; cnt++)
		{//�ő吔������
			m_apBlock[cnt] = CBlock::Create();
			m_apBlock[cnt]->SetSize(32.0f, 32.0f);
			m_apBlock[cnt]->SetPosition(D3DXVECTOR3(SCREEN_WIDTH + 32.0f, BLOCK_START_HEIGHT + (cnt * 32.0f * 2.0f), 0.0f));

			int nIdx = CManager::GetTexture()->Regist("data\\TEXTURE\\Block_R_01.png");
			m_apBlock[cnt]->SetIdxTexture(nIdx);
			m_apBlock[cnt]->SetVtx();
		}
	}
}

//=====================================
//�`��
//=====================================
void CBlockManager::Draw(void)
{
	
}

//=====================================
//����
//=====================================
CBlockManager* CBlockManager::Create(int nPriority)
{
	CBlockManager* pBlockManager = nullptr;

	//�ꉞ�`�F�b�N
	if (pBlockManager == nullptr)
	{//����
		pBlockManager = new CBlockManager;	//����
		pBlockManager->Init();			//������

		return pBlockManager;
	}
	return nullptr;	//���Ԃ�N���Ȃ��Ǝv������
}