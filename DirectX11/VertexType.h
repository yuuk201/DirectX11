#pragma once
#include <DirectXMath.h>

// １頂点の形式(今回は座標だけ)
struct VertexType
{
	DirectX::XMFLOAT3 Pos;	// 座標
	DirectX::XMFLOAT2 UV;	// UV座標
	DirectX::XMFLOAT4 Color; // 色
};