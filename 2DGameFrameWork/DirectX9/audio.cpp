#include "audio.h"

#define SAFE_DELETE(p)  {delete p; p = nullptr;}

IXAudio2* Audio::pAudio = nullptr;
IXAudio2MasteringVoice* Audio::pMaster = nullptr;
Audio::Audio()
{
	SecureZeroMemory(&wavFmt, sizeof(wavFmt));
}

Audio::~Audio()
{
	Exit();
}

bool Audio::Load()
{
	HRESULT hr;
	//COM�̏�����
	hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if (FAILED(hr))
	{
		MessageBox(NULL, "XAudio2COM�̏������Ɏ��s���܂���", "Error", MB_OK);
		return false;
	}

	/*hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	
	if (FAILED(hr))
	{
		MessageBox(NULL, "XAudio2COM�̏������Ɏ��s���܂���", "Error", MB_OK);
		return false;
	}*/

	//XAudio2�C���^�[�t�F�C�X�̍쐬
	if (!CreateXAudio2())
	{
		return false;
	}

	//�}�X�^�[�{�C�X�̍쐬
	if (!CreateMaster())
	{
		return false;
	}

	//wav�ǂݍ���
	if (!LoadWav("Grass.wav"))
	{
		return false;
	}

	return true;
}

bool Audio::LoadWav(const std::string &path)
{
	//WAV�N���X����ă��[�h
	if (!wav.Load(path))
	{
		return false;
	}
	//�\�[�X�{�C�X�̍쐬
	if (!CreateSorce())
	{
		return false;
	}

	//�ǂݍ��񂾃f�[�^���L���[�ɑ��M
	Submit();

	return true;
}

bool Audio::CreateXAudio2()
{
	UINT wFlag = 0;
#ifndef NDEBUG
	wFlag |= XAUDIO2_DEBUG_ENGINE;
#endif

	HRESULT hr;
	hr = XAudio2Create(&pAudio, wFlag);
	if (FAILED(hr))
	{
		MessageBox(NULL, "XAudio2�C���^�[�t�F�[�X�̎擾�Ɏ��s���܂���", "Error", MB_OK);
	}

	return true;
}

bool Audio::CreateMaster()
{
	HRESULT hr;
	hr = pAudio->CreateMasteringVoice(&pMaster);
	if (FAILED(hr))
	{
		MessageBox(NULL, "�}�X�^�����O���H�C�X�̍쐬�Ɏ��s���܂���", "Error", MB_OK);
	}

	return true;
}

bool Audio::CreateSorce()
{
	HRESULT hr;
	hr = pAudio->CreateSourceVoice(
		&pSource, 
		&wav.GetWaveFmtEx());
	if (FAILED(hr))
	{
		MessageBox(NULL, "�\�[�X�{�C�X�̍쐬�Ɏ��s���܂���", "Error", MB_OK);
		return false;
	}
	return true;
}

bool Audio::Submit()
{
	XAUDIO2_BUFFER buf = { 0 };
	buf.AudioBytes = wav.GetWaveSize();
	buf.pAudioData = wav.GetWaveData();
	buf.Flags = XAUDIO2_END_OF_STREAM;
	buf.LoopCount = XAUDIO2_LOOP_INFINITE;	//�������[�v
	HRESULT hr;
	hr = pSource->SubmitSourceBuffer(&buf);
	if (FAILED(hr))
	{
		MessageBox(NULL, "���y�f�[�^�̑��M�Ɏ��s���܂���", "Error", MB_OK);
		return false;
	}

	return true;
}

void Audio::Exit()
{
	/*������͕ς��Ȃ��悤��*/

	//�\�[�X�{�C�X�̔j��
	if (pSource)
	{
		pSource->Stop(0);
		pSource->DestroyVoice();
		pSource = nullptr;
	}

	//�}�X�^�����O�{�C�X�̔j��
	if (pMaster)
	{
		pMaster->DestroyVoice();
		pMaster = nullptr;
	}

	SAFE_DELETE(pAudio);	//XAudio2�C���^�[�t�F�C�X�̔j��

	CoUninitialize();
}

void Audio::Play()
{
	if (pSource)
	{
		pSource->Start(0);
	}
}

void Audio::Stop()
{
	if (pSource)
	{
		pSource->Stop(0);
	}
}

void Audio::Pause()
{

}

void Audio::SetGain(float gain)
{

}

float Audio::GetGain()const
{
	//��
	return 1.0f;
}

Audio* Audio::GetInst()
{
	static Audio inst;
	return &inst;
}