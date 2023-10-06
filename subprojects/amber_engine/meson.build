project('amber_engine', 'c')

engine_includes = include_directories('include')
engine_lib = shared_library('amber_engine', 'src/engine.c',
  include_directories: engine_includes,
)

amber_engine_dep = declare_dependency(
  include_directories: engine_includes,
  link_with: engine_lib,
)
set_variable(meson.project_name() + '_dep', amber_engine_dep)

pkg = import('pkgconfig')
pkg.generate(
  name : meson.project_name(),
  filebase : meson.project_name(),
  subdirs : meson.project_name(),
  description: 'The Amber Engine'
)