project(
  'amber_engine', 
  'c',
  default_options: {
    'warning_level': '3',
    'c_std': 'c17',
  },
)

cmake = import('cmake')

mimalloc_project = cmake.subproject('mimalloc')
stc_project = cmake.subproject('STC')
c_logger = cmake.subproject('c-logger')

engine_deps = [
  dependency('amber_engine_common', fallback: ['amber_engine_common', 'amber_engine_common_dep']),
  dependency('tomlc99', fallback: ['tomlc99', 'tomlc99_dep']),
  dependency('tinydir', fallback: ['tinydir', 'tinydir_dep']),
  mimalloc_project.dependency('mimalloc'),
  stc_project.dependency('stc'),
  c_logger.dependency('logger'),
]
engine_lib = executable('amber_engine', [
    'src/main.c',
    'src/engine.c',
    'src/globals.c',
    'src/config/config.c',
    'src/memory/memory.c',
    'src/bindings/proc_table.c',
    'src/runtime/system_manager.c',
    'src/common/stc_implementation.c',
    'src/common/c-logger.c'
  ],
  dependencies: engine_deps,
)

amber_engine_dep = declare_dependency(
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
