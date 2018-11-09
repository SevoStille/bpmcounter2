# bpmcounter2
 * BPM counter
 * 
 * Small utility to display BPM on a 16x2 I2C LED display 
 * Written for DIN Sync devices like the TR-606.  
 * Counts time between pulses, gets more accurate on a slow clock, but has some  
 * jitter, unless you stabilize the input (with a Schmitt trigger or the like).
 * For less jitter from a fast clock, like 96ppq use my bpmcounter3 utility 
 * (which calculates speed from the number of pulses in a second)
 * 
 * Connect the (TTL level) clock signal to pin 2 (and ground to GND) - e.g. 
 * DIN Sync Pin 3 to Arduino Uno Pin 2, DIN Pin 2 to any GND terminal on the Uno 
 * 
 * Copyright 2018 Sevo Stille <mailto:sevo@radiox.de>
 * @license GPL-3.0+ <http://www.gnu.org/licenses/gpl.html>
