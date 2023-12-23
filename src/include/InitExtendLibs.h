
#include "DllLoader.h"

class IGUIRecorderReportGen;
class IGUIRecorderCore;

class InitExtendLibs
{
    public:
        InitExtendLibs();
        ~InitExtendLibs();
        void loadReportLib();
        void loadRecorderCoreLib();
        DLLloader<IGUIRecorderReportGen*, void>* reportGenLib = nullptr;
        DLLloader<IGUIRecorderCore*, void>*  recorderCoreLib = nullptr; 

        bool loadedGen = false;
        bool loadedRep = false;
};