#pragma once
#include "DirectX.h"
#include "VertexType.h"

class Cube {
public:
	Cube();
	~Cube();
	bool Initialize(DirectX::XMFLOAT3 pos, float length, DirectX::XMFLOAT4 col);

	int GetVertexListSize();
	int GetIndexListSize();
	const VertexType* GetVertexList() const;
	const WORD* GetIndexList() const;
private:
	DirectX::XMFLOAT3 m_pos;
	float m_length;

	VertexType* m_VertexList;
	WORD* m_IndexList;

	static const int s_VertexBufferNum = 24;
	static const int s_IndexBufferNum = 36;
};