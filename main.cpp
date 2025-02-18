#include "memory/memory.h"
#include "src/bhop.h"

#include <iostream>
#include <thread>

int main()
{
	 bhop::procID = memory::GetProcID(L"cs2.exe");
	 bhop::moduleBase = memory::GetModuleBaseAddress(bhop::procID, L"client.dll");

	 std::cout << "Process ID: " << bhop::procID << std::endl;
	 std::cout << "Module Base ID: " << "0x" << std::hex << bhop::moduleBase << std::dec << std::endl;

	 while (true)
	 {
		  bhop::execute();

		  std::this_thread::sleep_for(std::chrono::milliseconds(5));
	 }
}