//DSU implementing Union by size instead of rank.
//_parent_or_size[i] stores the parent of node i in the standard tree implementation of DSU if it has a parent, and
//the size of the tree rooted at i * -1 otherwise. Memory efficient.
//The size(int) function should be used to retrieve size of a component.
class DSU{
		vector<int> _parent_or_size;
		int _Size;
	public:
		//Constructs DSU with n elements.
		DSU(int n=0):  _parent_or_size(n), _Size(n){
			fill(_parent_or_size.begin(),_parent_or_size.end(),-1);
		}
		
		//Resets the values in the DSU and changes size.
		void clear(unsigned long new_size){
			_parent_or_size.assign(new_size,-1);
			_Size=new_size;
		}
		//Adds a new singleton set at the end (with the new last index).
		void create(){
			++_Size;
			_parent_or_size.push_back(-1);
		}
		//Returns number of sets.
		int size(){
			return _Size;
		}
		//Returns number of nodes in a given set.
		int size(int i){
			return ((i<0||i>=_parent_or_size.size())?-1:-_parent_or_size[Find(i)]);
		}
		//The find operation.
		int Find(int x){
			if(_parent_or_size[x]>=0){
				return _parent_or_size[x]=Find(_parent_or_size[x]);
			}
			else{
				return x;
			}
		}
		//The union operation
		int Union(int x,int y){
			x=Find(x);
			y=Find(y);
			if(_parent_or_size[x]>_parent_or_size[y]){
				_parent_or_size[y]+=_parent_or_size[x];
				--_Size;
				return _parent_or_size[x]=y;
			}
			else if(x!=y){
				_parent_or_size[x]+=_parent_or_size[y];
				--_Size;
				return _parent_or_size[y]=x;
			}
			return -1;
		}
};
