//=============================================================================
//
// bullet���� [bullet.cpp]
// Author : 
//
//=============================================================================
#include "main.h"
#include "bullet.h"
#include "player.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexBullet(void);									//�o���b�g�̏�����
void SetTextureBullet(int cntPattern,BULLET *blt);				//�e�N�X�`���[�̌v�Z����
void SetVertexBullet(BULLET *blt);								// ���_�̌v�Z����


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static LPDIRECT3DTEXTURE9		g_pD3DTextureBullet = NULL;		// �e�N�X�`���ւ̃|�C���^

BULLET bullet[BULLET_MAX];										//�G�l�~�[�̔z��

//=============================================================================
// ����������
//=============================================================================
HRESULT InitBullet(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	BULLET *blt = GetBulletAddress(0);

	// �e�N�X�`���[�̏��������s���H
	//if (type == 0)
	{
		// �e�N�X�`���̓ǂݍ���
		D3DXCreateTextureFromFile(pDevice,	// �f�o�C�X�̃|�C���^
			TEXTURE_BULLET_SAMPLE00,			// �t�@�C���̖��O
			&g_pD3DTextureBullet);			// �ǂݍ��ރ������̃|�C���^	

	}

	for (int i = 0; i < BULLET_MAX; i++, blt++)
	{
		blt->pos = D3DXVECTOR3(-500.0f, 100.0f, 0.0f);	//�|���S���̍��W�̏�����
		blt->rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		blt->nCountAnim = 0;						//�A�j���[�V�����p�^�[���̏�����
		blt->nPatternAnim = 0;						// �A�j���[�V�����̐؂�ւ��J�E���g�̏�����

		blt->use = false;

		blt->Texture = g_pD3DTextureBullet;					// �e�N�X�`�����
	}
	
	// ���_���̍쐬
	MakeVertexBullet();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitBullet(void)
{
	if (g_pD3DTextureBullet != NULL)
	{	// �e�N�X�`���̊J��
		g_pD3DTextureBullet->Release();
		g_pD3DTextureBullet = NULL;
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateBullet(void)
{
	BULLET *blt = GetBulletAddress(0);

	// �A�j���[�V����
	//blt->nCountAnim++;

	for (int i = 0; i < BULLET_MAX; i++, blt++)
	{
		if (blt->use == true)
		{
			blt->pos.x += 3.0f;
			

			if (blt->pos.x > SCREEN_WIDTH + TEXTURE_BULLET_SIZE_Y)
			{
				blt->pos.x = -100.0f;
				blt->pos.y = 100.0f;
				blt->use = false;

			}
			SetVertexBullet(blt);	// ���_�̌v�Z����
		}
	}
		

}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawBullet(void)
{
	BULLET *blt = GetBulletAddress(0);
	//if (blt->use == false)
	//{
	//	return;
	//}
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	

	// �|���S���̕`��
	for (int i = 0; i < BULLET_MAX; i++, blt++)
	{
		if (blt->use == true)
		{
			// �e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, blt->Texture);

			// �|���S���̕`��
			pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, NUM_BULLET, blt->vertexWk, sizeof(VERTEX_2D));
		}
	}

}

//=============================================================================
// ���_�̍쐬
//=============================================================================
HRESULT MakeVertexBullet(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	BULLET *blt = GetBulletAddress(0);

	for (int i = 0; i < BULLET_MAX; i++, blt++)
	{
		// ���_���W�̐ݒ�	
		SetVertexBullet(blt);	// ���_�̌v�Z����

		blt->vertexWk[0].rhw =	// rhw�̐ݒ�
		blt->vertexWk[1].rhw =
		blt->vertexWk[2].rhw =
		blt->vertexWk[3].rhw = 1.0f;

		// ���ˌ��̐ݒ�
		blt->vertexWk[0].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
		blt->vertexWk[1].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
		blt->vertexWk[2].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
		blt->vertexWk[3].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);

		// �e�N�X�`�����W�̐ݒ�
		SetTextureBullet(blt->nPatternAnim,blt);
	}

	return S_OK;
}

//=============================================================================
// �e�N�X�`�����W�̐ݒ�
//=============================================================================
void SetTextureBullet(int cntPattern,BULLET *blt)
{

	blt->vertexWk[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	blt->vertexWk[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	blt->vertexWk[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	blt->vertexWk[3].tex = D3DXVECTOR2(1.0f, 1.0f);
}


//=============================================================================
// ���_���W�̐ݒ�
//=============================================================================
void SetVertexBullet(BULLET *blt)
{
	

	// ���_���W�̐ݒ�
	blt->vertexWk[0].vtx = D3DXVECTOR3(blt->pos.x, blt->pos.y, blt->pos.z);
	blt->vertexWk[1].vtx = D3DXVECTOR3(blt->pos.x + TEXTURE_BULLET_SIZE_X, blt->pos.y, blt->pos.z);
	blt->vertexWk[2].vtx = D3DXVECTOR3(blt->pos.x, blt->pos.y + TEXTURE_BULLET_SIZE_Y, blt->pos.z);
	blt->vertexWk[3].vtx = D3DXVECTOR3(blt->pos.x + TEXTURE_BULLET_SIZE_X, blt->pos.y + TEXTURE_BULLET_SIZE_Y, blt->pos.z);


}

BULLET *GetBulletAddress(int pno)
{
	return &bullet[pno];

}




void SetBullet(D3DXVECTOR3 pos )
{
	
	BULLET *blt = GetBulletAddress(0);
	
	for (int i = 0; i < BULLET_MAX; i++, blt++)
	{

		if (blt->use == false)							//�����g�p����Ă��Ȃ��ꍇ�A�֐����g��
		{
			//BULLET *blt = GetBulletAddress(0);

			
			blt->pos = D3DXVECTOR3(pos.x - TEXTURE_BULLET_SIZE_X / 2, pos.y - TEXTURE_BULLET_SIZE_Y / 2, 0.0f);
			SetVertexBullet(blt);

			blt->use = true;							//�g�p��
		
			return;										// 1���Z�b�g�����̂ŏI������

		}

	}
	
}


