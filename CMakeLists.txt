set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

project(GObjectIntrospectionTest)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GObjectIntrospection REQUIRED IMPORTED_TARGET gobject-introspection-1.0)

add_executable(find-girepository)
target_sources(find-girepository PRIVATE find-girepository.c)
target_link_libraries(find-girepository PRIVATE PkgConfig::GObjectIntrospection)

add_executable(glib-print)
target_sources(glib-print PRIVATE glib-print.c)
target_link_libraries(glib-print PRIVATE PkgConfig::GObjectIntrospection)
