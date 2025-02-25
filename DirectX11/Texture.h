#pragma once

#include "DirectX.h"
#include"framework.h"

//=========================================
// �e�N�X�`���N���X
//=========================================
class Texture
{
public:

	// �V�F�[�_�[���\�[�X�r���[(�摜�f�[�^�ǂݎ��n���h��)
	ComPtr<ID3D11ShaderResourceView> m_srv = nullptr;
	// �摜���
	DirectX::TexMetadata m_info = {};

	// �摜�t�@�C����ǂݍ���
	bool Load(const std::string& filename);
};