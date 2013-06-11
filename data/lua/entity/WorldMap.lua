

WorldMap = class();


function WorldMap:__init()

	--create sprites
	self.backgroundSprites = {nil,nil,nil,nil} -- 4 space array
	
	--world coordinates
	self.xpos = 0;
	self.ypos = 0;
	
	x,y,w,h = Camera.getView(camera);
	
	for i=1, 2 do -- #sprites
		self.backgroundSprites[i] = Sprite.create();
		local sprite = self.backgroundSprites[i];
		Sprite.loadTexture(sprite, "data/texture/starfield01.png");
		Sprite.setSize(sprite, w, h);
		Sprite.setPosition(sprite, x, y);
		Sprite.setTextureRect(sprite, 0, 0, w/i, h/i);
    end
	
end

function WorldMap:update_camera()
	x,y,w,h = Camera.getView(camera);
	--Sprite.setSize(sprite, w, h);
	--Sprite.setPosition(sprite, x, y);
	
	--size
	--width and height 
	--of backgroundSprites
end

function WorldMap:move(x,y)
	
	local moveTextRect = Sprite.moveTextureRect;
	local sprites = self.backgroundSprites;
	for i=1, 2 do 
		moveTextRect(sprites[i], x, y);
	end
end

function WorldMap:render()

	local render_sprite = Sprite.render;
	local sprites = self.backgroundSprites;
	for i=1, 2 do -- #sprites
		render_sprite(sprites[i]);
    end
    
    --render nebulas etc currently in screen
end
