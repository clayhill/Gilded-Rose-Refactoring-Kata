from conans import ConanFile, CMake


class GildedroseConan(ConanFile):
    generators = "cmake"
    requires = (
        "gtest/1.8.1@bincrafters/stable"
    )
