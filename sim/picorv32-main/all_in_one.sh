#!/bin/bash

function Verilate() {
	verilator --cc picorv32.v --Mdir Vpicorv32_axi --trace-fst --top-module picorv32_axi
	pushd picorv32_axi
	make -j -f Vpicorv32_axi.mk
	popd
}

function CompileMain() {
}

Verilate
CompileMain
