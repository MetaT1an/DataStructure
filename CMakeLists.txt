cmake_minimum_required(VERSION 3.13)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

# list
set(SRC_LIST List/main.c List/list.c)
add_executable(list_test ${SRC_LIST})

# linklist
set(SRC_LINKLIST Linklist/main.c Linklist/linklist.c)
add_executable(linklist_test ${SRC_LINKLIST})

# Stack
set(SRC_STACK Stack/main.c Stack/stack.c)
add_executable(stack_test ${SRC_STACK})

# Maze
set(SRC_MAZE Stack/maze/main.c Stack/maze/grids.c Stack/maze/cell.c Stack/maze/cellStack.c)
add_executable(maze ${SRC_MAZE})