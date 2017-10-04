
#include "Cryptbot.h"
#include "sc2api/sc2_api.h"
#include "sc2lib/sc2_lib.h"
#include "Strategys.h"

struct IsAttackable {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::ZERG_OVERLORD: return false;
		case UNIT_TYPEID::ZERG_OVERSEER: return false;
		case UNIT_TYPEID::PROTOSS_OBSERVER: return false;
		default: return true;
		}
	}
};
struct IsBuilding {
	bool operator()(const sc2::Unit & unit)
	{
		switch (unit.unit_type.ToType())
		{
		case sc2::UNIT_TYPEID::TERRAN_ARMORY:           return true;
		case sc2::UNIT_TYPEID::PROTOSS_ASSIMILATOR:     return true;
		case sc2::UNIT_TYPEID::ZERG_BANELINGNEST:       return true;
		case sc2::UNIT_TYPEID::TERRAN_BARRACKS:         return true;
		case sc2::UNIT_TYPEID::TERRAN_BARRACKSREACTOR:  return true;
		case sc2::UNIT_TYPEID::TERRAN_BARRACKSTECHLAB:  return true;
		case sc2::UNIT_TYPEID::TERRAN_BUNKER:           return true;
		case sc2::UNIT_TYPEID::TERRAN_COMMANDCENTER:    return true;
		case sc2::UNIT_TYPEID::PROTOSS_CYBERNETICSCORE: return true;
		case sc2::UNIT_TYPEID::PROTOSS_DARKSHRINE:      return true;
		case sc2::UNIT_TYPEID::TERRAN_ENGINEERINGBAY:   return true;
		case sc2::UNIT_TYPEID::ZERG_EVOLUTIONCHAMBER:   return true;
		case sc2::UNIT_TYPEID::ZERG_EXTRACTOR:          return true;
		case sc2::UNIT_TYPEID::TERRAN_FACTORY:          return true;
		case sc2::UNIT_TYPEID::TERRAN_FACTORYREACTOR:   return true;
		case sc2::UNIT_TYPEID::TERRAN_FACTORYTECHLAB:   return true;
		case sc2::UNIT_TYPEID::PROTOSS_FLEETBEACON:     return true;
		case sc2::UNIT_TYPEID::PROTOSS_FORGE:           return true;
		case sc2::UNIT_TYPEID::TERRAN_FUSIONCORE:       return true;
		case sc2::UNIT_TYPEID::PROTOSS_GATEWAY:         return true;
		case sc2::UNIT_TYPEID::PROTOSS_WARPGATE:        return true;
		case sc2::UNIT_TYPEID::TERRAN_GHOSTACADEMY:     return true;
		case sc2::UNIT_TYPEID::ZERG_HATCHERY:           return true;
		case sc2::UNIT_TYPEID::ZERG_HYDRALISKDEN:       return true;
		case sc2::UNIT_TYPEID::ZERG_INFESTATIONPIT:     return true;
		case sc2::UNIT_TYPEID::TERRAN_MISSILETURRET:    return true;
		case sc2::UNIT_TYPEID::PROTOSS_NEXUS:           return true;
		case sc2::UNIT_TYPEID::ZERG_NYDUSCANAL:         return true;
		case sc2::UNIT_TYPEID::ZERG_NYDUSNETWORK:       return true;
		case sc2::UNIT_TYPEID::PROTOSS_PHOTONCANNON:    return true;
		case sc2::UNIT_TYPEID::PROTOSS_PYLON:           return true;
		case sc2::UNIT_TYPEID::TERRAN_REFINERY:         return true;
		case sc2::UNIT_TYPEID::ZERG_ROACHWARREN:        return true;
		case sc2::UNIT_TYPEID::PROTOSS_ROBOTICSBAY:     return true;
		case sc2::UNIT_TYPEID::PROTOSS_ROBOTICSFACILITY: return true;
		case sc2::UNIT_TYPEID::TERRAN_SENSORTOWER:      return true;
		case sc2::UNIT_TYPEID::ZERG_SPAWNINGPOOL:       return true;
		case sc2::UNIT_TYPEID::ZERG_SPINECRAWLER:       return true;
		case sc2::UNIT_TYPEID::ZERG_SPIRE:              return true;
		case sc2::UNIT_TYPEID::ZERG_SPORECRAWLER:       return true;
		case sc2::UNIT_TYPEID::PROTOSS_STARGATE:        return true;
		case sc2::UNIT_TYPEID::TERRAN_STARPORT:         return true;
		case sc2::UNIT_TYPEID::TERRAN_STARPORTREACTOR:  return true;
		case sc2::UNIT_TYPEID::TERRAN_STARPORTTECHLAB:  return true;
		case sc2::UNIT_TYPEID::TERRAN_SUPPLYDEPOT:      return true;
		case sc2::UNIT_TYPEID::PROTOSS_TEMPLARARCHIVE:  return true;
		case sc2::UNIT_TYPEID::PROTOSS_TWILIGHTCOUNCIL: return true;
		case sc2::UNIT_TYPEID::ZERG_ULTRALISKCAVERN:    return true;
		case sc2::UNIT_TYPEID::ZERG_HIVE:               return true;
		case sc2::UNIT_TYPEID::ZERG_LAIR:               return true;
		case sc2::UNIT_TYPEID::ZERG_GREATERSPIRE:       return true;
		case sc2::UNIT_TYPEID::TERRAN_ORBITALCOMMAND:   return true;
		case sc2::UNIT_TYPEID::TERRAN_PLANETARYFORTRESS: return true;

		default: return false;
		}
	}
};
struct IsArmy {
	bool operator()(const sc2::Unit & unit)
	{
		switch (unit.unit_type.ToType())
		{
        case UNIT_TYPEID::TERRAN_BANSHEE: return true;
		case UNIT_TYPEID::TERRAN_BATTLECRUISER: return true;
		case UNIT_TYPEID::TERRAN_CYCLONE: return true;
		case UNIT_TYPEID::TERRAN_GHOST: return true;
		case UNIT_TYPEID::TERRAN_HELLION: return true;
		case UNIT_TYPEID::TERRAN_HELLIONTANK: return true;
		case UNIT_TYPEID::TERRAN_LIBERATOR: return true;
		case UNIT_TYPEID::TERRAN_LIBERATORAG: return true;
		case UNIT_TYPEID::TERRAN_MARAUDER: return true;
		case UNIT_TYPEID::TERRAN_MARINE: return true;
		case UNIT_TYPEID::TERRAN_MEDIVAC: return true;
		case UNIT_TYPEID::TERRAN_MULE: return true;
		case UNIT_TYPEID::TERRAN_RAVEN: return true;
		case UNIT_TYPEID::TERRAN_REAPER: return true;
		case UNIT_TYPEID::TERRAN_SCV: return true;
		case UNIT_TYPEID::TERRAN_SIEGETANK: return true;
		case UNIT_TYPEID::TERRAN_SIEGETANKSIEGED: return true;
		case UNIT_TYPEID::TERRAN_THOR: return true;
		case UNIT_TYPEID::TERRAN_THORAP: return true;
		case UNIT_TYPEID::TERRAN_VIKINGASSAULT: return true;
		case UNIT_TYPEID::TERRAN_VIKINGFIGHTER: return true;
		case UNIT_TYPEID::ZERG_BANELING: return true;
		case UNIT_TYPEID::ZERG_BROODLING: return true;
		case UNIT_TYPEID::ZERG_BROODLORD: return true;
		case UNIT_TYPEID::ZERG_BROODLORDCOCOON: return true;
		case UNIT_TYPEID::ZERG_CHANGELING: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGMARINE: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGMARINESHIELD: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGZEALOT: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGZERGLING: return true;
		case UNIT_TYPEID::ZERG_CHANGELINGZERGLINGWINGS: return true;
		case UNIT_TYPEID::ZERG_CORRUPTOR: return true;
		case UNIT_TYPEID::ZERG_DRONE: return true;
		case UNIT_TYPEID::ZERG_HYDRALISK: return true;
		case UNIT_TYPEID::ZERG_INFESTEDTERRANSEGG: return true;
		case UNIT_TYPEID::ZERG_INFESTOR: return true;
		case UNIT_TYPEID::ZERG_INFESTORTERRAN: return true;
		case UNIT_TYPEID::ZERG_LOCUSTMP: return true;
		case UNIT_TYPEID::ZERG_LOCUSTMPFLYING: return true;
		case UNIT_TYPEID::ZERG_LURKERMP: return true;
		case UNIT_TYPEID::ZERG_MUTALISK: return true;
		case UNIT_TYPEID::ZERG_OVERLORD: return true;
		case UNIT_TYPEID::ZERG_OVERLORDTRANSPORT: return true;
		case UNIT_TYPEID::ZERG_OVERSEER: return true;
		case UNIT_TYPEID::ZERG_QUEEN: return true;
		case UNIT_TYPEID::ZERG_RAVAGER: return true;
		case UNIT_TYPEID::ZERG_ROACH: return true;
		case UNIT_TYPEID::ZERG_SPINECRAWLERUPROOTED: return true;
		case UNIT_TYPEID::ZERG_SPORECRAWLERUPROOTED: return true;
		case UNIT_TYPEID::ZERG_SWARMHOSTBURROWEDMP: return true;
		case UNIT_TYPEID::ZERG_SWARMHOSTMP: return true;
		case UNIT_TYPEID::ZERG_TRANSPORTOVERLORDCOCOON: return true;
		case UNIT_TYPEID::ZERG_ULTRALISK: return true;
		case UNIT_TYPEID::ZERG_VIPER: return true;
		case UNIT_TYPEID::ZERG_ZERGLING: return true;
		case UNIT_TYPEID::PROTOSS_ADEPT: return true;
		case UNIT_TYPEID::PROTOSS_ARCHON: return true;
		case UNIT_TYPEID::PROTOSS_CARRIER: return true;
		case UNIT_TYPEID::PROTOSS_COLOSSUS: return true;
		case UNIT_TYPEID::PROTOSS_DARKTEMPLAR: return true;
		case UNIT_TYPEID::PROTOSS_DISRUPTOR: return true;
		case UNIT_TYPEID::PROTOSS_HIGHTEMPLAR: return true;
		case UNIT_TYPEID::PROTOSS_IMMORTAL: return true;
		case UNIT_TYPEID::PROTOSS_INTERCEPTOR: return true;
		case UNIT_TYPEID::PROTOSS_MOTHERSHIP: return true;
		case UNIT_TYPEID::PROTOSS_MOTHERSHIPCORE: return true;
		case UNIT_TYPEID::PROTOSS_OBSERVER: return true;
		case UNIT_TYPEID::PROTOSS_ORACLE: return true;
		case UNIT_TYPEID::PROTOSS_PHOENIX: return true;
		case UNIT_TYPEID::PROTOSS_PROBE: return true;
		case UNIT_TYPEID::PROTOSS_SENTRY: return true;
		case UNIT_TYPEID::PROTOSS_STALKER: return true;
		case UNIT_TYPEID::PROTOSS_TEMPEST: return true;
		case UNIT_TYPEID::PROTOSS_VOIDRAY: return true;
		case UNIT_TYPEID::PROTOSS_WARPPRISM: return true;
		case UNIT_TYPEID::PROTOSS_ZEALOT: return true;
		default: return false;
		}
	}
};

