#pragma once
#include "IScenario.h"

class IRecorder
{
protected:
	IRecorder() = default;

public:
	virtual ~IRecorder() = default;
	virtual void StartRecord(void) = 0;
	virtual IScenario* GetlastScenario(void) = 0;
};