#!/bin/sh
# This scripts fixes the "shutdown problem" of the 7inch TFT display on the
# BananaPro board.
# It sets various GPIO Pins and values to shut down the lcd screen.
# Usage:
#   - without any parameter the screen shuts off
#   - if "on" or number 1 is submitted as first parameter, the screen turns on
#
# Stolen here: https://forum.armbian.com/topic/7233-bananapi-pro-7-touchlcd-with-debian-buster-and-mainline-kernel-5xxxx/
# LCD Power         PH12    H=8     (8-1)*32+12   = 236
# Backlight enable  PH8     H=8     (8-1)*32+8    = 232
# Backlight PWM     PB2     B=2     (2-1)*32+2    = 34

if [ ! -d "/sys/class/gpio/gpio34" ]
then
  echo "34" > /sys/class/gpio/export
  echo "out" > /sys/class/gpio/gpio34/direction
  echo "1" > /sys/class/gpio/gpio34/value
fi
if [ ! -d "/sys/class/gpio/gpio232" ]
then
  echo "232" > /sys/class/gpio/export
  echo "out" > /sys/class/gpio/gpio232/direction
  echo "1" > /sys/class/gpio/gpio232/value
fi
if [ ! -d "/sys/class/gpio/gpio236" ]
then
  echo "236" > /sys/class/gpio/export
  echo "out" > /sys/class/gpio/gpio236/direction
  echo "1" > /sys/class/gpio/gpio236/value
fi

if [ "$1" == "on" || "$1" == 1 ]; then
  # LCD on
  echo "1" > /sys/class/gpio/gpio34/value
  echo "1" > /sys/class/gpio/gpio232/value
  echo "1" > /sys/class/gpio/gpio236/value
else
  # LCD off
  echo "0" > /sys/class/gpio/gpio34/value
  echo "0" > /sys/class/gpio/gpio232/value
  echo "0" > /sys/class/gpio/gpio236/value
fi