struct IsTownHall {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::ZERG_HATCHERY: return true;
		case UNIT_TYPEID::ZERG_LAIR: return true;
		case UNIT_TYPEID::ZERG_HIVE: return true;
		case UNIT_TYPEID::TERRAN_COMMANDCENTER: return true;
		case UNIT_TYPEID::TERRAN_ORBITALCOMMAND: return true;
		case UNIT_TYPEID::TERRAN_ORBITALCOMMANDFLYING: return true;
		case UNIT_TYPEID::TERRAN_PLANETARYFORTRESS: return true;
		case UNIT_TYPEID::PROTOSS_NEXUS: return true;
		default: return false;
		}
	}
};

struct IsVespeneGeyser {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::NEUTRAL_VESPENEGEYSER: return true;
		case UNIT_TYPEID::NEUTRAL_SPACEPLATFORMGEYSER: return true;
		case UNIT_TYPEID::NEUTRAL_PROTOSSVESPENEGEYSER: return true;
		default: return false;
		}
	}
};

struct IsWorker {
	bool operator()(const Unit& unit) {
		switch (unit.unit_type.ToType()) {
		case UNIT_TYPEID::PROTOSS_PROBE: return true;
		case UNIT_TYPEID::ZERG_DRONE: return true;
		case UNIT_TYPEID::TERRAN_SCV: return true;
		default: return false;
		}
	}
};

