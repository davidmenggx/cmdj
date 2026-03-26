cmake_minimum_required (VERSION 3.20)

if (POLICY CMP0141)
	cmake_policy(SET CMP0141 NEW)
	set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("cmdj")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(ftxui CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS 
    "src/*.cpp"
)

file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS 
    "include/*.h"
)

add_executable(cmdj ${SOURCES} ${HEADERS})

target_include_directories(cmdj PRIVATE include/cmdj)

target_link_libraries(cmdj PRIVATE 
    ftxui::screen 
    ftxui::dom 
    ftxui::component
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET cmdj PROPERTY CXX_STANDARD 20)
endif()
