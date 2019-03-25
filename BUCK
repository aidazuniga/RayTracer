cxx_library(
  name = 'car',
  srcs = [
    'ToyotaCar.cpp',
  ],
  headers = [
    'Car.h',
    'ToyotaCar.h',
  ],
)

cxx_library(
  name = 'driver',
  srcs = [
    'Driver.cpp'
  ],
  headers = [
    'Driver.h',
  ],
  deps = [
    ':car'
  ],
  visibility = [
    '//test:driver',
  ]
)

cxx_binary(
  name = 'main',
  srcs = [
    'main.cpp',
  ],
  deps = [
    ':driver',
  ],
)