#pragma once

#include "../common/types.h"
#include "amber_engine/memory/handling_strategy.h"

typedef struct ae_SystemManager ae_SystemManager;

typedef enum {
  AE_SYSTEM_RESULT_OK     = 0,
  AE_SYSTEM_RESULT_WARN   = 1,
  AE_SYSTEM_RESULT_ERROR  = 2,
  AE_SYSTEM_RESULT_FATAL  = 3,
} ae_System_Result;

typedef enum {
  AE_PHASE_ENTRYPOINT = 0,
  AE_PHASE_PRELIBINIT,
  AE_PHASE_LIBINIT,
  AE_PHASE_POSTLIBINIT,
  AE_PHASE_PREGAMEINIT,
  AE_PHASE_GAMEINIT,
  AE_PHASE_POSTGAMEINIT,
  AE_PHASE_PRELOGIC,
  AE_PHASE_LOGIC,
  AE_PHASE_POSTLOGIC,
  AE_PHASE_PREDRAW,
  AE_PHASE_DRAW,
  AE_PHASE_POSTDRAW,
  AE_PHASE_PREGAMEDEINIT,
  AE_PHASE_GAMEDEINIT,
  AE_PHASE_POSTGAMEDEINIT,
  AE_PHASE_PRELIBDEINIT,
  AE_PHASE_LIBDEINIT,
  AE_PHASE_POSTLIBDEINIT,
  AE_PHASE_EXIT,
} ae_Phase;

static inline bool ae_systemresult_can_continue(
  ae_System_Result result
) {
  return result < AE_SYSTEM_RESULT_FATAL;
}

typedef ae_System_Result (*ae_System_Entrypoint_Proc)     (void*);
typedef ae_System_Result (*ae_System_PreLibInit_Proc)     (void*);
typedef ae_System_Result (*ae_System_LibInit_Proc)        (void*);
typedef ae_System_Result (*ae_System_PostLibInit_Proc)    (void*);
typedef ae_System_Result (*ae_System_PreGameInit_Proc)    (void*);
typedef ae_System_Result (*ae_System_GameInit_Proc)       (void*);
typedef ae_System_Result (*ae_System_PostGameInit_Proc)   (void*);
typedef ae_System_Result (*ae_System_PreLogic_Proc)       (void*);
typedef ae_System_Result (*ae_System_Logic_Proc)          (void*);
typedef ae_System_Result (*ae_System_PostLogic_Proc)      (void*);
typedef ae_System_Result (*ae_System_PreDraw_Proc)        (void*);
typedef ae_System_Result (*ae_System_Draw_Proc)           (void*);
typedef ae_System_Result (*ae_System_PostDraw_Proc)       (void*);
typedef ae_System_Result (*ae_System_PreGameDeinit_Proc)  (void*);
typedef ae_System_Result (*ae_System_GameDeinit_Proc)     (void*);
typedef ae_System_Result (*ae_System_PostGameDeinit_Proc) (void*);
typedef ae_System_Result (*ae_System_PreLibDeinit_Proc)   (void*);
typedef ae_System_Result (*ae_System_LibDeinit_Proc)      (void*);
typedef ae_System_Result (*ae_System_PostLibDeinit_Proc)  (void*);
typedef ae_System_Result (*ae_System_Exit_Proc)           (void*);

typedef struct {
  ae_System_Entrypoint_Proc     entrypoint;
  ae_System_PreLibInit_Proc     pre_lib_init;
  ae_System_LibInit_Proc        lib_init;
  ae_System_PostLibInit_Proc    post_lib_init;
  ae_System_PreGameInit_Proc    pre_game_init;
  ae_System_GameInit_Proc       game_init;
  ae_System_PostGameInit_Proc   post_game_init;
  ae_System_PreLogic_Proc       pre_logic;
  ae_System_Logic_Proc          logic;
  ae_System_PostLogic_Proc      post_logic;
  ae_System_PreDraw_Proc        pre_draw;
  ae_System_Draw_Proc           draw;
  ae_System_PostDraw_Proc       post_draw;
  ae_System_PreGameDeinit_Proc  pre_game_deinit;
  ae_System_GameDeinit_Proc     game_deinit;
  ae_System_PostGameDeinit_Proc post_game_deinit; 
  ae_System_PreLibDeinit_Proc   pre_lib_deinit;
  ae_System_LibDeinit_Proc      lib_deinit;
  ae_System_PostLibDeinit_Proc  post_lib_deinit;
  ae_System_Exit_Proc           exit;
} ae_System_ProcTable;

typedef struct {
  const char* identifier;
  void* system_data;

  const char** dependencies;
  int dependencies_count;

  ae_System_ProcTable* proc_table;

  ae_MemoryHandlingStrategy user_data_handling_strategy;
} ae_System;