CryptBot::CryptBot()
	: Scouting(false)
	, ScoutingUnitTag(0)
	, Expanding(false)
{
}
int32_t CryptBot::GetCurrentMaxSupply()
{
	int32_t MaxSupply = 0;
	const Units NewUnits = Observation()->GetUnits();
	for (auto &u : NewUnits)
	{
		if (u->unit_type == UNIT_TYPEID::PROTOSS_NEXUS && u->build_progress == 1.0f)
		{
			MaxSupply += 15;
		} 
		else if (u->unit_type == UNIT_TYPEID::PROTOSS_PYLON && u->build_progress == 1.0f)
		{
			MaxSupply += 8;
		}

	}
	return MaxSupply;
}

void CryptBot::OnGameStart()
{
	const Units NewUnits = Observation()->GetUnits();
	for (auto &u : NewUnits)
	{
		if (u->unit_type == UNIT_TYPEID::PROTOSS_NEXUS)
		{
			StartPosition = new sc2::Point2D(u->pos);
			Actions()->UnitCommand(u, ABILITY_ID::TRAIN_PROBE);
			break;
		}
	}
	expansions_ = search::CalculateExpansionLocations(Observation(), Query());

	game_info_ = new sc2::GameInfo(Observation()->GetGameInfo());
}

void CryptBot::OnUnitDestroyed(const Unit *unit) {
	switch (unit->unit_type.ToType()) {
	case UNIT_TYPEID::PROTOSS_PROBE: {
		if (unit->tag == ScoutingUnitTag)
		{
			Scouting = false;
			ScoutingUnitTag = 0;
		}
		break;
	}
	case UNIT_TYPEID::PROTOSS_VOIDRAY: {
		/*
		for (auto& ThisBG : BattleGroups)
		{
			int thisMember = 0;
			for (const uint64_t ThisUnit : ThisBG.Members)
			{
				if (ThisUnit == unit.tag)
				{
					ThisBG.Members.erase(ThisBG.Members.begin() + thisMember);
				}
				thisMember++;
			}
		}
		*/
	}
	}
}

