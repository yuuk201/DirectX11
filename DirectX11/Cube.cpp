#include "Cube.h"

Cube::Cube():
	m_pos(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f)),
	m_length(1.0f),
	m_VertexList(nullptr), 
	m_IndexList(nullptr)
{}

Cube::~Cube()
{
	if (m_VertexList)
	{
		delete[] m_VertexList;
		m_VertexList = nullptr;
	}

	if (m_IndexList)
	{
		delete[] m_IndexList;
		m_IndexList = nullptr;
	}
}

bool Cube::Initialize(DirectX::XMFLOAT3 pos, float length, DirectX::XMFLOAT4 col)
{
	m_pos = pos;
	m_length = length;
	// Create the vertex list
	m_VertexList = new VertexType[s_VertexBufferNum];
	if (!m_VertexList)
	{
		return false;
	}

	DirectX::XMFLOAT3 vertexs[8];
	//0を中心、長さを1とした場合の頂点座標
	//{ -0.5f, -0.5f,	-0.5f }
	vertexs[0] = DirectX::XMFLOAT3(m_pos.x - m_length / 2, m_pos.y - m_length / 2, m_pos.z - m_length / 2);
	//{  0.5f, -0.5f,	-0.5f }
	vertexs[1] = DirectX::XMFLOAT3(m_pos.x + m_length / 2, m_pos.y - m_length / 2, m_pos.z - m_length / 2);
	//{  0.5f, 0.5f,	-0.5f }
	vertexs[2] = DirectX::XMFLOAT3(m_pos.x + m_length / 2, m_pos.y + m_length / 2, m_pos.z - m_length / 2);
	//{ -0.5f, 0.5f,	-0.5f }
	vertexs[3] = DirectX::XMFLOAT3(m_pos.x - m_length / 2, m_pos.y + m_length / 2, m_pos.z - m_length / 2);
	//{ -0.5f, -0.5f,	0.5f }
	vertexs[4] = DirectX::XMFLOAT3(m_pos.x - m_length / 2, m_pos.y - m_length / 2, m_pos.z + m_length / 2);
	//{  0.5f, -0.5f,	0.5f }
	vertexs[5] = DirectX::XMFLOAT3(m_pos.x + m_length / 2, m_pos.y - m_length / 2, m_pos.z + m_length / 2);
	//{  0.5f, 0.5f,	0.5f }
	vertexs[6] = DirectX::XMFLOAT3(m_pos.x + m_length / 2, m_pos.y + m_length / 2, m_pos.z + m_length / 2);
	//{ -0.5f, 0.5f,	0.5f }
	vertexs[7] = DirectX::XMFLOAT3(m_pos.x - m_length / 2, m_pos.y + m_length / 2, m_pos.z + m_length / 2);

	// Fill the vertex list
	m_VertexList[0].Pos = vertexs[3];
	m_VertexList[1].Pos = vertexs[2];
	m_VertexList[2].Pos = vertexs[0];
	m_VertexList[3].Pos = vertexs[1];
	m_VertexList[4].Pos = vertexs[7];
	m_VertexList[5].Pos = vertexs[4];
	m_VertexList[6].Pos = vertexs[6];
	m_VertexList[7].Pos = vertexs[5];
	m_VertexList[8].Pos = vertexs[7];
	m_VertexList[9].Pos = vertexs[3];
	m_VertexList[10].Pos = vertexs[4];
	m_VertexList[11].Pos = vertexs[0];
	m_VertexList[12].Pos = vertexs[6];
	m_VertexList[13].Pos = vertexs[5];
	m_VertexList[14].Pos = vertexs[2];
	m_VertexList[15].Pos = vertexs[1];
	m_VertexList[16].Pos = vertexs[7];
	m_VertexList[17].Pos = vertexs[6];
	m_VertexList[18].Pos = vertexs[3];
	m_VertexList[19].Pos = vertexs[2];
	m_VertexList[20].Pos = vertexs[4];
	m_VertexList[21].Pos = vertexs[0];
	m_VertexList[22].Pos = vertexs[5];
	m_VertexList[23].Pos = vertexs[1];
	
	// Fill the UV list
	m_VertexList[0].UV = DirectX::XMFLOAT2(0.0f, 0.0f);
	m_VertexList[1].UV = DirectX::XMFLOAT2(1.0f, 0.0f);
	m_VertexList[2].UV = DirectX::XMFLOAT2(1.0f, 1.0f);
	m_VertexList[3].UV = DirectX::XMFLOAT2(0.0f, 1.0f);
	m_VertexList[4].UV = DirectX::XMFLOAT2(0.0f, 0.0f);
	m_VertexList[5].UV = DirectX::XMFLOAT2(1.0f, 0.0f);
	m_VertexList[6].UV = DirectX::XMFLOAT2(1.0f, 1.0f);
	m_VertexList[7].UV = DirectX::XMFLOAT2(0.0f, 1.0f);
	m_VertexList[8].UV = DirectX::XMFLOAT2(0.0f, 0.0f);
	m_VertexList[9].UV = DirectX::XMFLOAT2(1.0f, 0.0f);
	m_VertexList[10].UV = DirectX::XMFLOAT2(1.0f, 1.0f);
	m_VertexList[11].UV = DirectX::XMFLOAT2(0.0f, 1.0f);
	m_VertexList[12].UV = DirectX::XMFLOAT2(0.0f, 0.0f);
	m_VertexList[13].UV = DirectX::XMFLOAT2(1.0f, 0.0f);
	m_VertexList[14].UV = DirectX::XMFLOAT2(1.0f, 1.0f);
	m_VertexList[15].UV = DirectX::XMFLOAT2(0.0f, 1.0f);
	m_VertexList[16].UV = DirectX::XMFLOAT2(0.0f, 0.0f);
	m_VertexList[17].UV = DirectX::XMFLOAT2(1.0f, 0.0f);
	m_VertexList[18].UV = DirectX::XMFLOAT2(1.0f, 1.0f);
	m_VertexList[19].UV = DirectX::XMFLOAT2(0.0f, 1.0f);
	m_VertexList[20].UV = DirectX::XMFLOAT2(0.0f, 0.0f);
	m_VertexList[21].UV = DirectX::XMFLOAT2(1.0f, 0.0f);
	m_VertexList[22].UV = DirectX::XMFLOAT2(1.0f, 1.0f);
	m_VertexList[23].UV = DirectX::XMFLOAT2(0.0f, 1.0f);

	//Color
	for (int i = 0; i < 24; i++)
	{
		m_VertexList[i].Color = col;
	}

	// Create the index list
	m_IndexList = new WORD[s_IndexBufferNum];
	if (!m_IndexList)
	{
		return false;
	}

	// Fill the index list
	m_IndexList[0] = 0; m_IndexList[1] = 1; m_IndexList[2] = 2;
	m_IndexList[3] = 3; m_IndexList[4] = 2; m_IndexList[5] = 1;
	m_IndexList[6] = 4; m_IndexList[7] = 5; m_IndexList[8] = 6;
	m_IndexList[9] = 7; m_IndexList[10] = 6; m_IndexList[11] = 5;
	m_IndexList[12] = 8; m_IndexList[13] = 9; m_IndexList[14] = 10;
	m_IndexList[15] = 11; m_IndexList[16] = 10; m_IndexList[17] = 9;
	m_IndexList[18] = 12; m_IndexList[19] = 13; m_IndexList[20] = 14;
	m_IndexList[21] = 15; m_IndexList[22] = 14; m_IndexList[23] = 13;
	m_IndexList[24] = 16; m_IndexList[25] = 17; m_IndexList[26] = 18;
	m_IndexList[27] = 19; m_IndexList[28] = 18; m_IndexList[29] = 17;
	m_IndexList[30] = 20; m_IndexList[31] = 21; m_IndexList[32] = 22;
	m_IndexList[33] = 23; m_IndexList[34] = 22; m_IndexList[35] = 21;
	
	return true;
}

int Cube::GetVertexListSize()
{
	return s_VertexBufferNum *sizeof(VertexType);
}

int Cube::GetIndexListSize()
{
	return s_IndexBufferNum*sizeof(WORD);
}

const VertexType* Cube::GetVertexList() const
{
	return m_VertexList;
}

const WORD* Cube::GetIndexList() const
{
	return m_IndexList;
}

