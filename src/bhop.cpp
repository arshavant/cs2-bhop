#include "bhop.h"
#include <stdint.h>
#include <thread>

const uint32_t STANDING = 65665;
const uint32_t CROUCHING = 65667;
const uint32_t PLUSH_JUMP = 65537;
const uint32_t MINUS_JUMP = 256;


void bhop::execute()
{
	 uintptr_t localPlayer = memory::Read<uintptr_t>(moduleBase + offsets::dwLocalPlayerPawn);
	 uint32_t fFlag = memory::Read<uint32_t>(localPlayer + offsets::m_fFlags);

	 if (GetAsyncKeyState(0x20) & 0x8000)
	 {
		  if (fFlag == STANDING || fFlag == CROUCHING)
		  {
				std::this_thread::sleep_for(std::chrono::milliseconds(1));

				memory::Write<uintptr_t>(moduleBase + offsets::jump, PLUSH_JUMP);
		  }
		  else
		  {
				memory::Write<uintptr_t>(moduleBase + offsets::jump, MINUS_JUMP);
		  }
	 }

	 std::this_thread::sleep_for(std::chrono::milliseconds(1));
}