# bpmcounter2
 * BPM counter
 * 
 * Small utility to display BPM on a 16x2 I2C LED display 
 * Written for DIN Sync devices like the TR-606.  
 * Less ressource heavy than bpmcounter1, it should be possible to make it work 
 * on a Nano or even on a Attiny. 
 * Counts time between pulses, gains accuracy on a slow clock like DIN24, but 
 * has some jitter. For less jitter from fast clocks use my bpmcounter3 utility 
 * (which calculates speed from the number of pulses in a second), for high 
 * accuracy (on a resonably fast board - Uno or up) use bpmcounter1
 * 
 * Connect the (TTL level) clock signal to pin 2 (and ground to GND) - e.g. 
 * DIN Sync Pin 3 to Arduino Uno Pin 2, DIN Pin 2 to any GND terminal on the Uno
 * will benefit from input stabilization (Schmitt Trigger or a H11L1 opto coupler)
 * 
 * Copyright 2018 Sevo Stille <mailto:sevo@radiox.de>
 * @license GPL-3.0+ <http://www.gnu.org/licenses/gpl.html>
