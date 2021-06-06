#!/usr/bin/env bash
cppcheck --language=c++ *.cpp *.h && cpplint *.cpp *.h
