cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMakeProjectRacingSimulatorAndDll")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(GameRule SHARED
"GameRule.h"
"GameRule.cpp"
"Transport.h"
"Transport.cpp"
"Air.h"
"Air.cpp"
"Lend.h"
"Lend.cpp"
"DistancePercent.h"
)

add_executable (CMakeProjectRacingSimulatorAndDll
"CMakeProjectRacingSimulatorAndDll.cpp"
"Print.h"
"Print.cpp"
"InputConsole.h"
"InputConsole.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProjectRacingSimulatorAndDll PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(CMakeProjectRacingSimulatorAndDll PRIVATE GameRule)
