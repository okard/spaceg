


-- creates a new logic entity
Nebula = class(Entity);


-- entity event
function Nebula:__init()

	-- seed as parameter: math.randomseed(1234), math.random()

	--set logic properties
	self.color = '';
	
	-- requires a sprite entity
	-- sprite object not mapped to scene
	self.sprite = Sprite()
	
	-- add sub entity
	self:add(self.sprite)

	-- register entity
	--Engine.Register(self);
end
