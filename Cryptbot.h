#pragma once

#include "sc2api/sc2_interfaces.h"
#include "sc2api/sc2_agent.h"
#include "sc2api/sc2_map_info.h"
#include "sc2lib/sc2_lib.h"

#include "Strategys.h"
#define DllExport   __declspec( dllexport )  
using namespace sc2;

#define MAX_GEASER_DISTANCE 200
#define BATTLEGROUP_SIZE 3
#define CANNONS_PER_PYLON 4
typedef struct BattleGroup_s
{
    UNIT_TYPEID UnitType;
    std::vector<int64_t> Members;
    bool Attacking;
    uint64_t engaged_tag;
    Point2D ScoutingTarget;

} BattleGroup;

typedef struct PylonLocations_s
{
    std::string MapName;
    Point3D TopLocation;
    Point3D BotLocation;
    PylonLocations_s(std::string InMapName, Point3D InTop, Point3D InBot)
        : MapName(InMapName)
        , TopLocation(InTop)
        , BotLocation(InBot)
    {}
} PylonLocations;

//std::vector<PylonLocations> MapLocations;
static const float PI = 3.1415927f;

enum QueryType
{
    None,
    MinXMinY,
    MinXMaxY,
    MaxXMinY,
    MaxXMaxY
};


class CryptBot : public Agent
{
public:
	Point2D GetRandomBuildableLocationFor(sc2::ABILITY_ID Structure, sc2::Point2D Location, QueryType QType, sc2::search::ExpansionParameters parameters);
	Point2D GetNearestBuildableLocationFor(sc2::ABILITY_ID Structure, sc2::Point2D Location, QueryType QType, sc2::search::ExpansionParameters parameters = sc2::search::ExpansionParameters());
    CryptBot();
    virtual void OnStep() override;
    void TryBuildBuildings(const ObservationInterface * observation);
    bool TryBuildStructureNearPylon(AbilityID ability_type_for_structure, UnitTypeID unit_type, Point2D NearPoint, bool UseScout = false);
    void ExcludeRushPylons(std::vector<PowerSource>& PowerSources);
    void TryBuildArmy(const ObservationInterface * observation);
	void TryBuildAltArmy(const ObservationInterface * observation);
    void TryBuildCannonRush(const ObservationInterface * observation);
	void TryBuildAltStrategy(const ObservationInterface * observation);
    bool TryBuildStructureNearPylon(AbilityID ability_type_for_structure, UnitTypeID unit_type);
    bool TryBuildStructure(ABILITY_ID ability_type_for_structure, UNIT_TYPEID unit_type, Point2D TargetLocation, bool UseScout = false);
    virtual void OnGameStart() override;
    virtual void OnUnitIdle(const Unit *unit) override;
	bool BuildAvailableGeaser(AbilityID build_ability, UnitTypeID worker_type, Point2D base_location);
    virtual void OnUnitDestroyed(const Unit *unit) override;
    bool CheckShouldBuildProbe(const sc2::Unit Nexus);
    virtual void OnUnitCreated(const Unit *unit) override;
    virtual void OnUnitEnterVision(const Unit *unit) override;
    void OnBuildingConstructionComplete(const Unit * unit);
    void ScoutWithUnit(Unit unit, const ObservationInterface* observation);

private:
    sc2::Point3D *StartPosition;
    sc2::Point2D DefensePylon;
    sc2::Point2D RushLocation;
    void SetupRushLocation(const ObservationInterface *observation);
    int32_t GetCurrentMaxSupply();
    bool FindNearestMineralPatch(const Point2D& start, uint64_t& target);
    bool TryBuildPylon(const ObservationInterface *observation);
    bool TryBuildStructure(ABILITY_ID ability_type_for_structure, UNIT_TYPEID unit_type = UNIT_TYPEID::PROTOSS_PROBE);
    bool TryBuildBasePylon();
    // Tries to find a random location that can be pathed to on the map.
    // Returns 'true' if a new, random location has been found that is pathable by the unit.
    bool FindEnemyPosition(Tag tag, Point2D& target_pos);
	const Unit *GetAvailableWorkerUnit();
    Tag GetAvailableWorker();
    bool TryBuildStructure(AbilityID ability_type_for_structure, UnitTypeID unit_type, Tag location_tag);
    bool FindNearestGeaser(const Point2D &start, uint64_t& target, float MaxDistance);
    size_t CountUnitType(const ObservationInterface * observation, UnitTypeID unit_type);
    void EconStrat(const ObservationInterface *observation);
    bool TryExpand(const ObservationInterface* observation);
    void ExecuteStrategy(const ObservationInterface *observation);
    void CheckScouting(const ObservationInterface *observation);
    bool TryFindRandomPathableLocation(Tag tag, Point2D& target_pos);
    void ManageBattleGroups(const ObservationInterface* observation);
    int64_t FindNearestUnit(const Point2D& start, Units UnitSet, ATTACK_TYPE AttackType = ATTACK_TYPE::BOTH);
    bool Scouting;
    std::vector<Point3D> expansions_;
	uint64_t RushUnitTag;
    uint64_t ScoutingUnitTag;
    GameInfo *game_info_;
    int32_t CurrentMaxSupply;
    bool Expanding;
    bool FirstPylon;
    bool RushPylonBuilt;
	bool HasTrainedCarrierLaunch;
    uint32_t ExpandingFrame;
    bool RushPylon;
    std::vector<BattleGroup> BattleGroups;
    Strategy *CurrentStrategy;
    sc2::search::ExpansionParameters PylonSearchParams;
    int32_t CurrentDefenseCannons;
    int32_t MaxDefenseCannons;
    int32_t CurrentOffenseno;
	bool RushPylonDestroyed;
	sc2::Race OpponentRace;
	bool UseAltStrategy;

};


void DllExport *CreateNewAgent();

int DllExport GetAgentRace();

const char DllExport *GetAgentName();
