static func print(p_value):
	GlobalScope.print("shadowed static print:", p_value)

func test():
	var print = "shadowed local print"
	var TYPE_BOOL = -1
	var PI = -1.0

	GlobalScope.print("global print")
	GlobalScope.print(print)
	GlobalScope.print(GlobalScope.TYPE_BOOL != TYPE_BOOL)
	GlobalScope.print(GlobalScope.PI > PI)
