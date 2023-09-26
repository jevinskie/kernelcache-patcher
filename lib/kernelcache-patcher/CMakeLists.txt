set(KCPATCHER_SRC
    CommonInternal.hpp
    MachO.cpp
)

set(KCPATCHER_HDR_STANDALONE
    Common.hpp
)

set(KCPATCHER_HDR)
foreach(HDR ${KCPATCHER_HDR_STANDALONE})
    set(HDR "${CMAKE_CURRENT_SOURCE_DIR}/../../include/kernelcache-patcher/${HDR}")
    list(APPEND KCPATCHER_HDR ${HDR})
endforeach()

foreach(SRC ${KCPATCHER_SRC})
    get_filename_component(HDR_NAME ${SRC} NAME_WLE)
    set(HDR "${CMAKE_CURRENT_SOURCE_DIR}/../../include/kernelcache-patcher/${HDR_NAME}.hpp")
    if(EXISTS ${HDR})
        list(APPEND KCPATCHER_HDR ${HDR})
    endif()
endforeach()

set(KCPATCHER_PUBLIC_LIBS
    range-v3
)

set(KCPATCHER_PRIVATE_LIBS
    fmt
)

# KCPATCHER_HDR added for Xcode project generation
add_library(kernelcache-patcher STATIC ${KCPATCHER_SRC} ${KCPATCHER_HDR})
add_library(kernelcache-patcher-shared SHARED ${KCPATCHER_SRC} ${KCPATCHER_HDR})
set_target_properties(kernelcache-patcher kernelcache-patcher-shared PROPERTIES PUBLIC_HEADER "${KCPATCHER_HDR}")

target_link_libraries(kernelcache-patcher
PUBLIC
    ${KCPATCHER_PUBLIC_LIBS}
PRIVATE
    ${KCPATCHER_PRIVATE_LIBS}
)
target_compile_options(kernelcache-patcher PRIVATE -Wall -Wextra -Wpedantic)

target_include_directories(kernelcache-patcher
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_link_libraries(kernelcache-patcher-shared
PUBLIC
    ${XNUTRACE_PUBLIC_LIBS}
PRIVATE
    ${KCPATCHER_PRIVATE_LIBS}
)
target_compile_options(kernelcache-patcher-shared PRIVATE -Wall -Wextra -Wpedantic)

target_include_directories(kernelcache-patcher-shared
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)


install(TARGETS kernelcache-patcher kernelcache-patcher-shared
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include/kernelcache-patcher
)

# target_compile_options(xnu-trace PRIVATE -Xclang -fdump-record-layouts)