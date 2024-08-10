#pragma once
#include <optional>
#include "../Core/ProcessManager.hpp"
#include "../Offsets/Offsets.h"
#include "View.hpp"

class CGame
{
private:
	struct
	{
		DWORD64 ServerDLL;
		DWORD64 ClientDLL;
		DWORD64 EntityList;
		DWORD64 Matrix;
		DWORD64 ViewAngle;
		DWORD64 EntityListEntry;
		DWORD64 LocalController;
		DWORD64 LocalPawn;
		DWORD64 ServerPawn;
		DWORD64 GlobalVars;
	}Address;

public:
	CView View;

public:	
	bool InitAddress();

	DWORD64 GetClientDLLAddress();
	DWORD64 GetServerDLLAddress();
	DWORD64 GetEntityListAddress();
	DWORD64 GetMatrixAddress();
	DWORD64 GetViewAngleAddress();
	DWORD64 GetEntityListEntry();
	DWORD64 GetLocalControllerAddress();
	DWORD64 GetLocalPawnAddress();
	DWORD64 GetServerPawnAddress();
	DWORD64 GetGlobalVarsAddress();

	bool UpdateEntityListEntry();
};

inline CGame gGame;