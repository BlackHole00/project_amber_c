#include "memory/library_definitions.h"

#include <stdio.h>
#include <assert.h>

#include <tomlc99/toml.h>
#include <flecs.h>
#include <mimalloc.h>

#include "config/config.h"
#include "memory/memory.h"
#include "bindings/proc_table.h"

typedef struct {
  float x, y;
} Position, Velocity;

void Move(ecs_iter_t *it) {
  Position *p = ecs_field(it, Position, 1);
  Velocity *v = ecs_field(it, Velocity, 2);

  for (int i = 0; i < it->count; i++) {
    p[i].x += v[i].x;
    p[i].y += v[i].y;
  }
}

void Print(ecs_iter_t* it) {
  Position *p = ecs_field(it, Position, 1);

  for (int i = 0; i < it->count; i++) {
    printf("%f %f\n", p->x, p->y);
  }
}

int main(void) {
  ae_defaultallocator_init();
  ae_proctable_init();

  ae_Config config;
  const char* config_location = ae_locate_config_file();

  if (!config_location) {
    ae_config_init_from_default(&config);
  } else {
    assert(ae_config_init_from_file(config_location, &config) == AE_PARSECONFIGERROR_SUCCESS);
    ae_free((void*)(config_location));
  }

  printf("%s\n", config.game_target);

  ecs_world_t *ecs = ecs_init();

  ECS_COMPONENT(ecs, Position);
  ECS_COMPONENT(ecs, Velocity);

  ECS_SYSTEM(ecs, Move, EcsOnUpdate, Position, Velocity);
  ECS_SYSTEM(ecs, Print, EcsOnUpdate, Position, Velocity);

  ecs_entity_t e = ecs_new_id(ecs);
  ecs_set(ecs, e, Position, {10, 20});
  ecs_set(ecs, e, Velocity, {1, 2});

  while (ecs_progress(ecs, 0)) { }
  
  ae_config_free(&config);
  ae_defaultallocator_deinit();
  
  return 0;
}

