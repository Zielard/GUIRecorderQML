#include "../include/InitExtendLibs.h"
#include "../include/DllLoader.h"
#include "../externalLibs/API/IGUIRecorderCore.h"
#include "../externalLibs/API/IGUIRecorderReportGen.h"

InitExtendLibs::InitExtendLibs()
{

}
InitExtendLibs::~InitExtendLibs()
{

}

void InitExtendLibs::loadReportLib()
{
	reportGenLib = new DLLloader<IGUIRecorderReportGen*, void>("GUIRecorderReportGen.dll");
	loadedGen = reportGenLib->LoadDLL("CreateIGUIRecorderReportGenInstance");
}

void InitExtendLibs::loadRecorderCoreLib()
{
    recorderCoreLib = new DLLloader<IGUIRecorderCore*, void>("GUIRecorderCore.dll");
	loadedRep = recorderCoreLib->LoadDLL("CreateIGUIRecorderCoreInstance");
}