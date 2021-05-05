python3 << parser

import vim,pyparsing as pp

qualifier = pp.Literal("long") | pp.Literal("short") | pp.Literal("signed") | pp.Literal("unsigned") | pp.Literal("const")

baseType=pp.Forward()
baseType <<= pp.Literal("int64_t") | pp.Literal("char") | pp.Literal("int") | pp.Literal("string") | pp.Literal("float") | pp.Literal("double") | pp.Literal("bool") | pp.Literal("void") | qualifier + baseType | pp.Word(pp.alphanums+"_")

template = pp.Literal("vector") | pp.Literal("stack") | pp.Literal("queue") | pp.Literal("deque") | pp.Literal("pair") | pp.Literal("tuple") | pp.Literal("array") | pp.Literal("set") | pp.Literal("map") | pp.Literal("bitset") | pp.Literal("multiset") | pp.Literal("multimap") | pp.Literal("unordered_set") | pp.Literal("ordered_set") | pp.Literal("unordered_map") | pp.Literal("min_queue") | pp.Literal("numeric_limits") | pp.Literal("static_cast") | pp.Literal("ModularInteger") | pp.Literal("power") | pp.Literal("greater") | pp.Literal("priority_queue") | pp.Literal("make_unique") | pp.Literal("uniform_int_distribution") | pp.Literal("get") | pp.Literal("complex") | pp.Literal("list")

fullType = pp.Forward()
args = pp.Forward()
arg = pp.Forward()

arg <<= pp.Word(pp.nums) | fullType | pp.Empty()

args <<= arg ^ (arg + "," + args)

fullType <<= template + "<" + args + ">" | baseType

def prettify(sname):
	if len(sname)>7 and sname[0:8]=="template":
	       	return sname
	ans=""
	ls=args.parseString(sname)
	for i in ls:
		ans=ans + i + " "
	ans=ans[:-1]
	return ans
parser

function CallParseWrapper(sname)
	let lis = split(execute ('py3 print(prettify("' . a:sname . '"),end="")'),"\n")
	return lis[0]
endfunction
