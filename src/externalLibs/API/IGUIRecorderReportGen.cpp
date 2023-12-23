#include "IGUIRecorderReportGen.h"
#include "GUIRecorderReportGen.h"

IGUIRecorderReportGen* CreateIGUIRecorderReportGenInstance(void)
{
	return new GUIRecorderReportGen();
}
const char* DeleteIGUIRecorderReportInstance()
{
	return "DLL SAY GOODBYE!";
}