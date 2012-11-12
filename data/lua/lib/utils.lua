

function new( baseTable)
	--if baseTable is a function call it
	--if it is a table okay

    local new_table = { __index= baseTable }
    setmetatable( new_table, baseTable)

    --todo look if OnCreate exist call it

    return new_table
end
