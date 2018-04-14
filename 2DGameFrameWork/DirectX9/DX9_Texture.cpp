#include "DX9_Texture.h"
using namespace DX9;
Texture::Texture()
{
	p_tex = nullptr;
}
Texture::~Texture()
{
	if (p_tex != nullptr)
	{
		p_tex->Release();
	}
}
bool Texture::Create(IDirect3DDevice9* device, const std::string path)
{
	//�摜�̃T�C�Y��񓙂��擾
	D3DXGetImageInfoFromFile(path.c_str(), &info);
	//�򉻂����̂Ŏg��Ȃ�
	//if (FAILED(D3DXCreateTextureFromFileEx(
	//	device,								//Direct3D�̃f�o�C�X
	//	path.c_str(),						//�t�@�C���p�X
	//	info.Width,							//�T�C�Y
	//	info.Height,						//
	//	NULL,									//�~�b�v�}�b�v���x��(�摜�̕⊮)
	//	NULL,									//�e�N�X�`���̃������̏ꏊ���w��
	//	D3DFMT_UNKNOWN,					//�e�N�X�`���̃s�N�Z���t�H�[�}�b�g
	//	D3DPOOL_MANAGED,					//�������̈ʒu�ƊǗ��̃t���O
	//	D3DX_FILTER_POINT,				//�摜�̃s�N�Z���⊮���@
	//	D3DX_DEFAULT,						//�t�B���^�����O���@
	//	NULL,									//�J���[�L�[�B�摜�̓��ߐE�F
	//	NULL,									//D3DXIMAGE_INFO�̃|�C���^�B�n���Ȃ��ꍇNULL
	//	NULL,									//�摜�̃p���b�g�ւ̃|�C���^
	//	&p_tex								//���������I�u�W�F�N�g�̃|�C���^
	//)))

	if (FAILED(D3DXCreateTextureFromFile(device, path.c_str(), &p_tex)))
	{
		MessageBox(NULL, "�摜�̓ǂݍ��݂Ɏ��s���܂���", "Error", MB_OK);
		return false;
	};
	
	return true;
}

