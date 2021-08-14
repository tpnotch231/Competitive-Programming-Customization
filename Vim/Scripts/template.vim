let g:pre_written_code_path="~/Vim-Customization/PreWrittenCode/"

"Base Template
function N(name)
	execute ':edit ' . a:name . '.cpp'
	call append(0,'#pragma GCC target("popcnt")')
	call append(1,"#include <bits/stdc++.h>")
	call append(2,"#include <numeric>")
	call append(3,"#include <ext/pb_ds/assoc_container.hpp>")
	call append(4,"#include <ext/pb_ds/tree_policy.hpp>")
	call append(5,"using namespace __gnu_pbds;")
	call append(6,"using namespace std;")
	call append(7,"const int64_t MOD = 1000000007;")
	call append("$","int main(){")
	call append("$","\tios_base::sync_with_stdio(false);")
	call append("$","\tcin.tie(NULL);")
	execute ':normal Go'
	call append("$","}")
endfunction

"Snippets
"Handles the most
function ExpandForLoops()
	"Somehow make this incomprehensible mess more readable and maintainable
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
endfunction

"This expands any short hands for tokens, including types and constants
function ExpandTokens()
	while search('[ ,\n\t(<=+-\*/]ll[ ,\n\t>(]')!=0
		execute '%s/\([ ,\n\t(<=+-\*/]\)ll\([ ,\n\t>(]\)/\1int64_t\2/ge'
	endwhile
	
	while search('[ ,\n\t(<=+-\*/]ull[ ,\n\t>(]')!=0
		execute '%s/\([ ,\n\t(<=+-\*/]\)ull\([ ,\n\t>(]\)/\1uint64_t\2/ge'
	endwhile

	while search('V\s*<[^@]*>')!=0
		execute '%s/V\s*<\([^@]*\)>/vector<\1>/ge'
	endwhile

	execute '%s/n_l<\(.\+\)>/numeric_limits<\1>/ge'
	execute '%s/s_c<\(.\+\)>/static_cast<\1>/ge'
endfunction

"Here on out, a snippet refers to a logical unit of a program, such as a function, class, template declaration, etc
function ExpandSmallSnippets()
	execute '%s/ORDERED_SET/template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;/ge'
"To type ^M pres Ctrl-V then Enter in Linux, and Ctrl-O then Enter in Windows.
"^M in the replace section becomes a new line character.
	execute '%s/LOG_POWER/ll power(ll a,ll b,ll mod=MOD){\tll ans=1;\tfor(ll i=0;(1LL<<i)<=b;++i){\t\tans*=(b\&(1LL<<i)?a:1LL);\t\tans%=mod;\t\ta*=a;\t\ta%=mod;\t}\treturn ans;}/ge'
	execute '%s/MIN_QUEUE/template <typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;/ge'
	execute '%s/INT_ROOT/ll intRoot(ll x){\tll l{0},r{x};\twhile(l<r){\t\tll mid=(l+r+1)\/2;\t\tif(x\/mid>=mid){\t\t\tl=mid;\t\t}\t\telse{\t\t\tr=mid-1;\t\t}\t}\treturn l;}/ge'
endfunction

"Used to expand components that are not well defined in terms of concepts defined above, and do not warrant a
"function of their own.
function ExpandMisc()
	execute '%s/W(\(.\+\))/int \1;\r\tcin>>\1;\r\tfor(int T_Case=1;T_Case<=\1;++T_Case)/ge'

	execute '%s/RAN_HASH/seed_seq seq{\t\t(uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),\t\t(uint64_t) __builtin_ia32_rdtsc(),\t\t(uint64_t) (uintptr_t) make_unique<char>().get()\t};\tmt19937 rng(seq);\tconst long long int base = uniform_int_distribution<long long int>(1, MOD-1)(rng),input_limit;\tvector<ModularInteger<MOD>> powers(input_limit+1,1LL);\tfor(int i=1;i<powers.size();++i){\t\tpowers[i]=powers[i-1]*base;\t}/ge'
endfunction

"Expand is the function that handles everything except large snippets
function Expand()
	"Close the log file if it exists
	if bufwinnr('log')>0
		execute 'sbuffer log'
		execute 'q!'
	endif

	call ExpandForLoops()
	
	call ExpandTokens()
	
	call ExpandSmallSnippets()

	call ExpandMisc()

	call FormatCode() "From spaceParse.vim
endfunction

"Not included in the Expand function as it behaves differently
function ExpandLargeSnippet(name)
	execute 'r' . g:pre_written_code_path . a:name . '.h'
endfunction

"Keybindings
nnoremap  :call Expand()<CR>
