#!/bin/bash

function Verilate() {
	verilator --cc picorv32.v --Mdir Vpicorv32_axi --trace-fst --top-module picorv32_axi -CFLAGS "-mbmi2" \
		-pvalue+ENABLE_IRQ=1 -pvalue+ENABLE_DIV=1 -pvalue+ENABLE_TRACE=1 -pvalue+ENABLE_MUL=1 -pvalue+COMPRESSED_ISA=1
	pushd Vpicorv32_axi
	make -j -f Vpicorv32_axi.mk
	popd
}

function CompileMain() {
	g++ -g -Og -L Vpicorv32_axi -I /usr/share/verilator/include -mbmi2 main.cpp -lz -lVpicorv32_axi -lverilated
}

Verilate
CompileMain
