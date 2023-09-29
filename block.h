//=====================================================
//
// �u���b�N�̏����̃w�b�_[block.h]
// Author:�Ό��D�n
//
//=====================================================
#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "object2D.h"

//�u���b�N�N���X
class CBlock : public CObject2D
{
public:
	//�u���b�N��ޗ�
	enum TYPE
	{
		TYPE_BLOCK = 0,
		TYPE_NEEDLE,
		TYPE_BEDROCK,
		TYPE_MAX
	};

	//�R���X�g���N�^�E�f�X�g���N�^
	CBlock();
	~CBlock();

	//��{����
	HRESULT Init(void);	// ����������
	void Uninit(void);	// �I������
	void Update(void);	// �X�V����
	void Draw(void);	// �`�揈��
	static CBlock *Create(int nPriority = PRIORITY_DEFAULT);		// ��������

	//�擾
	TYPE GetType(void) { return m_type; }							//�u���b�N��ށi�u���b�N�E�Ƃ����j�擾

	//�ݒ�
	void SetType(const TYPE type) { m_type = type; }				//�u���b�N��ށi�u���b�N�E�Ƃ����j�ݒ�

private:
	bool CheckOutOfRange(void);	//�͈͊O�`�F�b�N
	
	TYPE m_type;			//�u���b�N���
};
#endif // !_BLOCK_H_