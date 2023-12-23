#pragma once
#include "IScenario.h"

class IPlayer
{
protected:
	IPlayer() = default;

public:
	virtual ~IPlayer() = default;
	virtual bool RunTestFromFile(std::string pathFile) = 0;
	virtual bool RunTestFromFolder(std::string pathFolder) = 0;
};