bool CryptBot::CheckShouldBuildProbe(const sc2::Unit Nexus)
{
	const ObservationInterface* observation = Observation();
	if (CurrentMaxSupply >= observation->GetFoodUsed())
	{
		return false;
	}
	uint64_t mineral_target;
	if (Nexus.assigned_harvesters < Nexus.ideal_harvesters)
	{
		Actions()->UnitCommand(&Nexus, ABILITY_ID::TRAIN_PROBE);
		return true;
	}
	else if (FindNearestGeaser(Nexus.pos, mineral_target, MAX_GEASER_DISTANCE))
	{
		Actions()->UnitCommand(&Nexus, ABILITY_ID::TRAIN_PROBE);
		return true;
	}
	return false;
}

void CryptBot::OnUnitCreated(const Unit *unit)
{
	const ObservationInterface* observation = Observation();
	switch (unit->unit_type.ToType()) {
	case UNIT_TYPEID::PROTOSS_NEXUS: {
		Expanding = false;
		ExpandingFrame = 0;
		break;
	}
	case UNIT_TYPEID::PROTOSS_ADEPT:
	case UNIT_TYPEID::PROTOSS_ARCHON: 
	case UNIT_TYPEID::PROTOSS_CARRIER: 
	case UNIT_TYPEID::PROTOSS_COLOSSUS:
	case UNIT_TYPEID::PROTOSS_DARKTEMPLAR:
	case UNIT_TYPEID::PROTOSS_DISRUPTOR:
	case UNIT_TYPEID::PROTOSS_HIGHTEMPLAR:
	case UNIT_TYPEID::PROTOSS_IMMORTAL:
	case UNIT_TYPEID::PROTOSS_INTERCEPTOR:
	case UNIT_TYPEID::PROTOSS_MOTHERSHIP:
	case UNIT_TYPEID::PROTOSS_MOTHERSHIPCORE:
	case UNIT_TYPEID::PROTOSS_OBSERVER:
	case UNIT_TYPEID::PROTOSS_ORACLE:
	case UNIT_TYPEID::PROTOSS_PHOENIX:
	case UNIT_TYPEID::PROTOSS_SENTRY: 
	case UNIT_TYPEID::PROTOSS_STALKER:
	case UNIT_TYPEID::PROTOSS_TEMPEST: 
	case UNIT_TYPEID::PROTOSS_VOIDRAY: 
	case UNIT_TYPEID::PROTOSS_WARPPRISM:
	case UNIT_TYPEID::PROTOSS_ZEALOT: 
	{

		for (auto& ThisBG : BattleGroups)
		{
			if (ThisBG.UnitType == unit->unit_type.ToType() && ThisBG.Members.size() < BATTLEGROUP_SIZE && !ThisBG.Attacking)
			{
				ThisBG.Members.push_back(unit->tag);
				if (ThisBG.Members.size() >= BATTLEGROUP_SIZE)
				{
					ThisBG.Attacking = true;
				}
				break;
			}
		}
		BattleGroup BG;
		BG.Attacking = false;
		BG.engaged_tag = 0;
		BG.UnitType = unit->unit_type.ToType();
		BG.Members.push_back(unit->tag);
		BattleGroups.push_back(BG);

		break;
	}

	}
	if (observation->GetFoodUsed() > (GetCurrentMaxSupply() - 5))
	{
		bool ShouldBuildPylon = true;
		const Units NewUnits = Observation()->GetUnits(sc2::Unit::Alliance::Self, IsUnit(UNIT_TYPEID::PROTOSS_PYLON));
		for (const auto &u : NewUnits)
		{
			if (u->build_progress < 1.0f)
			{
					// Pylon currently being built, no need to build another one
				ShouldBuildPylon = false;
				break;
			}
		}
		if (ShouldBuildPylon)
		{
			TryBuildStructure(ABILITY_ID::BUILD_PYLON);
		}
	}
}

