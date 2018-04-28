#include "audio.h"


SoundSource::SoundSource()
{
	pSource = nullptr;
}
SoundSource::~SoundSource()
{
	if (pSource != nullptr)
	{
		pSource->DestroyVoice();
		pSource = nullptr;
	}
}
bool SoundSource::Load(const char* path)
{
	if (!wav.Load(path))
	{
		MessageBox(NULL, "�\�[�X�{�C�X�̍쐬�Ɏ��s���܂���", "Error", MB_OK);
		return false;
	}

	return true;
}

bool SoundSource::Submit()
{
		XAUDIO2_BUFFER buf = { 0 };
		buf.AudioBytes = wav.GetWaveSize();
		buf.pAudioData = wav.GetWaveData();
		buf.Flags = XAUDIO2_END_OF_STREAM;
		buf.LoopCount = XAUDIO2_LOOP_INFINITE;	//�������[�v
		HRESULT hr;
		hr = pSource->SubmitSourceBuffer(&buf);	//Source�ɉ����̏��𑗂�
		if (FAILED(hr))
		{
			MessageBox(NULL, "���y�f�[�^�̑��M�Ɏ��s���܂���", "Error", MB_OK);
			return false;
		}
	
		return true;
}

void SoundSource::Play()
{

	Submit();
	if (pSource)
	{
		pSource->Start();
	}
}

void SoundSource::Stop()
{
	if (pSource)
	{
		pSource->Stop();
	}
}




IXAudio2* SoundSystem::pXAudio2 = nullptr;
IXAudio2MasteringVoice* SoundSystem::pMaster = nullptr;
SoundSystem::SoundSystem()
{

}

void SoundSystem::DeleteSystem(SoundSource& source)
{
	//�������
	//Source��Master��XAudio2
	if (source.pSource != nullptr)
	{
		source.pSource->Stop(0);
		source.pSource->DestroyVoice();
		source.pSource = nullptr;
	}
	
	//�}�X�^�[�{�C�X�j��
	if (pMaster != nullptr)
	{
		pMaster->DestroyVoice();
		pMaster = nullptr;
	}
	//XAudi2�j��
	if (pXAudio2 != nullptr)
	{
		pXAudio2->Release();
		pXAudio2 = nullptr;
	}
	CoUninitialize();
}
SoundSystem::~SoundSystem()
{
	//�}�X�^�[�{�C�X�j��
	if (pMaster != nullptr)
	{
		pMaster->DestroyVoice();
		pMaster = nullptr;
	}
	//XAudi2�j��
	if (pXAudio2 != nullptr)
	{
		pXAudio2->Release();
		pXAudio2 = nullptr;
	}
	CoUninitialize();
}

SoundSystem* SoundSystem::GetSystem()
{
	static SoundSystem inst;
	return &inst;
}

bool SoundSystem::Create()
{
	HRESULT hr;
	//COM�̏�����
	hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if (FAILED(hr))
	{
		MessageBox(NULL, "XAudio2COM�̏������Ɏ��s���܂���", "Error", MB_OK);
		return false;
	}
	//XAudio2�̏�����
	hr = XAudio2Create(&pXAudio2, 0);
	if (FAILED(hr))
	{
		MessageBox(NULL, "XAudio2�̏������Ɏ��s���܂���", "Error", MB_OK);
		return false;
	}
	//�}�X�^�[�{�C�X�̐���
	hr = pXAudio2->CreateMasteringVoice(
		&pMaster, 
		XAUDIO2_DEFAULT_CHANNELS,
		XAUDIO2_DEFAULT_SAMPLERATE,
		0,
		0,
		NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, "�}�X�^�[�{�C�X�̏������Ɏ��s���܂���", "Error", MB_OK);
		return false;
	}

	return true;
}

bool SoundSystem::AddSource(SoundSource& source)
{
	HRESULT hr;
	hr = pXAudio2->CreateSourceVoice(
		&source.pSource,
		&source.wav.GetWaveFmtEx());
	if (FAILED(hr))
	{
		MessageBox(NULL, "�\�[�X�{�C�X�̒ǉ��Ɏ��s���܂���", "Error", MB_OK);
		return false;
	}
	return true;
}