template<int _mod> class ModularInteger;
template<int mod> ModularInteger<mod> power(const ModularInteger<mod> &a,const long long int &b);
template<int mod> ostream& operator<<(ostream &out,const ModularInteger<mod> &a);
template<int mod> istream& operator>>(istream &in,ModularInteger<mod> &a);

template<int _mod>
class ModularInteger{
	long long int _value;
	friend ModularInteger<_mod> power<_mod>(const ModularInteger<_mod> &a,const long long int &b);
	friend ostream& operator<< <_mod>(ostream &out,const ModularInteger<_mod> &a);
	friend istream& operator>> <_mod>(istream &in,ModularInteger<_mod> &a);
	public:
	ModularInteger()=default;
	ModularInteger(int)=delete;
	ModularInteger(double)=delete;
	ModularInteger(float)=delete;
	ModularInteger(char)=delete;
	ModularInteger(long double)=delete;
	ModularInteger(const long long int &a){
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
	void retrieve(long long int &c){
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
		long long int val=_value;
		++_value;
		_value%=_mod;
		return val;
	}
};
template<int mod>
ostream& operator<<(ostream &out,const ModularInteger<mod> &a){
	return out<<a._value;
}

template<int mod>
istream& operator>>(istream &in,ModularInteger<mod> &a){
	istream &ret=in>>a._value;
	a._value%=mod;
	return ret;
}
template<int mod>
ModularInteger<mod> power(const ModularInteger<mod> &a,const long long int &b){
	long long int ans=1,x=a._value;
	for(long long int i=0;(1LL<<i)<=b;++i){
		ans*=(b&(1LL<<i)?x:1LL);
		ans%=mod;
		x*=x;
		x%=mod;
	}
	return ans;
}
