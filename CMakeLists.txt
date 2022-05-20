cmake_minimum_required(VERSION 3.23.1)


project(TicTacToe)


add_executable(${PROJECT_NAME} "")


target_sources(${PROJECT_NAME} PRIVATE tictactoe.c ttt.h)




