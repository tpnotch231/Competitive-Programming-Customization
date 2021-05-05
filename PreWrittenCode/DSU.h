//DSU implementing Union by size instead of rank.
//_parent[i] stores the parent of node i in the standard tree implementation of DSU.
//_size[i] stores the size of the component that was at some point rooted at i. Because of Find operations many
//values in this array quickly become meaningless. The size(int) function should be used to retrieve size of a
//component.
class DSU{
		vector<int> _parent,_size;
		int _Size;
	public:
		//Constructs DSU with n elements.
		DSU(int n=0):  _parent(n), _size(n,1), _Size(n){
			iota(_parent.begin(),_parent.end(),0);
		}
		
		//Resets the values in the DSU and changes size.
		void clear(unsigned long new_size){
			_size.assign(new_size,1);
			_parent.resize(new_size);
			iota(_parent.begin(),_parent.end(),0);
			_Size=new_size;
		}
		//Adds a new singleton set at the end (with the new last index).
		void create(){
			++_Size;
			_size.push_back(1);
			_parent.push_back(_parent.size());
		}
		//Returns number of sets.
		int size(){
			return _Size;
		}
		//Returns number of nodes in a given set.
		int size(int i){
			return ((i<0||i>=_size.size())?-1:_size[Find(i)]);
		}
		//The find operation.
		int Find(int x){
			if(x!=_parent[x]){
				_parent[x]=Find(_parent[x]);
			}
			return _parent[x];
		}
		//The union operation
		int Union(int x,int y){
			x=Find(x);
			y=Find(y);
			if(_size[x]<_size[y]){
				_parent[x]=y;
				_size[y]+=_size[x];
				--_Size;
				return y;
			}
			else if(x!=y){
				_parent[y]=x;
				_size[x]+=_size[y];
				--_Size;
				return x;
			}
			return -1;
		}
};
