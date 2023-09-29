//=====================================================
//
// �u���b�N�}�l�[�W���̏���[blockmanager.cpp]
// Author:�Ό��D�n
//
//=====================================================
#include "blockmanager.h"
#include "manager.h"
#include "texture.h"

//�ÓI�����o�ϐ�
const int CBlockManager::m_aUpDown[BLOCK_CREATE_NUM - MAX_NEEDLE + 2][2] =
{
	{80,20},{65,35},{50,50},{35,65},{20,80}
};

//��������t�@�C���p�X
const char* g_apFilePath[CBlock::TYPE_MAX] =
{
	"data\\TEXTURE\\BLOCK\\block_00.png",
	"data\\TEXTURE\\BLOCK\\bonusblock.png",
	"data\\TEXTURE\\BLOCK\\damageblock.png",
	"data\\TEXTURE\\BLOCK\\bedrock.png"
};

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
	m_nNeedleHeight = 0;
	m_nChangeNeedleHeight = 0;
	m_nSpawnBonus = 0;
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
	m_nChangeNeedleHeight = 5;	//��
	m_nSpawnBonus = 7;

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
		float fDistance;
		if (m_apBlock[0] != nullptr)
		{//�O��̔z�u������
			fDistance = SCREEN_WIDTH - (m_apBlock[0]->GetPosition().x + m_apBlock[0]->GetWidth());
		}
		else
		{//����5
			fDistance = 0.0f;
		}

		//�{�[�i�X�o���^�C�~���O�̎��̓{�[�i�X�̏ꏊ��ݒ�
		int nBonus = -1;
		if (m_nSpawnBonus <= 0)
		{
			nBonus = (m_nNeedleHeight + 1) + rand() % (BLOCK_CREATE_NUM - m_nNeedleHeight - 1);
			m_nSpawnBonus = rand() % BONUS_SPAWN_DEGREE + BONUS_SPAWN_MIN + 1;	//�{�[�i�X�o���^�C�~���O�Đݒ�
		}

		for (int cnt = 0; cnt < BLOCK_CREATE_NUM; cnt++)
		{//�ő吔������
			m_apBlock[cnt] = CBlock::Create();
			m_apBlock[cnt]->SetSize(32.0f, 32.0f);
			m_apBlock[cnt]->SetPosition(D3DXVECTOR3(SCREEN_WIDTH + 32.0f - fDistance, BLOCK_START_HEIGHT + (cnt * 32.0f * 2.0f), 0.0f));

			//�u���b�N��ސݒ�
			int nIdx;
			
			if (cnt > m_nNeedleHeight)
			{//�Ƃ��̍�����艺�i�j��\�u���b�N�j
				if (nBonus == cnt)
				{//�{�[�i�X
					m_apBlock[cnt]->SetType(CBlock::TYPE_BONUS);
					nIdx = CManager::GetTexture()->Regist(g_apFilePath[CBlock::TYPE_BONUS]);
				}
				else
				{//�ʏ�
					m_apBlock[cnt]->SetType(CBlock::TYPE_BLOCK);
					nIdx = CManager::GetTexture()->Regist(g_apFilePath[CBlock::TYPE_BLOCK]);
				}
			}
			else if (cnt == m_nNeedleHeight)
			{//�Ƃ��̍����i�Ƃ��j
				m_apBlock[cnt]->SetType(CBlock::TYPE_NEEDLE);
				nIdx = CManager::GetTexture()->Regist(g_apFilePath[CBlock::TYPE_NEEDLE]);
			}
			if (cnt < m_nNeedleHeight)
			{//�Ƃ��̍�������i��Ձj
				m_apBlock[cnt]->SetType(CBlock::TYPE_BEDROCK);
				nIdx = CManager::GetTexture()->Regist(g_apFilePath[CBlock::TYPE_BEDROCK]);
			}
			m_apBlock[cnt]->SetIdxTexture(nIdx);
			m_apBlock[cnt]->SetVtx();
		}
		m_nChangeNeedleHeight--;	//�ύX�Ȃ��񐔌��炷
		m_nSpawnBonus--;			//�{�[�i�X�J�E���g���炷
	}

	//�����ύX�`�F�b�N
	if (m_nChangeNeedleHeight <= 0)
	{//�ύX����
		int nRand = rand() % (m_aUpDown[m_nNeedleHeight + 1][0] + m_aUpDown[m_nNeedleHeight + 1][1]);
		m_nNeedleHeight += (nRand < m_aUpDown[m_nNeedleHeight + 1][0]) ? 1 : -1;	//�����ύX

		//�Œ�������Ȃ��悤�ɂ���
		if (m_nNeedleHeight < MIN_NEEDLE)
		{
			m_nNeedleHeight = MIN_NEEDLE;
		}
		//�ō�������Ȃ��悤�ɂ���
		else if (m_nNeedleHeight > MAX_NEEDLE)
		{
			m_nNeedleHeight = MAX_NEEDLE;
		}

		m_nChangeNeedleHeight = rand() % MIN_CHANGE_NUM + CHANGE_NUM_DEGREE;	//�ύX�Ȃ��񐔍Đݒ�
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