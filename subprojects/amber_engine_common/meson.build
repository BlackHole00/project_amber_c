project('amber_engine_common', 'c')

engine_includes = include_directories('include')

amber_engine_common_dep = declare_dependency(
  include_directories: engine_includes,
)
set_variable(meson.project_name() + '_dep', amber_engine_common_dep)

pkg = import('pkgconfig')
pkg.generate(
  name : meson.project_name(),
  filebase : meson.project_name(),
  subdirs : meson.project_name(),
  description: 'The Amber Engine'
)
