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

bool InitExtendLibs::loadReportLib()
{
	reportGenLib = new DLLloader<IGUIRecorderReportGen*, void>("GUIRecorderReportGen.dll");
    return reportGenLib->LoadDLL("CreateIGUIRecorderReportGenInstance");
}

bool InitExtendLibs::loadRecorderCoreLib()
{
    recorderCoreLib = new DLLloader<IGUIRecorderCore*, void>("GUIRecorderCore.dll");
    return recorderCoreLib->LoadDLL("CreateIGUIRecorderCoreInstance");
}
