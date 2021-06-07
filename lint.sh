#!/usr/bin/env bash
cppcheck --language=c++ --quiet --std=c++11 *.cpp *.h && cpplint --filter=-build/include_subdir --quiet *.cpp *.h
