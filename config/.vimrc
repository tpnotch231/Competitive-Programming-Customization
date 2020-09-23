filetype plugin indent on
set nu
set nocp
set whichwrap=<,>,[,]
packadd termdebug
let truepath=
if !empty(glob(truepath . "pac.vim"))
	source truepath . "pac.vim"
endif
let g:termdebug_popup = 0
"To set width of termdebug
let g:termdebug_wide = 80
set mouse=a
set wildmenu
set magic
colo industry
hi debugPC term=reverse ctermbg=darkblue guibg=darkblue
