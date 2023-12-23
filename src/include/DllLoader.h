#pragma once
template<typename R, typename A>
class DLLloader
{
public:
	using fun_t = R(*) (A);
	fun_t pfCreate = NULL;

	HINSTANCE dllHandle = NULL;
	std::string dllName = NULL;
	DLLloader(std::string dllname_) : dllName(dllname_)
	{};

	bool LoadDLL(std::string fNameC)
	{
		bool retVal = false;

		const char* ptrFnc_Cname = fNameC.c_str();

		PCSTR pszModuleName = dllName.c_str();

		if (GetModuleHandleA(pszModuleName) == NULL)
		{
			dllHandle = LoadLibraryA(pszModuleName);
			if ((dllHandle != NULL) && (GetModuleHandleA(pszModuleName) != NULL))
			{
				pfCreate = (fun_t)GetProcAddress(dllHandle, ptrFnc_Cname);
				if ((pfCreate != NULL))
				{
					retVal = true;
				}
			}
		}
		return retVal;
	}

	bool UnLoadDll()
	{
		this->dllHandle = NULL;
		PCSTR pszModuleName = this->dllName.c_str();

		// Return true if library freeing succeseded, otherwise false
		return FreeLibrary(GetModuleHandleA(pszModuleName)) != 0;
	}
};
