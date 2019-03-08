#ifndef MODULES_DIRECTORY
    #define MODULES_DIRECTORY modules
#endif

class grad_civs {

    class accessors {
        file = MODULES_DIRECTORY\grad-civs\functions\accessors;

        class clearCurrentlyThinking {};
        class getCurrentlyThinking {};
        class getGroupVehicle {};
        class setCurrentlyThinking {};
        class setGroupVehicle {};
    };

	class behaviour {
        file = MODULES_DIRECTORY\grad-civs\functions\behaviour;

        class addCycleWaypoint {};
		class taskPatrol {};
        class taskPatrolAddWaypoint {};
    };

    class common {
        file = MODULES_DIRECTORY\grad-civs\functions\common;

        class addCompoundState {};
        class addToStateMachine {};
        class findBuildings {};
        class findPositionOfInterest {};
        class findRandomPos {};
        class findRandomPosArea {};
        class getCurrentState {};
        class populateArea {};
        class removeFromStateMachine {};
        class setBackpacks {};
        class setClothes {};
        class setDebugMode {};
        class setFaces {};
        class setGoggles {};
        class setHeadgear {};
        class setVehicles {};
    };

	class debug {
		file = MODULES_DIRECTORY\grad-civs\functions\debug;

        class drawCivs {};
        class mapMarkers {};
        class showWhatTheyThink {};
        class updateInfoLine {};
    };

    class init {
        file = MODULES_DIRECTORY\grad-civs\functions\init;

        class initModule {preInit = 1;};
    };

    class player {
        file = MODULES_DIRECTORY\grad-civs\functions\player;
        class checkWeaponOnCivilianPerception {};
        class checkWeaponOnCivilianPointer {};
        class playerLoop {};
        class registerAceInteractionHandler {};
        class showCivHint {};
    };

    class spawn {
        file = MODULES_DIRECTORY\grad-civs\functions\spawn;

        class addCarCrew {};
        class addFootsy {};
        class createSideRoadVehicles {};
        class deleteIfDamaged {};
        class findSpawnPosition {};
        class serverLoop {};
        class spawnCivilian {};
        class spawnCivilianGroup {};
        class spawnPass {};
        class spawnVehicle {};
    };

    class sm_activities {
        file = MODULES_DIRECTORY\grad-civs\functions\sm_activities;

        class sm_activities {};
        class sm_activities_helper_freeCondition {};
        class sm_activities_helper_surrenderCondition {};
        class sm_activities_state_asOrdered_enter {};
        class sm_activities_state_asOrdered_exit {};
        class sm_activities_state_asOrdered_loop {};
        class sm_activities_state_panic_enter {};
        class sm_activities_state_panic_exit {};
        class sm_activities_state_surrendered_enter {};
        class sm_activities_state_surrendered_exit {};
        class sm_activities_trans_asOrdered_business_condition {};
        class sm_activities_trans_business_panic_condition {};
        class sm_activities_trans_business_surrendered_condition {};
        // class sm_activities_trans_panic_business_condition {}; // event transition
        class sm_activities_trans_surrendered_business_condition {};
        class sm_activities_trans_surrendered_panic_condition {};
    };

    class sm_business {
        file = MODULES_DIRECTORY\grad-civs\functions\sm_business;

        class sm_business {};
        class sm_business_state_dismount_enter {};
        class sm_business_state_mountUp_enter {};
        class sm_business_state_mountUp_exit {};
        class sm_business_state_patrol_enter {};
        class sm_business_state_patrol_exit {};
        class sm_business_state_rally_enter {};
        class sm_business_state_rally_loop {};
        class sm_business_state_voyage_enter {};
        class sm_business_state_voyage_exit {};
        class sm_business_state_voyage_loop {};
        class sm_business_trans_dismount_rally_condition {};
        class sm_business_trans_mountUp_voyage_condition {};
        class sm_business_trans_mountUp_dismount_condition {};
        class sm_business_trans_rally_mountUp_condition {};
        class sm_business_trans_rally_patrol_condition {};
        class sm_business_trans_voyage_dismount_condition {};
    };

    class sm_lifecycle {
        file = MODULES_DIRECTORY\grad-civs\functions\sm_lifecycle;

        class sm_lifecycle {};
        class sm_lifecycle_state_death_enter {};
        class sm_lifecycle_state_despawn_enter {};
        class sm_lifecycle_trans_life_despawn_condition {};
        class sm_lifecycle_state_spawn_enter {};
    };

    class sm_emotions {
        file = MODULES_DIRECTORY\grad-civs\functions\sm_emotions;

        class sm_emotions {};
    };

    class sm_panic {
        file = MODULES_DIRECTORY\grad-civs\functions\sm_panic;

        class sm_panic {};
        class sm_panic_state_flight_loop {};
        class sm_panic_state_flight_enter {};
        class sm_panic_state_hidden_enter {};
        class sm_panic_state_hide_enter {};
        class sm_panic_state_hide_exit {};
        class sm_panic_trans_hide_hidden_condition {};
        class sm_panic_trans_hide_hidden_handler {};
    };
};
