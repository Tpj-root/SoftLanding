cmake_minimum_required(VERSION 3.25.1)

# Set the project name
project(MyProject C)

# Specify the source file
set(SOURCE_FILES main.c)

# Add an executable target
add_executable(softlanding ${SOURCE_FILES})

# Specify installation rules
install(TARGETS softlanding DESTINATION bin)
