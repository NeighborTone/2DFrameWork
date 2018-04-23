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
	//COMの初期化
	hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if (FAILED(hr))
	{
		MessageBox(NULL, "XAudio2COMの初期化に失敗しました", "Error", MB_OK);
		return false;
	}

	/*hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	
	if (FAILED(hr))
	{
		MessageBox(NULL, "XAudio2COMの初期化に失敗しました", "Error", MB_OK);
		return false;
	}*/

	//XAudio2インターフェイスの作成
	if (!CreateXAudio2())
	{
		return false;
	}

	//マスターボイスの作成
	if (!CreateMaster())
	{
		return false;
	}

	//wav読み込み
	if (!LoadWav("Grass.wav"))
	{
		return false;
	}

	return true;
}

bool Audio::LoadWav(const std::string &path)
{
	//WAVクラスを介してロード
	if (!wav.Load(path))
	{
		return false;
	}
	//ソースボイスの作成
	if (!CreateSorce())
	{
		return false;
	}

	//読み込んだデータをキューに送信
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
		MessageBox(NULL, "XAudio2インターフェースの取得に失敗しました", "Error", MB_OK);
	}

	return true;
}

bool Audio::CreateMaster()
{
	HRESULT hr;
	hr = pAudio->CreateMasteringVoice(&pMaster);
	if (FAILED(hr))
	{
		MessageBox(NULL, "マスタリングヴォイスの作成に失敗しました", "Error", MB_OK);
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
		MessageBox(NULL, "ソースボイスの作成に失敗しました", "Error", MB_OK);
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
	buf.LoopCount = XAUDIO2_LOOP_INFINITE;	//無限ループ
	HRESULT hr;
	hr = pSource->SubmitSourceBuffer(&buf);
	if (FAILED(hr))
	{
		MessageBox(NULL, "音楽データの送信に失敗しました", "Error", MB_OK);
		return false;
	}

	return true;
}

void Audio::Exit()
{
	/*解放順は変えないように*/

	//ソースボイスの破棄
	if (pSource)
	{
		pSource->Stop(0);
		pSource->DestroyVoice();
		pSource = nullptr;
	}

	//マスタリングボイスの破棄
	if (pMaster)
	{
		pMaster->DestroyVoice();
		pMaster = nullptr;
	}

	SAFE_DELETE(pAudio);	//XAudio2インターフェイスの破棄

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
	//仮
	return 1.0f;
}

Audio* Audio::GetInst()
{
	static Audio inst;
	return &inst;
}