#!/bin/bash

cd music_player
make clean && make all

cd ../music_server
make clean && make all

exit 0
