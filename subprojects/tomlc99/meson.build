project(
  'tomlc99', 
  'c',
  default_options: {
    'warning_level': 'everything',
  },
)


engine_includes = include_directories('.')
engine_lib = shared_library('tomlc99', 
  [
    'tomlc99/toml.c',
  ],
  include_directories: engine_includes,
)

tomlc99_dep = declare_dependency(
  include_directories: engine_includes,
  link_with: engine_lib,
)
set_variable(meson.project_name() + '_dep', tomlc99_dep)

pkg = import('pkgconfig')
pkg.generate(
  name : meson.project_name(),
  filebase : meson.project_name(),
  subdirs : meson.project_name(),
  description: 'The Amber Engine'
)