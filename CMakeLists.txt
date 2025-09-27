cmake_minimum_required(VERSION 4.0)
project(Servicio_Tecnico)

set(CMAKE_CXX_STANDARD 20)

add_executable(Servicio_Tecnico main.cpp
        pila_estatica.h
        cola_estatica.h
        lista_estatica.h
        tipo.h)
