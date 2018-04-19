#include "DX9_Input.h"

namespace DX9
{
	Input in;

	Input::Input() :buf(),prebuf()
	{
		pDI = nullptr;
		pKey = nullptr;
	}

	Input::~Input()
	{
		//���͂��󂯕t���Ȃ�����(�f�o�C�X�ւ̃A�N�Z�X�����������B)
		pKey->Unacquire();
		if (pDI != nullptr)
		{
			pDI->Release();
		}
		if (pKey != nullptr)
		{
			pKey->Release();
		}
	}

	bool Input::CreateInput(const HWND& hwnd)
	{
		//IDirectInput8�̍쐬
		HRESULT hr = DirectInput8Create(
			GetModuleHandle(NULL),
			DIRECTINPUT_VERSION,
			IID_IDirectInput8,
			(LPVOID*)&pDI,
			NULL);
		if (FAILED(hr))
		{
			MessageBox(NULL, "DirectInput�I�u�W�F�N�g�̐����Ɏ��s���܂���", "Error", MB_OK);
			return false;
		}

		//�f�o�C�X�̎擾
		hr = pDI->CreateDevice(
			GUID_SysKeyboard, 
			&pKey,
			NULL);
		if (FAILED(hr))
		{
			MessageBox(NULL, "�L�[�{�[�h�f�o�C�X�̍쐬�Ɏ��s���܂���", "Error", MB_OK);
			return false;
		}

		//���̓f�[�^�̃t�H�[�}�b�g
		hr = pKey->SetDataFormat(&c_dfDIKeyboard);
		if (FAILED(hr))
		{
			MessageBox(NULL, "���̓f�[�^�̐ݒ�Ɏ��s���܂���", "Error", MB_OK);
			return false;
		}

		//�r������
		hr = pKey->SetCooperativeLevel(
			hwnd,
			DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
		if (FAILED(hr))
		{
			MessageBox(NULL, "�r������̐ݒ�Ɏ��s���܂���", "Error", MB_OK);
			return false;
		}
		//����J�n
		pKey->Acquire();
		int keyList[Input::MAX_KEY] =
		{
			DIK_UP,				//��				
			DIK_LEFT,			//��
			DIK_RIGHT,			//��			
			DIK_DOWN	,			//��
			DIK_ESCAPE,			//Esc
			DIK_RETURN,	        //Enter
			DIK_LSHIFT,	        //Shift(��)	
			DIK_RSHIFT,			//Shift(�E)
			DIK_LCONTROL,	    //Ctrl(��)
			DIK_RCONTROL,	    //Ctrl(�E)					
			DIK_LMENU,			//Alt(��)
			DIK_RMENU,			//Alt(�E)
			DIK_SPACE,			//Space
			DIK_BACK	,			//Back Space
			DIK_TAB,				//Tab
			DIK_1,     			//1
			DIK_2,     			//2
			DIK_3,     			//3
			DIK_4,     			//4
			DIK_5,     			//5
			DIK_6,     			//6
			DIK_7,     			//7
			DIK_8,     			//8
			DIK_9,     			//9
			DIK_0,     			//0
			DIK_Q,				//Q
			DIK_W,				//W
			DIK_E,				//E
			DIK_R,				//R
			DIK_T,				//T
			DIK_Y,				//Y
			DIK_U,				//U
			DIK_I,				//I
			DIK_O,				//O
			DIK_P,				//P
			DIK_A,				//A
			DIK_S,				//S
			DIK_D,				//D
			DIK_F,				//F
			DIK_G,				//G
			DIK_H,				//H
			DIK_J,				//J
			DIK_K,				//K
			DIK_L,				//L
			DIK_Z,				//Z
			DIK_X,				//X
			DIK_C,				//C
			DIK_V,				//V
			DIK_B,				//B
			DIK_N,				//N
			DIK_M,				//M			
			DIK_F1,				//F1
			DIK_F2,				//F2
			DIK_F3,				//F3
			DIK_F4,				//F4
			DIK_F5,				//F5
			DIK_F6,				//F6
			DIK_F7,				//F7
			DIK_F8,				//F8
			DIK_F9,				//F9
			DIK_F10,				//F10		
		};
		memcpy_s(dikCode, sizeof(dikCode), keyList, sizeof(keyList));
		return true;
	}

	void Input::UpDate()
	{
		//�O�̃o�b�t�@��ۑ�
		for (int i = 0; i < 256; ++i)
		{
			prebuf[i] = buf[i];
		}
		HRESULT hr = pKey->GetDeviceState(sizeof(buf), &buf);
		if (FAILED(hr))
		{
			//���s�Ȃ�ĊJ�����Ă�����x�擾
			pKey->Acquire();
			//�o�b�t�@�ɓ��͂�ۑ�
			pKey->GetDeviceState(sizeof(buf), &buf);
		}
	}

	bool Input::Press(const int key)
	{
		//���͂�ۑ�
		unsigned char input = 0x00;	//0x00(�����ĂȂ�)0x80(�����Ă�)
		unsigned char prevInput = 0x00;
		//���͔ԍ��ɂ���ĕς���
		input = buf[dikCode[key]] & 0x80;
		prevInput = prebuf[dikCode[key]] & 0x80;
		//�O�̓��͂�������Ԃ�,���݉�����Ă�����
		return input != 0 && prevInput == 0;
	}

	bool Input::Push(const int key)
	{
	
		unsigned char input = 0x00;
	
		input = this->buf[dikCode[key]] & 0x80;
		//������Ă��邩
		return input != 0;
	}

	bool Input::Free(const int key)
	{
		//���͕ۑ��p
		unsigned char input = 0x00;
		//���͔ԍ��ɂ���ĕς���
		input = this->buf[dikCode[key]] & 0x80;
		//������Ă��Ȃ���
		return input == 0;
	}

	bool Input::Pull(const int key)
	{
		//���͕ۑ��p
		unsigned char input = 0x00;
		unsigned char prevInput = 0x00;
		//���͔ԍ��ɂ���ĕς���
		input = this->buf[dikCode[key]] & 0x80;
		prevInput = this->prebuf[dikCode[key]] & 0x80;
		//�O�̓��͂����茻�݂̓��͂����邩
		return input == 0 && prevInput != 0;
	}
}

