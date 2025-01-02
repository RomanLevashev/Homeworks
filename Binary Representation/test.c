#include <stdbool.h>

int decimalSumByBinaries(int, int, bool);

bool runTests(void) {
	if (decimalSumByBinaries(-1, 1, true) != 0) {
		return false;
	}
	if (decimalSumByBinaries(0, 928, true) != 928) {
		return false;
	}
	if (decimalSumByBinaries(238, -195, true) != 43) {
		return false;
	}
	if (decimalSumByBinaries(-1928, -5137, true) != -7065) {
		return false;
	}
	if (decimalSumByBinaries(123, 456, true) != 579) {
		return false;
	}
	if (decimalSumByBinaries(789, 321, true) != 1110) {
		return false;
	}
	if (decimalSumByBinaries(2048, 4096, true) != 6144) {
		return false;
	}
	if (decimalSumByBinaries(65535, 1, true) != 65536) {
		return false;
	}
	if (decimalSumByBinaries(0, 0, true) != 0) {
		return false;
	}
	if (decimalSumByBinaries(100000, 200000, true) != 300000) {
		return false;
	}
	if (decimalSumByBinaries(32768, 32768, true) != 65536) {
		return false;
	}
	if (decimalSumByBinaries(99999, 1, true) != 100000) {
		return false;
	}
	if (decimalSumByBinaries(2147483647, 1, true) != 2147483648) {
		return false;
	}
	if (decimalSumByBinaries(42, 58, true) != 100) {
		return false;
	}
	return true;
}
