filetype plugin indent on
set nu
set nocp
set whichwrap=<,>,[,]
packadd termdebug
if !empty(glob(s:truepath."pac.vim"))
	execute 'source ' . s:truepath . "pac.vim"
endif
let g:termdebug_popup = 0
"To set width of termdebug
let g:termdebug_wide = 80
set mouse=a
set wildmenu
set magic
colo industry
hi debugPC term=reverse ctermbg=darkblue guibg=darkblue
