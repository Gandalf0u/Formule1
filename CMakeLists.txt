cmake_minimum_required(VERSION 3.15)
project(formul111)

set (CMAKE_CXX_FLAGS "-static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic")

add_executable(formul111 main.cpp Piste.cpp Piste.h Voiture.cpp Voiture.h)
