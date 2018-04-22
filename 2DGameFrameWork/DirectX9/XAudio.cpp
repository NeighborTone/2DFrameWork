#include "XAudio.h"

IXAudio2* Audio::pAudio = nullptr;
IXAudio2MasteringVoice* Audio::pMaster = nullptr;
Audio::Audio()
{
	//COMライブラリ初期化
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	XAudio2Create(&pAudio, 0);
	pAudio->CreateMasteringVoice(&pMaster);
	pSource = nullptr;
}

Audio::~Audio()
{
	
	if (pMaster != nullptr)
	{
		pMaster->DestroyVoice();
		pMaster = nullptr;
	}

	if (pAudio != nullptr)
	{
		pAudio->Release();
		pAudio = nullptr;
	}

	//COMの破棄
	CoUninitialize();
}