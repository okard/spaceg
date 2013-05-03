
require("data/lua/lib/utils");
require("data/lua/entity/Entity");
--require("data/lua/entity/Nebula");

testSprite = nil

-- given the current LuaState as parameter
-- function main(Engine interface)

function main()
	print("Main is called");
	
	local test = new(Entity);
	
	print(test.x);
	
	testSprite = Sprite();
	--testSprite:loadTexture(

	-- local w = World()
	-- w.load(world1.world)
	-- Engine.add(w)
	
	-- local s = Ship()
	-- Engine.add(s)
	
	-- So c++ world class can create entities based on entity names
	-- Engine.registerEntity("name", luaTable);
	
	
	-- PostProcessing
	
	-- Gui Element
	-- Mouse Keyboard Input

end

function init()

end

function destroy()

end

function onkeypressed()
	--get entity at x/y
end


function update(t) --deliver time is ms
	--print(t)
end


function draw() -- deliver viewport? x,y,width,height

end
