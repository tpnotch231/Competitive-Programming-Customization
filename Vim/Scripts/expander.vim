" Modified version of the expander.py file found in ACL (https://github.com/atcoder/ac-library) to work as a
" vimscript function
" Ensure that the location of the root directory 'atcoder' is stored in the environment variable CPLUS_INCLUDE_PATH
" Only works with #include "atcoder/.." not #include <atcoder/..>

"TODO: Introduce logging capabilities?
"TODO: Add CWD to possible locations of atcoder/?

let s:already_included={}

function IncludeHeader(header_name,acl_directory_root)
	if !has_key(s:already_included,a:header_name) 
		try
			execute 'r ' . a:acl_directory_root . '/' . a:header_name
			let s:already_included[a:header_name]=1
		catch /^Vim\%((\a\+)\)\=:E484:/
			throw "File not found: " . a:header_name
		endtry
	endif
	return ""
endfunction

function ExpandACLFile()
	let acl_directory_root=g:external_directory_root . "/atcoder" "Global defined in .vimrc, this variable should not have a / at the end
	
	"Regexes
	let atcoder_include='#include\s*"atcoder\/\([a-z_]*\)\(\|\.hpp\)"\s*'
	let atcoder_header_guard='#.*ATCODER_[A-Z_]*_HPP.*\n'
	let pragma_once='\s*#pragma\s*once\s*'
	let comment='^\s*\/\/.*\n'

	while search(atcoder_include)!=0
		try
			execute '%s:' . atcoder_include . ':\=IncludeHeader(submatch(1).submatch(2),"' . acl_directory_root . '"):'
		catch
			echo v:exception
			return
		endtry
	endwhile
	
	"Remove header guards
	execute '%s/' . atcoder_header_guard . '//'
	
	"Remove #pragma once
	execute '%s/' . pragma_once . '//e'

	"Remove all comments
	execute '%s/' . comment . '//'

	"Add attribution
	call append(line('^'),'//Everything in namespace atcoder along with a few includes outside it are taken from Atcoder Library (Github link: https://github.com/atcoder/ac-library)')
	let s:already_included={}
endfunction

nnoremap <C-N> :call ExpandACLFile()<CR>
