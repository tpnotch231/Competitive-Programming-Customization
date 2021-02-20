python3 << parser

import vim,pyparsing as pp

qualifier = pp.Literal("long") | pp.Literal("short") | pp.Literal("signed") | pp.Literal("unsigned") | pp.Literal("const")

baseType=pp.Forward()
baseType <<= pp.Literal("int") | pp.Literal("char") | pp.Literal("int64_t") | pp.Literal("string") | pp.Literal("float") | pp.Literal("double") | pp.Literal("bool") | pp.Literal("void") | qualifier + baseType | pp.Word(pp.alphanums+"_")

template = pp.Literal("vector") | pp.Literal("stack") | pp.Literal("queue") | pp.Literal("deque") | pp.Literal("pair") | pp.Literal("tuple") | pp.Literal("array") | pp.Literal("set") | pp.Literal("map") | pp.Word(pp.alphanums+"_")

fullType = pp.Forward()
args = pp.Forward()
arg = pp.Forward()

arg <<= pp.Word(pp.nums) | fullType | pp.Empty()

args <<= arg + "," + args | arg

fullType <<= template + "<" + args + ">" | baseType

def prettify(sname):
	ans=""
	ls=fullType.parseString(sname)
	for i in ls:
		ans=ans + i + " "
	ans=ans[:-1]
	return ans
parser

function CallParseWrapper(sname)
	let lis = split(execute ('py3 print(prettify("' . a:sname . '"),end="")'),"\n")
	return lis[0]
endfunction
