#pragma once

using namespace sc2;

typedef struct BuildingOrder_s
{
    UNIT_TYPEID BuildUnitType;
    int32_t number;
    BuildingOrder_s(UNIT_TYPEID InType, int32_t InNumber)
        : BuildUnitType(InType)
        , number(InNumber)
    {}

} BuildingOrder;

enum class ATTACK_TYPE {
    NONE,
    GROUND,
    FLYING,
    BOTH
};

class Strategy
{

public:
    static ATTACK_TYPE CanAttack(UNIT_TYPEID UnitType);
    static bool IsBuilding(sc2::UNIT_TYPEID UnitType);
    static sc2::UNIT_TYPEID GetBuildingFor(sc2::UNIT_TYPEID InType);
    int32_t StartAtFood;
    int32_t GeyserAtFood;
    std::vector<BuildingOrder> IntitialBuildOrder;
    std::vector<BuildingOrder> ContinuousBuildOrder;

};

