# TODO

## Game Design

* Create UI mockups
	- Ship Menu
	- Main menu
	- Diplomatic Menu
	- Planet usage
	- Research
	
## Game Content

* Write first mission documentation as example

## Game Code

* Clean scripting interface
	- SpriteEntity
	- State
	- UI
* Reimplemented some things in lua code
	- Think about transfering delegate structs via lua for event mapping with complete native execution
	- Reimplement the Nebula Rendering
	- Implement Sprite Interface (Partial DONE)
	- Implement UI Interface
	- Picking API
* Remove unused stuff (IN PROGRESS)
* Memory Management
* Implement Logging
	- Generic Engine Log Source
* SceneGraph API for Lua?
* Create Particle System (Point Sprites)
* Create Decal System
* Thinking over Entity System
	- LogicEntity  
	- LogicEntity2D (contains 2D Information)
	- RenderEntity  (contains 2D Information + Render Interface)
	- Component Based?
* Reimplement the ResourceManager System
	- Texture/Shader Resource Manager
* Thinking about storing Entities and Object 
	- Using an ID system also easier for Lua objects DONE
* Think about workflow
	- When calling lua functions
	- Mapping between entities (scenegraph)
* Release/Debug checks in scripting code for optimization
	

## Textures

* Create a sample planet texture
* Write notices how to create nebula stamps

## Models

* Create a simple ship model

