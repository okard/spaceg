
require("data/lua/lib/utils");

require("data/lua/Player");
require("data/lua/entity/Entity");
require("data/lua/entity/Nebula");
require("data/lua/entity/WorldMap");

config = require("data/lua/config");


-- game storage add all global stuff to global table named 'game'
local game = {};

-- given the current LuaState as parameter
-- function main(Engine interface)

function main()
	--print out configuration
	print("Configuration: ");
	for k,v in pairs(config) do print(k,v) end
	
	game.player = Player();
	game.world = WorldMap();
	
	print(Camera.getView(camera));
	x,y,w,h = Camera.getView(camera);
	
	main_menu = UI.create();
	UI.loadDocument(main_menu, "data/ui/main_menu.rml");
	UI.addCallback(main_menu, "click", function() UI.hide(main_menu); end);
	UI.enableDebugger(main_menu, false);
	
	--register camera change function

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
	protect(_G);
end

function exit()
	print("exit called");
	UI.delete(main_menu);
end


function update(t) --deliver time is ms
	--print(t)
	
	if Input.isPressedMBR(input) then
		UI.show(main_menu);
	end
	
	--react on event?
	-- open menu etc
	
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
	
	game.world:move(xmove, ymove);
	--moves also view?
	--Camera.move(camera, xmove, ymove);
end


function draw() -- deliver viewport? x,y,width,height
	game.world:render();
end
