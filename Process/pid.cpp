/**
 * @file pid.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2026-01-05
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <iomanip>
#include <iostream>
#include <string>

// clang-format off
#include <windows.h>
#include <tlhelp32.h>
// clang-format on

int main() {
  // Take a snapshot of all processes in the system
  HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

  if (hSnapshot == INVALID_HANDLE_VALUE) {
    std::cerr << "Failed to create snapshot." << std::endl;
    return 1;
  }

  // Prepare the structure to hold process data
  PROCESSENTRY32 pe32;
  pe32.dwSize = sizeof(PROCESSENTRY32);

  std::cout << std::left << std::setw(30) << "Process Name" << " | " << "PID"
            << std::endl;
  std::cout << std::string(45, '-') << std::endl;

  // Retrieve information about the first process
  if (!Process32First(hSnapshot, &pe32)) {
    CloseHandle(hSnapshot);
    return 1;
  }

  // Walk through the snapshot of processes
  do {
    // szExeFile is a WCHAR array in Unicode builds.
    // We can wrap it in a std::wstring directly.
    std::wstring processName(pe32.szExeFile);

    // Use wcout for wide-character strings (Unicode)
    std::wcout << std::left << std::setw(30) << processName << L" | "
               << pe32.th32ProcessID << std::endl;

  } while (Process32Next(hSnapshot, &pe32));

  // Clean up the handle
  CloseHandle(hSnapshot);

  std::cout << "\nScan complete. Press Enter to exit.";
  std::cin.get();
  return 0;
}
