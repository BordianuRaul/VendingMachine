cmake_minimum_required(VERSION 3.21)
project(Lab10)

set(CMAKE_CXX_STANDARD 14)

add_executable(VendingMachine main.cpp Domain/Product.cpp Headers/Product.h Repository/Repository.h Repository/FileRepository.h Service/ProductService.cpp Service/ProductService.h Service/ProductService.h Service/ProductService.cpp Service/ProductService.h Tests/Tests.cpp Tests/Tests.h UserInterface/UserInterface.cpp UserInterface/UserInterface.h Domain/ProductValidator.cpp Headers/ProductValidator.h Domain/NotEnoughMoneyException.cpp Headers/NotEnoughMoneyException.h Domain/InvalidIDException.cpp Headers/InvalidIDException.h Domain/UniqueIDException.cpp Headers/UniqueIDException.h Domain/InvalidPriceException.cpp Headers/InvalidPriceException.h Domain/NegativeIdException.cpp Headers/NegativeIdException.h)
