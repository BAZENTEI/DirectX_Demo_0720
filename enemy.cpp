//=============================================================================
//
// �v���C���[���� [Player.cpp]
// Author : 
//
//=============================================================================
#include "main.h"
#include "enemy.h"
//#include "input.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
//#define ENEMY_MAX	(1)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexEnemy(void);
void SetTextureEnemy(int cntPattern,ENEMY *emy);	// 
void SetVertexEnemy(ENEMY *emy);				// ���_�̌v�Z����




//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static LPDIRECT3DTEXTURE9		g_pD3DTexture = NULL;					// �e�N�X�`���ւ̃|�C���^

//static VERTEX_2D				g_vertexWk[NUM_VERTEX];					// ���_���i�[���[�N

//static D3DXVECTOR3				g_posPlayer;						// �|���S���̍��W
//static D3DXVECTOR3				g_rotPlayer;						// �|���S���̉�]��
//static int						g_nCountAnim;						// �A�j���[�V�����J�E���g
//static int						g_nPatternAnim;						// �A�j���[�V�����p�^�[���i���o�[

float					g_fRadiusEnemy;									// �|���S���̔��a
float					g_fBaseAngleEnemy;								// �|���S���̊p�x

ENEMY enemy[ENEMY_MAX];												//�G�l�~�[�̔z��

//=============================================================================
// ����������
//=============================================================================
HRESULT InitEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	
		//������
		ENEMY *emy = GetEnemyAddress(0);

		emy->pos = D3DXVECTOR3(200.0f, 0.0f, 0.0f);
		emy->rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		emy->nCountAnim = 0;
		emy->nPatternAnim = 0;

		emy->use = true;
		

		emy = GetEnemyAddress(1);							//for??

		emy->pos = D3DXVECTOR3(400.0f, 50.0f, 0.0f);
		emy->rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		emy->nCountAnim = 0;
		emy->nPatternAnim = 0;

		emy->use = true;

		
		// ���_���̍쐬
		MakeVertexEnemy();

	
	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,		// �f�o�C�X�̃|�C���^
		TEXTURE_ENEMY_SAMPLE00,				// �t�@�C���̖��O
		&g_pD3DTexture);					// �ǂݍ��ރ������̃|�C���^

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitEnemy(void)
{
	if (g_pD3DTexture != NULL)
	{	// �e�N�X�`���̊J��
		g_pD3DTexture->Release();
		g_pD3DTexture = NULL;
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateEnemy(void)
{
	
	/*ENEMY *emy = GetEnemyAddress(0);*/
	ENEMY *emy = GetEnemyAddress(0);
	
	//for (ENEMY *emy = GetEnemyAddress(0); emy <= (enemy + ENEMY_MAX); emy++)		//or &enemy[PLAYER_MAX]
	for (int i = 0; i < ENEMY_MAX; i++, emy++)
	{
		if (emy->use == true)				//	������Ȃ����̂ݕ`��
		{
			// �A�j���[�V����
			emy->nCountAnim++;

			// �A�j���[�V����Wait�`�F�b�N
			if ((emy->nCountAnim % TIME_ANIMATION) == 0)
			{
				// �p�^�[���̐؂�ւ�
				emy->nPatternAnim = (emy->nPatternAnim + 1) % ANIM_PATTERN_NUM;

				// �e�N�X�`�����W��ݒ�
				SetTextureEnemy(emy->nPatternAnim, emy);
			}
		}
		

	}

	
	
	//SetVertexEnemy();	// ���_�̌v�Z����

}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);


	//�ŏ��̏ꍇ
	/*if (emy->use == false)																		
	{
		return;
	}*/

	// �|���S���̕`��
	ENEMY *emy = GetEnemyAddress(0);
	
	for (int i = 0; i < ENEMY_MAX; i++, emy++)
	{
		if (emy->use == true) 
		{
			// �e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pD3DTexture);

			// �|���S���̕`��
			pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, NUM_PLAYER, emy->vertexWk, sizeof(VERTEX_2D));
		}

	}
	
}

//=============================================================================
// ���_�̍쐬
//=============================================================================
HRESULT MakeVertexEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	ENEMY *emy = GetEnemyAddress(0);

	for (int i=0; i < ENEMY_MAX; i++, emy++)
	{
		SetVertexEnemy(emy);
		
		//// ���_���W�̐ݒ�	
		//SetVertexEnemy();								// ���_�̌v�Z����

		//ENEMY *emy = GetEnemyAddress(0);
		emy->vertexWk[0].rhw =							// rhw�̐ݒ�
		emy->vertexWk[1].rhw =	
		emy->vertexWk[2].rhw =
		emy->vertexWk[3].rhw = 1.0f;

		// ���ˌ��̐ݒ�
		emy->vertexWk[0].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
		emy->vertexWk[1].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
		emy->vertexWk[2].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
		emy->vertexWk[3].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
		
		
		SetTextureEnemy(emy->nPatternAnim,emy);
		
	}
	
	/*g_vertexWk[4].rhw =							//������
	g_vertexWk[5].rhw =
	g_vertexWk[6].rhw =
	g_vertexWk[7].rhw = 1.0f;*/

	/*g_vertexWk[4].rhw = 1.0f;						//TRIANGLESTRIP
	g_vertexWk[5].rhw = 1.0f;*/
	

	return S_OK;
}

//=============================================================================
// �e�N�X�`�����W�̐ݒ�
//=============================================================================
void SetTextureEnemy(int cntPattern,ENEMY *emy)
{
	// �e�N�X�`�����W�̐ݒ�(UV)
		
	int x = cntPattern % TEXTURE_PATTERN_DIVIDE_X;
	int y = cntPattern / TEXTURE_PATTERN_DIVIDE_X;
	float sizeX = 1.0f / TEXTURE_PATTERN_DIVIDE_X;
	float sizeY = 1.0f / TEXTURE_PATTERN_DIVIDE_Y;

	emy->vertexWk[0].tex = D3DXVECTOR2((float)(x)* sizeX, (float)(y)* sizeY);
	emy->vertexWk[1].tex = D3DXVECTOR2((float)(x)* sizeX + sizeX, (float)(y)* sizeY);
	emy->vertexWk[2].tex = D3DXVECTOR2((float)(x)* sizeX, (float)(y)* sizeY + sizeY);
	emy->vertexWk[3].tex = D3DXVECTOR2((float)(x)* sizeX + sizeX, (float)(y)* sizeY + sizeY);

	
}


//=============================================================================
// ���_���W�̐ݒ�
//=============================================================================
void SetVertexEnemy(ENEMY *emy)
{
	//ENEMY *emy = GetEnemyAddress(0); 
	
	//for (int i = 0; i < ENEMY_MAX; i++, emy++)
	//{
		// ���_���W�̐ݒ�
		emy->vertexWk[0].vtx = D3DXVECTOR3(emy->pos.x, emy->pos.y, emy->pos.z);
		emy->vertexWk[1].vtx = D3DXVECTOR3(emy->pos.x + TEXTURE_ENEMY_SIZE_X, emy->pos.y, emy->pos.z);
		emy->vertexWk[2].vtx = D3DXVECTOR3(emy->pos.x, emy->pos.y + TEXTURE_ENEMY_SIZE_Y, emy->pos.z);
		emy->vertexWk[3].vtx = D3DXVECTOR3(emy->pos.x + TEXTURE_ENEMY_SIZE_X, emy->pos.y + TEXTURE_ENEMY_SIZE_Y, emy->pos.z);
		
	//}

	
	
}



ENEMY *GetEnemyAddress(int pno)
{
	return &enemy[pno];

}
