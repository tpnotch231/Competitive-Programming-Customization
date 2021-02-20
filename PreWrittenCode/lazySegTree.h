//T is the type of the underlying vector element.
//L is the type of the lazy component.
//C is the type of the functor which is used to combine two elements. Eg plus<long long int>,max,etc.
//U is the type of the functor that is used to merge the lazy component with the tree node. Signature T U(const T &t,const L &l)
//LU is the type of the functor that updates the lazy component. Signature L LU(const L &dest,const L &src)
//LL is the type of the functor that propagates the lazy component from the current node to the next left child.
//LR is the type of the functor that propagates the lazy component from the current node to the next right child.
//Both LL and LR have signatures L LL(const L& cur,int l,int r). l and r are values for the current node.
//_id is the identity element under C. eg 0 for plus<long long int>, LLONG_MIN for max,etc.
//_uid is the identity element under U and LU
template<typename T,typename C,typename L,typename U,typename LU,typename LL,typename LR>
class LazySegmentTree{
	vector<T> _tree;
	vector<L> _lazy;
	C _combine;
	U _union;
	LU _lazy_union;
	LL _propagate_left;
	LR _propagate_right;
	const T _id;
	const L _uid;
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
		T t1=_build(l,(l+r)/2,_left(cur,l,(l+r)/2),v),t2=_build((l+r)/2+1,r,_right(cur,l,(l+r)/2),v);
		_tree[cur]=_combine(t1,t2);
		return _tree[cur];
	}
	//Add val lazily to the range [el,er] (in the array used to form the segment tree) to val
	T _range_add(const int &el,const int &er,const int &l,const int &r,const int &cur,const L &val){
		if(el<=l&&r<=er){
			return _union(_tree[cur],_lazy[cur]=_lazy_union(_lazy[cur],val));
		}
		if(er<l||r<el){
			return _union(_tree[cur],_lazy[cur]);
		}
		_lazy[_left(cur,l,(l+r)/2)]=_lazy_union(_lazy[_left(cur,l,(l+r)/2)],_propagate_left(_lazy[cur],l,r));
		_lazy[_right(cur,l,(l+r)/2)]=_lazy_union(_lazy[_right(cur,l,(l+r)/2)],_propagate_right(_lazy[cur],l,r));
		_lazy[cur]=_uid;
		return _tree[cur]=_combine(_range_add(el,er,l,(l+r)/2,_left(cur,l,(l+r)/2),_propagate_left(val,l,r)),_range_add(el,er,(l+r)/2+1,r,_right(cur,l,(l+r)/2),_propagate_right(val,l,r)));
	}
	//Query range [el,er]
	T _query(const int &el,const int &er,const int &l,const int &r,const int &cur){
		if(er<l||r<el){
			return _id;
		}
		if(el<=l&&r<=er){
			return _union(_tree[cur],_lazy[cur]);
		}
		_lazy[_left(cur,l,(l+r)/2)]=_lazy_union(_lazy[_left(cur,l,(l+r)/2)],_propagate_left(_lazy[cur],l,r));
		_lazy[_right(cur,l,(l+r)/2)]=_lazy_union(_lazy[_right(cur,l,(l+r)/2)],_propagate_right(_lazy[cur],l,r));
		_tree[cur]=_union(_tree[cur],_lazy[cur]);
		_lazy[cur]=_uid;
		return _combine(_query(el,er,l,(l+r)/2,_left(cur,l,(l+r)/2)),_query(el,er,(l+r)/2+1,r,_right(cur,l,(l+r)/2)));
	}
	public:
	LazySegmentTree(vector<T> v,const T &id,const L &uid):_id(id),_uid(uid){
		_tree.resize(2*v.size());
		_lazy.resize(2*v.size(),uid);
		_build(0,v.size()-1,0,v);
	}
	void update(const int &l,const int &r,const L &val){
		_range_add(l,r,0,_tree.size()/2-1,0,val);
	}
	T query(const int &l,const int &r){
		return _query(l,r,0,_tree.size()/2-1,0);
	}
};
