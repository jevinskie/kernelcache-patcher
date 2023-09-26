add_executable(no-appleserialshim no-appleserialshim.cpp)

target_link_libraries(no-appleserialshim kernelcache-patcher argparse fmt)
target_compile_options(no-appleserialshim PRIVATE -Wall -Wextra -Wpedantic)

install(TARGETS no-appleserialshim
    RUNTIME DESTINATION bin
)
