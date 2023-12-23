#include "IGUIRecorderCore.h"
#include "GUIRecorderCore.h"


IGUIRecorderCore* CreateIGUIRecorderCoreInstance(void)
{
	return new GUIRecorderCore();
}
const char* DeleteIGUIRecorderCoreInstance()
{
	return "DLL SAY GOODBYE!";
}