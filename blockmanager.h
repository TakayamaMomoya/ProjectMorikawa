//=====================================================
//
// �u���b�N�}�l�[�W���̏����̃w�b�_[blockmanager.h]
// Author:�Ό��D�n
//
//=====================================================
#ifndef _BLOCK_MANAGER_H_
#define _BLOCK_MANAGER_H_

#include "object.h"
#include "block.h"

//��������}�N��
#define BLOCK_CREATE_NUM	(6)		//��x�ɔz�u����u���b�N��
#define BLOCK_START_HEIGHT	(96.0f)	//1�ڂ̃u���b�N�z�u����
#define MIN_NEEDLE			(-1)	//�Ƃ��Œፂ��
#define MAX_NEEDLE			(3)		//�Ƃ��ō�����
#define MIN_CHANGE_NUM		(2)		//�Œ���ς��Ȃ��z�u��
#define CHANGE_NUM_DEGREE	(2)		//�z�u�񐔂̐U�ꕝ
#define BONUS_SPAWN_MIN		(4)		//�{�[�i�X�u���b�N�̍Œ�o���p�x
#define BONUS_SPAWN_DEGREE	(3)		//�{�[�i�X�u���b�N�̐U�ꕝ

//�u���b�N�N���X
class CBlockManager : public CObject
{
public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CBlockManager();
	~CBlockManager();

	//��{����
	HRESULT Init(void);	// ����������
	void Uninit(void);	// �I������
	void Update(void);	// �X�V����
	void Draw(void);	// �`�揈��
	static CBlockManager *Create(int nPriority = PRIORITY_DEFAULT);	// ��������

	//�擾
	float GetSpeed(void) { return m_fSpeed; }						//�X�N���[�����x�擾

	//�ݒ�
	void SetSpeed(const float fSpeed) { m_fSpeed = fSpeed; }		//�X�N���[�����x�ݒ�

private:
	CBlock* m_apBlock[BLOCK_CREATE_NUM];	//�ŋߔz�u�����u���b�N�I�u�W�F
	float m_fSpeed;							//�u���b�N�X�N���[�����x
	int m_nNeedleHeight;					//�Ƃ���u������
	int m_nChangeNeedleHeight;				//�Ƃ��̍�����ς���z�u��
	int m_nSpawnBonus;						//�{�[�i�X�u���b�N�����o�Ă���܂�
};
#endif // !_BLOCK_MANAGER_H_