#pragma once

#include "../common/types.h"
#include "amber_engine/memory/handling_strategy.h"

typedef struct ae_Executor ae_Executor;

typedef enum {
  AE_EXECUTIONSYSTEM_RESULT_OK     = 0,
  AE_EXECUTIONSYSTEM_RESULT_WARN   = 1,
  AE_EXECUTIONSYSTEM_RESULT_ERROR  = 2,
  AE_EXECUTIONSYSTEM_RESULT_FATAL  = 3,
} ae_ExecutionSystem_Result;

typedef enum {
  AE_EXECUTIONPHASE_ENTRYPOINT = 0,
  AE_EXECUTIONPHASE_PRELIBINIT,
  AE_EXECUTIONPHASE_LIBINIT,
  AE_EXECUTIONPHASE_POSTLIBINIT,
  AE_EXECUTIONPHASE_PREGAMEINIT,
  AE_EXECUTIONPHASE_GAMEINIT,
  AE_EXECUTIONPHASE_POSTGAMEINIT,
  AE_EXECUTIONPHASE_PRELOGIC,
  AE_EXECUTIONPHASE_LOGIC,
  AE_EXECUTIONPHASE_POSTLOGIC,
  AE_EXECUTIONPHASE_PREDRAW,
  AE_EXECUTIONPHASE_DRAW,
  AE_EXECUTIONPHASE_POSTDRAW,
  AE_EXECUTIONPHASE_PREGAMEDEINIT,
  AE_EXECUTIONPHASE_GAMEDEINIT,
  AE_EXECUTIONPHASE_POSTGAMEDEINIT,
  AE_EXECUTIONPHASE_PRELIBDEINIT,
  AE_EXECUTIONPHASE_LIBDEINIT,
  AE_EXECUTIONPHASE_POSTLIBDEINIT,
  AE_EXECUTIONPHASE_EXIT,
} ae_ExecutionPhase;

static inline bool ae_executionsystemresult_can_continue(
  ae_ExecutionSystem_Result result
) {
  return result < AE_EXECUTIONSYSTEM_RESULT_FATAL;
}

typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_Entrypoint_Proc)     (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_PreLibInit_Proc)     (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_LibInit_Proc)        (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_PostLibInit_Proc)    (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_PreGameInit_Proc)    (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_GameInit_Proc)       (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_PostGameInit_Proc)   (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_PreLogic_Proc)       (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_Logic_Proc)          (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_PostLogic_Proc)      (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_PreDraw_Proc)        (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_Draw_Proc)           (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_PostDraw_Proc)       (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_PreGameDeinit_Proc)  (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_GameDeinit_Proc)     (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_PostGameDeinit_Proc) (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_PreLibDeinit_Proc)   (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_LibDeinit_Proc)      (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_PostLibDeinit_Proc)  (void*);
typedef ae_ExecutionSystem_Result (*ae_ExecutionSystem_Exit_Proc)           (void*);

typedef struct {
  ae_ExecutionSystem_Entrypoint_Proc     entrypoint;
  ae_ExecutionSystem_PreLibInit_Proc     pre_lib_init;
  ae_ExecutionSystem_LibInit_Proc        lib_init;
  ae_ExecutionSystem_PostLibInit_Proc    post_lib_init;
  ae_ExecutionSystem_PreGameInit_Proc    pre_game_init;
  ae_ExecutionSystem_GameInit_Proc       game_init;
  ae_ExecutionSystem_PostGameInit_Proc   post_game_init;
  ae_ExecutionSystem_PreLogic_Proc       pre_logic;
  ae_ExecutionSystem_Logic_Proc          logic;
  ae_ExecutionSystem_PostLogic_Proc      post_logic;
  ae_ExecutionSystem_PreDraw_Proc        pre_draw;
  ae_ExecutionSystem_Draw_Proc           draw;
  ae_ExecutionSystem_PostDraw_Proc       post_draw;
  ae_ExecutionSystem_PreGameDeinit_Proc  pre_game_deinit;
  ae_ExecutionSystem_GameDeinit_Proc     game_deinit;
  ae_ExecutionSystem_PostGameDeinit_Proc post_game_deinit; 
  ae_ExecutionSystem_PreLibDeinit_Proc   pre_lib_deinit;
  ae_ExecutionSystem_LibDeinit_Proc      lib_deinit;
  ae_ExecutionSystem_PostLibDeinit_Proc  post_lib_deinit;
  ae_ExecutionSystem_Exit_Proc           exit;
} ae_ExecutionSystem_ProcTable;

typedef struct {
  const char* identifier;
  void* system_data;

  const char** dependencies;
  int dependencies_count;

  ae_ExecutionSystem_ProcTable* proc_table;

  ae_MemoryHandlingStrategy user_data_handling_strategy;
} ae_ExecutionSystem;

