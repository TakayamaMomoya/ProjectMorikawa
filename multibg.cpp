//*****************************************************
//
// �w�i�̏���[bg.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "main.h"
#include "multibg.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"

//*****************************************************
// �}�N����`
//*****************************************************
#define BG_FRONT	"data\\TEXTURE\\BG\\bg000.png"	        // ��ԑO�̔w�i
#define BG_MIDDLE	"data\\TEXTURE\\BG\\bg001.png"	        // �^�񒆂̔w�i
#define BG_BACK	    "data\\TEXTURE\\BG\\bg002.jpg"	        // ��Ԍ��̔w�i

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
LPDIRECT3DTEXTURE9 CMultiBg::m_pTexture = nullptr;	// �e�N�X�`���̃|�C���^

//=====================================================
// �R���X�g���N�^
//=====================================================
CMultiBg::CMultiBg(int nPriority) : CObject2D(nPriority)
{
	m_fSpeedU = 0.0f;
	m_fSpeedV = 0.0f;
	m_texLeftUp = { 0.0f,0.0f };
	m_texRightDown = { 0.0f,0.0f };
}

//=====================================================
// �f�X�g���N�^
//=====================================================
CMultiBg::~CMultiBg()
{

}

//=====================================================
// ����������
//=====================================================
HRESULT CMultiBg::Init(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	for(int nCount = 0; nCount < 3; nCount++)
	{
		if (m_apObject2D[nCount] == NULL)
		{//�g�p���Ă��Ȃ�������

			//����
			m_apObject2D[nCount] = CObject2D::Create(1, SCREEN_HEIGHT * 0.5f);

			if (nCount == 0)
			{
				int nIdx = CManager::GetTexture()->Regist(BG_BACK);
				m_apObject2D[0]->SetIdxTexture(nIdx);
			}

			if (nCount == 1)
			{
				int nIdx = CManager::GetTexture()->Regist(BG_MIDDLE);
				m_apObject2D[1]->SetIdxTexture(nIdx);
			}

			if (nCount == 2)
			{
				int nIdx = CManager::GetTexture()->Regist(BG_FRONT);
				m_apObject2D[2]->SetIdxTexture(nIdx);
			}

			//����������
			m_apObject2D[nCount]->Init();
		}
	}

	// �p���N���X�̏�����
	//CObject2D::Init();

	m_texLeftUp = { 0.0f,0.0f };
	m_texRightDown = { 1.0f,1.0f };

	return S_OK;
}

//=====================================================
// �I������
//=====================================================
void CMultiBg::Uninit(void)
{
	// �p���N���X�̏I��
	//CObject2D::Uninit();

	for (int nCount = 0; nCount < 3; nCount++)
	{
		if (m_apObject2D[nCount] != NULL)
		{
			m_apObject2D[nCount]->Uninit();

			m_apObject2D[nCount] = NULL;
		}
	}
}

//=====================================================
// �X�V����
//=====================================================
void CMultiBg::Update(void)
{
	m_texLeftUp.x += m_fSpeedU;
	m_texLeftUp.y += m_fSpeedV;
	m_texRightDown.x += m_fSpeedU;
	m_texRightDown.y += m_fSpeedV;

	if (m_texLeftUp.x > 1.0f)
	{
		m_texLeftUp.x -= 1.0f;
		m_texRightDown.x -= 1.0f;
	}

	if (m_texLeftUp.y > 1.0f)
	{
		m_texLeftUp.y -= 1.0f;
		m_texRightDown.y -= 1.0f;
	}

	// �p���N���X�̍X�V
	//CObject2D::Update();

	for (int nCount = 0; nCount < 3; nCount++)
	{
		if (m_apObject2D[nCount] != NULL)
		{
			m_apObject2D[nCount]->Update();

			m_apObject2D[nCount]->SetVtx();

			m_apObject2D[nCount]->SetTex(m_texLeftUp, m_texRightDown);
		}
	}

	// ���_���ݒ�
	//SetVtx();

	// �e�N�X�`�����W�X�V
	//SetTex(m_texLeftUp, m_texRightDown);
}

//=====================================================
// �`�揈��
//=====================================================
void CMultiBg::Draw(void)
{
	// �p���N���X�̕`��
	//CObject2D::Draw();

	for (int nCount = 0; nCount < 3; nCount++)
	{
		if (m_apObject2D[nCount] != NULL)
		{
			m_apObject2D[nCount]->Draw();
		}
	}
}

//=====================================================
// �Ǎ�����
//=====================================================
HRESULT CMultiBg::Load(void)
{
	if (m_pTexture == nullptr)
	{
		// �f�o�C�X�̎擾
		LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

		D3DXCreateTextureFromFile
		(
			pDevice,
			"data\\TEXTURE\\BG\\bg101.jpg",
			&m_pTexture
		);
	}

	return S_OK;
}

//=====================================================
// �j������
//=====================================================
void CMultiBg::Unload(void)
{
	if (m_pTexture != nullptr)
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
	}
}

//=====================================================
// �X�N���[�����x�ݒ菈��
//=====================================================
void CMultiBg::SetScroll(float fSpeedV, float fSpeedU)
{
	m_fSpeedV = fSpeedV;
	m_fSpeedU = fSpeedU;
}

//=====================================================
// ��������
//=====================================================
CMultiBg *CMultiBg::Create(void)
{
	CMultiBg *pBg = nullptr;

	if (pBg == nullptr)
	{// �C���X�^���X����
		pBg = new CMultiBg;

		// ����������
		pBg->Init();
		pBg->SetSize(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
		pBg->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
	}

	return pBg;
}