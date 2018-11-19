cmake_minimum_required(VERSION 3.6)
project(GildedRose)

add_library(GildedRose gilded_rose.cpp include/GildedRose/gilded_rose.h)
target_compile_features(GildedRose PUBLIC cxx_std_17)
target_include_directories(GildedRose PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
