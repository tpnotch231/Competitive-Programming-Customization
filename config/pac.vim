let g:pre_written_code_path="~/Documents/Programming/Contests/Vim-Customization/PreWrittenCode/"
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
	execute '%s/LOG_POWER/ll power(ll a,ll b,ll mod=MOD){\tll ans=1;\tfor(ll i=0;(1LL<<i)<=b;++i){\t\tans*=(b\&(1LL<<i)?a:1LL);\t\tans%=mod;\t\ta*=a;\t\ta%=mod;\t}\treturn ans;}/ge'
	execute '%s/MIN_QUEUE/template <typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;/ge'
	execute '%s/RAN_HASH/seed_seq seq{\t\t(uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),\t\t(uint64_t) __builtin_ia32_rdtsc(),\t\t(uint64_t) (uintptr_t) make_unique<char>().get()\t};\tmt19937 rng(seq);\tconst long long int base = uniform_int_distribution<int>(0, ModularInteger::_mod-1)(rng);/ge'
endfunction
function Snippet(name)
	execute 'r' . g:pre_written_code_path . a:name . '.h'
endfunction
"Template
function N(name)
	execute ':edit ' . a:name . '.cpp'
	call append(0,"#define MOD 1000000007")
	call append(1,"#include <bits/stdc++.h>")
	call append(2,"#include <numeric>")
	call append(3,"#include <ext/pb_ds/assoc_container.hpp>")
	call append(4,"#include <ext/pb_ds/tree_policy.hpp>")
	call append(5,"using namespace __gnu_pbds;")
	call append(6,"using namespace std;")
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
