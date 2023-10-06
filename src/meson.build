amber_engine_dep = dependency(
  'amber_engine', 
  fallback: ['amber_engine', 'amber_engine_dep'],
  required: true,
)

executable('project_amber', 'main.c', dependencies: amber_engine_dep)
