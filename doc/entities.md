# Entities

## Meta entities

* Player
	- Name
	- Race
	- Storage (store global equips)
	- Ships
	- Crews (each ship require a crew)
	- Resources
		- Money
		- Materials
			- Steel
			- Silicon
			- Deuterium

## Crew

* Name
* Bonus
* Skills
	- Tech		(faster)
	- Military 	(weapon bonuses)
	- Transport (more weight, more space)
* Abbilities
* Updates
* Experience

## Ship

* Class
	- Ranger - Small fast ships for scouting
	- Cargo - Bigger ships for transport missions
	- Cruiser - Big ships with a lot of weapons
* Speed
* Integrity (HP) Current/Max
* Integrity Regeneration Rate
* Shields Current/Max
* Shield Regeneration Rate
* Energy (For Weapons and Abilities)
* Energy Regenration Rate
* Equipment
	* Weapons
	* Support
* Level
* Sensory Range
* Currently Effects
	- e.g. (shield generate +10 for 60 seconds)
* Maximum weight
* Storage Space - for materials (Max Weight - Equipment)
* Crew
* Gear

(A ship has 2 settings each with 4 active and 2 passive equips, first active equip is marked as autofire)

## Equipment (Modules)

* Weight (in tons)
* Energy Balance
* Category
* Active/Passive
* Requirements
* IsAvailable
	
### Weapon Modules
* Class (also bullet?)
	- Phaser
	- Beam
	- Ion Cannon
* Bullet
* Energy Cost
* Material/Resource 
* Cooldown
* Level

#### Bullet
* Time to Life
* Range
* Type (Mechanical/Energy/\[Wave\])
* Damage
* Target
* Current Position


### Support Modules

* Reactor - Generate Energy (positive energy balance)
* Shieldgenerator - Regenerate Shields
* Cloaking device - Hide Ship
* Multishieldgenerator - effects ships near by
* Nanobots - Regenerate Integrity
* FactoryModule - Produce projectiles fir projectile weapons
* Material Collector - Collect Materials

### Gear Modules
* Jet
* Impulse
* Warp

## Researchs

* Enable Equipment
* Enable Updates
* General Bonuses

## Space Stations

* Docks
* Factory
	- Produce Equipment with materials
	- Upgrade Equipment with materials
	- Produce Ships
	- Upgrade Ships
* Shops
	- Equipment
	- Ships
	- Materials
	
## Planets

* Docks (Menu)
* Factory (Menu)
* Shops (Menu)
* Resources (Draw)

## Nebulas

* Position
* Type
* Resources
* Entry (can be accessed)
* Map (map for inner nebula)

## Portals

* Position
* Target
* Map

Connect different maps or provide shortcuts on map
