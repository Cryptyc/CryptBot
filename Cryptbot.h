#include "sc2api/sc2_interfaces.h"
#include "sc2api/sc2_agent.h"
#include "sc2api/sc2_map_info.h"
#include "Strategys.h"
#pragma once
#define DllExport   __declspec( dllexport )  
using namespace sc2;

#define MAX_GEASER_DISTANCE 200
#define BATTLEGROUP_SIZE 7

typedef struct BattleGroup_s
{
    UNIT_TYPEID UnitType;
    std::vector<int64_t> Members;
    bool Attacking;
    uint64_t engaged_tag;

} BattleGroup;

class CryptBot : public Agent
{
public:
    CryptBot();
    virtual void OnStep() override;
    void TryBuildBuildings(const ObservationInterface * observation);
    void TryBuildArmy(const ObservationInterface * observation);
    bool TryBuildStructureNearPylon(AbilityID ability_type_for_structure, UnitTypeID unit_type);
    bool TryBuildStructure(ABILITY_ID ability_type_for_structure, UNIT_TYPEID unit_type, Point2D TargetLocation);
    virtual void OnGameStart() override;
    virtual void OnUnitIdle(const Unit *unit) override;
	bool BuildAvailableGeaser(AbilityID build_ability, UnitTypeID worker_type, Point2D base_location);
    virtual void OnUnitDestroyed(const Unit *unit) override;
    bool CheckShouldBuildProbe(const sc2::Unit Nexus);
    virtual void OnUnitCreated(const Unit *unit) override;
    void ScoutWithUnit(Unit unit, const ObservationInterface* observation);

private:
    sc2::Point2D *StartPosition;
    int32_t GetCurrentMaxSupply();
    bool FindNearestMineralPatch(const Point2D& start, uint64_t& target);
    bool TryBuildPylon(const ObservationInterface *observation);
    bool TryBuildStructure(ABILITY_ID ability_type_for_structure, UNIT_TYPEID unit_type = UNIT_TYPEID::PROTOSS_PROBE);
    // Tries to find a random location that can be pathed to on the map.
    // Returns 'true' if a new, random location has been found that is pathable by the unit.
    bool FindEnemyPosition(Tag tag, Point2D& target_pos);
    Tag GetAvailableWorker();
    bool TryBuildStructure(AbilityID ability_type_for_structure, UnitTypeID unit_type, Tag location_tag);
    bool FindNearestGeaser(const Point2D &start, uint64_t& target, float MaxDistance);
    size_t CountUnitType(const ObservationInterface * observation, UnitTypeID unit_type);
    void EconStrat(const ObservationInterface *observation);
    bool TryExpand(const ObservationInterface* observation);
    void CheckScouting(const ObservationInterface *observation);
    bool TryFindRandomPathableLocation(Tag tag, Point2D& target_pos);
    void ManageBattleGroups(const ObservationInterface* observation);
    int64_t FindNearestUnit(const Point2D& start, Units UnitSet, ATTACK_TYPE AttackType = ATTACK_TYPE::BOTH);
    bool Scouting;
    std::vector<Point3D> expansions_;
    uint64_t ScoutingUnitTag;
    GameInfo *game_info_;
    int32_t CurrentMaxSupply;
    bool Expanding;
    int32_t ExpandingFrame;
    std::vector<BattleGroup> BattleGroups;
};

void DllExport *CreateNewAgent();

int DllExport GetAgentRace();

const char DllExport *GetAgentName();
