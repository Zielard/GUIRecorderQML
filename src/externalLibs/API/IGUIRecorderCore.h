#pragma once


#include "IPlayer.h"
#include "IRecorder.h"

class IGUIRecorderCore;

IGUIRecorderCore* CreateIGUIRecorderCoreInstance(void);
const char* DeleteIGUIRecorderCoreInstance();

class IGUIRecorderCore
{
public:
	IGUIRecorderCore() = default;
	virtual ~IGUIRecorderCore() = default;

	virtual IPlayer* GetIPlayerInstance() = 0;
	virtual IRecorder* GetIRecorderInstance() = 0;
};