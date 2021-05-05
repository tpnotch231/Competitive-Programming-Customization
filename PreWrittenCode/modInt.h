template<int64_t _mod> class ModularInteger;
template<int64_t mod> ModularInteger<mod> power(const ModularInteger<mod> &a,const __int128 &b);
template<int64_t mod> ostream& operator<<(ostream &out,const ModularInteger<mod> &a);
template<int64_t mod> istream& operator>>(istream &in,ModularInteger<mod> &a);

template<int64_t _mod>
class ModularInteger{
	__int128 _value;
	friend ModularInteger<_mod> power<_mod>(const ModularInteger<_mod> &a,const __int128 &b);
	friend ostream& operator<< <_mod>(ostream &out,const ModularInteger<_mod> &a);
	friend istream& operator>> <_mod>(istream &in,ModularInteger<_mod> &a);
	public:
	ModularInteger()=default;
	ModularInteger(int)=delete;
	ModularInteger(double)=delete;
	ModularInteger(float)=delete;
	ModularInteger(char)=delete;
	ModularInteger(long double)=delete;
	ModularInteger(const int64_t &a){
		_value=a%_mod;
		_value+=_mod;
		_value%=_mod;
	}
	ModularInteger(const __int128 &a){
		_value=a%_mod;
		_value+=_mod;
		_value%=_mod;
	}

	ModularInteger operator+(const ModularInteger &a){
		return (_value+a._value)%_mod;
	}
	ModularInteger operator-(const ModularInteger &a){
		return (_value-a._value+_mod)%_mod;
	}
	ModularInteger operator*(const ModularInteger &a){
		return (_value*a._value)%_mod;
	}
	ModularInteger operator/(const ModularInteger &a){
		return (_value*power(a,_mod-2)._value)%_mod;
	}

	ModularInteger& operator+=(const ModularInteger &a){
		_value=(_value+a._value)%_mod;
		return (*this);
	}
	ModularInteger& operator-=(const ModularInteger &a){
		_value=(_value-a._value+_mod)%_mod;
		return (*this);
	}
	ModularInteger& operator*=(const ModularInteger &a){
		_value=(_value*a._value)%_mod;
		return (*this);
	}
	ModularInteger& operator/=(const ModularInteger &a){
		_value=(_value*power(a,_mod-2)._value)%_mod;
		return (*this);
	}
	void retrieve(int64_t &c){
		c=_value;
	}

	bool operator==(const ModularInteger &a){
		return _value==a._value;
	}
	ModularInteger operator++(){
		++_value;
		_value%=_mod;
		return _value;
	}
	ModularInteger operator++(int){
		__int128 val=_value;
		++_value;
		_value%=_mod;
		return val;
	}
};
template<int64_t mod>
ostream& operator<<(ostream &out,const ModularInteger<mod> &a){
	return out<<a._value;
}

template<int64_t mod>
istream& operator>>(istream &in,ModularInteger<mod> &a){
	istream &ret=in>>a._value;
	a._value%=mod;
	return ret;
}
template<int64_t mod>
ModularInteger<mod> power(const ModularInteger<mod> &a,const __int128 &b){
	__int128 ans=1,x=a._value;
	for(int i=0;(__int128(1)<<i)<=b;++i){
		ans*=(b&(__int128(1)<<i)?x:__int128(1));
		ans%=mod;
		x*=x;
		x%=mod;
	}
	return ans;
}
