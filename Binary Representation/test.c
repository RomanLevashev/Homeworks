#include <stdbool.h>

int decimalSumByBinaries(int, int);

bool test(void) {
	if (decimalSumByBinaries(-1, 1) != 0) {
		return false;
	}
	if (decimalSumByBinaries(0, 928) != 928) {
		return false;
	}
	if (decimalSumByBinaries(238, -195) != 43) {
		return false;
	}
	if (decimalSumByBinaries(-1928, -5137) != -7065) {
		return false;
	}
	if (decimalSumByBinaries(123, 456) != 579) {
		return false;
	}
	if (decimalSumByBinaries(789, 321) != 1110) {
		return false;
	}
	if (decimalSumByBinaries(2048, 4096) != 6144) {
		return false;
	}
	if (decimalSumByBinaries(65535, 1) != 65536) {
		return false;
	}
	if (decimalSumByBinaries(0, 0) != 0) {
		return false;
	}
	if (decimalSumByBinaries(100000, 200000) != 300000) {
		return false;
	}
	if (decimalSumByBinaries(32768, 32768) != 65536) {
		return false;
	}
	if (decimalSumByBinaries(99999, 1) != 100000) {
		return false;
	}
	if (decimalSumByBinaries(2147483647, 1) != 2147483648) {
		return false;
	}
	if (decimalSumByBinaries(42, 58) != 100) {
		return false;
	}
	return true;
}