void CryptBot::ManageBattleGroups(const ObservationInterface* observation)
{
	Units EnemyBuildings = observation->GetUnits(Unit::Alliance::Enemy, IsBuilding());
	Units EnemyArmy = observation->GetUnits(Unit::Alliance::Enemy, IsArmy());
	for (const auto &ThisBG : BattleGroups)
	{
		if (ThisBG.Members.empty())
		{
			continue;
		}
		if (!ThisBG.Attacking)
		{
			// Still building;
			continue;
		}
		if (ThisBG.engaged_tag != 0)
		{
			const Unit *EngagedUnit = observation->GetUnit(ThisBG.engaged_tag);
			if (EngagedUnit != nullptr)
			{
				// Finish killing this unit
				continue;
			}
		}
		const Unit *Primary = observation->GetUnit(ThisBG.Members.back());
		if (Primary != nullptr)
		{
			int64_t AttackableUnit = FindNearestUnit(Primary->pos, EnemyArmy, ATTACK_TYPE::FLYING);
			if (AttackableUnit == 0)
			{
				AttackableUnit = FindNearestUnit(Primary->pos, EnemyBuildings);
			}
			if(AttackableUnit != 0)
			{
				for (int64_t VoidRayTag : ThisBG.Members)
				{
					const Unit *VRUnit = observation->GetUnit(VoidRayTag);
					if (VRUnit != nullptr)
					{
						if (VRUnit->weapon_cooldown <= 0.0f)
						{
							Actions()->UnitCommand(VRUnit, ABILITY_ID::EFFECT_VOIDRAYPRISMATICALIGNMENT);

						}
					}
					Actions()->UnitCommand(VRUnit, ABILITY_ID::ATTACK, observation->GetUnit(AttackableUnit));
					
				}
			}
		}
	}

}
int64_t CryptBot::FindNearestUnit(const Point2D& start, Units UnitSet, ATTACK_TYPE AttackType) {
	float distance = std::numeric_limits<float>::max();
	int64_t ReturnedUnit = 0;
	bool FoundUnit = false, FoundUnitType = false;
	if (AttackType == ATTACK_TYPE::BOTH)
	{
		FoundUnitType = true;
	}
	for (const auto& u : UnitSet) {
		float d = DistanceSquared2D(u->pos, start);
		if (d < distance || FoundUnitType == false) {
			FoundUnit = true;
			if (AttackType == ATTACK_TYPE::BOTH)
			{
				distance = d;
				ReturnedUnit = u->tag;
			}
			else if (FoundUnitType && d < distance)
			{
				ATTACK_TYPE UnitCanAttack = CanAttack(u->unit_type.ToType());
				if (UnitCanAttack == ATTACK_TYPE::BOTH || UnitCanAttack == AttackType)
				{
					distance = d;
					ReturnedUnit = u->tag;
				}
			}
			else if (FoundUnitType == false && d < distance)
			{
				distance = d;
				ReturnedUnit = u->tag;
				ATTACK_TYPE UnitCanAttack = CanAttack(u->unit_type.ToType());
				if (UnitCanAttack == ATTACK_TYPE::BOTH || UnitCanAttack == AttackType)
				{
					FoundUnitType = true;
				}
			}

		}
	}
	return ReturnedUnit;
}
	


void CryptBot::OnUnitIdle(const Unit *unit) {
	switch (unit->unit_type.ToType()) {
	case UNIT_TYPEID::PROTOSS_PROBE: {
		if (unit->tag != ScoutingUnitTag)
		{
			uint64_t valid_mineral_patch;
			FindNearestMineralPatch(unit->pos, valid_mineral_patch);
			Actions()->UnitCommand(unit, ABILITY_ID::HARVEST_GATHER, Observation()->GetUnit(valid_mineral_patch));
			return;

		}
	}
	}
}

bool CryptBot::BuildAvailableGeaser(AbilityID build_ability, UnitTypeID worker_type, Point2D base_location)
{
	const ObservationInterface* observation = Observation();
	Units geysers = observation->GetUnits(Unit::Alliance::Neutral, IsVespeneGeyser());

	//only search within this radius
	float minimum_distance = 15.0f;
	Tag closestGeyster = 0;
	for (const auto& geyser : geysers) {
		float current_distance = Distance2D(base_location, geyser->pos);
		if (current_distance < minimum_distance) {
			if (Query()->Placement(build_ability, geyser->pos)) {
				minimum_distance = current_distance;
				closestGeyster = geyser->tag;
			}
		}
	}

	// In the case where there are no more available geysers nearby
	if (closestGeyster == 0) {
		return false;
	}
	return TryBuildStructure(build_ability, worker_type, closestGeyster);
}

bool CryptBot::FindNearestGeaser(const Point2D &start, uint64_t& target, float MaxDistance)
{
	const ObservationInterface* observation = Observation();
	float distance = MaxDistance;
	Units geysers = observation->GetUnits(Unit::Alliance::Self, IsUnit(UNIT_TYPEID::PROTOSS_ASSIMILATOR));
	for (const auto& u : geysers) {
		if(u->assigned_harvesters < u->ideal_harvesters)
		{
			float d = DistanceSquared2D(u->pos, start);
			if (d < distance ) {
				distance = d;
				target = u->tag;
			}
		}
	}
	if (distance == MaxDistance) {
		return false;
	}

	return true;
}
size_t CryptBot::CountUnitType(const ObservationInterface* observation, UnitTypeID unit_type) {
	return observation->GetUnits(Unit::Alliance::Self, IsUnit(unit_type)).size();
}

