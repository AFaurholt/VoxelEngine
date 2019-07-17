#!/bin/bash

mkdir -p out/build
cd ./out/build
cmake -GNinja ../..
ninja
