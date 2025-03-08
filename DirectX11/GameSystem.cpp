// GameSystem�N���X���g����悤�ɂ���
#include "GameSystem.h"
// Direct3D�N���X���g����悤�ɂ���
#include "Direct3D.h"
#include "framework.h"

// DirectX�N���X���g����悤�ɂ���
#include "DirectX.h"

#include "VertexType.h"
#include "Cube.h"

// �Q�[���̏����ݒ���s��
void GameSystem::Initialize()
{
	// �摜�̓ǂݍ���
	m_tex.Load("Logo.png");
}

// ���̃Q�[���̎��Ԃ�i�߂�(���������s����)
void GameSystem::Execute()
{
    // ��ʂ�F�œh��Ԃ�
    float color[4] = { 0.2f, 0.2f, 1.0f, 1.0f };
    D3D.m_deviceContext->ClearRenderTargetView(D3D.m_backBufferView.Get(), color);

	// �O�p�`�̕`��
	{
		// �O�p�`����邽�߁A���_���R���
		/*VertexType v[4] = {
			{{-0.5f, -0.5f, 0}, {0, 1}, { 1.0f, 0.0f, 0.0f, 1.0f }},
			{{-0.5f,  0.5f, 0}, {0, 0}, { 1.0f, 0.0f, 0.0f, 1.0f }},
			{{ 0.5f, -0.5f, 0}, {1, 1}, { 1.0f, 0.0f, 0.0f, 1.0f }},
			{{ 0.5f,  0.5f, 0}, {1, 0}, { 1.0f, 0.0f, 0.0f, 1.0f }},
		};*/

	//	VertexType g_VertexList[]{
	//		{ { -0.5f,  0.5f, -0.5f }, {0, 1}, { 1.0f, 0.0f, 0.0f, 1.0f } },//3
	//		{ {  0.5f,  0.5f, -0.5f }, {0, 0}, { 1.0f, 0.0f, 0.0f, 1.0f } },//2
	//		{ { -0.5f, -0.5f, -0.5f }, {1, 1}, { 1.0f, 0.0f, 0.0f, 1.0f } },//0
	//		{ {  0.5f, -0.5f, -0.5f }, {1, 0}, { 1.0f, 0.0f, 0.0f, 1.0f } },//1

	//		{ { -0.5f,  0.5f,  0.5f }, {0, 1}, { 0.0f, 1.0f, 1.0f, 1.0f } },//7
	//		{ { -0.5f, -0.5f,  0.5f }, {0, 0}, { 0.0f, 1.0f, 1.0f, 1.0f } },//4
	//		{ {  0.5f,  0.5f,  0.5f }, {1, 1}, { 0.0f, 1.0f, 1.0f, 1.0f } },//6
	//		{ {  0.5f, -0.5f,  0.5f }, {1, 0}, { 0.0f, 1.0f, 1.0f, 1.0f } },//5

	//		{ { -0.5f,  0.5f,	0.5f }, {0, 1}, { 1.0f, 1.0f, 0.0f, 1.0f } },//7
	//		{ { -0.5f,  0.5f,	-0.5f }, {0, 0}, { 1.0f, 1.0f, 0.0f, 1.0f } },//3
	//		{ { -0.5f, -0.5f,	0.5f }, {1, 1}, { 1.0f, 1.0f, 0.0f, 1.0f } },//4
	//		{ { -0.5f, -0.5f,	-0.5f }, {1, 0}, { 1.0f, 1.0f, 0.0f, 1.0f } },//0

	//		{ {  0.5f,  0.5f,	0.5f }, {0, 1}, { 0.0f, 0.0f, 1.0f, 1.0f } },//6
	//		{ {  0.5f, -0.5f,	0.5f }, {0, 0}, { 0.0f, 0.0f, 1.0f, 1.0f } },//5
	//		{ {  0.5f,  0.5f,	-0.5f }, {1, 1}, { 0.0f, 0.0f, 1.0f, 1.0f } },//2
	//		{ {  0.5f, -0.5f,	-0.5f }, {1, 0}, { 0.0f, 0.0f, 1.0f, 1.0f } },//1

	//		{ { -0.5f,  0.5f,	0.5f }, {0, 1}, { 1.0f, 0.0f, 1.0f, 1.0f } },//7
	//		{ {  0.5f,  0.5f,	0.5f }, {0, 0}, { 1.0f, 0.0f, 1.0f, 1.0f } },//6
	//		{ { -0.5f,  0.5f,	-0.5f }, {1, 1}, { 1.0f, 0.0f, 1.0f, 1.0f } },//3
	//		{ {  0.5f,  0.5f,	-0.5f }, {1, 0}, { 1.0f, 0.0f, 1.0f, 1.0f } },//2

	//		{ { -0.5f, -0.5f,	0.5f }, {0, 1}, { 0.0f, 1.0f, 0.0f, 1.0f } },//4
	//		{ { -0.5f, -0.5f,	-0.5f }, {0, 0}, { 0.0f, 1.0f, 0.0f, 1.0f } },//0
	//		{ {  0.5f, -0.5f,	0.5f }, {1, 1}, { 0.0f, 1.0f, 0.0f, 1.0f } },//5
	//		{ {  0.5f, -0.5f,	-0.5f }, {1, 0}, { 0.0f, 1.0f, 0.0f, 1.0f } },//1
	//	};
	//	/*VertexType g_VertexList[]{
	//	{ { -0.5f,  0.5f, 0.5f }, {0, 1}, { 1.0f, 0.0f, 0.0f, 1.0f } },
	//	{ {  0.5f,  0.5f, 0.5f }, {0, 0}, { 1.0f, 0.0f, 0.0f, 1.0f } },
	//	{ { -0.5f, -0.5f, 0.5f }, {1, 1}, { 1.0f, 0.0f, 0.0f, 1.0f } },
	//	{ {  0.5f, -0.5f, 0.5f }, {1, 0}, { 1.0f, 0.0f, 0.0f, 1.0f } },

	//	{ { -0.5f,  0.5f,  0.5f }, {0, 1}, { 0.0f, 1.0f, 1.0f, 1.0f } },
	//	{ { -0.5f, -0.5f,  0.5f }, {0, 0}, { 0.0f, 1.0f, 1.0f, 1.0f } },
	//	{ {  0.5f,  0.5f,  0.5f }, {1, 1}, { 0.0f, 1.0f, 1.0f, 1.0f } },
	//	{ {  0.5f, -0.5f,  0.5f }, {1, 0}, { 0.0f, 1.0f, 1.0f, 1.0f } },

	//	{ { -0.5f,  0.5f,  0.5f }, {0, 1}, { 1.0f, 1.0f, 0.0f, 1.0f } },
	//	{ { -0.5f,  0.5f, 0.5f }, {0, 0}, { 1.0f, 1.0f, 0.0f, 1.0f } },
	//	{ { -0.5f, -0.5f,  0.5f }, {1, 1}, { 1.0f, 1.0f, 0.0f, 1.0f } },
	//	{ { -0.5f, -0.5f, 0.5f }, {1, 0}, { 1.0f, 1.0f, 0.0f, 1.0f } },

	//	{ {  0.5f,  0.5f,	0.5f }, {0, 1}, { 0.0f, 0.0f, 1.0f, 1.0f } },
	//	{ {  0.5f, -0.5f,	0.5f }, {0, 0}, { 0.0f, 0.0f, 1.0f, 1.0f } },
	//	{ {  0.5f,  0.5f,	0.5f }, {1, 1}, { 0.0f, 0.0f, 1.0f, 1.0f } },
	//	{ {  0.5f, -0.5f,	0.5f }, {1, 0}, { 0.0f, 0.0f, 1.0f, 1.0f } },

	//	{ { -0.5f,  0.5f,	0.5f  }, {0, 1}, { 1.0f, 0.0f, 1.0f, 1.0f } },
	//	{ {  0.5f,  0.5f,	0.5f }, {0, 0}, { 1.0f, 0.0f, 1.0f, 1.0f } },
	//	{ { -0.5f,  0.5f,	0.5f }, {1, 1}, { 1.0f, 0.0f, 1.0f, 1.0f } },
	//	{ {  0.5f,  0.5f,	0.5f }, {1, 0}, { 1.0f, 0.0f, 1.0f, 1.0f } },

	//	{ { -0.5f, -0.5f, 0.5f }, {0, 1}, { 0.0f, 1.0f, 0.0f, 1.0f } },
	//	{ { -0.5f, -0.5f, 0.5f}, {0, 0}, { 0.0f, 1.0f, 0.0f, 1.0f } },
	//	{ {  0.5f, -0.5f, 0.5f }, {1, 1}, { 0.0f, 1.0f, 0.0f, 1.0f } },
	//	{ {  0.5f, -0.5f, 0.5f}, {1, 0}, { 0.0f, 1.0f, 0.0f, 1.0f } },
	//	};*/


	//WORD g_IndexList[]{
	//	0,  1,  2,     3,  2,  1,
	//	4,  5,  6,     7,  6,  5,
	//	8,  9, 10,    11, 10,  9,
	//	12, 13, 14,    15, 14, 13,
	//	16, 17, 18,    19, 18, 17,
	//	20, 21, 22,    23, 22, 21,
	//};
		/*WORD g_IndexListRect[]{
		0,  1,  2,     3,  2,  1,
		};*/

		Cube cube;
		cube.Initialize(DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f, DirectX::XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f));

		//-----------------------------
		// ���_�o�b�t�@�쐬
		// �E��L�ō�����R�̒��_�͂��̂܂܂ł͕`��Ɏg�p�ł��Ȃ��񂷁c
		// �E�r�f�I���������Ɂu���_�o�b�t�@�v�Ƃ����`�ō��K�v������܂��I
		// �E����͌����������āA���̏�ō���āA�g���āA�����̂Ă܂��B
		//-----------------------------
		// �쐬����o�b�t�@�̎d�l�����߂�
		// �E����͒��_�o�b�t�@�ɂ��邼�I���Ċ����̐ݒ�
		D3D11_BUFFER_DESC vbDesc = {};
		vbDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// �f�o�C�X�Ƀo�C���h����Ƃ��̎��(���_�o�b�t�@�A�C���f�b�N�X�o�b�t�@�A�萔�o�b�t�@�Ȃ�)
		vbDesc.ByteWidth = cube.GetVertexListSize();					// �쐬����o�b�t�@�̃o�C�g�T�C�Y
		vbDesc.MiscFlags = 0;							// ���̑��̃t���O
		vbDesc.StructureByteStride = 0;					// �\�����o�b�t�@�̏ꍇ�A���̍\���̂̃T�C�Y
		vbDesc.Usage = D3D11_USAGE_DEFAULT;				// �쐬����o�b�t�@�̎g�p�@
		vbDesc.CPUAccessFlags = 0;

		// ��̎d�l��n���Ē��_�o�b�t�@������Ă��炤
		// �������f�o�C�X����ɂ��肢����
		ComPtr<ID3D11Buffer> vb;
		const VertexType* pVertex = cube.GetVertexList();
		D3D11_SUBRESOURCE_DATA initData = { &(pVertex[0]), cube.GetVertexListSize(), 0};	// �������ރf�[�^
		// ���_�o�b�t�@�̍쐬
		D3D.m_device->CreateBuffer(&vbDesc, &initData, &vb);

		//�C���f�b�N�X�o�b�t�@
		D3D11_BUFFER_DESC ibDesc;
		ibDesc.ByteWidth = cube.GetIndexListSize();
		ibDesc.Usage = D3D11_USAGE_DEFAULT;
		ibDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		ibDesc.CPUAccessFlags = 0;
		ibDesc.MiscFlags = 0;
		ibDesc.StructureByteStride = 0;

		ID3D11Buffer* ib;
		D3D11_SUBRESOURCE_DATA idData;
		const WORD* pIndex = cube.GetIndexList();
		idData.pSysMem = &(pIndex[0]);
		idData.SysMemPitch = 0;
		idData.SysMemSlicePitch = 0;

		D3D.m_device->CreateBuffer(&ibDesc, &idData, &ib);

		//�萔�o�b�t�@
		struct ConstantBuffer {
			DirectX::XMFLOAT4X4 world;
			DirectX::XMFLOAT4X4 view;
			DirectX::XMFLOAT4X4 projection;
		};
		ID3D11Buffer* cbuffer;
		D3D11_BUFFER_DESC cbDesc;
		cbDesc.ByteWidth = sizeof(ConstantBuffer);
		cbDesc.Usage = D3D11_USAGE_DEFAULT;
		cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		cbDesc.CPUAccessFlags = 0;
		cbDesc.MiscFlags = 0;
		cbDesc.StructureByteStride = 0;

		D3D.m_device->CreateBuffer(&cbDesc, NULL, &cbuffer);

		//�萔�o�b�t�@�̒��g��ݒ�
		DirectX::XMMATRIX worldMatrix = DirectX::XMMatrixTranslation(0.0f, 0.0f, 0.0f);

		DirectX::XMVECTOR eye = DirectX::XMVectorSet(2.0f, 2.0f, -2.0f, 0.0f);
		DirectX::XMVECTOR focus = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
		DirectX::XMVECTOR up = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
		DirectX::XMMATRIX viewMatrix = DirectX::XMMatrixLookAtLH(eye, focus, up);

		float    fov = DirectX::XMConvertToRadians(45.0f);
		float    aspect = 1280 / 720;
		float    nearZ = 0.1f;
		float    farZ = 100.0f;
		DirectX::XMMATRIX projMatrix = DirectX::XMMatrixPerspectiveFovLH(fov, aspect, nearZ, farZ);

		ConstantBuffer cb;
		XMStoreFloat4x4(&cb.world, XMMatrixTranspose(worldMatrix));
		XMStoreFloat4x4(&cb.view, XMMatrixTranspose(viewMatrix));
		XMStoreFloat4x4(&cb.projection, XMMatrixTranspose(projMatrix));
		D3D.m_deviceContext->UpdateSubresource(cbuffer, 0, NULL, &cb, 0, 0);


		//++++++++++++++++++++ ��������`�悵�Ă����܂� ++++++++++++++++++++

		// ��������́u�`��̐E�l�v�f�o�C�X�R���e�L�X�g���񂪑劈��

		// ���_�o�b�t�@��`��Ŏg����悤�ɃZ�b�g����
		UINT stride = sizeof(VertexType);
		UINT offset = 0;
		D3D.m_deviceContext->IASetVertexBuffers(0, 1, vb.GetAddressOf(), &stride, &offset);
		//�C���f�b�N�X�o�b�t�@���Z�b�g
		D3D.m_deviceContext->IASetIndexBuffer(ib, DXGI_FORMAT_R16_UINT, 0);
		// �v���~�e�B�u�E�g�|���W�[���Z�b�g
		D3D.m_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
		//�萔�o�b�t�@���Z�b�g
		D3D.m_deviceContext->VSSetConstantBuffers(0, 1, &cbuffer);

		//-----------------------------
		// �V�F�[�_�[���Z�b�g
		//-----------------------------
		D3D.m_deviceContext->VSSetShader(D3D.m_spriteVS.Get(), 0, 0);
		D3D.m_deviceContext->PSSetShader(D3D.m_spritePS.Get(), 0, 0);
		D3D.m_deviceContext->IASetInputLayout(D3D.m_spriteInputLayout.Get());

		// ����Ȋ����ŁA�Ђ�����f�o�C�X�R���e�L�X�g�ɏ���n��
		// �e�N�X�`�����A�s�N�Z���V�F�[�_�[�̃X���b�g0�ɃZ�b�g
		D3D.m_deviceContext->PSSetShaderResources(0, 1, m_tex.m_srv.GetAddressOf());

		//-----------------------------
		// �`����s
		//-----------------------------
		// �f�o�C�X�R���e�L�X�g����A��L�̃Z�b�g�������e�ŕ`�悵�Ă��������A�Ƃ��肢����
		//4���_�~6�ʕ���24��draw���Ă���
		D3D.m_deviceContext->Draw(24, 0);

	}

    // �o�b�N�o�b�t�@�̓��e����ʂɕ\��
    D3D.m_swapChain->Present(1, 0);
}