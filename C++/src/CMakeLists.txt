cmake_minimum_required(VERSION 3.6)
project(GildedRose)

add_library(GildedRose
  gilded_rose.cpp include/GildedRose/gilded_rose.h
  normal_item.cpp normal_item.h
  aged_brie_item.cpp aged_brie_item.h
  backstage_passes_item.cpp backstage_passes_item.h
  item.cpp item.h
  )
target_compile_features(GildedRose PUBLIC cxx_std_17)
target_include_directories(GildedRose PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  )
