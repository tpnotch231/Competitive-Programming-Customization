"Snippets
function ExpandFor()
	execute '%s/f#\(.\+\)<\([^#\n]\+\)#\(.\+\)/for(int \3=\1; \3<\2; \3++)/ge'
	execute '%s/f#\(.\+\)>\([^#\n]\+\)#\(.\+\)/for(int \3=\1; \3>\2; \3--)/ge'
	execute '%s/f#\(.\+\)<\([^#\n]\+\)/for(int i=\1; i<\2; i++)/ge'
	execute '%s/f#\(.\+\)>\([^#\n]\+\)/for(int i=\1; i>\2; i--)/ge'
	execute '%s/f\(.\+\)#\(.\+\)<\([^#\n]\+\)#\(.\+\)/for(int \4=\2; \4<\3; \4+=\1)/ge'
	execute '%s/f\(.\+\)#\(.\+\)>\([^#\n]\+\)#\(.\+\)/for(int \4=\2; \4>\3; \4-=\1)/ge'
	execute '%s/f\(.\+\)#\(.\+\)<\([^#\n]\+\)/for(int i=\2; i<\3; i+=\1)/ge'
	execute '%s/f\(.\+\)#\(.\+\)>\([^#\n]\+\)/for(int i=\2; i>\3; i-=\1)/ge'
	execute '%s/\([ \n\t(<]\)ll\([ \n\t>,]\)/\1long long int\2/ge'
	execute '%s/\([ \n\t(<]\)ull\([ \n\t>,]\)/\1unsigned long long int\2/ge'
endfunction
"Compile
function Compile()
	execute 'wa'
	execute '!g++ %'
endfunction
function Run()
	execute 'w ./input'
	execute 'silent !./a.out'
endfunction

"Keybindings
nnoremap <expr>  Compile()
nnoremap <expr> K Run()
nnoremap  :call ExpandFor()<CR>
