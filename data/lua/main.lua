
require("data/lua/lib/utils");
require("data/lua/entity/Entity");
--require("data/lua/entity/Nebula");

config = require("data/lua/config");

testSprite = nil

-- given the current LuaState as parameter
-- function main(Engine interface)

function main()
	print("Main is called");
	
	print(config.scroll_speed);
	
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
	
	local x,y,w,h = Camera.getView(camera);
	local mx,my = Input.getMousePosition(input);

	local xmove = 0;
	local ymove = 0;
	
	local factor = 2; --calc with time and speed
	
	if mx >= x and mx <= x+20 then
		xmove = -factor;
	end
	
	if mx <= w+x and mx >= (w+x-20) then
		xmove = factor;
	end
	
	if my >= y and my <= y+20 then
		ymove = -factor;
	end
	
	if my <= h+y and my >= (h+y-20) then
		ymove = factor;
	end
	

	testSprite:moveTextureRect(xmove, ymove);
	--print(testSprite:getViewport());
	--print(getMousePosition());
end


function draw() -- deliver viewport? x,y,width,height
	testSprite:render();
end
