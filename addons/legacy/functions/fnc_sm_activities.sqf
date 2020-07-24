#include "..\script_component.hpp"

private _activities = [[], true] call CBA_statemachine_fnc_create;
private _business = [] call FUNC(sm_business);
private _panic = [] call FUNC(sm_panic);

// STATES
assert(_activities isEqualType locationNull);
assert(_business isEqualType locationNull);
assert(_panic isEqualType locationNull);

private _act_business = [
    _activities,
    [_business],
    {},
    {},
    {},
    "act_business"
] call EFUNC(cba_statemachine,addCompoundState);
assert(_act_business != "");

private _act_asOrdered = [
    _activities,
    {},
    { _this call FUNC(sm_activities_state_asOrdered_enter) },
    { _this call FUNC(sm_activities_state_asOrdered_exit) },
    "act_asOrdered"
] call EFUNC(cba_statemachine,addState);
assert(_act_asOrdered != "");

private _act_surrendered = [
    _activities,
    {},
    { _this call FUNC(sm_activities_state_surrendered_enter) },
    { _this call FUNC(sm_activities_state_surrendered_exit) },
    "act_surrendered"
] call EFUNC(cba_statemachine,addState);
assert(_act_surrendered != "");

private _act_panic = [
    _activities,
    [_panic],
    {  },
    { _this call FUNC(sm_activities_state_panic_enter) },
    { _this call FUNC(sm_activities_state_panic_exit) },
    "act_panic"
] call EFUNC(cba_statemachine,addCompoundState);
assert(_act_panic != "");

// TRANSITIONS

assert ([
    _activities,
    _act_business, _act_surrendered,
    { _this call FUNC(sm_activities_trans_business_surrendered_condition) },
    {},
    _act_business + _act_surrendered
] call EFUNC(cba_statemachine,addTransition));

assert ([
    _activities,
    _act_business, _act_panic,
    { _this call FUNC(sm_activities_trans_business_panic_condition) },
    {},
    _act_business + _act_panic
] call EFUNC(cba_statemachine,addTransition));

assert ([
    _activities,
    _act_surrendered, _act_business,
    { _this call FUNC(sm_activities_trans_surrendered_business_condition) },
    {},
    _act_surrendered + _act_business
] call EFUNC(cba_statemachine,addTransition));

assert ([
    _activities,
    _act_surrendered, _act_panic,
    { _this call FUNC(sm_activities_trans_surrendered_panic_condition) },
    {},
    _act_surrendered + _act_panic
] call EFUNC(cba_statemachine,addTransition));

assert ([
    _activities,
    _act_panic, _act_business,
    ["grad_civs_panicking_end"],
    {true},
    {[QGVAR(switchMove), [_this, ""]] call CBA_fnc_globalEvent;},
    _act_panic + _act_business
] call CBA_statemachine_fnc_addEventTransition);

assert ([
    _activities,
    _act_business, _act_asOrdered,
    [QGVAR(customActivity_start)],
    {true},
    {},
    _act_business + _act_asOrdered
] call CBA_statemachine_fnc_addEventTransition);

assert ([
    _activities,
    _act_asOrdered, _act_business,
    [QGVAR(customActivity_end)],
    {true},
    {},
    _act_asOrdered + _act_business + "_event"
] call CBA_statemachine_fnc_addEventTransition);

EGVAR(common,stateMachines) setVariable ["activities", _activities];



_activities
