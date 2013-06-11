
require("data/lua/lib/utils");
require("data/lua/entity/Entity");
--require("data/lua/entity/Nebula");
--require("data/lua/entity/WorldMap");

config = require("data/lua/config");

testSprite = nil
testSprite2 = nil

-- game storage add all global stuff to global table named 'game'
local game = {};

-- given the current LuaState as parameter
-- function main(Engine interface)

function main()
	print("Main is called");
	
	for k,v in pairs(config) do print(k,v) end
	
	--local test = Entity();
	--print(test.x);
	
	testSprite = Sprite.create();
	Sprite.loadTexture(testSprite, "data/texture/starfield01.png");
	--testSprite2 = Sprite();
	--testSprite2:loadTexture("data/texture/starfield01.png");
	
	print(Camera.getView(camera));
	x,y,w,h = Camera.getView(camera);
	
	--register camera change function
	
	Sprite.setSize(testSprite, w, h);
	--testSprite:setTextureRect(0,0, w/2, h/2);
	Sprite.setTextureRect(testSprite, 0, 0, w/2, h/2);
	--testSprite:setColor(255, 50, 50, 255);
	
	--testSprite2:setSize(w, h);
	--testSprite2:setTextureRect(0,0, w, h);

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
	
	--global table is protected after main?
	--protect(_G);
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
	
	local limit = 50;
	local factor = 2; --calc with time and speed
	
	if mx >= x and mx <= x+limit then
		xmove = -factor;
	end
	
	if mx <= w+x and mx >= (w+x-limit) then
		xmove = factor;
	end
	
	if my >= y and my <= y+limit then
		ymove = -factor;
	end
	
	if my <= h+y and my >= (h+y-limit) then
		ymove = factor;
	end
	

	Sprite.moveTextureRect(testSprite, xmove, ymove);
	--testSprite2:moveTextureRect(xmove, ymove);
	
	--moves also view?
	--Camera.move(camera, xmove, ymove);
	
	--print(testSprite:getViewport());
	--print(getMousePosition());
end


function draw() -- deliver viewport? x,y,width,height
	--testSprite:render();
	Sprite.render(testSprite);
	--testSprite2:render();
end
