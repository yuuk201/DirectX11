// GameSystemクラスを使えるようにする
#include "GameSystem.h"
// Direct3Dクラスを使えるようにする
#include "Direct3D.h"
#include "framework.h"

// DirectXクラスを使えるようにする
#include "DirectX.h"

// ゲームの初期設定を行う
void GameSystem::Initialize()
{
	// 画像の読み込み
	m_tex.Load("Logo.png");
}

// このゲームの時間を進める(処理を実行する)
void GameSystem::Execute()
{
    // 画面を青色で塗りつぶす
    float color[4] = { 0.2f, 0.2f, 1.0f, 1.0f };
    D3D.m_deviceContext->ClearRenderTargetView(D3D.m_backBufferView.Get(), color);

	// 三角形の描画
	{
		// １頂点の形式(今回は座標だけ)
		struct VertexType
		{
			DirectX::XMFLOAT3 Pos;	// 座標
			DirectX::XMFLOAT2 UV;	// UV座標
			DirectX::XMFLOAT4 Color; // 色
		};
		// 三角形を作るため、頂点を３つ作る
		VertexType v[4] = {
			{{-0.5f, -0.5f, 0}, {0, 1}, { 1.0f, 0.0f, 0.0f, 1.0f }},
			{{-0.5f,  0.5f, 0}, {0, 0}, { 1.0f, 0.0f, 0.0f, 1.0f }},
			{{ 0.5f, -0.5f, 0}, {1, 1}, { 1.0f, 0.0f, 0.0f, 1.0f }},
			{{ 0.5f,  0.5f, 0}, {1, 0}, { 1.0f, 0.0f, 0.0f, 1.0f }},
		};

		/*VertexType g_VertexList[]{
		{ { -0.5f,  0.5f, -0.5f }, {0, 1}, { 1.0f, 0.0f, 0.0f, 1.0f } },
		{ {  0.5f,  0.5f, -0.5f }, {0, 0}, { 1.0f, 0.0f, 0.0f, 1.0f } },
		{ { -0.5f, -0.5f, -0.5f }, {1, 1}, { 1.0f, 0.0f, 0.0f, 1.0f } },
		{ {  0.5f, -0.5f, -0.5f }, {1, 0}, { 1.0f, 0.0f, 0.0f, 1.0f } },

		{ { -0.5f,  0.5f,  0.5f }, {0, 1}, { 0.0f, 1.0f, 1.0f, 1.0f } },
		{ { -0.5f, -0.5f,  0.5f }, {0, 0}, { 0.0f, 1.0f, 1.0f, 1.0f } },
		{ {  0.5f,  0.5f,  0.5f }, {1, 1}, { 0.0f, 1.0f, 1.0f, 1.0f } },
		{ {  0.5f, -0.5f,  0.5f }, {1, 0}, { 0.0f, 1.0f, 1.0f, 1.0f } },

		{ { -0.5f,  0.5f,  0.5f }, {0, 1}, { 1.0f, 1.0f, 0.0f, 1.0f } },
		{ { -0.5f,  0.5f, -0.5f }, {0, 0}, { 1.0f, 1.0f, 0.0f, 1.0f } },
		{ { -0.5f, -0.5f,  0.5f }, {1, 1}, { 1.0f, 1.0f, 0.0f, 1.0f } },
		{ { -0.5f, -0.5f, -0.5f }, {1, 0}, { 1.0f, 1.0f, 0.0f, 1.0f } },

		{ {  0.5f,  0.5f,  0.5f }, {0, 1}, { 0.0f, 0.0f, 1.0f, 1.0f } },
		{ {  0.5f, -0.5f,  0.5f }, {0, 0}, { 0.0f, 0.0f, 1.0f, 1.0f } },
		{ {  0.5f,  0.5f, -0.5f }, {1, 1}, { 0.0f, 0.0f, 1.0f, 1.0f } },
		{ {  0.5f, -0.5f, -0.5f }, {1, 0}, { 0.0f, 0.0f, 1.0f, 1.0f } },

		{ { -0.5f,  0.5f,  0.5f }, {0, 1}, { 1.0f, 0.0f, 1.0f, 1.0f } },
		{ {  0.5f,  0.5f,  0.5f }, {0, 0}, { 1.0f, 0.0f, 1.0f, 1.0f } },
		{ { -0.5f,  0.5f, -0.5f }, { 1.0f, 0.0f, 1.0f, 1.0f } },
		{ {  0.5f,  0.5f, -0.5f }, {1, 0}, { 1.0f, 0.0f, 1.0f, 1.0f } },

		{ { -0.5f, -0.5f,  0.5f }, {0, 1}, { 0.0f, 1.0f, 0.0f, 1.0f } },
		{ { -0.5f, -0.5f, -0.5f }, {0, 0}, { 0.0f, 1.0f, 0.0f, 1.0f } },
		{ {  0.5f, -0.5f,  0.5f }, {1, 1}, { 0.0f, 1.0f, 0.0f, 1.0f } },
		{ {  0.5f, -0.5f, -0.5f }, {1, 0}, { 0.0f, 1.0f, 0.0f, 1.0f } },
		};

	WORD g_IndexList[]{
		0,  1,  2,     3,  2,  1,
		4,  5,  6,     7,  6,  5,
		8,  9, 10,    11, 10,  9,
		12, 13, 14,    15, 14, 13,
		16, 17, 18,    19, 18, 17,
		20, 21, 22,    23, 22, 21,
	};*/
		WORD g_IndexListRect[]{
		0,  1,  2,     3,  2,  1,
		};


		int a=0;

		//-----------------------------
		// 頂点バッファ作成
		// ・上記で作った３つの頂点はそのままでは描画に使用できないんす…
		// ・ビデオメモリ側に「頂点バッファ」という形で作る必要があります！
		// ・今回は効率無視して、その場で作って、使って、すぐ捨てます。
		//-----------------------------
		// 作成するバッファの仕様を決める
		// ・今回は頂点バッファにするぞ！って感じの設定
		D3D11_BUFFER_DESC vbDesc = {};
		vbDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// デバイスにバインドするときの種類(頂点バッファ、インデックスバッファ、定数バッファなど)
		vbDesc.ByteWidth = sizeof(v);					// 作成するバッファのバイトサイズ
		vbDesc.MiscFlags = 0;							// その他のフラグ
		vbDesc.StructureByteStride = 0;					// 構造化バッファの場合、その構造体のサイズ
		vbDesc.Usage = D3D11_USAGE_DEFAULT;				// 作成するバッファの使用法
		vbDesc.CPUAccessFlags = 0;

		// 上の仕様を渡して頂点バッファを作ってもらう
		// もちろんデバイスさんにお願いする
		ComPtr<ID3D11Buffer> vb;
		D3D11_SUBRESOURCE_DATA initData = { &v[0], sizeof(v), 0 };	// 書き込むデータ
		// 頂点バッファの作成
		D3D.m_device->CreateBuffer(&vbDesc, &initData, &vb);

		//インデックスバッファ
		D3D11_BUFFER_DESC ibDesc;
		ibDesc.ByteWidth = sizeof(g_IndexListRect);
		ibDesc.Usage = D3D11_USAGE_DEFAULT;
		ibDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		ibDesc.CPUAccessFlags = 0;
		ibDesc.MiscFlags = 0;
		ibDesc.StructureByteStride = 0;

		ID3D11Buffer* ib;
		D3D11_SUBRESOURCE_DATA idData;
		idData.pSysMem = g_IndexListRect;
		idData.SysMemPitch = 0;
		idData.SysMemSlicePitch = 0;

		D3D.m_device->CreateBuffer(&ibDesc, &idData, &ib);

		//++++++++++++++++++++ ここから描画していきます ++++++++++++++++++++

		// ここからは「描画の職人」デバイスコンテキストくんが大活躍

		// 頂点バッファを描画で使えるようにセットする
		UINT stride = sizeof(VertexType);
		UINT offset = 0;
		D3D.m_deviceContext->IASetVertexBuffers(0, 1, vb.GetAddressOf(), &stride, &offset);
		//インデックスバッファをセット
		D3D.m_deviceContext->IASetIndexBuffer(ib, DXGI_FORMAT_R16_UINT, 0);
		// プロミティブ・トポロジーをセット
		D3D.m_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

		//-----------------------------
		// シェーダーをセット
		//-----------------------------
		D3D.m_deviceContext->VSSetShader(D3D.m_spriteVS.Get(), 0, 0);
		D3D.m_deviceContext->PSSetShader(D3D.m_spritePS.Get(), 0, 0);
		D3D.m_deviceContext->IASetInputLayout(D3D.m_spriteInputLayout.Get());

		// こんな感じで、ひたすらデバイスコンテキストに情報を渡す
		// テクスチャを、ピクセルシェーダーのスロット0にセット
		D3D.m_deviceContext->PSSetShaderResources(0, 1, m_tex.m_srv.GetAddressOf());

		//-----------------------------
		// 描画実行
		//-----------------------------
		// デバイスコンテキストくん、上記のセットした内容で描画してください、とお願いする
		D3D.m_deviceContext->Draw(4, 0);

	}

    // バックバッファの内容を画面に表示
    D3D.m_swapChain->Present(1, 0);
}