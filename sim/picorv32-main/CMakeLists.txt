cmake_minimum_required (VERSION 3.16)

project(picorv32)

find_package(verilator)

add_library(picorv32_axi)

verilate(
    picorv32_axi
    SOURCES picorv32.v
    TOP_MODULE picorv32_axi
    OUTPUT_DIRECTORY picorv32_axi
    TRACE_FST
)

