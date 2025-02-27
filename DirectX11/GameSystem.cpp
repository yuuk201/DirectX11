// GameSystem�N���X���g����悤�ɂ���
#include "GameSystem.h"
// Direct3D�N���X���g����悤�ɂ���
#include "Direct3D.h"
#include "framework.h"

// DirectX�N���X���g����悤�ɂ���
#include "DirectX.h"

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
		// �P���_�̌`��(����͍��W����)
		struct VertexType
		{
			DirectX::XMFLOAT3 Pos;	// ���W
			DirectX::XMFLOAT2 UV;	// UV���W
			DirectX::XMFLOAT4 Color; // �F
		};
		// �O�p�`����邽�߁A���_���R���
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
		// ���_�o�b�t�@�쐬
		// �E��L�ō�����R�̒��_�͂��̂܂܂ł͕`��Ɏg�p�ł��Ȃ��񂷁c
		// �E�r�f�I���������Ɂu���_�o�b�t�@�v�Ƃ����`�ō��K�v������܂��I
		// �E����͌����������āA���̏�ō���āA�g���āA�����̂Ă܂��B
		//-----------------------------
		// �쐬����o�b�t�@�̎d�l�����߂�
		// �E����͒��_�o�b�t�@�ɂ��邼�I���Ċ����̐ݒ�
		D3D11_BUFFER_DESC vbDesc = {};
		vbDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// �f�o�C�X�Ƀo�C���h����Ƃ��̎��(���_�o�b�t�@�A�C���f�b�N�X�o�b�t�@�A�萔�o�b�t�@�Ȃ�)
		vbDesc.ByteWidth = sizeof(v);					// �쐬����o�b�t�@�̃o�C�g�T�C�Y
		vbDesc.MiscFlags = 0;							// ���̑��̃t���O
		vbDesc.StructureByteStride = 0;					// �\�����o�b�t�@�̏ꍇ�A���̍\���̂̃T�C�Y
		vbDesc.Usage = D3D11_USAGE_DEFAULT;				// �쐬����o�b�t�@�̎g�p�@
		vbDesc.CPUAccessFlags = 0;

		// ��̎d�l��n���Ē��_�o�b�t�@������Ă��炤
		// �������f�o�C�X����ɂ��肢����
		ComPtr<ID3D11Buffer> vb;
		D3D11_SUBRESOURCE_DATA initData = { &v[0], sizeof(v), 0 };	// �������ރf�[�^
		// ���_�o�b�t�@�̍쐬
		D3D.m_device->CreateBuffer(&vbDesc, &initData, &vb);

		//�C���f�b�N�X�o�b�t�@
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
		D3D.m_deviceContext->Draw(4, 0);

	}

    // �o�b�N�o�b�t�@�̓��e����ʂɕ\��
    D3D.m_swapChain->Present(1, 0);
}