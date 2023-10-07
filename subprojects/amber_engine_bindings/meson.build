project(
  'amber_engine_bindings', 
  'c',
  default_options: {
    'warning_level': '3',
    'c_std': 'c17',
  },
)


engine_deps = [
  dependency('amber_engine_common', fallback: ['amber_engine_common', 'amber_engine_common_dep'])
]
engine_includes = include_directories('include')
engine_lib = static_library('amber_engine_bindings', 'src/bindings/bindings.c',
  include_directories: engine_includes,
  dependencies: engine_deps,
)

amber_engine_bindings_dep = declare_dependency(
  include_directories: engine_includes,
  link_with: engine_lib,
  dependencies: engine_deps,
)
set_variable(meson.project_name() + '_dep', amber_engine_bindings_dep)

amber_engine_binginds_include_dep = declare_dependency()

pkg = import('pkgconfig')
pkg.generate(
  name : meson.project_name(),
  filebase : meson.project_name(),
  subdirs : meson.project_name(),
  description: 'The Amber Engine'
)