PROJECT(RayTracingInOneWeekend-core)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0 FATAL_ERROR)
cmake_policy(SET CMP0020 NEW)
cmake_policy(SET CMP0016 NEW)

MESSAGE(STATUS "Configuring RayTracingInOneWeekend Source")



# glob sources from core directories
FILE(GLOB RayTracingInOneWeekendSources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  *.cpp
  *.c
)

FILE(GLOB RayTracingInOneWeekendHeaders RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  *.h
)

include_directories(${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_PATH} ${GLM_INCLUDE_DIR})


ADD_DEFINITIONS(${RayTracingInOneWeekendGlobalDefinitions})

INCLUDE_DIRECTORIES(${RayTracingInOneWeekendIncludeDirs})
LINK_DIRECTORIES(${GLFW_LIBRARY} ${GLEW_LIBRARY})

add_executable (RayTracingInOneWeekend
  ${RayTracingInOneWeekendSources}
  ${RayTracingInOneWeekendHeaders}
  )

IF(WIN32)
  TARGET_LINK_LIBRARIES(RayTracingInOneWeekend ${Boost_LIBRARIES} ${CGNS_LIBRARIES} ${VTK_LIBRARIES} ${OPENGL_LIBRARY} ${GLFW3_LIBRARY} ${GLEW_LIBRARY} ${ANT_TWEAK_BAR_LIBRARY} ${OPENCL_LIBRARY})
ELSE(WIN32)
  TARGET_LINK_LIBRARIES(RayTracingInOneWeekend ${Boost_LIBRARIES} ${CGNS_LIBRARIES} ${VTK_LIBRARIES} ${OPENGL_LIBRARY} ${GLFW3_LIBRARY} ${GLEW_LIBRARY} ${ANT_TWEAK_BAR_LIBRARY} ${OPENCL_LIBRARY})
ENDIF(WIN32)

DEFINE_SOURCE_GROUPS_FROM_SUBDIR(RayTracingInOneWeekendSources ${RayTracingInOneWeekendHome} "")
DEFINE_SOURCE_GROUPS_FROM_SUBDIR(RayTracingInOneWeekendHeaders ${RayTracingInOneWeekendHome} "")