void CryptBot::EconStrat(const ObservationInterface *observation)
{

	Units bases = observation->GetUnits(Unit::Alliance::Self, IsTownHall());
	Units NearbyGeasers = observation->GetUnits(Unit::Alliance::Self, IsUnit(UNIT_TYPEID::PROTOSS_ASSIMILATOR));
	Units Probes = observation->GetUnits(Unit::Alliance::Self, IsUnit(UNIT_TYPEID::PROTOSS_PROBE));
	bool ShouldExpandBase = true;
	for (const auto& base : bases)
	{
		if (!base->orders.empty())
		{
			ShouldExpandBase = false;
			// Already making a probe
			continue;
		}
		int32_t CurrentGeysers = 0;
		for (const auto& geyser : NearbyGeasers)
		{
			if (DistanceSquared2D(base->pos, geyser->pos) < MAX_GEASER_DISTANCE)
			{
				CurrentGeysers ++;
				if (geyser->assigned_harvesters < geyser->ideal_harvesters)
				{
					for (const auto& probe : Probes)
					{
						if (probe->tag != ScoutingUnitTag)
						{

							if (probe->orders.empty())
							{
								Actions()->UnitCommand(probe, ABILITY_ID::HARVEST_GATHER, geyser);
								break;
							}
							UnitOrder CurrentOrder = probe->orders.back();
							if (CurrentOrder.ability_id == ABILITY_ID::HARVEST_GATHER)
							{
								if (CurrentOrder.target_unit_tag == 0)
								{
									Actions()->UnitCommand(probe, ABILITY_ID::HARVEST_GATHER, geyser);
									break;
								}
								const Unit *TargetUnit = observation->GetUnit(CurrentOrder.target_unit_tag);
								if (TargetUnit == nullptr || TargetUnit->unit_type == UNIT_TYPEID::NEUTRAL_MINERALFIELD)
								{
									Actions()->UnitCommand(probe, ABILITY_ID::HARVEST_GATHER, geyser);
									break;
								}

							}
						}
					}
				}

			}

		}
		if (CurrentGeysers < 2)
		{
			if ((base->assigned_harvesters + 3) >= base->ideal_harvesters && (base->build_progress == 1.0f)) {
				BuildAvailableGeaser(ABILITY_ID::BUILD_ASSIMILATOR, UNIT_TYPEID::PROTOSS_PROBE, base->pos);
			}
			ShouldExpandBase = false;

		}
		if (base->assigned_harvesters < base->ideal_harvesters)
		{
			Actions()->UnitCommand(base, ABILITY_ID::TRAIN_PROBE);
			ShouldExpandBase = false;
		}
	}
	if (ExpandingFrame > 0 && observation->GetGameLoop() > (ExpandingFrame + 150))
	{
		Expanding = false;
		ExpandingFrame = 0;
	}
	if (ShouldExpandBase && !Expanding)
	{
		Expanding = TryExpand(observation);
		ExpandingFrame = observation->GetGameLoop();

	}
}

bool CryptBot::TryExpand(const ObservationInterface* observation)
{

	float minimum_distance = std::numeric_limits<float>::max();
	Point3D closest_expansion;
	for (const auto& expansion : expansions_) {
		float current_distance = Distance2D(*StartPosition, expansion);
		if (current_distance < .01f) {
			continue;
		}

		if (current_distance < minimum_distance) {
			if (Query()->Placement(ABILITY_ID::BUILD_NEXUS, expansion)) {
				closest_expansion = expansion;
				minimum_distance = current_distance;
			}
		}
	}
	//only update staging location up till 3 bases.
	if (TryBuildStructure(ABILITY_ID::BUILD_NEXUS, UNIT_TYPEID::PROTOSS_PROBE, closest_expansion))
	{
		return true;
	}
	return false;

}

void CryptBot::CheckScouting(const ObservationInterface *observation)
{
	if (Scouting)
	{
		const Unit *ScoutingUnit = observation->GetUnit(ScoutingUnitTag);

		if (ScoutingUnit == nullptr || ScoutingUnit->orders.empty())
		{
			Scouting = false;
		}
	}
	if (!Scouting)
	{
		if (observation->GetUnits(sc2::Unit::Alliance::Enemy, IsTownHall()).empty())
		{
			if (ScoutingUnitTag != 0)
			{
				const Unit *NewScoutingUnit = observation->GetUnit(ScoutingUnitTag);
				if (NewScoutingUnit != nullptr)
				{
					ScoutWithUnit(*NewScoutingUnit, observation);
					Scouting = true;

				}

			}
			ScoutingUnitTag = GetAvailableWorker();
			const Unit *NewScoutingUnit = observation->GetUnit(ScoutingUnitTag);
			if (NewScoutingUnit != nullptr)
			{
				ScoutWithUnit(*NewScoutingUnit, observation);
				Scouting = true;

			}
		}
	}
}

void CryptBot::OnStep() {
	const ObservationInterface* observation = Observation();
	if (!observation)
	{
		return;
	}
	//Throttle some behavior that can wait to avoid duplicate orders.
	int frames_to_skip = 4;
	if (observation->GetFoodUsed() >= observation->GetFoodCap()) {
		frames_to_skip = 6;
	}

	if (observation->GetGameLoop() % frames_to_skip != 0) {
		return;
	}
	CurrentMaxSupply = GetCurrentMaxSupply();


	CheckScouting(observation);
	EconStrat(observation);
	TryBuildPylon(observation);
	if (observation->GetFoodWorkers() > 18)
	{
		TryBuildBuildings(observation);
		TryBuildArmy(observation);
		ManageBattleGroups(observation);
	}
}

