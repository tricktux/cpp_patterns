
include_directories(${CMAKE_SOURCE_DIR}/inc)

if (GLOG_FOUND)
	include_directories(SYSTEM "${GLOG_INCLUDE_DIRS}")
endif ()

if (RAPIDJSON_INCLUDE_DIRS)
	include_directories(SYSTEM "${RAPIDJSON_INCLUDE_DIRS}")
endif ()

# Show more warnings at compiletime.
if (MSVC)
    # FIXME: put Windows specific options here.
else ()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif ()

# Set ExecutableName.
add_executable(patterns "main.cpp")
add_executable(lesson2 "lesson2_journal.cpp")

if (GLOG_FOUND)
	target_link_libraries(patterns ${GLOG_LIBRARIES})
	target_link_libraries(lesson2 ${GLOG_LIBRARIES})
endif ()

if (APPLE)
	target_link_libraries(patterns "-framework Carbon")
endif ()

# Linux specific.
if (UNIX AND NOT APPLE)
	target_link_libraries(patterns pthread dl)
endif ()
