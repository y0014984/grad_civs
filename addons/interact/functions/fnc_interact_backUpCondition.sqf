#include "..\script_component.hpp"

private _veh = vehicle _target; // target may be a vehicle itself
private _civ = driver _veh;

alive _target &&
    (_veh isKindOf "Car") &&
    (_civ isKindOf "Man") &&
    (_civ getVariable ["grad_civs_primaryTask", ""] != "")
