#!/bin/bash
du -sm -B1 */ | awk -v x=$1 '$1 > x { print $2 }'