//=============================================================================
//
// score���� [score.cpp]
// Author : 
//
//=============================================================================
#include "main.h"


//*****************************************************************************
// �}�N����`
//*****************************************************************************


//*****************************************************************************
// �\���̒�`
//*****************************************************************************

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�:
//*****************************************************************************
int score = 0;

//=============================================================================
// score�����Z����֐�
//=============================================================================
void AddScore()
{
	score++;
}

//=============================================================================
// score�����Z����֐�
//=============================================================================
int *GetScoreAddress(void)
{

	return &score;

}


/*
//=============================================================================
// ����������
//=============================================================================
HRESULT InitPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	PLAYER *ply = GetPlayerAddress(0);

	ply->pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	ply->rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	ply->nCountAnim = 0;
	ply->nPatternAnim = 0;
	ply->use = false;


	// ���_���̍쐬
	MakeVertexPlayer();

	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,		// �f�o�C�X�̃|�C���^
		TEXTURE_GAME_SAMPLE00,				// �t�@�C���̖��O
		&g_pD3DTexture);					// �ǂݍ��ރ������̃|�C���^

	return S_OK;
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdatePlayer(void)
{
	PLAYER *ply = GetPlayerAddress(0);

	// �A�j���[�V����
	ply->nCountAnim++;



	// �A�j���[�V����Wait�`�F�b�N
	if (((ply->nCountAnim) % TIME_ANIMATION) == 0)
	{
		// �p�^�[���̐؂�ւ�
		ply->nPatternAnim = (ply->nPatternAnim + 1) % ANIM_PATTERN_NUM;

		// �e�N�X�`�����W��ݒ�
		SetTexturePlayer(ply->nPatternAnim);
	}

	if (GetKeyboardPress(DIK_UP))
	{

		ply->pos.y -= 2.0f;

	}
	else if (GetKeyboardPress(DIK_DOWN))
	{
		ply->pos.y += 2.0f;
	}


	if (GetKeyboardPress(DIK_LEFT))
	{
		ply->pos.x -= 2.0f;
	}
	else if (GetKeyboardPress(DIK_RIGHT))
	{
		ply->pos.x += 2.0f;
	}

	if (GetKeyboardPress(DIK_SPACE))
	{
		SetBullet(ply->pos);
	}


	SetVertexPlayer();	// ���_�̌v�Z����

}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	// �e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_pD3DTexture);

	// �|���S���̕`��
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, NUM_PLAYER, g_vertexWk, sizeof(VERTEX_2D));
}


//=============================================================================
// �I������
//=============================================================================
void UninitPlayer(void)
{
	if (g_pD3DTexture != NULL)
	{	// �e�N�X�`���̊J��
		g_pD3DTexture->Release();
		g_pD3DTexture = NULL;
	}
}*/