//=============================================================================
//
// �o���b�g���� [bullet.h]
// Author : 
//
//=============================================================================

#ifndef _BULLET_H_
#define _BULLET_H_


// �}�N����`
#define TEXTURE_BULLET_SAMPLE00	_T("data/TEXTURE/ddon.png")	// �T���v���p�摜
#define TEXTURE_BULLET_SIZE_X	(50)	// �e�N�X�`���T�C�Y
#define TEXTURE_BULLET_SIZE_Y	(50)	// 

#define TEXTURE_PATTERN_DIVIDE_X	(5)	// �A�j���p�^�[���̃e�N�X�`�����������iX)
#define TEXTURE_PATTERN_DIVIDE_Y	(2)	// �A�j���p�^�[���̃e�N�X�`�����������iY)
#define ANIM_PATTERN_NUM			(TEXTURE_PATTERN_DIVIDE_X*TEXTURE_PATTERN_DIVIDE_Y)	// �A�j���[�V�����p�^�[����
#define TIME_ANIMATION				(4)	// �A�j���[�V�����̐؂�ւ��J�E���g


#define	RADIUS_MIN				(50.0f)							// �|���S���̔��a�ŏ��l
#define	RADIUS_MAX				(300.0f)						// �|���S���̔��a�ő�l
#define	VALUE_ROTATION			(D3DX_PI * 0.01f)				// �|���S���̉�]��
#define	VALUE_SCALE				(2.0f)							// �|���S���̃X�P�[���ω���


#define	NUM_BULLET		(2)				    // polygon��


//*****************************************************************************
// �\���̒�`
//*****************************************************************************
typedef struct
{
	D3DXVECTOR3				pos;						// �|���S���̍��W
	D3DXVECTOR3				rot;						// �|���S���̉�]��
	int						nCountAnim;					// �A�j���[�V�����J�E���g
	int						nPatternAnim;				// �A�j���[�V�����p�^�[���i���o�[
	bool                    use;						//�g�pflag

}BULLET;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);

void SetBullet(D3DXVECTOR3 pos);
BULLET *GetBulletAddress(int pno);
#endif