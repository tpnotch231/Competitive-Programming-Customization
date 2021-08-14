"Compile
function Compile()
	if bufwinnr('log')>0
		execute 'sbuffer log'
		execute 'q!'
	endif
	execute 'wa'
	execute '!g++ -g -I ' . g:external_directory_root . ' -std=c++17 % 2>log'
	execute 'vsp'
	execute 'wincmd l'
	execute 'edit log'
	execute 'vertical resize -15'
endfunction
function Run()
	if bufwinnr('log')>0
		execute 'sbuffer log'
		execute 'q!'
	endif
	execute 'Termdebug a.out'
	execute 'vertical resize -15'
endfunction

"Keybindings
nnoremap  :call Compile()<CR>
nnoremap s :call Run()<CR>
