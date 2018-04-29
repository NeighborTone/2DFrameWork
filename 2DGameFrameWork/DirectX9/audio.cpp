#include "audio.h"


SoundSource::SoundSource()
{
	pSource = nullptr;
}

SoundSource::SoundSource(SoundSource& sound)
{
	pSource = sound.pSource;
	wav = sound.wav;
}

SoundSource::~SoundSource()
{
	Destroy();
}

bool SoundSource::Load(const char* path)
{
	if (!wav.Load(path))
	{
		MessageBox(NULL, "ソースボイスの作成に失敗しました", "Error", MB_OK);
		return false;
	}

	return true;
}

void SoundSource::PlayBGM(int loopNum,float gain, float pitch)
{	
	HRESULT hr;
	XAUDIO2_BUFFER buf = { 0 };
	buf.AudioBytes = wav.GetWaveSize();
	buf.pAudioData = wav.GetWaveData();
	buf.Flags = XAUDIO2_END_OF_STREAM;	//このバッファの後にデータがないことをソースボイスに伝える
	buf.LoopCount = loopNum;	//ループ回数を指定。デフォルトで無限ループ
	buf.LoopBegin = 0;
	pSource->SetFrequencyRatio(pitch);	//ピッチ
	pSource->SetVolume(gain);					//ゲイン
	hr = pSource->SubmitSourceBuffer(&buf, nullptr);	//Sourceに音源の情報を送る
	if (FAILED(hr))
	{
		MessageBox(NULL, "音楽データの送信に失敗しました", "Error", MB_OK);
	}

	if (pSource)
	{
		pSource->Start();
	}
}

void SoundSource::PlaySE(float gain, float pitch)
{
	XAUDIO2_BUFFER buf = { 0 };
	buf.AudioBytes = wav.GetWaveSize();
	buf.pAudioData = wav.GetWaveData();
	buf.Flags = XAUDIO2_END_OF_STREAM;
	buf.LoopCount = 0;	//ループ回数を指定。
	buf.LoopBegin = 0;

	pSource->SetFrequencyRatio(pitch);	//ピッチ
	pSource->SetVolume(gain);					//ゲイン
	pSource->Stop(0);							//一旦停止
	pSource->FlushSourceBuffers();			//ボイスキューを削除(再生位置を戻すため)
	pSource->SubmitSourceBuffer(&buf, nullptr);	//Sourceに音源の情報を送る
	
	if (pSource)
	{
		pSource->Start();
	}
}

void SoundSource::Stop()
{
	XAUDIO2_VOICE_STATE xa2state;
	pSource->GetState(&xa2state);
	auto isPlay = xa2state.BuffersQueued;	//再生中なら0以外が返る
	if (pSource && isPlay != 0)
	{
		pSource->Stop();
	}
}

void SoundSource::Destroy()
{
	if (pSource != nullptr)
	{
		pSource->Stop(0);
		pSource->DestroyVoice();
		pSource = nullptr;
	}
}






//static------------------------------------------------
IXAudio2* SoundSystem::pXAudio2 = nullptr;
IXAudio2MasteringVoice* SoundSystem::pMaster = nullptr;
//------------------------------------------------------
SoundSystem::SoundSystem()
{

}

void SoundSystem::DestroySystem(SoundSource& source)
{
	//解放順は
	//Source→Master→XAudio2
	if (source.pSource != nullptr)
	{
		source.pSource->Stop(0);
		source.pSource->DestroyVoice();
		source.pSource = nullptr;
	}
	
	//マスターボイス破棄
	if (pMaster != nullptr)
	{
		pMaster->DestroyVoice();
		pMaster = nullptr;
	}
	//XAudi2破棄
	if (pXAudio2 != nullptr)
	{
		pXAudio2->Release();
		pXAudio2 = nullptr;
	}
	CoUninitialize();
}

SoundSystem::~SoundSystem()
{
	//マスターボイス破棄
	if (pMaster != nullptr)
	{
		pMaster->DestroyVoice();
		pMaster = nullptr;
	}
	//XAudi2破棄
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
	//COMの初期化
	hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if (FAILED(hr))
	{
		MessageBox(NULL, "XAudio2COMの初期化に失敗しました", "Error", MB_OK);
		return false;
	}
	//XAudio2の初期化
	hr = XAudio2Create(&pXAudio2, 0);
	if (FAILED(hr))
	{
		MessageBox(NULL, "XAudio2の初期化に失敗しました", "Error", MB_OK);
		return false;
	}
	//マスターボイスの生成
	hr = pXAudio2->CreateMasteringVoice(
		&pMaster, 
		XAUDIO2_DEFAULT_CHANNELS,
		XAUDIO2_DEFAULT_SAMPLERATE,
		0,
		0,
		NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, "マスターボイスの初期化に失敗しました", "Error", MB_OK);
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
		MessageBox(NULL, "ソースボイスの追加に失敗しました", "Error", MB_OK);
		return false;
	}
	return true;
}