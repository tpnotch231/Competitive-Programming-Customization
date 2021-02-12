class DSU{
		vector<int> _rank,_parent,_size;
		int _Size;
	public:
		DSU(int n): _rank(n,0), _parent(n), _size(n,1), _Size(n){
			iota(_parent.begin(),_parent.end(),0);
		}
		int size(){
			return _Size;
		}
		int size(int i){
			return ((i<0||i>=_size.size())?-1:_size[Find(i)]);
		}
		int Find(int x){
			if(x!=_parent[x]){
				_parent[x]=Find(_parent[x]);
			}
			return _parent[x];
		}
		int Union(int x,int y){
			x=Find(x);
			y=Find(y);
			if(_rank[x]<_rank[y]){
				_parent[x]=y;
				_size[y]+=_size[x];
				--_Size;
				return y;
			}
			else if(_rank[x]>_rank[y]){
				_parent[y]=x;
				_size[x]+=_size[y];
				--_Size;
				return x;
			}
			else if(x!=y){
				_parent[y]=x;
				_size[x]+=_size[y];
				--_Size;
				++_rank[x];
				return x;
			}
			return -1;
		}
};
