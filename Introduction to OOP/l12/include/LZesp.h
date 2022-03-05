#pragma once
#include <string>
#include <cstring>
#include <iostream>

class LZesp{

	private:

	int re;
	int im;

	public:

	static LZesp i;
	static int IMAGINARY;
	static int REAL;

	LZesp(int realum);
	LZesp(int realum, int imaginum);
	
	LZesp operator+(const LZesp &lzesp) const{
		return LZesp(this->getRe() + lzesp.getRe(),this->getIm() + lzesp.getIm());
	}

	LZesp operator-(const LZesp &lzesp) const{
		return LZesp(this->getRe() - lzesp.getRe(),this->getIm() - lzesp.getIm());
	}


	LZesp operator*(const LZesp &lzesp) const {
		return LZesp(this->getRe()*lzesp.getRe() - this->getIm()*lzesp.getIm(), this->getRe() * lzesp.getIm() + this->getIm() * lzesp.getRe());
	}

	LZesp operator*=(int num) {
		this->setRe(this->getRe() * num);
		this->setIm(this->getIm() * num);
		return *this;
	}

	LZesp operator++() {
		this->setRe(this->getRe() + 1);
		return *this;
	}

	LZesp operator++(int x) {
		this->setRe(this->getRe() + 1);
		return LZesp(this->re -1,this->im);
	}

	bool operator>(const LZesp &lzesp) const{
		return this->re * this->re + this->im * this->im > lzesp.re *lzesp.re + lzesp.im * lzesp.im ? true : false;
	}

	int& operator[](unsigned index) {
		if (index)
			return this->im;
		else 
			return this->re;
	}	

	int getRe() const{
		return this->re;
	}

	int getIm() const{
		return this->im;
	}

	void setRe(int x) {
		this->re = x;
	}	
	
	void setIm(int x) {
		this->im = x;
	}	

	friend LZesp operator-(const int x,const LZesp &lzesp);
	friend std::ostream& operator<<(std::ostream&, const LZesp&);
	friend LZesp operator+(const int x,const LZesp &lzesp);
};



