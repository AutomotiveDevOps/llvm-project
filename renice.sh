#!/usr/bin/env bash

pgrep -x cc1plus | xargs -r sudo renice 19 -p
pgrep -x cursor   | xargs -r sudo renice -20 -p
