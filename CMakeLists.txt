cmake_minimum_required(VERSION 3.15)
project(mileStone2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)


add_executable(mileStone2 server_side.cpp server_side.h MySerialServer.cpp MySerialServer.h ClientHandler.cpp ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.cpp Solver.h FileCacheManager.cpp FileCacheManager.h CacheManager.cpp CacheManager.h StringReverser.cpp StringReverser.h Main.cpp Main.h DFS.cpp DFS.h MyClientHandler.cpp MyClientHandler.h State.h State.h Searcheable.h Searcher.h BestFirstSearch.cpp BestFirstSearch.h Matrix.cpp Matrix.h MatrixSolver.cpp MatrixSolver.h PriorityQueue.cpp PriorityQueue.h BFS.cpp BFS.h Astar.cpp Astar.h PriorityQueueAstar.h MyParallelServer.cpp MyParallelServer.h)