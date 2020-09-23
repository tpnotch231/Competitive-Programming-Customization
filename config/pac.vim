"Snippets
function ExpandFor()
	execute '%s/f#\(.\+\)<\([^#\n]\+\)#\(.\+\){/for(int \3=\1; \3<\2; ++\3){/ge'
	execute '%s/f#\(.\+\)>\([^#\n]\+\)#\(.\+\){/for(int \3=\1; \3>\2; --\3){/ge'
	execute '%s/f#\(.\+\)<\([^#\n]\+\){/for(int i=\1; i<\2; ++i){/ge'
	execute '%s/f#\(.\+\)>\([^#\n]\+\){/for(int i=\1; i>\2; --i){/ge'
	execute '%s/f\(.\+\)#\(.\+\)<\([^#\n]\+\)#\(.\+\){/for(int \4=\2; \4<\3; \4+=\1){/ge'
	execute '%s/f\(.\+\)#\(.\+\)>\([^#\n]\+\)#\(.\+\){/for(int \4=\2; \4>\3; \4-=\1){/ge'
	execute '%s/f\(.\+\)#\(.\+\)<\([^#\n]\+\){/for(int i=\2; i<\3; i+=\1){/ge'
	execute '%s/f\(.\+\)#\(.\+\)>\([^#\n]\+\){/for(int i=\2; i>\3; i-=\1){/ge'
	execute '%s/f#\(.\+\)<\([^#\n]\+\)#\(.\+\)/for(int \3=\1; \3<\2; ++\3)/ge'
	execute '%s/f#\(.\+\)>\([^#\n]\+\)#\(.\+\)/for(int \3=\1; \3>\2; --\3)/ge'
	execute '%s/f#\(.\+\)<\([^#\n]\+\)/for(int i=\1; i<\2; ++i)/ge'
	execute '%s/f#\(.\+\)>\([^#\n]\+\)/for(int i=\1; i>\2; --i)/ge'
	execute '%s/f\(.\+\)#\(.\+\)<\([^#\n]\+\)#\(.\+\)/for(int \4=\2; \4<\3; \4+=\1)/ge'
	execute '%s/f\(.\+\)#\(.\+\)>\([^#\n]\+\)#\(.\+\)/for(int \4=\2; \4>\3; \4-=\1)/ge'
	execute '%s/f\(.\+\)#\(.\+\)<\([^#\n]\+\)/for(int i=\2; i<\3; i+=\1)/ge'
	execute '%s/f\(.\+\)#\(.\+\)>\([^#\n]\+\)/for(int i=\2; i>\3; i-=\1)/ge'
	execute '%s/\([ ,\n\t(<]\)ll\([ ,\n\t>]\)/\1long long int\2/ge'
	execute '%s/\([ ,\n\t(<]\)ull\([ ,\n\t>]\)/\1unsigned long long int\2/ge'
	execute '%s/n_l<\(.\+\)>/numeric_limits<\1>/ge'
	execute '%s/s_c<\(.\+\)>/static_cast<\1>/ge'
	execute '%s/W(\(.\+\))/int \1;\r\tcin>>\1;\r\tfor(int T_Case=1;T_Case<=\1;++T_Case)/ge'
endfunction
function Functions()
	execute '%s/ORDERED_SET/template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;/ge'
"To type ^M pres Ctrl-V then Enter in Linux, and Ctrl-O then Enter in Windows.
"^M in the replace section becomes a new line character.
	execute '%s/LOG_POWER/ll power(ll a,ll b,ll mod){\tll ans=1;\tfor(ll i=0;(1LL<<i)<=b;++i){\t\tans*=(b\&(1LL<<i)?a:1LL);\t\tans%=mod;\t\ta*=a;\t\ta%=mod;\t}\treturn ans;}/ge'
	execute '%s/DS_UNION/class DSU{\t\tvector<int> _rank,_parent,_size;\t\tint _Size;\tpublic:\t\tDSU(int n): _rank(n,0), _parent(n), _size(n,1), _Size(n){\t\t\tiota(_parent.begin(),_parent.end(),0);\t\t}\t\tint size(){\t\t\treturn _Size;\t\t}\t\tint size(int i){\t\t\treturn ((i<0||i>=_size.size())?-1:_size[i]);\t\t}\t\tint Find(int x){\t\t\tif(x!=_parent[x]){\t\t\t\t_parent[x]=Find(_parent[x]);\t\t\t}\t\t\treturn _parent[x];\t\t}\t\tint Union(int x,int y){\t\t\tx=Find(x);\t\t\ty=Find(y);\t\t\tif(_rank[x]<_rank[y]){\t\t\t\t_parent[x]=y;\t\t\t\t_size[y]+=_size[x];\t\t\t\t--_Size;\t\t\t\treturn y;\t\t\t}\t\t\telse if(_rank[x]>_rank[y]){\t\t\t\t_parent[y]=x;\t\t\t\t_size[x]+=_size[y];\t\t\t\t--_Size;\t\t\t\treturn x;\t\t\t}\t\t\telse if(x!=y){\t\t\t\t_parent[y]=x;\t\t\t\t_size[x]+=_size[y];\t\t\t\t--_Size;\t\t\t\t++_rank[x];\t\t\t\treturn x;\t\t\t}\t\t\treturn -1;\t\t}};/ge'
endfunction
"Template
function N(name)
	execute ':edit ' . a:name . '.cpp'
	call append(0,"#define MOD 1000000007")
	call append(1,"#include <bits/stdc++.h>")
	call append(2,"#include <numeric>")
	call append(3,"#include <ext/pb_ds/assoc_container.hpp>")
	call append(4,"using namespace __gnu_pbds;")
	call append(5,"using namespace std;")
	call append("$","int main(){")
	call append("$","\tios_base::sync_with_stdio(false);")
	call append("$","\tcin.tie(NULL);")
	execute ':normal Go'
	call append("$","}")
endfunction
"Compile
function Compile()
	execute 'wa'
	execute '!g++ -g -std=c++17 %'
endfunction
function Run()
	execute 'Termdebug a.out'
	execute 'vertical resize -15'
endfunction

"Keybindings
nnoremap <expr>  Compile()
nnoremap <expr> s Run()
nnoremap  :call ExpandFor()<CR>
nnoremap <C-@> :call Functions()<CR>
