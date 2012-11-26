
# Notice for lua programming



	Object = {}
	
Static function

	function Object.Bar(n)
	--equals
	Object.Bar = function(n)
	
	Object.Bar(5)
	--static call
	
	
Object function

	function Object:Foo(n)
	--equals
	Object.Foo = function(self, n)
	
	Object:Foo(5)
	--equals
	Object.Foo(Object, 5)