void CryptBot::TryBuildArmy(const ObservationInterface* observation)
{
	if (observation->GetMinerals() < 250 || observation->GetVespene() < 150)
	{
		return;
	}
	Units Stargates = observation->GetUnits(Unit::Alliance::Self, IsUnit(UNIT_TYPEID::PROTOSS_STARGATE));
	for (const auto& Stargate : Stargates)
	{
		if (Stargate->orders.empty())
		{
			Actions()->UnitCommand(Stargate, ABILITY_ID::TRAIN_VOIDRAY);
		}
	}
}
void CryptBot::TryBuildBuildings(const ObservationInterface* observation)
{
	size_t gateway_count = CountUnitType(observation, UNIT_TYPEID::PROTOSS_GATEWAY) + CountUnitType(observation, UNIT_TYPEID::PROTOSS_WARPGATE);
	if (gateway_count < 1)
	{ 
		if (observation->GetMinerals() > 150) {

			TryBuildStructureNearPylon(ABILITY_ID::BUILD_GATEWAY, UNIT_TYPEID::PROTOSS_PROBE);
		}
		return;
	}
	size_t cybernetics_count = CountUnitType(observation, UNIT_TYPEID::PROTOSS_CYBERNETICSCORE);
	if (cybernetics_count < 1)
	{
		TryBuildStructureNearPylon(ABILITY_ID::BUILD_CYBERNETICSCORE, UNIT_TYPEID::PROTOSS_PROBE);
		return;
	}
	size_t stargate_count = CountUnitType(observation, UNIT_TYPEID::PROTOSS_STARGATE);

	if (stargate_count < 3 && observation->GetMinerals() > 150 && observation->GetVespene() > 150) {
		TryBuildStructureNearPylon(ABILITY_ID::BUILD_STARGATE, UNIT_TYPEID::PROTOSS_PROBE);
	}

}

bool CryptBot::TryBuildStructureNearPylon(AbilityID ability_type_for_structure, UnitTypeID unit_type) {
	const ObservationInterface* observation = Observation();

	//Need to check to make sure its a pylon instead of a warp prism
	std::vector<PowerSource> power_sources = observation->GetPowerSources();
	if (power_sources.empty()) {
		return false;
	}

	const PowerSource& random_power_source = GetRandomEntry(power_sources);
	if (observation->GetUnit(random_power_source.tag) != nullptr) {
		if (observation->GetUnit(random_power_source.tag)->unit_type == UNIT_TYPEID::PROTOSS_WARPPRISM) {
			return false;
		}
	}
	else {
		return false;
	}
	float radius = random_power_source.radius;
	float rx = GetRandomScalar();
	float ry = GetRandomScalar();
	Point2D build_location = Point2D(random_power_source.position.x + rx * radius, random_power_source.position.y + ry * radius);
	return TryBuildStructure(ability_type_for_structure, UNIT_TYPEID::PROTOSS_PROBE, build_location);
}

bool CryptBot::TryBuildStructure(ABILITY_ID ability_type_for_structure, UNIT_TYPEID unit_type, Point2D TargetLocation) {
	const ObservationInterface* observation = Observation();

	// If a unit already is building a supply structure of this type, do nothing.
	// Also get an scv to build the structure.
	const Unit *unit_to_build = nullptr;
	Units units = observation->GetUnits(Unit::Alliance::Self, IsUnit(unit_type));
	for (const auto& unit : units) {
		for (const auto& order : unit->orders) {
			if (order.ability_id == ability_type_for_structure) {
				return false;
			}
		}

		unit_to_build = unit;
	}
	if (unit_to_build != nullptr)
	{
		Actions()->UnitCommand(unit_to_build,
			ability_type_for_structure,
			TargetLocation);
	}

	return true;

}


bool CryptBot::TryBuildStructure(ABILITY_ID ability_type_for_structure, UNIT_TYPEID unit_type) {
	const ObservationInterface* observation = Observation();

	// If a unit already is building a supply structure of this type, do nothing.
	// Also get an scv to build the structure.
	const Unit *unit_to_build = nullptr;
	Units units = observation->GetUnits(Unit::Alliance::Self, IsUnit(unit_type));
	for (const auto& unit : units) {
		for (const auto& order : unit->orders) {
			if (order.ability_id == ability_type_for_structure) {
				return false;
			}
		}

		unit_to_build = unit;
	}

	float rx = GetRandomScalar();
	float ry = GetRandomScalar();
	if (unit_to_build != nullptr)
	{
	
		Actions()->UnitCommand(unit_to_build,
			ability_type_for_structure,
			Point2D(unit_to_build->pos.x + rx * 15.0f, unit_to_build->pos.y + ry * 15.0f));
	}

	return true;
}

bool CryptBot::TryBuildPylon(const ObservationInterface* observation) {

	// If we are not supply capped, don't build a supply depot.
	if (observation->GetFoodUsed() <= observation->GetFoodCap() - 2)
		return false;

	const Units NewUnits = Observation()->GetUnits(sc2::Unit::Alliance::Self, IsUnit(UNIT_TYPEID::PROTOSS_PYLON));
	for (const auto &u : NewUnits)
	{
		if (u->build_progress < 1.0f)
		{
			// Pylon currently being built, no need to build another one
			return false;
			break;
		}
	}
	// Try and build a depot. Find a random SCV and give it the order.
	return TryBuildStructure(ABILITY_ID::BUILD_PYLON);
}

