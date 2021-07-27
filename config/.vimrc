filetype plugin indent on
set nu
set nocp
set whichwrap=<,>,[,]
packadd termdebug
let s:truepath="~/Vim-Customization/config/"
if !empty(glob(s:truepath."pac.vim"))
	execute 'source ' . s:truepath . "pac.vim"
endif
if !empty(glob(s:truepath."spaceParse.vim"))
	execute 'source ' . s:truepath . "spaceParse.vim"
endif
let g:termdebug_popup = 0
"To set width of termdebug
let g:termdebug_wide = 80
set mouse=a
set wildmenu
set magic
colo industry
set visualbell
set foldmethod=manual
set cino+=(0
set switchbuf+=useopen
"set laststatus=2
hi statusline ctermbg=white ctermfg=black
hi debugPC term=reverse ctermbg=darkblue guibg=darkblue
