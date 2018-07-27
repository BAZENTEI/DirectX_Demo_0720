//=============================================================================
//
// bullet処理 [bullet.cpp]
// Author : 
//
//=============================================================================
#include "main.h"
#include "bullet.h"
#include "player.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT MakeVertexBullet(void);									//バレットの初期化
void SetTextureBullet(int cntPattern,BULLET *blt);				//テクスチャーの計算処理
void SetVertexBullet(BULLET *blt);								// 頂点の計算処理


//*****************************************************************************
// グローバル変数
//*****************************************************************************
static LPDIRECT3DTEXTURE9		g_pD3DTextureBullet = NULL;		// テクスチャへのポインタ

BULLET bullet[BULLET_MAX];										//エネミーの配列

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT InitBullet(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	BULLET *blt = GetBulletAddress(0);

	// テクスチャーの初期化を行う？
	//if (type == 0)
	{
		// テクスチャの読み込み
		D3DXCreateTextureFromFile(pDevice,	// デバイスのポインタ
			TEXTURE_BULLET_SAMPLE00,			// ファイルの名前
			&g_pD3DTextureBullet);			// 読み込むメモリのポインタ	

	}

	for (int i = 0; i < BULLET_MAX; i++, blt++)
	{
		blt->pos = D3DXVECTOR3(-500.0f, 100.0f, 0.0f);	//ポリゴンの座標の初期化
		blt->rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		blt->nCountAnim = 0;						//アニメーションパターンの初期化
		blt->nPatternAnim = 0;						// アニメーションの切り替わるカウントの初期化

		blt->use = false;

		blt->Texture = g_pD3DTextureBullet;					// テクスチャ情報
	}
	
	// 頂点情報の作成
	MakeVertexBullet();

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitBullet(void)
{
	if (g_pD3DTextureBullet != NULL)
	{	// テクスチャの開放
		g_pD3DTextureBullet->Release();
		g_pD3DTextureBullet = NULL;
	}
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateBullet(void)
{
	BULLET *blt = GetBulletAddress(0);

	// アニメーション
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
			SetVertexBullet(blt);	// 頂点の計算処理
		}
	}
		

}

//=============================================================================
// 描画処理
//=============================================================================
void DrawBullet(void)
{
	BULLET *blt = GetBulletAddress(0);
	//if (blt->use == false)
	//{
	//	return;
	//}
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	

	// ポリゴンの描画
	for (int i = 0; i < BULLET_MAX; i++, blt++)
	{
		if (blt->use == true)
		{
			// テクスチャの設定
			pDevice->SetTexture(0, blt->Texture);

			// ポリゴンの描画
			pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, NUM_BULLET, blt->vertexWk, sizeof(VERTEX_2D));
		}
	}

}

//=============================================================================
// 頂点の作成
//=============================================================================
HRESULT MakeVertexBullet(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	BULLET *blt = GetBulletAddress(0);

	for (int i = 0; i < BULLET_MAX; i++, blt++)
	{
		// 頂点座標の設定	
		SetVertexBullet(blt);	// 頂点の計算処理

		blt->vertexWk[0].rhw =	// rhwの設定
		blt->vertexWk[1].rhw =
		blt->vertexWk[2].rhw =
		blt->vertexWk[3].rhw = 1.0f;

		// 反射光の設定
		blt->vertexWk[0].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
		blt->vertexWk[1].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
		blt->vertexWk[2].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
		blt->vertexWk[3].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);

		// テクスチャ座標の設定
		SetTextureBullet(blt->nPatternAnim,blt);
	}

	return S_OK;
}

//=============================================================================
// テクスチャ座標の設定
//=============================================================================
void SetTextureBullet(int cntPattern,BULLET *blt)
{

	blt->vertexWk[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	blt->vertexWk[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	blt->vertexWk[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	blt->vertexWk[3].tex = D3DXVECTOR2(1.0f, 1.0f);
}


//=============================================================================
// 頂点座標の設定
//=============================================================================
void SetVertexBullet(BULLET *blt)
{
	

	// 頂点座標の設定
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

		if (blt->use == false)							//もし使用されていない場合、関数を使う
		{
			//BULLET *blt = GetBulletAddress(0);

			
			blt->pos = D3DXVECTOR3(pos.x - TEXTURE_BULLET_SIZE_X / 2, pos.y - TEXTURE_BULLET_SIZE_Y / 2, 0.0f);
			SetVertexBullet(blt);

			blt->use = true;							//使用中
		
			return;										// 1発セットしたので終了する

		}

	}
	
}


