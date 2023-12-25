
#include "DllLoader.h"
#include <QObject>

class IGUIRecorderReportGen;
class IGUIRecorderCore;

class InitExtendLibs : public QObject
{
    Q_OBJECT
    public:
        InitExtendLibs();
        ~InitExtendLibs();
        Q_INVOKABLE bool loadReportLib();
        Q_INVOKABLE bool loadRecorderCoreLib();
        DLLloader<IGUIRecorderReportGen*, void>* reportGenLib = nullptr;
        DLLloader<IGUIRecorderCore*, void>*  recorderCoreLib = nullptr; 
};
