filetype plugin indent on
set nu
set nocp
set whichwrap=<,>,[,]
packadd termdebug
let s:truepath="~/Competitive-Programming-Customization/Vim/Scripts/"
let g:pre_written_code_path="~/Competitive-Programming-Customization/PreWrittenCode/"  "Used in template.vim in ExpandLargeSnippet()
let g:external_directory_root="~/Competitive-Programming-Customization/External" "Should not have / at the end, currently used in expander.vim and possibly some future testing library
if !empty(glob(s:truepath."template.vim"))
	execute 'source ' . s:truepath . "template.vim"
endif
if !empty(glob(s:truepath."compile.vim"))
	execute 'source ' . s:truepath . "compile.vim"
endif
if !empty(glob(s:truepath."expander.vim"))
	execute 'source ' . s:truepath . "expander.vim"
endif
if !empty(glob(s:truepath."spaceParse.vim"))
	execute 'source ' . s:truepath . "/spaceParse.vim"
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
