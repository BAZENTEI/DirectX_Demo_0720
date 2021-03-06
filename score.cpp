//=============================================================================
//
// score処理 [score.cpp]
// Author : 
//
//=============================================================================
#include "main.h"


//*****************************************************************************
// マクロ定義
//*****************************************************************************


//*****************************************************************************
// 構造体定義
//*****************************************************************************

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// グローバル変数:
//*****************************************************************************
int score = 0;

//=============================================================================
// scoreを加算する関数
//=============================================================================
void AddScore()
{
	score++;
}

//=============================================================================
// scoreを加算する関数
//=============================================================================
int *GetScoreAddress(void)
{

	return &score;

}


/*
//=============================================================================
// 初期化処理
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


	// 頂点情報の作成
	MakeVertexPlayer();

	// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,		// デバイスのポインタ
		TEXTURE_GAME_SAMPLE00,				// ファイルの名前
		&g_pD3DTexture);					// 読み込むメモリのポインタ

	return S_OK;
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdatePlayer(void)
{
	PLAYER *ply = GetPlayerAddress(0);

	// アニメーション
	ply->nCountAnim++;



	// アニメーションWaitチェック
	if (((ply->nCountAnim) % TIME_ANIMATION) == 0)
	{
		// パターンの切り替え
		ply->nPatternAnim = (ply->nPatternAnim + 1) % ANIM_PATTERN_NUM;

		// テクスチャ座標を設定
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


	SetVertexPlayer();	// 頂点の計算処理

}

//=============================================================================
// 描画処理
//=============================================================================
void DrawPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	// テクスチャの設定
	pDevice->SetTexture(0, g_pD3DTexture);

	// ポリゴンの描画
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, NUM_PLAYER, g_vertexWk, sizeof(VERTEX_2D));
}


//=============================================================================
// 終了処理
//=============================================================================
void UninitPlayer(void)
{
	if (g_pD3DTexture != NULL)
	{	// テクスチャの開放
		g_pD3DTexture->Release();
		g_pD3DTexture = NULL;
	}
}*/