//=====================================================
//
// �u���b�N�̏����̃w�b�_[block.h]
// Author:�Ό��D�n
//
//=====================================================
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
	static CBlock *Create(int nPriority = PRIORITY_DEFAULT);	// ��������

	//�擾
	TYPE GetType(void) { return m_type; }

	//�ݒ�
	void SetType(TYPE type) { m_type = type; }

private:
	TYPE m_type;
};