#pragma once

#include "../memory/memory.h"
#include "../sdk/offsets.h"

#include <Windows.h>
#include <cstddef>

namespace bhop
{
	 inline uintptr_t procID;
	 inline uintptr_t moduleBase;

	 void execute();
}