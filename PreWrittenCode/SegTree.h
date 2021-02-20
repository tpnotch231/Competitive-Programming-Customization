//T is the type of the underlying vector element.
//C is the type of the functor which is used to combine two elements. Eg plus<ll>,max,etc.
//_id is the identity element under C. eg 0 for plus<ll>, LLONG_MIN for max,etc.
template<typename T,typename C>
class SegmentTree{
	vector<T> _tree;
	C _combine;
	const T _id;
	//The two functions below print the left and right child of the current tree node. Basically the index of
	//a node found by these functions is the index of the node in the preorder traversal of the segtree.
	//Using these functions allows for the tree vector to be of size 2*n rather than 4*n.
	inline int _left(const int &x,const int &l,const int &mid){
		return x+1;
	}
	inline int _right(const int &x,const int &l,const int &mid){
		return x+2*(mid-l+1);
	}
	//For the below functions, [l,r] is the range of elements whose value is stored in index cur.
	T _build(int l,int r,int cur,vector<T> &v){
		if(l==r) return _tree[cur]=v[l];
		return _tree[cur]=_combine(_build(l,(l+r)/2,_left(cur,l,(l+r)/2),v),_build((l+r)/2+1,r,_right(cur,l,(l+r)/2),v));
	}
	//Set value at ind (in the array used to form the segment tree) to val
	T _set(const int &l,const int &r,const int &ind,const int &cur,const T &val){
		if(l==r) return _tree[cur]=val;
		else if(ind>(l+r)/2) return _tree[cur]=_combine(_tree[_left(cur,l,(l+r)/2)],_set((l+r)/2+1,r,ind,_right(cur,l,(l+r)/2),val));
		else return _tree[cur]=_combine(_set(l,(l+r)/2,ind,_left(cur,l,(l+r)/2),val),_tree[_right(cur,l,(l+r)/2)]);
	}
	//Query range [el,er]
	T _query(const int &el,const int &er,const int &l,const int &r,const int &cur){
		if(er<l||r<el) return _id;
		if(el<=l&&r<=er) return _tree[cur];
		return _combine(_query(el,er,l,(l+r)/2,_left(cur,l,(l+r)/2)),_query(el,er,(l+r)/2+1,r,_right(cur,l,(l+r)/2)));
	}
	public:
	SegmentTree(vector<T> v,const T &id):_id(id){
		_tree.resize(2*v.size());
		_build(0,v.size()-1,0,v);
	}
	void change(const int &ind,const T &val){
		_set(0,_tree.size()/2-1,ind,0,val);
	}
	T query(const int &l,const int &r){
		return _query(l,r,0,_tree.size()/2-1,0);
	}
};
