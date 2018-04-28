#pragma once
#include <XAudio2.h>
#include "wav.h"

class SoundSource
{
private:

	bool Submit();
public:
	SoundSource();
	~SoundSource();
	bool Load(const char* path);
	void Play();
	void Stop();
	//�\�[�X���H�C�X(�����ɉ������i�[�����
	IXAudio2SourceVoice* pSource;
	//wav�f�[�^
	WAV					  wav;
	IXAudio2SourceVoice* GetSource() { return pSource; }
	WAV GetWav() { return wav; }
};

class SoundSystem
{
private:
		//�C���^�[�t�F�[�X
		static IXAudio2* pXAudio2;
		//�}�X�^�[���H�C�X
		static IXAudio2MasteringVoice* pMaster;

		SoundSystem();
		
public:
	~SoundSystem();
	
	static SoundSystem* GetSystem();
	bool Create();
	bool AddSource(SoundSource& source);
	void DeleteSystem(SoundSource& source);
};

