#!/bin/bash

function Verilate() {
	verilator --cc picorv32.v --Mdir Vpicorv32_axi --trace-fst --top-module picorv32_axi -CFLAGS "-mbmi2"
	pushd Vpicorv32_axi
	make -j -f Vpicorv32_axi.mk
	popd
}

function CompileMain() {
	g++ -L Vpicorv32_axi -I /usr/share/verilator/include -mbmi2 main.cpp -lz -lVpicorv32_axi -lverilated
}

Verilate
CompileMain
