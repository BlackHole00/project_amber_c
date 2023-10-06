amber_engine_dep = dependency(
  'amber_engine_bindings', 
  fallback: ['amber_engine_bindings', 'amber_engine_bindings_dep'],
  required: true,
)

shared_library('project_amber', 'project_amber.c', dependencies: amber_engine_dep)
