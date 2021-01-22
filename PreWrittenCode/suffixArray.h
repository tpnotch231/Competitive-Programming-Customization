//Suffix array to work with strings that have lower case characters.
struct SuffixArray{
	private:
	bool _sa_made;
	public:
	SuffixArray():_sa_made(false){}
	vector<int> sa,lcp;
	void buildSA(string s){
		s.push_back('$');
		_sa_made=true;
		int c{0};
		vector<int> aux(256),co(s.size()),e(s.size());
		sa.resize(s.size());
		iota(sa.begin(),sa.end(),0);
		aux[0]=1;
		for(int i=0; i<s.size()-1; ++i) ++aux[s[i]];
		for(int i=1; i<aux.size(); ++i) aux[i]+=aux[i-1];
		for(int i=s.size()-2; i>=0; --i) sa[--aux[s[i]]]=i;
		sa[0]=s.size()-1;
		for(int i=1; i<s.size(); ++i){
			if(s[sa[i]]!=s[sa[i-1]]) ++c;
			e[sa[i]]=c;
		}
		aux.resize(n);
		for(int j=0;(1<<j)<s.size();++j){
			fill(aux.begin(),aux.end(),0);
			c=0;
			for(int i=0; i<sa.size(); ++i){
				sa[i]=(sa[i]-(1<<j)+s.size())%s.size();
				++aux[e[sa[i]]];
			}
			for(int i=1; i<aux.size(); ++i) aux[i]+=aux[i-1];
			for(int i=sa.size()-1; i>=0; --i) co[--aux[e[sa[i]]]]=sa[i];
			sa=co;
			co[sa[0]]=0;
			for(int i=1; i<sa.size(); ++i){
				if(e[sa[i]]!=e[sa[i-1]]||e[(sa[i]+(1<<j))%s.size()]!=e[(sa[i-1]+(1<<j))%s.size()]) ++c;
				co[sa[i]]=c;
			}
			e=co;
		}
	}
	void buildLCP(string s){
		if(!_sa_made) return;
		s.push_back('$');
		vector<int> ia(sa.size());
		lcp.resize(sa.size());
		for(int i=0; i<sa.size(); ++i){
			ia[sa[i]]=i;
		}
		int l{0};
		for(int i=0; i<s.size()-1; ++i){
			int k=ia[i],j=sa[k-1];
			while(i+l<s.size()-1&&j+l<s.size()-1&&s[i+l]==s[j+l]) ++l;
			lcp[k]=l;
			if(l>0) --l;
		}
	}
};
