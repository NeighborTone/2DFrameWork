#include "DX9_Device.h"
//�O���[�o���ȕϐ�������̂ŁA���O��Ԃɓ����(using�̓_��)
namespace DX9
{
	Direct3D direct3d;

	Direct3D::Direct3D()
	{
		p_d3d = nullptr;
		p_d3dDevice = nullptr;
	}

	Direct3D::~Direct3D()
	{
		if (p_d3d != nullptr)
		{
			p_d3d->Release();
		}
		if (p_d3dDevice != nullptr)
		{
			p_d3dDevice->Release();
		}
	}

	bool Direct3D::Create(System& win)
	{
		//IDirect3D9�R���|�[�l���g�擾
		if (NULL == (p_d3d = Direct3DCreate9(D3D_SDK_VERSION))) { return false; }
		// �f�B�X�v���C���擾(������擾���ăt�H�[�}�b�g���w�肵�Ȃ��ƃt���X�N���[���ɂȂ�Ȃ�)
		D3DDISPLAYMODE display;
		p_d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &display);

		D3DPRESENT_PARAMETERS parameter;
		SecureZeroMemory(&parameter, sizeof(parameter));

		parameter.BackBufferWidth = win.Width();											//�o�b�N�o�b�t�@(�����)�ݒ�l
		parameter.BackBufferHeight = win.Height();										//
		parameter.BackBufferFormat = display.Format;									//��ʂ̃t�H�[�}�b�g���
		parameter.BackBufferCount = 0;														//�o�b�N�o�b�t�@�̐�
		parameter.MultiSampleType = D3DMULTISAMPLE_NONE;							//�}���`�T���v�����i������グ��Ɖ摜�����ꂢ�ɂȂ�j
		parameter.MultiSampleQuality = 0;													//�}���`�T���v���̕i��(NONE�Ȃ�0�ł���)
		parameter.SwapEffect = D3DSWAPEFFECT_DISCARD;								//�t�����g�o�b�t�@�ƃo�b�N�o�b�t�@�̐؂�ւ����@�B�Ƃ肠�����͂���ł���
		parameter.hDeviceWindow = win.GetWindow();										//��ʂ�`�悷��E�B���h�E�n���h���Bnull�Ȃ猻�݃t�H�[�J�X����Ă���E�B���h�E���g�p�����
		parameter.Windowed = true;															//�E�B���h�E�T�C�Y�̐؂�ւ��Btrue�Ȃ�E�B���h�E���[�h
		parameter.EnableAutoDepthStencil = true;										//�[�x�X�e���V���o�b�t�@�A3D���g���Ȃ�true���(Z�o�b�t�@�ƃ}�X�N�@�\)
		parameter.AutoDepthStencilFormat = D3DFMT_D24S8;							//�X�e���V���o�b�t�@�̃t�H�[�}�b�g
		parameter.Flags = 0;																		//�o�b�N�o�b�t�@����t�����g�o�b�t�@�֓]������Ƃ��̃I�v�V����
		parameter.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;		//���t���b�V�����[�g�A�E�C���h�E�Ȃ�0�ɂ���
		parameter.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;		//�X���b�v�̏��������^�C�~���O
																			//HAL���[�h�Ńf�o�C�X����
		if (FAILED(p_d3d->CreateDevice(
			D3DADAPTER_DEFAULT,																	//�f�B�X�v���C�A�_�v�^�̔ԍ��B��{�ύX���Ȃ�
			D3DDEVTYPE_HAL,																		//�`�揈�����n�[�h�E�F�A�ōs��
			parameter.hDeviceWindow,															//�`����s���E�B���h�E�n���h��
			D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
			&parameter,
			&p_d3dDevice))
			)
			if (FAILED(p_d3d->CreateDevice(
				D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL,
				parameter.hDeviceWindow,
				D3DCREATE_MIXED_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
				&parameter,
				&p_d3dDevice))
				)
				// REF���[�h��3D�f�o�C�X�쐬
				if (FAILED(p_d3d->CreateDevice(
					D3DADAPTER_DEFAULT,
					D3DDEVTYPE_REF,
					parameter.hDeviceWindow,
					D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
					&parameter,
					&p_d3dDevice))
					)
					if (FAILED(p_d3d->CreateDevice(
						D3DADAPTER_DEFAULT,
						D3DDEVTYPE_REF,
						parameter.hDeviceWindow,
						D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
						&parameter,
						&p_d3dDevice))
						)

					{
						MessageBox(parameter.hDeviceWindow, "�f�o�C�X�̐����Ɏ��s���܂���", "Error", MB_OK);
						p_d3d->Release();
						return false;
					}



		p_d3dDevice->SetRenderState(D3DRS_ZENABLE, true);								//����ȍ~�̕`���Z�o�b�t�@��K�p
		p_d3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);				//�J�����O���I���i�|���S���̗���`�悵�Ȃ��j
		p_d3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);				//�A���t�@�u�����h��L���ɂ���
		p_d3dDevice->SetRenderState(D3DRS_LIGHTING, false);							//���C�g�Ȃ�
																					//�\�[�X�f�[�^�ƃf�X�e�l�[�V�����f�[�^�̃u�����h
		p_d3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		p_d3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);



		return true;
	}

}

