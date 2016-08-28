IF(NOT CommonconfProcessed)

CMAKE_POLICY(SET CMP0005 NEW)
CMAKE_POLICY(SET CMP0011 NEW)

SET(RayTracingInOneWeekendHome ${CMAKE_CURRENT_SOURCE_DIR})
SET(RayTracingInOneWeekendBinaryDir ${CMAKE_BINARY_DIR})

MESSAGE(STATUS "RayTracingInOneWeekend Source Directory: ${RayTracingInOneWeekendHome}")
MESSAGE(STATUS "RayTracingInOneWeekend Binary Directory: ${RayTracingInOneWeekendBinaryDir}")

# include macros
INCLUDE(${RayTracingInOneWeekendHome}/cmake/macros.cmake)

# set binary output path
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# common include directories
LIST(APPEND RayTracingInOneWeekendIncludeDirs ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}) 

LIST(APPEND RayTracingInOneWeekendGlobalDefinitions "-DMOBIRFIDVIS_SOURCE_DIR=\"${RayTracingInOneWeekendHome}\"")

# platform-dependent configuration
IF(WIN32)
    LIST(APPEND RayTracingInOneWeekendGlobalDefinitions "-DNOMINMAX" "-D_CRT_SECURE_NO_DEPRECATE")

    # Disable warnings for Microsoft compiler:
    # C4290: C++ exception specification ignored except to indicate a function is
    #        not __declspec(nothrow)
    # C4390: ';' : empty controlled statement found; is this the intent?
    #        occurs when OpenGL error logging macros are disabled
    # C4503: The decorated name was longer than the compiler limit (4096), and was truncated.
    #        Occurs in AutoEvaluatePipeline due to some nested nested map-iterator-map. Could
    #        not be deactivated locally...
    LIST(APPEND RayTracingInOneWeekendGlobalDefinitions /wd4290 /wd4390 /wd4503)

    # prevent error: number of sections exceeded object file format limit
    LIST(APPEND RayTracingInOneWeekendGlobalDefinitions /bigobj)
    
    # allows 32 Bit builds to use more than 2GB RAM (VC++ only)
    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /LARGEADDRESSAWARE")
    SET(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS} /LARGEADDRESSAWARE")
    
    LIST(APPEND RayTracingInOneWeekend_GlobalExternalLibs netapi32 version)
ENDIF(WIN32)

ADD_DEFINITIONS(/WX)

IF(CMAKE_COMPILER_IS_GNUCXX)
    # enable C++11 support in GCC
    LIST(APPEND CMAKE_CXX_FLAGS "-std=c++11")
ENDIF()

IF(STREAM_SURFACE_GENERATOR)

    # GL Math
    FIND_PACKAGE(GLM REQUIRED)
    INCLUDE_DIRECTORIES(${GLM_INCLUDE_DIR})

ENDIF(STREAM_SURFACE_GENERATOR)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${RayTracingInOneWeekendHome}/cmake")

SET(CommonconfProcessed TRUE)

ENDIF(NOT CommonconfProcessed)