bool CryptBot::FindNearestMineralPatch(const Point2D& start, uint64_t& target) {
	Units units = Observation()->GetUnits(Unit::Alliance::Neutral);
	float distance = std::numeric_limits<float>::max();
	for (const auto& u : units) {
		if (u->unit_type == UNIT_TYPEID::NEUTRAL_MINERALFIELD) {
			float d = DistanceSquared2D(u->pos, start);
			if (d < distance) {
				distance = d;
				target = u->tag;
			}
		}
	}

	if (distance == std::numeric_limits<float>::max()) {
		return false;
	}

	return true;
}

void CryptBot::ScoutWithUnit(Unit unit, const ObservationInterface* observation) {
	Units enemy_units = observation->GetUnits(Unit::Alliance::Enemy, IsAttackable());

	Point2D target_pos;

	if (FindEnemyPosition(unit.tag, target_pos)) {
		if (Distance2D(unit.pos, target_pos) < 20 && enemy_units.empty()) {
			if (TryFindRandomPathableLocation(unit.tag, target_pos)) {
				Actions()->UnitCommand(&unit, ABILITY_ID::SMART, target_pos);
				return;
			}
		}
		else if (!enemy_units.empty())
		{
			Actions()->UnitCommand(&unit, ABILITY_ID::ATTACK, enemy_units.front());
			return;
		}
		Actions()->UnitCommand(&unit, ABILITY_ID::SMART, target_pos);
	}
	else {
		if (TryFindRandomPathableLocation(unit.tag, target_pos)) {
			Actions()->UnitCommand(&unit, ABILITY_ID::SMART, target_pos);
		}
	}
}

bool CryptBot::TryFindRandomPathableLocation(Tag tag, Point2D& target_pos) {
	// First, find a random point inside the playable area of the map.
	float playable_w = game_info_->playable_max.x - game_info_->playable_min.x;
	float playable_h = game_info_->playable_max.y - game_info_->playable_min.y;

	// The case where game_info_ does not provide a valid answer
	if (playable_w == 0 || playable_h == 0) {
		playable_w = 236;
		playable_h = 228;
	}

	target_pos.x = playable_w * GetRandomFraction() + game_info_->playable_min.x;
	target_pos.y = playable_h * GetRandomFraction() + game_info_->playable_min.y;

	// Now send a pathing query from the unit to that point. Can also query from point to point,
	// but using a unit tag wherever possible will be more accurate.
	// Note: This query must communicate with the game to get a result which affects performance.
	// Ideally batch up the queries (using PathingDistanceBatched) and do many at once.
	float distance = Query()->PathingDistance(Observation()->GetUnit(tag), target_pos);

	return distance > 0.1f;
}

// Tries to find a random location that can be pathed to on the map.
// Returns 'true' if a new, random location has been found that is pathable by the unit.
bool CryptBot::FindEnemyPosition(Tag tag, Point2D& target_pos) {
	if (game_info_->enemy_start_locations.empty()) {
		return false;
	}
	int32_t NextPos = rand() % game_info_->enemy_start_locations.size();
	target_pos = game_info_->enemy_start_locations[NextPos];
	return true;
}

Tag CryptBot::GetAvailableWorker()
{
	const ObservationInterface* observation = Observation();
	sc2::Units WorkerUnits = observation->GetUnits(Unit::Alliance::Self, IsUnit(UNIT_TYPEID::PROTOSS_PROBE));
	if (WorkerUnits.empty())
	{
		return 0;
	}
	return WorkerUnits.back()->tag;
	//TODO: Find a better way to get a worker unit
}

//Try to build a structure based on tag, Used mostly for Vespene, since the pathing check will fail even though the geyser is "Pathable"
bool CryptBot::TryBuildStructure(AbilityID ability_type_for_structure, UnitTypeID unit_type, Tag location_tag) {
	const ObservationInterface* observation = Observation();
	Units workers = observation->GetUnits(Unit::Alliance::Self, IsUnit(unit_type));
	const Unit* target = observation->GetUnit(location_tag);

	if (workers.empty()) {
		return false;
	}

	// Check to see if there is already a worker heading out to build it
	for (const auto& worker : workers) {
		for (const auto& order : worker->orders) {
			if (order.ability_id == ability_type_for_structure) {
				return false;
			}
		}
	}

	// If no worker is already building one, get a random worker to build one
	const Unit *unit = GetRandomEntry(workers);

	// Check to see if unit can build there
	if (Query()->Placement(ability_type_for_structure, target->pos)) {
		Actions()->UnitCommand(unit, ability_type_for_structure, target);
		return true;
	}
	return false;

}


void *CreateNewAgent()
{
	return (void *)new CryptBot();
}

const char *GetAgentName()
{
	return "CryptBot";
}

int GetAgentRace()
{
	return (int)sc2::Race::Protoss;
}