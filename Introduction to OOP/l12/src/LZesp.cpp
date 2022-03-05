#include "LZesp.h"
#include <iostream>

LZesp LZesp::i = LZesp(0,1);
int LZesp::IMAGINARY = 1;
int LZesp::REAL = 0;

LZesp::LZesp(int realum) {
	this->re = realum;
	this->im = 0;
}

LZesp::LZesp(int realum, int imaginum) {
	this->re = realum;
	this->im = imaginum;
}

std::ostream& operator<<(std::ostream& strm, const LZesp &lzesp) {
	strm << lzesp.getRe() << " + " << lzesp.getIm() <<"i";	
	return strm;
}

LZesp operator+(const int x,const LZesp &lzesp) {
	return LZesp(x + lzesp.getRe(),lzesp.getIm());
}

LZesp operator-(const int x,const LZesp &lzesp) {
	return LZesp(x-lzesp.getRe(),-lzesp.getIm());
}

