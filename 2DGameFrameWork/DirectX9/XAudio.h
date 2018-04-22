#pragma once
#include <XAudio2.h>
#include "wav.h"

class Audio
{
private:
	static IXAudio2* pAudio;
	static IXAudio2MasteringVoice* pMaster;
	IXAudio2SourceVoice* pSource;

public:
	Audio();
	~Audio();
};