
require("data/lua/lib/utils");
require("data/lua/entity/Entity");
--require("data/lua/entity/Nebula");

testSprite = nil

-- given the current LuaState as parameter
-- function main(Engine interface)

function main()
	print("Main is called");
	
	local test = Entity();
	
	print(test.x);
	
	testSprite = Sprite(); --Sprite.create()
	testSprite:loadTexture("data/texture/starfield01.png");
	
	print(camera);
	print(input);
	print(Camera.getView(camera));
	x,y,w,h = Camera.getView(camera);
	
	--register camera change function
	
	testSprite:setSize(w, h);
	testSprite:setTextureRect(0,0, w/2, h/2);
	testSprite:setColor(255, 150, 150, 255);

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
	testSprite:moveTextureRect(1, 1);
	--print(testSprite:getViewport());
	--print(getMousePosition());
end


function draw() -- deliver viewport? x,y,width,height
	testSprite:render();
end
