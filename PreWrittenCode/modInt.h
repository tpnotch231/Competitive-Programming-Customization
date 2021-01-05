class ModularInteger{
	long long int _value;
	static const long long int _mod;
	friend ModularInteger power(const ModularInteger &a,const long long int &b);
	friend ostream& operator<<(ostream &out,const ModularInteger &a);
	friend istream& operator>>(istream &in,ModularInteger &a);
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
ostream& operator<<(ostream &out,const ModularInteger &a){
	return out<<a._value;
}
istream& operator>>(istream &in,ModularInteger &a){
	istream &ret=in>>a._value;
	a._value%=ModularInteger::_mod;
	return ret;
}
ModularInteger power(const ModularInteger &a,const long long int &b){
	long long int ans=1,x=a._value;
	for(long long int i=0;(1LL<<i)<=b;++i){
		ans*=(b&(1LL<<i)?x:1LL);
		ans%=ModularInteger::_mod;
		x*=x;
		x%=ModularInteger::_mod;
	}
	return ans;
}
