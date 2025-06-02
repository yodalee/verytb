#pragma once
// Direct include
#include "Vpicorv32_axi/Vpicorv32_axi.h"
// C system headers
// C++ standard library headers
#include <memory>
// Other libraries' .h files.
// Your project's .h files.

using namespace std;

struct Vpicorv32Wrap {
	unique_ptr<Vpicorv32_axi> dut;
	Vpicorv32Wrap():
		dut(new Vpicorv32_axi)
	{
		dut->resetn = 1;
		PosNeg();
		PosNeg();
		dut->resetn = 0;
		PosNeg();
		PosNeg();
		dut->resetn = 1;
		PosNeg();
		PosNeg();

	}

	void PosNeg() {
		dut->clk = 0;
		dut->eval();
		dut->clk = 1;
		dut->eval();
	}

	void Pre() {
	}

	void Post() {
		dut->clk = 0;
		dut->eval();
		dut->clk = 1;
		dut->eval();
	}
};

struct AxiMemory {
	AxiMemory() {
	}
	void Main() {
	}
};

int main() {
	Vpicorv32Wrap dut;
	AxiMemory axi;
	return 0;
}
