#pragma once
#include <string>

class IGUIRecorderReportGen;

IGUIRecorderReportGen* CreateIGUIRecorderReportGenInstance(void);
const char* DeleteIGUIRecorderReportInstance();

class IGUIRecorderReportGen
{
public:
	IGUIRecorderReportGen() = default;
	virtual ~IGUIRecorderReportGen() = default;

	virtual bool GenerateReportFromOneTest(std::string testPath, std::string outPath) = 0;
	virtual bool GenerateReportFromOneTestBoostrapStyle(std::string testPath, std::string outPath) = 0;
	virtual bool GenerateReportFromTests(std::string testsPath, std::string outPath) = 0;
};