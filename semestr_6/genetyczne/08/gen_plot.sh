#!/bin/sh
cat plot_template.sh |sed -e s/__OUT__/data_"$1".png/|sed s/__TITLE__/"$2"/|sed s/__PATH__/"$1"/ >plot_$1.sh
chmod +x plot_$1.sh
