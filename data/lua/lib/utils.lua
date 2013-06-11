-----------------------------------------------------------------
-- function for creating classes
function class( baseClass )
    -- basic
    local new_class = {}
    local new_class_mt = {};
    
    --setup metatable
    if baseClass then
        new_class_mt.__index = baseClass;
    end
    setmetatable( new_class, new_class_mt)
    
    -- set up ctor
    local class_mt = { __index = new_class}
    new_class_mt.__call = function(c, ...)
        local newinst = {}
        setmetatable( newinst, class_mt )
        
        --TODO chaining ctor
        -- call ctor
        if newinst.__init then
            newinst:__init(...);
        end
        return newinst
    end
    
    -- Return the class object of the instance
    function new_class:class()
        return new_class
    end
    -- Return the super class object of the instance
    function new_class:super()
        return baseClass
    end
    
    return new_class
end


-- protect function
function protect(table) 
	local mt = 
	{ 
		__index = table, 
		__newindex = function(table, key, value) 
					 error("attempted to modify a read only table")
				     end, 
		__metatable = false 
	};
	setmetatable(table, mt) 
end


-- create_closure function
